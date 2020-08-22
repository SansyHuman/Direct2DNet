#include "IDXGIResource.h"

namespace D2DNet
{
    namespace DXGINet
    {
        HRESULT IDXGIResource::GetSharedHandle(System::IntPtr %sharedHandle)
        {
            HANDLE handle = __nullptr;
            HRESULT hr = ((::IDXGIResource *)m_pObj)->GetSharedHandle(&handle);
            sharedHandle = System::IntPtr(handle);
            return hr;
        }

        HRESULT IDXGIResource::GetUsage(DXGINet::DXGI_USAGE %usage, DXGINet::DXGI_CPU_ACCESS %cpuAccess)
        {
            ::DXGI_USAGE u;
            HRESULT hr = ((::IDXGIResource *)m_pObj)->GetUsage(&u);

            cpuAccess = (DXGINet::DXGI_CPU_ACCESS)(u & DXGI_CPU_ACCESS_FIELD);
            usage = (DXGINet::DXGI_USAGE)(u & ~DXGI_CPU_ACCESS_FIELD);

            return hr;
        }

        HRESULT IDXGIResource::SetEvictionPriority(UINT evictionPriority)
        {
            return ((::IDXGIResource *)m_pObj)->SetEvictionPriority(evictionPriority);
        }

        HRESULT IDXGIResource::GetEvictionPriority(UINT %evictionPriority)
        {
            UINT ep = 0U;
            HRESULT hr = ((::IDXGIResource *)m_pObj)->GetEvictionPriority(&ep);
            evictionPriority = ep;
            return hr;
        }

    }
}