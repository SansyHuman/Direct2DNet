#include "IDXGISurface.h"
#include "IDXGIDevice.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGISurface::IDXGISurface(::IDXGISurface *pSurface) : DXGINet::IDXGIDeviceSubObject()
        {
            m_pObj = pSurface;
        }

        IDXGISurface::IDXGISurface(
            DXGINet::IDXGIDevice ^device,
            DXGINet::DXGI_SURFACE_DESC %desc,
            UINT numSurfaces,
            DXGINet::DXGI_USAGE usage,
            DXGINet::DXGI_CPU_ACCESS cpuAccess,
            System::Nullable<System::IntPtr> %sharedResource)
        {
            pin_ptr<::IDXGIObject *> ppSurf = &m_pObj;

            pin_ptr<DXGINet::DXGI_SURFACE_DESC> pDesc = &desc;
            ::DXGI_SHARED_RESOURCE resource = { 0 };
            resource.Handle = sharedResource.HasValue ? (HANDLE)sharedResource.Value.ToPointer() : __nullptr;

            HRESULT hr = ((::IDXGIDevice *)device->m_pObj)->CreateSurface(
                reinterpret_cast<::DXGI_SURFACE_DESC *>(pDesc),
                numSurfaces,
                (::DXGI_USAGE)usage | (::DXGI_USAGE)cpuAccess,
                sharedResource.HasValue ? &resource : __nullptr,
                (::IDXGISurface **)ppSurf
            );
            ppSurf = nullptr;

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to create IDXGISurface.", (int)hr);
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_SURFACE_DESC> IDXGISurface::GetDesc()
        {
            ::DXGI_SURFACE_DESC desc;
            HRESULT hr = ((::IDXGISurface *)m_pObj)->GetDesc(&desc);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_SURFACE_DESC>(
                hr,
                static_cast<DXGINet::DXGI_SURFACE_DESC>(desc)
                );
        }

        HRESULT IDXGISurface::GetDesc(DXGINet::DXGI_SURFACE_DESC %desc)
        {
            ::DXGI_SURFACE_DESC nativeDesc;
            HRESULT hr = ((::IDXGISurface *)m_pObj)->GetDesc(&nativeDesc);

            desc = static_cast<DXGINet::DXGI_SURFACE_DESC>(nativeDesc);

            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_MAPPED_RECT> IDXGISurface::Map(DXGINet::DXGI_MAP mapFlags)
        {
            ::DXGI_MAPPED_RECT rect;

            HRESULT hr = ((::IDXGISurface *)m_pObj)->Map(&rect, (UINT)mapFlags);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_MAPPED_RECT>(
                hr,
                static_cast<DXGINet::DXGI_MAPPED_RECT>(rect)
                );
        }

        HRESULT IDXGISurface::Map(DXGINet::DXGI_MAP mapFlags, DXGINet::DXGI_MAPPED_RECT %lockedRect)
        {
            ::DXGI_MAPPED_RECT rect;

            HRESULT hr = ((::IDXGISurface *)m_pObj)->Map(&rect, (UINT)mapFlags);
            lockedRect = static_cast<DXGINet::DXGI_MAPPED_RECT>(rect);

            return hr;
        }

        HRESULT IDXGISurface::Unmap()
        {
            return ((::IDXGISurface *)m_pObj)->Unmap();
        }

    }
}