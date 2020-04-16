#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"

namespace Direct2DNet
{
    ref class ID2D1Geometry;
    ref class ID2D1RectangleGeometry;
    ref class ID2D1RoundedRectangleGeometry;
    ref class ID2D1EllipseGeometry;
    ref class ID2D1GeometryGroup;
    ref class ID2D1TransformedGeometry;
    ref class ID2D1PathGeometry;
    ref class ID2D1HwndRenderTarget;
    ref class ID2D1StrokeStyle;

    /// <summary>
    /// The root factory interface for all of D2D's objects.
    /// </summary>
    [System::Runtime::InteropServices::GuidAttribute("A804A679-80D3-43FE-93D5-75171B3427E2")]
    public ref class ID2D1Factory : public IDirect2DObject
    {
    internal:
        ::ID2D1Factory *m_pFactory;
        Direct2DNet::D2D1_FACTORY_TYPE m_type;

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
        ID2D1Factory(Direct2DNet::D2D1_FACTORY_TYPE type, Direct2DNet::D2D1_FACTORY_OPTIONS options);
        ~ID2D1Factory();
        !ID2D1Factory();

        virtual property void *NativePointer
        {
            virtual void *get()
            {
                return reinterpret_cast<void *>(m_pFactory);
            }
        }

        /// <summary>Gets the type of the factory.</summary>
        property Direct2DNet::D2D1_FACTORY_TYPE Type
        {
            Direct2DNet::D2D1_FACTORY_TYPE get()
            {
                return m_type;
            }
        }

        /// <summary>
        /// Creates <see cref="Direct2DNet::ID2D1Factory"/> object.
        /// The type of the object can determine whether the factory
        /// and the derived resources can be invoked from single thread
        /// or multi thread.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to create the factory.
        /// </exception>
        /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
        static Direct2DNet::ID2D1Factory ^CreateFactory(Direct2DNet::D2D1_FACTORY_TYPE type);

        /// <summary>
        /// Creates <see cref="Direct2DNet::ID2D1Factory"/> object.
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
        static Direct2DNet::ID2D1Factory ^CreateFactory(Direct2DNet::D2D1_FACTORY_TYPE type, Direct2DNet::D2D1_FACTORY_OPTIONS options);

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
        void GetDesktopDpi(float %dpiX, float %dpiY);

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
            Direct2DNet::D2D1_RECT_F rectangle
        );

        /// <summary>
        /// Creates a rounded rectangle geometry.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to create the geometry.
        /// </exception>
        /// <seealso cref="Direct2DNet::D2D1_ROUNDED_RECT"/>
        Direct2DNet::ID2D1RoundedRectangleGeometry ^CreateRoundedRectangleGeometry(
            Direct2DNet::D2D1_ROUNDED_RECT roundedRectangle
        );

        /// <summary>
        /// Creates an ellipse geometry.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to create the geometry.
        /// </exception>
        Direct2DNet::ID2D1EllipseGeometry ^CreateEllipseGeometry(
            Direct2DNet::D2D1_ELLIPSE ellipse
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
            Direct2DNet::D2D1_MATRIX_3X2_F transform
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
        /// This value can be null if you don't use custom dash style.
        /// </param>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to create the stroke style.
        /// </exception>
        /// <seealso cref="Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES"/>
        Direct2DNet::ID2D1StrokeStyle ^CreateStrokeStyle(
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES properties,
            array<float> ^dashes
        );

        /// <summary>
        /// Creates a render target that appears on the display.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to create the render target.
        /// </exception>
        /// <seealso cref="Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES"/>
        /// <seealso cref="Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES"/>
        Direct2DNet::ID2D1HwndRenderTarget ^CreateHwndRenderTarget(
            Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES renderTargetProperties,
            Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRenderTargetProperties
        );
    };
}
