#include "ID2D1GradientStopCollection.h"
#include "ID2D1RenderTarget.h"
#include "ID2D1DeviceContext.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GradientStopCollection::ID2D1GradientStopCollection(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            array<Direct2DNet::D2D1_GRADIENT_STOP> ^gradientStops,
            Direct2DNet::D2D1_GAMMA gamma,
            Direct2DNet::D2D1_EXTEND_MODE extendMode
        ) : Direct2DNet::ID2D1Resource(renderTarget->m_factory), m_gamma(gamma), m_extendMode(extendMode)
        {
            HRESULT hr = S_OK;
            pin_ptr<Direct2DNet::D2D1_GRADIENT_STOP> pStops = &gradientStops[0];
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateGradientStopCollection(
                reinterpret_cast<::D2D1_GRADIENT_STOP *>(pStops),
                gradientStops->Length,
                (::D2D1_GAMMA)((int)gamma),
                (::D2D1_EXTEND_MODE)((int)extendMode),
                (::ID2D1GradientStopCollection **)ppResource
            );
            pStops = nullptr;
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GradientStopCollection", (int)hr);

            m_gradientStops = gcnew array<Direct2DNet::D2D1_GRADIENT_STOP>(gradientStops->Length);
            gradientStops->CopyTo(m_gradientStops, 0);
        }

        ID2D1GradientStopCollection::ID2D1GradientStopCollection(
            Direct2DNet::ID2D1DeviceContext ^deviceContext
        ) : Direct2DNet::ID2D1Resource(deviceContext->m_factory)
        {
            
        }

        void ID2D1GradientStopCollection::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Resource::HandleCOMInterface(obj);

            UINT32 stopsCount = ((::ID2D1GradientStopCollection *)m_pResource)->GetGradientStopCount();
            m_gradientStops = gcnew array<Direct2DNet::D2D1_GRADIENT_STOP>(stopsCount);
            pin_ptr<Direct2DNet::D2D1_GRADIENT_STOP> pStops = &m_gradientStops[0];
            ((::ID2D1GradientStopCollection *)m_pResource)->GetGradientStops(
                reinterpret_cast<::D2D1_GRADIENT_STOP *>(pStops), stopsCount
            );
            pStops = nullptr;

            m_gamma = (Direct2DNet::D2D1_GAMMA)((int)((::ID2D1GradientStopCollection *)m_pResource)->GetColorInterpolationGamma());
            m_extendMode = (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1GradientStopCollection *)m_pResource)->GetExtendMode());
        }

    }
}