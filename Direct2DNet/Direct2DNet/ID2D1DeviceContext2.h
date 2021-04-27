#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1DeviceContext1.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICBitmapSource;
    }

    namespace Direct2DNet
    {
        namespace Effects
        {
            ref class ID2D1LookupTable3D;
        }

        ref class ID2D1Device2;
        ref class ID2D1Device3;
        ref class ID2D1Ink;
        ref class ID2D1InkStyle;
        ref class ID2D1GradientMesh;
        ref class ID2D1ImageSource;
        ref class ID2D1Brush;
        ref class ID2D1GdiMetafile;
        ref class ID2D1TransformedImageSource;
        ref class ID2D1ImageSourceFromWic;

        // Done.

        /// <summary>
        /// This interface performs all the same functions as the ID2D1DeviceContext1
        /// interface, plus it enables functionality such as ink rendering, gradient mesh
        /// rendering, and improved image loading.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("394ea6a3-0c34-4321-950b-6ca20f0be6c7")]
        public ref class ID2D1DeviceContext2 : Direct2DNet::ID2D1DeviceContext1
        {
        protected:
            ID2D1DeviceContext2(
                Direct2DNet::ID2D1Device3 ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );

        internal:
            ID2D1DeviceContext2() : Direct2DNet::ID2D1DeviceContext1() {}

            ID2D1DeviceContext2(
                Direct2DNet::ID2D1Device2 ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );

        public:
            /// <summary>
            /// Creates a new ID2D1Ink object that starts at the given point.
            /// </summary>
            /// <param name="startPoint">
            /// The starting point of the first segment of the first stroke in the new ink object.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the ink.
            /// </exception>
            Direct2DNet::ID2D1Ink ^CreateInk(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_INK_POINT %startPoint
            );

            /// <summary>
            /// Creates a new ink style.
            /// </summary>
            /// <param name="inkStyleProperties">
            /// The optional properties of the ink style to be created.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the ink style.
            /// </exception>
            Direct2DNet::ID2D1InkStyle ^CreateInkStyle(
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_INK_STYLE_PROPERTIES> inkStyleProperties
            );

            /// <summary>
            /// Creates a new ID2D1GradientMesh instance using the given array of patches.
            /// </summary>
            /// <param name="patches">
            /// The array containing the patches to be used in this mesh.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the mesh.
            /// </exception>
            Direct2DNet::ID2D1GradientMesh ^CreateGradientMesh(
                ... array<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> ^patches
            );

            /// <summary>
            /// Creates an image source object from a WIC bitmap source, while populating all pixel
            /// memory within the image source. The image is loaded andstored while using a minimal amount
            /// of memory.
            /// </summary>
            /// <param name="wicBitmapSource">
            /// The WIC bitmap source to create the image source from.
            /// </param>
            /// <param name="loadingOptions">
            /// Options for creating the image source.
            /// </param>
            /// <param name="alphaMode">
            /// The alpha mode of the image; this is determined automatically from the source¡¯s pixel format
            /// if <see cref="Direct2DNet::D2D1_ALPHA_MODE::UNKNOWN"/> is passed.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the image source.
            /// </exception>
            Direct2DNet::ID2D1ImageSourceFromWic ^CreateImageSourceFromWic(
                D2DNet::WICNet::IWICBitmapSource ^wicBitmapSource,
                Direct2DNet::D2D1_IMAGE_SOURCE_LOADING_OPTIONS loadingOptions,
                Direct2DNet::D2D1_ALPHA_MODE alphaMode
            );

            /// <summary>
            /// Creates a 3D lookup table for mapping a 3-channel input to a 3-channel output.
            /// The table data must be provided in 4-channel format.
            /// </summary>
            /// <param name="precision">
            /// Precision of the input lookup table data.
            /// </param>
            /// <param name="extents">
            /// Number of lookup table elements per dimension (X, Y, Z).
            /// </param>
            /// <param name="data">
            /// Buffer holding the lookup table data.
            /// </param>
            /// <param name="strides">
            /// A tuple containing two values. The first value is the size in bytes from one row
            /// (X dimension) of LUT data to the next. The second value is the size in bytes from one LUT
            /// data plane(X andY dimensions) to the next.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the lookup table.
            /// </exception>
            Direct2DNet::Effects::ID2D1LookupTable3D ^CreateLookupTable3D(
                Direct2DNet::D2D1_BUFFER_PRECISION precision,
                [InAttribute][IsReadOnlyAttribute] System::ValueTuple<UINT32, UINT32, UINT32> %extents,
                array<BYTE> ^data,
                [InAttribute][IsReadOnlyAttribute] System::ValueTuple<UINT32, UINT32> %strides
            );

            /// <summary>
            /// Creates an image source from a set of DXGI surface(s). The YCbCr surface(s) are converted
            /// to RGBA automatically during subsequent drawing.
            /// </summary>
            /// <param name="surfaces">
            /// The DXGI surfaces to create the image source from.
            /// </param>
            /// <param name="colorSpace">
            /// The color space of the input.
            /// </param>
            /// <param name="options">
            /// Options controlling color space conversions.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the image source.
            /// </exception>
            Direct2DNet::ID2D1ImageSource ^CreateImageSourceFromDxgi(
                array<DXGINet::IDXGISurface ^> ^surfaces,
                DXGINet::DXGI_COLOR_SPACE_TYPE colorSpace,
                Direct2DNet::D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS options
            );

            /// <summary>
            /// Retrieves the world-space bounds in DIPs of the gradient mesh using the device
            /// context DPI.
            /// </summary>
            /// <param name="gradientMesh">
            /// The gradient mesh whose world bounds will be calculated.
            /// </param>
            /// <param name="bounds">
            /// When this method returns, contains the bounds of the gradient mesh, in
            /// device independent pixels (DIPs)(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetGradientMeshWorldBounds(
                Direct2DNet::ID2D1GradientMesh ^gradientMesh,
                [OutAttribute] Direct2DNet::D2D1_RECT_F %bounds
            );

            /// <summary>
            /// Retrieves the world-space bounds in DIPs of the gradient mesh using the device
            /// context DPI.
            /// </summary>
            /// <param name="gradientMesh">
            /// The gradient mesh whose world bounds will be calculated.
            /// </param>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>) tuple. HRESULT is an error code.
            /// <see cref="Direct2DNet::D2D1_RECT_F"/> is the bounds of the gradient mesh, in
            /// device independent pixels (DIPs).
            /// </returns>
            System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> GetGradientMeshWorldBounds(
                Direct2DNet::ID2D1GradientMesh ^gradientMesh
            );

            /// <summary>
            /// Renders the given ink object using the given brush and ink style.
            /// </summary>
            /// <param name="ink">
            /// The ink object to be rendered.
            /// </param>
            /// <param name="brush">
            /// The brush with which to render the ink object.
            /// </param>
            /// <param name="inkStyle">
            /// Optional ink style to use when rendering the ink object.
            /// </param>
            void DrawInk(
                Direct2DNet::ID2D1Ink ^ink,
                Direct2DNet::ID2D1Brush ^brush,
                [OptionalAttribute] Direct2DNet::ID2D1InkStyle ^inkStyle
            );

            /// <summary>
            /// Renders a given gradient mesh to the target.
            /// </summary>
            void DrawGradientMesh(Direct2DNet::ID2D1GradientMesh ^gradientMesh);

            /// <summary>
            /// Draws a metafile to the device context using the given source and destination rectangles.
            /// </summary>
            /// <param name="gdiMetafile">
            /// The metafile to draw.
            /// </param>
            /// <param name="destinationRectangle">
            /// Optional rectangle in the target where the metafile will be drawn, relative to the upper
            /// left corner (defined in DIPs) of the render target. If null is specified, the destination
            /// rectangle is {0, 0, w, h}, where w and h are the width and height of the metafile as
            /// reported by ID2D1GdiMetafile::GetBounds.
            /// </param>
            /// <param name="sourceRectangle">
            /// Optional rectangle of the source metafile that will be drawn, relative to the upper left
            /// corner (defined in DIPs) of the metafile. If null is specified, the source rectangle is
            /// the value returned by ID2D1GdiMetafile1::GetSourceBounds.
            /// </param>
            void DrawGdiMetafile(
                Direct2DNet::ID2D1GdiMetafile ^gdiMetafile,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle
            );

            /// <summary>
            /// Creates an image source which shares resources with an original.
            /// </summary>
            /// <param name="imageSource">
            /// The original image.
            /// </param>
            /// <param name="properties">
            /// Properties for the source image.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the image source.
            /// </exception>
            Direct2DNet::ID2D1TransformedImageSource ^CreateTransformedImageSource(
                Direct2DNet::ID2D1ImageSource ^imageSource,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES %properties
            );
        };
    }
}