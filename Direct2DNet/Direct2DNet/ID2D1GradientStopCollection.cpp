#include "ID2D1GradientStopCollection.h"
#include "ID2D1RenderTarget.h"

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
            m_gradientStops = gcnew array<Direct2DNet::D2D1_GRADIENT_STOP>(gradientStops->Length);
            gradientStops->CopyTo(m_gradientStops, 0);

            std::vector<::D2D1_GRADIENT_STOP> nativeStops(gradientStops->Length);
            for(int i = 0; i < nativeStops.size(); i++)
            {
                nativeStops[i] = static_cast<::D2D1_GRADIENT_STOP>(gradientStops[i]);
            }

            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateGradientStopCollection(
                nativeStops.data(),
                nativeStops.size(),
                (::D2D1_GAMMA)((int)gamma),
                (::D2D1_EXTEND_MODE)((int)extendMode),
                (::ID2D1GradientStopCollection **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GradientStopCollection", (int)hr);
        }
    }
}