#include "ID2D1CommandList.h"
#include "ID2D1DeviceContext.h"
#include "ID2D1CommandSink.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1CommandList::ID2D1CommandList(Direct2DNet::ID2D1DeviceContext ^deviceContext)
            : Direct2DNet::ID2D1Image(deviceContext->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateCommandList(
                (::ID2D1CommandList **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1CommandList", (int)hr);
        }

        HRESULT ID2D1CommandList::Stream(Direct2DNet::ID2D1CommandSink ^sink)
        {
            return ((::ID2D1CommandList *)m_pResource)->Stream(sink->m_pSink);
        }

        HRESULT ID2D1CommandList::Close()
        {
            return ((::ID2D1CommandList *)m_pResource)->Close();
        }

    }
}