#include "ID2D1DeviceContext.h"
#include "ID2D1Device.h"
#include "ID2D1Image.h"
#include "ID2D1Bitmap1.h"
#include "ID2D1ColorContext.h"
#include "ID2D1Effect.h"
#include "ID2D1GradientStopCollection1.h"
#include "../DXGINet/IDXGISurface.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DeviceContext::ID2D1DeviceContext(
            Direct2DNet::ID2D1Device ^device,
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
            : Direct2DNet::ID2D1RenderTarget(device->m_factory), m_device(device), m_target(nullptr)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = ((::ID2D1Device *)device->m_pResource)->CreateDeviceContext(
                (::D2D1_DEVICE_CONTEXT_OPTIONS)((int)options),
                (::ID2D1DeviceContext **)ppRenderTarget
            );
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DeviceContext", (int)hr);
        }

        Direct2DNet::ID2D1Bitmap1 ^ID2D1DeviceContext::CreateBitmap(
            Direct2DNet::D2D1_SIZE_U %size,
            void *sourceData,
            unsigned int pitch,
            Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties)
        {
            return gcnew Direct2DNet::ID2D1Bitmap1(this, size, sourceData, pitch, bitmapProperties);
        }

        Direct2DNet::ID2D1ColorContext ^ID2D1DeviceContext::CreateColorContext(
            Direct2DNet::D2D1_COLOR_SPACE space,
            array<unsigned char> ^profile)
        {
            if(space == Direct2DNet::D2D1_COLOR_SPACE::CUSTOM
                && (profile == nullptr || profile->Length <= 0))
                throw gcnew Direct2DNet::Exception::DxException(
                    "Failed to create color context. You set the custom color context, but the profile array is null or has length zero.",
                    E_INVALIDARG);

            return gcnew Direct2DNet::ID2D1ColorContext(this, space, profile);
        }

        Direct2DNet::ID2D1ColorContext ^ID2D1DeviceContext::CreateColorContextFromFilename(
            System::String ^filename)
        {
            return gcnew Direct2DNet::ID2D1ColorContext(this, filename);
        }

        Direct2DNet::ID2D1Bitmap1 ^ID2D1DeviceContext::CreateBitmapFromDxgiSurface(
            DXGINet::IDXGISurface ^surface,
            Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties)
        {
            return gcnew Direct2DNet::ID2D1Bitmap1(this, surface, bitmapProperties);
        }

        Direct2DNet::ID2D1Effect ^ID2D1DeviceContext::CreateEffect(System::Guid %effectId)
        {
            return gcnew Direct2DNet::ID2D1Effect(this, effectId);
        }

        Direct2DNet::ID2D1GradientStopCollection1 ^ID2D1DeviceContext::CreateGradientStopCollection(
            array<Direct2DNet::D2D1_GRADIENT_STOP> ^straightAlphaGradientStops,
            Direct2DNet::D2D1_COLOR_SPACE preInterpolationSpace,
            Direct2DNet::D2D1_COLOR_SPACE postInterpolationSpace,
            Direct2DNet::D2D1_BUFFER_PRECISION bufferPrecision,
            Direct2DNet::D2D1_EXTEND_MODE extendMode,
            Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE colorInterpolationMode)
        {
            return gcnew Direct2DNet::ID2D1GradientStopCollection1(
                this,
                straightAlphaGradientStops,
                preInterpolationSpace,
                postInterpolationSpace,
                bufferPrecision,
                extendMode,
                colorInterpolationMode
            );
        }

        Direct2DNet::ID2D1Image ^ID2D1DeviceContext::Target::get()
        {
            return m_target;
        }

        void ID2D1DeviceContext::Target::set(Direct2DNet::ID2D1Image ^value)
        {
            ((::ID2D1DeviceContext *)m_pResource)->SetTarget((::ID2D1Image *)value->m_pResource);
            m_target = value;
        }

    }
}