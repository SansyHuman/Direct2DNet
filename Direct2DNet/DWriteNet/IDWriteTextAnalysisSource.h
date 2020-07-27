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
        using fnTxtPos = HRESULT(__stdcall *)(UINT32, const WCHAR **, UINT32 *);
        using fnRdDir = ::DWRITE_READING_DIRECTION(__stdcall *)(void);
        using fnLocale = HRESULT(__stdcall *)(UINT32, UINT32 *, const WCHAR **);
        using fnNumSub = HRESULT(__stdcall *)(UINT32, UINT32 *, ::IDWriteNumberSubstitution **);

        class IDWriteNativeTextAnalysisSource : public ::IDWriteTextAnalysisSource
        {
        private:
            UINT m_cRef;

        public:
            fnTxtPos m_getTextAtPosition;
            fnTxtPos m_getTextBeforePosition;
            fnRdDir m_getParagraphReadingDirection;
            fnLocale m_getLocaleName;
            fnNumSub m_getNumberSubstitiution;

            IDWriteNativeTextAnalysisSource() : m_cRef(1) {}
            IDWriteNativeTextAnalysisSource(const IDWriteNativeTextAnalysisSource &) = delete;
            IDWriteNativeTextAnalysisSource(IDWriteNativeTextAnalysisSource &&) = delete;
            IDWriteNativeTextAnalysisSource &operator=(const IDWriteNativeTextAnalysisSource &) = delete;

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
                else if(__uuidof(::IDWriteTextAnalysisSource) == iid)
                {
                    *ppvObject = static_cast<::IDWriteTextAnalysisSource *>(this);
                    AddRef();
                }
                else
                {
                    *ppvObject = NULL;
                    hr = E_NOINTERFACE;
                }

                return hr;
            }

            STDMETHOD(GetTextAtPosition)(
                UINT32 textPosition,
                _Outptr_result_buffer_(*textLength) WCHAR const **textString,
                _Out_ UINT32 *textLength
                ) override
            {
                return m_getTextAtPosition(textPosition, textString, textLength);
            }

            STDMETHOD(GetTextBeforePosition)(
                UINT32 textPosition,
                _Outptr_result_buffer_(*textLength) WCHAR const **textString,
                _Out_ UINT32 *textLength
                ) override
            {
                return m_getTextBeforePosition(textPosition, textString, textLength);
            }

            STDMETHOD_(::DWRITE_READING_DIRECTION, GetParagraphReadingDirection)() override
            {
                return m_getParagraphReadingDirection();
            }

            STDMETHOD(GetLocaleName)(
                UINT32 textPosition,
                _Out_ UINT32 *textLength,
                _Outptr_result_z_ WCHAR const **localeName
                ) override
            {
                return m_getLocaleName(textPosition, textLength, localeName);
            }

            STDMETHOD(GetNumberSubstitution)(
                UINT32 textPosition,
                _Out_ UINT32 *textLength,
                _COM_Outptr_ ::IDWriteNumberSubstitution **numberSubstitution
                ) override
            {
                return m_getNumberSubstitiution(textPosition, textLength, numberSubstitution);
            }
        };

        ref class IDWriteNumberSubstitution;

        // Done.

        /// <summary>
        /// The interface implemented by the text analyzer's client to provide text to
        /// the analyzer. It allows the separation between the logical view of text as
        /// a continuous stream of characters identifiable by unique text positions,
        /// and the actual memory layout of potentially discrete blocks of text in the
        /// client's backing store.
        ///
        /// If any of these callbacks returns an error, the analysis functions will
        /// stop prematurely and return a callback error. Rather than return E_NOTIMPL,
        /// an application should stub the method and return a constant/null and S_OK.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("688e1a58-5094-47c8-adc8-fbcea60ae92b")]
        public ref class IDWriteTextAnalysisSource abstract : DWriteNet::IDirectWriteObject
        {
        protected:
            delegate HRESULT FnTxtPos(UINT32, const WCHAR **, UINT32 *);
            delegate ::DWRITE_READING_DIRECTION FnRdDir();
            delegate HRESULT FnLocale(UINT32, UINT32 *, const WCHAR **);
            delegate HRESULT FnNumSub(UINT32, UINT32 *, ::IDWriteNumberSubstitution **);

        internal:
            ::IDWriteTextAnalysisSource *m_pSource;

        private:
            GCHandle m_getTextAtPosition;
            GCHandle m_getTextBeforePosition;
            GCHandle m_getParagraphReadingDirection;
            GCHandle m_getLocaleName;
            GCHandle m_getNumberSubstitution;

        protected:
            /// <summary>
            /// The basic constructor of IDWriteTextAnalysisSource. You should call this ctor when you
            /// implement the source.
            /// </summary>
            IDWriteTextAnalysisSource();

        public:
            ~IDWriteTextAnalysisSource();
            !IDWriteTextAnalysisSource();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pSource;
                }
            }

            virtual void HandleCOMInterface(void *obj) sealed;

        private:
            HRESULT GetTextAtPositionInternal(
                UINT32 textPosition,
                _Outptr_result_buffer_(*textLength) WCHAR const **textString,
                _Out_ UINT32 *textLength
            );

            HRESULT GetTextBeforePositionInternal (
                UINT32 textPosition,
                _Outptr_result_buffer_(*textLength) WCHAR const **textString,
                _Out_ UINT32 *textLength
                );

            ::DWRITE_READING_DIRECTION GetParagraphReadingDirectionInternal();

            HRESULT GetLocaleNameInternal(
                UINT32 textPosition,
                _Out_ UINT32 *textLength,
                _Outptr_result_z_ WCHAR const **localeName
            );

            HRESULT GetNumberSubstitutionInternal(
                UINT32 textPosition,
                _Out_ UINT32 *textLength,
                _COM_Outptr_ ::IDWriteNumberSubstitution **numberSubstitution
            );

        public:
            /// <summary>
            /// Gets a block of text starting at the specified text position.
            /// Returning NULL indicates the end of text - the position is after
            /// the last character. This function is called iteratively for
            /// each consecutive block, tying together several fragmented blocks
            /// in the backing store into a virtual contiguous string.
            /// </summary>
            /// <param name="textPosition">First position of the piece to obtain. All
            ///     positions are in UTF16 code-units, not whole characters, which
            ///     matters when supplementary characters are used.</param>
            /// <param name="textString">Address that receives a pointer to the text block
            ///     at the specified position(out parameter).
            ///     Pointer to the first character at the given text position.
            ///     NULL indicates no chunk available at the specified position, either
            ///     because textPosition >= the entire text content length or because the
            ///     queried position is not mapped into the app's backing store.</param>
            /// <param name="textLength">Number of UTF16 units of the retrieved chunk(out parameter).
            ///     The returned length is not the length of the block, but the length
            ///     remaining in the block, from the given position until its end.
            ///     So querying for a position that is 75 positions into a 100
            ///     position block would return 25.</param>
            /// <returns>Standard HRESULT error code.</returns>
            /// <remarks>
            /// Although apps can implement sparse textual content that only maps part of
            /// the backing store, the app must map any text that is in the range passed
            /// to any analysis functions.
            /// The implemetation should fix the pointer to the text until the next call or until the analysis
            /// returns if it is in managed heap.
            /// </remarks>
            virtual HRESULT GetTextAtPosition(
                UINT32 textPosition,
                [OutAttribute] WCHAR *%textString,
                [OutAttribute] UINT32 %textLength
            ) abstract;

            /// <summary>
            /// Gets a block of text immediately preceding the specified position.
            /// </summary>
            /// <param name="textPosition">Position immediately after the last position of the chunk
            ///     to obtain.</param>
            /// <param name="textString">Address that receives a pointer to the text block
            ///     at the specified position(out parameter).
            ///     Pointer to the first character at (textPosition - textLength).
            ///     NULL indicates no chunk available at the specified position, either
            ///     because textPosition == 0,the textPosition > the entire text content
            ///     length, or the queried position is not mapped into the app's backing
            ///     store.</param>
            /// <param name="textLength">Number of UTF16 units of the retrieved block.
            ///     The length returned is from the given position to the front of
            ///     the block.</param>
            /// <returns>Standard HRESULT error code.</returns>
            /// <remarks>
            /// Although apps can implement sparse textual content that only maps part of
            /// the backing store, the app must map any text that is in the range passed
            /// to any analysis functions.
            /// The implemetation should fix the pointer to the text until the next call or until the analysis
            /// returns if it is in managed heap.
            /// </remarks>
            virtual HRESULT GetTextBeforePosition(
                UINT32 textPosition,
                [OutAttribute] WCHAR *%textString,
                [OutAttribute] UINT32 %textLength
            ) abstract;

            /// <summary>
            /// Gets paragraph reading direction.
            /// </summary>
            virtual DWriteNet::DWRITE_READING_DIRECTION GetParagraphReadingDirection() abstract;

            /// <summary>
            /// Gets locale name on the range affected by it.
            /// </summary>
            /// <param name="textPosition">Position to get the locale name of.</param>
            /// <param name="textLength">Receives the length from the given position up to the
            ///     next differing locale(out parameter).</param>
            /// <param name="localeName">Address that receives a pointer to the locale
            ///     at the specified position(out parameter). It should terminate with null
            ///     character.</param>
            /// <returns>Standard HRESULT error code.</returns>
            /// <remarks>
            /// The localeName pointer must remain valid until the next call or until
            /// the analysis returns.
            /// The implemetation should fix the pointer to the text until the next call or until the analysis
            /// returns if it is in managed heap.
            /// </remarks>
            virtual HRESULT GetLocaleName(
                UINT32 textPosition,
                [OutAttribute] UINT32 %textLength,
                [OutAttribute] WCHAR *%localeName
            ) abstract;

            /// <summary>
            /// Get number substitution on the range affected by it.
            /// </summary>
            /// <param name="textPosition">Position to get the number substitution of.</param>
            /// <param name="textLength">Receives the length from the given position up to the
            ///     next differing number substitution.</param>
            /// <param name="numberSubstitution">Reference that receives the number substitution
            ///     at the specified position(out parameter).</param>
            /// <remarks>
            /// The analysis will release the reference count of (unmanaged) substitution when finished
            /// with it (either before the next call or before it returns). However, the sink callback
            /// may hold onto it after that.
            /// </remarks>
            virtual HRESULT GetNumberSubstitution(
                UINT32 textPosition,
                [OutAttribute] UINT32 %textLength,
                [OutAttribute] DWriteNet::IDWriteNumberSubstitution ^%numberSubstitution
            ) abstract;
        };
    }
}