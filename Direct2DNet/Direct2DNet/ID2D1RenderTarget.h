#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

using namespace System::Runtime::InteropServices;

namespace Direct2DNet
{
    ref class ID2D1Brush;
    ref class ID2D1SolidColorBrush;
    ref class ID2D1StrokeStyle;
    ref class ID2D1Geometry;

    /// <summary>
    /// Represents an object that can receive drawing commands. Classes that inherit
    /// from <see cref="Direct2DNet::ID2D1RenderTarget"/> render the drawing commands
    /// they receive in different ways.
    /// </summary>
    public ref class ID2D1RenderTarget abstract : Direct2DNet::ID2D1Resource
    {
    protected:
        ID2D1RenderTarget(Direct2DNet::ID2D1Factory ^factory) : ID2D1Resource(factory) {}

    public:
        /// <summary>
        /// Draws a line using the <paramref name="brush"/> in width <paramref name="strokeWidth"/>
        /// and with <paramref name="strokeStyle"/>.
        /// </summary>
        /// <param name="point0">Start point.</param>
        /// <param name="point1">End point.</param>
        /// <param name="strokeWidth">Width of the stroke in pixels.
        /// The default value is 1.0.</param>
        /// <param name="strokeStyle">Stroke style applied to the stroke.
        /// This value can be null. The default value is null.</param>
        void DrawLine(
            Direct2DNet::D2D1_POINT_2F point0,
            Direct2DNet::D2D1_POINT_2F point1,
            Direct2DNet::ID2D1Brush ^brush,
            [OptionalAttribute] System::Nullable<float> strokeWidth,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
        );

        /// <summary>
        /// Draws the geometry using the <paramref name="brush"/> in width <paramref name="strokeWidth"/>
        /// and with <paramref name="strokeStyle"/>.
        /// </summary>
        /// <param name="strokeWidth">Width of the stroke in pixels.
        /// The default value is 1.0.</param>
        /// <param name="strokeStyle">Stroke style applied to the stroke.
        /// This value can be null. The default value is null.</param>
        void DrawGeometry(
            Direct2DNet::ID2D1Geometry ^geometry,
            Direct2DNet::ID2D1Brush ^brush,
            [OptionalAttribute] System::Nullable<float> strokeWidth,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
        );

        // Need to implement fill geometry with opacity brush later.

        /// <summary>
        /// Fills inside of the geometry using the <paramref name="brush"/>.
        /// </summary>
        void FillGeometry(
            Direct2DNet::ID2D1Geometry ^geometry,
            Direct2DNet::ID2D1Brush ^brush
        );

        /// <summary>
        /// Gets and sets the antialias mode of the render target.
        /// </summary>
        property Direct2DNet::D2D1_ANTIALIAS_MODE AntialiasMode
        {
            Direct2DNet::D2D1_ANTIALIAS_MODE get()
            {
                return (Direct2DNet::D2D1_ANTIALIAS_MODE)(
                    (int)((::ID2D1RenderTarget *)m_pResource)->GetAntialiasMode());
            }

            void set(Direct2DNet::D2D1_ANTIALIAS_MODE value)
            {
                ((::ID2D1RenderTarget *)m_pResource)->SetAntialiasMode((::D2D1_ANTIALIAS_MODE)((int)value));
            }
        }

        /// <summary>
        /// Gets and sets the text antialias mode of the render target.
        /// </summary>
        property Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE TextAntialiasMode
        {
            Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE get()
            {
                return (Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE)(
                    (int)((::ID2D1RenderTarget *)m_pResource)->GetTextAntialiasMode());
            }

            void set(Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE value)
            {
                ((::ID2D1RenderTarget *)m_pResource)->SetTextAntialiasMode((::D2D1_TEXT_ANTIALIAS_MODE)((int)value));
            }
        }

        /// <summary>
        /// Start drawing on this render target. Draw calls can only be issued between a
        /// BeginDraw and EndDraw call.
        /// </summary>
        void BeginDraw();

        /// <summary>
        /// Ends drawing on the render target, error results can be retrieved at this time,
        /// or when calling flush.
        /// </summary>
        /// <returns>
        /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
        /// </returns>
        HRESULT EndDraw();

        /// <summary>
        /// Gets the pixel format of the render target.
        /// </summary>
        property Direct2DNet::D2D1_PIXEL_FORMAT PixelFormat
        {
            Direct2DNet::D2D1_PIXEL_FORMAT get()
            {
                return static_cast<Direct2DNet::D2D1_PIXEL_FORMAT>(
                    ((::ID2D1RenderTarget *)m_pResource)->GetPixelFormat()
                    );
            }
        }

        /// <summary>
        /// Gets and sets the DPI on the render target. This results in the render target being
        /// interpreted to a different scale. Neither DPI can be negative. If zero is
        /// specified for both, the system DPI is chosen. If one is zero and the other
        /// unspecified, the DPI is not changed.
        /// </summary>
        property System::ValueTuple<float, float> Dpi
        {
            System::ValueTuple<float, float> get()
            {
                float dpiX, dpiY;
                pin_ptr<float> pDpiX = &dpiX, pDpiY = &dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi((float *)pDpiX, (float *)pDpiY);
                pDpiX = nullptr; pDpiY = nullptr;
                return System::ValueTuple<float, float>(dpiX, dpiY);
            }

            void set(System::ValueTuple<float, float> value)
            {
                ((::ID2D1RenderTarget *)m_pResource)->SetDpi(value.Item1, value.Item2);
            }
        }

        /// <summary>
        /// Gets and sets the DPI in x direction on the render target. 
        /// This results in the render target being interpreted to a different scale. 
        /// Neither DPI can be negative.
        /// </summary>
        property float DpiX
        {
            float get()
            {
                float dpiX, dpiY;
                pin_ptr<float> pDpiX = &dpiX, pDpiY = &dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi((float *)pDpiX, (float *)pDpiY);
                pDpiX = nullptr; pDpiY = nullptr;
                return dpiX;
            }

            void set(float value)
            {
                float dpiX, dpiY;
                pin_ptr<float> pDpiX = &dpiX, pDpiY = &dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi((float *)pDpiX, (float *)pDpiY);
                pDpiX = nullptr; pDpiY = nullptr;
                ((::ID2D1RenderTarget *)m_pResource)->SetDpi(value, dpiY);
            }
        }

        /// <summary>
        /// Gets and sets the DPI in y direction on the render target. 
        /// This results in the render target being interpreted to a different scale. 
        /// Neither DPI can be negative.
        /// </summary>
        property float DpiY
        {
            float get()
            {
                float dpiX, dpiY;
                pin_ptr<float> pDpiX = &dpiX, pDpiY = &dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi((float *)pDpiX, (float *)pDpiY);
                pDpiX = nullptr; pDpiY = nullptr;
                return dpiY;
            }

            void set(float value)
            {
                float dpiX, dpiY;
                pin_ptr<float> pDpiX = &dpiX, pDpiY = &dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi((float *)pDpiX, (float *)pDpiY);
                pDpiX = nullptr; pDpiY = nullptr;
                ((::ID2D1RenderTarget *)m_pResource)->SetDpi(dpiX, value);
            }
        }

        /// <summary>
        /// Gets the size of the render target in DIPs.
        /// </summary>
        property Direct2DNet::D2D1_SIZE_F Size
        {
            Direct2DNet::D2D1_SIZE_F get()
            {
                return static_cast<Direct2DNet::D2D1_SIZE_F>(
                    ((::ID2D1RenderTarget *)m_pResource)->GetSize()
                    );
            }
        }

        /// <summary>
        /// Gets the size of the render target in pixels.
        /// </summary>
        property Direct2DNet::D2D1_SIZE_U PixelSize
        {
            Direct2DNet::D2D1_SIZE_U get()
            {
                return static_cast<Direct2DNet::D2D1_SIZE_U>(
                    ((::ID2D1RenderTarget *)m_pResource)->GetPixelSize()
                    );
            }
        }

        /// <summary>
        /// Gets the maximum bitmap and render target size that is guaranteed to be
        /// supported by the render target.
        /// </summary>
        property unsigned int MaximumBitmapSize
        {
            unsigned int get()
            {
                return ((::ID2D1RenderTarget *)m_pResource)->GetMaximumBitmapSize();
            }
        }

        /// <summary>
        /// Returns true if the given properties are supported by this render target. The
        /// DPI is ignored. NOTE: If the render target type is software, then neither
        /// <see cref="Direct2DNet::D2D1_FEATURE_LEVEL::FEATURE_LEVEL_9"/>nor
        /// <see cref="Direct2DNet::D2D1_FEATURE_LEVEL::FEATURE_LEVEL_10"/> will be considered
        /// to be supported.
        /// </summary>
        bool IsSupported(Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES properties);

        /// <summary>
        /// Gets <see cref="Direct2DNet::ID2D1SolidColorBrush"/> instance of the <paramref name="color"/>.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to create the brush.
        /// </exception>
        Direct2DNet::ID2D1SolidColorBrush ^CreateSolidColorBrush(Direct2DNet::D2D1_COLOR_F color);

        /// <summary>
        /// Draws the rectangle using the <paramref name="brush"/> in width <paramref name="strokeWidth"/>
        /// and with <paramref name="strokeStyle"/>.
        /// </summary>
        /// <param name="strokeWidth">Width of the stroke in pixels.
        /// The default value is 1.0.</param>
        /// <param name="strokeStyle">Stroke style applied to the stroke.
        /// This value can be null. The default value is null.</param>
        void DrawRectangle(
            Direct2DNet::D2D1_RECT_F rect,
            Direct2DNet::ID2D1Brush ^brush,
            [OptionalAttribute] System::Nullable<float> strokeWidth,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
        );

        /// <summary>
        /// Fills the rectangle using the <paramref name="brush"/>.
        /// </summary>
        void FillRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush);

        /// <summary>
        /// Draws the rounded rectangle using the <paramref name="brush"/> in width
        /// <paramref name="strokeWidth"/> and with <paramref name="strokeStyle"/>.
        /// </summary>
        /// <param name="strokeWidth">Width of the stroke in pixels.
        /// The default value is 1.0.</param>
        /// <param name="strokeStyle">Stroke style applied to the stroke.
        /// This value can be null. The default value is null.</param>
        void DrawRoundedRectangle(
            Direct2DNet::D2D1_ROUNDED_RECT roundedRect,
            Direct2DNet::ID2D1Brush ^brush,
            [OptionalAttribute] System::Nullable<float> strokeWidth,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
        );

        /// <summary>
        /// Fills the rounded rectangle using the <paramref name="brush"/>.
        /// </summary>
        void FillRoundedRectangle(
            Direct2DNet::D2D1_ROUNDED_RECT roundedRect,
            Direct2DNet::ID2D1Brush ^brush
        );

        /// <summary>
        /// Draws the ellipse using the <paramref name="brush"/> in width <paramref name="strokeWidth"/>
        /// and with <paramref name="strokeStyle"/>.
        /// </summary>
        /// <param name="strokeWidth">Width of the stroke in pixels.
        /// The default value is 1.0.</param>
        /// <param name="strokeStyle">Stroke style applied to the stroke.
        /// This value can be null. The default value is null.</param>
        void DrawEllipse(
            Direct2DNet::D2D1_ELLIPSE ellipse,
            Direct2DNet::ID2D1Brush ^brush,
            [OptionalAttribute] System::Nullable<float> strokeWidth,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
        );

        /// <summary>
        /// Fills the ellipse using the <paramref name="brush"/>.
        /// </summary>
        void FillEllipse(
            Direct2DNet::D2D1_ELLIPSE ellipse,
            Direct2DNet::ID2D1Brush ^brush
        );

        /// <summary>
        /// Gets and sets the transformation matrix of the render target.
        /// </summary>
        property Direct2DNet::D2D1_MATRIX_3X2_F Transform
        {
            Direct2DNet::D2D1_MATRIX_3X2_F get()
            {
                ::D2D1_MATRIX_3X2_F temp;
                pin_ptr<::D2D1_MATRIX_3X2_F> pTemp = &temp;
                ((::ID2D1RenderTarget *)m_pResource)->GetTransform((::D2D1_MATRIX_3X2_F *)pTemp);
                pTemp = nullptr;
                return static_cast<Direct2DNet::D2D1_MATRIX_3X2_F>(temp);
            }

            void set(Direct2DNet::D2D1_MATRIX_3X2_F value)
            {
                ((::ID2D1RenderTarget *)m_pResource)->SetTransform(
                    static_cast<::D2D1_MATRIX_3X2_F>(value)
                );
            }
        }

        /// <summary>
        /// Clears the render target with the color <paramref name="clearColor"/>.
        /// </summary>
        void Clear(Direct2DNet::D2D1_COLOR_F clearColor);
    };
}