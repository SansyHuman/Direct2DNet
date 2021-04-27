#include "ID2D1ImageSourceFromWic.h"
#include "ID2D1DeviceContext2.h"
#include "../WICNet/IWICBitmapSource.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1ImageSourceFromWic::ID2D1ImageSourceFromWic(
            Direct2DNet::ID2D1DeviceContext2 ^context,
            D2DNet::WICNet::IWICBitmapSource ^wicBitmapSource,
            Direct2DNet::D2D1_IMAGE_SOURCE_LOADING_OPTIONS loadingOptions,
            Direct2DNet::D2D1_ALPHA_MODE alphaMode)
            : Direct2DNet::ID2D1ImageSource(context)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext2 *)context->m_pResource)->CreateImageSourceFromWic(
                wicBitmapSource->m_pSource,
                (::D2D1_IMAGE_SOURCE_LOADING_OPTIONS)((int)loadingOptions),
                (::D2D1_ALPHA_MODE)((int)alphaMode),
                (::ID2D1ImageSourceFromWic **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1ImageSourceFromWic", (int)hr);

            m_source = wicBitmapSource;
        }

        void ID2D1ImageSourceFromWic::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1ImageSource::HandleCOMInterface(obj);

            ::IWICBitmapSource *source = __nullptr;
            ((::ID2D1ImageSourceFromWic *)m_pResource)->GetSource(&source);
            if(!source)
                m_source = nullptr;
            else
                m_source = gcnew WICNet::IWICBitmapSource(source);
        }

        HRESULT ID2D1ImageSourceFromWic::EnsureCached(System::Nullable<D2D1_RECT_U> rectangleToFill)
        {
            pin_ptr<D2D1_RECT_U> pRect = nullptr;
            if(rectangleToFill.HasValue)
                pRect = &rectangleToFill.Value;

            return ((::ID2D1ImageSourceFromWic *)m_pResource)->EnsureCached(
                (::D2D1_RECT_U *)pRect
            );
        }

        HRESULT ID2D1ImageSourceFromWic::TrimCache(System::Nullable<D2D1_RECT_U> rectangleToPreserve)
        {
            pin_ptr<D2D1_RECT_U> pRect = nullptr;
            if(rectangleToPreserve.HasValue)
                pRect = &rectangleToPreserve.Value;

            return ((::ID2D1ImageSourceFromWic *)m_pResource)->TrimCache(
                (::D2D1_RECT_U *)pRect
            );
        }

        D2DNet::WICNet::IWICBitmapSource ^ID2D1ImageSourceFromWic::Source::get()
        {
            if(m_source)
                return m_source;

            ::IWICBitmapSource *source = __nullptr;
            ((::ID2D1ImageSourceFromWic *)m_pResource)->GetSource(&source);
            if(!source)
                m_source = nullptr;
            else
                m_source = gcnew D2DNet::WICNet::IWICBitmapSource(source);

            return m_source;
        }

    }
}