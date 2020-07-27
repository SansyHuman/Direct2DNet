#include "ID2D1StrokeStyle1.h"
#include "ID2D1Factory1.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1StrokeStyle1::ID2D1StrokeStyle1(
            Direct2DNet::ID2D1Factory1 ^factory,
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 %properties,
            array<float> ^dashes)
            : Direct2DNet::ID2D1StrokeStyle(factory, properties, dashes),
            m_transformType(properties.transformType)
        {
            HRESULT hr = S_OK;
            pin_ptr<Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1> pProperties = &properties;
            pin_ptr<float> pDashes = dashes == nullptr ? nullptr : &dashes[0];
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory1 *)factory->m_pFactory)->CreateStrokeStyle(
                reinterpret_cast<::D2D1_STROKE_STYLE_PROPERTIES1 *>(pProperties),
                (float *)pDashes,
                dashes == nullptr ? 0 : dashes->Length,
                (::ID2D1StrokeStyle1 **)ppResource
            );
            pProperties = nullptr;
            pDashes = nullptr;
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1StrokeStyle1", (int)hr);
        }

        void ID2D1StrokeStyle1::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1StrokeStyle::HandleCOMInterface(obj);

            m_transformType = (Direct2DNet::D2D1_STROKE_TRANSFORM_TYPE)((int)((::ID2D1StrokeStyle1 *)m_pResource)->GetStrokeTransformType());
        }

    }
}