#pragma once

#include "D2DMath.h"

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
        D2D1_FACTORY_TYPE_SINGLE_THREADED = 0,

        /// <summary>
        /// The resulting factory may be invoked from multiple threads. Returned resources
        /// use interlocked reference counting and their state is protected.
        /// </summary>
        D2D1_FACTORY_TYPE_MULTI_THREADED = 1,
        D2D1_FACTORY_TYPE_FORCE_DWORD = 0xffffffff
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
        D2D1_RENDER_TARGET_TYPE_DEFAULT = 0,

        /// <summary>
        /// The render target will render using the CPU.
        /// </summary>
        D2D1_RENDER_TARGET_TYPE_SOFTWARE = 1,

        /// <summary>
        /// The render target will render using the GPU.
        /// </summary>
        D2D1_RENDER_TARGET_TYPE_HARDWARE = 2,
        D2D1_RENDER_TARGET_TYPE_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Resource data formats, including fully - typed and typeless formats.
    /// A list of modifiers at the bottom of the page more fully describes 
    /// each format type.
    /// </summary>
    public enum class DXGI_FORMAT
    {
        /// <summary>The format is not known.</summary>
        DXGI_FORMAT_UNKNOWN = 0,

        /// <summary>A four-component, 128-bit typeless format that supports
        /// 32 bits per channel including alpha.</summary>
        DXGI_FORMAT_R32G32B32A32_TYPELESS = 1,

        /// <summary>A four-component, 128-bit floating-point format that supports
        /// 32 bits per channel including alpha.</summary>
        DXGI_FORMAT_R32G32B32A32_FLOAT = 2,

        /// <summary>A four-component, 128-bit unsigned-integer format that
        /// supports 32 bits per channel including alpha.</summary>
        DXGI_FORMAT_R32G32B32A32_UINT = 3,

        /// <summary>A four-component, 128-bit signed-integer format that
        /// supports 32 bits per channel including alpha.</summary>
        DXGI_FORMAT_R32G32B32A32_SINT = 4,

        /// <summary>A three-component, 96-bit typeless format that supports
        /// 32 bits per color channel.</summary>
        DXGI_FORMAT_R32G32B32_TYPELESS = 5,

        /// <summary>A three-component, 96-bit floating-point format that supports
        /// 32 bits per color channel.</summary>
        DXGI_FORMAT_R32G32B32_FLOAT = 6,

        /// <summary>A three-component, 96-bit unsigned-integer format that
        /// supports 32 bits per color channel.</summary>
        DXGI_FORMAT_R32G32B32_UINT = 7,

        /// <summary>A three-component, 96-bit signed-integer format that supports
        /// 32 bits per color channel.</summary>
        DXGI_FORMAT_R32G32B32_SINT = 8,

        /// <summary>A four-component, 64-bit typeless format that supports
        /// 16 bits per channel including alpha.</summary>
        DXGI_FORMAT_R16G16B16A16_TYPELESS = 9,

        /// <summary>A four-component, 64-bit floating-point format that supports
        /// 16 bits per channel including alpha.</summary>
        DXGI_FORMAT_R16G16B16A16_FLOAT = 10,

        /// <summary>A four-component, 64-bit unsigned-normalized-integer format
        /// that supports 16 bits per channel including alpha.</summary>
        DXGI_FORMAT_R16G16B16A16_UNORM = 11,

        /// <summary>A four-component, 64-bit unsigned-integer format that
        /// supports 16 bits per channel including alpha.</summary>
        DXGI_FORMAT_R16G16B16A16_UINT = 12,

        /// <summary>A four-component, 64-bit signed-normalized-integer format
        /// that supports 16 bits per channel including alpha.</summary>
        DXGI_FORMAT_R16G16B16A16_SNORM = 13,

        /// <summary>A four-component, 64-bit signed-integer format that supports
        /// 16 bits per channel including alpha.</summary>
        DXGI_FORMAT_R16G16B16A16_SINT = 14,

        /// <summary>A two-component, 64-bit typeless format that supports
        /// 32 bits for the red channel and 32 bits for the green channel.</summary>
        DXGI_FORMAT_R32G32_TYPELESS = 15,

        /// <summary>A two-component, 64-bit floating-point format that supports
        /// 32 bits for the red channel and 32 bits for the green channel.</summary>
        DXGI_FORMAT_R32G32_FLOAT = 16,

        /// <summary>A two-component, 64-bit unsigned-integer format that supports
        /// 32 bits for the red channel and 32 bits for the green channel.</summary>
        DXGI_FORMAT_R32G32_UINT = 17,

        /// <summary>A two-component, 64-bit signed-integer format that supports
        /// 32 bits for the red channel and 32 bits for the green channel.</summary>
        DXGI_FORMAT_R32G32_SINT = 18,

        /// <summary>A two-component, 64-bit typeless format that supports
        /// 32 bits for the red channel, 8 bits for the green channel,
        /// and 24 bits are unused.</summary>
        DXGI_FORMAT_R32G8X24_TYPELESS = 19,

        /// <summary>A 32-bit floating-point component, and two unsigned-integer
        /// components (with an additional 32 bits). This format supports
        /// 32-bit depth, 8-bit stencil, and 24 bits are unused.</summary>
        DXGI_FORMAT_D32_FLOAT_S8X24_UINT = 20,

        /// <summary>A 32-bit floating-point component, and two typeless
        /// components (with an additional 32 bits). This format supports 32-bit
        /// red channel, 8 bits are unused, and 24 bits are unused.</summary>
        DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,

        /// <summary>A 32-bit typeless component, and two unsigned-integer components
        /// (with an additional 32 bits). This format has 32 bits unused, 8 bits for
        /// green channel, and 24 bits are unused.</summary>
        DXGI_FORMAT_X32_TYPELESS_G8X24_UINT = 22,

        /// <summary>A four-component, 32-bit typeless format that supports
        /// 10 bits for each color and 2 bits for alpha.</summary>
        DXGI_FORMAT_R10G10B10A2_TYPELESS = 23,

        /// <summary>A four-component, 32-bit unsigned-normalized-integer format
        /// that supports 10 bits for each color and 2 bits for alpha.</summary>
        DXGI_FORMAT_R10G10B10A2_UNORM = 24,

        /// <summary>A four-component, 32-bit unsigned-integer format that supports
        /// 10 bits for each color and 2 bits for alpha.</summary>
        DXGI_FORMAT_R10G10B10A2_UINT = 25,

        /// <summary>Three partial-precision floating-point numbers encoded into a
        /// single 32-bit value (a variant of s10e5, which is sign bit, 10-bit
        /// mantissa, and 5-bit biased (15) exponent).
        /// There are no sign bits, andthere is a 5 - bit biased(15) exponent for
        /// each channel, 6 - bit mantissa for R andG, anda 5 - bit mantissa
        /// for B.</summary>
        DXGI_FORMAT_R11G11B10_FLOAT = 26,

        /// <summary>A four-component, 32-bit typeless format that supports
        /// 8 bits per channel including alpha.</summary>
        DXGI_FORMAT_R8G8B8A8_TYPELESS = 27,

        /// <summary>A four-component, 32-bit unsigned-normalized-integer format
        /// that supports 8 bits per channel including alpha.</summary>
        DXGI_FORMAT_R8G8B8A8_UNORM = 28,

        /// <summary>A four-component, 32-bit unsigned-normalized integer sRGB
        /// format that supports 8 bits per channel including alpha.</summary>
        DXGI_FORMAT_R8G8B8A8_UNORM_SRGB = 29,

        /// <summary>A four-component, 32-bit unsigned-integer format that supports
        /// 8 bits per channel including alpha.</summary>
        DXGI_FORMAT_R8G8B8A8_UINT = 30,

        /// <summary>A four-component, 32-bit signed-normalized-integer format
        /// that supports 8 bits per channel including alpha.</summary>
        DXGI_FORMAT_R8G8B8A8_SNORM = 31,

        /// <summary>A four-component, 32-bit signed-integer format that supports
        /// 8 bits per channel including alpha.</summary>
        DXGI_FORMAT_R8G8B8A8_SINT = 32,

        /// <summary>A two-component, 32-bit typeless format that supports 16 bits
        /// for the red channel and 16 bits for the green channel.</summary>
        DXGI_FORMAT_R16G16_TYPELESS = 33,

        /// <summary>A two-component, 32-bit floating-point format that supports
        /// 16 bits for the red channel and 16 bits for the green channel.</summary>
        DXGI_FORMAT_R16G16_FLOAT = 34,

        /// <summary>A two-component, 32-bit unsigned-normalized-integer format
        /// that supports 16 bits each for the green and red channels.</summary>
        DXGI_FORMAT_R16G16_UNORM = 35,

        /// <summary>A two-component, 32-bit unsigned-integer format that supports
        /// 16 bits for the red channel and 16 bits for the green channel.</summary>
        DXGI_FORMAT_R16G16_UINT = 36,

        /// <summary>A two-component, 32-bit signed-normalized-integer format that
        /// supports 16 bits for the red channel and 16 bits for the green
        /// channel.</summary>
        DXGI_FORMAT_R16G16_SNORM = 37,

        /// <summary>A two-component, 32-bit signed-integer format that supports
        /// 16 bits for the red channel and 16 bits for the green channel.</summary>
        DXGI_FORMAT_R16G16_SINT = 38,

        /// <summary>A single-component, 32-bit typeless format that supports
        /// 32 bits for the red channel.</summary>
        DXGI_FORMAT_R32_TYPELESS = 39,

        /// <summary>A single-component, 32-bit floating-point format that supports
        /// 32 bits for depth.</summary>
        DXGI_FORMAT_D32_FLOAT = 40,

        /// <summary>A single-component, 32-bit floating-point format that supports
        /// 32 bits for the red channel.</summary>
        DXGI_FORMAT_R32_FLOAT = 41,

        /// <summary>A single-component, 32-bit unsigned-integer format that
        /// supports 32 bits for the red channel.</summary>
        DXGI_FORMAT_R32_UINT = 42,

        /// <summary>A single-component, 32-bit signed-integer format that supports
        /// 32 bits for the red channel.</summary>
        DXGI_FORMAT_R32_SINT = 43,

        /// <summary>A two-component, 32-bit typeless format that supports
        /// 24 bits for the red channel and 8 bits for the green channel.</summary>
        DXGI_FORMAT_R24G8_TYPELESS = 44,

        /// <summary>A 32-bit z-buffer format that supports 24 bits for depth
        /// and 8 bits for stencil.</summary>
        DXGI_FORMAT_D24_UNORM_S8_UINT = 45,

        /// <summary>A 32-bit format, that contains a 24 bit, single-component,
        /// unsigned-normalized integer, with an additional typeless 8 bits.
        /// This format has 24 bits red channel and 8 bits unused.</summary>
        DXGI_FORMAT_R24_UNORM_X8_TYPELESS = 46,

        /// <summary>A 32-bit format, that contains a 24 bit, single-component,
        /// typeless format, with an additional 8 bit unsigned integer component.
        /// This format has 24 bits unused and 8 bits green channel.</summary>
        DXGI_FORMAT_X24_TYPELESS_G8_UINT = 47,

        /// <summary>A two-component, 16-bit typeless format that supports
        /// 8 bits for the red channel and 8 bits for the green channel.</summary>
        DXGI_FORMAT_R8G8_TYPELESS = 48,

        /// <summary>A two-component, 16-bit unsigned-normalized-integer format
        /// that supports 8 bits for the red channel and 8 bits for the
        /// green channel.</summary>
        DXGI_FORMAT_R8G8_UNORM = 49,

        /// <summary>A two-component, 16-bit unsigned-integer format that supports
        /// 8 bits for the red channel and 8 bits for the green channel.</summary>
        DXGI_FORMAT_R8G8_UINT = 50,

        /// <summary>A two-component, 16-bit signed-normalized-integer format
        /// that supports 8 bits for the red channel and 8 bits for the
        /// green channel.</summary>
        DXGI_FORMAT_R8G8_SNORM = 51,

        /// <summary>A two-component, 16-bit signed-integer format that supports
        /// 8 bits for the red channel and 8 bits for the green channel.</summary>
        DXGI_FORMAT_R8G8_SINT = 52,

        /// <summary>A single-component, 16-bit typeless format that supports
        /// 16 bits for the red channel.</summary>
        DXGI_FORMAT_R16_TYPELESS = 53,

        /// <summary>A single-component, 16-bit floating-point format that supports
        /// 16 bits for the red channel.</summary>
        DXGI_FORMAT_R16_FLOAT = 54,

        /// <summary>A single-component, 16-bit unsigned-normalized-integer format
        /// that supports 16 bits for depth.</summary>
        DXGI_FORMAT_D16_UNORM = 55,

        /// <summary>A single-component, 16-bit unsigned-normalized-integer format
        /// that supports 16 bits for the red channel.</summary>
        DXGI_FORMAT_R16_UNORM = 56,

        /// <summary>A single-component, 16-bit unsigned-integer format that
        /// supports 16 bits for the red channel.</summary>
        DXGI_FORMAT_R16_UINT = 57,

        /// <summary>A single-component, 16-bit signed-normalized-integer format
        /// that supports 16 bits for the red channel.</summary>
        DXGI_FORMAT_R16_SNORM = 58,

        /// <summary>A single-component, 16-bit signed-integer format that supports
        /// 16 bits for the red channel.</summary>
        DXGI_FORMAT_R16_SINT = 59,

        /// <summary>A single-component, 8-bit typeless format that supports 8 bits
        /// for the red channel.</summary>
        DXGI_FORMAT_R8_TYPELESS = 60,

        /// <summary>A single-component, 8-bit unsigned-normalized-integer format
        /// that supports 8 bits for the red channel.</summary>
        DXGI_FORMAT_R8_UNORM = 61,

        /// <summary>A single-component, 8-bit unsigned-integer format
        /// that supports 8 bits for the red channel.</summary>
        DXGI_FORMAT_R8_UINT = 62,

        /// <summary>A single-component, 8-bit signed-normalized-integer format
        /// that supports 8 bits for the red channel.</summary>
        DXGI_FORMAT_R8_SNORM = 63,

        /// <summary>A single-component, 8-bit signed-integer format that supports
        /// 8 bits for the red channel.</summary>
        DXGI_FORMAT_R8_SINT = 64,

        /// <summary>A single-component, 8-bit unsigned-normalized-integer format
        /// for alpha only.</summary>
        DXGI_FORMAT_A8_UNORM = 65,

        /// <summary>A single-component, 1-bit unsigned-normalized integer format
        /// that supports 1 bit for the red channel.</summary>
        DXGI_FORMAT_R1_UNORM = 66,

        /// <summary>Three partial-precision floating-point numbers encoded into
        /// a single 32-bit value all sharing the same 5-bit exponent (variant
        /// of s10e5, which is sign bit, 10-bit mantissa, and 5-bit biased
        /// (15) exponent).
        /// There is no sign bit, and there is a shared 5 - bit biased(15)
        /// exponent and a 9 - bit mantissa for each channel</summary>
        DXGI_FORMAT_R9G9B9E5_SHAREDEXP = 67,

        /// <summary>A four-component, 32-bit unsigned-normalized-integer format.
        /// This packed RGB format is analogous to the UYVY format.
        /// Each 32-bit block describes a pair of pixels: (R8, G8, B8) and
        /// (R8, G8, B8) where the R8/B8 values are repeated, and the G8 values
        /// are unique to each pixel. Width must be even.</summary>
        DXGI_FORMAT_R8G8_B8G8_UNORM = 68,

        /// <summary>A four-component, 32-bit unsigned-normalized-integer format.
        /// This packed RGB format is analogous to the YUY2 format.
        /// Each 32-bit block describes a pair of pixels: (R8, G8, B8) and
        /// (R8, G8, B8) where the R8/B8 values are repeated, and the G8 values
        /// are unique to each pixel. Width must be even.</summary>
        DXGI_FORMAT_G8R8_G8B8_UNORM = 69,

        /// <summary>Four-component typeless block-compression format.</summary>
        DXGI_FORMAT_BC1_TYPELESS = 70,

        /// <summary>Four-component block-compression format.</summary>
        DXGI_FORMAT_BC1_UNORM = 71,

        /// <summary>Four-component block-compression format for sRGB data.</summary>
        DXGI_FORMAT_BC1_UNORM_SRGB = 72,

        /// <summary>Four-component typeless block-compression format.</summary>
        DXGI_FORMAT_BC2_TYPELESS = 73,

        /// <summary>Four-component block-compression format.</summary>
        DXGI_FORMAT_BC2_UNORM = 74,

        /// <summary>Four-component block-compression format for sRGB data.</summary>
        DXGI_FORMAT_BC2_UNORM_SRGB = 75,

        /// <summary>Four-component typeless block-compression format.</summary>
        DXGI_FORMAT_BC3_TYPELESS = 76,

        /// <summary>Four-component block-compression format.</summary>
        DXGI_FORMAT_BC3_UNORM = 77,

        /// <summary>Four-component block-compression format for sRGB data.</summary>
        DXGI_FORMAT_BC3_UNORM_SRGB = 78,

        /// <summary>One-component typeless block-compression format.</summary>
        DXGI_FORMAT_BC4_TYPELESS = 79,

        /// <summary>One-component block-compression format.</summary>
        DXGI_FORMAT_BC4_UNORM = 80,
            
        /// <summary>One-component block-compression format.</summary>
        DXGI_FORMAT_BC4_SNORM = 81,

        /// <summary>Two-component typeless block-compression format.</summary>
        DXGI_FORMAT_BC5_TYPELESS = 82,

        /// <summary>Two-component block-compression format.</summary>
        DXGI_FORMAT_BC5_UNORM = 83,

        /// <summary>Two-component block-compression format.</summary>
        DXGI_FORMAT_BC5_SNORM = 84,

        /// <summary>A three-component, 16-bit unsigned-normalized-integer format
        /// that supports 5 bits for blue, 6 bits for green, and 5 bits for red.
        /// </summary>
        /// <remarks>Direct3D 10 through Direct3D 11: This value is defined for DXGI.
        /// However, Direct3D 10, 10.1, or 11 devices do not support this format.
        /// </remarks>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_B5G6R5_UNORM = 85,

        /// <summary>A four-component, 16-bit unsigned-normalized-integer format
        /// that supports 5 bits for each color channel and 1-bit alpha.</summary>
        /// <remarks>Direct3D 10 through Direct3D 11: This value is defined for DXGI.
        /// However, Direct3D 10, 10.1, or 11 devices do not support this format.
        /// </remarks>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_B5G5R5A1_UNORM = 86,

        /// <summary>A four-component, 32-bit unsigned-normalized-integer format
        /// that supports 8 bits for each color channel and 8-bit alpha.</summary>
        DXGI_FORMAT_B8G8R8A8_UNORM = 87,

        /// <summary>A four-component, 32-bit unsigned-normalized-integer format
        /// that supports 8 bits for each color channel and 8 bits unused.</summary>
        DXGI_FORMAT_B8G8R8X8_UNORM = 88,

        /// <summary>A four-component, 32-bit 2.8-biased fixed-point format
        /// that supports 10 bits for each color channel and 2-bit alpha.</summary>
        DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,

        /// <summary>A four-component, 32-bit typeless format that supports
        /// 8 bits for each channel including alpha.</summary>
        DXGI_FORMAT_B8G8R8A8_TYPELESS = 90,

        /// <summary>A four-component, 32-bit unsigned-normalized standard
        /// RGB format that supports 8 bits for each channel including alpha.</summary>
        DXGI_FORMAT_B8G8R8A8_UNORM_SRGB = 91,

        /// <summary>A four-component, 32-bit typeless format that supports 8 bits
        /// for each color channel, and 8 bits are unused.</summary>
        DXGI_FORMAT_B8G8R8X8_TYPELESS = 92,

        /// <summary>A four-component, 32-bit unsigned-normalized standard RGB
        /// format that supports 8 bits for each color channel, and 8 bits are
        /// unused.</summary>
        DXGI_FORMAT_B8G8R8X8_UNORM_SRGB = 93,

        /// <summary>A typeless block-compression format.</summary>
        DXGI_FORMAT_BC6H_TYPELESS = 94,

        /// <summary>A block-compression format.</summary>
        DXGI_FORMAT_BC6H_UF16 = 95,

        /// <summary>A block-compression format.</summary>
        DXGI_FORMAT_BC6H_SF16 = 96,

        /// <summary>A typeless block-compression format.</summary>
        DXGI_FORMAT_BC7_TYPELESS = 97,

        /// <summary>A block-compression format.</summary>
        DXGI_FORMAT_BC7_UNORM = 98,

        /// <summary>A block-compression format.</summary>
        DXGI_FORMAT_BC7_UNORM_SRGB = 99,

        /// <summary>Most common YUV 4:4:4 video resource format.
        /// Valid view formats for this video resource format are
        /// DXGI_FORMAT_R8G8B8A8_UNORM and DXGI_FORMAT_R8G8B8A8_UINT.
        /// For UAVs, an additional valid view format is DXGI_FORMAT_R32_UINT.
        /// By using DXGI_FORMAT_R32_UINT for UAVs, you can both read and write
        /// as opposed to just write for DXGI_FORMAT_R8G8B8A8_UNORM and
        /// DXGI_FORMAT_R8G8B8A8_UINT. Supported view types are SRV, RTV, and UAV.
        /// One view provides a straightforward mapping of the entire surface.
        /// The mapping to the view channel is V->R8, U->G8, Y->B8, andA->A8.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_AYUV = 100,

        /// <summary>10-bit per channel packed YUV 4:4:4 video resource format.
        /// Valid view formats for this video resource format are
        /// DXGI_FORMAT_R10G10B10A2_UNORM and DXGI_FORMAT_R10G10B10A2_UINT.
        /// For UAVs, an additional valid view format is DXGI_FORMAT_R32_UINT.
        /// By using DXGI_FORMAT_R32_UINT for UAVs, you can both read and write
        /// as opposed to just write for DXGI_FORMAT_R10G10B10A2_UNORM and
        /// DXGI_FORMAT_R10G10B10A2_UINT. Supported view types are SRV and UAV.
        /// One view provides a straightforward mapping of the entire surface.
        /// The mapping to the view channel is U->R10, Y->G10, V->B10, andA->A2.
        /// </summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_Y410 = 101,

        /// <summary>16-bit per channel packed YUV 4:4:4 video resource format.
        /// Valid view formats for this video resource format are
        /// DXGI_FORMAT_R16G16B16A16_UNORM and DXGI_FORMAT_R16G16B16A16_UINT.
        /// Supported view types are SRV and UAV. One view provides a straightforward
        /// mapping of the entire surface. The mapping to the view channel is
        /// U->R16, Y->G16, V->B16, andA->A16.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_Y416 = 102,

        /// <summary>Most common YUV 4:2:0 video resource format.
        /// Valid luminance data view formats for this video resource format are
        /// DXGI_FORMAT_R8_UNORM and DXGI_FORMAT_R8_UINT.
        /// Valid chrominance data view formats (width and height are each 1/2 of
        /// luminance view) for this video resource format are
        /// DXGI_FORMAT_R8G8_UNORM and DXGI_FORMAT_R8G8_UINT.
        /// Supported view types are SRV, RTV, and UAV. For luminance data view,
        /// the mapping to the view channel is Y->R8. For chrominance data view,
        /// the mapping to the view channel is U->R8 and V->G8.</summary>
        /// <remarks>Width and height must be even. Direct3D 11 staging resources
        /// and initData parameters for this format use
        /// (rowPitch * (height + (height / 2))) bytes. The first
        /// (SysMemPitch * height) bytes are the Y plane, the remaining
        /// (SysMemPitch * (height / 2)) bytes are the UV plane.
        /// </remarks>
        /// <remarks>An app using the YUY 4:2:0 formats must map the luma (Y) plane
        /// separately from the chroma (UV) planes. Developers do this by calling
        /// ID3D12Device::CreateShaderResourceView twice for the same texture and
        /// passing in 1-channel and 2-channel formats. Passing in a 1-channel format
        /// compatible with the Y plane maps only the Y plane. Passing in a 2-channel
        /// format compatible with the UV planes (together) maps only the U and V planes
        /// as a single resource view.
        /// </remarks>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_NV12 = 103,

        /// <summary>10-bit per channel planar YUV 4:2:0 video resource format.
        /// Valid luminance data view formats for this video resource format are
        /// DXGI_FORMAT_R16_UNORM and DXGI_FORMAT_R16_UINT. The runtime does not
        /// enforce whether the lowest 6 bits are 0 (given that this video resource
        /// format is a 10-bit format that uses 16 bits). If required, application
        /// shader code would have to enforce this manually. From the runtime's
        /// point of view, DXGI_FORMAT_P010 is no different than DXGI_FORMAT_P016.
        /// Valid chrominance data view formats (width and height are each 1/2 of
        /// luminance view) for this video resource format are
        /// DXGI_FORMAT_R16G16_UNORM and DXGI_FORMAT_R16G16_UINT.
        /// For UAVs, an additional valid chrominance data view format is
        /// DXGI_FORMAT_R32_UINT. By using DXGI_FORMAT_R32_UINT for UAVs,
        /// you can both read and write as opposed to just write for
        /// DXGI_FORMAT_R16G16_UNORM and DXGI_FORMAT_R16G16_UINT.
        /// Supported view types are SRV, RTV, and UAV. For luminance data view,
        /// the mapping to the view channel is Y->R16. For chrominance data view,
        /// the mapping to the view channel is U->R16 and V->G16.</summary>
        /// <remarks>Width and height must be even. Direct3D 11 staging resources
        /// and initData parameters for this format use
        /// (rowPitch * (height + (height / 2))) bytes. The first
        /// (SysMemPitch * height) bytes are the Y plane, the remaining
        /// (SysMemPitch * (height / 2)) bytes are the UV plane.
        /// </remarks>
        /// <remarks>An app using the YUY 4:2:0 formats must map the luma (Y) plane
        /// separately from the chroma (UV) planes. Developers do this by calling
        /// ID3D12Device::CreateShaderResourceView twice for the same texture and
        /// passing in 1-channel and 2-channel formats. Passing in a 1-channel format
        /// compatible with the Y plane maps only the Y plane. Passing in a 2-channel
        /// format compatible with the UV planes (together) maps only the U and V planes
        /// as a single resource view.
        /// </remarks>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_P010 = 104,

        /// <summary>16-bit per channel planar YUV 4:2:0 video resource format.
        /// Valid luminance data view formats for this video resource format are
        /// DXGI_FORMAT_R16_UNORM and DXGI_FORMAT_R16_UINT. Valid chrominance data
        /// view formats (width and height are each 1/2 of luminance view) for
        /// this video resource format are DXGI_FORMAT_R16G16_UNORM and
        /// DXGI_FORMAT_R16G16_UINT. For UAVs, an additional valid chrominance
        /// data view format is DXGI_FORMAT_R32_UINT. By using DXGI_FORMAT_R32_UINT
        /// for UAVs, you can both read and write as opposed to just write for
        /// DXGI_FORMAT_R16G16_UNORM and DXGI_FORMAT_R16G16_UINT. Supported view types
        /// are SRV, RTV, and UAV. For luminance data view, the mapping to the
        /// view channel is Y->R16. For chrominance data view, the mapping to the
        /// view channel is U->R16 and V->G16.</summary>
        /// <remarks>Width and height must be even. Direct3D 11 staging resources
        /// and initData parameters for this format use
        /// (rowPitch * (height + (height / 2))) bytes. The first
        /// (SysMemPitch * height) bytes are the Y plane, the remaining
        /// (SysMemPitch * (height / 2)) bytes are the UV plane.
        /// </remarks>
        /// <remarks>An app using the YUY 4:2:0 formats must map the luma (Y) plane
        /// separately from the chroma (UV) planes. Developers do this by calling
        /// ID3D12Device::CreateShaderResourceView twice for the same texture and
        /// passing in 1-channel and 2-channel formats. Passing in a 1-channel format
        /// compatible with the Y plane maps only the Y plane. Passing in a 2-channel
        /// format compatible with the UV planes (together) maps only the U and V planes
        /// as a single resource view.
        /// </remarks>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_P016 = 105,

        /// <summary>8-bit per channel planar YUV 4:2:0 video resource format.
        /// This format is subsampled where each pixel has its own Y value,
        /// but each 2x2 pixel block shares a single U and V value. The runtime
        /// requires that the width and height of all resources that are created
        /// with this format are multiples of 2. The runtime also requires that the
        /// left, right, top, and bottom members of any RECT that are used for this
        /// format are multiples of 2. This format differs from DXGI_FORMAT_NV12
        /// in that the layout of the data within the resource is completely opaque
        /// to applications. Applications cannot use the CPU to map the resource
        /// and then access the data within the resource. You cannot use shaders
        /// with this format. Because of this behavior, legacy hardware that supports
        /// a non-NV12 4:2:0 layout (for example, YV12, and so on) can be used. Also,
        /// new hardware that has a 4:2:0 implementation better than NV12 can be
        /// used when the application does not need the data to be in a
        /// standard layout. </summary>
        /// <remarks>Width and height must be even. Direct3D 11 staging resources
        /// and initData parameters for this format use
        /// (rowPitch * (height + (height / 2))) bytes. 
        /// </remarks>
        /// <remarks>An app using the YUY 4:2:0 formats must map the luma (Y) plane
        /// separately from the chroma (UV) planes. Developers do this by calling
        /// ID3D12Device::CreateShaderResourceView twice for the same texture and
        /// passing in 1-channel and 2-channel formats. Passing in a 1-channel format
        /// compatible with the Y plane maps only the Y plane. Passing in a 2-channel
        /// format compatible with the UV planes (together) maps only the U and V planes
        /// as a single resource view.
        /// </remarks>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_420_OPAQUE = 106,

        /// <summary>
        /// <para>Most common YUV 4:2:2 video resource format.
        /// Valid view formats for this video resource format are
        /// DXGI_FORMAT_R8G8B8A8_UNORM and DXGI_FORMAT_R8G8B8A8_UINT.
        /// For UAVs, an additional valid view format is DXGI_FORMAT_R32_UINT.
        /// By using DXGI_FORMAT_R32_UINT for UAVs, you can both read and write
        /// as opposed to just write for DXGI_FORMAT_R8G8B8A8_UNORM and
        /// DXGI_FORMAT_R8G8B8A8_UINT. Supported view types are SRV and UAV.
        /// One view provides a straightforward mapping of the entire surface.
        /// The mapping to the view channel is Y0->R8, U0->G8, Y1->B8, andV0->A8.
        /// </para>
        /// <para>A unique valid view format for this video resource format is
        /// DXGI_FORMAT_R8G8_B8G8_UNORM. With this view format, the width of the
        /// view appears to be twice what the DXGI_FORMAT_R8G8B8A8_UNORM or
        /// DXGI_FORMAT_R8G8B8A8_UINT view would be when hardware reconstructs
        /// RGBA automatically on read and before filtering. This Direct3D
        /// hardware behavior is legacy and is likely not useful any more.
        /// With this view format, the mapping to the view channel is Y0->R8,
        /// U0->G8[0], Y1->B8, andV0->G8[1].
        /// </para>
        /// <para>Width must be even.</para>
        /// </summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_YUY2 = 107,

        /// <summary>10-bit per channel packed YUV 4:2:2 video resource format.
        /// Valid view formats for this video resource format are
        /// DXGI_FORMAT_R16G16B16A16_UNORM and DXGI_FORMAT_R16G16B16A16_UINT.
        /// The runtime does not enforce whether the lowest 6 bits are 0
        /// (given that this video resource format is a 10-bit format that uses
        /// 16 bits). If required, application shader code would have to enforce
        /// this manually. From the runtime's point of view, DXGI_FORMAT_Y210 is
        /// no different than DXGI_FORMAT_Y216. Supported view types are SRV and UAV.
        /// One view provides a straightforward mapping of the entire surface.
        /// The mapping to the view channel is Y0->R16, U->G16, Y1->B16, andV->A16.
        /// Width must be even.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_Y210 = 108,

        /// <summary>16-bit per channel packed YUV 4:2:2 video resource format.
        /// Valid view formats for this video resource format are
        /// DXGI_FORMAT_R16G16B16A16_UNORM and DXGI_FORMAT_R16G16B16A16_UINT.
        /// Supported view types are SRV and UAV. One view provides a
        /// straightforward mapping of the entire surface.
        /// The mapping to the view channel is Y0->R16, U->G16, Y1->B16, andV->A16.
        /// Width must be even.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_Y216 = 109,

        /// <summary>Most common planar YUV 4:1:1 video resource format.
        /// Valid luminance data view formats for this video resource format are
        /// DXGI_FORMAT_R8_UNORM and DXGI_FORMAT_R8_UINT. Valid chrominance data
        /// view formats (width and height are each 1/4 of luminance view) for this
        /// video resource format are DXGI_FORMAT_R8G8_UNORM and DXGI_FORMAT_R8G8_UINT.
        /// Supported view types are SRV, RTV, and UAV. For luminance data view,
        /// the mapping to the view channel is Y->R8. For chrominance data view,
        /// the mapping to the view channel is U->R8 and V->G8.</summary>
        /// <remarks>Width must be a multiple of 4. Direct3D11 staging resources
        /// and initData parameters for this format use
        /// (rowPitch * height * 2) bytes. The first (SysMemPitch * height) bytes
        /// are the Y plane, the next ((SysMemPitch / 2) * height) bytes are the
        /// UV plane, and the remainder is padding. 
        /// </remarks>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_NV11 = 110,

        /// <summary>4-bit palletized YUV format that is commonly used for
        /// DVD subpicture.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_AI44 = 111,

        /// <summary>4-bit palletized YUV format that is commonly used for
        /// DVD subpicture.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_IA44 = 112,

        /// <summary>8-bit palletized format that is used for palletized RGB data
        /// when the processor processes ISDB-T data and for palletized YUV data
        /// when the processor processes BluRay data.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_P8 = 113,

        /// <summary>8-bit palletized format with 8 bits of alpha that is used
        /// for palletized YUV data when the processor processes BluRay data.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_A8P8 = 114,

        /// <summary>A four-component, 16-bit unsigned-normalized integer format
        /// that supports 4 bits for each channel including alpha.</summary>
        /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
        /// </remarks>
        DXGI_FORMAT_B4G4R4A4_UNORM = 115,

        /// <summary>A video format; an 8-bit version of a hybrid planar 4:2:2 format.
        /// </summary>
        DXGI_FORMAT_P208 = 130,

        /// <summary>An 8 bit YCbCrA 4:4 rendering format.</summary>
        DXGI_FORMAT_V208 = 131,

        /// <summary>An 8 bit YCbCrA 4:4:4:4 rendering format.</summary>
        DXGI_FORMAT_V408 = 132,
        DXGI_FORMAT_FORCE_UINT = 0xffffffff
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
        D2D1_ALPHA_MODE_UNKNOWN = 0,

        /// <summary>
        /// Treat the alpha as premultipled.
        /// </summary>
        D2D1_ALPHA_MODE_PREMULTIPLIED = 1,

        /// <summary>
        /// Opacity is in the 'A' component only.
        /// </summary>
        D2D1_ALPHA_MODE_STRAIGHT = 2,

        /// <summary>
        /// Ignore any alpha channel information.
        /// </summary>
        D2D1_ALPHA_MODE_IGNORE = 3,

        D2D1_ALPHA_MODE_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Description of a pixel format.
    /// </summary>
    public value struct D2D1_PIXEL_FORMAT
    {
        Direct2DNet::DXGI_FORMAT format;
        Direct2DNet::D2D1_ALPHA_MODE alphaMode;

    internal:
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
            value.format = (Direct2DNet::DXGI_FORMAT)((int)rhs.format);
            value.alphaMode = (Direct2DNet::D2D1_ALPHA_MODE)((int)rhs.alphaMode);

            return value;
        }

    public:
        /// <summary>
        /// Gets the default pixel format, which is
        /// <see cref="Direct2DNet::DXGI_FORMAT::DXGI_FORMAT_UNKNOWN"/> for
        /// <see cref="format"/> and
        /// <see cref="Direct2DNet::D2D1_ALPHA_MODE::D2D1_ALPHA_MODE_UNKNOWN"/> for
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
    public enum class D2D1_RENDER_TARGET_USAGE
    {
        D2D1_RENDER_TARGET_USAGE_NONE = 0x00000000,

        /// <summary>
        /// Rendering will occur locally, if a terminal-services session is established, the
        /// bitmap updates will be sent to the terminal services client.
        /// </summary>
        D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING = 0x00000001,

        /// <summary>
        /// The render target will allow a call to GetDC on the ID2D1GdiInteropRenderTarget
        /// interface. Rendering will also occur locally.
        /// </summary>
        D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE = 0x00000002,
        D2D1_RENDER_TARGET_USAGE_FORCE_DWORD = 0xffffffff
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
        D2D1_FEATURE_LEVEL_DEFAULT = 0,

        /// <summary>
        /// The D3D device level is DX9 compatible.
        /// </summary>
        D2D1_FEATURE_LEVEL_9 = D3D_FEATURE_LEVEL_9_1,

        /// <summary>
        /// The D3D device level is DX10 compatible.
        /// </summary>
        D2D1_FEATURE_LEVEL_10 = D3D_FEATURE_LEVEL_10_0,
        D2D1_FEATURE_LEVEL_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Contains rendering options (hardware or software), pixel format, DPI
    /// information, remoting options, and Direct3D support requirements for a render
    /// target.
    /// </summary>
    public value struct D2D1_RENDER_TARGET_PROPERTIES
    {
        Direct2DNet::D2D1_RENDER_TARGET_TYPE type;
        Direct2DNet::D2D1_PIXEL_FORMAT pixelFormat;
        float dpiX;
        float dpiY;
        Direct2DNet::D2D1_RENDER_TARGET_USAGE usage;
        Direct2DNet::D2D1_FEATURE_LEVEL minLevel;

    internal:
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

    public:
        /// <summary>
        /// Gets the default render target property, which is
        /// <see cref="Direct2DNet::D2D1_RENDER_TARGET_TYPE::D2D1_RENDER_TARGET_TYPE_DEFAULT"/> for
        /// <see cref="type"/>, <see cref="Direct2DNet::D2D1_PIXEL_FORMAT::Default"/> for
        /// <see cref="pixelFormat"/>, <c>0</c> for
        /// <see cref="dpiX"/> and <see cref="dpiY"/>
        /// <see cref="Direct2DNet::D2D1_RENDER_TARGET_USAGE::D2D1_RENDER_TARGET_USAGE_NONE"/> for
        /// <see cref="usage"/>, and <see cref="Direct2DNet::D2D1_FEATURE_LEVEL::D2D1_FEATURE_LEVEL_DEFAULT"/> for
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
    /// Describes how present should behave.
    /// </summary>
    public enum class D2D1_PRESENT_OPTIONS
    {
        D2D1_PRESENT_OPTIONS_NONE = 0x00000000,

        /// <summary>
        /// Keep the target contents intact through present.
        /// </summary>
        D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS = 0x00000001,

        /// <summary>
        /// Do not wait for display refresh to commit changes to display.
        /// </summary>
        D2D1_PRESENT_OPTIONS_IMMEDIATELY = 0x00000002,
        D2D1_PRESENT_OPTIONS_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Contains the HWND, pixel size, and presentation options for an
    /// ID2D1HwndRenderTarget.
    /// </summary>
    public value struct D2D1_HWND_RENDER_TARGET_PROPERTIES
    {
        System::IntPtr hwnd;
        Direct2DNet::D2D1_SIZE_U pixelSize;
        Direct2DNet::D2D1_PRESENT_OPTIONS presentOptions;

    internal:
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

    public:
        /// <summary>
        /// Gets the default hwnd render target property, which is
        /// 0 width and 0 height for
        /// <see cref="pixelSize"/> and <see cref="Direct2DNet::D2D1_PRESENT_OPTIONS::D2D1_PRESENT_OPTIONS_NONE"/> for
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
    /// Describes whether a window is occluded.
    /// </summary>
    public enum class D2D1_WINDOW_STATE
    {
        /// <summary>The window is not occluded.</summary>
        D2D1_WINDOW_STATE_NONE = 0x0000000,

        /// <summary>The window is occluded.</summary>
        D2D1_WINDOW_STATE_OCCLUDED = 0x0000001,
        D2D1_WINDOW_STATE_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Enum which describes the drawing of the ends of a line.
    /// </summary>
    public enum class D2D1_CAP_STYLE
    {
        /// <summary>
        /// Flat line cap.
        /// </summary>
        D2D1_CAP_STYLE_FLAT = 0,

        /// <summary>
        /// Square line cap.
        /// </summary>
        D2D1_CAP_STYLE_SQUARE = 1,

        /// <summary>
        /// Round line cap.
        /// </summary>
        D2D1_CAP_STYLE_ROUND = 2,

        /// <summary>
        /// Triangle line cap.
        /// </summary>
        D2D1_CAP_STYLE_TRIANGLE = 3,
        D2D1_CAP_STYLE_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Enum which describes the drawing of the corners on the line.
    /// </summary>
    public enum class D2D1_LINE_JOIN
    {
        /// <summary>
        /// Miter join.
        /// </summary>
        D2D1_LINE_JOIN_MITER = 0,

        /// <summary>
        /// Bevel join.
        /// </summary>
        D2D1_LINE_JOIN_BEVEL = 1,

        /// <summary>
        /// Round join.
        /// </summary>
        D2D1_LINE_JOIN_ROUND = 2,

        /// <summary>
        /// Miter/Bevel join.
        /// </summary>
        D2D1_LINE_JOIN_MITER_OR_BEVEL = 3,
        D2D1_LINE_JOIN_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Describes the sequence of dashes and gaps in a stroke.
    /// </summary>
    public enum class D2D1_DASH_STYLE
    {
        /// <summary>A solid line with no breaks.</summary>
        D2D1_DASH_STYLE_SOLID = 0,

        /// <summary>A dash followed by a gap of equal length.
        /// The dash and the gap are each twice as long as the stroke thickness.
        /// The equivalent dash array for D2D1_DASH_STYLE_DASH is{ 2, 2 }.</summary>
        D2D1_DASH_STYLE_DASH = 1,

        /// <summary>A dot followed by a longer gap.
        /// The equivalent dash array for D2D1_DASH_STYLE_DOT is{ 0, 2 }.</summary>
        D2D1_DASH_STYLE_DOT = 2,

        /// <summary>A dash, followed by a gap, followed by a dot, followed by
        /// another gap.The equivalent dash array for D2D1_DASH_STYLE_DASH_DOT is
        /// { 2, 2, 0, 2 }.</summary>
        D2D1_DASH_STYLE_DASH_DOT = 3,

        /// <summary>A dash, followed by a gap, followed by a dot, followed by another
        /// gap, followed by another dot, followed by another gap.
        ///The equivalent dash array for D2D1_DASH_STYLE_DASH_DOT_DOT is
        ///{ 2, 2, 0, 2, 0, 2 }.</summary>
        D2D1_DASH_STYLE_DASH_DOT_DOT = 4,

        /// <summary>The dash pattern is specified by an array of
        /// floating-point values.</summary>
        D2D1_DASH_STYLE_CUSTOM = 5,
        D2D1_DASH_STYLE_FORCE_DWORD = 0xffffffff
    };

    /// <summary>
    /// Properties, aside from the width, that allow geometric penning to be specified.
    /// </summary>
    public value struct D2D1_STROKE_STYLE_PROPERTIES
    {
        Direct2DNet::D2D1_CAP_STYLE startCap;
        Direct2DNet::D2D1_CAP_STYLE endCap;
        Direct2DNet::D2D1_CAP_STYLE dashCap;
        Direct2DNet::D2D1_LINE_JOIN lineJoin;
        float miterLimit;
        Direct2DNet::D2D1_DASH_STYLE dashStyle;
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

    internal:
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
    };
}