#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1RenderTarget.h"
#include "../DWriteNet/DWriteSettings.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGISurface;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Device;
        ref class ID2D1Device1;
        ref class ID2D1Image;
        ref class ID2D1Bitmap;
        ref class ID2D1Bitmap1;
        ref class ID2D1ColorContext;
        ref class ID2D1Effect;
        ref class ID2D1GradientStopCollection1;
        ref class ID2D1ImageBrush;
        ref class ID2D1BitmapBrush1;
        ref class ID2D1CommandList;
        ref class ID2D1GdiMetafile;
        ref class ID2D1Layer;

        /// <summary>
        /// The device context represents a set of state and a command buffer that is used
        /// to render to a target bitmap.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("e8f7fe7a-191c-466d-ad95-975678bda998")]
        public ref class ID2D1DeviceContext : Direct2DNet::ID2D1RenderTarget
        {
        private:
            Direct2DNet::ID2D1Device ^m_device;
            Direct2DNet::ID2D1Image ^m_target;

        protected:
            ID2D1DeviceContext(
                Direct2DNet::ID2D1Device1 ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );

        internal:
            ID2D1DeviceContext() : Direct2DNet::ID2D1RenderTarget() {}

            ID2D1DeviceContext(
                Direct2DNet::ID2D1Device ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options);

            ID2D1DeviceContext(
                DXGINet::IDXGISurface ^dxgiSurface,
                System::Nullable<Direct2DNet::D2D1_CREATION_PROPERTIES> %creationProperties
            );

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Creates a bitmap with extended bitmap properties, potentially from a block of
            /// memory.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the bitmap.
            /// </exception>
            Direct2DNet::ID2D1Bitmap1 ^CreateBitmap(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_U %size,
                void *sourceData,
                unsigned int pitch,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties
            );

            // CreateBitmapFromWicBitmap

            /// <summary>
            /// Creates a color context.
            /// </summary>
            /// <param name="profile">
            /// A buffer containing the ICC profile bytes used to initialize the color context when
            /// space is <see cref="Direct2DNet::D2D1_COLOR_SPACE::CUSTOM"/>. For other types, the parameter
            /// is ignored and should be set to NULL.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the color context.
            /// </exception>
            Direct2DNet::ID2D1ColorContext ^CreateColorContext(
                Direct2DNet::D2D1_COLOR_SPACE space,
                array<unsigned char> ^profile
            );

            /// <summary>
            /// Creates a color context by loading it from the specified filename.
            /// The profile bytes are the contents of the file specified by Filename.
            /// </summary>
            /// <param name="filename">
            /// The path to the file containing the profile bytes to initialize the color context with.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the color context.
            /// </exception>
            Direct2DNet::ID2D1ColorContext ^CreateColorContextFromFilename(
                System::String ^filename
            );

            // CreateColorContextFromWicColorContext

            /// <summary>
            /// Creates a bitmap from a DXGI surface with a set of extended properties.
            /// </summary>
            Direct2DNet::ID2D1Bitmap1 ^CreateBitmapFromDxgiSurface(
                DXGINet::IDXGISurface ^surface,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties
            );

            /// <summary>
            /// Create a new effect, the effect must either be built in or previously registered
            /// through ID2D1Factory1::RegisterEffectFromStream or
            /// ID2D1Factory1::RegisterEffectFromString.
            /// </summary>
            Direct2DNet::ID2D1Effect ^CreateEffect([InAttribute][IsReadOnlyAttribute] System::Guid %effectId);

            /// <summary>
            /// Creates a gradient stop collection represents a set of stops in an ideal unit length.
            /// This is the source resource for a linear gradient and radial gradient brush.
            /// </summary>
            /// <param name="preInterpolationSpace">Specifies both the input color space and the
            /// space in which the color interpolation occurs.</param>
            /// <param name="postInterpolationSpace">Specifies the color space colors will be
            /// converted to after interpolation occurs.</param>
            /// <param name="bufferPrecision">Specifies the precision in which the gradient
            /// buffer will be held.</param>
            /// <param name="extendMode">Specifies how the gradient will be extended outside of
            /// the unit length.</param>
            /// <param name="colorInterpolationMode">Determines if colors will be interpolated
            /// in straight alpha or premultiplied alpha space.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the collection.
            /// </exception>
            Direct2DNet::ID2D1GradientStopCollection1 ^CreateGradientStopCollection(
                array<Direct2DNet::D2D1_GRADIENT_STOP> ^straightAlphaGradientStops,
                Direct2DNet::D2D1_COLOR_SPACE preInterpolationSpace,
                Direct2DNet::D2D1_COLOR_SPACE postInterpolationSpace,
                Direct2DNet::D2D1_BUFFER_PRECISION bufferPrecision,
                Direct2DNet::D2D1_EXTEND_MODE extendMode,
                Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE colorInterpolationMode
            );

            /// <summary>
            /// Creates an image brush, the input image can be any type of image, including a
            /// bitmap, effect and a command list.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the brush.
            /// </exception>
            Direct2DNet::ID2D1ImageBrush ^CreateImageBrush(
                Direct2DNet::ID2D1Image ^image,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES %imageBrushProperties
            );

            /// <summary>
            /// Creates a bitmap brush, the input image is a Direct2D bitmap object.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the bitmap brush.
            /// </exception>
            Direct2DNet::ID2D1BitmapBrush1 ^CreateBitmapBrush1(
                Direct2DNet::ID2D1Bitmap ^bitmap
            );

            /// <summary>
            /// Creates a new command list.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the command list.
            /// </exception>
            Direct2DNet::ID2D1CommandList ^CreateCommandList();

            /// <summary>
            /// Indicates whether the format is supported by D2D.
            /// </summary>
            bool IsDxgiFormatSupported(DXGINet::DXGI_FORMAT format);

            /// <summary>
            /// Indicates whether the buffer precision is supported by D2D.
            /// </summary>
            bool IsBufferPrecisionSupported(Direct2DNet::D2D1_BUFFER_PRECISION bufferPrecision);

            /// <summary>
            /// Gets the local-space bounds of an image without the world transform of the context applied.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>) tuple. If this method succeeds, HRESULT is
            /// S_OK(0). Otherwise, it is an error code. <see cref="Direct2DNet::D2D1_RECT_F"/> is the bounds
            /// of the image.
            /// </returns>
            System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> GetImageLocalBounds(
                Direct2DNet::ID2D1Image ^image
            );

            /// <summary>
            /// Gets the local-space bounds of an image without the world transform of the context applied.
            /// </summary>
            /// <param name="localBounds">Bounds of the image(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetImageLocalBounds(
                Direct2DNet::ID2D1Image ^image,
                [OutAttribute] Direct2DNet::D2D1_RECT_F %localBounds
            );

            /// <summary>
            /// Gets the world-space bounds of an image with the world transform of the context applied.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>) tuple. If this method succeeds, HRESULT is
            /// S_OK(0). Otherwise, it is an error code. <see cref="Direct2DNet::D2D1_RECT_F"/> is the bounds
            /// of the image.
            /// </returns>
            System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> GetImageWorldBounds(
                Direct2DNet::ID2D1Image ^image
            );

            /// <summary>
            /// Gets the world-space bounds of an image with the world transform of the context applied.
            /// </summary>
            /// <param name="worldBounds">Bounds of the image(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetImageWorldBounds(
                Direct2DNet::ID2D1Image ^image,
                [OutAttribute] Direct2DNet::D2D1_RECT_F %worldBounds
            );

            /// <summary>
            /// Retrieves the world-space bounds in DIPs of the glyph run using the device
            /// context DPI.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>) tuple. If this method succeeds, HRESULT is
            /// S_OK(0). Otherwise, it is an error code. <see cref="Direct2DNet::D2D1_RECT_F"/> is the bounds
            /// of the glyph run.
            /// </returns>
            System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> GetGlyphRunWorldBounds(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %baselineOrigin,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode
            );

            /// <summary>
            /// Retrieves the world-space bounds in DIPs of the glyph run using the device
            /// context DPI.
            /// </summary>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetGlyphRunWorldBounds(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %baselineOrigin,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode,
                [OutAttribute] Direct2DNet::D2D1_RECT_F %bounds
            );

            /// <summary>
            /// Gets the device associated with this device context.
            /// </summary>
            property Direct2DNet::ID2D1Device ^Device
            {
                Direct2DNet::ID2D1Device ^get()
                {
                    return m_device;
                }
            }

            /// <summary>
            /// Gets and sets the target for this device context to point to the given image. The image
            /// can be a command list or a bitmap created with the 
            /// <see cref="Direct2DNet::D2D1_BITMAP_OPTIONS::TARGET"/> flag.
            /// </summary>
            property Direct2DNet::ID2D1Image ^Target
            {
                Direct2DNet::ID2D1Image ^get();
                void set(Direct2DNet::ID2D1Image ^value);
            }

            /// <summary>
            /// Gets and sets the rendering controls for internal rendering inside the device context.
            /// </summary>
            property Direct2DNet::D2D1_RENDERING_CONTROLS RenderingControls
            {
                Direct2DNet::D2D1_RENDERING_CONTROLS get()
                {
                    ::D2D1_RENDERING_CONTROLS control;

                    ((::ID2D1DeviceContext *)m_pResource)->GetRenderingControls(&control);
                    return static_cast<Direct2DNet::D2D1_RENDERING_CONTROLS>(control);
                }

                void set(Direct2DNet::D2D1_RENDERING_CONTROLS value)
                {
                    ((::ID2D1DeviceContext *)m_pResource)->SetRenderingControls(
                        &static_cast<::D2D1_RENDERING_CONTROLS>(value)
                    );
                }
            }

            /// <summary>
            /// Gets and sets the primitive blend for all of the rendering operations.
            /// </summary>
            property Direct2DNet::D2D1_PRIMITIVE_BLEND PrimitiveBlend
            {
                Direct2DNet::D2D1_PRIMITIVE_BLEND get()
                {
                    return (Direct2DNet::D2D1_PRIMITIVE_BLEND)((int)
                        ((::ID2D1DeviceContext *)m_pResource)->GetPrimitiveBlend()
                        );
                }

                void set(Direct2DNet::D2D1_PRIMITIVE_BLEND value)
                {
                    ((::ID2D1DeviceContext *)m_pResource)->SetPrimitiveBlend(
                        (::D2D1_PRIMITIVE_BLEND)((int)value)
                    );
                }
            }

            /// <summary>
            /// Gets and sets the units used for all of the rendering operations.
            /// </summary>
            property Direct2DNet::D2D1_UNIT_MODE UnitMode
            {
                Direct2DNet::D2D1_UNIT_MODE get()
                {
                    return (Direct2DNet::D2D1_UNIT_MODE)((int)
                        ((::ID2D1DeviceContext *)m_pResource)->GetUnitMode()
                        );
                }

                void set(Direct2DNet::D2D1_UNIT_MODE value)
                {
                    ((::ID2D1DeviceContext *)m_pResource)->SetUnitMode(
                        (::D2D1_UNIT_MODE)((int)value)
                    );
                }
            }

            /// <summary>
            /// Draws the glyph run with an extended description to describe the glyphs.
            /// </summary>
            /// <param name="baselineOrigin">Origin of first glyph in the series.</param>
            /// <param name="glyphRun">The glyphs to render.</param>
            /// <param name="foregroundBrush">The brush that defines the text color.</param>
            /// <param name="glyphRunDescription">Supplementary glyph series information.
            /// The default value is null.</param>
            /// <param name="measuringMode">The measuring mode of the glyph series, used to determine the
            /// advances and offsets. The default value is
            /// <see cref="D2DNet::DWriteNet::DWRITE_MEASURING_MODE::NATURAL"/>.</param>
            void DrawGlyphRun(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %baselineOrigin,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
                Direct2DNet::ID2D1Brush ^foregroundBrush,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_GLYPH_RUN_DESCRIPTION> glyphRunDescription,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MEASURING_MODE> measuringMode
            );

            /// <summary>
            /// Draw an image to the device context. The image represents either a concrete
            /// bitmap or the output of an effect graph.
            /// </summary>
            /// <param name="targetOffset">The offset in the destination space that the image will be
            /// rendered to. The entire logical extent of the image will be rendered to the corresponding
            /// destination. If not specified, the destination origin will be (0, 0). The top-left corner
            /// of the image will be mapped to the target offset. This will not necessarily be the origin.
            /// The default value is null.</param>
            /// <param name="imageRectangle">The corresponding rectangle in the image space will be mapped
            /// to the given origins when processing the image. The default value is null.</param>
            /// <param name="interpolationMode">The interpolation mode that will be used to scale the image
            /// if necessary. The default value is <see cref="Direct2DNet::D2D1_INTERPOLATION_MODE::LINEAR"/>.
            /// </param>
            /// <param name="compositeMode">The composite mode that will be applied to the limits of
            /// the currently selected clip. The default value is
            /// <see cref="Direct2DNet::D2D1_COMPOSITE_MODE::SOURCE_OVER"/>.</param>
            void DrawImage(
                Direct2DNet::ID2D1Image ^image,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_POINT_2F> targetOffset,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> imageRectangle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_INTERPOLATION_MODE> interpolationMode,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_COMPOSITE_MODE> compositeMode
            );

            /// <summary>
            /// Draws the output of the effect as an image.
            /// </summary>
            /// <param name="targetOffset">The offset in the destination space that the image will be
            /// rendered to. The entire logical extent of the image will be rendered to the corresponding
            /// destination. If not specified, the destination origin will be (0, 0). The top-left corner
            /// of the image will be mapped to the target offset. This will not necessarily be the origin.
            /// The default value is null.</param>
            /// <param name="imageRectangle">The corresponding rectangle in the image space will be mapped
            /// to the given origins when processing the image. The default value is null.</param>
            /// <param name="interpolationMode">The interpolation mode that will be used to scale the image
            /// if necessary. The default value is <see cref="Direct2DNet::D2D1_INTERPOLATION_MODE::LINEAR"/>.
            /// </param>
            /// <param name="compositeMode">The composite mode that will be applied to the limits of
            /// the currently selected clip. The default value is
            /// <see cref="Direct2DNet::D2D1_COMPOSITE_MODE::SOURCE_OVER"/>.</param>
            void DrawImage(
                Direct2DNet::ID2D1Effect ^effect,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_POINT_2F> targetOffset,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> imageRectangle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_INTERPOLATION_MODE> interpolationMode,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_COMPOSITE_MODE> compositeMode
            );

            /// <summary>
            /// Draw a metafile to the device context.
            /// </summary>
            /// <param name="gdiMetafile">The metafile to draw.</param>
            /// <param name="targetOffset">Optional offset from the upper left corner of the render target.
            /// </param>
            void DrawGdiMetafile(
                Direct2DNet::ID2D1GdiMetafile ^gdiMetafile,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_POINT_2F> targetOffset
                );

            /// <summary>
            /// Draws a bitmap to the render target.
            /// </summary>
            /// <param name="opacity">The opacity of the bitmap.</param>
            /// <param name="interpolationMode">The interpolation mode to use.</param>
            /// <param name="destinationRectangle">The destination rectangle. The default is the size
            /// of the bitmap and the location is the upper left corner of the render target.
            /// </param>
            /// <param name="sourceRectangle">An optional source rectangle. The default value is null.</param>
            /// <param name="perspectiveTransform">An optional perspective transform.
            /// The default value is null.</param>
            void DrawBitmap(
                Direct2DNet::ID2D1Bitmap ^bitmap,
                float opacity,
                Direct2DNet::D2D1_INTERPOLATION_MODE interpolationMode,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_4X4_F> perspectiveTransform
            );

            /// <summary>
            /// Push a layer on the device context.
            /// </summary>
            void PushLayer(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_LAYER_PARAMETERS1 %layerParameters,
                Direct2DNet::ID2D1Layer ^layer
            );

            /// <summary>
            /// This indicates that a portion of an effect's input is invalid. This method can
            /// be called many times.
            /// </summary>
            /// <param name="input">The input index.</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT InvalidateEffectInputRectangle(
                Direct2DNet::ID2D1Effect ^effect,
                unsigned int input,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_F %inputRectangle
            );

            /// <summary>
            /// Gets the number of invalid ouptut rectangles that have accumulated at the
            /// effect.
            /// </summary>
            /// <returns>
            /// (HRESULT, uint) tuple. If this method succeeds, HRESULT is S_OK(0). Otherwise, it is an
            /// error code. uint is the number of invalid rectangles.
            /// </returns>
            System::ValueTuple<HRESULT, unsigned int> GetEffectInvalidRectangleCount(
                Direct2DNet::ID2D1Effect ^effect
            );

            /// <summary>
            /// Gets the number of invalid ouptut rectangles that have accumulated at the
            /// effect.
            /// </summary>
            /// <param name="rectangleCount">The number of invalid output rectangles(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetEffectInvalidRectangleCount(
                Direct2DNet::ID2D1Effect ^effect,
                [OutAttribute] unsigned int %rectangleCount
            );

            /// <summary>
            /// Gets the invalid rectangles that are at the output of the effect.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>[]) tuple. If this method succeeds, HRESULT
            /// is S_OK(0). Otherwise, it is an error code. <see cref="Direct2DNet::D2D1_RECT_F"/>[] is the
            /// array of rectangles.
            /// </returns>
            System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^> GetEffectInvalidRectangles(
                Direct2DNet::ID2D1Effect ^effect
            );

            /// <summary>
            /// Gets the invalid rectangles that are at the output of the effect.
            /// </summary>
            /// <param name="rectangles">The array of rectangles(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetEffectInvalidRectangles(
                Direct2DNet::ID2D1Effect ^effect,
                [OutAttribute] array<Direct2DNet::D2D1_RECT_F> ^%rectangles
            );

            /// <summary>
            /// Gets the maximum region of each specified input which would be used during a
            /// subsequent rendering operation
            /// </summary>
            /// <param name="renderEffect">The image whose output is being rendered.</param>
            /// <param name="inputDescription">A list of the inputs whos rectangles are being queried.</param>
            /// <param name="renderImageRectangle">The portion of the output image whose inputs are
            /// being inspected. The default value is null.</param>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>[]) tuple. If this method succeeds, HRESULT
            /// is S_OK(0). Otherwise, it is an error code. <see cref="Direct2DNet::D2D1_RECT_F"/>[] is the
            /// array of required input rectangles.
            /// </returns>
            System::ValueTuple<HRESULT, array<Direct2DNet::D2D1_RECT_F> ^> GetEffectRequiredInputRectangles(
                Direct2DNet::ID2D1Effect ^renderEffect,
                array<Direct2DNet::D2D1_EFFECT_INPUT_DESCRIPTION> ^inputDescription,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> renderImageRectangle
            );

            /// <summary>
            /// Gets the maximum region of each specified input which would be used during a
            /// subsequent rendering operation
            /// </summary>
            /// <param name="renderEffect">The image whose output is being rendered.</param>
            /// <param name="inputDescription">A list of the inputs whos rectangles are being queried.</param>
            /// <param name="requiredInputRects">The input rectangles returned to the caller
            /// (out parameter).</param>
            /// <param name="renderImageRectangle">The portion of the output image whose inputs are
            /// being inspected. The default value is null.</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetEffectRequiredInputRectangles(
                Direct2DNet::ID2D1Effect ^renderEffect,
                array<Direct2DNet::D2D1_EFFECT_INPUT_DESCRIPTION> ^inputDescription,
                [OutAttribute] array<Direct2DNet::D2D1_RECT_F> ^%requiredInputRects,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> renderImageRectangle
            );

            /// <summary>
            /// Fill using the alpha channel of the supplied opacity mask bitmap. The brush
            /// opacity will be modulated by the mask. The render target antialiasing mode must
            /// be set to aliased.
            /// </summary>
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
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle
            );
        };
    }
}