#include "IDXGIFactory.h"
#include "IDXGISwapChain.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIFactory::IDXGIFactory(::IDXGIFactory *pFactory) : m_pFactory(pFactory)
        {
            
        }

        IDXGIFactory::IDXGIFactory(int)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IDXGIFactory *> ppFactory = &m_pFactory;
            hr = ::CreateDXGIFactory(__uuidof(::IDXGIFactory), (void **)ppFactory);
            ppFactory = nullptr;

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to create IDXGIFactory", (int)hr);
        }

        IDXGIFactory::~IDXGIFactory()
        {
            this->!IDXGIFactory();
        }

        IDXGIFactory::!IDXGIFactory()
        {
            if(m_pFactory)
            {
                m_pFactory->Release();
                m_pFactory = nullptr;
            }
        }

        DXGINet::IDXGIFactory ^IDXGIFactory::CreateFactory()
        {
            return gcnew DXGINet::IDXGIFactory(1);
        }

        void IDXGIFactory::HandleCOMInterface(void *obj)
        {
            if(m_pFactory)
            {
                m_pFactory->Release();
            }

            m_pFactory = (::IDXGIFactory *)obj;
            m_pFactory->AddRef();
        }

        DXGINet::IDXGISwapChain ^IDXGIFactory::CreateSwapChain(
            D2DNet::IUnknown ^device,
            DXGINet::DXGI_SWAP_CHAIN_DESC %desc)
        {
            return gcnew DXGINet::IDXGISwapChain(this, device, desc);
        }

    }
}