#include "IDXGIDeviceSubObject.h"
#include "IDXGIDevice.h"
#include "../GUIDs.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace DXGINet
    {
        HRESULT IDXGIDeviceSubObject::GetDevice(
            System::Guid %guid,
            DXGINet::IDXGIDevice ^%device)
        {
            ::IDXGIDevice *pDevice = __nullptr;
            HRESULT hr = ((::IDXGIDeviceSubObject *)m_pObj)->GetDevice(DirectX::ToNativeGUID(guid), (void **)&pDevice);

            if(FAILED(hr) || !pDevice)
            {
                device = nullptr;
                return hr;
            }

            if(guid == D2DNetGUID::UID_IDXGIDevice)
            {
                device = gcnew DXGINet::IDXGIDevice(pDevice);
                return hr;
            }
            else
            {
                pDevice->Release();
                device = nullptr;
                return DXGI_ERROR_INVALID_CALL;
            }
        }

    }
}