#include "ID2D1RadialGradientBrush.h"
#include "ID2D1RenderTarget.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1RadialGradientBrush::ID2D1RadialGradientBrush(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES %properties,
            Direct2DNet::ID2D1GradientStopCollection ^collection
        ) : Direct2DNet::ID2D1Brush(renderTarget->m_factory), m_collection(collection)
        {
            HRESULT hr = S_OK;
            pin_ptr<Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES> pProperties = &properties;
            pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateRadialGradientBrush(
                reinterpret_cast<::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *>(pProperties),
                __nullptr,
                (::ID2D1GradientStopCollection *)collection->m_pResource,
                (::ID2D1RadialGradientBrush **)ppBrush
            );
            pProperties = nullptr;
            ppBrush = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1RadialGradientBrush", (int)hr);
        }

        void ID2D1RadialGradientBrush::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Brush::HandleCOMInterface(obj);

            ::ID2D1GradientStopCollection *collection = __nullptr;
            ((::ID2D1RadialGradientBrush *)m_pResource)->GetGradientStopCollection(&collection);

            m_collection = gcnew Direct2DNet::ID2D1GradientStopCollection();
            m_collection->HandleCOMInterface(collection);

            if(collection)
            {
                collection->Release();
            }
        }

    }
}