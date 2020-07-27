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

        DXGINet::IDXGIFactory ^IDXGIAdapter::GetParentFactory(System::Guid %guid)
        {
            if(guid == D2DNetGUID::UID_IDXGIFactory)
            {
                ::IDXGIFactory *pFactory = __nullptr;
                HRESULT hr = m_pAdapter->GetParent(__uuidof(::IDXGIFactory), (void **)&pFactory);

                if(FAILED(hr))
                    throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                        "Failed to get parent IDXGIFactory", (int)hr);

                return gcnew DXGINet::IDXGIFactory(pFactory);
            }
            else
            {
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to get parent IDXGIFactory", DXGI_ERROR_INVALID_CALL);
            }
        }

    }
}