#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

namespace Direct2DNet
{
    ref class ID2D1Brush;
    ref class ID2D1SolidColorBrush;
    ref class ID2D1StrokeStyle;

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
        /// Start drawing on this render target. Draw calls can only be issued between a
        /// BeginDraw and EndDraw call.
        /// </summary>
        void BeginDraw();

        /// <summary>
        /// Ends drawing on the render target, error results can be retrieved at this time,
        /// or when calling flush.
        /// </summary>
        /// <returns>
        /// The result code.
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
        property System::Tuple<float, float> ^Dpi
        {
            System::Tuple<float, float> ^get()
            {
                float dpiX, dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi(&dpiX, &dpiY);
                return gcnew System::Tuple<float, float>(dpiX, dpiY);
            }

            void set(System::Tuple<float, float> ^value)
            {
                ((::ID2D1RenderTarget *)m_pResource)->SetDpi(value->Item1, value->Item2);
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
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi(&dpiX, &dpiY);
                return dpiX;
            }

            void set(float value)
            {
                float dpiX, dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi(&dpiX, &dpiY);
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
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi(&dpiX, &dpiY);
                return dpiY;
            }

            void set(float value)
            {
                float dpiX, dpiY;
                ((::ID2D1RenderTarget *)m_pResource)->GetDpi(&dpiX, &dpiY);
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
        /// D2D1_FEATURE_LEVEL_9 nor D2D1_FEATURE_LEVEL_10 will be considered to be
        /// supported.
        /// </summary>
        bool IsSupported(Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES properties);

        /// <summary>
        /// Gets <see cref="Direct2DNet::ID2D1SolidColorBrush"/> instance of the <paramref name="color"/>.
        /// </summary>
        Direct2DNet::ID2D1SolidColorBrush ^CreateSolidColorBrush(Direct2DNet::D2D1_COLOR_F color);

        /// <summary>
        /// Draws the rectangle using the <paramref name="brush"/>.
        /// </summary>
        void DrawRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush);

        /// <summary>
        /// Draws the rectangle using the <paramref name="brush"/> in width <paramref name="strokeWidth"/>.
        /// </summary>
        void DrawRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush, float strokeWidth);

        /// <summary>
        /// Draws the rectangle using the <paramref name="brush"/> in width <paramref name="strokeWidth"/>
        /// and <paramref name="strokeStyle"/>.
        /// </summary>
        void DrawRectangle(
            Direct2DNet::D2D1_RECT_F rect,
            Direct2DNet::ID2D1Brush ^brush,
            float strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle);

        /// <summary>
        /// Fills the rectangle using the <paramref name="brush"/>.
        /// </summary>
        void FillRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush);

        /// <summary>
        /// Sets the transformation matrix of the render target.
        /// </summary>
        void SetTransform(Direct2DNet::D2D1_MATRIX_3X2_F transform);

        /// <summary>
        /// Clears the render target with the color <paramref name="clearColor"/>.
        /// </summary>
        void Clear(Direct2DNet::D2D1_COLOR_F clearColor);
    };
}