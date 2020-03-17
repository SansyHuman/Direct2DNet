#include "ID2D1StrokeStyle.h"
#include "ID2D1Factory.h"

namespace Direct2DNet
{
    ID2D1StrokeStyle::ID2D1StrokeStyle(
        Direct2DNet::ID2D1Factory ^factory,
        Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES properties,
        array<float> ^dashes
    ) : Direct2DNet::ID2D1Resource(factory)
    {
        HRESULT hr = S_OK;
        pin_ptr<float> pDashes = &dashes[0];
        pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
        hr = factory->m_pFactory->CreateStrokeStyle(
            static_cast<::D2D1_STROKE_STYLE_PROPERTIES>(properties),
            (float *)pDashes,
            dashes->Length,
            (::ID2D1StrokeStyle **)ppResource
        );
        pDashes = nullptr;
        ppResource = nullptr;

        if(FAILED(hr))
            throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1StrokeStyle", (int)hr);
    }
}