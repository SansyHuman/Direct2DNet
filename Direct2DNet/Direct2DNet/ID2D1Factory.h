#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"

namespace Direct2DNet
{
    ref class ID2D1HwndRenderTarget;
    ref class ID2D1StrokeStyle;

    /// <summary>
    /// The root factory interface for all of D2D's objects.
    /// </summary>
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
        /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
        ID2D1Factory(Direct2DNet::D2D1_FACTORY_TYPE type);
        ~ID2D1Factory();
        !ID2D1Factory();

        /// <summary>Gets the type of the factory.</summary>
        property Direct2DNet::D2D1_FACTORY_TYPE Type
        {
            Direct2DNet::D2D1_FACTORY_TYPE get()
            {
                return m_type;
            }
        }

        /// <summary>
        /// Create <see cref="Direct2DNet::ID2D1Factory"/> object.
        /// The type of the object can determine whether the factory
        /// and the derived resources can be invoked from single thread
        /// or multi thread.
        /// </summary>
        /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
        static Direct2DNet::ID2D1Factory ^CreateFactory(Direct2DNet::D2D1_FACTORY_TYPE type);

        /// <summary>
        /// Cause the factory to refresh any system metrics that it might have been snapped
        /// on factory creation.
        /// </summary>
        void ReloadSystemMetrics();

        /// <summary>
        /// Retrieves the current desktop DPI. To refresh this, call ReloadSystemMetrics.
        /// </summary>
        [System::ObsoleteAttribute("Deprecated. Use DisplayInformation::LogicalDpi for Windows Store Apps or GetDpiForWindow for desktop apps.")]
        void GetDesktopDpi(float %dpiX, float %dpiY);

        /// <summary>
        /// Retrieves the current desktop DPI. To refresh this, call ReloadSystemMetrics.
        /// </summary>
        [System::ObsoleteAttribute("Deprecated. Use DisplayInformation::LogicalDpi for Windows Store Apps or GetDpiForWindow for desktop apps.")]
        System::Tuple<float, float> ^GetDesktopDpi();

        /// <summary>
        /// Creates a non-default stroke style to be specified for a given geometry at draw
        /// time.
        /// </summary>
        /// <param name="dashes">
        /// An array whose elements are set to the length of each dash and space in the dash pattern.
        /// The first element sets the length of a dash, the second element sets the length of a space,
        /// the third element sets the length of a dash, and so on.
        /// the length is in unit of stroke width.
        /// </param>
        /// <seealso cref="Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES"/>
        Direct2DNet::ID2D1StrokeStyle ^CreateStrokeStyle(
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES properties,
            array<float> ^dashes
        );

        /// <summary>
        /// Creates a render target that appears on the display.
        /// </summary>
        /// <seealso cref="Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES"/>
        /// <seealso cref="Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES"/>
        Direct2DNet::ID2D1HwndRenderTarget ^CreateHwndRenderTarget(
            Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES renderTargetProperties,
            Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRenderTargetProperties
        );
    };
}
