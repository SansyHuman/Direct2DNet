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
        [System::Runtime::InteropServices::GuidAttribute("cafcb56c-6ac3-4889-bf47-9e23bbd260ec")]
        public ref class IDXGISurface : DXGINet::IDXGIDeviceSubObject
        {
        internal:
            IDXGISurface() : DXGINet::IDXGIDeviceSubObject() {}

            // Called by IDXGISwapChain::GetBufferAsDXGISurface
            IDXGISurface(::IDXGISurface *pSurface);

        public:
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