#include "ID2D1Device2.h"
#include "ID2D1Factory3.h"
#include "../DXGINet/IDXGIDevice.h"
#include "ID2D1Bitmap.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Device2::ID2D1Device2(Direct2DNet::ID2D1Factory3 ^factory, DXGINet::IDXGIDevice ^device)
            : Direct2DNet::ID2D1Device1(factory), m_device(device)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory3 *)factory->m_pFactory)->CreateDevice(
                device->m_pDevice,
                (::ID2D1Device2 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Device2", (int)hr);
        }

        void ID2D1Device2::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Device1::HandleCOMInterface(obj);

            ::IDXGIDevice *device = __nullptr;
            HRESULT hr = ((::ID2D1Device2 *)m_pResource)->GetDxgiDevice(&device);
            if(FAILED(hr))
                m_device = nullptr;
            else
                m_device = gcnew DXGINet::IDXGIDevice(device);
        }

        void ID2D1Device2::FlushDeviceContexts(Direct2DNet::ID2D1Bitmap ^bitmap)
        {
            ((::ID2D1Device2 *)m_pResource)->FlushDeviceContexts((::ID2D1Bitmap *)bitmap->m_pResource);
        }

        System::ValueTuple<HRESULT, DXGINet::IDXGIDevice ^> ID2D1Device2::GetDxgiDevice()
        {
            if(m_device)
            {
                return System::ValueTuple<HRESULT, DXGINet::IDXGIDevice ^>(S_OK, m_device);
            }

            ::IDXGIDevice *device = __nullptr;
            HRESULT hr = ((::ID2D1Device2 *)m_pResource)->GetDxgiDevice(&device);
            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, DXGINet::IDXGIDevice ^>(hr, nullptr);
            }
            else
            {
                m_device = gcnew DXGINet::IDXGIDevice(device);
                System::ValueTuple<HRESULT, DXGINet::IDXGIDevice ^>(hr, m_device);
            }
        }

        HRESULT ID2D1Device2::GetDxgiDevice(DXGINet::IDXGIDevice ^%dxgiDevice)
        {
            if(m_device)
            {
                dxgiDevice = m_device;
                return S_OK;
            }

            ::IDXGIDevice *device = __nullptr;
            HRESULT hr = ((::ID2D1Device2 *)m_pResource)->GetDxgiDevice(&device);
            if(FAILED(hr))
            {
                dxgiDevice = nullptr;
                return hr;
            }
            else
            {
                m_device = gcnew DXGINet::IDXGIDevice(device);
                dxgiDevice = m_device;
                return hr;
            }
        }

    }
}