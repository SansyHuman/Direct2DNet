#include "IDXGISurface.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGISurface::IDXGISurface(::IDXGISurface *pSurface) : DXGINet::IDXGIDeviceSubObject()
        {
            m_pSubObject = pSurface;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_SURFACE_DESC> IDXGISurface::GetDesc()
        {
            ::DXGI_SURFACE_DESC desc;
            HRESULT hr = ((::IDXGISurface *)m_pSubObject)->GetDesc(&desc);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_SURFACE_DESC>(
                hr,
                static_cast<DXGINet::DXGI_SURFACE_DESC>(desc)
                );
        }

        HRESULT IDXGISurface::GetDesc(DXGINet::DXGI_SURFACE_DESC %desc)
        {
            ::DXGI_SURFACE_DESC nativeDesc;
            HRESULT hr = ((::IDXGISurface *)m_pSubObject)->GetDesc(&nativeDesc);

            desc = static_cast<DXGINet::DXGI_SURFACE_DESC>(nativeDesc);

            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_MAPPED_RECT> IDXGISurface::Map(DXGINet::DXGI_MAP mapFlags)
        {
            ::DXGI_MAPPED_RECT rect;

            HRESULT hr = ((::IDXGISurface *)m_pSubObject)->Map(&rect, (UINT)mapFlags);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_MAPPED_RECT>(
                hr,
                static_cast<DXGINet::DXGI_MAPPED_RECT>(rect)
                );
        }

        HRESULT IDXGISurface::Map(DXGINet::DXGI_MAP mapFlags, DXGINet::DXGI_MAPPED_RECT %lockedRect)
        {
            ::DXGI_MAPPED_RECT rect;

            HRESULT hr = ((::IDXGISurface *)m_pSubObject)->Map(&rect, (UINT)mapFlags);
            lockedRect = static_cast<DXGINet::DXGI_MAPPED_RECT>(rect);

            return hr;
        }

        HRESULT IDXGISurface::Unmap()
        {
            return ((::IDXGISurface *)m_pSubObject)->Unmap();
        }

    }
}