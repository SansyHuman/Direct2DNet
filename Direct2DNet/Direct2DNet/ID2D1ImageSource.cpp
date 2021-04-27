#include "ID2D1ImageSource.h"
#include "ID2D1DeviceContext2.h"
#include "../DXGINet/IDXGISurface.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1ImageSource::ID2D1ImageSource(
            Direct2DNet::ID2D1DeviceContext2 ^context,
            array<DXGINet::IDXGISurface ^> ^surfaces,
            DXGINet::DXGI_COLOR_SPACE_TYPE colorSpace,
            Direct2DNet::D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS options)
            : Direct2DNet::ID2D1Image(context->m_factory)
        {
            HRESULT hr = S_OK;

            std::vector<::IDXGISurface *> pSurfaces(surfaces->Length);
            for(int i = 0; i < surfaces->Length; i++)
            {
                pSurfaces[i] = (::IDXGISurface *)surfaces[i]->m_pObj;
            }

            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext2 *)context->m_pResource)->CreateImageSourceFromDxgi(
                pSurfaces.data(),
                pSurfaces.size(),
                (::DXGI_COLOR_SPACE_TYPE)((int)colorSpace),
                (::D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS)((int)options),
                (::ID2D1ImageSource **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1ImageSource", (int)hr);
        }

        ID2D1ImageSource::ID2D1ImageSource(Direct2DNet::ID2D1DeviceContext2 ^context)
            : Direct2DNet::ID2D1Image(context->m_factory)
        {
            
        }

        HRESULT ID2D1ImageSource::OfferResources()
        {
            return ((::ID2D1ImageSource *)m_pResource)->OfferResources();
        }

        HRESULT ID2D1ImageSource::TryReclaimResources(bool %resourcesDiscarded)
        {
            BOOL discarded = FALSE;
            HRESULT hr = ((::ID2D1ImageSource *)m_pResource)->TryReclaimResources(&discarded);
            resourcesDiscarded = System::Convert::ToBoolean(discarded);
            return hr;
        }

    }
}