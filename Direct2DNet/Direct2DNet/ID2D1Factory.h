#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGISurface;
    }

    namespace DWriteNet
    {
        ref class IDWriteRenderingParams;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Geometry;
        ref class ID2D1RectangleGeometry;
        ref class ID2D1RoundedRectangleGeometry;
        ref class ID2D1EllipseGeometry;
        ref class ID2D1GeometryGroup;
        ref class ID2D1TransformedGeometry;
        ref class ID2D1PathGeometry;
        ref class ID2D1DrawingStateBlock;
        ref class ID2D1HwndRenderTarget;
        ref class ID2D1RenderTarget;
        ref class ID2D1DCRenderTarget;
        ref class ID2D1StrokeStyle;
        ref class ID2D1Multithread;

        /// <summary>
        /// The root factory interface for all of D2D's objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("06152247-6f50-465a-9245-118bfd3b6007")]
        public ref class ID2D1Factory : public IDirect2DObject
        {
        internal:
            ::ID2D1Factory *m_pFactory;
            Direct2DNet::D2D1_FACTORY_TYPE m_type;

        protected:
            ID2D1Factory(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                System::Guid guid
            );

            ID2D1Factory(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                Direct2DNet::D2D1_FACTORY_OPTIONS %options,
                System::Guid guid
            );

        internal:
            // Called by ID2D1CommandSink
            ID2D1Factory(::ID2D1Factory *pFactory);

        public:

            /// <summary>
            /// Create <see cref="Direct2DNet::ID2D1Factory"/> object.
            /// The type of the object can determine whether the factory
            /// and the derived resources can be invoked from single thread
            /// or multi thread.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
            ID2D1Factory(Direct2DNet::D2D1_FACTORY_TYPE type);

            /// <summary>
            /// Create <see cref="Direct2DNet::ID2D1Factory"/> object.
            /// The type of the object can determine whether the factory
            /// and the derived resources can be invoked from single thread
            /// or multi thread.
            /// The options determine the debug layer level.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_OPTIONS"/>
            ID2D1Factory(
                Direct2DNet::D2D1_FACTORY_TYPE type, 
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_FACTORY_OPTIONS %options
            );
            ~ID2D1Factory();
            !ID2D1Factory();

            virtual bool Equals(System::Object ^other) override;

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return reinterpret_cast<void *>(m_pFactory);
                }
            }

            /// <summary>
            /// Cause the factory to refresh any system metrics that it might have been snapped
            /// on factory creation.
            /// </summary>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT ReloadSystemMetrics();

            /// <summary>
            /// Retrieves the current desktop DPI. To refresh this, call ReloadSystemMetrics.
            /// </summary>
            [System::ObsoleteAttribute("Deprecated.")]
            void GetDesktopDpi([OutAttribute] float %dpiX, [OutAttribute] float %dpiY);

            /// <summary>
            /// Retrieves the current desktop DPI. To refresh this, call ReloadSystemMetrics.
            /// </summary>
            [System::ObsoleteAttribute("Deprecated.")]
            System::ValueTuple<float, float> ^GetDesktopDpi();

            /// <summary>
            /// Creates a rectangle geometry.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the geometry.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_RECT_F"/>
            Direct2DNet::ID2D1RectangleGeometry ^CreateRectangleGeometry(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_F %rectangle
            );

            /// <summary>
            /// Creates a rounded rectangle geometry.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the geometry.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_ROUNDED_RECT"/>
            Direct2DNet::ID2D1RoundedRectangleGeometry ^CreateRoundedRectangleGeometry(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_ROUNDED_RECT %roundedRectangle
            );

            /// <summary>
            /// Creates an ellipse geometry.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the geometry.
            /// </exception>
            Direct2DNet::ID2D1EllipseGeometry ^CreateEllipseGeometry(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_ELLIPSE %ellipse
            );

            /// <summary>
            /// Creates a geometry group.
            /// </summary>
            /// <param name="fillMode">
            /// Fill mode to apply to the geometry group.
            /// </param>
            /// <param name="geometries">
            /// An array of source geometries.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the geometry group.
            /// </exception>
            Direct2DNet::ID2D1GeometryGroup ^CreateGeometryGroup(
                Direct2DNet::D2D1_FILL_MODE fillMode,
                ... array<Direct2DNet::ID2D1Geometry ^> ^geometries
            );

            /// <summary>
            /// Creates a transformed geometry.
            /// </summary>
            /// <param name="sourceGeometry">
            /// A geometry to apply transform.
            /// </param>
            /// <param name="transform">
            /// A transform matrix to apply to the geometry.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the geometry.
            /// </exception>
            Direct2DNet::ID2D1TransformedGeometry ^CreateTransformedGeometry(
                Direct2DNet::ID2D1Geometry ^sourceGeometry,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %transform
            );

            /// <summary>
            /// Creates an initially empty path geometry instance. A geometry sink is created
            /// off the interface to populate it.
            /// </summary>
            Direct2DNet::ID2D1PathGeometry ^CreatePathGeometry();

            /// <summary>
            /// Creates a non-default stroke style to be specified for a given geometry at draw
            /// time.
            /// </summary>
            /// <param name="dashes">
            /// An array whose elements are set to the length of each dash and space in the dash pattern.
            /// The first element sets the length of a dash, the second element sets the length of a space,
            /// the third element sets the length of a dash, and so on.
            /// the length is in unit of stroke width.
            /// This value should be null if you don't use custom dash style. Do not use the empty array.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the stroke style.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES"/>
            Direct2DNet::ID2D1StrokeStyle ^CreateStrokeStyle(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES %properties,
                array<float> ^dashes
            );

            /// <summary>
            /// Creates a new drawing state block, this can be used in subsequent
            /// SaveDrawingState and RestoreDrawingState operations on the render target.
            /// </summary>
            /// <param name="drawingStateDescription">
            /// A structure that contains antialiasing, transform, and tags information. The default value
            /// is null.
            /// </param>
            /// <param name="textRenderingParams">
            /// Optional text parameters that indicate how text should be rendered. The default value is null.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the block.
            /// </exception>
            Direct2DNet::ID2D1DrawingStateBlock ^CreateDrawingStateBlock(
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION> drawingStateDescription,
                [OptionalAttribute] D2DNet::DWriteNet::IDWriteRenderingParams ^textRenderingParams
            );

            // CreateWicBitmapRenderTarget

            /// <summary>
            /// Creates a render target that appears on the display.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the render target.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES"/>
            /// <seealso cref="Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES"/>
            Direct2DNet::ID2D1HwndRenderTarget ^CreateHwndRenderTarget(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES %hwndRenderTargetProperties
            );

            /// <summary>
            /// Creates a render target that draws to a DXGI Surface. The device that owns the
            /// surface is used for rendering.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the render target.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES"/>
            Direct2DNet::ID2D1RenderTarget ^CreateDxgiSurfaceRenderTarget(
                DXGINet::IDXGISurface ^dxgiSurface,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties
            );

            /// <summary>
            /// Creates a render target that draws to a GDI device context.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the render target.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES"/>
            Direct2DNet::ID2D1DCRenderTarget ^CreateDCRenderTarget(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties
            );

            /// <summary>
            /// Queries the factory to ID2D1Multithread interface.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to query to ID2D1Multithread.
            /// </exception>
            Direct2DNet::ID2D1Multithread ^QueryToID2D1Multithread();
        };
    }
}