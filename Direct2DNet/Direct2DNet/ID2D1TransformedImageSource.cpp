#include "ID2D1TransformedImageSource.h"
#include "ID2D1DeviceContext2.h"
#include "ID2D1ImageSource.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1TransformedImageSource::ID2D1TransformedImageSource(
            Direct2DNet::ID2D1DeviceContext2 ^context,
            Direct2DNet::ID2D1ImageSource ^imageSource,
            Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES %properties)
            : Direct2DNet::ID2D1Image(context->m_factory), m_source(imageSource), m_properties(properties)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            pin_ptr<Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES> pProp = &properties;
            hr = ((::ID2D1DeviceContext2 *)context->m_pResource)->CreateTransformedImageSource(
                (::ID2D1ImageSource *)imageSource->m_pResource,
                reinterpret_cast<::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES *>(pProp),
                (::ID2D1TransformedImageSource **)ppResource
            );
            ppResource = nullptr;
            pProp = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1TransformedImageSource", (int)hr);
        }

        void ID2D1TransformedImageSource::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Image::HandleCOMInterface(obj);

            ::ID2D1ImageSource *source = __nullptr;
            ((::ID2D1TransformedImageSource *)m_pResource)->GetSource(&source);
            if(!source)
                m_source = nullptr;
            else
            {
                m_source = gcnew Direct2DNet::ID2D1ImageSource();
                m_source->HandleCOMInterface(source);
                source->Release();
            }

            pin_ptr<Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES> pProps = &m_properties;
            ((::ID2D1TransformedImageSource *)m_pResource)->GetProperties(
                reinterpret_cast<::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES *>(pProps)
            );
            pProps = nullptr;
        }

        Direct2DNet::ID2D1ImageSource ^ID2D1TransformedImageSource::Source::get()
        {
            if(m_source)
                return m_source;

            ::ID2D1ImageSource *source = __nullptr;
            ((::ID2D1TransformedImageSource *)m_pResource)->GetSource(&source);
            if(!source)
                m_source = nullptr;
            else
            {
                m_source = gcnew Direct2DNet::ID2D1ImageSource();
                m_source->HandleCOMInterface(source);
                source->Release();
            }

            return m_source;
        }

    }
}