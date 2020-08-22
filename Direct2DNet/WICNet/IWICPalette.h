#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICImagingFactory;
        ref class IWICBitmapSource;

        // Done.

        /// <summary>
        /// Exposes methods for accessing and building a color table, primarily for indexed pixel formats.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("00000040-a8f2-4877-ba0a-fd2b6645fb94")]
        public ref class IWICPalette : WICNet::IWICObject
        {
        internal:
            ::IWICPalette *m_pPalette;

            IWICPalette() : m_pPalette(nullptr) {}

            IWICPalette(WICNet::IWICImagingFactory ^factory);

        public:
            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pPalette;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Initializes the palette to one of the pre-defined palettes specified by
            /// <see cref="WICNet::WICBitmapPaletteType"/> and optionally adds a transparent color.
            /// </summary>
            /// <param name="paletteType">
            /// The desired pre-defined palette type.
            /// </param>
            /// <param name="addTransparentColor">
            /// The optional transparent color to add to the palette. If no transparent color is needed,
            /// use false. When initializing to a grayscale or black and white palette, set this parameter
            /// to false.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT InitializePredefined(
                WICNet::WICBitmapPaletteType paletteType,
                bool addTransparentColor
            );

            /// <summary>
            /// Initializes a palette to the custom color entries provided.
            /// </summary>
            /// <param name="colors">
            /// The color array.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            /// <remarks>
            /// <para>
            /// If a transparent color is required, provide it as part of the custom entries. To add
            /// a transparent value to the palette, its alpha value must be 0 (0x00RRGGBB).
            /// </para>
            /// <para>
            /// The entry count is limited to 256.
            /// </para>
            /// </remarks>
            HRESULT InitializeCustom(
                array<WICColor> ^colors
            );

            /// <summary>
            /// Initializes a palette using a computed optimized values based on the reference bitmap.
            /// </summary>
            /// <param name="surface">
            /// The source bitmap.
            /// </param>
            /// <param name="cCount">
            /// The number of colors to initialize the palette with.
            /// </param>
            /// <param name="addTransparentColor">
            /// A value to indicate whether to add a transparent color.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT InitializeFromBitmap(
                WICNet::IWICBitmapSource ^surface,
                UINT cCount,
                bool addTransparentColor
            );

            /// <summary>
            /// Initialize the palette based on a given palette.
            /// </summary>
            /// <param name="palette">
            /// The source palette.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT InitializeFromPalette(WICNet::IWICPalette ^palette);

            /// <summary>
            /// Retrieves the <see cref="WICNet::WICBitmapPaletteType"/> that describes the palette.
            /// </summary>
            /// <param name="paletteType">
            /// Parameter that receives the palette type of the bimtap(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetType(
                [OutAttribute] WICNet::WICBitmapPaletteType %paletteType
            );

            /// <summary>
            /// Retrieves the <see cref="WICNet::WICBitmapPaletteType"/> that describes the palette.
            /// </summary>
            /// <param name="paletteType">
            /// Parameter that receives the palette type of the bimtap(out parameter).
            /// </param>
            /// <returns>
            /// (HRESULT, <see cref="WICNet::WICBitmapPaletteType"/>) tuple. If this method succeeds,
            /// HRESULT is S_OK. Otherwise, it is an HRESULT error code.
            /// <see cref="WICNet::WICBitmapPaletteType"/> is the palette type of the bimtap.
            /// </returns>
            System::ValueTuple<HRESULT, WICNet::WICBitmapPaletteType> GetType();

            /// <summary>
            /// Retrieves the number of colors in the color table.
            /// </summary>
            /// <param name="paletteType">
            /// Parameter that receives the number of colors in the color table(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetColorCount(
                [OutAttribute] UINT %cCount
            );

            /// <summary>
            /// Retrieves the number of colors in the color table.
            /// </summary>
            /// <returns>
            /// (HRESULT, uint) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. uint is the number of colors in the color table.
            /// </returns>
            System::ValueTuple<HRESULT, UINT> GetColorCount();

            /// <summary>
            /// Fills out the supplied color array with the colors from the internal color table. The
            /// color array should be sized according to the return results from
            /// <see cref="WICNet::IWICPalette::GetColorCount"/>.
            /// </summary>
            /// <param name="colors">
            /// Array buffer that receives the colors of the palette.
            /// </param>
            /// <param name="paletteType">
            /// Parameter that receives the actual size needed to obtain the palette colors(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetColors(
                array<WICColor> ^colors,
                [OutAttribute] UINT %cActualColors
            );

            /// <summary>
            /// Retrieves a value that describes whether the palette is black and white.
            /// </summary>
            /// <param name="isBlackWhite">
            /// Parameter that receives a boolean value that indicates whether the palette is black and white
            /// (out parameter). true indicates that the palette is black and white; otherwise, false.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT IsBlackWhite(
                [OutAttribute] bool %isBlackWhite
            );

            /// <summary>
            /// Retrieves a value that describes whether the palette is black and white.
            /// </summary>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is a boolean value that indicates whether the palette is black
            /// and white. true indicates that the palette is black and white; otherwise, false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> IsBlackWhite();

            /// <summary>
            /// Retrieves a value that describes whether a palette is grayscale.
            /// </summary>
            /// <param name="isGrayscale">
            /// Parameter that receives a boolean value that indicates whether the palette is grayscale(out
            /// parameter). true indicates that the palette is grayscale; otherwise false.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT IsGrayscale(
                [OutAttribute] bool %isGrayscale
            );

            /// <summary>
            /// Retrieves a value that describes whether the palette is black and white.
            /// </summary>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is a boolean value that indicates whether the palette is grayscale.
            /// true indicates that the palette is grayscale; otherwise false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> IsGrayscale();

            /// <summary>
            /// Indicates whether the palette contains an entry that is non-opaque (that is, an entry with
            /// an alpha that is less than 1).
            /// </summary>
            /// <param name="hasAlpha">
            /// Parameter that receives true if the palette contains a transparent color; otherwise, false(out
            /// parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT HasAlpha(
                [OutAttribute] bool %hasAlpha
            );

            /// <summary>
            /// Retrieves a value that describes whether the palette is black and white.
            /// </summary>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is true if the palette contains a transparent color; otherwise, false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> HasAlpha();
        };
    }
}