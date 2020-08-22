#include "IDXGIDevice.h"
#include "IDXGIAdapter.h"
#include "IDXGISurface.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIDevice::IDXGIDevice(::IDXGIDevice *pDevice) : DXGINet::IDXGIObject()
        {
            m_pObj = pDevice;
        }

        HRESULT IDXGIDevice::GetAdapter(DXGINet::IDXGIAdapter ^%adapter)
        {
            ::IDXGIAdapter *pAdapter = __nullptr;

            HRESULT hr = ((::IDXGIDevice *)m_pObj)->GetAdapter(&pAdapter);

            if(FAILED(hr))
            {
                adapter = nullptr;
                return hr;
            }

            adapter = gcnew DXGINet::IDXGIAdapter(pAdapter);
            return hr;
        }

        DXGINet::IDXGISurface ^IDXGIDevice::CreateSurface(
            DXGINet::DXGI_SURFACE_DESC %desc,
            UINT numSurfaces,
            DXGINet::DXGI_USAGE usage,
            DXGINet::DXGI_CPU_ACCESS cpuAccess,
            System::Nullable<System::IntPtr> sharedResource)
        {
            return gcnew DXGINet::IDXGISurface(this, desc, numSurfaces, usage, cpuAccess, sharedResource);
        }

        HRESULT IDXGIDevice::QueryResourceResidency(
            array<D2DNet::IUnknown ^> ^resources,
            array<DXGINet::DXGI_RESIDENCY> ^residencyStatus)
        {
            if(resources->Length != residencyStatus->Length)
                return E_INVALIDARG;

            UINT numResources = resources->Length;

            std::vector<::IUnknown *> pResources(numResources);

            for(UINT i = 0; i < numResources; i++)
            {
                pResources[i] = (::IUnknown *)resources[i]->NativePointer;
            }

            pin_ptr<DXGINet::DXGI_RESIDENCY> pResidency = &residencyStatus[0];

            return ((::IDXGIDevice *)m_pObj)->QueryResourceResidency(
                pResources.data(),
                reinterpret_cast<::DXGI_RESIDENCY *>(pResidency),
                numResources
            );
        }

        HRESULT IDXGIDevice::SetGPUThreadPriority(DXGINet::DXGI_GPU_THREAD_PRIORITY priority)
        {
            return ((::IDXGIDevice *)m_pObj)->SetGPUThreadPriority((INT)priority);
        }

        HRESULT IDXGIDevice::GetGPUThreadPriority(DXGINet::DXGI_GPU_THREAD_PRIORITY %priority)
        {
            INT pr = 0;
            HRESULT hr = ((::IDXGIDevice *)m_pObj)->GetGPUThreadPriority(&pr);

            priority = (DXGINet::DXGI_GPU_THREAD_PRIORITY)pr;
            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_GPU_THREAD_PRIORITY> IDXGIDevice::GetGPUThreadPriority()
        {
            INT pr = 0;
            HRESULT hr = ((::IDXGIDevice *)m_pObj)->GetGPUThreadPriority(&pr);

           return System::ValueTuple<HRESULT, DXGINet::DXGI_GPU_THREAD_PRIORITY>(
               hr, (DXGINet::DXGI_GPU_THREAD_PRIORITY)pr);
        }

    }
}