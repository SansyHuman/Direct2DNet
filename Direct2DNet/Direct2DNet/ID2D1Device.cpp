#include "ID2D1Device.h"
#include "ID2D1Factory1.h"
#include "ID2D1DeviceContext.h"
#include "../DXGINet/IDXGIDevice.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Device::ID2D1Device(
            Direct2DNet::ID2D1Factory1 ^factory,
            DXGINet::IDXGIDevice ^device) : Direct2DNet::ID2D1Resource(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory1 *)factory->m_pFactory)->CreateDevice(
                device->m_pDevice,
                (::ID2D1Device **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Device", (int)hr);
        }

        Direct2DNet::ID2D1DeviceContext ^ID2D1Device::CreateDeviceContext(
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
        {
            return gcnew Direct2DNet::ID2D1DeviceContext(this, options);
        }

        void ID2D1Device::ClearResources(System::Nullable<UINT64> millisecondsSinceUse)
        {
            if(!millisecondsSinceUse.HasValue)
                millisecondsSinceUse = 0U;

            ((::ID2D1Device *)m_pResource)->ClearResources(millisecondsSinceUse.Value);
        }

    }
}