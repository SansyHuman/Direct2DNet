#include "ID2D1DeviceContext.h"
#include "ID2D1Device.h"
#include "ID2D1Device1.h"
#include "ID2D1Factory1.h"
#include "ID2D1Image.h"
#include "ID2D1Bitmap1.h"
#include "ID2D1ColorContext.h"
#include "ID2D1Effect.h"
#include "ID2D1GradientStopCollection1.h"
#include "ID2D1ImageBrush.h"
#include "ID2D1BitmapBrush1.h"
#include "ID2D1CommandList.h"
#include "ID2D1GdiMetafile.h"
#include "ID2D1Layer.h"
#include "ID2D1Brush.h"
#include "../DXGINet/IDXGISurface.h"
#include "../WICNet/IWICBitmapSource.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DeviceContext::ID2D1DeviceContext(
            Direct2DNet::ID2D1Device1 ^device,
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
            : Direct2DNet::ID2D1RenderTarget(device->m_factory), m_device(device), m_target(nullptr)
        {
            
        }

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

        ID2D1DeviceContext::ID2D1DeviceContext(
            DXGINet::IDXGISurface ^dxgiSurface,
            System::Nullable<Direct2DNet::D2D1_CREATION_PROPERTIES> %creationProperties)
            : Direct2DNet::ID2D1RenderTarget(nullptr)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = D2D1CreateDeviceContext(
                (::IDXGISurface *)dxgiSurface->m_pObj,
                creationProperties.HasValue ? &static_cast<::D2D1_CREATION_PROPERTIES>(creationProperties.Value) : __nullptr,
                (::ID2D1DeviceContext **)ppRenderTarget
            );
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DeviceContext", (int)hr);

            ::ID2D1Device *pDevice = __nullptr;
            ::ID2D1Factory1 *pFactory1 = __nullptr;
            ::ID2D1Image *pTargetImage = __nullptr;

            ((::ID2D1DeviceContext *)m_pResource)->GetDevice(&pDevice);
            pDevice->GetFactory((::ID2D1Factory **)&pFactory1);
            ((::ID2D1DeviceContext *)m_pResource)->GetTarget(&pTargetImage);

            m_factory = gcnew Direct2DNet::ID2D1Factory1(pFactory1);
            m_device = gcnew Direct2DNet::ID2D1Device((Direct2DNet::ID2D1Factory1 ^)m_factory, pDevice);
            m_target = gcnew Direct2DNet::ID2D1Image(m_factory, pTargetImage);
        }

        void ID2D1DeviceContext::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1RenderTarget::HandleCOMInterface(obj);

            ::ID2D1Device *device = __nullptr;
            ::ID2D1Image *target = __nullptr;

            ((::ID2D1DeviceContext *)m_pResource)->GetDevice(&device);

            ::ID2D1Factory1 *factory = __nullptr;
            device->GetFactory((::ID2D1Factory **)&factory);
            m_device = gcnew Direct2DNet::ID2D1Device(gcnew Direct2DNet::ID2D1Factory1(factory), device);

            ((::ID2D1DeviceContext *)m_pResource)->GetTarget(&target);
            if(!target)
                m_target = nullptr;
            else
            {
                ::ID2D1Factory *factory = __nullptr;
                target->GetFactory(&factory);
                m_target = gcnew Direct2DNet::ID2D1Image(gcnew Direct2DNet::ID2D1Factory(factory), target);
            }
        }

        Direct2DNet::ID2D1Bitmap1 ^ID2D1DeviceContext::CreateBitmap(
            Direct2DNet::D2D1_SIZE_U %size,
            void *sourceData,
            unsigned int pitch,
            Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties)
        {
            return gcnew Direct2DNet::ID2D1Bitmap1(this, size, sourceData, pitch, bitmapProperties);
        }

        Direct2DNet::ID2D1Bitmap1 ^ID2D1DeviceContext::CreateBitmapFromWicBitmap(
            D2DNet::WICNet::IWICBitmapSource ^wicBitmapSource,
            System::Nullable<Direct2DNet::D2D1_BITMAP_PROPERTIES1> bitmapProperties)
        {
            return gcnew Direct2DNet::ID2D1Bitmap1(this, wicBitmapSource, bitmapProperties);
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

        Direct2DNet::ID2D1ColorContext ^ID2D1DeviceContext::CreateColorContextFromWicColorContext(
            D2DNet::WICNet::IWICColorContext ^wicColorContext)
        {
            return gcnew Direct2DNet::ID2D1ColorContext(this, wicColorContext);
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

        Direct2DNet::ID2D1ImageBrush ^ID2D1DeviceContext::CreateImageBrush(
            Direct2DNet::ID2D1Image ^image,
            Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES %imageBrushProperties)
        {
            return gcnew Direct2DNet::ID2D1ImageBrush(this, image, imageBrushProperties);
        }

        Direct2DNet::ID2D1BitmapBrush1 ^ID2D1DeviceContext::CreateBitmapBrush1(
            Direct2DNet::ID2D1Bitmap ^bitmap)
        {
            return gcnew Direct2DNet::ID2D1BitmapBrush1(this, bitmap);
        }

        Direct2DNet::ID2D1CommandList ^ID2D1DeviceContext::CreateCommandList()
        {
            return gcnew Direct2DNet::ID2D1CommandList(this);
        }

        bool ID2D1DeviceContext::IsDxgiFormatSupported(DXGINet::DXGI_FORMAT format)
        {
            return System::Convert::ToBoolean(
                ((::ID2D1DeviceContext *)m_pResource)->IsDxgiFormatSupported((::DXGI_FORMAT)((int)format))
            );
        }

        bool ID2D1DeviceContext::IsBufferPrecisionSupported(Direct2DNet::D2D1_BUFFER_PRECISION bufferPrecision)
        {
            return System::Convert::ToBoolean(
                ((::ID2D1DeviceContext *)m_pResource)->IsBufferPrecisionSupported((::D2D1_BUFFER_PRECISION)((int)bufferPrecision))
            );
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> ID2D1DeviceContext::GetImageLocalBounds(
            Direct2DNet::ID2D1Image ^image)
        {
            ::D2D1_RECT_F bounds;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetImageLocalBounds(
                (::ID2D1Image *)image->m_pResource,
                &bounds
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F>(
                hr,
                static_cast<Direct2DNet::D2D1_RECT_F>(bounds)
                );
        }

        HRESULT ID2D1DeviceContext::GetImageLocalBounds(
            Direct2DNet::ID2D1Image ^image,
            Direct2DNet::D2D1_RECT_F %localBounds)
        {
            ::D2D1_RECT_F bounds;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetImageLocalBounds(
                (::ID2D1Image *)image->m_pResource,
                &bounds
            );

            localBounds = static_cast<Direct2DNet::D2D1_RECT_F>(bounds);

            return hr;
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> ID2D1DeviceContext::GetImageWorldBounds(
            Direct2DNet::ID2D1Image ^image)
        {
            ::D2D1_RECT_F bounds;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetImageWorldBounds(
                (::ID2D1Image *)image->m_pResource,
                &bounds
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F>(
                hr,
                static_cast<Direct2DNet::D2D1_RECT_F>(bounds)
                );
        }

        HRESULT ID2D1DeviceContext::GetImageWorldBounds(
            Direct2DNet::ID2D1Image ^image,
            Direct2DNet::D2D1_RECT_F %worldBounds)
        {
            ::D2D1_RECT_F bounds;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetImageWorldBounds(
                (::ID2D1Image *)image->m_pResource,
                &bounds
            );

            worldBounds = static_cast<Direct2DNet::D2D1_RECT_F>(bounds);

            return hr;
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> ID2D1DeviceContext::GetGlyphRunWorldBounds(
            Direct2DNet::D2D1_POINT_2F %baselineOrigin,
            DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
            DWriteNet::DWRITE_MEASURING_MODE measuringMode)
        {
            ::D2D1_RECT_F bounds = { 0 };

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetGlyphRunWorldBounds(
                static_cast<::D2D1_POINT_2F>(baselineOrigin),
                &static_cast<::DWRITE_GLYPH_RUN>(glyphRun),
                (::DWRITE_MEASURING_MODE)((int)measuringMode),
                &bounds
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F>(
                hr,
                static_cast<Direct2DNet::D2D1_RECT_F>(bounds)
                );
        }

        HRESULT ID2D1DeviceContext::GetGlyphRunWorldBounds(
            Direct2DNet::D2D1_POINT_2F %baselineOrigin,
            DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
            DWriteNet::DWRITE_MEASURING_MODE measuringMode,
            Direct2DNet::D2D1_RECT_F %bounds)
        {
            pin_ptr<Direct2DNet::D2D1_RECT_F> pBounds = &bounds;

            return ((::ID2D1DeviceContext *)m_pResource)->GetGlyphRunWorldBounds(
                static_cast<::D2D1_POINT_2F>(baselineOrigin),
                &static_cast<::DWRITE_GLYPH_RUN>(glyphRun),
                (::DWRITE_MEASURING_MODE)((int)measuringMode),
                reinterpret_cast<::D2D1_RECT_F *>(pBounds)
            );
        }

        Direct2DNet::ID2D1Image ^ID2D1DeviceContext::Target::get()
        {
            return m_target;
        }

        void ID2D1DeviceContext::Target::set(Direct2DNet::ID2D1Image ^value)
        {
            if(value == nullptr)
            {
                ((::ID2D1DeviceContext *)m_pResource)->SetTarget(__nullptr);
                m_target = nullptr;
                return;
            }

            ((::ID2D1DeviceContext *)m_pResource)->SetTarget((::ID2D1Image *)value->m_pResource);
            m_target = value;
        }

        void ID2D1DeviceContext::DrawGlyphRun(
            Direct2DNet::D2D1_POINT_2F %baselineOrigin,
            DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
            Direct2DNet::ID2D1Brush ^foregroundBrush, 
            System::Nullable<DWriteNet::DWRITE_GLYPH_RUN_DESCRIPTION> glyphRunDescription, 
            System::Nullable<DWriteNet::DWRITE_MEASURING_MODE> measuringMode)
        {
            if(!measuringMode.HasValue)
                measuringMode = DWriteNet::DWRITE_MEASURING_MODE::NATURAL;

            ((::ID2D1DeviceContext *)m_pResource)->DrawGlyphRun(
                static_cast<::D2D1_POINT_2F>(baselineOrigin),
                &static_cast<::DWRITE_GLYPH_RUN>(glyphRun),
                glyphRunDescription.HasValue ? reinterpret_cast<::DWRITE_GLYPH_RUN_DESCRIPTION *>(&glyphRunDescription.Value) : __nullptr,
                (::ID2D1Brush *)foregroundBrush->m_pResource,
                (::DWRITE_MEASURING_MODE)((int)measuringMode.Value)
            );
        }

        void ID2D1DeviceContext::DrawImage(
            Direct2DNet::ID2D1Image ^image,
            System::Nullable<Direct2DNet::D2D1_POINT_2F> targetOffset,
            System::Nullable<Direct2DNet::D2D1_RECT_F> imageRectangle,
            System::Nullable<Direct2DNet::D2D1_INTERPOLATION_MODE> interpolationMode,
            System::Nullable<Direct2DNet::D2D1_COMPOSITE_MODE> compositeMode)
        {
            if(!interpolationMode.HasValue)
                interpolationMode = Direct2DNet::D2D1_INTERPOLATION_MODE::LINEAR;

            if(!compositeMode.HasValue)
                compositeMode = Direct2DNet::D2D1_COMPOSITE_MODE::SOURCE_OVER;

            ((::ID2D1DeviceContext *)m_pResource)->DrawImage(
                (::ID2D1Image *)image->m_pResource,
                targetOffset.HasValue ? &static_cast<::D2D1_POINT_2F>(targetOffset.Value) : __nullptr,
                imageRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(imageRectangle.Value) : __nullptr,
                (::D2D1_INTERPOLATION_MODE)((int)interpolationMode.Value),
                (::D2D1_COMPOSITE_MODE)((int)compositeMode.Value)
            );
        }

        void ID2D1DeviceContext::DrawImage(Direct2DNet::ID2D1Effect ^effect,
            System::Nullable<Direct2DNet::D2D1_POINT_2F> targetOffset,
            System::Nullable<Direct2DNet::D2D1_RECT_F> imageRectangle,
            System::Nullable<Direct2DNet::D2D1_INTERPOLATION_MODE> interpolationMode,
            System::Nullable<Direct2DNet::D2D1_COMPOSITE_MODE> compositeMode)
        {
            Direct2DNet::ID2D1Image ^output = effect->Output;
            DrawImage(output, targetOffset, imageRectangle, interpolationMode, compositeMode);
            delete output;
        }

        void ID2D1DeviceContext::DrawGdiMetafile(
            Direct2DNet::ID2D1GdiMetafile ^gdiMetafile,
            System::Nullable<Direct2DNet::D2D1_POINT_2F> targetOffset)
        {
            ((::ID2D1DeviceContext *)m_pResource)->DrawGdiMetafile(
                (::ID2D1GdiMetafile *)gdiMetafile->m_pResource,
                targetOffset.HasValue ? &static_cast<::D2D1_POINT_2F>(targetOffset.Value) : __nullptr
            );
        }

        void ID2D1DeviceContext::DrawBitmap(
            Direct2DNet::ID2D1Bitmap ^bitmap,
            float opacity,
            Direct2DNet::D2D1_INTERPOLATION_MODE interpolationMode,
            System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
            System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle,
            System::Nullable<Direct2DNet::D2D1_MATRIX_4X4_F> perspectiveTransform)
        {
            ((::ID2D1DeviceContext *)m_pResource)->DrawBitmap(
                (::ID2D1Bitmap *)bitmap->m_pResource,
                destinationRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(destinationRectangle.Value) : __nullptr,
                opacity,
                (::D2D1_INTERPOLATION_MODE)((int)interpolationMode),
                sourceRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(sourceRectangle.Value) : __nullptr,
                perspectiveTransform.HasValue ? &static_cast<::D2D1_MATRIX_4X4_F>(perspectiveTransform.Value) : __nullptr
            );
        }

        void ID2D1DeviceContext::PushLayer(
            Direct2DNet::D2D1_LAYER_PARAMETERS1 %layerParameters,
            Direct2DNet::ID2D1Layer ^layer)
        {
            ((::ID2D1DeviceContext *)m_pResource)->PushLayer(
                &static_cast<::D2D1_LAYER_PARAMETERS1>(layerParameters),
                (::ID2D1Layer *)layer->m_pResource
            );
        }

        HRESULT ID2D1DeviceContext::InvalidateEffectInputRectangle(
            Direct2DNet::ID2D1Effect ^effect,
            unsigned int input,
            Direct2DNet::D2D1_RECT_F %inputRectangle)
        {
            return ((::ID2D1DeviceContext *)m_pResource)->InvalidateEffectInputRectangle(
                (::ID2D1Effect *)effect->m_pProperties,
                input,
                &static_cast<::D2D1_RECT_F>(inputRectangle)
            );
        }

        System::ValueTuple<HRESULT, unsigned int> ID2D1DeviceContext::GetEffectInvalidRectangleCount(
            Direct2DNet::ID2D1Effect ^effect)
        {
            unsigned int count = 0U;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectInvalidRectangleCount(
                (::ID2D1Effect *)effect->m_pProperties,
                &count
            );

            return System::ValueTuple<HRESULT, unsigned int>(hr, count);
        }

        HRESULT ID2D1DeviceContext::GetEffectInvalidRectangleCount(
            Direct2DNet::ID2D1Effect ^effect,
            unsigned int %rectangleCount)
        {
            unsigned int count = 0U;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectInvalidRectangleCount(
                (::ID2D1Effect *)effect->m_pProperties,
                &count
            );
            rectangleCount = count;

            return hr;
        }

        System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^> ID2D1DeviceContext::GetEffectInvalidRectangles(Direct2DNet::ID2D1Effect ^effect)
        {
            unsigned int rectCount = 0U;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectInvalidRectangleCount(
                (::ID2D1Effect *)effect->m_pProperties,
                &rectCount
            );

            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^>(hr, nullptr);
            }

            std::vector<::D2D1_RECT_F> rects(rectCount);

            hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectInvalidRectangles(
                (::ID2D1Effect *)effect->m_pProperties,
                rects.data(),
                rectCount
            );

            array<Direct2DNet::D2D1_RECT_F> ^rectangles = gcnew array<Direct2DNet::D2D1_RECT_F>(rectCount);
            for(int i = 0; i < rects.size(); i++)
            {
                rectangles[i] = static_cast<Direct2DNet::D2D1_RECT_F>(rects[i]);
            }

            return System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^>(hr, rectangles);
        }

        HRESULT ID2D1DeviceContext::GetEffectInvalidRectangles(
            Direct2DNet::ID2D1Effect ^effect,
            array<Direct2DNet::D2D1_RECT_F> ^%rectangles)
        {
            unsigned int rectCount = 0U;

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectInvalidRectangleCount(
                (::ID2D1Effect *)effect->m_pProperties,
                &rectCount
            );

            if(FAILED(hr))
            {
                rectangles = nullptr;
                return hr;
            }

            std::vector<::D2D1_RECT_F> rects(rectCount);

            hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectInvalidRectangles(
                (::ID2D1Effect *)effect->m_pProperties,
                rects.data(),
                rectCount
            );

            rectangles = gcnew array<Direct2DNet::D2D1_RECT_F>(rectCount);
            for(int i = 0; i < rects.size(); i++)
            {
                rectangles[i] = static_cast<Direct2DNet::D2D1_RECT_F>(rects[i]);
            }

            return hr;
        }

        System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^> ID2D1DeviceContext::GetEffectRequiredInputRectangles(
            Direct2DNet::ID2D1Effect ^renderEffect,
            array<Direct2DNet::D2D1_EFFECT_INPUT_DESCRIPTION> ^inputDescription,
            System::Nullable<Direct2DNet::D2D1_RECT_F> renderImageRectangle)
        {
            int inputCount = inputDescription->Length;
            if(inputCount == 0)
                return System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^>(
                    E_INVALIDARG, nullptr
                    );

            std::vector<::D2D1_EFFECT_INPUT_DESCRIPTION> nativeDescs(inputCount);
            std::vector<::D2D1_RECT_F> nativeRects(inputCount);

            for(int i = 0; i < inputCount; i++)
            {
                nativeDescs[i] = static_cast<::D2D1_EFFECT_INPUT_DESCRIPTION>(inputDescription[i]);
            }

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectRequiredInputRectangles(
                (::ID2D1Effect *)renderEffect->m_pProperties,
                renderImageRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(renderImageRectangle.Value) : __nullptr,
                nativeDescs.data(),
                nativeRects.data(),
                inputCount
            );

            array<Direct2DNet::D2D1_RECT_F> ^inputRects = gcnew array<Direct2DNet::D2D1_RECT_F>(inputCount);
            for(int i = 0; i < inputCount; i++)
            {
                inputRects[i] = static_cast<Direct2DNet::D2D1_RECT_F>(nativeRects[i]);
            }

            return System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^>(hr, inputRects);
        }

        HRESULT ID2D1DeviceContext::GetEffectRequiredInputRectangles(
            Direct2DNet::ID2D1Effect ^renderEffect,
            array<Direct2DNet::D2D1_EFFECT_INPUT_DESCRIPTION> ^inputDescription, 
            array<Direct2DNet::D2D1_RECT_F> ^%requiredInputRects,
            System::Nullable<Direct2DNet::D2D1_RECT_F> renderImageRectangle)
        {
            int inputCount = inputDescription->Length;
            if(inputCount == 0)
            {
                requiredInputRects = nullptr;
                return E_INVALIDARG;
            }

            std::vector<::D2D1_EFFECT_INPUT_DESCRIPTION> nativeDescs(inputCount);
            std::vector<::D2D1_RECT_F> nativeRects(inputCount);

            for(int i = 0; i < inputCount; i++)
            {
                nativeDescs[i] = static_cast<::D2D1_EFFECT_INPUT_DESCRIPTION>(inputDescription[i]);
            }

            HRESULT hr = ((::ID2D1DeviceContext *)m_pResource)->GetEffectRequiredInputRectangles(
                (::ID2D1Effect *)renderEffect->m_pProperties,
                renderImageRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(renderImageRectangle.Value) : __nullptr,
                nativeDescs.data(),
                nativeRects.data(),
                inputCount
            );

            requiredInputRects = gcnew array<Direct2DNet::D2D1_RECT_F>(inputCount);
            for(int i = 0; i < inputCount; i++)
            {
                requiredInputRects[i] = static_cast<Direct2DNet::D2D1_RECT_F>(nativeRects[i]);
            }

            return hr;
        }

        void ID2D1DeviceContext::FillOpacityMask(
            Direct2DNet::ID2D1Bitmap ^opacityMask,
            Direct2DNet::ID2D1Brush ^brush,
            System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
            System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle)
        {
            if(AntialiasMode != Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED)
            {
                AntialiasMode = Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED;
                D2DNet::DirectX::PrintDebugMessage("Direct2DNet Warning: You tried to fill opacity mask when the antialias mode of the render target is not D2D1_ANTIALIAS_MODE::ALIASED. Forced to change to aliased mode.");
            }

            ((::ID2D1DeviceContext *)m_pResource)->FillOpacityMask(
                (::ID2D1Bitmap *)opacityMask->m_pResource,
                (::ID2D1Brush *)brush->m_pResource,
                destinationRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(destinationRectangle.Value) : __nullptr,
                sourceRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(sourceRectangle.Value) : __nullptr
            );
        }

    }
}