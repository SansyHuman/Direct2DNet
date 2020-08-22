#include "ID2D1Device1.h"
#include "ID2D1Factory2.h"
#include "ID2D1DeviceContext1.h"
#include "../DXGINet/IDXGIDevice.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Device1::ID2D1Device1(Direct2DNet::ID2D1Factory2 ^factory, DXGINet::IDXGIDevice ^device)
            : Direct2DNet::ID2D1Device(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory2 *)factory->m_pFactory)->CreateDevice(
                (::IDXGIDevice *)device->m_pObj,
                (::ID2D1Device1 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Device1", (int)hr);
        }

        Direct2DNet::ID2D1DeviceContext1 ^ID2D1Device1::CreateDeviceContext1(
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
        {
            return gcnew Direct2DNet::ID2D1DeviceContext1(this, options);
        }

    }
}