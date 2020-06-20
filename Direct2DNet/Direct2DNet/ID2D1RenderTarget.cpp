#include "ID2D1RenderTarget.h"
#include "ID2D1Factory.h"
#include "../DXGINet/IDXGISurface.h"
#include "ID2D1Bitmap.h"
#include "ID2D1BitmapBrush.h"
#include "ID2D1SolidColorBrush.h"
#include "ID2D1GradientStopCollection.h"
#include "ID2D1LinearGradientBrush.h"
#include "ID2D1RadialGradientBrush.h"
#include "ID2D1BitmapRenderTarget.h"
#include "ID2D1Layer.h"
#include "ID2D1Mesh.h"
#include "ID2D1StrokeStyle.h"
#include "ID2D1Geometry.h"
#include "ID2D1DrawingStateBlock.h"
#include "ID2D1GdiInteropRenderTarget.h"
#include "../DWriteNet/IDWriteTextFormat.h"
#include "../DWriteNet/IDWriteRenderingParams.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1RenderTarget::ID2D1RenderTarget(
            Direct2DNet::ID2D1Factory ^factory,
            DXGINet::IDXGISurface ^surface,
            Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %properties) : Direct2DNet::ID2D1Resource(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = factory->m_pFactory->CreateDxgiSurfaceRenderTarget(
                (::IDXGISurface *)surface->m_pSubObject,
                &static_cast<::D2D1_RENDER_TARGET_PROPERTIES>(properties),
                (::ID2D1RenderTarget **)ppRenderTarget
            );
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1RenderTarget", (int)hr);
        }

        Direct2DNet::ID2D1Bitmap ^ID2D1RenderTarget::CreateBitmap(
            Direct2DNet::D2D1_SIZE_U %size,
            Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties)
        {
            return gcnew Direct2DNet::ID2D1Bitmap(this, size, bitmapProperties);
        }

        Direct2DNet::ID2D1Bitmap ^ID2D1RenderTarget::CreateBitmap(
            Direct2DNet::D2D1_SIZE_U %size,
            void *srcData,
            unsigned int pitch,
            Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties)
        {
            return gcnew Direct2DNet::ID2D1Bitmap(this, size, srcData, pitch, bitmapProperties);
        }

        generic<typename T> where T : D2DNet::IUnknown
            Direct2DNet::ID2D1Bitmap ^ID2D1RenderTarget::CreateSharedBitmap(
            T data,
            Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties)
        {
            GuidAttribute ^guidAtt = (GuidAttribute ^)System::Attribute::GetCustomAttribute(
                T::typeid,
                GuidAttribute::typeid
            );

            System::Guid guid(guidAtt->Value);

            return gcnew Direct2DNet::ID2D1Bitmap(this, guid, data, bitmapProperties);
        }

        Direct2DNet::ID2D1BitmapBrush ^ID2D1RenderTarget::CreateBitmapBrush(Direct2DNet::ID2D1Bitmap ^bitmap)
        {
            return gcnew Direct2DNet::ID2D1BitmapBrush(this, bitmap);
        }

        ID2D1SolidColorBrush ^Direct2DNet::ID2D1RenderTarget::CreateSolidColorBrush(
            Direct2DNet::D2D1_COLOR_F %color)
        {
            return gcnew Direct2DNet::ID2D1SolidColorBrush(this, color);
        }

        Direct2DNet::ID2D1GradientStopCollection ^ID2D1RenderTarget::CreateGradientStopCollection(
            array<Direct2DNet::D2D1_GRADIENT_STOP> ^gradientStops,
            System::Nullable<Direct2DNet::D2D1_GAMMA> colorInterpolationGamma,
            System::Nullable<Direct2DNet::D2D1_EXTEND_MODE> extendMode)
        {
            if(!colorInterpolationGamma.HasValue)
                colorInterpolationGamma = Direct2DNet::D2D1_GAMMA::GAMMA_2_2;

            if(!extendMode.HasValue)
                extendMode = Direct2DNet::D2D1_EXTEND_MODE::CLAMP;

            return gcnew Direct2DNet::ID2D1GradientStopCollection(
                this,
                gradientStops,
                colorInterpolationGamma.Value,
                extendMode.Value
            );
        }

        Direct2DNet::ID2D1LinearGradientBrush ^ID2D1RenderTarget::CreateLinearGradientBrush(
            Direct2DNet::D2D1_POINT_2F %startPoint, 
            Direct2DNet::D2D1_POINT_2F %endPoint, 
            Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection)
        {
            return gcnew Direct2DNet::ID2D1LinearGradientBrush(this, startPoint, endPoint, gradientStopCollection);
        }

        Direct2DNet::ID2D1LinearGradientBrush ^ID2D1RenderTarget::CreateLinearGradientBrush(
            Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES %properties, 
            Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection)
        {
            return gcnew Direct2DNet::ID2D1LinearGradientBrush(this, properties, gradientStopCollection);
        }

        Direct2DNet::ID2D1RadialGradientBrush ^ID2D1RenderTarget::CreateRadialGradientBrush(
            Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES %properties, 
            Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection)
        {
            return gcnew Direct2DNet::ID2D1RadialGradientBrush(this, properties, gradientStopCollection);
        }

        Direct2DNet::ID2D1BitmapRenderTarget ^ID2D1RenderTarget::CreateCompatibleRenderTarget(
            Direct2DNet::D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options, 
            System::Nullable<Direct2DNet::D2D1_SIZE_F> desiredSize, 
            System::Nullable<Direct2DNet::D2D1_SIZE_U> desiredPixelSize, 
            System::Nullable<Direct2DNet::D2D1_PIXEL_FORMAT> desiredFormat)
        {
            return gcnew Direct2DNet::ID2D1BitmapRenderTarget(
                this,
                desiredSize,
                desiredPixelSize,
                desiredFormat,
                options
            );
        }

        Direct2DNet::ID2D1Layer ^ID2D1RenderTarget::CreateLayer(System::Nullable<Direct2DNet::D2D1_SIZE_F> size)
        {
            return gcnew Direct2DNet::ID2D1Layer(this, size);
        }

        Direct2DNet::ID2D1Mesh ^ID2D1RenderTarget::CreateMesh()
        {
            return gcnew Direct2DNet::ID2D1Mesh(this);
        }

        void ID2D1RenderTarget::DrawLine(
            Direct2DNet::D2D1_POINT_2F %point0,
            Direct2DNet::D2D1_POINT_2F %point1,
            Direct2DNet::ID2D1Brush ^brush,
            System::Nullable<float> strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
        {
            if(!strokeWidth.HasValue)
                strokeWidth = 1.0f;

            ((::ID2D1RenderTarget *)m_pResource)->DrawLine(
                static_cast<::D2D1_POINT_2F>(point0),
                static_cast<::D2D1_POINT_2F>(point1),
                (::ID2D1Brush *)brush->m_pResource,
                strokeWidth.Value,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
            );
        }

        void ID2D1RenderTarget::DrawRectangle(
            Direct2DNet::D2D1_RECT_F %rect,
            Direct2DNet::ID2D1Brush ^brush,
            System::Nullable<float> strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
        {
            if(!strokeWidth.HasValue)
                strokeWidth = 1.0f;

            ((::ID2D1RenderTarget *)m_pResource)->DrawRectangle(
                static_cast<::D2D1_RECT_F>(rect),
                (::ID2D1Brush *)brush->m_pResource,
                strokeWidth.Value,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
            );
        }

        void ID2D1RenderTarget::FillRectangle(Direct2DNet::D2D1_RECT_F %rect, Direct2DNet::ID2D1Brush ^brush)
        {
            ((::ID2D1RenderTarget *)m_pResource)->FillRectangle(
                static_cast<::D2D1_RECT_F>(rect),
                (::ID2D1Brush *)brush->m_pResource
            );
        }

        void ID2D1RenderTarget::DrawRoundedRectangle(
            Direct2DNet::D2D1_ROUNDED_RECT %roundedRect,
            Direct2DNet::ID2D1Brush ^brush,
            System::Nullable<float> strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
        {
            if(!strokeWidth.HasValue)
                strokeWidth = 1.0f;

            ((::ID2D1RenderTarget *)m_pResource)->DrawRoundedRectangle(
                static_cast<::D2D1_ROUNDED_RECT>(roundedRect),
                (::ID2D1Brush *)brush->m_pResource,
                strokeWidth.Value,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
            );
        }

        void ID2D1RenderTarget::FillRoundedRectangle(
            Direct2DNet::D2D1_ROUNDED_RECT %roundedRect, 
            Direct2DNet::ID2D1Brush ^brush)
        {
            ((::ID2D1RenderTarget *)m_pResource)->FillRoundedRectangle(
                static_cast<::D2D1_ROUNDED_RECT>(roundedRect),
                (::ID2D1Brush *)brush->m_pResource
            );
        }

        void ID2D1RenderTarget::DrawEllipse(
            Direct2DNet::D2D1_ELLIPSE %ellipse,
            Direct2DNet::ID2D1Brush ^brush,
            System::Nullable<float> strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
        {
            if(!strokeWidth.HasValue)
                strokeWidth = 1.0f;

            ((::ID2D1RenderTarget *)m_pResource)->DrawEllipse(
                static_cast<::D2D1_ELLIPSE>(ellipse),
                (::ID2D1Brush *)brush->m_pResource,
                strokeWidth.Value,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
            );
        }

        void ID2D1RenderTarget::FillEllipse(Direct2DNet::D2D1_ELLIPSE %ellipse, Direct2DNet::ID2D1Brush ^brush)
        {
            ((::ID2D1RenderTarget *)m_pResource)->FillEllipse(
                static_cast<::D2D1_ELLIPSE>(ellipse),
                (::ID2D1Brush *)brush->m_pResource
            );
        }

        void ID2D1RenderTarget::DrawGeometry(
            Direct2DNet::ID2D1Geometry ^geometry,
            Direct2DNet::ID2D1Brush ^brush,
            System::Nullable<float> strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
        {
            if(!strokeWidth.HasValue)
                strokeWidth = 1.0f;

            ((::ID2D1RenderTarget *)m_pResource)->DrawGeometry(
                (::ID2D1Geometry *)geometry->m_pResource,
                (::ID2D1Brush *)brush->m_pResource,
                strokeWidth.Value,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
            );
        }

        void ID2D1RenderTarget::FillGeometry(
            Direct2DNet::ID2D1Geometry ^geometry,
            Direct2DNet::ID2D1Brush ^brush,
            Direct2DNet::ID2D1Brush ^opacityBrush)
        {
            ((::ID2D1RenderTarget *)m_pResource)->FillGeometry(
                (::ID2D1Geometry *)geometry->m_pResource,
                (::ID2D1Brush *)brush->m_pResource,
                opacityBrush == nullptr ? __nullptr : (::ID2D1Brush *)opacityBrush->m_pResource
            );
        }

        void ID2D1RenderTarget::FillMesh(Direct2DNet::ID2D1Mesh ^mesh, Direct2DNet::ID2D1Brush ^brush)
        {
            if(AntialiasMode != Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED)
            {
                AntialiasMode = Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED;
                System::Console::Error->WriteLine("Direct2DNet Warning: You tried to draw mesh when the antialias mode of the render target is not D2D1_ANTIALIAS_MODE::ALIASED. Forced to change to aliased mode.");
            }
            ((::ID2D1RenderTarget *)m_pResource)->FillMesh(
                (::ID2D1Mesh *)mesh->m_pResource,
                (::ID2D1Brush *)brush->m_pResource
            );
        }

        void ID2D1RenderTarget::FillOpacityMask(
            Direct2DNet::ID2D1Bitmap ^opacityMask, 
            Direct2DNet::ID2D1Brush ^brush, 
            Direct2DNet::D2D1_OPACITY_MASK_CONTENT content, 
            System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle, 
            System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle)
        {
            if(AntialiasMode != Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED)
            {
                AntialiasMode = Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED;
                System::Console::Error->WriteLine("Direct2DNet Warning: You tried to fill opacity mask when the antialias mode of the render target is not D2D1_ANTIALIAS_MODE::ALIASED. Forced to change to aliased mode.");
            }
            ::D2D1_RECT_F destRect;
            ::D2D1_RECT_F srcRect;

            if(destinationRectangle.HasValue)
                destRect = static_cast<::D2D1_RECT_F>(destinationRectangle.Value);

            if(sourceRectangle.HasValue)
                srcRect = static_cast<::D2D1_RECT_F>(sourceRectangle.Value);

            ((::ID2D1RenderTarget *)m_pResource)->FillOpacityMask(
                (::ID2D1Bitmap *)opacityMask->m_pResource,
                (::ID2D1Brush *)brush->m_pResource,
                (::D2D1_OPACITY_MASK_CONTENT)((int)content),
                destinationRectangle.HasValue ? &destRect : __nullptr,
                sourceRectangle.HasValue ? &srcRect : __nullptr
            );
        }

        void ID2D1RenderTarget::DrawBitmap(
            Direct2DNet::ID2D1Bitmap ^bitmap,
            System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
            System::Nullable<float> opacity,
            System::Nullable<Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE> interpolationMode,
            System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle)
        {
            if(!opacity.HasValue)
                opacity = 1.0f;

            if(!interpolationMode.HasValue)
                interpolationMode = Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE::LINEAR;

            ((::ID2D1RenderTarget *)m_pResource)->DrawBitmap(
                (::ID2D1Bitmap *)bitmap->m_pResource,
                destinationRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(destinationRectangle.Value) : __nullptr,
                opacity.Value,
                (::D2D1_BITMAP_INTERPOLATION_MODE)((int)interpolationMode.Value),
                sourceRectangle.HasValue ? &static_cast<::D2D1_RECT_F>(sourceRectangle.Value) : __nullptr
            );
        }

        void ID2D1RenderTarget::DrawText(
            System::String ^text, 
            D2DNet::DWriteNet::IDWriteTextFormat ^textFormat, 
            Direct2DNet::D2D1_RECT_F %layoutRect, 
            Direct2DNet::ID2D1Brush ^defaultFillBrush, 
            System::Nullable<Direct2DNet::D2D1_DRAW_TEXT_OPTIONS> options, 
            System::Nullable<D2DNet::DWriteNet::DWRITE_MEASURING_MODE> measuringMode)
        {
            if(!options.HasValue)
                options = Direct2DNet::D2D1_DRAW_TEXT_OPTIONS::NONE;

            if(!measuringMode.HasValue)
                measuringMode = D2DNet::DWriteNet::DWRITE_MEASURING_MODE::NATURAL;

            marshal_context context;

            ((::ID2D1RenderTarget *)m_pResource)->DrawText(
                context.marshal_as<const wchar_t *>(text),
                text->Length,
                textFormat->m_pFormat,
                static_cast<::D2D1_RECT_F>(layoutRect),
                (::ID2D1Brush *)defaultFillBrush->m_pResource,
                (::D2D1_DRAW_TEXT_OPTIONS)((int)options.Value),
                (::DWRITE_MEASURING_MODE)((int)measuringMode.Value)
            );
        }

        void ID2D1RenderTarget::TextRenderingParams::set(DWriteNet::IDWriteRenderingParams ^value)
        {
            ((::ID2D1RenderTarget *)m_pResource)->SetTextRenderingParams(
                value == nullptr ? __nullptr : value->m_pParams
            );
            m_params = value;
        }

        void ID2D1RenderTarget::SetTags(D2D1_TAG tag1, D2D1_TAG tag2)
        {
            ((::ID2D1RenderTarget *)m_pResource)->SetTags(tag1, tag2);
        }

        void ID2D1RenderTarget::GetTags(D2D1_TAG %tag1, D2D1_TAG %tag2)
        {
            pin_ptr<D2D1_TAG> pTag1 = &tag1, pTag2 = &tag2;
            ((::ID2D1RenderTarget *)m_pResource)->GetTags((D2D1_TAG *)pTag1, (D2D1_TAG *)pTag2);
            pTag1 = nullptr;
            pTag2 = nullptr;
        }

        void ID2D1RenderTarget::PushLayer(
            Direct2DNet::D2D1_LAYER_PARAMETERS %layerParameters, 
            Direct2DNet::ID2D1Layer ^layer)
        {
            ((::ID2D1RenderTarget *)m_pResource)->PushLayer(
                static_cast<::D2D1_LAYER_PARAMETERS>(layerParameters),
                layer == nullptr ? __nullptr : (::ID2D1Layer *)layer->m_pResource
            );
        }

        void ID2D1RenderTarget::PopLayer()
        {
            ((::ID2D1RenderTarget *)m_pResource)->PopLayer();
        }

        HRESULT ID2D1RenderTarget::Flush()
        {
            return ((::ID2D1RenderTarget *)m_pResource)->Flush();
        }

        HRESULT ID2D1RenderTarget::Flush(D2D1_TAG %tag1, D2D1_TAG %tag2)
        {
            HRESULT hr = S_OK;

            pin_ptr<D2D1_TAG> pTag1 = &tag1, pTag2 = &tag2;
            hr = ((::ID2D1RenderTarget *)m_pResource)->Flush((D2D1_TAG *)pTag1, (D2D1_TAG *)pTag2);
            pTag1 = nullptr;
            pTag2 = nullptr;

            return hr;
        }

        void ID2D1RenderTarget::SaveDrawingState(Direct2DNet::ID2D1DrawingStateBlock ^drawingStateBlock)
        {
            ((::ID2D1RenderTarget *)m_pResource)->SaveDrawingState(
                (::ID2D1DrawingStateBlock *)drawingStateBlock->m_pResource
            );
        }

        void ID2D1RenderTarget::RestoreDrawingState(Direct2DNet::ID2D1DrawingStateBlock ^drawingStateBlock)
        {
            ((::ID2D1RenderTarget *)m_pResource)->RestoreDrawingState(
                (::ID2D1DrawingStateBlock *)drawingStateBlock->m_pResource
            );
        }

        void ID2D1RenderTarget::PushAxisAlignedClip(
            Direct2DNet::D2D1_RECT_F %clipRect, 
            Direct2DNet::D2D1_ANTIALIAS_MODE antialiasMode)
        {
            ((::ID2D1RenderTarget *)m_pResource)->PushAxisAlignedClip(
                static_cast<Direct2DNet::D2D1_RECT_F>(clipRect),
                (::D2D1_ANTIALIAS_MODE)((int)antialiasMode)
            );
        }

        void ID2D1RenderTarget::PopAxisAlignedClip()
        {
            ((::ID2D1RenderTarget *)m_pResource)->PopAxisAlignedClip();
        }

        void ID2D1RenderTarget::Clear(Direct2DNet::D2D1_COLOR_F %clearColor)
        {
            ((::ID2D1RenderTarget *)m_pResource)->Clear(
                static_cast<::D2D1_COLOR_F>(clearColor)
            );
        }

        void ID2D1RenderTarget::Clear()
        {
            ((::ID2D1RenderTarget *)m_pResource)->Clear();
        }

        void ID2D1RenderTarget::BeginDraw()
        {
            ((::ID2D1RenderTarget *)m_pResource)->BeginDraw();
        }

        HRESULT ID2D1RenderTarget::EndDraw()
        {
            return ((::ID2D1RenderTarget *)m_pResource)->EndDraw();
        }

        HRESULT ID2D1RenderTarget::EndDraw(D2D1_TAG %tag1, D2D1_TAG %tag2)
        {
            pin_ptr<D2D1_TAG> pTag1 = &tag1, pTag2 = &tag2;
            return ((::ID2D1RenderTarget *)m_pResource)->EndDraw((D2D1_TAG *)pTag1, (D2D1_TAG *)pTag2);
        }

        void ID2D1RenderTarget::GetDpi(float %dpiX, float %dpiY)
        {
            pin_ptr<float> pDpiX = &dpiX, pDpiY = &dpiY;
            ((::ID2D1RenderTarget *)m_pResource)->GetDpi((float *)pDpiX, (float *)pDpiY);
            pDpiX = nullptr;
            pDpiY = nullptr;
        }

        bool ID2D1RenderTarget::IsSupported(Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %properties)
        {
            BOOL result = ((::ID2D1RenderTarget *)m_pResource)->IsSupported(
                &static_cast<::D2D1_RENDER_TARGET_PROPERTIES>(properties)
            );

            return System::Convert::ToBoolean(result);
        }

        Direct2DNet::ID2D1GdiInteropRenderTarget ^ID2D1RenderTarget::QueryToGdiInteropRenderTarget()
        {
            ::ID2D1GdiInteropRenderTarget *pGDIRT = __nullptr;
            HRESULT hr = m_pResource->QueryInterface(__uuidof(::ID2D1GdiInteropRenderTarget), (void **)&pGDIRT);

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to query ID2D1GdiInteropRenderTarget", hr);

            return gcnew Direct2DNet::ID2D1GdiInteropRenderTarget(pGDIRT);
        }

    }
}