#pragma once

#include "../IUnknown.h"
#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "../DWriteNet/DWriteSettings.h"
#include "ID2D1Resource.h"
#include <msclr/marshal.h>

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteTextFormat;
        ref class IDWriteRenderingParams;
    }

    namespace DXGINet
    {
        ref class IDXGISurface;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Bitmap;
        ref class ID2D1Brush;
        ref class ID2D1BitmapBrush;
        ref class ID2D1SolidColorBrush;
        ref class ID2D1GradientStopCollection;
        ref class ID2D1LinearGradientBrush;
        ref class ID2D1RadialGradientBrush;
        ref class ID2D1BitmapRenderTarget;
        ref class ID2D1Layer;
        ref class ID2D1Mesh;
        ref class ID2D1StrokeStyle;
        ref class ID2D1Geometry;
        ref class ID2D1DrawingStateBlock;
        ref class ID2D1GdiInteropRenderTarget;

        /// <summary>
        /// Represents an object that can receive drawing commands. Classes that inherit
        /// from <see cref="Direct2DNet::ID2D1RenderTarget"/> render the drawing commands
        /// they receive in different ways.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2cd90694-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1RenderTarget : Direct2DNet::ID2D1Resource
        {
        private:
            DWriteNet::IDWriteRenderingParams ^m_params = nullptr;

        protected:
            ID2D1RenderTarget(Direct2DNet::ID2D1Factory ^factory) : ID2D1Resource(factory) {}

        internal:
            ID2D1RenderTarget(
                Direct2DNet::ID2D1Factory ^factory,
                DXGINet::IDXGISurface ^surface,
                Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %properties
            );

        public:
            /// <summary>
            /// Creates an uninitialized Direct2D bitmap.
            /// </summary>
            /// <param name="size">The dimension of the bitmap to create in pixels.</param>
            /// <param name="bitmapProperties">The pixel format and dots per inch (DPI) of the bitmap
            /// to create.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the bitmap.
            /// </exception>
            Direct2DNet::ID2D1Bitmap ^CreateBitmap(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_U %size,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
            );

            /// <summary>
            /// Create a D2D bitmap by copying from memory, or create uninitialized.
            /// </summary>
            /// <param name="size">The dimension of the bitmap to create in pixels.</param>
            /// <param name="srcData">A pointer to the memory location of the image data, or
            /// null to create an uninitialized bitmap.</param>
            /// <param name="pitch">The byte count of each scanline, which is equal to
            /// (the image width in pixels * the number of bytes per pixel) + memory padding.
            /// If srcData is NULL, this value is ignored.</param>
            /// <param name="bitmapProperties">The pixel format and dots per inch (DPI) of the bitmap
            /// to create.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the bitmap.
            /// </exception>
            Direct2DNet::ID2D1Bitmap ^CreateBitmap(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_U %size,
                void *srcData,
                unsigned int pitch,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
            );

            // CreateBitmapFromWicBitmap

            /// <summary>
            /// Create a D2D bitmap by sharing bits from another resource. The bitmap must be
            /// compatible with the render target for the call to succeed. For example, an
            /// IWICBitmap can be shared with a software target, or a DXGI surface can be shared
            /// with a DXGI render target.
            /// </summary>
            /// <typeparam name="T">A type that inherits from the IUnknown interface.</typeparam>
            /// <param name="data">An ID2D1Bitmap, IDXGISurface, or an IWICBitmapLock that contains the
            /// data to share with the new ID2D1Bitmap.</param>
            /// <param name="bitmapProperties">The pixel format and dots per inch (DPI) of the bitmap
            /// to create.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the bitmap.
            /// </exception>
            generic<typename T> where T : D2DNet::IUnknown Direct2DNet::ID2D1Bitmap ^CreateSharedBitmap(
                T data,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
            );

            /// <summary>
            /// Creates a bitmap brush. The bitmap is scaled, rotated, skewed or tiled to fill
            /// or pen a geometry.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the bitmap brush.
            /// </exception>
            Direct2DNet::ID2D1BitmapBrush ^CreateBitmapBrush(
                Direct2DNet::ID2D1Bitmap ^bitmap
            );

            /// <summary>
            /// Gets <see cref="Direct2DNet::ID2D1SolidColorBrush"/> instance of the <paramref name="color"/>.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the brush.
            /// </exception>
            Direct2DNet::ID2D1SolidColorBrush ^CreateSolidColorBrush(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_COLOR_F %color
            );

            /// <summary>
            /// Gets <see cref="Direct2DNet::ID2D1GradientStopCollection"/> instance.
            /// A gradient stop collection represents a set of stops in an ideal unit length.
            /// This is the source resource for a linear gradient and radial gradient brush.
            /// </summary>
            /// <param name="colorInterpolationGamma">Specifies which space the color
            /// interpolation occurs in.</param>
            /// <param name="extendMode">Specifies how the gradient will be extended outside of
            /// the unit length.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the collection.
            /// </exception>
            Direct2DNet::ID2D1GradientStopCollection ^CreateGradientStopCollection(
                array<Direct2DNet::D2D1_GRADIENT_STOP> ^gradientStops,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_GAMMA> colorInterpolationGamma,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_EXTEND_MODE> extendMode
            );

            /// <summary>
            /// Gets <see cref="Direct2DNet::ID2D1LinearGradientBrush"/> instance.
            /// </summary>
            /// <param name="startPoint">Start point of the gradient in local coordinate space.</param>
            /// <param name="endPoint">End point of the gradient in local coordinate space.</param>
            /// <param name="gradientStopCollection"><see cref="Direct2DNet::ID2D1GradientStopCollection"/>
            /// used to draw.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the brush.
            /// </exception>
            Direct2DNet::ID2D1LinearGradientBrush ^CreateLinearGradientBrush(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %startPoint,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %endPoint,
                Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection
            );

            /// <summary>
            /// Gets <see cref="Direct2DNet::ID2D1LinearGradientBrush"/> instance.
            /// </summary>
            /// <param name="gradientStopCollection"><see cref="Direct2DNet::ID2D1GradientStopCollection"/>
            /// used to draw.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the brush.
            /// </exception>
            Direct2DNet::ID2D1LinearGradientBrush ^CreateLinearGradientBrush(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES %properties,
                Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection
            );

            /// <summary>
            /// Gets <see cref="Direct2DNet::ID2D1RadialGradientBrush"/> instance.
            /// </summary>
            /// <param name="gradientStopCollection"><see cref="Direct2DNet::ID2D1GradientStopCollection"/>
            /// used to draw.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the brush.
            /// </exception>
            Direct2DNet::ID2D1RadialGradientBrush ^CreateRadialGradientBrush(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES %properties,
                Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection
            );

            /// <summary>
            /// Creates a bitmap render target whose bitmap can be used as a source for
            /// rendering in the API.
            /// </summary>
            /// <param name="desiredSize">The requested size of the target in DIPs. If the pixel
            /// size is not specified, the DPI is inherited from the parent target. However, the
            /// render target will never contain a fractional number of pixels.</param>
            /// <param name="desiredPixelSize">The requested size of the render target in
            /// pixels. If the DIP size is also specified, the DPI is calculated from these two
            /// values. If the desired size is not specified, the DPI is inherited from the
            /// parent render target. If neither value is specified, the compatible render
            /// target will be the same size and have the same DPI as the parent target.</param>
            /// <param name="desiredFormat">The desired pixel format. The format must be
            /// compatible with the parent render target type. If the format is not specified,
            /// it will be inherited from the parent render target.</param>
            /// <param name="options">Allows the caller to retrieve a GDI compatible render
            /// target.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the render target.
            /// </exception>
            Direct2DNet::ID2D1BitmapRenderTarget ^CreateCompatibleRenderTarget(
                Direct2DNet::D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_SIZE_F> desiredSize,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_SIZE_U> desiredPixelSize,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_PIXEL_FORMAT> desiredFormat
            );

            /// <summary>
            /// Creates a layer resource that can be used on any target and which will resize
            /// under the covers if necessary.
            /// </summary>
            /// <param name="size">The resolution independent minimum size hint for the layer
            /// resource. Specify this to prevent unwanted reallocation of the layer backing
            /// store. The size is in DIPs, but, it is unaffected by the current world
            /// transform. If the size is unspecified, the returned resource is a placeholder
            /// and the backing store will be allocated to be the minimum size that can hold the
            /// content when the layer is pushed. The default value is null.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the layer.
            /// </exception>
            Direct2DNet::ID2D1Layer ^CreateLayer(
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_SIZE_F> size
            );

            /// <summary>
            /// Gets <see cref="Direct2DNet::ID2D1Mesh"/> instance.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the mesh.
            /// </exception>
            Direct2DNet::ID2D1Mesh ^CreateMesh();

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
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %point0,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %point1,
                Direct2DNet::ID2D1Brush ^brush,
                [OptionalAttribute] System::Nullable<float> strokeWidth,
                [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            );

            /// <summary>
            /// Draws the rectangle using the <paramref name="brush"/> in width <paramref name="strokeWidth"/>
            /// and with <paramref name="strokeStyle"/>.
            /// </summary>
            /// <param name="strokeWidth">Width of the stroke in pixels.
            /// The default value is 1.0.</param>
            /// <param name="strokeStyle">Stroke style applied to the stroke.
            /// This value can be null. The default value is null.</param>
            void DrawRectangle(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_F %rect,
                Direct2DNet::ID2D1Brush ^brush,
                [OptionalAttribute] System::Nullable<float> strokeWidth,
                [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            );

            /// <summary>
            /// Fills the rectangle using the <paramref name="brush"/>.
            /// </summary>
            void FillRectangle(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_F %rect,
                Direct2DNet::ID2D1Brush ^brush
            );

            /// <summary>
            /// Draws the rounded rectangle using the <paramref name="brush"/> in width
            /// <paramref name="strokeWidth"/> and with <paramref name="strokeStyle"/>.
            /// </summary>
            /// <param name="strokeWidth">Width of the stroke in pixels.
            /// The default value is 1.0.</param>
            /// <param name="strokeStyle">Stroke style applied to the stroke.
            /// This value can be null. The default value is null.</param>
            void DrawRoundedRectangle(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_ROUNDED_RECT %roundedRect,
                Direct2DNet::ID2D1Brush ^brush,
                [OptionalAttribute] System::Nullable<float> strokeWidth,
                [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            );

            /// <summary>
            /// Fills the rounded rectangle using the <paramref name="brush"/>.
            /// </summary>
            void FillRoundedRectangle(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_ROUNDED_RECT %roundedRect,
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
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_ELLIPSE %ellipse,
                Direct2DNet::ID2D1Brush ^brush,
                [OptionalAttribute] System::Nullable<float> strokeWidth,
                [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            );

            /// <summary>
            /// Fills the ellipse using the <paramref name="brush"/>.
            /// </summary>
            void FillEllipse(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_ELLIPSE %ellipse,
                Direct2DNet::ID2D1Brush ^brush
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

            /// <summary>
            /// Fills inside of the geometry using the <paramref name="brush"/>.
            /// </summary>
            /// <param name="opacityBrush">An optionally specified opacity brush. Only the alpha
            /// channel of the corresponding brush will be sampled and will be applied to the
            /// entire fill of the geometry. If this brush is specified, the fill brush must be
            /// a bitmap brush with an extend mode of D2D1_EXTEND_MODE_CLAMP.</param>
            void FillGeometry(
                Direct2DNet::ID2D1Geometry ^geometry,
                Direct2DNet::ID2D1Brush ^brush,
                [OptionalAttribute] Direct2DNet::ID2D1Brush ^opacityBrush
            );

            /// <summary>
            /// Fills a mesh. Since meshes can only render aliased content, the render target
            /// antialiasing mode must be set to aliased.
            /// </summary>
            void FillMesh(
                Direct2DNet::ID2D1Mesh ^mesh,
                Direct2DNet::ID2D1Brush ^brush
            );

            /// <summary>
            /// Fill using the alpha channel of the supplied opacity mask bitmap. The brush
            /// opacity will be modulated by the mask. The render target antialiasing mode must
            /// be set to aliased.
            /// </summary>
            /// <param name="content">The type of content the opacity mask contains. The value is
            /// used to determine the color space in which the opacity mask is blended.</param>
            /// <param name="destinationRectangle">The region of the render target to paint,
            /// in device-independent pixels. If the value is null, the destination rectangle 
            /// has the same size to the <paramref name="sourceRectangle"/> placed on the origin.
            /// If <paramref name="sourceRectangle"/> is also null, the destination rectangle has
            /// the same size with the size of the opacity mask bitmap. The default value is null.</param>
            /// <param name="sourceRectangle">The region of the bitmap to use as the opacity mask, in
            /// device-independent pixels. If this value is null, use the whole bitmap as the opacity
            /// mask. The default value is null.</param>
            void FillOpacityMask(
                Direct2DNet::ID2D1Bitmap ^opacityMask,
                Direct2DNet::ID2D1Brush ^brush,
                Direct2DNet::D2D1_OPACITY_MASK_CONTENT content,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle
            );

            /// <summary>
            /// Draws the specified bitmap after scaling it to the size of the specified rectangle.
            /// </summary>
            /// <param name="destinationRectangle">The size and position, in device-independent pixels
            /// in the render target's coordinate space, of the area to which the bitmap is drawn;
            /// Default value to draw the selected portion of the bitmap at the origin of the render target.
            /// If the rectangle is specified but not well-ordered, nothing is drawn, but the render target
            /// does not enter an error state.</param>
            /// <param name="opacity">A value between 0.0f and 1.0f, inclusive, that specifies an opacity
            /// value to apply to the bitmap; this value is multiplied against the alpha values of the
            /// bitmap's contents. The default value is 1.0f.</param>
            /// <param name="interpolationMode">The interpolation mode to use if the bitmap is scaled or
            /// rotated by the drawing operation. The default value is
            /// <see cref="Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE::LINEAR"/>.</param>
            /// <param name="sourceRectangle">The size and position, in device-independent pixels in the
            /// bitmap's coordinate space, of the area within the bitmap to be drawn;
            /// Default value to draw the entire bitmap.</param>
            void DrawBitmap(
                Direct2DNet::ID2D1Bitmap ^bitmap,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
                [OptionalAttribute] System::Nullable<float> opacity,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE> interpolationMode,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle
            );

            /// <summary>
            /// Draws the text within the given layout rectangle and by default also performs
            /// baseline snapping.
            /// </summary>
            /// <param name="layoutRect">The size and position of the area in which the text is drawn.</param>
            /// <param name="defaultFillBrush">The brush used to paint the text.</param>
            /// <param name="options">A value that indicates whether the text should be snapped to pixel
            /// boundaries and whether the text should be clipped to the layout rectangle. The default value
            /// is <see cref="Direct2DNet::D2D1_DRAW_TEXT_OPTIONS::NONE"/>, which indicates that text
            /// should be snapped to pixel boundaries and it should not be clipped to the layout
            /// rectangle.</param>
            /// <param name="measuringMode">A value that indicates how glyph metrics are used to measure text
            /// when it is formatted.
            /// The default value is <see cref="D2DNet::DWriteNet::DWRITE_MEASURING_MODE::NATURAL"/>.</param>
            void DrawText(
                System::String ^text,
                D2DNet::DWriteNet::IDWriteTextFormat ^textFormat,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_F %layoutRect,
                Direct2DNet::ID2D1Brush ^defaultFillBrush,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_DRAW_TEXT_OPTIONS> options,
                [OptionalAttribute] System::Nullable<D2DNet::DWriteNet::DWRITE_MEASURING_MODE> measuringMode
            );

            // DrawTextLayout

            // DrawGlyphRun

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
            /// Gets and sets the text rendering parameters of the render target.
            /// If you set the rendering parameters to null, it will use the default settings.
            /// </summary>
            property DWriteNet::IDWriteRenderingParams ^TextRenderingParams
            {
                DWriteNet::IDWriteRenderingParams ^get()
                {
                    return m_params;
                }

                void set(DWriteNet::IDWriteRenderingParams ^value);
            }

            /// <summary>
            /// Gets and sets tags to correspond to the succeeding primitives. If an error occurs
            /// rendering a primitive, the tags can be returned from the Flush or EndDraw call.
            /// </summary>
            property System::ValueTuple<D2D1_TAG, D2D1_TAG> Tags
            {
                System::ValueTuple<D2D1_TAG, D2D1_TAG> get()
                {
                    D2D1_TAG tag1, tag2;
                    ((::ID2D1RenderTarget *)m_pResource)->GetTags(&tag1, &tag2);
                    return System::ValueTuple<D2D1_TAG, D2D1_TAG>(tag1, tag2);
                }

                void set(System::ValueTuple<D2D1_TAG, D2D1_TAG> value)
                {
                    ((::ID2D1RenderTarget *)m_pResource)->SetTags(value.Item1, value.Item2);
                }
            }

            /// <summary>
            /// Gets and sets the first tag to correspond to the succeeding primitives. If an error occurs
            /// rendering a primitive, the tags can be returned from the Flush or EndDraw call.
            /// </summary>
            property D2D1_TAG Tag1
            {
                D2D1_TAG get()
                {
                    D2D1_TAG tag1;
                    ((::ID2D1RenderTarget *)m_pResource)->GetTags(&tag1, __nullptr);
                    return tag1;
                }

                void set(D2D1_TAG value)
                {
                    D2D1_TAG tag2;
                    ((::ID2D1RenderTarget *)m_pResource)->GetTags(__nullptr, &tag2);
                    ((::ID2D1RenderTarget *)m_pResource)->SetTags(value, tag2);
                }
            }

            /// <summary>
            /// Gets and sets the second tag to correspond to the succeeding primitives. If an error occurs
            /// rendering a primitive, the tags can be returned from the Flush or EndDraw call.
            /// </summary>
            property D2D1_TAG Tag2
            {
                D2D1_TAG get()
                {
                    D2D1_TAG tag2;
                    ((::ID2D1RenderTarget *)m_pResource)->GetTags(__nullptr, &tag2);
                    return tag2;
                }

                void set(D2D1_TAG value)
                {
                    D2D1_TAG tag1;
                    ((::ID2D1RenderTarget *)m_pResource)->GetTags(&tag1, __nullptr);
                    ((::ID2D1RenderTarget *)m_pResource)->SetTags(tag1, value);
                }
            }

            /// <summary>
            /// Set tags to correspond to the succeeding primitives. If an error occurs
            /// rendering a primitive, the tags can be returned from the Flush or EndDraw call.
            /// </summary>
            void SetTags(D2D1_TAG tag1, D2D1_TAG tag2);

            /// <summary>
            /// Retrieves the currently set tags. This does not retrieve the tags corresponding
            /// to any primitive that is in error.
            /// </summary>
            void GetTags(
                [OutAttribute] D2D1_TAG %tag1,
                [OutAttribute] D2D1_TAG %tag2
            );

            /// <summary>
            /// Start a layer of drawing calls. The way in which the layer must be resolved is
            /// specified first as well as the logical resource that stores the layer
            /// parameters. The supplied layer resource might grow if the specified content
            /// cannot fit inside it. The layer will grow monotonically on each axis.
            /// Starting from Windows 8, if a NULL ID2D1Layer is provided, then a layer resource
            /// will be allocated automatically.
            /// </summary>
            void PushLayer(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_LAYER_PARAMETERS %layerParameters,
                Direct2DNet::ID2D1Layer ^layer
            );

            /// <summary>
            /// Ends a layer that was defined with particular layer resources.
            /// </summary>
            void PopLayer();

            /// <summary>
            /// Executes all pending drawing commands.
            /// </summary>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT Flush();

            /// <summary>
            /// Executes all pending drawing commands and returns the tag for drawing operations that
            /// caused errors or 0 if there were no errors.
            /// </summary>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT Flush(
                [OutAttribute] D2D1_TAG %tag1,
                [OutAttribute] D2D1_TAG %tag2
            );

            /// <summary>
            /// Gets the current drawing state and saves it into the supplied
            /// ID2D1DrawingStatckBlock.
            /// </summary>
            void SaveDrawingState(Direct2DNet::ID2D1DrawingStateBlock ^drawingStateBlock);

            /// <summary>
            /// Copies the state stored in the block interface.
            /// </summary>
            void RestoreDrawingState(Direct2DNet::ID2D1DrawingStateBlock ^drawingStateBlock);

            /// <summary>
            /// Pushes a clip. The clip can be antialiased. The clip must be axis aligned. If
            /// the current world transform is not axis preserving, then the bounding box of the
            /// transformed clip rect will be used. The clip will remain in effect until a
            /// PopAxisAligned clip call is made.
            /// </summary>
            void PushAxisAlignedClip(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_F %clipRect,
                Direct2DNet::D2D1_ANTIALIAS_MODE antialiasMode
            );

            /// <summary>
            /// Removes the last axis-aligned clip from the render target. After this method is called,
            /// the clip is no longer applied to subsequent drawing operations.
            /// </summary>
            void PopAxisAlignedClip();

            /// <summary>
            /// Clears the render target with the color <paramref name="clearColor"/>.
            /// </summary>
            void Clear([InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_COLOR_F %clearColor);

            /// <summary>
            /// Clears the render target with transparent black.
            /// </summary>
            void Clear();

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
            /// Ends drawing on the render target and returns the tag for drawing operations that
            /// caused errors or 0 if there were no errors.
            /// </summary>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT EndDraw(
                [OutAttribute] D2D1_TAG %tag1,
                [OutAttribute] D2D1_TAG %tag2
            );

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
                    ((::ID2D1RenderTarget *)m_pResource)->GetDpi(&dpiX, &dpiY);
                    return System::ValueTuple<float, float>(dpiX, dpiY);
                }

                void set(System::ValueTuple<float, float> value)
                {
                    ((::ID2D1RenderTarget *)m_pResource)->SetDpi(value.Item1, value.Item2);
                }
            }

            /// <summary>
            /// Gets and the DPI on the render target.
            /// </summary>
            void GetDpi([OutAttribute] float %dpiX, [OutAttribute] float %dpiY);

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
            /// <see cref="Direct2DNet::D2D1_FEATURE_LEVEL::FEATURE_LEVEL_9"/>nor
            /// <see cref="Direct2DNet::D2D1_FEATURE_LEVEL::FEATURE_LEVEL_10"/> will be considered
            /// to be supported.
            /// </summary>
            bool IsSupported([InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %properties);

            /// <summary>
            /// Queries ID2D1GdiInteropRenderTarget from the render target.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the layer.
            /// </exception>
            Direct2DNet::ID2D1GdiInteropRenderTarget ^QueryToGdiInteropRenderTarget();
        };
    }
}