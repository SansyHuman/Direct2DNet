#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "IDXGIDeviceSubObject.h"
#include "../IUnknown.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIFactory;
        ref class IDXGISurface;
       
        [System::Runtime::InteropServices::GuidAttribute("310d36a0-d2e7-4c0a-aa04-6a9d23b8886a")]
        public ref class IDXGISwapChain : DXGINet::IDXGIDeviceSubObject
        {
        internal:
            IDXGISwapChain(
                DXGINet::IDXGIFactory ^factory,
                D2DNet::IUnknown ^device,
                DXGINet::DXGI_SWAP_CHAIN_DESC %desc
            );

        public:
            HRESULT Present(
                unsigned int syncInterval,
                DXGINet::DXGI_PRESENT flags
            );

            DXGINet::IDXGISurface ^GetBufferAsDXGISurface(
                unsigned int buffer,
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::Guid %guid
            );

            // SetFullscreenState

            // GetFullscreenState

            System::ValueTuple<HRESULT, DXGINet::DXGI_SWAP_CHAIN_DESC> GetDesc();

            HRESULT GetDesc(
                [InteropServices::OutAttribute] DXGINet::DXGI_SWAP_CHAIN_DESC %desc
            );

            HRESULT ResizeBuffers(
                unsigned int bufferCount,
                unsigned int width,
                unsigned int height,
                DXGINet::DXGI_FORMAT newFormat,
                DXGINet::DXGI_SWAP_CHAIN_FLAG swapChainFlags);

            HRESULT ResizeTarget(
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_MODE_DESC %newTargetParameters
            );

            // GetContainingOutput

            System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS> GetFrameStatistics();

            HRESULT GetFrameStatistics(
                [InteropServices::OutAttribute] DXGINet::DXGI_FRAME_STATISTICS %stats
            );

            System::ValueTuple<HRESULT, unsigned int> GetLastPresentCount();

            HRESULT GetLastPresentCount(
                [InteropServices::OutAttribute] unsigned int %lastPresentCount
            );
        };
        
    }
}