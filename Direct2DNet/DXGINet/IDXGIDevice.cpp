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

        HRESULT IDXGIDevice::GetAdapter(DXGINet::IDXGIAdapter ^%adapter)
        {
            ::IDXGIAdapter *pAdapter = __nullptr;

            HRESULT hr = m_pDevice->GetAdapter(&pAdapter);

            if(FAILED(hr))
            {
                adapter = nullptr;
                return hr;
            }

            adapter = gcnew DXGINet::IDXGIAdapter(pAdapter);
            return hr;
        }

    }
}