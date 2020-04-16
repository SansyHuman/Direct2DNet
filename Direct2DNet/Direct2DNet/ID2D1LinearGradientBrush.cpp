#include "ID2D1LinearGradientBrush.h"
#include "ID2D1RenderTarget.h"

namespace Direct2DNet
{
    ID2D1LinearGradientBrush::ID2D1LinearGradientBrush(
        Direct2DNet::ID2D1RenderTarget ^renderTarget,
        Direct2DNet::D2D1_POINT_2F %startPoint,
        Direct2DNet::D2D1_POINT_2F %endPoint,
        Direct2DNet::ID2D1GradientStopCollection ^collection
    ) : Direct2DNet::ID2D1Brush(renderTarget->m_factory), m_collection(collection)
    {
        HRESULT hr = S_OK;
        pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
        hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateLinearGradientBrush(
            D2D1::LinearGradientBrushProperties(
                static_cast<::D2D1_POINT_2F>(startPoint),
                static_cast<::D2D1_POINT_2F>(endPoint)
            ),
            (::ID2D1GradientStopCollection *)collection->m_pResource,
            (::ID2D1LinearGradientBrush **)ppBrush
        );
        ppBrush = nullptr;

        if(FAILED(hr))
            throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1LinearGradientBrush", (int)hr);
    }

    ID2D1LinearGradientBrush::ID2D1LinearGradientBrush(
        Direct2DNet::ID2D1RenderTarget ^renderTarget,
        Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES %properties,
        Direct2DNet::ID2D1GradientStopCollection ^collection
    ) : Direct2DNet::ID2D1Brush(renderTarget->m_factory), m_collection(collection)
    {
        HRESULT hr = S_OK;
        pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
        hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateLinearGradientBrush(
            static_cast<::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES>(properties),
            (::ID2D1GradientStopCollection *)collection->m_pResource,
            (::ID2D1LinearGradientBrush **)ppBrush
        );
        ppBrush = nullptr;

        if(FAILED(hr))
            throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1LinearGradientBrush", (int)hr);
    }
}