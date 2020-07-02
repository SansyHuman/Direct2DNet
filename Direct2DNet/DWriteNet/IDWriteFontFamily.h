#pragma once

#include <msclr/marshal.h>

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDWriteFontList.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFontCollection;
        ref class IDWriteLocalizedStrings;
        ref class IDWriteFont;

        /// <summary>
        /// The IDWriteFontFamily interface represents a set of fonts that share the same design but are differentiated
        /// by weight, stretch, and style.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("da20d8ef-812a-4c43-9802-62ec4abd7add")]
        public ref class IDWriteFontFamily : DWriteNet::IDWriteFontList
        {
        internal:
            IDWriteFontFamily(::IDWriteFontFamily *pFamily, DWriteNet::IDWriteFontCollection ^fontCollection);

        public:

            /// <summary>
            /// Creates a localized strings object that contains the family names for the font family, indexed by locale name.
            /// </summary>
            /// <param name="names">Receives the newly created localized strings object(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFamilyNames(
                [OutAttribute] DWriteNet::IDWriteLocalizedStrings ^%names
            );

            /// <summary>
            /// Creates a localized strings object that contains the family names for the font family, indexed by locale name.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteLocalizedStrings"/>) tuple.
            /// HRESULT is an error code. <see cref="DWriteNet::IDWriteLocalizedStrings"/> is the localized
            /// strings object. If an error occurs, <see cref="DWriteNet::IDWriteLocalizedStrings"/> is null.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^> GetFamilyNames();

            /// <summary>
            /// Gets the font that best matches the specified properties.
            /// </summary>
            /// <param name="weight">Requested font weight.</param>
            /// <param name="stretch">Requested font stretch.</param>
            /// <param name="style">Requested font style.</param>
            /// <param name="matchingFont">Receives the newly created font object(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFirstMatchingFont(
                DWriteNet::DWRITE_FONT_WEIGHT weight,
                DWriteNet::DWRITE_FONT_STRETCH stretch,
                DWriteNet::DWRITE_FONT_STYLE style,
                [OutAttribute] DWriteNet::IDWriteFont ^%matchingFont
            );

            /// <summary>
            /// Gets the font that best matches the specified properties.
            /// </summary>
            /// <param name="weight">Requested font weight.</param>
            /// <param name="stretch">Requested font stretch.</param>
            /// <param name="style">Requested font style.</param>
            /// <param name="matchingFont">Receives the newly created font object(out parameter).</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteFont"/>) tuple.
            /// HRESULT is an error code. if failed, <see cref="DWriteNet::IDWriteFont"/> is null.
            /// <see cref="DWriteNet::IDWriteFont"/> is the newly created font.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^> GetFirstMatchingFont(
                DWriteNet::DWRITE_FONT_WEIGHT weight,
                DWriteNet::DWRITE_FONT_STRETCH stretch,
                DWriteNet::DWRITE_FONT_STYLE style
            );

            /// <summary>
            /// Gets a list of fonts in the font family ranked in order of how well they match the specified properties.
            /// </summary>
            /// <param name="weight">Requested font weight.</param>
            /// <param name="stretch">Requested font stretch.</param>
            /// <param name="style">Requested font style.</param>
            /// <param name="matchingFonts">Receives the newly created font list object(out parameter).
            /// If failed, matchingFonts is null.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetMatchingFonts(
                DWriteNet::DWRITE_FONT_WEIGHT weight,
                DWriteNet::DWRITE_FONT_STRETCH stretch,
                DWriteNet::DWRITE_FONT_STYLE style,
                [OutAttribute] DWriteNet::IDWriteFontList ^%matchingFonts
            );

            /// <summary>
            /// Gets a list of fonts in the font family ranked in order of how well they match the specified properties.
            /// </summary>
            /// <param name="weight">Requested font weight.</param>
            /// <param name="stretch">Requested font stretch.</param>
            /// <param name="style">Requested font style.</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteFontList"/>) tuple.
            /// HRESULT is an error code. if failed, <see cref="DWriteNet::IDWriteFontList"/> is null.
            /// <see cref="DWriteNet::IDWriteFontList"/> is the newly created font list.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteFontList ^> GetMatchingFonts(
                DWriteNet::DWRITE_FONT_WEIGHT weight,
                DWriteNet::DWRITE_FONT_STRETCH stretch,
                DWriteNet::DWRITE_FONT_STYLE style
            );
        };
    }
}