#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"

using namespace System;
using namespace System::Runtime;

#ifndef GCHandle
#define GCHandle InteropServices::GCHandle
#endif

#ifndef Marshal
#define Marshal InteropServices::Marshal
#endif

namespace D2DNet
{
    namespace Direct2DNet
    {
        using fnPrRec = HRESULT(__stdcall *)(DWORD, void *, DWORD);

        class ID2D1NativeGdiMetafileSink : public ::ID2D1GdiMetafileSink
        {
        private:
            UINT m_cRef;

        public:
            fnPrRec m_processRecord;

            ID2D1NativeGdiMetafileSink() : m_cRef(1) {}

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
                else if(__uuidof(::ID2D1GdiMetafileSink) == iid)
                {
                    *ppvObject = static_cast<::ID2D1GdiMetafileSink *>(this);
                    AddRef();
                }
                else
                {
                    *ppvObject = NULL;
                    hr = E_NOINTERFACE;
                }

                return hr;
            }

            STDMETHOD(ProcessRecord)(
                DWORD recordType,
                _In_opt_ CONST void *recordData,
                DWORD recordDataSize
                ) override
            {
                return m_processRecord(recordType, const_cast<void *>(recordData), recordDataSize);
            }
        };

        /// <summary>
        /// User-implementable interface for introspecting on a metafile.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("82237326-8111-4f7c-bcf4-b5c1175564fe")]
        public ref class ID2D1GdiMetafileSink abstract : Direct2DNet::IDirect2DObject
        {
        protected:
            delegate HRESULT FnPrRec(DWORD, void *, DWORD);

        internal:
            ::ID2D1GdiMetafileSink *m_pSink;

        private:
            GCHandle m_processRecord;

        protected:
            ID2D1GdiMetafileSink();

        public:
            ~ID2D1GdiMetafileSink();
            !ID2D1GdiMetafileSink();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return reinterpret_cast<void *>(m_pSink);
                }
            }

        protected:
            virtual HRESULT ProcessRecord(DWORD recordType, void *recordData, DWORD recordDataSize) abstract;
        };
    }
}