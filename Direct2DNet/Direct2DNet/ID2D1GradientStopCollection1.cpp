#include "ID2D1GradientStopCollection1.h"
#include "ID2D1DeviceContext.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GradientStopCollection1::ID2D1GradientStopCollection1(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            array<Direct2DNet::D2D1_GRADIENT_STOP> ^straightAlphaGradientStops,
            Direct2DNet::D2D1_COLOR_SPACE preInterpolationSpace,
            Direct2DNet::D2D1_COLOR_SPACE postInterpolationSpace,
            Direct2DNet::D2D1_BUFFER_PRECISION bufferPrecision,
            Direct2DNet::D2D1_EXTEND_MODE extendMode,
            Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE colorInterpolationMode)
            : Direct2DNet::ID2D1GradientStopCollection(deviceContext),
            m_preInterpolationSpace(preInterpolationSpace), m_postInterpolationSpace(postInterpolationSpace),
            m_bufferPrecision(bufferPrecision), m_colorInterpolationMode(colorInterpolationMode)
        {
            HRESULT hr = S_OK;
            pin_ptr<Direct2DNet::D2D1_GRADIENT_STOP> pStops = &straightAlphaGradientStops[0];
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateGradientStopCollection(
                reinterpret_cast<::D2D1_GRADIENT_STOP *>(pStops),
                straightAlphaGradientStops->Length,
                (::D2D1_COLOR_SPACE)((int)preInterpolationSpace),
                (::D2D1_COLOR_SPACE)((int)postInterpolationSpace),
                (::D2D1_BUFFER_PRECISION)((int)bufferPrecision),
                (::D2D1_EXTEND_MODE)((int)extendMode),
                (::D2D1_COLOR_INTERPOLATION_MODE)((int)colorInterpolationMode),
                (::ID2D1GradientStopCollection1 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GradientStopCollection1", (int)hr);

            m_gradientStops = gcnew array<Direct2DNet::D2D1_GRADIENT_STOP>(straightAlphaGradientStops->Length);
            straightAlphaGradientStops->CopyTo(m_gradientStops, 0);

            m_gamma = (Direct2DNet::D2D1_GAMMA)((int)((::ID2D1GradientStopCollection1 *)m_pResource)->GetColorInterpolationGamma());

            m_extendMode = extendMode;
        }

        void ID2D1GradientStopCollection1::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1GradientStopCollection::HandleCOMInterface(obj);

            m_preInterpolationSpace = (Direct2DNet::D2D1_COLOR_SPACE)((int)((::ID2D1GradientStopCollection1 *)m_pResource)->GetPreInterpolationSpace());
            m_postInterpolationSpace = (Direct2DNet::D2D1_COLOR_SPACE)((int)((::ID2D1GradientStopCollection1 *)m_pResource)->GetPostInterpolationSpace());
            m_bufferPrecision = (Direct2DNet::D2D1_BUFFER_PRECISION)((int)((::ID2D1GradientStopCollection1 *)m_pResource)->GetBufferPrecision());
            m_colorInterpolationMode = (Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE)((int)((::ID2D1GradientStopCollection1 *)m_pResource)->GetColorInterpolationMode());
        }

    }
}