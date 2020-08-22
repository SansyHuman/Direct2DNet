#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "IWICBitmapSource.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICImagingFactory;
        ref class IWICPalette;

        // Done.

        /// <summary>
        /// Represents an IWICBitmapSource that converts the image data from one pixel format to another,
        /// handling dithering and halftoning to indexed formats, palette translation and alpha thresholding.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("00000301-a8f2-4877-ba0a-fd2b6645fb94")]
        public ref class IWICFormatConverter : WICNet::IWICBitmapSource
        {
        internal:
            IWICFormatConverter() : WICNet::IWICBitmapSource() {}

            IWICFormatConverter(WICNet::IWICImagingFactory ^factory);

        public:
            /// <summary>
            /// Initializes the format converter.
            /// </summary>
            /// <param name="source">
            /// The input bitmap to convert.
            /// </param>
            /// <param name="dstFormat">
            /// The destination pixel format GUID. The list of built-in format GUIDs are in
            /// <see cref="WICNet::PixelFormatGUID"/> class.
            /// </param>
            /// <param name="dither">
            /// The <see cref="WICNet::WICBitmapDitherType"/> used for conversion.
            /// </param>
            /// <param name="alphaThresholdPercent">
            /// The alpha threshold to use for conversion.
            /// </param>
            /// <param name="paletteTranslate">
            /// The palette translation type to use for conversion.
            /// </param>
            /// <param name="palette">
            /// The optional palette to use for conversion. The default value is null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT Initialize(
                WICNet::IWICBitmapSource ^source,
                [InAttribute][IsReadOnlyAttribute] System::Guid %dstFormat,
                WICNet::WICBitmapDitherType dither,
                double alphaThresholdPercent,
                WICNet::WICBitmapPaletteType paletteTranslate,
                [OptionalAttribute] WICNet::IWICPalette ^palette
            );

            /// <summary>
            /// Determines if the source pixel format can be converted to the destination pixel format.
            /// </summary>
            /// <param name="srcPixelFormat">
            /// The source pixel format.
            /// </param>
            /// <param name="dstPixelFormat">
            /// The destionation pixel format.
            /// </param>
            /// <param name="canConvert">
            /// A parameter that receives a value indicating whether the source pixel format can be
            /// converted to the destination pixel format(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT CanConvert(
                [InAttribute][IsReadOnlyAttribute] System::Guid %srcPixelFormat,
                [InAttribute][IsReadOnlyAttribute] System::Guid %dstPixelFormat,
                [OutAttribute] bool %canConvert
            );

            /// <summary>
            /// Determines if the source pixel format can be converted to the destination pixel format.
            /// </summary>
            /// <param name="srcPixelFormat">
            /// The source pixel format.
            /// </param>
            /// <param name="dstPixelFormat">
            /// The destionation pixel format.
            /// </param>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is whether the source pixel format can be converted to the destination
            /// pixel format.
            /// </returns>
            System::ValueTuple<HRESULT, bool> CanConvert(
                [InAttribute][IsReadOnlyAttribute] System::Guid %srcPixelFormat,
                [InAttribute][IsReadOnlyAttribute] System::Guid %dstPixelFormat
            );
        };
    }
}