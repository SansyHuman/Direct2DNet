#pragma once

#include "DXGINetHeaders.h"
#include "../DXCommonSettings.h"
#include <msclr/marshal.h>
#include <wchar.h>
#include <memory>

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

        /// <summary>
        /// Represents a rational number.
        /// </summary>
        public value struct DXGI_RATIONAL
        {
            /// <summary>
            /// An unsigned integer value representing the top of the rational number.
            /// </summary>
            unsigned int numerator;

            /// <summary>
            /// An unsigned integer value representing the bottom of the rational number.
            /// </summary>
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

        /// <summary>
        /// Flags indicating the method the raster uses to create an image on a surface.
        /// </summary>
        public enum class DXGI_MODE_SCANLINE_ORDER
        {
            /// <summary>
            /// Scanline order is unspecified.
            /// </summary>
            UNSPECIFIED = 0,

            /// <summary>
            /// The image is created from the first scanline to the last without skipping any.
            /// </summary>
            PROGRESSIVE = 1,

            /// <summary>
            /// The image is created beginning with the upper field.
            /// </summary>
            UPPER_FIELD_FIRST = 2,

            /// <summary>
            /// The image is created beginning with the lower field.
            /// </summary>
            LOWER_FIELD_FIRST = 3
        };

        /// <summary>
        /// Flags indicating how an image is stretched to fit a given monitor's resolution.
        /// </summary>
        public enum class DXGI_MODE_SCALING
        {
            /// <summary>
            /// Unspecified scaling.
            /// </summary>
            UNSPECIFIED = 0,

            /// <summary>
            /// Specifies no scaling. The image is centered on the display. This flag is typically used for
            /// a fixed-dot-pitch display (such as an LED display).
            /// </summary>
            CENTERED = 1,

            /// <summary>
            /// Specifies stretched scaling.
            /// </summary>
            STRETCHED = 2
        };

        /// <summary>
        /// Describes a display mode.
        /// </summary>
        public value struct DXGI_MODE_DESC
        {
            /// <summary>
            /// A value that describes the resolution width. If you specify the width as zero when you call
            /// the <see cref="DXGINet::IDXGIFactory::CreateSwapChain"/> method to create a swap chain,
            /// the runtime obtains the width from the output window and assigns this width value to the
            /// swap-chain description. You can subsequently call the
            /// <see cref="DXGINet::IDXGISwapChain::GetDesc"/> method to retrieve the assigned width value.
            /// </summary>
            unsigned int width;

            /// <summary>
            /// A value that describes the resolution height. If you specify the height as zero when you call
            /// the <see cref="DXGINet::IDXGIFactory::CreateSwapChain"/> method to create a swap chain,
            /// the runtime obtains the height from the output window and assigns this height value to the
            /// swap-chain description. You can subsequently call the
            /// <see cref="DXGINet::IDXGISwapChain::GetDesc"/> method to retrieve the assigned height value.
            /// </summary>
            unsigned int height;

            /// <summary>
            /// A <see cref="DXGINet::DXGI_RATIONAL"/> structure describing the refresh rate in hertz.
            /// </summary>
            DXGINet::DXGI_RATIONAL refreshRate;

            /// <summary>
            /// Describing the display format.
            /// </summary>
            DXGINet::DXGI_FORMAT format;

            /// <summary>
            /// Describing the scanline drawing mode.
            /// </summary>
            DXGINet::DXGI_MODE_SCANLINE_ORDER scanlineOrdering;

            /// <summary>
            /// Describing the scaling mode.
            /// </summary>
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

        /// <summary>
        /// Describes multi-sampling parameters for a resource.
        /// </summary>
        public value struct DXGI_SAMPLE_DESC
        {
            /// <summary>
            /// The number of multisamples per pixel.
            /// </summary>
            unsigned int count;

            /// <summary>
            /// The image quality level. The higher the quality, the lower the performance.
            /// </summary>
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

        /// <summary>
        /// Flags for surface and resource creation options in CPU access.
        /// </summary>
        public enum class DXGI_CPU_ACCESS
        {
            NONE = DXGI_CPU_ACCESS_NONE,
            DYNAMIC = DXGI_CPU_ACCESS_DYNAMIC,
            READ_WRITE = DXGI_CPU_ACCESS_READ_WRITE,
            SCRATCH = DXGI_CPU_ACCESS_SCRATCH
        };

        /// <summary>
        /// Flags for surface and resource creation options in usage.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DXGI_USAGE : UINT
        {
            /// <summary>
            /// No usage.
            /// </summary>
            NONE = 0,

            /// <summary>
            /// Use the surface or resource as an input to a shader.
            /// </summary>
            SHADER_INPUT = DXGI_USAGE_SHADER_INPUT,

            /// <summary>
            /// Use the surface or resource as an output render target.
            /// </summary>
            RENDER_TARGET_OUTPUT = DXGI_USAGE_RENDER_TARGET_OUTPUT,

            /// <summary>
            /// The surface or resource is used as a back buffer. You don¡¯t need to pass
            /// <see cref="DXGINet::DXGI_USAGE::BACK_BUFFER"/> when you create a swap chain. But you can
            /// determine whether a resource belongs to a swap chain when you call
            /// <see cref="DXGINet::IDXGIResource::GetUsage"/> and get
            /// <see cref="DXGINet::DXGI_USAGE::BACK_BUFFER"/>.
            /// </summary>
            BACK_BUFFER = DXGI_USAGE_BACK_BUFFER,

            /// <summary>
            /// Share the surface or resource.
            /// </summary>
            SHARED = DXGI_USAGE_SHARED,

            /// <summary>
            /// Use the surface or resource for reading only.
            /// </summary>
            READ_ONLY = DXGI_USAGE_READ_ONLY,

            /// <summary>
            /// This flag is for internal use only.
            /// </summary>
            DISCARD_ON_PRESENT = DXGI_USAGE_DISCARD_ON_PRESENT,

            /// <summary>
            /// Use the surface or resource for unordered access.
            /// </summary>
            UNORDERED_ACCESS = DXGI_USAGE_UNORDERED_ACCESS
        };

        /// <summary>
        /// Options for handling pixels in a display surface after presentation.
        /// </summary>
        public enum class DXGI_SWAP_EFFECT
        {
            /// <summary>
            /// Use this flag to specify the bit-block transfer (bitblt) model and to specify that DXGI
            /// discard the contents of the back buffer. This flag is valid for a swap chain with more than
            /// one back buffer, although, applications only have read andwrite access to buffer 0.
            /// Use this flag to enable the display driver to select the most efficient presentation
            /// technique for the swap chain.
            /// </summary>
            DISCARD = 0,

            /// <summary>
            /// Use this flag to specify the bitblt model and to specify that DXGI persist the contents of
            /// the back buffer. Use this option to present the contents of the swap chain in order, from
            /// the first buffer(buffer 0) to the last buffer. This flag cannot be used with multisampling.
            /// </summary>
            SEQUENTIAL = 1,

            /// <summary>
            /// Use this flag to specify the flip presentation model and to specify that DXGI persist
            /// the contents of the back buffer. This flag cannot be used with multisampling.
            /// </summary>
            FLIP_SEQUENTIAL = 3,

            /// <summary>
            /// Use this flag to specify the flip presentation model and to specify that DXGI discard
            /// the contents of the back buffer. This flag cannot be used with multisampling and
            /// partial presentation.
            /// </summary>
            FLIP_DISCARD = 4
        };

        /// <summary>
        /// Options for swap-chain behavior.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DXGI_SWAP_CHAIN_FLAG : unsigned int
        {
            /// <summary>
            /// No options.
            /// </summary>
            NONE = 0,

            /// <summary>
            /// Set this flag to turn off automatic image rotation; that is, do not perform a rotation
            /// when transferring the contents of the front buffer to the monitor.
            /// Use this flag to avoid a bandwidth penalty when an application expects to handle rotation.
            /// This option is valid only during full - screen mode.
            /// </summary>
            NONPREROTATED = 1,

            /// <summary>
            /// Set this flag to enable an application to switch modes by calling
            /// <see cref="DXGINet::IDXGISwapChain::ResizeTarget"/>.
            /// When switching from windowed to full - screen mode, the display mode(or monitor resolution)
            /// will be changed to match the dimensions of the application window.
            /// </summary>
            ALLOW_MODE_SWITCH = 2,

            /// <summary>
            /// Set this flag to enable an application to render using GDI on a swap chain or a surface.
            /// </summary>
            GDI_COMPATIBLE = 4,

            /// <summary>
            /// Set this flag to indicate that the swap chain might contain protected content; therefore,
            /// the operating system supports the creation of the swap chain only when driver and hardware
            /// protection is used. If the driver and hardware do not support content protection, the call
            /// to create a resource for the swap chain fails.
            /// </summary>
            RESTRICTED_CONTENT = 8,

            /// <summary>
            /// Set this flag to indicate that shared resources that are created within the swap chain must
            /// be protected by using the driver¡¯s mechanism for restricting access to shared surfaces.
            /// </summary>
            RESTRICT_SHARED_RESOURCE_DRIVER = 16,

            /// <summary>
            /// Set this flag to restrict presented content to the local displays. Therefore, the
            /// presented content is not accessible via remote accessing or through the desktop duplication
            /// APIs.
            /// This flag supports the window content protection features of Windows. Applications can use
            /// this flag to protect their own onscreen window content from being captured or copied through
            /// a specific set of public operating system features and APIs.
            /// </summary>
            DISPLAY_ONLY = 32,

            /// <summary>
            /// Set this flag to create a waitable object you can use to ensure rendering does not begin
            /// while a frame is still being presented. When this flag is used, the swapchain's latency must
            /// be set with the <see cref="DXGINet::IDXGISwapChain2::SetMaximumFrameLatency"/> API instead
            /// of <see cref="DXGINet::IDXGIDevice1::SetMaximumFrameLatency"/>.
            /// </summary>
            FRAME_LATENCY_WAITABLE_OBJECT = 64,

            /// <summary>
            /// Set this flag to create a swap chain in the foreground layer for multi-plane rendering.
            /// This flag can only be used with CoreWindow swap chains.
            /// </summary>
            FOREGROUND_LAYER = 128,

            /// <summary>
            /// Set this flag to create a swap chain for full-screen video.
            /// </summary>
            FULLSCREEN_VIDEO = 256,

            /// <summary>
            /// Set this flag to create a swap chain for YUV video.
            /// </summary>
            YUV_VIDEO = 512,

            /// <summary>
            /// Indicates that the swap chain should be created such that all underlying resources can
            /// be protected by the hardware. Resource creation will fail if hardware content protection is
            /// not supported.
            /// This flag can only be used with swap effect
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::FLIP_SEQUENTIAL"/>.
            /// </summary>
            HW_PROTECTED = 1024,

            /// <summary>
            /// Tearing support is a requirement to enable displays that support variable refresh rates
            /// to function properly when the application presents a swap chain tied to a full screen
            /// borderless window. Win32 apps can already achieve tearing in fullscreen exclusive mode by
            /// calling SetFullscreenState(true), but the recommended approach for Win32 developers is to
            /// use this tearing flag instead. This flag requires the use of a DXGI_SWAP_EFFECT::FLIP_*
            /// swap effect.
            /// </summary>
            ALLOW_TEARING = 2048,

            RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS = 4096
        };

        /// <summary>
        /// Describes a swap chain.
        /// </summary>
        public value struct DXGI_SWAP_CHAIN_DESC
        {
            /// <summary>
            /// A <see cref="DXGINet::DXGI_MODE_DESC"/> structure that describes the backbuffer display mode.
            /// </summary>
            DXGINet::DXGI_MODE_DESC bufferDesc;

            /// <summary>
            /// A <see cref="DXGINet::DXGI_SAMPLE_DESC"/> structure that describes multi-sampling parameters.
            /// </summary>
            DXGINet::DXGI_SAMPLE_DESC sampleDesc;

            /// <summary>
            /// A member of the <see cref="DXGINet::DXGI_USAGE"/> enumerated type that describes the
            /// surface usage and CPU access options for the back buffer. The back buffer can be used
            /// for shader input or render-target output.
            /// </summary>
            DXGINet::DXGI_USAGE bufferUsage;

            /// <summary>
            /// A value that describes the number of buffers in the swap chain.
            /// </summary>
            unsigned int bufferCount;

            /// <summary>
            /// A handle to the output window. This member must not be null.
            /// </summary>
            System::IntPtr outputWindow;

            /// <summary>
            /// A Boolean value that specifies whether the output is in windowed mode.
            /// </summary>
            bool windowed;

            /// <summary>
            /// A member of the <see cref="DXGINet::DXGI_SWAP_EFFECT"/> enumerated type that describes 
            /// options for handling the contents of the presentation buffer after presenting a surface.
            /// </summary>
            DXGINet::DXGI_SWAP_EFFECT swapEffect;

            /// <summary>
            /// A member of the <see cref="DXGINet::DXGI_SWAP_CHAIN_FLAG"/> enumerated type that describes
            /// options for swap-chain behavior.
            /// </summary>
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

        /// <summary>
        /// Describes an adapter (or video card) by using DXGI 1.0.
        /// </summary>
        public value struct DXGI_ADAPTER_DESC
        {
            /// <summary>
            /// A string that contains the adapter description. On feature level 9 graphics hardware,
            /// GetDesc returns ¡°Software Adapter¡± for the description string.
            /// </summary>
            System::String ^description;

            /// <summary>
            /// The PCI ID of the hardware vendor. On feature level 9 graphics hardware, GetDesc returns
            /// zeros for the PCI ID of the hardware vendor.
            /// </summary>
            unsigned int vendorId;

            /// <summary>
            /// The PCI ID of the hardware device. On feature level 9 graphics hardware, GetDesc returns
            /// zeros for the PCI ID of the hardware device.
            /// </summary>
            unsigned int deviceId;

            /// <summary>
            /// The PCI ID of the sub system. On feature level 9 graphics hardware, GetDesc returns zeros
            /// for the PCI ID of the sub system.
            /// </summary>
            unsigned int subSysId;

            /// <summary>
            /// The PCI ID of the revision number of the adapter. On feature level 9 graphics hardware,
            /// GetDesc returns zeros for the PCI ID of the revision number of the adapter.
            /// </summary>
            unsigned int revision;

            /// <summary>
            /// The number of bytes of dedicated video memory that are not shared with the CPU.
            /// </summary>
            unsigned __int64 dedicatedVideoMemory;

            /// <summary>
            /// The number of bytes of dedicated system memory that are not shared with the CPU.
            /// This memory is allocated from available system memory at boot time.
            /// </summary>
            unsigned __int64 dedicatedSystemMemory;

            /// <summary>
            /// The number of bytes of shared system memory. This is the maximum value of system memory
            /// that may be consumed by the adapter during operation. Any incidental memory consumed by
            /// the driver as it manages and uses video memory is additional.
            /// </summary>
            unsigned __int64 sharedSystemMemory;

            /// <summary>
            /// A unique value that identifies the adapter.
            /// </summary>
            D2DNet::LUID adapterLuid;

            static operator DXGINet::DXGI_ADAPTER_DESC(::DXGI_ADAPTER_DESC %rhs)
            {
                DXGINet::DXGI_ADAPTER_DESC value;

                size_t descLen = wcslen(&rhs.Description[0]);
                if(descLen >= 128Ui64)
                {
                    WCHAR desc[129] = { 0 };
                    wcscpy_s(&desc[0], 128, &rhs.Description[0]);
                    value.description = marshal_as<System::String ^>(&desc[0]);
                }
                else
                {
                    value.description = marshal_as<System::String ^>(&rhs.Description[0]);
                }
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

        /// <summary>
        /// The DXGI_PRESENT constants specify options for presenting frames to the output.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DXGI_PRESENT : UINT
        {
            /// <summary>
            /// Present a frame from each buffer (starting with the current buffer) to the output.
            /// </summary>
            NONE = 0UL,

            /// <summary>
            /// Do not present the frame to the output. The status of the swap chain will be tested
            /// and appropriate errors returned. DXGI_PRESENT_TEST is intended for use only when switching
            /// from the idle state; do not use it to determine when to switch to the idle state because
            /// doing so can leave the swap chain unable to exit full-screen mode.
            /// </summary>
            TEST = DXGI_PRESENT_TEST,

            /// <summary>
            /// Present a frame from the current buffer to the output. Use this flag so that the
            /// presentation can use vertical-blank synchronization instead of sequencing buffers in the
            /// chain in the usual manner.
            /// </summary>
            DO_NOT_SEQUENCE = DXGI_PRESENT_DO_NOT_SEQUENCE,

            /// <summary>
            /// Specifies that the runtime will discard outstanding queued presents.
            /// </summary>
            RESTART = DXGI_PRESENT_RESTART,

            /// <summary>
            /// Specifies that the runtime will fail the presentation with the DXGI_ERROR_WAS_STILL_DRAWING
            /// error code if the calling thread is blocked; the runtime returns DXGI_ERROR_WAS_STILL_DRAWING
            /// instead of sleeping until the dependency is resolved.
            /// </summary>
            DO_NOT_WAIT = DXGI_PRESENT_DO_NOT_WAIT,

            /// <summary>
            /// Indicates that if the stereo present must be reduced to mono, right-eye viewing is used
            /// rather than left-eye viewing.
            /// </summary>
            STEREO_PREFER_RIGHT = DXGI_PRESENT_STEREO_PREFER_RIGHT,

            /// <summary>
            /// Indicates that the presentation should use the left buffer as a mono buffer.
            /// </summary>
            STEREO_TEMPORARY_MONO = DXGI_PRESENT_STEREO_TEMPORARY_MONO,

            /// <summary>
            /// Indicates that presentation content will be shown only on the particular output. The
            /// content will not be visible on other outputs. For example, if the user tries to relocate
            /// video content on another output, the video content will not be visible. 
            /// </summary>
            RESTRICT_TO_OUTPUT = DXGI_PRESENT_RESTRICT_TO_OUTPUT,

            /// <summary>
            /// This flag must be set by media apps that are currently using a custom present duration.
            /// </summary>
            USE_DURATION = DXGI_PRESENT_USE_DURATION,

            /// <summary>
            /// <para>
            /// Allowing tearing is a requirement of variable refresh rate displays.
            /// The conditions for using <see cref="DXGINet::DXGI_PRESENT::ALLOW_TEARING"/> during Present
            /// are as follows :
            /// </para>
            /// <para>
            ///     The swap chain must be created with the
            /// <see cref="DXGINet::DXGI_SWAP_CHAIN_FLAG::ALLOW_TEARING"/> flag.
            /// </para>
            /// <para>
            ///     The sync interval passed in to Present (or Present1) must be 0.
            /// </para>
            /// <para>
            ///     The DXGI_PRESENT_ALLOW_TEARING flag cannot be used in an application that is currently
            /// in full screen exclusive mode (set by calling SetFullscreenState(true)). It can only be used
            /// in windowed mode. To use this flag in full screen Win32 apps, the application should present
            /// to a fullscreen borderless window and disable automatic ALT+ENTER fullscreen switching using
            /// <see cref="DXGINet::IDXGIFactory::MakeWindowAssociation"/>.
            /// </para>
            /// <para>
            /// Calling Present (or Present1) with this flag and not meeting the conditions above will
            /// result in a DXGI_ERROR_INVALID_CALL error being returned to the calling application.
            /// </para>
            /// </summary>
            ALLOW_TEARING = DXGI_PRESENT_ALLOW_TEARING
        };

        /// <summary>
        /// Describes a surface.
        /// </summary>
        public value struct DXGI_SURFACE_DESC
        {
            /// <summary>
            /// A value describing the surface width.
            /// </summary>
            unsigned int width;

            /// <summary>
            /// A value describing the surface height.
            /// </summary>
            unsigned int height;

            /// <summary>
            /// A member of the <see cref="DXGINet::DXGI_FORMAT"/> enumerated type that describes the
            /// surface format.
            /// </summary>
            DXGINet::DXGI_FORMAT format;

            /// <summary>
            /// A member of the <see cref="DXGINet::DXGI_SAMPLE_DESC"/> structure that describes
            /// multi-sampling parameters for the surface.
            /// </summary>
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

        /// <summary>
        /// Describes a mapped rectangle that is used to access a surface.
        /// </summary>
        public value struct DXGI_MAPPED_RECT
        {
            /// <summary>
            /// A value that describes the width, in bytes, of the surface.
            /// </summary>
            int pitch;

            /// <summary>
            /// A pointer to the image buffer of the surface.
            /// </summary>
            unsigned char *pBits;

            static operator DXGINet::DXGI_MAPPED_RECT(::DXGI_MAPPED_RECT %rhs)
            {
                DXGINet::DXGI_MAPPED_RECT value;
                value.pitch = rhs.Pitch;
                value.pBits = rhs.pBits;

                return value;
            }
        };

        /// <summary>
        /// CPU read-write flags of the mapped rectangle.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DXGI_MAP : UINT
        {
            /// <summary>
            /// No flags.
            /// </summary>
            NONE = 0U,

            /// <summary>
            /// Allow CPU read access.
            /// </summary>
            READ = DXGI_MAP_READ,

            /// <summary>
            /// Allow CPU write access.
            /// </summary>
            WRITE = DXGI_MAP_WRITE,

            /// <summary>
            /// Discard the previous contents of a resource when it is mapped.
            /// </summary>
            DISCARD = DXGI_MAP_DISCARD
        };

        /// <summary>
        /// Describes timing and presentation statistics for a frame.
        /// </summary>
        public value struct DXGI_FRAME_STATISTICS
        {
            /// <summary>
            /// A value that represents the running total count of times that an image was presented to
            /// the monitor since the computer booted.
            /// </summary>
            unsigned int presentCount;

            /// <summary>
            /// A value that represents the running total count of v-blanks at which the last image was
            /// presented to the monitor and that have happened since the computer booted (for windowed mode,
            /// since the swap chain was created).
            /// </summary>
            unsigned int presentRefreshCount;

            /// <summary>
            /// A value that represents the running total count of v-blanks when the scheduler last sampled
            /// the machine time by calling QueryPerformanceCounter and that have happened since the
            /// computer booted (for windowed mode, since the swap chain was created).
            /// </summary>
            unsigned int syncRefreshCount;

            /// <summary>
            /// A value that represents the high-resolution performance counter timer. This value is the
            /// same as the value returned by the QueryPerformanceCounter function.
            /// </summary>
            D2DNet::LARGE_INTEGER syncQPCTime;

            /// <summary>
            /// Reserved. Always returns 0.
            /// </summary>
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

        /// <summary>
        /// Flags related to window association.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DXGI_MWA : UINT
        {
            /// <summary>
            /// No flags.
            /// </summary>
            NONE = 0U,

            /// <summary>
            /// Prevent DXGI from monitoring an applications message queue; this makes DXGI unable to
            /// respond to mode changes.
            /// </summary>
            NO_WINDOW_CHANGES = DXGI_MWA_NO_WINDOW_CHANGES,

            /// <summary>
            /// Prevent DXGI from responding to an alt-enter sequence.
            /// </summary>
            NO_ALT_ENTER = DXGI_MWA_NO_ALT_ENTER,

            /// <summary>
            /// Prevent DXGI from responding to a print-screen key.
            /// </summary>
            NO_PRINT_SCREEN = DXGI_MWA_NO_PRINT_SCREEN
        };

        /// <summary>
        /// Flags that indicate how the back buffers should be rotated to fit the physical rotation of
        /// a monitor.
        /// </summary>
        public enum class DXGI_MODE_ROTATION
        {
            /// <summary>
            /// Unspecified rotation.
            /// </summary>
            UNSPECIFIED = 0,

            /// <summary>
            /// Specifies no rotation.
            /// </summary>
            IDENTITY = 1,

            /// <summary>
            /// Specifies 90 degrees of rotation.
            /// </summary>
            ROTATE90 = 2,
            
            /// <summary>
            /// Specifies 180 degrees of rotation.
            /// </summary>
            ROTATE180 = 3,

            /// <summary>
            /// Specifies 270 degrees of rotation.
            /// </summary>
            ROTATE270 = 4
        };

        /// <summary>
        /// Describes an output or physical connection between the adapter (video card) and a device.
        /// </summary>
        public value struct DXGI_OUTPUT_DESC
        {
            /// <summary>
            /// A string that contains the name of the output device.
            /// </summary>
            System::String ^deviceName;

            /// <summary>
            /// A <see cref="D2DNet::RECT"/> structure containing the bounds of the output in desktop
            /// coordinates. Desktop coordinates depend on the dots per inch (DPI) of the desktop.
            /// </summary>
            D2DNet::RECT desktopCoordinates;

            /// <summary>
            /// True if the output is attached to the desktop; otherwise, false.
            /// </summary>
            bool attachedToDesktop;

            /// <summary>
            /// A member of the <see cref="DXGINet::DXGI_MODE_ROTATION"/> enumerated type describing on how
            /// an image is rotated bythe output.
            /// </summary>
            DXGINet::DXGI_MODE_ROTATION rotation;

            /// <summary>
            /// A handle that represents the display monitor.
            /// </summary>
            System::IntPtr monitor;

            static operator DXGINet::DXGI_OUTPUT_DESC(::DXGI_OUTPUT_DESC %rhs)
            {
                DXGINet::DXGI_OUTPUT_DESC value;

                size_t nameLen = wcslen(&rhs.DeviceName[0]);
                if(nameLen >= 32Ui64)
                {
                    WCHAR name[33] = { 0 };
                    wcscpy_s(&name[0], 32, &rhs.DeviceName[0]);
                    value.deviceName = marshal_as<System::String ^>(&name[0]);
                }
                else
                {
                    value.deviceName = marshal_as<System::String ^>(&rhs.DeviceName[0]);
                }
                value.desktopCoordinates = static_cast<D2DNet::RECT>(rhs.DesktopCoordinates);
                value.attachedToDesktop = System::Convert::ToBoolean(rhs.AttachedToDesktop);
                value.rotation = (DXGINet::DXGI_MODE_ROTATION)((int)rhs.Rotation);
                value.monitor = System::IntPtr(rhs.Monitor);

                return value;
            }
        };

        /// <summary>
        /// Options for enumerating display modes.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DXGI_ENUM_MODES : UINT
        {
            /// <summary>
            /// No options.
            /// </summary>
            NONE = 0U,

            /// <summary>
            /// Include interlaced modes.
            /// </summary>
            INTERLACED = DXGI_ENUM_MODES_INTERLACED,

            /// <summary>
            /// Include stretched-scaling modes.
            /// </summary>
            SCALING = DXGI_ENUM_MODES_SCALING,

            /// <summary>
            /// Include stereo modes.
            /// </summary>
            STEREO = DXGI_ENUM_MODES_STEREO,

            /// <summary>
            /// Include stereo modes that are hidden because the user has disabled stereo. Control
            /// panel applications can use this option to show stereo capabilities that have been disabled
            /// as part of a user interface that enables and disables stereo.
            /// </summary>
            DISABLED_STEREO = DXGI_ENUM_MODES_DISABLED_STEREO
        };

        /// <summary>
        /// Controls the gamma capabilities of an adapter.
        /// </summary>
        public value struct DXGI_GAMMA_CONTROL_CAPABILITIES
        {
            /// <summary>
            /// True if scaling and offset operations are supported during gamma correction; otherwise, false.
            /// </summary>
            bool scaleAndOffsetSupported;

            /// <summary>
            /// A value describing the maximum range of the control-point positions.
            /// </summary>
            float maxConvertedValue;

            /// <summary>
            /// A value describing the minimum range of the control-point positions.
            /// </summary>
            float minConvertedValue;

            /// <summary>
            /// An array of values describing control points; the maximum length of control points is 1025.
            /// </summary>
            array<float> ^controlPointPositions;

            static operator DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES(::DXGI_GAMMA_CONTROL_CAPABILITIES %rhs)
            {
                DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES value;
                value.scaleAndOffsetSupported = System::Convert::ToBoolean(rhs.ScaleAndOffsetSupported);
                value.maxConvertedValue = rhs.MaxConvertedValue;
                value.minConvertedValue = rhs.MinConvertedValue;
                value.controlPointPositions = gcnew array<float>(rhs.NumGammaControlPoints);

                if(rhs.NumGammaControlPoints > 0)
                {
                    pin_ptr<float> pPoints = &value.controlPointPositions[0];
                    memcpy_s(
                        (void *)pPoints,
                        rhs.NumGammaControlPoints * sizeof(float),
                        (void *)&rhs.ControlPointPositions[0],
                        1025 * sizeof(float)
                    );
                    pPoints = nullptr;
                }

                return value;
            }
        };

        /// <summary>
        /// Represents an RGB color.
        /// </summary>
        public value struct DXGI_RGB
        {
            /// <summary>
            /// A value representing the color of the red component. The range of this value is between 0
            /// and 1.
            /// </summary>
            float red;

            /// <summary>
            /// A value representing the color of the green component. The range of this value is between 0
            /// and 1.
            /// </summary>
            float green;

            /// <summary>
            /// A value representing the color of the blue component. The range of this value is between 0
            /// and 1.
            /// </summary>
            float blue;

            DXGI_RGB(float red, float green, float blue) : red(red), green(green), blue(blue) {}
        };

        /// <summary>
        /// Controls the settings of a gamma curve.
        /// </summary>
        public value struct DXGI_GAMMA_CONTROL
        {
            /// <summary>
            /// A <see cref="DXGINet::DXGI_RGB"/> structure with scalar values that are applied to rgb values
            /// before being sent to the gamma look up table.
            /// </summary>
            DXGINet::DXGI_RGB scale;

            /// <summary>
            /// A <see cref="DXGINet::DXGI_RGB"/> structure with offset values that are applied to rgb values
            /// before being sent to the gamma look up table.
            /// </summary>
            DXGINet::DXGI_RGB offset;

            /// <summary>
            /// An array of <see cref="DXGINet::DXGI_RGB"/> structures that control the points of a
            /// gamma curve.
            /// </summary>
            array<DXGINet::DXGI_RGB> ^gammaCurve;

            static operator DXGINet::DXGI_GAMMA_CONTROL(::DXGI_GAMMA_CONTROL %rhs)
            {
                DXGINet::DXGI_GAMMA_CONTROL value;
                value.scale = *(DXGINet::DXGI_RGB *)&rhs.Scale;
                value.offset = *(DXGINet::DXGI_RGB *)&rhs.Offset;
                value.gammaCurve = gcnew array<DXGINet::DXGI_RGB>(1025);

                pin_ptr<DXGINet::DXGI_RGB> pCurve = &value.gammaCurve[0];
                memcpy_s(
                    (void *)pCurve,
                    1025 * sizeof(DXGINet::DXGI_RGB),
                    (void *)&rhs.GammaCurve[0],
                    1025 * sizeof(::DXGI_RGB)
                );
                pCurve = nullptr;
                
                return value;
            }

            static operator ::DXGI_GAMMA_CONTROL(DXGINet::DXGI_GAMMA_CONTROL %rhs)
            {
                if(rhs.gammaCurve && rhs.gammaCurve->Length > 1025)
                    throw gcnew System::InvalidOperationException("The length of gamma curve of managed "
                        + "gamma control is over 1025.");

                ::DXGI_GAMMA_CONTROL value = { 0 };
                pin_ptr<DXGINet::DXGI_RGB> pScale = &rhs.scale;
                pin_ptr<DXGINet::DXGI_RGB> pOffset = &rhs.offset;
                value.Scale = *(::DXGI_RGB *)pScale;
                value.Offset = *(::DXGI_RGB *)pOffset;
                pScale = nullptr;
                pOffset = nullptr;

                if(rhs.gammaCurve && rhs.gammaCurve->Length > 0)
                {
                    pin_ptr<DXGINet::DXGI_RGB> pCurve = &rhs.gammaCurve[0];
                    memcpy_s(
                        (void *)&value.GammaCurve[0],
                        1025 * sizeof(::DXGI_RGB),
                        (void *)pCurve,
                        rhs.gammaCurve->Length * sizeof(DXGINet::DXGI_RGB)
                    );
                }

                return value;
            }
        };

        /// <summary>
        /// Flags indicating the memory location of a resource.
        /// </summary>
        public enum class DXGI_RESIDENCY
        {
            /// <summary>
            /// The resource is located in video memory.
            /// </summary>
            FULLY_RESIDENT = 1,

            /// <summary>
            /// At least some of the resource is located in CPU memory.
            /// </summary>
            RESIDENT_IN_SHARED_MEMORY = 2,

            /// <summary>
            /// At least some of the resource has been paged out to the hard drive.
            /// </summary>
            EVICTED_TO_DISK = 3
        };

        /// <summary>
        /// Flags indicating the GPU thread priority.
        /// </summary>
        public enum class DXGI_GPU_THREAD_PRIORITY : INT
        {
            /// <summary>
            /// Lowest priority(-7).
            /// </summary>
            NEG_7 = -7,
            NEG_6 = -6,
            NEG_5 = -5,
            NEG_4 = -4,
            NEG_3 = -3,
            NEG_2 = -2,
            NEG_1 = -1,

            /// <summary>
            /// Default priority(0).
            /// </summary>
            NORMAL = 0,
            POS_1 = 1,
            POS_2 = 2,
            POS_3 = 3,
            POS_4 = 4,
            POS_5 = 5,
            POS_6 = 6,

            /// <summary>
            /// Highest priority(7).
            /// </summary>
            POS_7 = 7
        };

        /// <summary>
        /// Pre-defined resource priority values.
        /// </summary>
        public ref class DXGI_RESOURCE_PRIORITY abstract sealed
        {
        public:
            /// <summary>
            /// The resource is unused and can be evicted as soon as another resource requires the memory
            /// that the resource occupies. 
            /// </summary>
            literal UINT MINIMUM = DXGI_RESOURCE_PRIORITY_MINIMUM;

            /// <summary>
            /// The eviction priority of the resource is low. The placement of the resource is not critical,
            /// and minimal work is performed to find a location for the resource. For example, if a GPU
            /// can render with a vertex buffer from either local or non-local memory with little difference
            /// in performance, that vertex buffer is low priority. Other more critical resources (for
            /// example, a render target or texture) can then occupy the faster memory. 
            /// </summary>
            literal UINT LOW = DXGI_RESOURCE_PRIORITY_LOW;

            /// <summary>
            /// The eviction priority of the resource is normal. The placement of the resource is important,
            /// but not critical, for performance. The resource is placed in its preferred location instead
            /// of a low-priority resource. 
            /// </summary>
            literal UINT NORMAL = DXGI_RESOURCE_PRIORITY_NORMAL;

            /// <summary>
            /// The eviction priority of the resource is high. The resource is placed in its preferred
            /// location instead of a low-priority or normal-priority resource. 
            /// </summary>
            literal UINT HIGH = DXGI_RESOURCE_PRIORITY_HIGH;

            /// <summary>
            /// The resource is evicted from memory only if there is no other way of resolving the
            /// memory requirement. 
            /// </summary>
            literal UINT MAXIMUM = DXGI_RESOURCE_PRIORITY_MAXIMUM;

            /// <summary>
            /// Checks if the user-defined priority is in range.
            /// </summary>
            /// <returns>
            /// True if the priority is in range. Otherwise, returns false.
            /// </returns>
            static bool IsPriorityInRange(UINT priority)
            {
                return priority >= MINIMUM && priority <= MAXIMUM;
            }
        };

        /// <summary>
        /// Specifies color space types.
        /// </summary>
        public enum class DXGI_COLOR_SPACE_TYPE
        {
            /// <summary>
            /// This is the standard definition for sRGB.
            /// Note that this is often implemented with a linear segment, but in that case the exponent
            /// is corrected to stay aligned with a gamma 2.2 curve.
            /// This is usually used with 8 or 10 bit color channels.
            /// </summary>
            RGB_FULL_G22_NONE_P709 = 0,

            /// <summary>
            /// This is the standard definition for scRGB, and is usually used with 16 bit integer,
            /// 16 bit floating point, or 32 bit floating point color channels.
            /// </summary>
            RGB_FULL_G10_NONE_P709 = 1,

            /// <summary>
            /// This is the standard definition for ITU-R Recommendation BT.709. Note that due to the
            /// inclusion of a linear segment, the transfer curve looks similar to a pure exponential gamma
            /// of 1.9.
            /// This is usually used with 8 or 10 bit color channels.
            /// </summary>
            RGB_STUDIO_G22_NONE_P709 = 2,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            RGB_STUDIO_G22_NONE_P2020 = 3,

            /// <summary>
            /// Reserved.
            /// </summary>
            RESERVED = 4,

            /// <summary>
            /// This definition is commonly used for JPG, and is usually used with 8, 10, or 12 bit
            /// color channels.
            /// </summary>
            YCBCR_FULL_G22_NONE_P709_X601 = 5,

            /// <summary>
            /// This definition is commonly used for MPEG2, and is usually used with 8, 10, or 12 bit
            /// color channels.
            /// </summary>
            YCBCR_STUDIO_G22_LEFT_P601 = 6,

            /// <summary>
            /// This is sometimes used for H.264 camera capture, and is usually used with 8, 10, or 12
            /// bit color channels.
            /// </summary>
            YCBCR_FULL_G22_LEFT_P601 = 7,

            /// <summary>
            /// This definition is commonly used for H.264 and HEVC, and is usually used with 8, 10, or 12
            /// bit color channels.
            /// </summary>
            YCBCR_STUDIO_G22_LEFT_P709 = 8,

            /// <summary>
            /// This is sometimes used for H.264 camera capture, and is usually used with 8, 10, or 12
            /// bit color channels.
            /// </summary>
            YCBCR_FULL_G22_LEFT_P709 = 9,

            /// <summary>
            /// This definition may be used by HEVC, and is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_G22_LEFT_P2020 = 10,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_FULL_G22_LEFT_P2020 = 11,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            RGB_FULL_G2084_NONE_P2020 = 12,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_G2084_LEFT_P2020 = 13,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            RGB_STUDIO_G2084_NONE_P2020 = 14,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_G22_TOPLEFT_P2020 = 15,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_G2084_TOPLEFT_P2020 = 16,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            RGB_FULL_G22_NONE_P2020 = 17,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_GHLG_TOPLEFT_P2020 = 18,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_FULL_GHLG_TOPLEFT_P2020 = 19,

            /// <summary>
            /// This is usually used with 8, 10, or 12 bit color channels.
            /// </summary>
            RGB_STUDIO_G24_NONE_P709 = 20,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            RGB_STUDIO_G24_NONE_P2020 = 21,

            /// <summary>
            /// This is usually used with 8, 10, or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_G24_LEFT_P709 = 22,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_G24_LEFT_P2020 = 23,

            /// <summary>
            /// This is usually used with 10 or 12 bit color channels.
            /// </summary>
            YCBCR_STUDIO_G24_TOPLEFT_P2020 = 24,

            /// <summary>
            /// A custom color definition is used.
            /// </summary>
            CUSTOM = 0xFFFFFFFF
        };
    }
}