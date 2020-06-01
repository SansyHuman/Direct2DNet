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
            pin_ptr<float> pDashes = dashes == nullptr ? nullptr : &dashes[0];
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory1 *)factory->m_pFactory)->CreateStrokeStyle(
                static_cast<::D2D1_STROKE_STYLE_PROPERTIES1>(properties),
                (float *)pDashes,
                dashes == nullptr ? 0 : dashes->Length,
                (::ID2D1StrokeStyle1 **)ppResource
            );
            pDashes = nullptr;
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1StrokeStyle1", (int)hr);
        }

    }
}