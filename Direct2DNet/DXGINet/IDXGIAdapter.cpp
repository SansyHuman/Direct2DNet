#include "IDXGIAdapter.h"
#include "IDXGIFactory.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIAdapter::IDXGIAdapter(::IDXGIAdapter *pAdapter) : m_pAdapter(pAdapter)
        {
            
        }

        IDXGIAdapter::~IDXGIAdapter()
        {
            this->!IDXGIAdapter();
        }

        IDXGIAdapter::!IDXGIAdapter()
        {
            if(m_pAdapter)
            {
                m_pAdapter->Release();
                m_pAdapter = nullptr;
            }
        }

        void IDXGIAdapter::HandleCOMInterface(void *obj)
        {
            if(m_pAdapter)
            {
                m_pAdapter->Release();
            }

            m_pAdapter = (::IDXGIAdapter *)obj;
            m_pAdapter->AddRef();
        }

        HRESULT IDXGIAdapter::GetParentFactory(System::Guid %guid, DXGINet::IDXGIFactory ^%factory)
        {
            if(guid == D2DNetGUID::UID_IDXGIFactory)
            {
                ::IDXGIFactory *pFactory = __nullptr;
                HRESULT hr = m_pAdapter->GetParent(__uuidof(::IDXGIFactory), (void **)&pFactory);

                if(FAILED(hr))
                {
                    factory = nullptr;
                    return hr;
                }

                factory = gcnew DXGINet::IDXGIFactory(pFactory);
                return hr;
            }
            else
            {
                factory = nullptr;
                return DXGI_ERROR_INVALID_CALL;
            }
        }
    }
}