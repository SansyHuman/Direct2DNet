#pragma once

#include "D2DMath.h"
#include "../DXGINet/DXGISettings.h"

using namespace System::Runtime;

namespace D2DNet
{
    namespace Direct2DNet
    {
        /// <summary>
        /// Specifies the threading model of the created factory and all of its derived
        /// resources.
        /// </summary>
        public enum class D2D1_FACTORY_TYPE
        {
            /// <summary>
            /// The resulting factory and derived resources may only be invoked serially.
            /// Reference counts on resources are interlocked, however, resource and render
            /// target state is not protected from multi-threaded access.
            /// </summary>
            SINGLE_THREADED = 0,

            /// <summary>
            /// The resulting factory may be invoked from multiple threads. Returned resources
            /// use interlocked reference counting and their state is protected.
            /// </summary>
            MULTI_THREADED = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Indicates the debug level to be output by the debug layer.
        /// </summary>
        public enum class D2D1_DEBUG_LEVEL
        {
            /// <summary>
            /// Direct2D does not produce any debugging output.
            /// </summary>
            LEVEL_NONE = 0,

            /// <summary>
            /// Direct2D sends error messages to the debug layer.
            /// </summary>
            LEVEL_ERROR = 1,

            /// <summary>
            /// Direct2D sends error messages and warnings to the debug layer.
            /// </summary>
            LEVEL_WARNING = 2,

            /// <summary>
            /// Direct2D sends error messages, warnings, and additional diagnostic information
            /// that can help improve performance to the debug layer.
            /// </summary>
            LEVEL_INFORMATION = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Allows additional parameters for factory creation.
        /// </summary>
        public value struct D2D1_FACTORY_OPTIONS
        {
            /// <summary>
            /// Requests a certain level of debugging information from the debug layer. This
            /// parameter is ignored if the debug layer DLL is not present.
            /// </summary>
            Direct2DNet::D2D1_DEBUG_LEVEL debugLevel;

            D2D1_FACTORY_OPTIONS(Direct2DNet::D2D1_DEBUG_LEVEL debugLevel)
                : debugLevel(debugLevel) {}

            static operator ::D2D1_FACTORY_OPTIONS(Direct2DNet::D2D1_FACTORY_OPTIONS %rhs)
            {
                ::D2D1_FACTORY_OPTIONS value;
                value.debugLevel = (::D2D1_DEBUG_LEVEL)((int)rhs.debugLevel);

                return value;
            }

            static operator Direct2DNet::D2D1_FACTORY_OPTIONS(::D2D1_FACTORY_OPTIONS %rhs)
            {
                Direct2DNet::D2D1_FACTORY_OPTIONS value;
                value.debugLevel = (Direct2DNet::D2D1_DEBUG_LEVEL)((int)rhs.debugLevel);

                return value;
            }
        };

        /// <summary>
        /// Describes whether a render target uses hardware or software rendering, or if
        /// Direct2D should select the rendering mode.
        /// </summary>
        public enum class D2D1_RENDER_TARGET_TYPE
        {
            /// <summary>
            /// D2D is free to choose the render target type for the caller.
            /// </summary>
            DEFAULT = 0,

            /// <summary>
            /// The render target will render using the CPU.
            /// </summary>
            SOFTWARE = 1,

            /// <summary>
            /// The render target will render using the GPU.
            /// </summary>
            HARDWARE = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Qualifies how alpha is to be treated in a bitmap or render target containing
        /// alpha.
        /// </summary>
        public enum class D2D1_ALPHA_MODE
        {
            /// <summary>
            /// Alpha mode should be determined implicitly. Some target surfaces do not supply
            /// or imply this information in which case alpha must be specified.
            /// </summary>
            UNKNOWN = 0,

            /// <summary>
            /// Treat the alpha as premultipled.
            /// </summary>
            PREMULTIPLIED = 1,

            /// <summary>
            /// Opacity is in the 'A' component only.
            /// </summary>
            STRAIGHT = 2,

            /// <summary>
            /// Ignore any alpha channel information.
            /// </summary>
            IGNORE_ALPHA = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Description of a pixel format.
        /// </summary>
        public value struct D2D1_PIXEL_FORMAT
        {
            /// <summary>
            /// The format of the pixel. See <see cref="DXGINet::DXGI_FORMAT"/>
            /// for more informations.
            /// </summary>
            DXGINet::DXGI_FORMAT format;

            /// <summary>
            /// Qualifies how alpha is to be treated. See
            /// <see cref="Direct2DNet::D2D1_ALPHA_MODE"/> for more informations.
            /// </summary>
            Direct2DNet::D2D1_ALPHA_MODE alphaMode;

            D2D1_PIXEL_FORMAT(DXGINet::DXGI_FORMAT format, Direct2DNet::D2D1_ALPHA_MODE alphaMode)
                : format(format), alphaMode(alphaMode) {}

            static operator ::D2D1_PIXEL_FORMAT(Direct2DNet::D2D1_PIXEL_FORMAT %rhs)
            {
                ::D2D1_PIXEL_FORMAT value;
                value.format = (::DXGI_FORMAT)((int)rhs.format);
                value.alphaMode = (::D2D1_ALPHA_MODE)((int)rhs.alphaMode);

                return value;
            }

            static operator Direct2DNet::D2D1_PIXEL_FORMAT(::D2D1_PIXEL_FORMAT %rhs)
            {
                Direct2DNet::D2D1_PIXEL_FORMAT value;
                value.format = (DXGINet::DXGI_FORMAT)((int)rhs.format);
                value.alphaMode = (Direct2DNet::D2D1_ALPHA_MODE)((int)rhs.alphaMode);

                return value;
            }

        public:
            /// <summary>
            /// Gets the default pixel format, which is
            /// <see cref="DXGINet::DXGI_FORMAT::FORMAT_UNKNOWN"/> for
            /// <see cref="format"/> and
            /// <see cref="Direct2DNet::D2D1_ALPHA_MODE::UNKNOWN"/> for
            /// <see cref="alphaMode"/>
            /// </summary>
            static property Direct2DNet::D2D1_PIXEL_FORMAT Default
            {
                static Direct2DNet::D2D1_PIXEL_FORMAT get()
                {
                    return (Direct2DNet::D2D1_PIXEL_FORMAT)D2D1::PixelFormat();
                }
            }
        };

        /// <summary>
        /// Describes how a render target is remoted and whether it should be
        /// GDI-compatible. This enumeration allows a bitwise combination of its member
        /// values.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_RENDER_TARGET_USAGE
        {
            NONE = 0x00000000,

            /// <summary>
            /// Rendering will occur locally, if a terminal-services session is established, the
            /// bitmap updates will be sent to the terminal services client.
            /// </summary>
            FORCE_BITMAP_REMOTING = 0x00000001,

            /// <summary>
            /// The render target will allow a call to GetDC on the ID2D1GdiInteropRenderTarget
            /// interface. Rendering will also occur locally.
            /// </summary>
            GDI_COMPATIBLE = 0x00000002,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes the minimum DirectX support required for hardware rendering by a
        /// render target.
        /// </summary>
        public enum class D2D1_FEATURE_LEVEL
        {
            /// <summary>
            /// The caller does not require a particular underlying D3D device level.
            /// </summary>
            DEFAULT = 0,

            /// <summary>
            /// The D3D device level is DX9 compatible.
            /// </summary>
            FEATURE_LEVEL_9 = D3D_FEATURE_LEVEL_9_1,

            /// <summary>
            /// The D3D device level is DX10 compatible.
            /// </summary>
            FEATURE_LEVEL_10 = D3D_FEATURE_LEVEL_10_0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Contains rendering options (hardware or software), pixel format, DPI
        /// information, remoting options, and Direct3D support requirements for a render
        /// target.
        /// </summary>
        public value struct D2D1_RENDER_TARGET_PROPERTIES
        {
            /// <summary>
            /// Rendering mode of the render target.
            /// See <see cref="Direct2DNet::D2D1_RENDER_TARGET_TYPE"/> for more informations.
            /// </summary>
            Direct2DNet::D2D1_RENDER_TARGET_TYPE type;

            /// <summary>
            /// Pixel format of the render target.
            /// See <see cref="Direct2DNet::D2D1_PIXEL_FORMAT"/> for more informations.
            /// </summary>
            Direct2DNet::D2D1_PIXEL_FORMAT pixelFormat;

            /// <summary>
            /// DPI in x axis.
            /// </summary>
            float dpiX;

            /// <summary>
            /// DPI in y axis.
            /// </summary>
            float dpiY;

            /// <summary>
            /// Describes how a render target is remoted and whether it should be GDI-compatible.
            /// See <see cref="Direct2DNet::D2D1_RENDER_TARGET_USAGE"/> for more informations.
            /// </summary>
            Direct2DNet::D2D1_RENDER_TARGET_USAGE usage;

            /// <summary>
            /// Minimum DirectX support required.
            /// </summary>
            Direct2DNet::D2D1_FEATURE_LEVEL minLevel;

            D2D1_RENDER_TARGET_PROPERTIES(
                Direct2DNet::D2D1_RENDER_TARGET_TYPE type,
                Direct2DNet::D2D1_PIXEL_FORMAT pixelFormat,
                float dpiX,
                float dpiY,
                Direct2DNet::D2D1_RENDER_TARGET_USAGE usage,
                Direct2DNet::D2D1_FEATURE_LEVEL minLevel
            ) : type(type), pixelFormat(pixelFormat), dpiX(dpiX), dpiY(dpiY), usage(usage), minLevel(minLevel) {}

            static operator ::D2D1_RENDER_TARGET_PROPERTIES(Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %rhs)
            {
                ::D2D1_RENDER_TARGET_PROPERTIES value;
                value.type = (::D2D1_RENDER_TARGET_TYPE)((int)rhs.type);
                value.pixelFormat = (::D2D1_PIXEL_FORMAT)rhs.pixelFormat;
                value.dpiX = rhs.dpiX;
                value.dpiY = rhs.dpiY;
                value.usage = (::D2D1_RENDER_TARGET_USAGE)((int)rhs.usage);
                value.minLevel = (::D2D1_FEATURE_LEVEL)((int)rhs.minLevel);

                return value;
            }

            static operator Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES(::D2D1_RENDER_TARGET_PROPERTIES %rhs)
            {
                Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES value;
                value.type = (Direct2DNet::D2D1_RENDER_TARGET_TYPE)((int)rhs.type);
                value.pixelFormat = (Direct2DNet::D2D1_PIXEL_FORMAT)rhs.pixelFormat;
                value.dpiX = rhs.dpiX;
                value.dpiY = rhs.dpiY;
                value.usage = (Direct2DNet::D2D1_RENDER_TARGET_USAGE)((int)rhs.usage);
                value.minLevel = (Direct2DNet::D2D1_FEATURE_LEVEL)((int)rhs.minLevel);

                return value;
            }

            /// <summary>
            /// Gets the default render target property, which is
            /// <see cref="Direct2DNet::D2D1_RENDER_TARGET_TYPE::DEFAULT"/> for
            /// <see cref="type"/>, <see cref="Direct2DNet::D2D1_PIXEL_FORMAT::Default"/> for
            /// <see cref="pixelFormat"/>, <c>0</c> for
            /// <see cref="dpiX"/> and <see cref="dpiY"/>
            /// <see cref="Direct2DNet::D2D1_RENDER_TARGET_USAGE::NONE"/> for
            /// <see cref="usage"/>, and <see cref="Direct2DNet::D2D1_FEATURE_LEVEL::DEFAULT"/> for
            /// <see cref="minLevel"/>.
            /// </summary>
            static property Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES Default
            {
                static Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES get()
                {
                    return (Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES)D2D1::RenderTargetProperties();
                }
            }
        };

        /// <summary>
        /// Enum which describes the manner in which we render edges of non-text primitives.
        /// </summary>
        public enum class D2D1_ANTIALIAS_MODE
        {

            /// <summary>
            /// The edges of each primitive are antialiased sequentially.
            /// </summary>
            PER_PRIMITIVE = 0,

            /// <summary>
            /// Each pixel is rendered if its pixel center is contained by the geometry.
            /// </summary>
            ALIASED = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes the antialiasing mode used for drawing text.
        /// </summary>
        public enum class D2D1_TEXT_ANTIALIAS_MODE
        {

            /// <summary>
            /// Render text using the current system setting.
            /// </summary>
            DEFAULT = 0,

            /// <summary>
            /// Render text using ClearType.
            /// </summary>
            CLEARTYPE = 1,

            /// <summary>
            /// Render text using gray-scale.
            /// </summary>
            GRAYSCALE = 2,

            /// <summary>
            /// Render text aliased.
            /// </summary>
            ALIASED = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes how present should behave.
        /// </summary>
        public enum class D2D1_PRESENT_OPTIONS
        {
            NONE = 0x00000000,

            /// <summary>
            /// Keep the target contents intact through present.
            /// </summary>
            RETAIN_CONTENTS = 0x00000001,

            /// <summary>
            /// Do not wait for display refresh to commit changes to display.
            /// </summary>
            IMMEDIATELY = 0x00000002,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Contains the HWND, pixel size, and presentation options for an
        /// ID2D1HwndRenderTarget.
        /// </summary>
        public value struct D2D1_HWND_RENDER_TARGET_PROPERTIES
        {
            /// <summary>
            /// Handle to the window to render.
            /// </summary>
            System::IntPtr hwnd;

            /// <summary>
            /// Size of the render target in pixels.
            /// </summary>
            Direct2DNet::D2D1_SIZE_U pixelSize;

            /// <summary>
            /// Present option of the render target.
            /// See <see cref="Direct2DNet::D2D1_PRESENT_OPTIONS"/> for more informations.
            /// </summary>
            Direct2DNet::D2D1_PRESENT_OPTIONS presentOptions;

            D2D1_HWND_RENDER_TARGET_PROPERTIES(
                System::IntPtr hwnd,
                Direct2DNet::D2D1_SIZE_U pixelSize,
                Direct2DNet::D2D1_PRESENT_OPTIONS presentOptions
            ) : hwnd(hwnd), pixelSize(pixelSize), presentOptions(presentOptions) {}

            static operator ::D2D1_HWND_RENDER_TARGET_PROPERTIES(Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES %rhs)
            {
                ::D2D1_HWND_RENDER_TARGET_PROPERTIES value;
                value.hwnd = (HWND)rhs.hwnd.ToPointer();
                value.pixelSize = (::D2D1_SIZE_U)rhs.pixelSize;
                value.presentOptions = (::D2D1_PRESENT_OPTIONS)((int)rhs.presentOptions);

                return value;
            }

            static operator Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES(::D2D1_HWND_RENDER_TARGET_PROPERTIES %rhs)
            {
                Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES value;
                value.hwnd = System::IntPtr(rhs.hwnd);
                value.pixelSize = (Direct2DNet::D2D1_SIZE_U)rhs.pixelSize;
                value.presentOptions = (Direct2DNet::D2D1_PRESENT_OPTIONS)((int)rhs.presentOptions);

                return value;
            }

            /// <summary>
            /// Gets the default hwnd render target property, which is
            /// 0 width and 0 height for
            /// <see cref="pixelSize"/> and <see cref="Direct2DNet::D2D1_PRESENT_OPTIONS::NONE"/> for
            /// <see cref="presentOptions"/>.
            /// </summary>
            /// <param name="hwnd">Handle to the window to draw.</param>
            static Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES Default(System::IntPtr hwnd)
            {
                HWND hWnd = (HWND)hwnd.ToPointer();
                return (Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES)D2D1::HwndRenderTargetProperties(hWnd);
            }
        };

        /// <summary>
        /// Specifies additional features supportable by a compatible render target when it
        /// is created. This enumeration allows a bitwise combination of its member values.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS
        {
            NONE = 0x00000000,

            /// <summary>
            /// The compatible render target will allow a call to GetDC on the
            /// ID2D1GdiInteropRenderTarget interface. This can be specified even if the parent
            /// render target is not GDI compatible.
            /// </summary>
            GDI_COMPATIBLE = 0x00000001,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes whether a window is occluded.
        /// </summary>
        public enum class D2D1_WINDOW_STATE
        {
            /// <summary>The window is not occluded.</summary>
            NONE = 0x0000000,

            /// <summary>The window is occluded.</summary>
            OCCLUDED = 0x0000001,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Enum which describes the drawing of the ends of a line.
        /// </summary>
        public enum class D2D1_CAP_STYLE
        {
            /// <summary>
            /// Flat line cap.
            /// </summary>
            FLAT = 0,

            /// <summary>
            /// Square line cap.
            /// </summary>
            SQUARE = 1,

            /// <summary>
            /// Round line cap.
            /// </summary>
            ROUND = 2,

            /// <summary>
            /// Triangle line cap.
            /// </summary>
            TRIANGLE = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Enum which describes the drawing of the corners on the line.
        /// </summary>
        public enum class D2D1_LINE_JOIN
        {
            /// <summary>
            /// Miter join.
            /// </summary>
            MITER = 0,

            /// <summary>
            /// Bevel join.
            /// </summary>
            BEVEL = 1,

            /// <summary>
            /// Round join.
            /// </summary>
            ROUND = 2,

            /// <summary>
            /// Miter/Bevel join.
            /// </summary>
            MITER_OR_BEVEL = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes the sequence of dashes and gaps in a stroke.
        /// </summary>
        public enum class D2D1_DASH_STYLE
        {
            /// <summary>A solid line with no breaks.</summary>
            SOLID = 0,

            /// <summary>A dash followed by a gap of equal length.
            /// The dash and the gap are each twice as long as the stroke thickness.
            /// The equivalent dash array for DASH is{ 2, 2 }.</summary>
            DASH = 1,

            /// <summary>A dot followed by a longer gap.
            /// The equivalent dash array for DOT is{ 0, 2 }.</summary>
            DOT = 2,

            /// <summary>A dash, followed by a gap, followed by a dot, followed by
            /// another gap.The equivalent dash array for DASH_DOT is
            /// { 2, 2, 0, 2 }.</summary>
            DASH_DOT = 3,

            /// <summary>A dash, followed by a gap, followed by a dot, followed by another
            /// gap, followed by another dot, followed by another gap.
            /// The equivalent dash array for DASH_DOT_DOT is
            /// { 2, 2, 0, 2, 0, 2 }.</summary>
            DASH_DOT_DOT = 4,

            /// <summary>The dash pattern is specified by an array of
            /// floating-point values.</summary>
            CUSTOM = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Properties, aside from the width, that allow geometric penning to be specified.
        /// </summary>
        public value struct D2D1_STROKE_STYLE_PROPERTIES
        {
            /// <summary>
            /// Cap style applied to the start of stroke.
            /// </summary>
            Direct2DNet::D2D1_CAP_STYLE startCap;

            /// <summary>
            /// Cap style applied to the end of stroke.
            /// </summary>
            Direct2DNet::D2D1_CAP_STYLE endCap;

            /// <summary>
            /// Cap style applied to the each end of all dashes in stroke.
            /// </summary>
            Direct2DNet::D2D1_CAP_STYLE dashCap;

            /// <summary>
            /// Describes how segments are joined.
            /// See <see cref="Direct2DNet::D2D1_LINE_JOIN"/> for more informations.
            /// </summary>
            Direct2DNet::D2D1_LINE_JOIN lineJoin;

            /// <summary>
            /// The limit of the thickness of the join on a mitered corner.
            /// </summary>
            float miterLimit;

            /// <summary>
            /// The dash style of the stroke.
            /// See <see cref="Direct2DNet::D2D1_DASH_STYLE"/> for more informations.
            /// </summary>
            Direct2DNet::D2D1_DASH_STYLE dashStyle;

            /// <summary>
            /// An offset in the dash sequence in the unit of stroke width.
            /// Positive offset shifts the pattern toward the start of the stroke.
            /// Negative offset shifts the pattern toward the end of the stroke.
            /// </summary>
            float dashOffset;

            D2D1_STROKE_STYLE_PROPERTIES(
                Direct2DNet::D2D1_CAP_STYLE startCap,
                Direct2DNet::D2D1_CAP_STYLE endCap,
                Direct2DNet::D2D1_CAP_STYLE dashCap,
                Direct2DNet::D2D1_LINE_JOIN lineJoin,
                float miterLimit,
                Direct2DNet::D2D1_DASH_STYLE dashStyle,
                float dashOffset
            ) : startCap(startCap), endCap(endCap), dashCap(dashCap), lineJoin(lineJoin),
                miterLimit(miterLimit), dashStyle(dashStyle), dashOffset(dashOffset)
            {
            }

            static operator ::D2D1_STROKE_STYLE_PROPERTIES(Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES %rhs)
            {
                ::D2D1_STROKE_STYLE_PROPERTIES value;
                value.startCap = (::D2D1_CAP_STYLE)((int)rhs.startCap);
                value.endCap = (::D2D1_CAP_STYLE)((int)rhs.endCap);
                value.dashCap = (::D2D1_CAP_STYLE)((int)rhs.dashCap);
                value.lineJoin = (::D2D1_LINE_JOIN)((int)rhs.lineJoin);
                value.miterLimit = rhs.miterLimit;
                value.dashStyle = (::D2D1_DASH_STYLE)((int)rhs.dashStyle);
                value.dashOffset = rhs.dashOffset;

                return value;
            }

            static operator Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES(::D2D1_STROKE_STYLE_PROPERTIES %rhs)
            {
                Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES value;
                value.startCap = (Direct2DNet::D2D1_CAP_STYLE)((int)rhs.startCap);
                value.endCap = (Direct2DNet::D2D1_CAP_STYLE)((int)rhs.endCap);
                value.dashCap = (Direct2DNet::D2D1_CAP_STYLE)((int)rhs.dashCap);
                value.lineJoin = (Direct2DNet::D2D1_LINE_JOIN)((int)rhs.lineJoin);
                value.miterLimit = rhs.miterLimit;
                value.dashStyle = (Direct2DNet::D2D1_DASH_STYLE)((int)rhs.dashStyle);
                value.dashOffset = rhs.dashOffset;

                return value;
            }

            static property Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES Default
            {
                static Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES get()
                {
                    return static_cast<Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES>(
                        D2D1::StrokeStyleProperties()
                        );
                }
            }
        };

        /// <summary>
        /// Describes how one geometry object is spatially related to another geometry
        /// object.
        /// </summary>
        public enum class D2D1_GEOMETRY_RELATION
        {
            /// <summary>
            /// The relation between the geometries couldn't be determined. This value is never
            /// returned by any D2D method.
            /// </summary>
            UNKNOWN = 0,

            /// <summary>
            /// The two geometries do not intersect at all.
            /// </summary>
            DISJOINT = 1,

            /// <summary>
            /// The passed in geometry is entirely contained by the object.
            /// </summary>
            IS_CONTAINED = 2,

            /// <summary>
            /// The object entirely contains the passed in geometry.
            /// </summary>
            CONTAINS = 3,

            /// <summary>
            /// The two geometries overlap but neither completely contains the other.
            /// </summary>
            OVERLAP = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies how simple the output of a simplified geometry sink should be.
        /// </summary>
        public enum class D2D1_GEOMETRY_SIMPLIFICATION_OPTION
        {
            /// <summary>
            /// The output can contain cubic Bezier curves and line segments.
            /// </summary>
            CUBICS_AND_LINES = 0,

            /// <summary>
            /// The output is flattened so that it contains only line segments.
            /// </summary>
            LINES = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies how the intersecting areas of geometries or figures are combined to
        /// form the area of the composite geometry.
        /// </summary>
        public enum class D2D1_FILL_MODE
        {
            /// <summary>
            /// Determines whether a point is in the fill region by drawing a ray from that point to
            /// infinity in any direction, and then counting the number of path segments within the
            /// given shape that the ray crosses. If this number is odd, the point is in the fill region;
            /// if even, the point is outside the fill region.
            /// </summary>
            MODE_ALTERNATE = 0,

            /// <summary>
            /// Determines whether a point is in the fill region of the path by drawing a ray from
            /// that point to infinity in any direction, and then examining the places where a segment
            /// of the shape crosses the ray. Starting with a count of zero, add one each time a segment
            /// crosses the ray from left to right and subtract one each time a path segment crosses
            /// the ray from right to left, as long as left and right are seen from the perspective of
            /// the ray. After counting the crossings, if the result is zero, then the point is outside
            /// the path. Otherwise, it is inside the path.
            /// </summary>
            MODE_WINDING = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// This enumeration describes the type of combine operation to be performed.
        /// </summary>
        public enum class D2D1_COMBINE_MODE
        {
            /// <summary>
            /// Produce a geometry representing the set of points contained in either the first
            /// or the second geometry.
            /// </summary>
            MODE_UNION = 0,

            /// <summary>
            /// Produce a geometry representing the set of points common to the first and the
            /// second geometries.
            /// </summary>
            MODE_INTERSECT = 1,

            /// <summary>
            /// Produce a geometry representing the set of points contained in the first
            /// geometry or the second geometry, but not both.
            /// </summary>
            MODE_XOR = 2,

            /// <summary>
            /// Produce a geometry representing the set of points contained in the first
            /// geometry but not the second geometry.
            /// </summary>
            MODE_EXCLUDE = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Indicates whether the given segment should be stroked, or, if the join between
        /// this segment and the previous one should be smooth.
        /// This enumeration allows a bitwise combination of its member values.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_PATH_SEGMENT
        {
            /// <summary>
            /// The segment is joined as specified by the <see cref="Direct2DNet::ID2D1StrokeStyle"/>
            /// class, and it is stroked.
            /// </summary>
            NONE = 0x00000000,

            /// <summary>
            /// The segment is not stroked.
            /// </summary>
            FORCE_UNSTROKED = 0x00000001,

            /// <summary>
            /// The segment is always joined with the one preceding it using a round line join,
            /// regardless of which <see cref="Direct2DNet::D2D1_LINE_JOIN"/> enumeration is specified by
            /// the <see cref="Direct2DNet::ID2D1StrokeStyle"/> class. If this segment is the first
            /// segment and the figure is closed, a round line join is used to connect the closing segment
            /// with the first segment. If the figure is not closed, this setting has no effect on the first
            /// segment of the figure. If <see cref="Direct2DNet::ID2D1PathGeometry::SetSegmentFlags"/>
            /// is called just before <see cref="Direct2DNet::ID2D1PathGeometry::EndFigure"/>, the join
            /// between the closing segment and the last explicitly specified segment is affected.
            /// </summary>
            FORCE_ROUND_LINE_JOIN = 0x00000002,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Indicates whether the given figure is filled or hollow.
        /// </summary>
        public enum class D2D1_FIGURE_BEGIN
        {
            /// <summary>
            /// Indicates the figure will be filled by the FillGeometry method.
            /// </summary>
            FILLED = 0,

            /// <summary>
            /// Indicates the figure will not be filled by the FillGeometry method and will only consist
            /// of an outline. Moreover, the bounds of a hollow figure are zero.
            /// HOLLOW should be used for stroking, or for other geometry operations.
            /// </summary>
            HOLLOW = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Indicates whether the figure is open or closed on its end point.
        /// </summary>
        public enum class D2D1_FIGURE_END
        {
            /// <summary>
            /// The figure is open.
            /// </summary>
            OPEN = 0,

            /// <summary>
            /// The figure is closed.
            /// </summary>
            CLOSED = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Contains the position and color of a gradient stop.
        /// </summary>
        public value struct D2D1_GRADIENT_STOP
        {
            float position;
            Direct2DNet::D2D1_COLOR_F color;

            D2D1_GRADIENT_STOP(float position, Direct2DNet::D2D1_COLOR_F color)
                : position(position), color(color) {}

            static operator ::D2D1_GRADIENT_STOP(Direct2DNet::D2D1_GRADIENT_STOP %rhs)
            {
                ::D2D1_GRADIENT_STOP value;
                value.position = rhs.position;
                value.color = static_cast<::D2D1_COLOR_F>(rhs.color);

                return value;
            }

            static operator Direct2DNet::D2D1_GRADIENT_STOP(::D2D1_GRADIENT_STOP %rhs)
            {
                Direct2DNet::D2D1_GRADIENT_STOP value;
                value.position = rhs.position;
                value.color = static_cast<Direct2DNet::D2D1_COLOR_F>(rhs.color);

                return value;
            }
        };

        /// <summary>
        /// Contains the starting point and endpoint of the gradient axis for an
        /// ID2D1LinearGradientBrush.
        /// </summary>
        public value struct D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
        {
            Direct2DNet::D2D1_POINT_2F startPoint;
            Direct2DNet::D2D1_POINT_2F endPoint;

            D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES(
                Direct2DNet::D2D1_POINT_2F startPoint,
                Direct2DNet::D2D1_POINT_2F endPoint
            ) : startPoint(startPoint), endPoint(endPoint) {}

            static operator ::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES(Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES %rhs)
            {
                ::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES value;
                value.startPoint = static_cast<::D2D1_POINT_2F>(rhs.startPoint);
                value.endPoint = static_cast<::D2D1_POINT_2F>(rhs.endPoint);

                return value;
            }

            static operator Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES(::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES %rhs)
            {
                Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES value;
                value.startPoint = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.startPoint);
                value.endPoint = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.endPoint);

                return value;
            }
        };

        /// <summary>
        /// Contains the gradient origin offset and the size and position of the gradient
        /// ellipse for an ID2D1RadialGradientBrush.
        /// </summary>
        public value struct D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
        {
            /// <summary>
            /// In the brush's coordinate space, the center of the gradient ellipse.
            /// </summary>
            Direct2DNet::D2D1_POINT_2F center;

            /// <summary>
            /// In the brush's coordinate space, the offset of the gradient origin relative to
            /// the gradient ellipse's center.
            /// </summary>
            Direct2DNet::D2D1_POINT_2F gradientOriginOffset;

            /// <summary>
            /// In the brush's coordinate space, the x-radius of the gradient ellipse.
            /// </summary>
            float radiusX;

            /// <summary>
            /// In the brush's coordinate space, the y-radius of the gradient ellipse.
            /// </summary>
            float radiusY;

            D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES(
                Direct2DNet::D2D1_POINT_2F center,
                Direct2DNet::D2D1_POINT_2F gradientOriginOffset,
                float radiusX,
                float radiusY
            ) : center(center), gradientOriginOffset(gradientOriginOffset), radiusX(radiusX), radiusY(radiusY) {}

            static operator ::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES(Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES %rhs)
            {
                ::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES value;
                value.center = static_cast<::D2D1_POINT_2F>(rhs.center);
                value.gradientOriginOffset = static_cast<::D2D1_POINT_2F>(rhs.gradientOriginOffset);
                value.radiusX = rhs.radiusX;
                value.radiusY = rhs.radiusY;

                return value;
            }

            static operator Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES(::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES %rhs)
            {
                Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES value;
                value.center = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.center);
                value.gradientOriginOffset = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.gradientOriginOffset);
                value.radiusX = rhs.radiusX;
                value.radiusY = rhs.radiusY;

                return value;
            }
        };

        /// <summary>
        /// This determines what gamma is used for interpolation/blending.
        /// </summary>
        public enum class D2D1_GAMMA
        {

            /// <summary>
            /// Colors are manipulated in 2.2 gamma color space.
            /// </summary>
            GAMMA_2_2 = 0,

            /// <summary>
            /// Colors are manipulated in 1.0 gamma color space.
            /// </summary>
            GAMMA_1_0 = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Enum which describes how to sample from a source outside its base tile.
        /// </summary>
        public enum class D2D1_EXTEND_MODE
        {

            /// <summary>
            /// Extend the edges of the source out by clamping sample points outside the source
            /// to the edges.
            /// </summary>
            CLAMP = 0,

            /// <summary>
            /// The base tile is drawn untransformed and the remainder are filled by repeating
            /// the base tile.
            /// </summary>
            WRAP = 1,

            /// <summary>
            /// The same as wrap, but alternate tiles are flipped  The base tile is drawn
            /// untransformed.
            /// </summary>
            MIRROR = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes the pixel format and dpi of a bitmap.
        /// </summary>
        public value struct D2D1_BITMAP_PROPERTIES
        {
            Direct2DNet::D2D1_PIXEL_FORMAT pixelFormat;
            float dpiX;
            float dpiY;

            D2D1_BITMAP_PROPERTIES(
                Direct2DNet::D2D1_PIXEL_FORMAT pixelFormat,
                float dpiX,
                float dpiY
            ) : pixelFormat(pixelFormat), dpiX(dpiX), dpiY(dpiY) {}

            static operator ::D2D1_BITMAP_PROPERTIES(Direct2DNet::D2D1_BITMAP_PROPERTIES %rhs)
            {
                ::D2D1_BITMAP_PROPERTIES value;
                value.pixelFormat = static_cast<::D2D1_PIXEL_FORMAT>(rhs.pixelFormat);
                value.dpiX = rhs.dpiX;
                value.dpiY = rhs.dpiY;

                return value;
            }

            static operator Direct2DNet::D2D1_BITMAP_PROPERTIES(::D2D1_BITMAP_PROPERTIES %rhs)
            {
                Direct2DNet::D2D1_BITMAP_PROPERTIES value;
                value.pixelFormat = static_cast<Direct2DNet::D2D1_PIXEL_FORMAT>(rhs.pixelFormat);
                value.dpiX = rhs.dpiX;
                value.dpiY = rhs.dpiY;

                return value;
            }

            static property Direct2DNet::D2D1_BITMAP_PROPERTIES Default
            {
                static Direct2DNet::D2D1_BITMAP_PROPERTIES get()
                {
                    return static_cast<Direct2DNet::D2D1_BITMAP_PROPERTIES>(D2D1::BitmapProperties());
                }
            }
        };

        /// <summary>
        /// Specifies the algorithm that is used when images are scaled or rotated. Note
        /// Starting in Windows 8, more interpolations modes are available. See
        /// D2D1_INTERPOLATION_MODE for more info.
        /// </summary>
        public enum class D2D1_BITMAP_INTERPOLATION_MODE
        {

            /// <summary>
            /// Nearest Neighbor filtering. Also known as nearest pixel or nearest point
            /// sampling.
            /// </summary>
            NEAREST_NEIGHBOR = D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR,

            /// <summary>
            /// Linear filtering.
            /// </summary>
            LINEAR = D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies what the contents are of an opacity mask.
        /// </summary>
        public enum class D2D1_OPACITY_MASK_CONTENT
        {
            /// <summary>
            /// The mask contains geometries or bitmaps.
            /// </summary>
            GRAPHICS = 0,

            /// <summary>
            /// The mask contains text rendered using one of the natural text modes.
            /// </summary>
            TEXT_NATURAL = 1,

            /// <summary>
            /// The mask contains text rendered using one of the GDI compatible text modes.
            /// </summary>
            TEXT_GDI_COMPATIBLE = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Modifications made to the draw text call that influence how the text is rendered.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_DRAW_TEXT_OPTIONS
        {
            /// <summary>
            /// Do not snap the baseline of the text vertically.
            /// </summary>
            NO_SNAP = 0x00000001,

            /// <summary>
            /// Clip the text to the content bounds.
            /// </summary>
            CLIP = 0x00000002,

            /// <summary>
            /// Render color versions of glyphs if defined by the font.
            /// </summary>
            ENABLE_COLOR_FONT = 0x00000004,

            /// <summary>
            /// Bitmap origins of color glyph bitmaps are not snapped.
            /// </summary>
            DISABLE_COLOR_BITMAP_SNAPPING = 0x00000008,

            NONE = 0x00000000,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specified options that can be applied when a layer resource is applied to create
        /// a layer.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_LAYER_OPTIONS
        {
            NONE = 0x00000000,

            /// <summary>
            /// The layer will render correctly for ClearType text. If the render target was set
            /// to ClearType previously, the layer will continue to render ClearType. If the
            /// render target was set to ClearType and this option is not specified, the render
            /// target will be set to render gray-scale until the layer is popped. The caller
            /// can override this default by calling SetTextAntialiasMode while within the
            /// layer. This flag is slightly slower than the default.
            /// </summary>
            INITIALIZE_FOR_CLEARTYPE = 0x00000001,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        ref class ID2D1Geometry;
        ref class ID2D1Brush;

        /// <summary>
        /// Contains the content bounds, mask information, opacity settings, and other
        /// options for a layer resource.
        /// </summary>
        public value struct D2D1_LAYER_PARAMETERS
        {
            /// <summary>
            /// The rectangular clip that will be applied to the layer. The clip is affected by
            /// the world transform. Content outside of the content bounds will not render.
            /// </summary>
            Direct2DNet::D2D1_RECT_F contentBounds;

            /// <summary>
            /// A general mask that can be optionally applied to the content. Content not inside
            /// the fill of the mask will not be rendered.
            /// </summary>
            Direct2DNet::ID2D1Geometry ^geometricMask;

            /// <summary>
            /// Specifies whether the mask should be aliased or antialiased.
            /// </summary>
            Direct2DNet::D2D1_ANTIALIAS_MODE maskAntialiasMode;

            /// <summary>
            /// An additional transform that may be applied to the mask in addition to the
            /// current world transform.
            /// </summary>
            Direct2DNet::D2D1_MATRIX_3X2_F maskTransform;

            /// <summary>
            /// The opacity with which all of the content in the layer will be blended back to
            /// the target when the layer is popped.
            /// </summary>
            float opacity;

            /// <summary>
            /// An additional brush that can be applied to the layer. Only the opacity channel
            /// is sampled from this brush and multiplied both with the layer content and the
            /// over-all layer opacity.
            /// </summary>
            Direct2DNet::ID2D1Brush ^opacityBrush;

            /// <summary>
            /// Specifies if ClearType will be rendered into the layer.
            /// </summary>
            Direct2DNet::D2D1_LAYER_OPTIONS layerOptions;

            D2D1_LAYER_PARAMETERS(
                Direct2DNet::D2D1_RECT_F contentBounds,
                Direct2DNet::ID2D1Geometry ^geometricMask,
                Direct2DNet::D2D1_ANTIALIAS_MODE maskAntialiasMode,
                Direct2DNet::D2D1_MATRIX_3X2_F maskTransform,
                float opacity,
                Direct2DNet::ID2D1Brush ^opacityBrush,
                Direct2DNet::D2D1_LAYER_OPTIONS layerOptions
            ) : contentBounds(contentBounds), geometricMask(geometricMask),
                maskAntialiasMode(maskAntialiasMode), maskTransform(maskTransform), opacity(opacity),
                opacityBrush(opacityBrush), layerOptions(layerOptions) {}

            static operator ::D2D1_LAYER_PARAMETERS(Direct2DNet::D2D1_LAYER_PARAMETERS %rhs);

            static property Direct2DNet::D2D1_LAYER_PARAMETERS Default
            {
                static Direct2DNet::D2D1_LAYER_PARAMETERS get()
                {
                    return Direct2DNet::D2D1_LAYER_PARAMETERS(
                        Direct2DNet::D2D1_RECT_F::InfiniteRect,
                        nullptr,
                        Direct2DNet::D2D1_ANTIALIAS_MODE::PER_PRIMITIVE,
                        Direct2DNet::D2D1_MATRIX_3X2_F::Identity,
                        1.0f,
                        nullptr,
                        Direct2DNet::D2D1_LAYER_OPTIONS::NONE
                    );
                }
            }
        };

        /// <summary>
        /// Allows the drawing state to be atomically created. This also specifies the
        /// drawing state that is saved into an IDrawingStateBlock object.
        /// </summary>
        public value struct D2D1_DRAWING_STATE_DESCRIPTION
        {
            Direct2DNet::D2D1_ANTIALIAS_MODE antialiasMode;
            Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode;
            D2D1_TAG tag1;
            D2D1_TAG tag2;
            Direct2DNet::D2D1_MATRIX_3X2_F transform;

            D2D1_DRAWING_STATE_DESCRIPTION(
                Direct2DNet::D2D1_ANTIALIAS_MODE antialiasMode,
                Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode,
                D2D1_TAG tag1,
                D2D1_TAG tag2,
                Direct2DNet::D2D1_MATRIX_3X2_F transform
            ) : antialiasMode(antialiasMode), textAntialiasMode(textAntialiasMode), tag1(tag1),
                tag2(tag2), transform(transform) {}

            static operator ::D2D1_DRAWING_STATE_DESCRIPTION(Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION %rhs)
            {
                ::D2D1_DRAWING_STATE_DESCRIPTION value;
                value.antialiasMode = (::D2D1_ANTIALIAS_MODE)((int)rhs.antialiasMode);
                value.textAntialiasMode = (::D2D1_TEXT_ANTIALIAS_MODE)((int)rhs.textAntialiasMode);
                value.tag1 = rhs.tag1;
                value.tag2 = rhs.tag2;
                value.transform = static_cast<::D2D1_MATRIX_3X2_F>(rhs.transform);

                return value;
            }

            static operator Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION(::D2D1_DRAWING_STATE_DESCRIPTION %rhs)
            {
                Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION value;
                value.antialiasMode = (Direct2DNet::D2D1_ANTIALIAS_MODE)((int)rhs.antialiasMode);
                value.textAntialiasMode = (Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE)((int)rhs.textAntialiasMode);
                value.tag1 = rhs.tag1;
                value.tag2 = rhs.tag2;
                value.transform = static_cast<Direct2DNet::D2D1_MATRIX_3X2_F>(rhs.transform);

                return value;
            }

            static property Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION Default
            {
                static Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION get()
                {
                    return static_cast<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION>(D2D1::DrawingStateDescription());
                }
            }
        };

        /// <summary>
        /// Defines how the world transform, dots per inch (dpi), and stroke width affect
        /// the shape of the pen used to stroke a primitive.
        /// </summary>
        public enum class D2D1_STROKE_TRANSFORM_TYPE
        {

            /// <summary>
            /// The stroke respects the world transform, the DPI, and the stroke width.
            /// </summary>
            NORMAL = 0,

            /// <summary>
            /// The stroke does not respect the world transform, but it does respect the DPI and
            /// the stroke width.
            /// </summary>
            FIXED = 1,

            /// <summary>
            /// The stroke is forced to one pixel wide.
            /// </summary>
            HAIRLINE = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// This defines how geometries should be drawn and widened.
        /// </summary>
        /// <seealso cref="Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES"/>
        public value struct D2D1_STROKE_STYLE_PROPERTIES1
        {
            Direct2DNet::D2D1_CAP_STYLE startCap;
            Direct2DNet::D2D1_CAP_STYLE endCap;
            Direct2DNet::D2D1_CAP_STYLE dashCap;
            Direct2DNet::D2D1_LINE_JOIN lineJoin;
            float miterLimit;
            Direct2DNet::D2D1_DASH_STYLE dashStyle;
            float dashOffset;

            /// <summary>
            /// How the nib of the stroke is influenced by the context properties.
            /// </summary>
            Direct2DNet::D2D1_STROKE_TRANSFORM_TYPE transformType;

        public:
            D2D1_STROKE_STYLE_PROPERTIES1(
                Direct2DNet::D2D1_CAP_STYLE startCap,
                Direct2DNet::D2D1_CAP_STYLE endCap,
                Direct2DNet::D2D1_CAP_STYLE dashCap,
                Direct2DNet::D2D1_LINE_JOIN lineJoin,
                float miterLimit,
                Direct2DNet::D2D1_DASH_STYLE dashStyle,
                float dashOffset,
                Direct2DNet::D2D1_STROKE_TRANSFORM_TYPE transformType
            ) : startCap(startCap), endCap(endCap), dashCap(dashCap), lineJoin(lineJoin),
                miterLimit(miterLimit), dashStyle(dashStyle), dashOffset(dashOffset),
                transformType(transformType) {}

            static operator ::D2D1_STROKE_STYLE_PROPERTIES1(Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 %rhs)
            {
                ::D2D1_STROKE_STYLE_PROPERTIES1 value;
                value.startCap = (::D2D1_CAP_STYLE)((int)rhs.startCap);
                value.endCap = (::D2D1_CAP_STYLE)((int)rhs.endCap);
                value.dashCap = (::D2D1_CAP_STYLE)((int)rhs.dashCap);
                value.lineJoin = (::D2D1_LINE_JOIN)((int)rhs.lineJoin);
                value.miterLimit = rhs.miterLimit;
                value.dashStyle = (::D2D1_DASH_STYLE)((int)rhs.dashStyle);
                value.dashOffset = rhs.dashOffset;
                value.transformType = (::D2D1_STROKE_TRANSFORM_TYPE)((int)rhs.transformType);

                return value;
            }

            static operator Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1(::D2D1_STROKE_STYLE_PROPERTIES1 %rhs)
            {
                Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 value;
                value.startCap = (Direct2DNet::D2D1_CAP_STYLE)((int)rhs.startCap);
                value.endCap = (Direct2DNet::D2D1_CAP_STYLE)((int)rhs.endCap);
                value.dashCap = (Direct2DNet::D2D1_CAP_STYLE)((int)rhs.dashCap);
                value.lineJoin = (Direct2DNet::D2D1_LINE_JOIN)((int)rhs.lineJoin);
                value.miterLimit = rhs.miterLimit;
                value.dashStyle = (Direct2DNet::D2D1_DASH_STYLE)((int)rhs.dashStyle);
                value.dashOffset = rhs.dashOffset;
                value.transformType = (Direct2DNet::D2D1_STROKE_TRANSFORM_TYPE)((int)rhs.transformType);

                return value;
            }

            static property Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 Default
            {
                Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 get()
                {
                    return static_cast<Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1>(D2D1::StrokeStyleProperties1());
                }
            }
        };

        /// <summary>
        /// A blend mode that applies to all primitives drawn on the context.
        /// </summary>
        public enum class D2D1_PRIMITIVE_BLEND
        {
            SOURCE_OVER = 0,
            COPY = 1,
            MIN = 2,
            ADD = 3,
            MAX = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// This specifies what units should be accepted by the D2D API.
        /// </summary>
        public enum class D2D1_UNIT_MODE
        {
            DIPS = 0,
            PIXELS = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// This describes the drawing state.
        /// </summary>
        public value struct D2D1_DRAWING_STATE_DESCRIPTION1
        {
            Direct2DNet::D2D1_ANTIALIAS_MODE antialiasMode;
            Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode;
            D2D1_TAG tag1;
            D2D1_TAG tag2;
            Direct2DNet::D2D1_MATRIX_3X2_F transform;
            Direct2DNet::D2D1_PRIMITIVE_BLEND primitiveBlend;
            Direct2DNet::D2D1_UNIT_MODE unitMode;

        };

        /// <summary>
        /// This specifies options that apply to the device context for its lifetime.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_DEVICE_CONTEXT_OPTIONS
        {
            /// <summary>
            /// The device context is created with default options.
            /// </summary>
            NONE = 0,

            /// <summary>
            /// Distribute rendering work across multiple threads.
            /// </summary>
            ENABLE_MULTITHREADED_OPTIMIZATIONS = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Defines a color space.
        /// </summary>
        public enum class D2D1_COLOR_SPACE
        {
            /// <summary>
            /// The color space is described by accompanying data, such as a color profile.
            /// </summary>
            CUSTOM = 0,

            /// <summary>
            /// The sRGB color space.
            /// </summary>
            SRGB = 1,

            /// <summary>
            /// The scRGB color space.
            /// </summary>
            SCRGB = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies how the bitmap can be used.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_BITMAP_OPTIONS
        {
            /// <summary>
            /// The bitmap is created with default properties.
            /// </summary>
            NONE = 0x00000000,

            /// <summary>
            /// The bitmap can be specified as a target in ID2D1DeviceContext::SetTarget
            /// </summary>
            TARGET = 0x00000001,

            /// <summary>
            /// The bitmap cannot be used as an input to DrawBitmap, DrawImage, in a bitmap
            /// brush or as an input to an effect.
            /// </summary>
            CANNOT_DRAW = 0x00000002,

            /// <summary>
            /// The bitmap can be read from the CPU.
            /// </summary>
            CPU_READ = 0x00000004,

            /// <summary>
            /// The bitmap works with the ID2D1GdiInteropRenderTarget::GetDC API.
            /// </summary>
            GDI_COMPATIBLE = 0x00000008,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        ref class ID2D1ColorContext;

        /// <summary>
        /// Extended bitmap properties.
        /// </summary>
        public value struct D2D1_BITMAP_PROPERTIES1
        {
            Direct2DNet::D2D1_PIXEL_FORMAT pixelFormat;
            float dpiX;
            float dpiY;

            /// <summary>
            /// Specifies how the bitmap can be used.
            /// </summary>
            Direct2DNet::D2D1_BITMAP_OPTIONS bitmapOptions;

            /// <summary>
            /// The optionally specified color context information.
            /// </summary>
            Direct2DNet::ID2D1ColorContext ^colorContext;

            D2D1_BITMAP_PROPERTIES1(
                Direct2DNet::D2D1_PIXEL_FORMAT pixelFormat,
                float dpiX,
                float dpiY,
                Direct2DNet::D2D1_BITMAP_OPTIONS bitmapOptions,
                [InteropServices::OptionalAttribute] Direct2DNet::ID2D1ColorContext ^colorContext
            ) : pixelFormat(pixelFormat), dpiX(dpiX), dpiY(dpiY), bitmapOptions(bitmapOptions),
                colorContext(colorContext)
            {

            }

            static operator ::D2D1_BITMAP_PROPERTIES1(Direct2DNet::D2D1_BITMAP_PROPERTIES1 %rhs);

            static property Direct2DNet::D2D1_BITMAP_PROPERTIES1 Default
            {
                static Direct2DNet::D2D1_BITMAP_PROPERTIES1 get()
                {
                    return Direct2DNet::D2D1_BITMAP_PROPERTIES1(
                        Direct2DNet::D2D1_PIXEL_FORMAT::Default,
                        96.0f,
                        96.0f,
                        Direct2DNet::D2D1_BITMAP_OPTIONS::NONE,
                        nullptr
                    );
                }
            }
        };

        /// <summary>
        /// This describes how the individual mapping operation should be performed.
        /// </summary>
        [System::FlagsAttribute]
        public enum class D2D1_MAP_OPTIONS
        {
            /// <summary>
            /// The mapped pointer has undefined behavior.
            /// </summary>
            NONE = 0,

            /// <summary>
            /// The mapped pointer can be read from.
            /// </summary>
            READ = 1,

            /// <summary>
            /// The mapped pointer can be written to.
            /// </summary>
            WRITE = 2,

            /// <summary>
            /// The previous contents of the bitmap are discarded when it is mapped.
            /// </summary>
            DISCARD = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes mapped memory from the ID2D1Bitmap1::Map API.
        /// </summary>
        public value struct D2D1_MAPPED_RECT
        {
            unsigned int pitch;
            unsigned char *bits;

            static operator Direct2DNet::D2D1_MAPPED_RECT(::D2D1_MAPPED_RECT %rhs)
            {
                Direct2DNet::D2D1_MAPPED_RECT value;
                value.pitch = rhs.pitch;
                value.bits = rhs.bits;

                return value;
            }
        };

        /// <summary>
        /// This specifies the precision that should be used in buffers allocated by D2D.
        /// </summary>
        public enum class D2D1_BUFFER_PRECISION
        {
            /// <summary>
            /// The buffer precision is not specified.
            /// </summary>
            UNKNOWN = 0,

            /// <summary>
            /// Use 8-bit normalized integer per channel.
            /// </summary>
            PRECISION_8BPC_UNORM = 1,

            /// <summary>
            /// Use 8-bit normalized integer standard RGB data per channel.
            /// </summary>
            PRECISION_8BPC_UNORM_SRGB = 2,

            /// <summary>
            /// Use 16-bit normalized integer per channel.
            /// </summary>
            PRECISION_16BPC_UNORM = 3,

            /// <summary>
            /// Use 16-bit floats per channel.
            /// </summary>
            PRECISION_16BPC_FLOAT = 4,

            /// <summary>
            /// Use 32-bit floats per channel.
            /// </summary>
            PRECISION_32BPC_FLOAT = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// This specifies how colors are interpolated.
        /// </summary>
        public enum class D2D1_COLOR_INTERPOLATION_MODE
        {
            /// <summary>
            /// Colors will be interpolated in straight alpha space.
            /// </summary>
            STRAIGHT = 0,

            /// <summary>
            /// Colors will be interpolated in premultiplied alpha space.
            /// </summary>
            PREMULTIPLIED = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// This defines the valid property types that can be used in an effect property
        /// interface.
        /// </summary>
        public enum class D2D1_PROPERTY_TYPE
        {
            UNKNOWN = 0,
            STRING = 1,
            BOOL = 2,
            UINT32 = 3,
            INT32 = 4,
            FLOAT = 5,
            VECTOR2 = 6,
            VECTOR3 = 7,
            VECTOR4 = 8,
            BLOB = 9,
            IUNKNOWN = 10,
            ENUM = 11,
            ARRAY = 12,
            CLSID = 13,
            MATRIX_3X2 = 14,
            MATRIX_4X3 = 15,
            MATRIX_4X4 = 16,
            MATRIX_5X4 = 17,
            COLOR_CONTEXT = 18,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// This is used to specify the quality of image scaling with
        /// ID2D1DeviceContext::DrawImage and with the 2D Affine Transform Effect.
        /// </summary>
        public enum class D2D1_INTERPOLATION_MODE
        {
            /// <summary>
            /// Samples the nearest single point and uses that exact color.
            /// This mode uses less processing time, but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = ::D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR,

            /// <summary>
            /// Uses a four point sample and linear interpolation.
            /// This mode uses more processing time than the nearest neighbor mode, but outputs
            /// a higher quality image.
            /// </summary>
            LINEAR = ::D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation.
            /// This mode uses the most processing time, but outputs a higher quality image.
            /// </summary>
            CUBIC = ::D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing.
            /// This mode is good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = ::D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape
            /// of the bitmap.
            /// </summary>
            ANISOTROPIC = ::D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image if
            /// downscaling is involved in the transform matrix. Then uses the cubic interpolation mode
            /// for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = ::D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Creation properties for an image brush.
        /// </summary>
        public value struct D2D1_IMAGE_BRUSH_PROPERTIES
        {
            /// <summary>
            /// The source rectangle in the image space from which the image will be tiled or interpolated.
            /// </summary>
            Direct2DNet::D2D1_RECT_F sourceRectangle;

            /// <summary>
            /// The extend mode in the image x-axis.
            /// </summary>
            Direct2DNet::D2D1_EXTEND_MODE extendModeX;

            /// <summary>
            /// The extend mode in the image y-axis.
            /// </summary>
            Direct2DNet::D2D1_EXTEND_MODE extendModeY;

            /// <summary>
            /// The interpolation mode to use when scaling the image brush.
            /// </summary>
            Direct2DNet::D2D1_INTERPOLATION_MODE interpolationMode;

            D2D1_IMAGE_BRUSH_PROPERTIES(
                Direct2DNet::D2D1_RECT_F sourceRectangle,
                Direct2DNet::D2D1_EXTEND_MODE extendModeX,
                Direct2DNet::D2D1_EXTEND_MODE extendModeY,
                Direct2DNet::D2D1_INTERPOLATION_MODE interpolationMode
            ) : sourceRectangle(sourceRectangle), extendModeX(extendModeX), extendModeY(extendModeY),
                interpolationMode(interpolationMode) {}

            static operator ::D2D1_IMAGE_BRUSH_PROPERTIES(Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES %rhs)
            {
                ::D2D1_IMAGE_BRUSH_PROPERTIES value;
                value.sourceRectangle = static_cast<::D2D1_RECT_F>(rhs.sourceRectangle);
                value.extendModeX = (::D2D1_EXTEND_MODE)((int)rhs.extendModeX);
                value.extendModeY = (::D2D1_EXTEND_MODE)((int)rhs.extendModeY);
                value.interpolationMode = (::D2D1_INTERPOLATION_MODE)((int)rhs.interpolationMode);

                return value;
            }

            static operator Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES(::D2D1_IMAGE_BRUSH_PROPERTIES %rhs)
            {
                Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES value;
                value.sourceRectangle = static_cast<Direct2DNet::D2D1_RECT_F>(rhs.sourceRectangle);
                value.extendModeX = (Direct2DNet::D2D1_EXTEND_MODE)((int)rhs.extendModeX);
                value.extendModeY = (Direct2DNet::D2D1_EXTEND_MODE)((int)rhs.extendModeY);
                value.interpolationMode = (Direct2DNet::D2D1_INTERPOLATION_MODE)((int)rhs.interpolationMode);

                return value;
            }

            static Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES Default(Direct2DNet::D2D1_RECT_F sourceRectangle)
            {
                return Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES(
                    sourceRectangle,
                    Direct2DNet::D2D1_EXTEND_MODE::CLAMP,
                    Direct2DNet::D2D1_EXTEND_MODE::CLAMP,
                    Direct2DNet::D2D1_INTERPOLATION_MODE::LINEAR
                );
            }
        };
    }
}