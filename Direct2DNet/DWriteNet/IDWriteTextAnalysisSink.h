#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DWriteNet
    {
        using fnScAnal = HRESULT(__stdcall *)(UINT32, UINT32, const ::DWRITE_SCRIPT_ANALYSIS *);
        using fnLnBp = HRESULT(__stdcall *)(UINT32, UINT32, const ::DWRITE_LINE_BREAKPOINT *);
        using fnBdLvl = HRESULT(__stdcall *)(UINT32, UINT32, UINT8, UINT8);
        using fnNumSubSet = HRESULT(__stdcall *)(UINT32, UINT32, ::IDWriteNumberSubstitution *);

        class IDWriteNativeTextAnalysisSink : public ::IDWriteTextAnalysisSink
        {
        private:
            UINT m_cRef;

        public:
            fnScAnal m_setScriptAnalysis;
            fnLnBp m_setLineBreakpoints;
            fnBdLvl m_setBidiLevel;
            fnNumSubSet m_setNumberSubstitution;

            IDWriteNativeTextAnalysisSink() : m_cRef(1) {}
            IDWriteNativeTextAnalysisSink(const IDWriteNativeTextAnalysisSink &) = delete;
            IDWriteNativeTextAnalysisSink(IDWriteNativeTextAnalysisSink &&) = delete;
            IDWriteNativeTextAnalysisSink &operator=(const IDWriteNativeTextAnalysisSink &) = delete;

            STDMETHOD_(ULONG, AddRef)(void) override
            {
                return InterlockedIncrement(reinterpret_cast<LONG volatile *>(&m_cRef));
            }

            STDMETHOD_(ULONG, Release)(void) override
            {
                ULONG cRef = static_cast<ULONG>(
                    InterlockedDecrement(reinterpret_cast<LONG volatile *>(&m_cRef)));

                if(0 == cRef)
                {
                    delete this;
                }

                return cRef;
            }

            STDMETHOD(QueryInterface)(THIS_ REFIID iid, void **ppvObject) override
            {
                HRESULT hr = S_OK;

                if(__uuidof(::IUnknown) == iid)
                {
                    *ppvObject = static_cast<::IUnknown *>(this);
                    AddRef();
                }
                else if(__uuidof(::IDWriteTextAnalysisSink) == iid)
                {
                    *ppvObject = static_cast<::IDWriteTextAnalysisSink *>(this);
                    AddRef();
                }
                else
                {
                    *ppvObject = NULL;
                    hr = E_NOINTERFACE;
                }

                return hr;
            }

            STDMETHOD(SetScriptAnalysis)(
                UINT32 textPosition,
                UINT32 textLength,
                _In_ ::DWRITE_SCRIPT_ANALYSIS const *scriptAnalysis
                ) override
            {
                return m_setScriptAnalysis(textPosition, textLength, scriptAnalysis);
            }

            STDMETHOD(SetLineBreakpoints)(
                UINT32 textPosition,
                UINT32 textLength,
                _In_reads_(textLength) ::DWRITE_LINE_BREAKPOINT const *lineBreakpoints
                ) override
            {
                return m_setLineBreakpoints(textPosition, textLength, lineBreakpoints);
            }

            STDMETHOD(SetBidiLevel)(
                UINT32 textPosition,
                UINT32 textLength,
                UINT8 explicitLevel,
                UINT8 resolvedLevel
                ) override
            {
                return m_setBidiLevel(textPosition, textLength, explicitLevel, resolvedLevel);
            }

            STDMETHOD(SetNumberSubstitution)(
                UINT32 textPosition,
                UINT32 textLength,
                _In_::IDWriteNumberSubstitution *numberSubstitution
                ) override
            {
                return m_setNumberSubstitution(textPosition, textLength, numberSubstitution);
            }
        };

        ref class IDWriteNumberSubstitution;

        // Done.

        /// <summary>
        /// The interface implemented by the text analyzer's client to receive the
        /// output of a given text analysis. The Text analyzer disregards any current
        /// state of the analysis sink, therefore a Set method call on a range
        /// overwrites the previously set analysis result of the same range. 
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("5810cd44-0ca0-4701-b3fa-bec5182ae4f6")]
        public ref class IDWriteTextAnalysisSink abstract : DWriteNet::IDirectWriteObject
        {
        protected:
            delegate HRESULT FnScAnal(UINT32, UINT32, const ::DWRITE_SCRIPT_ANALYSIS *);
            delegate HRESULT FnLnBp(UINT32, UINT32, const ::DWRITE_LINE_BREAKPOINT *);
            delegate HRESULT FnBdLvl(UINT32, UINT32, UINT8, UINT8);
            delegate HRESULT FnNumSubSet(UINT32, UINT32, ::IDWriteNumberSubstitution *);

        internal:
            ::IDWriteTextAnalysisSink *m_pSink;

        private:
            GCHandle m_setScriptAnalysis;
            GCHandle m_setLineBreakpoints;
            GCHandle m_setBidiLevel;
            GCHandle m_setNumberSubstitution;

        protected:
            /// <summary>
            /// The basic constructor of IDWriteTextAnalysisSink. You should call this ctor when you
            /// implement the sink.
            /// </summary>
            IDWriteTextAnalysisSink();

        public:
            ~IDWriteTextAnalysisSink();
            !IDWriteTextAnalysisSink();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pSink;
                }
            }

            virtual void HandleCOMInterface(void *obj) sealed;

        private:
            HRESULT SetScriptAnalysisInternal(
                UINT32 textPosition,
                UINT32 textLength,
                _In_ ::DWRITE_SCRIPT_ANALYSIS const *scriptAnalysis
            );

            HRESULT SetLineBreakpointsInternal(
                UINT32 textPosition,
                UINT32 textLength,
                _In_reads_(textLength) ::DWRITE_LINE_BREAKPOINT const *lineBreakpoints
            );

            HRESULT SetBidiLevelInternal(
                UINT32 textPosition,
                UINT32 textLength,
                UINT8 explicitLevel,
                UINT8 resolvedLevel
            );

            HRESULT SetNumberSubstitutionInternal(
                UINT32 textPosition,
                UINT32 textLength,
                _In_ ::IDWriteNumberSubstitution *numberSubstitution
            );

        public:
            /// <summary>
            /// Reports script analysis for the text range.
            /// </summary>
            /// <param name="textPosition">Starting position to report from.</param>
            /// <param name="textLength">Number of UTF16 units of the reported range.</param>
            /// <param name="scriptAnalysis">Script analysis of characters in range.</param>
            /// <returns>
            /// A successful code or error code to abort analysis.
            /// </returns>
            virtual HRESULT SetScriptAnalysis(
                UINT32 textPosition,
                UINT32 textLength,
                DWriteNet::DWRITE_SCRIPT_ANALYSIS %scriptAnalysis
            ) abstract;

            /// <summary>
            /// Reports line-break opportunities for each character, starting from
            /// the specified position.
            /// </summary>
            /// <param name="textPosition">Starting position to report from.</param>
            /// <param name="textLength">Number of UTF16 units of the reported range.</param>
            /// <param name="lineBreakpoints">Pointer to array of reaking conditions for each character.
            /// The length of the array is <paramref name="textLength"/>.</param>
            /// <returns>
            /// A successful code or error code to abort analysis.
            /// </returns>
            /// <remarks>
            /// Do not modify the value of the struct pointed by <paramref name="lineBreakpoints"/> pointer.
            /// </remarks>
            virtual HRESULT SetLineBreakpoints(
                UINT32 textPosition,
                UINT32 textLength,
                DWriteNet::DWRITE_LINE_BREAKPOINT *lineBreakpoints
            ) abstract;

            /// <summary>
            /// Sets bidirectional level on the range, called once per each
            /// level run change (either explicit or resolved implicit).
            /// </summary>
            /// <param name="textPosition">Starting position to report from.</param>
            /// <param name="textLength">Number of UTF16 units of the reported range.</param>
            /// <param name="explicitLevel">Explicit level from embedded control codes
            ///     RLE/RLO/LRE/LRO/PDF, determined before any additional rules.</param>
            /// <param name="resolvedLevel">Final implicit level considering the
            ///     explicit level and characters' natural directionality, after all
            ///     Bidi rules have been applied.</param>
            /// <returns>
            /// A successful code or error code to abort analysis.
            /// </returns>
            virtual HRESULT SetBidiLevel(
                UINT32 textPosition,
                UINT32 textLength,
                UINT8 explicitLevel,
                UINT8 resolvedLevel
            ) abstract;

            /// <summary>
            /// Sets number substitution on the range.
            /// </summary>
            /// <param name="textPosition">Starting position to report from.</param>
            /// <param name="textLength">Number of UTF16 units of the reported range.</param>
            /// <param name="numberSubstitution">The number substitution applicable to
            ///     the returned range of text.</param>
            /// <returns>
            /// A successful code or error code to abort analysis.
            /// </returns>
            /// <remarks>
            /// Unlike script and bidi analysis, where every character passed to the
            /// analyzer has a result, this will only be called for those ranges where
            /// substitution is applicable. For any other range, you will simply not
            /// be called.
            /// </remarks>
            virtual HRESULT SetNumberSubstitution(
                UINT32 textPosition,
                UINT32 textLength,
                DWriteNet::IDWriteNumberSubstitution ^numberSubstitution
            ) abstract;
        };
    }
}