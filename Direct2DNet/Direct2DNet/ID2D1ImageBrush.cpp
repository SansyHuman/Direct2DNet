#include "ID2D1ImageBrush.h"
#include "ID2D1Image.h"
#include "ID2D1DeviceContext.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1ImageBrush::ID2D1ImageBrush(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            Direct2DNet::ID2D1Image ^image,
            Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES %properties
        ) : Direct2DNet::ID2D1Brush(deviceContext->m_factory), m_image(image)
        {
            HRESULT hr = S_OK;
            pin_ptr<Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES> pProperties = &properties;
            pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateImageBrush(
                image == nullptr ? __nullptr : (::ID2D1Image *)image->m_pResource,
                reinterpret_cast<::D2D1_IMAGE_BRUSH_PROPERTIES *>(pProperties),
                __nullptr,
                (::ID2D1ImageBrush **)ppBrush
            );
            pProperties = nullptr;
            ppBrush = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1ImageBrush", (int)hr);
        }

        void ID2D1ImageBrush::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Brush::HandleCOMInterface(obj);

            ::ID2D1Image *image = __nullptr;
            ((::ID2D1ImageBrush *)m_pResource)->GetImage(&image);
            if(!image)
                m_image = nullptr;
            else
            {
                ::ID2D1Factory *factory = __nullptr;
                m_pResource->GetFactory(&factory);
                m_image = gcnew Direct2DNet::ID2D1Image(
                    gcnew Direct2DNet::ID2D1Factory(factory), image
                );
            }
        }

        void ID2D1ImageBrush::Image::set(Direct2DNet::ID2D1Image ^value)
        {
            ((::ID2D1ImageBrush *)m_pResource)->SetImage(
                value == nullptr ? __nullptr : (::ID2D1Image *)value->m_pResource
            );
            m_image = value;
        }
    }
}