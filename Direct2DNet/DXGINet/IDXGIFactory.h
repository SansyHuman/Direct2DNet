#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../Direct2DNet/Exception/DXException.h"
#include "../IUnknown.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGISwapChain;

        [System::Runtime::InteropServices::GuidAttribute("7b7166ec-21c7-44ae-b21a-c9ae321ae369")]
        public ref class IDXGIFactory : DXGINet::IDXGIObject
        {
        internal:
            ::IDXGIFactory *m_pFactory;

        public:
            // Called by IDXGIAdapter::GetParentFactory
            IDXGIFactory(::IDXGIFactory *pFactory);

        public:
            IDXGIFactory();
            ~IDXGIFactory();
            !IDXGIFactory();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pFactory;
                }
            }

            // EnumAdapters

            // MakeWindowAssociation

            // GetWindowAssociation

            DXGINet::IDXGISwapChain ^CreateSwapChain(
                D2DNet::IUnknown ^device,
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_SWAP_CHAIN_DESC %desc
            );

        };
    }
}