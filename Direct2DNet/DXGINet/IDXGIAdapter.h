#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../GUIDs.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIFactory;

        [System::Runtime::InteropServices::GuidAttribute("8A1A53AF-AC5E-4A95-B01F-A077ED4E6018")]
        public ref class IDXGIAdapter : DXGINet::IDXGIObject
        {
        internal:
            ::IDXGIAdapter *m_pAdapter;

            // Called by IDXGIDevice::GetAdapter
            IDXGIAdapter(::IDXGIAdapter *pAdapter);

        public:
            ~IDXGIAdapter();
            !IDXGIAdapter();

        public:
            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pAdapter;
                }
            }

            property DXGINet::DXGI_ADAPTER_DESC AdapterDesc
            {
                DXGINet::DXGI_ADAPTER_DESC get()
                {
                    ::DXGI_ADAPTER_DESC nativeDesc;
                    m_pAdapter->GetDesc(&nativeDesc);

                    return static_cast<DXGINet::DXGI_ADAPTER_DESC>(nativeDesc);
                }
            }

            DXGINet::IDXGIFactory ^GetParentFactory(
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::Guid %guid);

        };
    }
}