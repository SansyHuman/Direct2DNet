#include "ID2D1RadialGradientBrush.h"
#include "ID2D1RenderTarget.h"

namespace Direct2DNet
{
    ID2D1RadialGradientBrush::ID2D1RadialGradientBrush(
        Direct2DNet::ID2D1RenderTarget ^renderTarget,
        Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES %properties,
        Direct2DNet::ID2D1GradientStopCollection ^collection
    ) : Direct2DNet::ID2D1Brush(renderTarget->m_factory), m_collection(collection)
    {
        HRESULT hr = S_OK;
        pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
        hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateRadialGradientBrush(
            static_cast<::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES>(properties),
            (::ID2D1GradientStopCollection *)collection->m_pResource,
            (::ID2D1RadialGradientBrush **)ppBrush
        );
        ppBrush = nullptr;

        if(FAILED(hr))
            throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1RadialGradientBrush", (int)hr);
    }
}