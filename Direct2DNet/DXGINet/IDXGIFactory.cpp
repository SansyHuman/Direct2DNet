#include "IDXGIFactory.h"
#include "IDXGISwapChain.h"
#include "IDXGIAdapter.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIFactory::IDXGIFactory(::IDXGIFactory *pFactory) : DXGINet::IDXGIObject()
        {
            m_pObj = pFactory;
        }

        IDXGIFactory::IDXGIFactory(int) : DXGINet::IDXGIObject()
        {
            HRESULT hr = S_OK;
            pin_ptr<::IDXGIObject *> ppFactory = &m_pObj;
            hr = ::CreateDXGIFactory(__uuidof(::IDXGIFactory), (void **)ppFactory);
            ppFactory = nullptr;

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to create IDXGIFactory", (int)hr);
        }

        DXGINet::IDXGIFactory ^IDXGIFactory::CreateFactory()
        {
            return gcnew DXGINet::IDXGIFactory(1);
        }

        HRESULT IDXGIFactory::EnumAdapters(UINT index, DXGINet::IDXGIAdapter ^%adapter)
        {
            ::IDXGIAdapter *pAdapter = __nullptr;

            HRESULT hr = ((::IDXGIFactory *)m_pObj)->EnumAdapters(index, &pAdapter);
            if(FAILED(hr) || !pAdapter)
            {
                adapter = nullptr;
                return hr;
            }

            adapter = gcnew DXGINet::IDXGIAdapter(pAdapter);
            return hr;
        }

        HRESULT IDXGIFactory::MakeWindowAssociation(System::IntPtr %windowHandle, DXGINet::DXGI_MWA flags)
        {
            return ((::IDXGIFactory *)m_pObj)->MakeWindowAssociation(
                (HWND)windowHandle.ToPointer(), (UINT)flags
            );
        }

        HRESULT IDXGIFactory::GetWindowAssociation(System::IntPtr %windowHandle)
        {
            HWND handle = __nullptr;
            HRESULT hr = ((::IDXGIFactory *)m_pObj)->GetWindowAssociation(&handle);

            if(FAILED(hr) || !handle)
            {
                windowHandle = System::IntPtr::Zero;
                return hr;
            }

            windowHandle = System::IntPtr(handle);
            return hr;
        }

        System::ValueTuple<HRESULT, System::IntPtr> IDXGIFactory::GetWindowAssociation()
        {
            HWND handle = __nullptr;
            HRESULT hr = ((::IDXGIFactory *)m_pObj)->GetWindowAssociation(&handle);

            if(FAILED(hr) || !handle)
            {
                return System::ValueTuple<HRESULT, System::IntPtr>(hr, System::IntPtr::Zero);
            }

            return System::ValueTuple<HRESULT, System::IntPtr>(hr, System::IntPtr(handle));
        }

        DXGINet::IDXGISwapChain ^IDXGIFactory::CreateSwapChain(
            D2DNet::IUnknown ^device,
            DXGINet::DXGI_SWAP_CHAIN_DESC %desc)
        {
            return gcnew DXGINet::IDXGISwapChain(this, device, desc);
        }

        DXGINet::IDXGIAdapter ^IDXGIFactory::CreateSoftwareAdapter(System::IntPtr %module)
        {
            return gcnew DXGINet::IDXGIAdapter(this, module);
        }

    }
}