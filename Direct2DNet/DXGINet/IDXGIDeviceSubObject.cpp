#include "IDXGIDeviceSubObject.h"
#include "IDXGIDevice.h"
#include "../GUIDs.h"

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

        DXGINet::IDXGIDevice ^IDXGIDeviceSubObject::GetDevice(System::Guid %guid)
        {
            if(guid == D2DNetGUID::UID_IDXGIDevice)
            {
                ::IDXGIDevice *pDevice = __nullptr;
                HRESULT hr = m_pSubObject->GetDevice(__uuidof(::IDXGIDevice), (void **)&pDevice);

                if(FAILED(hr))
                    throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                        "Failed to get related IDXGIDevice", (int)hr);

                return gcnew DXGINet::IDXGIDevice(pDevice);
            }
            else
            {
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to get related IDXGIDevice", DXGI_ERROR_INVALID_CALL);
            }
        }

    }
}