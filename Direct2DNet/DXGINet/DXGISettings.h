#pragma once

#include "DXGINetHeaders.h"
#include "../DXCommonSettings.h"
#include <msclr/marshal.h>

using namespace msclr::interop;

namespace D2DNet
{
    namespace DXGINet
    {
        /// <summary>
        /// Resource data formats, including fully - typed and typeless formats.
        /// A list of modifiers at the bottom of the page more fully describes 
        /// each format type.
        /// </summary>
        public enum class DXGI_FORMAT
        {
            /// <summary>The format is not known.</summary>
            FORMAT_UNKNOWN = 0,

            /// <summary>A four-component, 128-bit typeless format that supports
            /// 32 bits per channel including alpha.</summary>
            FORMAT_R32G32B32A32_TYPELESS = 1,

            /// <summary>A four-component, 128-bit floating-point format that supports
            /// 32 bits per channel including alpha.</summary>
            FORMAT_R32G32B32A32_FLOAT = 2,

            /// <summary>A four-component, 128-bit unsigned-integer format that
            /// supports 32 bits per channel including alpha.</summary>
            FORMAT_R32G32B32A32_UINT = 3,

            /// <summary>A four-component, 128-bit signed-integer format that
            /// supports 32 bits per channel including alpha.</summary>
            FORMAT_R32G32B32A32_SINT = 4,

            /// <summary>A three-component, 96-bit typeless format that supports
            /// 32 bits per color channel.</summary>
            FORMAT_R32G32B32_TYPELESS = 5,

            /// <summary>A three-component, 96-bit floating-point format that supports
            /// 32 bits per color channel.</summary>
            FORMAT_R32G32B32_FLOAT = 6,

            /// <summary>A three-component, 96-bit unsigned-integer format that
            /// supports 32 bits per color channel.</summary>
            FORMAT_R32G32B32_UINT = 7,

            /// <summary>A three-component, 96-bit signed-integer format that supports
            /// 32 bits per color channel.</summary>
            FORMAT_R32G32B32_SINT = 8,

            /// <summary>A four-component, 64-bit typeless format that supports
            /// 16 bits per channel including alpha.</summary>
            FORMAT_R16G16B16A16_TYPELESS = 9,

            /// <summary>A four-component, 64-bit floating-point format that supports
            /// 16 bits per channel including alpha.</summary>
            FORMAT_R16G16B16A16_FLOAT = 10,

            /// <summary>A four-component, 64-bit unsigned-normalized-integer format
            /// that supports 16 bits per channel including alpha.</summary>
            FORMAT_R16G16B16A16_UNORM = 11,

            /// <summary>A four-component, 64-bit unsigned-integer format that
            /// supports 16 bits per channel including alpha.</summary>
            FORMAT_R16G16B16A16_UINT = 12,

            /// <summary>A four-component, 64-bit signed-normalized-integer format
            /// that supports 16 bits per channel including alpha.</summary>
            FORMAT_R16G16B16A16_SNORM = 13,

            /// <summary>A four-component, 64-bit signed-integer format that supports
            /// 16 bits per channel including alpha.</summary>
            FORMAT_R16G16B16A16_SINT = 14,

            /// <summary>A two-component, 64-bit typeless format that supports
            /// 32 bits for the red channel and 32 bits for the green channel.</summary>
            FORMAT_R32G32_TYPELESS = 15,

            /// <summary>A two-component, 64-bit floating-point format that supports
            /// 32 bits for the red channel and 32 bits for the green channel.</summary>
            FORMAT_R32G32_FLOAT = 16,

            /// <summary>A two-component, 64-bit unsigned-integer format that supports
            /// 32 bits for the red channel and 32 bits for the green channel.</summary>
            FORMAT_R32G32_UINT = 17,

            /// <summary>A two-component, 64-bit signed-integer format that supports
            /// 32 bits for the red channel and 32 bits for the green channel.</summary>
            FORMAT_R32G32_SINT = 18,

            /// <summary>A two-component, 64-bit typeless format that supports
            /// 32 bits for the red channel, 8 bits for the green channel,
            /// and 24 bits are unused.</summary>
            FORMAT_R32G8X24_TYPELESS = 19,

            /// <summary>A 32-bit floating-point component, and two unsigned-integer
            /// components (with an additional 32 bits). This format supports
            /// 32-bit depth, 8-bit stencil, and 24 bits are unused.</summary>
            FORMAT_D32_FLOAT_S8X24_UINT = 20,

            /// <summary>A 32-bit floating-point component, and two typeless
            /// components (with an additional 32 bits). This format supports 32-bit
            /// red channel, 8 bits are unused, and 24 bits are unused.</summary>
            FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,

            /// <summary>A 32-bit typeless component, and two unsigned-integer components
            /// (with an additional 32 bits). This format has 32 bits unused, 8 bits for
            /// green channel, and 24 bits are unused.</summary>
            FORMAT_X32_TYPELESS_G8X24_UINT = 22,

            /// <summary>A four-component, 32-bit typeless format that supports
            /// 10 bits for each color and 2 bits for alpha.</summary>
            FORMAT_R10G10B10A2_TYPELESS = 23,

            /// <summary>A four-component, 32-bit unsigned-normalized-integer format
            /// that supports 10 bits for each color and 2 bits for alpha.</summary>
            FORMAT_R10G10B10A2_UNORM = 24,

            /// <summary>A four-component, 32-bit unsigned-integer format that supports
            /// 10 bits for each color and 2 bits for alpha.</summary>
            FORMAT_R10G10B10A2_UINT = 25,

            /// <summary>Three partial-precision floating-point numbers encoded into a
            /// single 32-bit value (a variant of s10e5, which is sign bit, 10-bit
            /// mantissa, and 5-bit biased (15) exponent).
            /// There are no sign bits, andthere is a 5 - bit biased(15) exponent for
            /// each channel, 6 - bit mantissa for R andG, anda 5 - bit mantissa
            /// for B.</summary>
            FORMAT_R11G11B10_FLOAT = 26,

            /// <summary>A four-component, 32-bit typeless format that supports
            /// 8 bits per channel including alpha.</summary>
            FORMAT_R8G8B8A8_TYPELESS = 27,

            /// <summary>A four-component, 32-bit unsigned-normalized-integer format
            /// that supports 8 bits per channel including alpha.</summary>
            FORMAT_R8G8B8A8_UNORM = 28,

            /// <summary>A four-component, 32-bit unsigned-normalized integer sRGB
            /// format that supports 8 bits per channel including alpha.</summary>
            FORMAT_R8G8B8A8_UNORM_SRGB = 29,

            /// <summary>A four-component, 32-bit unsigned-integer format that supports
            /// 8 bits per channel including alpha.</summary>
            FORMAT_R8G8B8A8_UINT = 30,

            /// <summary>A four-component, 32-bit signed-normalized-integer format
            /// that supports 8 bits per channel including alpha.</summary>
            FORMAT_R8G8B8A8_SNORM = 31,

            /// <summary>A four-component, 32-bit signed-integer format that supports
            /// 8 bits per channel including alpha.</summary>
            FORMAT_R8G8B8A8_SINT = 32,

            /// <summary>A two-component, 32-bit typeless format that supports 16 bits
            /// for the red channel and 16 bits for the green channel.</summary>
            FORMAT_R16G16_TYPELESS = 33,

            /// <summary>A two-component, 32-bit floating-point format that supports
            /// 16 bits for the red channel and 16 bits for the green channel.</summary>
            FORMAT_R16G16_FLOAT = 34,

            /// <summary>A two-component, 32-bit unsigned-normalized-integer format
            /// that supports 16 bits each for the green and red channels.</summary>
            FORMAT_R16G16_UNORM = 35,

            /// <summary>A two-component, 32-bit unsigned-integer format that supports
            /// 16 bits for the red channel and 16 bits for the green channel.</summary>
            FORMAT_R16G16_UINT = 36,

            /// <summary>A two-component, 32-bit signed-normalized-integer format that
            /// supports 16 bits for the red channel and 16 bits for the green
            /// channel.</summary>
            FORMAT_R16G16_SNORM = 37,

            /// <summary>A two-component, 32-bit signed-integer format that supports
            /// 16 bits for the red channel and 16 bits for the green channel.</summary>
            FORMAT_R16G16_SINT = 38,

            /// <summary>A single-component, 32-bit typeless format that supports
            /// 32 bits for the red channel.</summary>
            FORMAT_R32_TYPELESS = 39,

            /// <summary>A single-component, 32-bit floating-point format that supports
            /// 32 bits for depth.</summary>
            FORMAT_D32_FLOAT = 40,

            /// <summary>A single-component, 32-bit floating-point format that supports
            /// 32 bits for the red channel.</summary>
            FORMAT_R32_FLOAT = 41,

            /// <summary>A single-component, 32-bit unsigned-integer format that
            /// supports 32 bits for the red channel.</summary>
            FORMAT_R32_UINT = 42,

            /// <summary>A single-component, 32-bit signed-integer format that supports
            /// 32 bits for the red channel.</summary>
            FORMAT_R32_SINT = 43,

            /// <summary>A two-component, 32-bit typeless format that supports
            /// 24 bits for the red channel and 8 bits for the green channel.</summary>
            FORMAT_R24G8_TYPELESS = 44,

            /// <summary>A 32-bit z-buffer format that supports 24 bits for depth
            /// and 8 bits for stencil.</summary>
            FORMAT_D24_UNORM_S8_UINT = 45,

            /// <summary>A 32-bit format, that contains a 24 bit, single-component,
            /// unsigned-normalized integer, with an additional typeless 8 bits.
            /// This format has 24 bits red channel and 8 bits unused.</summary>
            FORMAT_R24_UNORM_X8_TYPELESS = 46,

            /// <summary>A 32-bit format, that contains a 24 bit, single-component,
            /// typeless format, with an additional 8 bit unsigned integer component.
            /// This format has 24 bits unused and 8 bits green channel.</summary>
            FORMAT_X24_TYPELESS_G8_UINT = 47,

            /// <summary>A two-component, 16-bit typeless format that supports
            /// 8 bits for the red channel and 8 bits for the green channel.</summary>
            FORMAT_R8G8_TYPELESS = 48,

            /// <summary>A two-component, 16-bit unsigned-normalized-integer format
            /// that supports 8 bits for the red channel and 8 bits for the
            /// green channel.</summary>
            FORMAT_R8G8_UNORM = 49,

            /// <summary>A two-component, 16-bit unsigned-integer format that supports
            /// 8 bits for the red channel and 8 bits for the green channel.</summary>
            FORMAT_R8G8_UINT = 50,

            /// <summary>A two-component, 16-bit signed-normalized-integer format
            /// that supports 8 bits for the red channel and 8 bits for the
            /// green channel.</summary>
            FORMAT_R8G8_SNORM = 51,

            /// <summary>A two-component, 16-bit signed-integer format that supports
            /// 8 bits for the red channel and 8 bits for the green channel.</summary>
            FORMAT_R8G8_SINT = 52,

            /// <summary>A single-component, 16-bit typeless format that supports
            /// 16 bits for the red channel.</summary>
            FORMAT_R16_TYPELESS = 53,

            /// <summary>A single-component, 16-bit floating-point format that supports
            /// 16 bits for the red channel.</summary>
            FORMAT_R16_FLOAT = 54,

            /// <summary>A single-component, 16-bit unsigned-normalized-integer format
            /// that supports 16 bits for depth.</summary>
            FORMAT_D16_UNORM = 55,

            /// <summary>A single-component, 16-bit unsigned-normalized-integer format
            /// that supports 16 bits for the red channel.</summary>
            FORMAT_R16_UNORM = 56,

            /// <summary>A single-component, 16-bit unsigned-integer format that
            /// supports 16 bits for the red channel.</summary>
            FORMAT_R16_UINT = 57,

            /// <summary>A single-component, 16-bit signed-normalized-integer format
            /// that supports 16 bits for the red channel.</summary>
            FORMAT_R16_SNORM = 58,

            /// <summary>A single-component, 16-bit signed-integer format that supports
            /// 16 bits for the red channel.</summary>
            FORMAT_R16_SINT = 59,

            /// <summary>A single-component, 8-bit typeless format that supports 8 bits
            /// for the red channel.</summary>
            FORMAT_R8_TYPELESS = 60,

            /// <summary>A single-component, 8-bit unsigned-normalized-integer format
            /// that supports 8 bits for the red channel.</summary>
            FORMAT_R8_UNORM = 61,

            /// <summary>A single-component, 8-bit unsigned-integer format
            /// that supports 8 bits for the red channel.</summary>
            FORMAT_R8_UINT = 62,

            /// <summary>A single-component, 8-bit signed-normalized-integer format
            /// that supports 8 bits for the red channel.</summary>
            FORMAT_R8_SNORM = 63,

            /// <summary>A single-component, 8-bit signed-integer format that supports
            /// 8 bits for the red channel.</summary>
            FORMAT_R8_SINT = 64,

            /// <summary>A single-component, 8-bit unsigned-normalized-integer format
            /// for alpha only.</summary>
            FORMAT_A8_UNORM = 65,

            /// <summary>A single-component, 1-bit unsigned-normalized integer format
            /// that supports 1 bit for the red channel.</summary>
            FORMAT_R1_UNORM = 66,

            /// <summary>Three partial-precision floating-point numbers encoded into
            /// a single 32-bit value all sharing the same 5-bit exponent (variant
            /// of s10e5, which is sign bit, 10-bit mantissa, and 5-bit biased
            /// (15) exponent).
            /// There is no sign bit, and there is a shared 5 - bit biased(15)
            /// exponent and a 9 - bit mantissa for each channel</summary>
            FORMAT_R9G9B9E5_SHAREDEXP = 67,

            /// <summary>A four-component, 32-bit unsigned-normalized-integer format.
            /// This packed RGB format is analogous to the UYVY format.
            /// Each 32-bit block describes a pair of pixels: (R8, G8, B8) and
            /// (R8, G8, B8) where the R8/B8 values are repeated, and the G8 values
            /// are unique to each pixel. Width must be even.</summary>
            FORMAT_R8G8_B8G8_UNORM = 68,

            /// <summary>A four-component, 32-bit unsigned-normalized-integer format.
            /// This packed RGB format is analogous to the YUY2 format.
            /// Each 32-bit block describes a pair of pixels: (R8, G8, B8) and
            /// (R8, G8, B8) where the R8/B8 values are repeated, and the G8 values
            /// are unique to each pixel. Width must be even.</summary>
            FORMAT_G8R8_G8B8_UNORM = 69,

            /// <summary>Four-component typeless block-compression format.</summary>
            FORMAT_BC1_TYPELESS = 70,

            /// <summary>Four-component block-compression format.</summary>
            FORMAT_BC1_UNORM = 71,

            /// <summary>Four-component block-compression format for sRGB data.</summary>
            FORMAT_BC1_UNORM_SRGB = 72,

            /// <summary>Four-component typeless block-compression format.</summary>
            FORMAT_BC2_TYPELESS = 73,

            /// <summary>Four-component block-compression format.</summary>
            FORMAT_BC2_UNORM = 74,

            /// <summary>Four-component block-compression format for sRGB data.</summary>
            FORMAT_BC2_UNORM_SRGB = 75,

            /// <summary>Four-component typeless block-compression format.</summary>
            FORMAT_BC3_TYPELESS = 76,

            /// <summary>Four-component block-compression format.</summary>
            FORMAT_BC3_UNORM = 77,

            /// <summary>Four-component block-compression format for sRGB data.</summary>
            FORMAT_BC3_UNORM_SRGB = 78,

            /// <summary>One-component typeless block-compression format.</summary>
            FORMAT_BC4_TYPELESS = 79,

            /// <summary>One-component block-compression format.</summary>
            FORMAT_BC4_UNORM = 80,

            /// <summary>One-component block-compression format.</summary>
            FORMAT_BC4_SNORM = 81,

            /// <summary>Two-component typeless block-compression format.</summary>
            FORMAT_BC5_TYPELESS = 82,

            /// <summary>Two-component block-compression format.</summary>
            FORMAT_BC5_UNORM = 83,

            /// <summary>Two-component block-compression format.</summary>
            FORMAT_BC5_SNORM = 84,

            /// <summary>A three-component, 16-bit unsigned-normalized-integer format
            /// that supports 5 bits for blue, 6 bits for green, and 5 bits for red.
            /// </summary>
            /// <remarks>Direct3D 10 through Direct3D 11: This value is defined for DXGI.
            /// However, Direct3D 10, 10.1, or 11 devices do not support this format.
            /// </remarks>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_B5G6R5_UNORM = 85,

            /// <summary>A four-component, 16-bit unsigned-normalized-integer format
            /// that supports 5 bits for each color channel and 1-bit alpha.</summary>
            /// <remarks>Direct3D 10 through Direct3D 11: This value is defined for DXGI.
            /// However, Direct3D 10, 10.1, or 11 devices do not support this format.
            /// </remarks>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_B5G5R5A1_UNORM = 86,

            /// <summary>A four-component, 32-bit unsigned-normalized-integer format
            /// that supports 8 bits for each color channel and 8-bit alpha.</summary>
            FORMAT_B8G8R8A8_UNORM = 87,

            /// <summary>A four-component, 32-bit unsigned-normalized-integer format
            /// that supports 8 bits for each color channel and 8 bits unused.</summary>
            FORMAT_B8G8R8X8_UNORM = 88,

            /// <summary>A four-component, 32-bit 2.8-biased fixed-point format
            /// that supports 10 bits for each color channel and 2-bit alpha.</summary>
            FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,

            /// <summary>A four-component, 32-bit typeless format that supports
            /// 8 bits for each channel including alpha.</summary>
            FORMAT_B8G8R8A8_TYPELESS = 90,

            /// <summary>A four-component, 32-bit unsigned-normalized standard
            /// RGB format that supports 8 bits for each channel including alpha.</summary>
            FORMAT_B8G8R8A8_UNORM_SRGB = 91,

            /// <summary>A four-component, 32-bit typeless format that supports 8 bits
            /// for each color channel, and 8 bits are unused.</summary>
            FORMAT_B8G8R8X8_TYPELESS = 92,

            /// <summary>A four-component, 32-bit unsigned-normalized standard RGB
            /// format that supports 8 bits for each color channel, and 8 bits are
            /// unused.</summary>
            FORMAT_B8G8R8X8_UNORM_SRGB = 93,

            /// <summary>A typeless block-compression format.</summary>
            FORMAT_BC6H_TYPELESS = 94,

            /// <summary>A block-compression format.</summary>
            FORMAT_BC6H_UF16 = 95,

            /// <summary>A block-compression format.</summary>
            FORMAT_BC6H_SF16 = 96,

            /// <summary>A typeless block-compression format.</summary>
            FORMAT_BC7_TYPELESS = 97,

            /// <summary>A block-compression format.</summary>
            FORMAT_BC7_UNORM = 98,

            /// <summary>A block-compression format.</summary>
            FORMAT_BC7_UNORM_SRGB = 99,

            /// <summary>Most common YUV 4:4:4 video resource format.
            /// Valid view formats for this video resource format are
            /// FORMAT_R8G8B8A8_UNORM and FORMAT_R8G8B8A8_UINT.
            /// For UAVs, an additional valid view format is FORMAT_R32_UINT.
            /// By using FORMAT_R32_UINT for UAVs, you can both read and write
            /// as opposed to just write for FORMAT_R8G8B8A8_UNORM and
            /// FORMAT_R8G8B8A8_UINT. Supported view types are SRV, RTV, and UAV.
            /// One view provides a straightforward mapping of the entire surface.
            /// The mapping to the view channel is V->R8, U->G8, Y->B8, andA->A8.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_AYUV = 100,

            /// <summary>10-bit per channel packed YUV 4:4:4 video resource format.
            /// Valid view formats for this video resource format are
            /// FORMAT_R10G10B10A2_UNORM and FORMAT_R10G10B10A2_UINT.
            /// For UAVs, an additional valid view format is FORMAT_R32_UINT.
            /// By using FORMAT_R32_UINT for UAVs, you can both read and write
            /// as opposed to just write for FORMAT_R10G10B10A2_UNORM and
            /// FORMAT_R10G10B10A2_UINT. Supported view types are SRV and UAV.
            /// One view provides a straightforward mapping of the entire surface.
            /// The mapping to the view channel is U->R10, Y->G10, V->B10, andA->A2.
            /// </summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_Y410 = 101,

            /// <summary>16-bit per channel packed YUV 4:4:4 video resource format.
            /// Valid view formats for this video resource format are
            /// FORMAT_R16G16B16A16_UNORM and FORMAT_R16G16B16A16_UINT.
            /// Supported view types are SRV and UAV. One view provides a straightforward
            /// mapping of the entire surface. The mapping to the view channel is
            /// U->R16, Y->G16, V->B16, andA->A16.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_Y416 = 102,

            /// <summary>Most common YUV 4:2:0 video resource format.
            /// Valid luminance data view formats for this video resource format are
            /// FORMAT_R8_UNORM and FORMAT_R8_UINT.
            /// Valid chrominance data view formats (width and height are each 1/2 of
            /// luminance view) for this video resource format are
            /// FORMAT_R8G8_UNORM and FORMAT_R8G8_UINT.
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
            FORMAT_NV12 = 103,

            /// <summary>10-bit per channel planar YUV 4:2:0 video resource format.
            /// Valid luminance data view formats for this video resource format are
            /// FORMAT_R16_UNORM and FORMAT_R16_UINT. The runtime does not
            /// enforce whether the lowest 6 bits are 0 (given that this video resource
            /// format is a 10-bit format that uses 16 bits). If required, application
            /// shader code would have to enforce this manually. From the runtime's
            /// point of view, FORMAT_P010 is no different than FORMAT_P016.
            /// Valid chrominance data view formats (width and height are each 1/2 of
            /// luminance view) for this video resource format are
            /// FORMAT_R16G16_UNORM and FORMAT_R16G16_UINT.
            /// For UAVs, an additional valid chrominance data view format is
            /// FORMAT_R32_UINT. By using FORMAT_R32_UINT for UAVs,
            /// you can both read and write as opposed to just write for
            /// FORMAT_R16G16_UNORM and FORMAT_R16G16_UINT.
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
            FORMAT_P010 = 104,

            /// <summary>16-bit per channel planar YUV 4:2:0 video resource format.
            /// Valid luminance data view formats for this video resource format are
            /// FORMAT_R16_UNORM and FORMAT_R16_UINT. Valid chrominance data
            /// view formats (width and height are each 1/2 of luminance view) for
            /// this video resource format are FORMAT_R16G16_UNORM and
            /// FORMAT_R16G16_UINT. For UAVs, an additional valid chrominance
            /// data view format is FORMAT_R32_UINT. By using FORMAT_R32_UINT
            /// for UAVs, you can both read and write as opposed to just write for
            /// FORMAT_R16G16_UNORM and FORMAT_R16G16_UINT. Supported view types
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
            FORMAT_P016 = 105,

            /// <summary>8-bit per channel planar YUV 4:2:0 video resource format.
            /// This format is subsampled where each pixel has its own Y value,
            /// but each 2x2 pixel block shares a single U and V value. The runtime
            /// requires that the width and height of all resources that are created
            /// with this format are multiples of 2. The runtime also requires that the
            /// left, right, top, and bottom members of any RECT that are used for this
            /// format are multiples of 2. This format differs from FORMAT_NV12
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
            FORMAT_420_OPAQUE = 106,

            /// <summary>
            /// <para>Most common YUV 4:2:2 video resource format.
            /// Valid view formats for this video resource format are
            /// FORMAT_R8G8B8A8_UNORM and FORMAT_R8G8B8A8_UINT.
            /// For UAVs, an additional valid view format is FORMAT_R32_UINT.
            /// By using FORMAT_R32_UINT for UAVs, you can both read and write
            /// as opposed to just write for FORMAT_R8G8B8A8_UNORM and
            /// FORMAT_R8G8B8A8_UINT. Supported view types are SRV and UAV.
            /// One view provides a straightforward mapping of the entire surface.
            /// The mapping to the view channel is Y0->R8, U0->G8, Y1->B8, andV0->A8.
            /// </para>
            /// <para>A unique valid view format for this video resource format is
            /// FORMAT_R8G8_B8G8_UNORM. With this view format, the width of the
            /// view appears to be twice what the FORMAT_R8G8B8A8_UNORM or
            /// FORMAT_R8G8B8A8_UINT view would be when hardware reconstructs
            /// RGBA automatically on read and before filtering. This Direct3D
            /// hardware behavior is legacy and is likely not useful any more.
            /// With this view format, the mapping to the view channel is Y0->R8,
            /// U0->G8[0], Y1->B8, andV0->G8[1].
            /// </para>
            /// <para>Width must be even.</para>
            /// </summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_YUY2 = 107,

            /// <summary>10-bit per channel packed YUV 4:2:2 video resource format.
            /// Valid view formats for this video resource format are
            /// FORMAT_R16G16B16A16_UNORM and FORMAT_R16G16B16A16_UINT.
            /// The runtime does not enforce whether the lowest 6 bits are 0
            /// (given that this video resource format is a 10-bit format that uses
            /// 16 bits). If required, application shader code would have to enforce
            /// this manually. From the runtime's point of view, FORMAT_Y210 is
            /// no different than FORMAT_Y216. Supported view types are SRV and UAV.
            /// One view provides a straightforward mapping of the entire surface.
            /// The mapping to the view channel is Y0->R16, U->G16, Y1->B16, andV->A16.
            /// Width must be even.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_Y210 = 108,

            /// <summary>16-bit per channel packed YUV 4:2:2 video resource format.
            /// Valid view formats for this video resource format are
            /// FORMAT_R16G16B16A16_UNORM and FORMAT_R16G16B16A16_UINT.
            /// Supported view types are SRV and UAV. One view provides a
            /// straightforward mapping of the entire surface.
            /// The mapping to the view channel is Y0->R16, U->G16, Y1->B16, andV->A16.
            /// Width must be even.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_Y216 = 109,

            /// <summary>Most common planar YUV 4:1:1 video resource format.
            /// Valid luminance data view formats for this video resource format are
            /// FORMAT_R8_UNORM and FORMAT_R8_UINT. Valid chrominance data
            /// view formats (width and height are each 1/4 of luminance view) for this
            /// video resource format are FORMAT_R8G8_UNORM and FORMAT_R8G8_UINT.
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
            FORMAT_NV11 = 110,

            /// <summary>4-bit palletized YUV format that is commonly used for
            /// DVD subpicture.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_AI44 = 111,

            /// <summary>4-bit palletized YUV format that is commonly used for
            /// DVD subpicture.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_IA44 = 112,

            /// <summary>8-bit palletized format that is used for palletized RGB data
            /// when the processor processes ISDB-T data and for palletized YUV data
            /// when the processor processes BluRay data.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_P8 = 113,

            /// <summary>8-bit palletized format with 8 bits of alpha that is used
            /// for palletized YUV data when the processor processes BluRay data.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_A8P8 = 114,

            /// <summary>A four-component, 16-bit unsigned-normalized integer format
            /// that supports 4 bits for each channel including alpha.</summary>
            /// <remarks>Direct3D 11.1:  This value is not supported until Windows 8.
            /// </remarks>
            FORMAT_B4G4R4A4_UNORM = 115,

            /// <summary>A video format; an 8-bit version of a hybrid planar 4:2:2 format.
            /// </summary>
            FORMAT_P208 = 130,

            /// <summary>An 8 bit YCbCrA 4:4 rendering format.</summary>
            FORMAT_V208 = 131,

            /// <summary>An 8 bit YCbCrA 4:4:4:4 rendering format.</summary>
            FORMAT_V408 = 132,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_UINT = 0xffffffff
        };

        public value struct DXGI_RATIONAL
        {
            unsigned int numerator;
            unsigned int denominator;

            DXGI_RATIONAL(unsigned int numerator, unsigned int denominator)
                : numerator(numerator), denominator(denominator) {}

            static operator ::DXGI_RATIONAL(DXGINet::DXGI_RATIONAL %rhs)
            {
                ::DXGI_RATIONAL value;
                value.Numerator = rhs.numerator;
                value.Denominator = rhs.denominator;

                return value;
            }

            static operator DXGINet::DXGI_RATIONAL(::DXGI_RATIONAL %rhs)
            {
                DXGINet::DXGI_RATIONAL value;
                value.numerator = rhs.Numerator;
                value.denominator = rhs.Denominator;

                return value;
            }
        };

        public enum class DXGI_MODE_SCANLINE_ORDER
        {
            UNSPECIFIED = 0,
            PROGRESSIVE = 1,
            UPPER_FIELD_FIRST = 2,
            LOWER_FIELD_FIRST = 3
        };

        public enum class DXGI_MODE_SCALING
        {
            UNSPECIFIED = 0,
            CENTERED = 1,
            STRETCHED = 2
        };

        public value struct DXGI_MODE_DESC
        {
            unsigned int width;
            unsigned int height;
            DXGINet::DXGI_RATIONAL refreshRate;
            DXGINet::DXGI_FORMAT format;
            DXGINet::DXGI_MODE_SCANLINE_ORDER scanlineOrdering;
            DXGINet::DXGI_MODE_SCALING scaling;

            DXGI_MODE_DESC(
                unsigned int width,
                unsigned int height,
                DXGINet::DXGI_RATIONAL refreshRate,
                DXGINet::DXGI_FORMAT format,
                DXGINet::DXGI_MODE_SCANLINE_ORDER scanlineOrdering,
                DXGINet::DXGI_MODE_SCALING scaling)
                : width(width), height(height), refreshRate(refreshRate), format(format),
                scanlineOrdering(scanlineOrdering), scaling(scaling) {}

            static operator ::DXGI_MODE_DESC(DXGINet::DXGI_MODE_DESC %rhs)
            {
                ::DXGI_MODE_DESC value;
                value.Width = rhs.width;
                value.Height = rhs.height;
                value.RefreshRate = static_cast<::DXGI_RATIONAL>(rhs.refreshRate);
                value.Format = (::DXGI_FORMAT)((int)rhs.format);
                value.ScanlineOrdering = (::DXGI_MODE_SCANLINE_ORDER)((int)rhs.scanlineOrdering);
                value.Scaling = (::DXGI_MODE_SCALING)((int)rhs.scaling);

                return value;
            }

            static operator DXGINet::DXGI_MODE_DESC(::DXGI_MODE_DESC %rhs)
            {
                DXGINet::DXGI_MODE_DESC value;
                value.width = rhs.Width;
                value.height = rhs.Height;
                value.refreshRate = static_cast<DXGINet::DXGI_RATIONAL>(rhs.RefreshRate);
                value.format = (DXGINet::DXGI_FORMAT)((int)rhs.Format);
                value.scanlineOrdering = (DXGINet::DXGI_MODE_SCANLINE_ORDER)((int)rhs.ScanlineOrdering);
                value.scaling = (DXGINet::DXGI_MODE_SCALING)((int)rhs.Scaling);

                return value;
            }
        };

        public value struct DXGI_SAMPLE_DESC
        {
            unsigned int count;
            unsigned int quality;

            DXGI_SAMPLE_DESC(unsigned int count, unsigned int quality) : count(count), quality(quality) {}

            static operator ::DXGI_SAMPLE_DESC(DXGINet::DXGI_SAMPLE_DESC %rhs)
            {
                ::DXGI_SAMPLE_DESC value;
                value.Count = rhs.count;
                value.Quality = rhs.quality;

                return value;
            }

            static operator DXGINet::DXGI_SAMPLE_DESC(::DXGI_SAMPLE_DESC %rhs)
            {
                DXGINet::DXGI_SAMPLE_DESC value;
                value.count = rhs.Count;
                value.quality = rhs.Quality;

                return value;
            }
        };

        public enum class DXGI_CPU_ACCESS
        {
            NONE = DXGI_CPU_ACCESS_NONE,
            DYNAMIC = DXGI_CPU_ACCESS_DYNAMIC,
            READ_WRITE = DXGI_CPU_ACCESS_READ_WRITE,
            SCRATCH = DXGI_CPU_ACCESS_SCRATCH
        };

        [System::FlagsAttribute]
        public enum class DXGI_USAGE : UINT
        {
            NONE = 0,
            SHADER_INPUT = DXGI_USAGE_SHADER_INPUT,
            RENDER_TARGET_OUTPUT = DXGI_USAGE_RENDER_TARGET_OUTPUT,
            BACK_BUFFER = DXGI_USAGE_BACK_BUFFER,
            SHARED = DXGI_USAGE_SHARED,
            READ_ONLY = DXGI_USAGE_READ_ONLY,
            DISCARD_ON_PRESENT = DXGI_USAGE_DISCARD_ON_PRESENT,
            UNORDERED_ACCESS = DXGI_USAGE_UNORDERED_ACCESS
        };

        public enum class DXGI_SWAP_EFFECT
        {
            DISCARD = 0,
            SEQUENTIAL = 1,
            FLIP_SEQUENTIAL = 3,
            FLIP_DISCARD = 4
        };

        [System::FlagsAttribute]
        public enum class DXGI_SWAP_CHAIN_FLAG : unsigned int
        {
            NONE = 0,
            NONPREROTATED = 1,
            ALLOW_MODE_SWITCH = 2,
            GDI_COMPATIBLE = 4,
            RESTRICTED_CONTENT = 8,
            RESTRICT_SHARED_RESOURCE_DRIVER = 16,
            DISPLAY_ONLY = 32,
            FRAME_LATENCY_WAITABLE_OBJECT = 64,
            FOREGROUND_LAYER = 128,
            FULLSCREEN_VIDEO = 256,
            YUV_VIDEO = 512,
            HW_PROTECTED = 1024,
            ALLOW_TEARING = 2048,
            RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS = 4096
        };

        public value struct DXGI_SWAP_CHAIN_DESC
        {
            DXGINet::DXGI_MODE_DESC bufferDesc;
            DXGINet::DXGI_SAMPLE_DESC sampleDesc;
            DXGINet::DXGI_USAGE bufferUsage;
            unsigned int bufferCount;
            System::IntPtr outputWindow;
            bool windowed;
            DXGINet::DXGI_SWAP_EFFECT swapEffect;
            DXGINet::DXGI_SWAP_CHAIN_FLAG flags;

            DXGI_SWAP_CHAIN_DESC(
                DXGINet::DXGI_MODE_DESC bufferDesc,
                DXGINet::DXGI_SAMPLE_DESC sampleDesc,
                DXGINet::DXGI_USAGE bufferUsage,
                unsigned int bufferCount,
                System::IntPtr outputWindow,
                bool windowed,
                DXGINet::DXGI_SWAP_EFFECT swapEffect,
                DXGINet::DXGI_SWAP_CHAIN_FLAG flags)
                : bufferDesc(bufferDesc), sampleDesc(sampleDesc), bufferUsage(bufferUsage),
                bufferCount(bufferCount), outputWindow(outputWindow), windowed(windowed),
                swapEffect(swapEffect), flags(flags) {}

            static operator ::DXGI_SWAP_CHAIN_DESC(DXGINet::DXGI_SWAP_CHAIN_DESC %rhs)
            {
                ::DXGI_SWAP_CHAIN_DESC value;
                value.BufferDesc = static_cast<::DXGI_MODE_DESC>(rhs.bufferDesc);
                value.SampleDesc = static_cast<::DXGI_SAMPLE_DESC>(rhs.sampleDesc);
                value.BufferUsage = (::DXGI_USAGE)rhs.bufferUsage;
                value.BufferCount = rhs.bufferCount;
                value.OutputWindow = (HWND)rhs.outputWindow.ToPointer();
                value.Windowed = System::Convert::ToInt32(rhs.windowed);
                value.SwapEffect = (::DXGI_SWAP_EFFECT)((int)rhs.swapEffect);
                value.Flags = (UINT)rhs.flags;

                return value;
            }

            static operator DXGINet::DXGI_SWAP_CHAIN_DESC(::DXGI_SWAP_CHAIN_DESC %rhs)
            {
                DXGINet::DXGI_SWAP_CHAIN_DESC value;
                value.bufferDesc = static_cast<DXGINet::DXGI_MODE_DESC>(rhs.BufferDesc);
                value.sampleDesc = static_cast<DXGINet::DXGI_SAMPLE_DESC>(rhs.SampleDesc);
                value.bufferUsage = (DXGINet::DXGI_USAGE)rhs.BufferUsage;
                value.bufferCount = rhs.BufferCount;
                value.outputWindow = System::IntPtr(rhs.OutputWindow);
                value.windowed = System::Convert::ToBoolean(rhs.Windowed);
                value.swapEffect = (DXGINet::DXGI_SWAP_EFFECT)((int)rhs.SwapEffect);
                value.flags = (DXGINet::DXGI_SWAP_CHAIN_FLAG)rhs.Flags;

                return value;
            }
        };

        public value struct DXGI_ADAPTER_DESC
        {
            System::String ^description;
            unsigned int vendorId;
            unsigned int deviceId;
            unsigned int subSysId;
            unsigned int revision;
            unsigned __int64 dedicatedVideoMemory;
            unsigned __int64 dedicatedSystemMemory;
            unsigned __int64 sharedSystemMemory;
            D2DNet::LUID adapterLuid;

            static operator DXGINet::DXGI_ADAPTER_DESC(::DXGI_ADAPTER_DESC %rhs)
            {
                DXGINet::DXGI_ADAPTER_DESC value;
                value.description = marshal_as<System::String ^>(&rhs.Description[0]);
                value.vendorId = rhs.VendorId;
                value.deviceId = rhs.DeviceId;
                value.subSysId = rhs.SubSysId;
                value.revision = rhs.Revision;
                value.dedicatedVideoMemory = rhs.DedicatedVideoMemory;
                value.dedicatedSystemMemory = rhs.DedicatedSystemMemory;
                value.sharedSystemMemory = rhs.SharedSystemMemory;
                value.adapterLuid = static_cast<D2DNet::LUID>(rhs.AdapterLuid);

                return value;
            }
        };

        [System::FlagsAttribute]
        public enum class DXGI_PRESENT : UINT
        {
            NONE = 0UL,
            TEST = DXGI_PRESENT_TEST,
            DO_NOT_SEQUENCE = DXGI_PRESENT_DO_NOT_SEQUENCE,
            RESTART = DXGI_PRESENT_RESTART,
            DO_NOT_WAIT = DXGI_PRESENT_DO_NOT_WAIT,
            STEREO_PREFER_RIGHT = DXGI_PRESENT_STEREO_PREFER_RIGHT,
            STEREO_TEMPORARY_MONO = DXGI_PRESENT_STEREO_TEMPORARY_MONO,
            RESTRICT_TO_OUTPUT = DXGI_PRESENT_RESTRICT_TO_OUTPUT,
            USE_DURATION = DXGI_PRESENT_USE_DURATION,
            ALLOW_TEARING = DXGI_PRESENT_ALLOW_TEARING
        };

        public value struct DXGI_SURFACE_DESC
        {
            unsigned int width;
            unsigned int height;
            DXGINet::DXGI_FORMAT format;
            DXGINet::DXGI_SAMPLE_DESC sampleDesc;

            static operator DXGINet::DXGI_SURFACE_DESC(::DXGI_SURFACE_DESC %rhs)
            {
                DXGINet::DXGI_SURFACE_DESC value;
                value.width = rhs.Width;
                value.height = rhs.Height;
                value.format = static_cast<DXGINet::DXGI_FORMAT>(rhs.Format);
                value.sampleDesc = static_cast<DXGINet::DXGI_SAMPLE_DESC>(rhs.SampleDesc);

                return value;
            }
        };

        public value struct DXGI_MAPPED_RECT
        {
            int pitch;
            unsigned char *pBits;

            static operator DXGINet::DXGI_MAPPED_RECT(::DXGI_MAPPED_RECT %rhs)
            {
                DXGINet::DXGI_MAPPED_RECT value;
                value.pitch = rhs.Pitch;
                value.pBits = rhs.pBits;

                return value;
            }
        };

        [System::FlagsAttribute]
        public enum class DXGI_MAP : UINT
        {
            NONE = 0U,
            READ = DXGI_MAP_READ,
            WRITE = DXGI_MAP_WRITE,
            DISCARD = DXGI_MAP_DISCARD
        };

        public value struct DXGI_FRAME_STATISTICS
        {
            unsigned int presentCount;
            unsigned int presentRefreshCount;
            unsigned int syncRefreshCount;
            D2DNet::LARGE_INTEGER syncQPCTime;
            D2DNet::LARGE_INTEGER syncGPUTime;

            static operator DXGINet::DXGI_FRAME_STATISTICS(::DXGI_FRAME_STATISTICS %rhs)
            {
                DXGINet::DXGI_FRAME_STATISTICS value;
                value.presentCount = rhs.PresentCount;
                value.presentRefreshCount = rhs.PresentRefreshCount;
                value.syncRefreshCount = rhs.SyncRefreshCount;
                value.syncQPCTime = static_cast<D2DNet::LARGE_INTEGER>(rhs.SyncQPCTime);
                value.syncGPUTime = static_cast<D2DNet::LARGE_INTEGER>(rhs.SyncGPUTime);

                return value;
            }
        };

    }
}