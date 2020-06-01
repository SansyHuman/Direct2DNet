#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "IDXGIDeviceSubObject.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        [System::Runtime::InteropServices::GuidAttribute("B9A14584-BCBB-4F29-A109-94A02A80EF3B")]
        public ref class IDXGISurface : DXGINet::IDXGIDeviceSubObject
        {
        public:
            // Called by IDXGISwapChain::GetBufferAsDXGISurface
            IDXGISurface(::IDXGISurface *pSurface);

            System::ValueTuple<HRESULT, DXGINet::DXGI_SURFACE_DESC> GetDesc();

            HRESULT GetDesc(
                [InteropServices::OutAttribute] DXGINet::DXGI_SURFACE_DESC %desc
            );

            System::ValueTuple<HRESULT, DXGINet::DXGI_MAPPED_RECT> Map(DXGINet::DXGI_MAP mapFlags);

            HRESULT Map(
                DXGINet::DXGI_MAP mapFlags,
                [InteropServices::OutAttribute] DXGINet::DXGI_MAPPED_RECT %lockedRect
            );

            HRESULT Unmap();

        };
    }
}