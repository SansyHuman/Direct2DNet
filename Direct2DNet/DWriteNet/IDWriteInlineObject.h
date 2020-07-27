#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace System::Collections::Generic;

namespace D2DNet
{
    namespace DWriteNet
    {
        using fnMet = HRESULT(__stdcall *)(::DWRITE_INLINE_OBJECT_METRICS *);
        using fnOhMet = HRESULT(__stdcall *)(::DWRITE_OVERHANG_METRICS *);
        using fnBC = HRESULT(__stdcall *)(::DWRITE_BREAK_CONDITION *, ::DWRITE_BREAK_CONDITION *);

        class IDWriteNativeInlineObject : public ::IDWriteInlineObject
        {
        private:
            UINT m_cRef;

        public:
            fnMet m_getMetrics;
            fnOhMet m_getOverhangMetrics;
            fnBC m_getBreakConditions;

            IDWriteNativeInlineObject() : m_cRef(1) {}
            IDWriteNativeInlineObject(const IDWriteNativeInlineObject &) = delete;
            IDWriteNativeInlineObject(IDWriteNativeInlineObject &&) = delete;
            IDWriteNativeInlineObject &operator=(const IDWriteNativeInlineObject &) = delete;

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
                else if(__uuidof(::IDWriteInlineObject) == iid)
                {
                    *ppvObject = static_cast<::IDWriteInlineObject *>(this);
                    AddRef();
                }
                else
                {
                    *ppvObject = NULL;
                    hr = E_NOINTERFACE;
                }

                return hr;
            }

            STDMETHOD(Draw)(
                _In_opt_ void *clientDrawingContext,
                _In_ IDWriteTextRenderer *renderer,
                FLOAT originX,
                FLOAT originY,
                BOOL isSideways,
                BOOL isRightToLeft,
                _In_opt_ IUnknown *clientDrawingEffect
                ) override
            {
                return E_NOTIMPL;
            }

            STDMETHOD(GetMetrics)(
                _Out_ ::DWRITE_INLINE_OBJECT_METRICS *metrics
                ) override
            {
                return m_getMetrics(metrics);
            }

            STDMETHOD(GetOverhangMetrics)(
                _Out_ ::DWRITE_OVERHANG_METRICS *overhangs
                ) override
            {
                return m_getOverhangMetrics(overhangs);
            }

            STDMETHOD(GetBreakConditions)(
                _Out_ ::DWRITE_BREAK_CONDITION *breakConditionBefore,
                _Out_ ::DWRITE_BREAK_CONDITION *breakConditionAfter
                ) override
            {
                return m_getBreakConditions(breakConditionBefore, breakConditionAfter);
            }
        };

        /// <summary>
        /// The IDWriteInlineObject interface wraps an application defined inline graphic,
        /// allowing DWrite to query metrics as if it was a glyph inline with the text.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("8339FDE3-106F-47ab-8373-1C6295EB10B3")]
        public ref class IDWriteInlineObject abstract : DWriteNet::IDirectWriteObject
        {
        protected:
            delegate HRESULT FnMet(::DWRITE_INLINE_OBJECT_METRICS *);
            delegate HRESULT FnOhMet(::DWRITE_OVERHANG_METRICS *);
            delegate HRESULT FnBC(::DWRITE_BREAK_CONDITION *, ::DWRITE_BREAK_CONDITION *);

        internal:
            ::IDWriteInlineObject *m_pObject;

            static Dictionary<System::IntPtr, DWriteNet::IDWriteInlineObject ^> ^objList = gcnew Dictionary<System::IntPtr, DWriteNet::IDWriteInlineObject ^>();

        private:
            GCHandle m_getMetrics;
            GCHandle m_getOverhangMetrics;
            GCHandle m_getBreakConditions;

        internal:
            // For CreateEllipsisTrimmingSign.
            IDWriteInlineObject(::IDWriteInlineObject *pObject);

        protected:
            /// <summary>
            /// The basic constructor of IDWriteInlineObject. You should call this ctor when you
            /// implement the inline object.
            /// </summary>
            IDWriteInlineObject();

        public:
            ~IDWriteInlineObject();
            !IDWriteInlineObject();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pObject;
                }
            }

            virtual void HandleCOMInterface(void *obj) sealed;

        private:
            HRESULT GetMetricsInternal(::DWRITE_INLINE_OBJECT_METRICS *metrics);

            HRESULT GetOverhangMetricsInternal(::DWRITE_OVERHANG_METRICS *overhangs);

            HRESULT GetBreakConditionsInternal(
                ::DWRITE_BREAK_CONDITION *breakConditionBefore,
                ::DWRITE_BREAK_CONDITION *breakConditionAfter
            );

        public:
            // Draw

            virtual HRESULT GetMetrics(
                [OutAttribute] DWriteNet::DWRITE_INLINE_OBJECT_METRICS %metrics
            ) abstract;

            virtual HRESULT GetOverhangMetrics(
                [OutAttribute] DWriteNet::DWRITE_OVERHANG_METRICS %overhangs
            ) abstract;

            virtual HRESULT GetBreakConditions(
                [OutAttribute] DWriteNet::DWRITE_BREAK_CONDITION %breakConditionBefore,
                [OutAttribute] DWriteNet::DWRITE_BREAK_CONDITION %breakConditionAfter
            ) abstract;
        };

        ref class IDWriteFactory;
        ref class IDWriteTextFormat;

        ref class EllipsisInlineObject : DWriteNet::IDWriteInlineObject
        {
        internal:
            EllipsisInlineObject(
                DWriteNet::IDWriteFactory ^factory,
                DWriteNet::IDWriteTextFormat ^format);

        public:
            virtual HRESULT GetMetrics(
                [OutAttribute] DWriteNet::DWRITE_INLINE_OBJECT_METRICS %metrics
            ) override;

            virtual HRESULT GetOverhangMetrics(
                [OutAttribute] DWriteNet::DWRITE_OVERHANG_METRICS %overhangs
            ) override;

            virtual HRESULT GetBreakConditions(
                [OutAttribute] DWriteNet::DWRITE_BREAK_CONDITION %breakConditionBefore,
                [OutAttribute] DWriteNet::DWRITE_BREAK_CONDITION %breakConditionAfter
            ) override;
        };
    }
}