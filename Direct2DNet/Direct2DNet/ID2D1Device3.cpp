#include "ID2D1Device3.h"
#include "ID2D1Factory4.h"
#include "../DXGINet/IDXGIDevice.h"
#include "ID2D1DeviceContext3.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Device3::ID2D1Device3(Direct2DNet::ID2D1Factory4 ^factory, DXGINet::IDXGIDevice ^device)
            : Direct2DNet::ID2D1Device2(factory, device)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory4 *)factory->m_pFactory)->CreateDevice(
                (::IDXGIDevice *)device->m_pObj,
                (::ID2D1Device3 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Device3", (int)hr);
        }

        Direct2DNet::ID2D1DeviceContext3 ^ID2D1Device3::CreateDeviceContext3(
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
        {
            return gcnew Direct2DNet::ID2D1DeviceContext3(this, options);
        }

    }
}