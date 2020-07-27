#include "IDXGIDevice.h"
#include "IDXGIAdapter.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIDevice::IDXGIDevice(::IDXGIDevice *pDevice) : m_pDevice(pDevice)
        {
            
        }

        IDXGIDevice::~IDXGIDevice()
        {
            this->!IDXGIDevice();
        }

        IDXGIDevice::!IDXGIDevice()
        {
            if(m_pDevice)
            {
                m_pDevice->Release();
                m_pDevice = nullptr;
            }
        }

        void IDXGIDevice::HandleCOMInterface(void *obj)
        {
            if(m_pDevice)
            {
                m_pDevice->Release();
            }

            m_pDevice = (::IDXGIDevice *)obj;
            m_pDevice->AddRef();
        }

        DXGINet::IDXGIAdapter ^IDXGIDevice::GetAdapter()
        {
            ::IDXGIAdapter *pAdapter = __nullptr;

            HRESULT hr = m_pDevice->GetAdapter(&pAdapter);

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to get IDXGIAdapter", hr
                );

            return gcnew DXGINet::IDXGIAdapter(pAdapter);
        }

    }
}