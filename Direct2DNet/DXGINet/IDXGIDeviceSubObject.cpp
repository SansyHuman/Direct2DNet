#include "IDXGIDeviceSubObject.h"
#include "IDXGIDevice.h"
#include "../GUIDs.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIDeviceSubObject::~IDXGIDeviceSubObject()
        {
            this->!IDXGIDeviceSubObject();
        }

        IDXGIDeviceSubObject::!IDXGIDeviceSubObject()
        {
            if(m_pSubObject)
            {
                m_pSubObject->Release();
                m_pSubObject = nullptr;
            }
        }

        void IDXGIDeviceSubObject::HandleCOMInterface(void *obj)
        {
            if(m_pSubObject)
            {
                m_pSubObject->Release();
            }

            m_pSubObject = (::IDXGIDeviceSubObject *)obj;
            m_pSubObject->AddRef();
        }

        HRESULT IDXGIDeviceSubObject::GetDevice(
            System::Guid %guid,
            DXGINet::IDXGIDevice ^%device)
        {
            ::IDXGIDevice *pDevice = __nullptr;
            HRESULT hr = m_pSubObject->GetDevice(DirectX::ToNativeGUID(guid), (void **)&pDevice);

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