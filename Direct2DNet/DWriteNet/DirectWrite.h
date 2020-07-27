#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        public ref class DirectWrite abstract sealed
        {
        public:

            /// <summary>
            /// Creates an OpenType tag as a 32bit integer such that
            /// the first character in the tag is the lowest byte,
            /// (least significant on little endian architectures)
            /// which can be used to compare with tags in the font file.
            /// This method is compatible with <see cref="DirectWrite::MakeFontFeatureTag"/>.
            ///
            /// Example: DWRITE_MAKE_OPENTYPE_TAG('c','c','m','p')
            /// Dword:   0x706D6363
            /// </summary>
            static UINT32 MakeOpentypeTag(wchar_t a, wchar_t b, wchar_t c, wchar_t d);

            /// <summary>
            /// Creates an OpenType tag for glyph positioning and substitution font features.
            /// </summary>
            static UINT32 MakeFontFeatureTag(wchar_t a, wchar_t b, wchar_t c, wchar_t d);

            /// <summary>
            /// Creates an 4-byte integer expression or rgb color. The range of each channel is 0 to 255.
            /// </summary>
            static COLORREF MakeRGB(BYTE r, BYTE g, BYTE b);
        };
    }
}