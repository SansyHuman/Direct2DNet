#pragma once

#include "DXGINetHeaders.h"
#include "../IUnknown.h"

using namespace System::Runtime;

namespace D2DNet
{
    namespace DXGINet
    {
        /// <summary>
        /// An IDXGIObject interface is a base interface for all DXGI objects; IDXGIObject supports
        /// associating caller-defined (private data) with an object and retrieval of an interface to
        /// the parent object.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("aec22fb8-76f3-4639-9be0-28eb43a67a2e")]
        public ref class IDXGIObject : D2DNet::IUnknown
        {
        internal:
            ::IDXGIObject *m_pObj;

            IDXGIObject() : m_pObj(nullptr) {}

        public:
            ~IDXGIObject();
            !IDXGIObject();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pObj;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            HRESULT SetPrivateData(
                [InteropServices::InAttribute][CompilerServices::IsReadOnlyAttribute] System::Guid %name,
                UINT dataSize,
                void *pData
            );

            HRESULT SetPrivateDataInterface(
                [InteropServices::InAttribute][CompilerServices::IsReadOnlyAttribute] System::Guid %name,
                D2DNet::IUnknown ^unknown
            );

            HRESULT GetPrivateData(
                [InteropServices::InAttribute][CompilerServices::IsReadOnlyAttribute] System::Guid %name,
                UINT dataSize,
                void *pData
            );

            generic<typename T> where T : D2DNet::IUnknown
            HRESULT GetParent(
                [InteropServices::OutAttribute] T %parent
            );

            HRESULT GetParent(
                [InteropServices::InAttribute][CompilerServices::IsReadOnlyAttribute] System::Guid %riid,
                [InteropServices::OutAttribute] D2DNet::IUnknown ^%parent
            );

        };

    }
}