#pragma once

#include "DWNetHeaders.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        value struct D2D1_MATRIX_3X2_F;
    }

    namespace DWriteNet
    {
#ifdef NEAR
#undef NEAR
#endif

#ifdef FAR
#undef FAR
#endif

        /// <summary>
        /// Specifies the type of DirectWrite factory object.
        /// </summary>
        public enum class DWRITE_FACTORY_TYPE
        {
            /// <summary>
            /// Shared factory allow for re-use of cached font data across multiple in process components.
            /// Such factories also take advantage of cross process font caching components for better performance.
            /// </summary>
            SHARED = ::DWRITE_FACTORY_TYPE_SHARED,

            /// <summary>
            /// Objects created from the isolated factory do not interact with internal DirectWrite state from other components.
            /// </summary>
            ISOLATED = ::DWRITE_FACTORY_TYPE_ISOLATED
        };

        /// <summary>
        /// The font weight enumeration describes common values for degree of blackness or thickness of strokes of characters in a font.
        /// Font weight values less than 1 or greater than 999 are considered to be invalid, and they are rejected by font API functions.
        /// </summary>
        public enum class DWRITE_FONT_WEIGHT
        {
            /// <summary>
            /// Predefined font weight : Thin (100).
            /// </summary>
            THIN = 100,

            /// <summary>
            /// Predefined font weight : Extra-light (200).
            /// </summary>
            EXTRA_LIGHT = 200,

            /// <summary>
            /// Predefined font weight : Ultra-light (200).
            /// </summary>
            ULTRA_LIGHT = 200,

            /// <summary>
            /// Predefined font weight : Light (300).
            /// </summary>
            LIGHT = 300,

            /// <summary>
            /// Predefined font weight : Semi-light (350).
            /// </summary>
            SEMI_LIGHT = 350,

            /// <summary>
            /// Predefined font weight : Normal (400).
            /// </summary>
            NORMAL = 400,

            /// <summary>
            /// Predefined font weight : Regular (400).
            /// </summary>
            REGULAR = 400,

            /// <summary>
            /// Predefined font weight : Medium (500).
            /// </summary>
            MEDIUM = 500,

            /// <summary>
            /// Predefined font weight : Demi-bold (600).
            /// </summary>
            DEMI_BOLD = 600,

            /// <summary>
            /// Predefined font weight : Semi-bold (600).
            /// </summary>
            SEMI_BOLD = 600,

            /// <summary>
            /// Predefined font weight : Bold (700).
            /// </summary>
            BOLD = 700,

            /// <summary>
            /// Predefined font weight : Extra-bold (800).
            /// </summary>
            EXTRA_BOLD = 800,

            /// <summary>
            /// Predefined font weight : Ultra-bold (800).
            /// </summary>
            ULTRA_BOLD = 800,

            /// <summary>
            /// Predefined font weight : Black (900).
            /// </summary>
            BLACK = 900,

            /// <summary>
            /// Predefined font weight : Heavy (900).
            /// </summary>
            HEAVY = 900,

            /// <summary>
            /// Predefined font weight : Extra-black (950).
            /// </summary>
            EXTRA_BLACK = 950,

            /// <summary>
            /// Predefined font weight : Ultra-black (950).
            /// </summary>
            ULTRA_BLACK = 950
        };

        /// <summary>
        /// The font style enumeration describes the slope style of a font face, such as Normal, Italic or Oblique.
        /// Values other than the ones defined in the enumeration are considered to be invalid, and they are rejected by font API functions.
        /// </summary>
        public enum class DWRITE_FONT_STYLE
        {
            /// <summary>
            /// Font slope style : Normal.
            /// </summary>
            NORMAL = ::DWRITE_FONT_STYLE_NORMAL,

            /// <summary>
            /// Font slope style : Oblique.
            /// </summary>
            OBLIQUE = ::DWRITE_FONT_STYLE_OBLIQUE,

            /// <summary>
            /// Font slope style : Italic.
            /// </summary>
            ITALIC = ::DWRITE_FONT_STYLE_ITALIC
        };

        /// <summary>
        /// The font stretch enumeration describes relative change from the normal aspect ratio
        /// as specified by a font designer for the glyphs in a font.
        /// Values less than 1 or greater than 9 are considered to be invalid, and they are rejected by font API functions.
        /// </summary>
        public enum class DWRITE_FONT_STRETCH
        {
            /// <summary>
            /// Predefined font stretch : Not known (0).
            /// </summary>
            UNDEFINED = 0,

            /// <summary>
            /// Predefined font stretch : Ultra-condensed (1).
            /// </summary>
            ULTRA_CONDENSED = 1,

            /// <summary>
            /// Predefined font stretch : Extra-condensed (2).
            /// </summary>
            EXTRA_CONDENSED = 2,

            /// <summary>
            /// Predefined font stretch : Condensed (3).
            /// </summary>
            CONDENSED = 3,

            /// <summary>
            /// Predefined font stretch : Semi-condensed (4).
            /// </summary>
            SEMI_CONDENSED = 4,

            /// <summary>
            /// Predefined font stretch : Normal (5).
            /// </summary>
            NORMAL = 5,

            /// <summary>
            /// Predefined font stretch : Medium (5).
            /// </summary>
            MEDIUM = 5,

            /// <summary>
            /// Predefined font stretch : Semi-expanded (6).
            /// </summary>
            SEMI_EXPANDED = 6,

            /// <summary>
            /// Predefined font stretch : Expanded (7).
            /// </summary>
            EXPANDED = 7,

            /// <summary>
            /// Predefined font stretch : Extra-expanded (8).
            /// </summary>
            EXTRA_EXPANDED = 8,

            /// <summary>
            /// Predefined font stretch : Ultra-expanded (9).
            /// </summary>
            ULTRA_EXPANDED = 9
        };

        /// <summary>
        /// Alignment of paragraph text along the reading direction axis relative to 
        /// the leading and trailing edge of the layout box.
        /// </summary>
        public enum class DWRITE_TEXT_ALIGNMENT
        {
            /// <summary>
            /// The leading edge of the paragraph text is aligned to the layout box's leading edge.
            /// </summary>
            LEADING = ::DWRITE_TEXT_ALIGNMENT_LEADING,

            /// <summary>
            /// The trailing edge of the paragraph text is aligned to the layout box's trailing edge.
            /// </summary>
            TRAILING = ::DWRITE_TEXT_ALIGNMENT_TRAILING,

            /// <summary>
            /// The center of the paragraph text is aligned to the center of the layout box.
            /// </summary>
            CENTER = ::DWRITE_TEXT_ALIGNMENT_CENTER,

            /// <summary>
            /// Align text to the leading side, and also justify text to fill the lines.
            /// </summary>
            JUSTIFIED = ::DWRITE_TEXT_ALIGNMENT_JUSTIFIED
        };

        /// <summary>
        /// Alignment of paragraph text along the flow direction axis relative to the
        /// flow's beginning and ending edge of the layout box.
        /// </summary>
        public enum class DWRITE_PARAGRAPH_ALIGNMENT
        {
            /// <summary>
            /// The first line of paragraph is aligned to the flow's beginning edge of the layout box.
            /// </summary>
            NEAR = ::DWRITE_PARAGRAPH_ALIGNMENT_NEAR,

            /// <summary>
            /// The last line of paragraph is aligned to the flow's ending edge of the layout box.
            /// </summary>
            FAR = ::DWRITE_PARAGRAPH_ALIGNMENT_FAR,

            /// <summary>
            /// The center of the paragraph is aligned to the center of the flow of the layout box.
            /// </summary>
            CENTER = ::DWRITE_PARAGRAPH_ALIGNMENT_CENTER
        };

        /// <summary>
        /// Word wrapping in multiline paragraph.
        /// </summary>
        public enum class DWRITE_WORD_WRAPPING
        {
            /// <summary>
            /// Words are broken across lines to avoid text overflowing the layout box.
            /// </summary>
            WRAP = 0,

            /// <summary>
            /// Words are kept within the same line even when it overflows the layout box.
            /// This option is often used with scrolling to reveal overflow text. 
            /// </summary>
            NO_WRAP = 1,

            /// <summary>
            /// Words are broken across lines to avoid text overflowing the layout box.
            /// Emergency wrapping occurs if the word is larger than the maximum width.
            /// </summary>
            EMERGENCY_BREAK = 2,

            /// <summary>
            /// Only wrap whole words, never breaking words (emergency wrapping) when the
            /// layout width is too small for even a single word.
            /// </summary>
            WHOLE_WORD = 3,

            /// <summary>
            /// Wrap between any valid characters clusters.
            /// </summary>
            CHARACTER = 4,
        };

        /// <summary>
        /// Direction for how reading progresses.
        /// </summary>
        public enum class DWRITE_READING_DIRECTION
        {
            /// <summary>
            /// Reading progresses from left to right.
            /// </summary>
            LEFT_TO_RIGHT = 0,

            /// <summary>
            /// Reading progresses from right to left.
            /// </summary>
            RIGHT_TO_LEFT = 1,

            /// <summary>
            /// Reading progresses from top to bottom.
            /// </summary>
            TOP_TO_BOTTOM = 2,

            /// <summary>
            /// Reading progresses from bottom to top.
            /// </summary>
            BOTTOM_TO_TOP = 3,
        };

        /// <summary>
        /// Direction for how lines of text are placed relative to one another.
        /// </summary>
        public enum class DWRITE_FLOW_DIRECTION
        {
            /// <summary>
            /// Text lines are placed from top to bottom.
            /// </summary>
            TOP_TO_BOTTOM = 0,

            /// <summary>
            /// Text lines are placed from bottom to top.
            /// </summary>
            BOTTOM_TO_TOP = 1,

            /// <summary>
            /// Text lines are placed from left to right.
            /// </summary>
            LEFT_TO_RIGHT = 2,

            /// <summary>
            /// Text lines are placed from right to left.
            /// </summary>
            RIGHT_TO_LEFT = 3,
        };

        /// <summary>
        /// Text granularity used to trim text overflowing the layout box.
        /// </summary>
        public enum class DWRITE_TRIMMING_GRANULARITY
        {
            /// <summary>
            /// No trimming occurs. Text flows beyond the layout width.
            /// </summary>
            NONE = ::DWRITE_TRIMMING_GRANULARITY_NONE,

            /// <summary>
            /// Trimming occurs at character cluster boundary.
            /// </summary>
            CHARACTER = ::DWRITE_TRIMMING_GRANULARITY_CHARACTER,

            /// <summary>
            /// Trimming occurs at word boundary.
            /// </summary>
            WORD = ::DWRITE_TRIMMING_GRANULARITY_WORD
        };

        /// <summary>
        /// The DWRITE_TRIMMING structure specifies the trimming option for text overflowing the layout box.
        /// </summary>
        public value struct DWRITE_TRIMMING
        {
            /// <summary>
            /// Text granularity of which trimming applies.
            /// </summary>
            DWriteNet::DWRITE_TRIMMING_GRANULARITY granularity;

            /// <summary>
            /// Character code used as the delimiter signaling the beginning of the portion of text to be preserved,
            /// most useful for path ellipsis, where the delimiter would be a slash. Leave this zero if there is no
            /// delimiter.
            /// </summary>
            unsigned int delimiter;

            /// <summary>
            /// How many occurrences of the delimiter to step back. Leave this zero if there is no delimiter.
            /// </summary>
            unsigned int delimiterCount;

            DWRITE_TRIMMING(
                DWriteNet::DWRITE_TRIMMING_GRANULARITY granularity,
                unsigned int delimiter,
                unsigned int delimiterCount
            ) : granularity(granularity), delimiter(delimiter), delimiterCount(delimiterCount) {}

            static operator ::DWRITE_TRIMMING(DWriteNet::DWRITE_TRIMMING %rhs)
            {
                ::DWRITE_TRIMMING value;
                value.granularity = (::DWRITE_TRIMMING_GRANULARITY)((int)rhs.granularity);
                value.delimiter = rhs.delimiter;
                value.delimiterCount = rhs.delimiterCount;

                return value;
            }

            static operator DWriteNet::DWRITE_TRIMMING(::DWRITE_TRIMMING %rhs)
            {
                DWriteNet::DWRITE_TRIMMING value;
                value.granularity = (DWriteNet::DWRITE_TRIMMING_GRANULARITY)((int)rhs.granularity);
                value.delimiter = rhs.delimiter;
                value.delimiterCount = rhs.delimiterCount;

                return value;
            }
        };

        /// <summary>
        /// The method used for line spacing in layout.
        /// </summary>
        public enum class DWRITE_LINE_SPACING_METHOD
        {
            /// <summary>
            /// Line spacing depends solely on the content, growing to accommodate the size of fonts and inline objects.
            /// </summary>
            DEFAULT = ::DWRITE_LINE_SPACING_METHOD_DEFAULT,

            /// <summary>
            /// Lines are explicitly set to uniform spacing, regardless of contained font sizes.
            /// This can be useful to avoid the uneven appearance that can occur from font fallback.
            /// </summary>
            UNIFORM = ::DWRITE_LINE_SPACING_METHOD_UNIFORM,

            /// <summary>
            /// Line spacing and baseline distances are proportional to the computed values based on the content, the size of the fonts and inline objects.
            /// </summary>
            PROPORTIONAL = ::DWRITE_LINE_SPACING_METHOD_PROPORTIONAL
        };

        /// <summary>
        /// The measuring method used for text layout.
        /// </summary>
        public enum class DWRITE_MEASURING_MODE
        {
            /// <summary>
            /// Text is measured using glyph ideal metrics whose values are independent to the current display resolution.
            /// </summary>
            NATURAL = ::DWRITE_MEASURING_MODE_NATURAL,

            /// <summary>
            /// Text is measured using glyph display compatible metrics whose values tuned for the current display resolution.
            /// </summary>
            GDI_CLASSIC = ::DWRITE_MEASURING_MODE_GDI_CLASSIC,

            /// <summary>
            // Text is measured using the same glyph display metrics as text measured by GDI using a font
            // created with CLEARTYPE_NATURAL_QUALITY.
            /// </summary>
            GDI_NATURAL = ::DWRITE_MEASURING_MODE_GDI_NATURAL
        };

        /// <summary>
        /// Represents the internal structure of a device pixel (i.e., the physical arrangement of red,
        /// green, and blue color components) that is assumed for purposes of rendering text.
        /// </summary>
        public enum class DWRITE_PIXEL_GEOMETRY
        {
            /// <summary>
            /// The red, green, and blue color components of each pixel are assumed to occupy the same point.
            /// </summary>
            FLAT = ::DWRITE_PIXEL_GEOMETRY_FLAT,

            /// <summary>
            /// Each pixel comprises three vertical stripes, with red on the left, green in the center, and 
            /// blue on the right. This is the most common pixel geometry for LCD monitors.
            /// </summary>
            RGB = ::DWRITE_PIXEL_GEOMETRY_RGB,

            /// <summary>
            /// Each pixel comprises three vertical stripes, with blue on the left, green in the center, and 
            /// red on the right.
            /// </summary>
            BGR = ::DWRITE_PIXEL_GEOMETRY_BGR
        };

        /// <summary>
        /// Represents a method of rendering glyphs.
        /// </summary>
        public enum class DWRITE_RENDERING_MODE
        {
            /// <summary>
            /// Specifies that the rendering mode is determined automatically based on the font and size.
            /// </summary>
            DEFAULT = ::DWRITE_RENDERING_MODE_DEFAULT,

            /// <summary>
            /// Specifies that no antialiasing is performed. Each pixel is either set to the foreground 
            /// color of the text or retains the color of the background.
            /// </summary>
            ALIASED = ::DWRITE_RENDERING_MODE_ALIASED,

            /// <summary>
            /// Specifies that antialiasing is performed in the horizontal direction and the appearance
            /// of glyphs is layout-compatible with GDI using CLEARTYPE_QUALITY. Use DWRITE_MEASURING_MODE_GDI_CLASSIC 
            /// to get glyph advances. The antialiasing may be either ClearType or grayscale depending on
            /// the text antialiasing mode.
            /// </summary>
            GDI_CLASSIC = ::DWRITE_RENDERING_MODE_GDI_CLASSIC,

            /// <summary>
            /// Specifies that antialiasing is performed in the horizontal direction and the appearance
            /// of glyphs is layout-compatible with GDI using CLEARTYPE_NATURAL_QUALITY. Glyph advances
            /// are close to the font design advances, but are still rounded to whole pixels. Use
            /// DWRITE_MEASURING_MODE_GDI_NATURAL to get glyph advances. The antialiasing may be either
            /// ClearType or grayscale depending on the text antialiasing mode.
            /// </summary>
            GDI_NATURAL = ::DWRITE_RENDERING_MODE_GDI_NATURAL,

            /// <summary>
            /// Specifies that antialiasing is performed in the horizontal direction. This rendering
            /// mode allows glyphs to be positioned with subpixel precision and is therefore suitable
            /// for natural (i.e., resolution-independent) layout. The antialiasing may be either
            /// ClearType or grayscale depending on the text antialiasing mode.
            /// </summary>
            NATURAL = ::DWRITE_RENDERING_MODE_NATURAL,

            /// <summary>
            /// Similar to natural mode except that antialiasing is performed in both the horizontal
            /// and vertical directions. This is typically used at larger sizes to make curves and
            /// diagonal lines look smoother. The antialiasing may be either ClearType or grayscale
            /// depending on the text antialiasing mode.
            /// </summary>
            NATURAL_SYMMETRIC = ::DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC,

            /// <summary>
            /// Specifies that rendering should bypass the rasterizer and use the outlines directly. 
            /// This is typically used at very large sizes.
            /// </summary>
            OUTLINE = ::DWRITE_RENDERING_MODE_OUTLINE,

            [System::ObsoleteAttribute("The following names are obsolete, but are kept as aliases to avoid breaking existing code. Each of these rendering modes may result in either ClearType or grayscale antialiasing depending on the DWRITE_TEXT_ANTIALIASING_MODE.", false)]
            CLEARTYPE_GDI_CLASSIC = ::DWRITE_RENDERING_MODE_GDI_CLASSIC,

            [System::ObsoleteAttribute("The following names are obsolete, but are kept as aliases to avoid breaking existing code. Each of these rendering modes may result in either ClearType or grayscale antialiasing depending on the DWRITE_TEXT_ANTIALIASING_MODE.", false)]
            CLEARTYPE_GDI_NATURAL = ::DWRITE_RENDERING_MODE_GDI_NATURAL,
            
            [System::ObsoleteAttribute("The following names are obsolete, but are kept as aliases to avoid breaking existing code. Each of these rendering modes may result in either ClearType or grayscale antialiasing depending on the DWRITE_TEXT_ANTIALIASING_MODE.", false)]
            CLEARTYPE_NATURAL = ::DWRITE_RENDERING_MODE_NATURAL,

            [System::ObsoleteAttribute("The following names are obsolete, but are kept as aliases to avoid breaking existing code. Each of these rendering modes may result in either ClearType or grayscale antialiasing depending on the DWRITE_TEXT_ANTIALIASING_MODE.", false)]
            CLEARTYPE_NATURAL_SYMMETRIC = ::DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC
        };

        /// <summary>
        /// Specifies algorithmic style simulations to be applied to the font face.
        /// Bold and oblique simulations can be combined via bitwise OR operation.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DWRITE_FONT_SIMULATIONS
        {
            /// <summary>
            /// No simulations are performed.
            /// </summary>
            NONE = 0x0000,

            /// <summary>
            /// Algorithmic emboldening is performed.
            /// </summary>
            BOLD = 0x0001,

            /// <summary>
            /// Algorithmic italicization is performed.
            /// </summary>
            OBLIQUE = 0x0002
        };

        /// <summary>
        /// The informational string enumeration identifies a string in a font.
        /// </summary>
        public enum class DWRITE_INFORMATIONAL_STRING_ID
        {
            /// <summary>
            /// Unspecified name ID.
            /// </summary>
            NONE = ::DWRITE_INFORMATIONAL_STRING_NONE,

            /// <summary>
            /// Copyright notice provided by the font.
            /// </summary>
            COPYRIGHT_NOTICE = ::DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE,

            /// <summary>
            /// String containing a version number.
            /// </summary>
            VERSION_STRINGS = ::DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS,

            /// <summary>
            /// Trademark information provided by the font.
            /// </summary>
            TRADEMARK = ::DWRITE_INFORMATIONAL_STRING_TRADEMARK,

            /// <summary>
            /// Name of the font manufacturer.
            /// </summary>
            MANUFACTURER = ::DWRITE_INFORMATIONAL_STRING_MANUFACTURER,

            /// <summary>
            /// Name of the font designer.
            /// </summary>
            DESIGNER = ::DWRITE_INFORMATIONAL_STRING_DESIGNER,

            /// <summary>
            /// URL of font designer (with protocol, e.g., http://, ftp://).
            /// </summary>
            DESIGNER_URL = ::DWRITE_INFORMATIONAL_STRING_DESIGNER_URL,

            /// <summary>
            /// Description of the font. Can contain revision information, usage recommendations, history, features, etc.
            /// </summary>
            DESCRIPTION = ::DWRITE_INFORMATIONAL_STRING_DESCRIPTION,

            /// <summary>
            /// URL of font vendor (with protocol, e.g., http://, ftp://). If a unique serial number is embedded in the URL, it can be used to register the font.
            /// </summary>
            FONT_VENDOR_URL = ::DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL,

            /// <summary>
            /// Description of how the font may be legally used, or different example scenarios for licensed use. This field should be written in plain language, not legalese.
            /// </summary>
            LICENSE_DESCRIPTION = ::DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION,

            /// <summary>
            /// URL where additional licensing information can be found.
            /// </summary>
            LICENSE_INFO_URL = ::DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL,

            /// <summary>
            /// GDI-compatible family name. Because GDI allows a maximum of four fonts per family, fonts in the same family may have different GDI-compatible family names
            /// (e.g., "Arial", "Arial Narrow", "Arial Black").
            /// </summary>
            WIN32_FAMILY_NAMES = ::DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES,

            /// <summary>
            /// GDI-compatible subfamily name.
            /// </summary>
            WIN32_SUBFAMILY_NAMES = ::DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES,

            /// <summary>
            /// Typographic family name preferred by the designer. This enables font designers to group more than four fonts in a single family without losing compatibility with
            /// GDI. This name is typically only present if it differs from the GDI-compatible family name.
            /// </summary>
            TYPOGRAPHIC_FAMILY_NAMES = ::DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES,

            /// <summary>
            /// Typographic subfamily name preferred by the designer. This name is typically only present if it differs from the GDI-compatible subfamily name. 
            /// </summary>
            TYPOGRAPHIC_SUBFAMILY_NAMES = ::DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES,

            /// <summary>
            /// Sample text. This can be the font name or any other text that the designer thinks is the best example to display the font in.
            /// </summary>
            SAMPLE_TEXT = ::DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT,

            /// <summary>
            /// The full name of the font, e.g. "Arial Bold", from name id 4 in the name table.
            /// </summary>
            FULL_NAME = ::DWRITE_INFORMATIONAL_STRING_FULL_NAME,

            /// <summary>
            /// The postscript name of the font, e.g. "GillSans-Bold" from name id 6 in the name table.
            /// </summary>
            POSTSCRIPT_NAME = ::DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME,

            /// <summary>
            /// The postscript CID findfont name, from name id 20 in the name table.
            /// </summary>
            POSTSCRIPT_CID_NAME = ::DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME,

            /// <summary>
            /// Family name for the weight-stretch-style model.
            /// </summary>
            WEIGHT_STRETCH_STYLE_FAMILY_NAME = ::DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME,

            /// <summary>
            /// Script/language tag to identify the scripts or languages that the font was
            /// primarily designed to support. See DWRITE_FONT_PROPERTY_ID_DESIGN_SCRIPT_LANGUAGE_TAG
            /// for a longer description.
            /// </summary>
            DESIGN_SCRIPT_LANGUAGE_TAG = ::DWRITE_INFORMATIONAL_STRING_DESIGN_SCRIPT_LANGUAGE_TAG,

            /// <summary>
            /// Script/language tag to identify the scripts or languages that the font declares
            /// it is able to support.
            /// </summary>
            SUPPORTED_SCRIPT_LANGUAGE_TAG = ::DWRITE_INFORMATIONAL_STRING_SUPPORTED_SCRIPT_LANGUAGE_TAG,

            [System::ObsoleteAttribute("Obsolete aliases kept to avoid breaking existing code.", false)]
            PREFERRED_FAMILY_NAMES = ::DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES,

            [System::ObsoleteAttribute("Obsolete aliases kept to avoid breaking existing code.", false)]
            PREFERRED_SUBFAMILY_NAMES = ::DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES,

            [System::ObsoleteAttribute("Obsolete aliases kept to avoid breaking existing code.", false)]
            WWS_FAMILY_NAME = ::DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME
        };

        /// <summary>
        /// The DWRITE_FONT_METRICS structure specifies the metrics of a font face that
        /// are applicable to all glyphs within the font face.
        /// </summary>
        public value struct DWRITE_FONT_METRICS
        {
            /// <summary>
            /// The number of font design units per em unit.
            /// Font files use their own coordinate system of font design units.
            /// A font design unit is the smallest measurable unit in the em square,
            /// an imaginary square that is used to size and align glyphs.
            /// The concept of em square is used as a reference scale factor when defining font size and device transformation semantics.
            /// The size of one em square is also commonly used to compute the paragraph indentation value.
            /// </summary>
            UINT16 designUnitsPerEm;

            /// <summary>
            /// Ascent value of the font face in font design units.
            /// Ascent is the distance from the top of font character alignment box to English baseline.
            /// </summary>
            UINT16 ascent;

            /// <summary>
            /// Descent value of the font face in font design units.
            /// Descent is the distance from the bottom of font character alignment box to English baseline.
            /// </summary>
            UINT16 descent;

            /// <summary>
            /// Line gap in font design units.
            /// Recommended additional white space to add between lines to improve legibility. The recommended line spacing 
            /// (baseline-to-baseline distance) is thus the sum of ascent, descent, and lineGap. The line gap is usually 
            /// positive or zero but can be negative, in which case the recommended line spacing is less than the height
            /// of the character alignment box.
            /// </summary>
            INT16 lineGap;

            /// <summary>
            /// Cap height value of the font face in font design units.
            /// Cap height is the distance from English baseline to the top of a typical English capital.
            /// Capital "H" is often used as a reference character for the purpose of calculating the cap height value.
            /// </summary>
            UINT16 capHeight;

            /// <summary>
            /// x-height value of the font face in font design units.
            /// x-height is the distance from English baseline to the top of lowercase letter "x", or a similar lowercase character.
            /// </summary>
            UINT16 xHeight;

            /// <summary>
            /// The underline position value of the font face in font design units.
            /// Underline position is the position of underline relative to the English baseline.
            /// The value is usually made negative in order to place the underline below the baseline.
            /// </summary>
            INT16 underlinePosition;

            /// <summary>
            /// The suggested underline thickness value of the font face in font design units.
            /// </summary>
            UINT16 underlineThickness;

            /// <summary>
            /// The strikethrough position value of the font face in font design units.
            /// Strikethrough position is the position of strikethrough relative to the English baseline.
            /// The value is usually made positive in order to place the strikethrough above the baseline.
            /// </summary>
            INT16 strikethroughPosition;

            /// <summary>
            /// The suggested strikethrough thickness value of the font face in font design units.
            /// </summary>
            UINT16 strikethroughThickness;
        };

        /// <summary>
        /// The type of a font represented by a single font file.
        /// Font formats that consist of multiple files, e.g. Type 1 .PFM and .PFB, have
        /// separate enum values for each of the file type.
        /// </summary>
        public enum class DWRITE_FONT_FILE_TYPE
        {
            /// <summary>
            /// Font type is not recognized by the DirectWrite font system.
            /// </summary>
            UNKNOWN = ::DWRITE_FONT_FILE_TYPE_UNKNOWN,

            /// <summary>
            /// OpenType font with CFF outlines.
            /// </summary>
            CFF = ::DWRITE_FONT_FILE_TYPE_CFF,

            /// <summary>
            /// OpenType font with TrueType outlines.
            /// </summary>
            TRUETYPE = ::DWRITE_FONT_FILE_TYPE_TRUETYPE,

            /// <summary>
            /// OpenType font that contains a TrueType collection.
            /// </summary>
            OPENTYPE_COLLECTION = ::DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION,

            /// <summary>
            /// Type 1 PFM font.
            /// </summary>
            TYPE1_PFM = ::DWRITE_FONT_FILE_TYPE_TYPE1_PFM,

            /// <summary>
            /// Type 1 PFB font.
            /// </summary>
            TYPE1_PFB = ::DWRITE_FONT_FILE_TYPE_TYPE1_PFB,

            /// <summary>
            /// Vector .FON font.
            /// </summary>
            VECTOR = ::DWRITE_FONT_FILE_TYPE_VECTOR,

            /// <summary>
            /// Bitmap .FON font.
            /// </summary>
            BITMAP = ::DWRITE_FONT_FILE_TYPE_BITMAP,

            [System::ObsoleteAttribute("The following name is obsolete, but kept as an alias to avoid breaking existing code.", false)]
            TRUETYPE_COLLECTION = ::DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION
        };

        /// <summary>
        /// The file format of a complete font face.
        /// Font formats that consist of multiple files, e.g. Type 1 .PFM and .PFB, have
        /// a single enum entry.
        /// </summary>
        public enum class DWRITE_FONT_FACE_TYPE
        {
            /// <summary>
            /// OpenType font face with CFF outlines.
            /// </summary>
            CFF = ::DWRITE_FONT_FACE_TYPE_CFF,

            /// <summary>
            /// OpenType font face with TrueType outlines.
            /// </summary>
            TRUETYPE = ::DWRITE_FONT_FACE_TYPE_TRUETYPE,

            /// <summary>
            /// OpenType font face that is a part of a TrueType or CFF collection.
            /// </summary>
            OPENTYPE_COLLECTION = ::DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION,

            /// <summary>
            /// A Type 1 font face.
            /// </summary>
            TYPE1 = ::DWRITE_FONT_FACE_TYPE_TYPE1,

            /// <summary>
            /// A vector .FON format font face.
            /// </summary>
            VECTOR = ::DWRITE_FONT_FACE_TYPE_VECTOR,

            /// <summary>
            /// A bitmap .FON format font face.
            /// </summary>
            BITMAP = ::DWRITE_FONT_FACE_TYPE_BITMAP,

            /// <summary>
            /// Font face type is not recognized by the DirectWrite font system.
            /// </summary>
            UNKNOWN = ::DWRITE_FONT_FACE_TYPE_UNKNOWN,

            /// <summary>
            /// The font data includes only the CFF table from an OpenType CFF font.
            /// This font face type can be used only for embedded fonts (i.e., custom
            /// font file loaders) and the resulting font face object supports only the
            /// minimum functionality necessary to render glyphs.
            /// </summary>
            RAW_CFF = ::DWRITE_FONT_FACE_TYPE_RAW_CFF,

            [System::ObsoleteAttribute("The following name is obsolete, but kept as an alias to avoid breaking existing code.", false)]
            TRUETYPE_COLLECTION = ::DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION
        };

        /// <summary>
        /// The DWRITE_GLYPH_METRICS structure specifies the metrics of an individual glyph.
        /// The units depend on how the metrics are obtained.
        /// </summary>
        public value struct DWRITE_GLYPH_METRICS
        {
            /// <summary>
            /// Specifies the X offset from the glyph origin to the left edge of the black box.
            /// The glyph origin is the current horizontal writing position.
            /// A negative value means the black box extends to the left of the origin (often true for lowercase italic 'f').
            /// </summary>
            INT32 leftSideBearing;

            /// <summary>
            /// Specifies the X offset from the origin of the current glyph to the origin of the next glyph when writing horizontally.
            /// </summary>
            UINT32 advanceWidth;

            /// <summary>
            /// Specifies the X offset from the right edge of the black box to the origin of the next glyph when writing horizontally.
            /// The value is negative when the right edge of the black box overhangs the layout box.
            /// </summary>
            INT32 rightSideBearing;

            /// <summary>
            /// Specifies the vertical offset from the vertical origin to the top of the black box.
            /// Thus, a positive value adds whitespace whereas a negative value means the glyph overhangs the top of the layout box.
            /// </summary>
            INT32 topSideBearing;

            /// <summary>
            /// Specifies the Y offset from the vertical origin of the current glyph to the vertical origin of the next glyph when writing vertically.
            /// (Note that the term "origin" by itself denotes the horizontal origin. The vertical origin is different.
            /// Its Y coordinate is specified by verticalOriginY value,
            /// and its X coordinate is half the advanceWidth to the right of the horizontal origin).
            /// </summary>
            UINT32 advanceHeight;

            /// <summary>
            /// Specifies the vertical distance from the black box's bottom edge to the advance height.
            /// Positive when the bottom edge of the black box is within the layout box.
            /// Negative when the bottom edge of black box overhangs the layout box.
            /// </summary>
            INT32 bottomSideBearing;

            /// <summary>
            /// Specifies the Y coordinate of a glyph's vertical origin, in the font's design coordinate system.
            /// The y coordinate of a glyph's vertical origin is the sum of the glyph's top side bearing
            /// and the top (i.e. yMax) of the glyph's bounding box.
            /// </summary>
            INT32 verticalOriginY;
        };

        /// <summary>
        /// Optional adjustment to a glyph's position. A glyph offset changes the position of a glyph
        /// without affecting the pen position. Offsets are in logical, pre-transform units.
        /// </summary>
        public value struct DWRITE_GLYPH_OFFSET
        {
            /// <summary>
            /// Offset in the advance direction of the run. A positive advance offset moves the glyph to the right
            /// (in pre-transform coordinates) if the run is left-to-right or to the left if the run is right-to-left.
            /// </summary>
            float advanceOffset;

            /// <summary>
            /// Offset in the ascent direction, i.e., the direction ascenders point. A positive ascender offset moves
            /// the glyph up (in pre-transform coordinates).
            /// </summary>
            float ascenderOffset;
        };

        /// <summary>
        /// The DWRITE_MATRIX structure specifies the graphics transform to be applied
        /// to rendered glyphs.
        /// </summary>
        public value struct DWRITE_MATRIX
        {
            /// <summary>
            /// Horizontal scaling / cosine of rotation
            /// </summary>
            float m11;

            /// <summary>
            /// Vertical shear / sine of rotation
            /// </summary>
            float m12;

            /// <summary>
            /// Horizontal shear / negative sine of rotation
            /// </summary>
            float m21;

            /// <summary>
            /// Vertical scaling / cosine of rotation
            /// </summary>
            float m22;

            /// <summary>
            /// Horizontal shift (always orthogonal regardless of rotation)
            /// </summary>
            float dx;

            /// <summary>
            /// Vertical shift (always orthogonal regardless of rotation)
            /// </summary>
            float dy;

            DWRITE_MATRIX(float m11, float m12, float m21, float m22, float dx, float dy)
                : m11(m11), m12(m12), m21(m21), m22(m22), dx(dx), dy(dy) {}

            static operator ::DWRITE_MATRIX(DWriteNet::DWRITE_MATRIX %rhs)
            {
                ::DWRITE_MATRIX value;
                value.m11 = rhs.m11;
                value.m12 = rhs.m12;
                value.m21 = rhs.m21;
                value.m22 = rhs.m22;
                value.dx = rhs.dx;
                value.dy = rhs.dy;

                return value;
            }

            static operator DWriteNet::DWRITE_MATRIX(::DWRITE_MATRIX %rhs)
            {
                DWriteNet::DWRITE_MATRIX value;
                value.m11 = rhs.m11;
                value.m12 = rhs.m12;
                value.m21 = rhs.m21;
                value.m22 = rhs.m22;
                value.dx = rhs.dx;
                value.dy = rhs.dy;

                return value;
            }

            static operator Direct2DNet::D2D1_MATRIX_3X2_F(
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_MATRIX %rhs);
            static operator DWriteNet::DWRITE_MATRIX(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %rhs);
        };

        /// <summary>
        /// Typographic feature of text supplied by the font.
        /// </summary>
        /// <remarks>
        /// Use <see cref="DirectWrite::MakeFontFeatureTag"/> to create a custom one.
        /// <remarks>
        public enum class DWRITE_FONT_FEATURE_TAG : UINT32
        {
            ALTERNATIVE_FRACTIONS = DWRITE_MAKE_OPENTYPE_TAG('a', 'f', 'r', 'c'),
            PETITE_CAPITALS_FROM_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('c', '2', 'p', 'c'),
            SMALL_CAPITALS_FROM_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('c', '2', 's', 'c'),
            CONTEXTUAL_ALTERNATES = DWRITE_MAKE_OPENTYPE_TAG('c', 'a', 'l', 't'),
            CASE_SENSITIVE_FORMS = DWRITE_MAKE_OPENTYPE_TAG('c', 'a', 's', 'e'),
            GLYPH_COMPOSITION_DECOMPOSITION = DWRITE_MAKE_OPENTYPE_TAG('c', 'c', 'm', 'p'),
            CONTEXTUAL_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('c', 'l', 'i', 'g'),
            CAPITAL_SPACING = DWRITE_MAKE_OPENTYPE_TAG('c', 'p', 's', 'p'),
            CONTEXTUAL_SWASH = DWRITE_MAKE_OPENTYPE_TAG('c', 's', 'w', 'h'),
            CURSIVE_POSITIONING = DWRITE_MAKE_OPENTYPE_TAG('c', 'u', 'r', 's'),
            DEFAULT = DWRITE_MAKE_OPENTYPE_TAG('d', 'f', 'l', 't'),
            DISCRETIONARY_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('d', 'l', 'i', 'g'),
            EXPERT_FORMS = DWRITE_MAKE_OPENTYPE_TAG('e', 'x', 'p', 't'),
            FRACTIONS = DWRITE_MAKE_OPENTYPE_TAG('f', 'r', 'a', 'c'),
            FULL_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('f', 'w', 'i', 'd'),
            HALF_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 'f'),
            HALANT_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 'n'),
            ALTERNATE_HALF_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 't'),
            HISTORICAL_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'i', 's', 't'),
            HORIZONTAL_KANA_ALTERNATES = DWRITE_MAKE_OPENTYPE_TAG('h', 'k', 'n', 'a'),
            HISTORICAL_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('h', 'l', 'i', 'g'),
            HALF_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('h', 'w', 'i', 'd'),
            HOJO_KANJI_FORMS = DWRITE_MAKE_OPENTYPE_TAG('h', 'o', 'j', 'o'),
            JIS04_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '0', '4'),
            JIS78_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '7', '8'),
            JIS83_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '8', '3'),
            JIS90_FORMS = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '9', '0'),
            KERNING = DWRITE_MAKE_OPENTYPE_TAG('k', 'e', 'r', 'n'),
            STANDARD_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('l', 'i', 'g', 'a'),
            LINING_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('l', 'n', 'u', 'm'),
            LOCALIZED_FORMS = DWRITE_MAKE_OPENTYPE_TAG('l', 'o', 'c', 'l'),
            MARK_POSITIONING = DWRITE_MAKE_OPENTYPE_TAG('m', 'a', 'r', 'k'),
            MATHEMATICAL_GREEK = DWRITE_MAKE_OPENTYPE_TAG('m', 'g', 'r', 'k'),
            MARK_TO_MARK_POSITIONING = DWRITE_MAKE_OPENTYPE_TAG('m', 'k', 'm', 'k'),
            ALTERNATE_ANNOTATION_FORMS = DWRITE_MAKE_OPENTYPE_TAG('n', 'a', 'l', 't'),
            NLC_KANJI_FORMS = DWRITE_MAKE_OPENTYPE_TAG('n', 'l', 'c', 'k'),
            OLD_STYLE_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('o', 'n', 'u', 'm'),
            ORDINALS = DWRITE_MAKE_OPENTYPE_TAG('o', 'r', 'd', 'n'),
            PROPORTIONAL_ALTERNATE_WIDTH = DWRITE_MAKE_OPENTYPE_TAG('p', 'a', 'l', 't'),
            PETITE_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('p', 'c', 'a', 'p'),
            PROPORTIONAL_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('p', 'n', 'u', 'm'),
            PROPORTIONAL_WIDTHS = DWRITE_MAKE_OPENTYPE_TAG('p', 'w', 'i', 'd'),
            QUARTER_WIDTHS = DWRITE_MAKE_OPENTYPE_TAG('q', 'w', 'i', 'd'),
            REQUIRED_LIGATURES = DWRITE_MAKE_OPENTYPE_TAG('r', 'l', 'i', 'g'),
            RUBY_NOTATION_FORMS = DWRITE_MAKE_OPENTYPE_TAG('r', 'u', 'b', 'y'),
            STYLISTIC_ALTERNATES = DWRITE_MAKE_OPENTYPE_TAG('s', 'a', 'l', 't'),
            SCIENTIFIC_INFERIORS = DWRITE_MAKE_OPENTYPE_TAG('s', 'i', 'n', 'f'),
            SMALL_CAPITALS = DWRITE_MAKE_OPENTYPE_TAG('s', 'm', 'c', 'p'),
            SIMPLIFIED_FORMS = DWRITE_MAKE_OPENTYPE_TAG('s', 'm', 'p', 'l'),
            STYLISTIC_SET_1 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '1'),
            STYLISTIC_SET_2 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '2'),
            STYLISTIC_SET_3 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '3'),
            STYLISTIC_SET_4 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '4'),
            STYLISTIC_SET_5 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '5'),
            STYLISTIC_SET_6 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '6'),
            STYLISTIC_SET_7 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '7'),
            STYLISTIC_SET_8 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '8'),
            STYLISTIC_SET_9 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '9'),
            STYLISTIC_SET_10 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '0'),
            STYLISTIC_SET_11 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '1'),
            STYLISTIC_SET_12 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '2'),
            STYLISTIC_SET_13 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '3'),
            STYLISTIC_SET_14 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '4'),
            STYLISTIC_SET_15 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '5'),
            STYLISTIC_SET_16 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '6'),
            STYLISTIC_SET_17 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '7'),
            STYLISTIC_SET_18 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '8'),
            STYLISTIC_SET_19 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '9'),
            STYLISTIC_SET_20 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '2', '0'),
            SUBSCRIPT = DWRITE_MAKE_OPENTYPE_TAG('s', 'u', 'b', 's'),
            SUPERSCRIPT = DWRITE_MAKE_OPENTYPE_TAG('s', 'u', 'p', 's'),
            SWASH = DWRITE_MAKE_OPENTYPE_TAG('s', 'w', 's', 'h'),
            TITLING = DWRITE_MAKE_OPENTYPE_TAG('t', 'i', 't', 'l'),
            TRADITIONAL_NAME_FORMS = DWRITE_MAKE_OPENTYPE_TAG('t', 'n', 'a', 'm'),
            TABULAR_FIGURES = DWRITE_MAKE_OPENTYPE_TAG('t', 'n', 'u', 'm'),
            TRADITIONAL_FORMS = DWRITE_MAKE_OPENTYPE_TAG('t', 'r', 'a', 'd'),
            THIRD_WIDTHS = DWRITE_MAKE_OPENTYPE_TAG('t', 'w', 'i', 'd'),
            UNICASE = DWRITE_MAKE_OPENTYPE_TAG('u', 'n', 'i', 'c'),
            VERTICAL_WRITING = DWRITE_MAKE_OPENTYPE_TAG('v', 'e', 'r', 't'),
            VERTICAL_ALTERNATES_AND_ROTATION = DWRITE_MAKE_OPENTYPE_TAG('v', 'r', 't', '2'),
            SLASHED_ZERO = DWRITE_MAKE_OPENTYPE_TAG('z', 'e', 'r', 'o'),
        };

        /// <summary>
        /// The DWRITE_FONT_FEATURE structure specifies properties used to identify and execute typographic
        /// feature in the font.
        /// </summary>
        public value struct DWRITE_FONT_FEATURE
        {
            /// <summary>
            /// The feature OpenType name identifier.
            /// </summary>
            UINT32 nameTag;

            /// <summary>
            /// Execution parameter of the feature.
            /// </summary>
            /// <remarks>
            /// The parameter should be non-zero to enable the feature.  Once enabled, a feature can't be
            /// disabled again within the same range.  Features requiring a selector use this value to
            /// indicate the selector index. 
            /// </remarks>
            UINT32 parameter;

            DWRITE_FONT_FEATURE(UINT32 nameTag, UINT32 parameter) : nameTag(nameTag), parameter(parameter) {}
            DWRITE_FONT_FEATURE(DWriteNet::DWRITE_FONT_FEATURE_TAG nameTag, UINT32 parameter)
                : nameTag((UINT32)nameTag), parameter(parameter) {}

            static operator ::DWRITE_FONT_FEATURE(DWriteNet::DWRITE_FONT_FEATURE %rhs)
            {
                ::DWRITE_FONT_FEATURE value;
                value.nameTag = (::DWRITE_FONT_FEATURE_TAG)rhs.nameTag;
                value.parameter = rhs.parameter;

                return value;
            }

            static operator DWriteNet::DWRITE_FONT_FEATURE(::DWRITE_FONT_FEATURE %rhs)
            {
                DWriteNet::DWRITE_FONT_FEATURE value;
                value.nameTag = (UINT32)rhs.nameTag;
                value.parameter = rhs.parameter;

                return value;
            }
        };

        ref class IDWriteFontFace;

        /// <summary>
        /// The DWRITE_GLYPH_RUN structure contains the information needed by renderers
        /// to draw glyph runs. All coordinates are in device independent pixels (DIPs).
        /// </summary>
        public value struct DWRITE_GLYPH_RUN
        {
            /// <summary>
            /// The physical font face to draw with.
            /// </summary>
            DWriteNet::IDWriteFontFace ^fontFace;

            /// <summary>
            /// Logical size of the font in DIPs, not points (equals 1/96 inch).
            /// </summary>
            FLOAT fontEmSize;

            /// <summary>
            /// The number of glyphs.
            /// </summary>
            UINT32 glyphCount;

            /// <summary>
            /// Pointer to the array of the indices to render.
            /// </summary>    
            UINT16 *glyphIndices;

            /// <summary>
            /// Optional pointer to the array of the glyph advance widths.
            /// </summary>
            FLOAT *glyphAdvances;

            /// <summary>
            /// Optional pointer to the array of the glyph offsets.
            /// </summary>
            DWriteNet::DWRITE_GLYPH_OFFSET *glyphOffsets;

            /// <summary>
            /// If true, specifies that glyphs are rotated 90 degrees to the left and
            /// vertical metrics are used. Vertical writing is achieved by specifying
            /// isSideways = true and rotating the entire run 90 degrees to the right
            /// via a rotate transform.
            /// </summary>
            bool isSideways;

            /// <summary>
            /// The implicit resolved bidi level of the run. Odd levels indicate
            /// right-to-left languages like Hebrew and Arabic, while even levels
            /// indicate left-to-right languages like English and Japanese (when
            /// written horizontally). For right-to-left languages, the text origin
            /// is on the right, and text should be drawn to the left.
            /// </summary>
            UINT32 bidiLevel;

            DWRITE_GLYPH_RUN(
                DWriteNet::IDWriteFontFace ^fontFace,
                FLOAT fontEmSize,
                UINT32 glyphCount,
                UINT16 *glyphIndices,
                bool isSideways,
                UINT32 bidiLevel,
                [OptionalAttribute] FLOAT *glyphAdvances,
                [OptionalAttribute] DWriteNet::DWRITE_GLYPH_OFFSET *glyphOffsets
            ) : fontFace(fontFace), fontEmSize(fontEmSize), glyphCount(glyphCount), glyphIndices(glyphIndices),
                isSideways(isSideways), bidiLevel(bidiLevel), glyphAdvances(glyphAdvances),
                glyphOffsets(glyphOffsets)
            {

            }

            static operator ::DWRITE_GLYPH_RUN(DWriteNet::DWRITE_GLYPH_RUN %rhs);
        };

        /// <summary>
        /// The DWRITE_TEXT_RANGE structure specifies a range of text positions where format is applied.
        /// </summary>
        public value struct DWRITE_TEXT_RANGE
        {
            /// <summary>
            /// The start text position of the range.
            /// </summary>
            UINT32 startPosition;

            /// <summary>
            /// The number of text positions in the range.
            /// </summary>
            UINT32 length;

            DWRITE_TEXT_RANGE(UINT32 startPosition, UINT32 length)
                : startPosition(startPosition), length(length) {}

            static operator ::DWRITE_TEXT_RANGE(DWriteNet::DWRITE_TEXT_RANGE %rhs)
            {
                ::DWRITE_TEXT_RANGE value;
                value.startPosition = rhs.startPosition;
                value.length = rhs.length;
                
                return value;
            }

            static operator DWriteNet::DWRITE_TEXT_RANGE(::DWRITE_TEXT_RANGE %rhs)
            {
                DWriteNet::DWRITE_TEXT_RANGE value;
                value.startPosition = rhs.startPosition;
                value.length = rhs.length;

                return value;
            }
        };

        /// <summary>
        /// The DWRITE_LINE_METRICS structure contains information about a formatted
        /// line of text.
        /// </summary>
        public value struct DWRITE_LINE_METRICS
        {
            /// <summary>
            /// The number of total text positions in the line.
            /// This includes any trailing whitespace and newline characters.
            /// </summary>
            UINT32 length;

            /// <summary>
            /// The number of whitespace positions at the end of the line.  Newline
            /// sequences are considered whitespace.
            /// </summary>
            UINT32 trailingWhitespaceLength;

            /// <summary>
            /// The number of characters in the newline sequence at the end of the line.
            /// If the count is zero, then the line was either wrapped or it is the
            /// end of the text.
            /// </summary>
            UINT32 newlineLength;

            /// <summary>
            /// Height of the line as measured from top to bottom.
            /// </summary>
            FLOAT height;

            /// <summary>
            /// Distance from the top of the line to its baseline.
            /// </summary>
            FLOAT baseline;

            /// <summary>
            /// The line is trimmed.
            /// </summary>
            bool isTrimmed;

        private:
            char pad1;
            char pad2;
            char pad3;
        };

        /// <summary>
        /// Overall metrics associated with text after layout.
        /// All coordinates are in device independent pixels (DIPs).
        /// </summary>
        public value struct DWRITE_TEXT_METRICS
        {
            /// <summary>
            /// Left-most point of formatted text relative to layout box
            /// (excluding any glyph overhang).
            /// </summary>
            FLOAT left;

            /// <summary>
            /// Top-most point of formatted text relative to layout box
            /// (excluding any glyph overhang).
            /// </summary>
            FLOAT top;

            /// <summary>
            /// The width of the formatted text ignoring trailing whitespace
            /// at the end of each line.
            /// </summary>
            FLOAT width;

            /// <summary>
            /// The width of the formatted text taking into account the
            /// trailing whitespace at the end of each line.
            /// </summary>
            FLOAT widthIncludingTrailingWhitespace;

            /// <summary>
            /// The height of the formatted text. The height of an empty string
            /// is determined by the size of the default font's line height.
            /// </summary>
            FLOAT height;

            /// <summary>
            /// Initial width given to the layout. Depending on whether the text
            /// was wrapped or not, it can be either larger or smaller than the
            /// text content width.
            /// </summary>
            FLOAT layoutWidth;

            /// <summary>
            /// Initial height given to the layout. Depending on the length of the
            /// text, it may be larger or smaller than the text content height.
            /// </summary>
            FLOAT layoutHeight;

            /// <summary>
            /// The maximum reordering count of any line of text, used
            /// to calculate the most number of hit-testing boxes needed.
            /// If the layout has no bidirectional text or no text at all,
            /// the minimum level is 1.
            /// </summary>
            UINT32 maxBidiReorderingDepth;

            /// <summary>
            /// Total number of lines.
            /// </summary>
            UINT32 lineCount;
        };

        /// <summary>
        /// The DWRITE_OVERHANG_METRICS structure holds how much any visible pixels
        /// (in DIPs) overshoot each side of the layout or inline objects.
        /// </summary>
        /// <remarks>
        /// Positive overhangs indicate that the visible area extends outside the layout
        /// box or inline object, while negative values mean there is whitespace inside.
        /// The returned values are unaffected by rendering transforms or pixel snapping.
        /// Additionally, they may not exactly match final target's pixel bounds after
        /// applying grid fitting and hinting.
        /// </remarks>
        public value struct DWRITE_OVERHANG_METRICS
        {
            /// <summary>
            /// The distance from the left-most visible DIP to its left alignment edge.
            /// </summary>
            FLOAT left;

            /// <summary>
            /// The distance from the top-most visible DIP to its top alignment edge.
            /// </summary>
            FLOAT top;

            /// <summary>
            /// The distance from the right-most visible DIP to its right alignment edge.
            /// </summary>
            FLOAT right;

            /// <summary>
            /// The distance from the bottom-most visible DIP to its bottom alignment edge.
            /// </summary>
            FLOAT bottom;

            DWRITE_OVERHANG_METRICS(float left, float top, float right, float bottom)
                : left(left), top(top), right(right), bottom(bottom) {}
        };

        /// <summary>
        /// The DWRITE_CLUSTER_METRICS structure contains information about a glyph cluster.
        /// </summary>
        public value struct DWRITE_CLUSTER_METRICS
        {
            /// <summary>
            /// The total advance width of all glyphs in the cluster.
            /// </summary>
            FLOAT width;

            /// <summary>
            /// The number of text positions in the cluster.
            /// </summary>
            UINT16 length;

        private:
            UINT16 flagVector;

        public:
            /// <summary>
            /// Indicate whether line can be broken right after the cluster.
            /// </summary>
            property bool canWrapLineAfter
            {
                bool get()
                {
                    return (flagVector & 1U) != 0;
                }

                void set(bool value)
                {
                    if(value)
                        flagVector |= 1U;
                    else
                        flagVector &= ~1U;
                }
            }

            /// <summary>
            /// Indicate whether the cluster corresponds to whitespace character.
            /// </summary>
            property bool isWhitespace
            {
                bool get()
                {
                    return (flagVector & (0b10U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        flagVector |= 0b10U;
                    else
                        flagVector &= ~0b10U;
                }
            }

            /// <summary>
            /// Indicate whether the cluster corresponds to a newline character.
            /// </summary>
            property bool isNewline
            {
                bool get()
                {
                    return (flagVector & (0b100U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        flagVector |= 0b100U;
                    else
                        flagVector &= ~0b100U;
                }
            }

            /// <summary>
            /// Indicate whether the cluster corresponds to soft hyphen character.
            /// </summary>
            property bool isSoftHyphen
            {
                bool get()
                {
                    return (flagVector & (0b1000U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        flagVector |= 0b1000U;
                    else
                        flagVector &= ~0b1000U;
                }
            }

            /// <summary>
            /// Indicate whether the cluster is read from right to left.
            /// </summary>
            property bool isRightToLeft
            {
                bool get()
                {
                    return (flagVector & (0b10000U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        flagVector |= 0b10000U;
                    else
                        flagVector &= ~0b10000U;
                }
            }
        };

        /// <summary>
        /// Geometry enclosing of text positions.
        /// </summary>
        public value struct DWRITE_HIT_TEST_METRICS
        {
            /// <summary>
            /// First text position within the geometry.
            /// </summary>
            UINT32 textPosition;

            /// <summary>
            /// Number of text positions within the geometry.
            /// </summary>
            UINT32 length;

            /// <summary>
            /// Left position of the top-left coordinate of the geometry.
            /// </summary>
            FLOAT left;

            /// <summary>
            /// Top position of the top-left coordinate of the geometry.
            /// </summary>
            FLOAT top;

            /// <summary>
            /// Geometry's width.
            /// </summary>
            FLOAT width;

            /// <summary>
            /// Geometry's height.
            /// </summary>
            FLOAT height;

            /// <summary>
            /// Bidi level of text positions enclosed within the geometry.
            /// </summary>
            UINT32 bidiLevel;

            /// <summary>
            /// Geometry encloses text?
            /// </summary>
            bool isText;

        private:
            char pad1;
            char pad2;
            char pad3;

        public:
            /// <summary>
            /// Range is trimmed.
            /// </summary>
            bool isTrimmed;

        private:
            char pad4;
            char pad5;
            char pad6;
        };

        /// <summary>
        /// Properties describing the geometric measurement of an
        /// application-defined inline object.
        /// </summary>
        public value struct DWRITE_INLINE_OBJECT_METRICS
        {
        public:
            /// <summary>
            /// Width of the inline object.
            /// </summary>
            FLOAT width;

            /// <summary>
            /// Height of the inline object as measured from top to bottom.
            /// </summary>
            FLOAT height;

            /// <summary>
            /// Distance from the top of the object to the baseline where it is lined up with the adjacent text.
            /// If the baseline is at the bottom, baseline simply equals height.
            /// </summary>
            FLOAT baseline;

            /// <summary>
            /// Flag indicating whether the object is to be placed upright or alongside the text baseline
            /// for vertical text.
            /// </summary>
            bool  supportsSideways;

        private:
            char pad1;
            char pad2;
            char pad3;

            DWRITE_INLINE_OBJECT_METRICS(float width, float height, float baseline, bool supportsSideways)
                : width(width), height(height), baseline(baseline), supportsSideways(supportsSideways)
                , pad1(0), pad2(0), pad3(0)
            {}
        };

        /// <summary>
        /// Condition at the edges of inline object or text used to determine
        /// line-breaking behavior.
        /// </summary>
        public enum class DWRITE_BREAK_CONDITION
        {
            /// <summary>
            /// Whether a break is allowed is determined by the condition of the
            /// neighboring text span or inline object.
            /// </summary>
            NEUTRAL = ::DWRITE_BREAK_CONDITION_NEUTRAL,

            /// <summary>
            /// A break is allowed, unless overruled by the condition of the
            /// neighboring text span or inline object, either prohibited by a
            /// May Not or forced by a Must.
            /// </summary>
            CAN_BREAK = ::DWRITE_BREAK_CONDITION_CAN_BREAK,

            /// <summary>
            /// There should be no break, unless overruled by a Must condition from
            /// the neighboring text span or inline object.
            /// </summary>
            MAY_NOT_BREAK = ::DWRITE_BREAK_CONDITION_MAY_NOT_BREAK,

            /// <summary>
            /// The break must happen, regardless of the condition of the adjacent
            /// text span or inline object.
            /// </summary>
            MUST_BREAK = ::DWRITE_BREAK_CONDITION_MUST_BREAK
        };

        /// <summary>
        /// How to apply number substitution on digits and related punctuation.
        /// </summary>
        public enum class DWRITE_NUMBER_SUBSTITUTION_METHOD
        {
            /// <summary>
            /// Specifies that the substitution method should be determined based
            /// on LOCALE_IDIGITSUBSTITUTION value of the specified text culture.
            /// </summary>
            FROM_CULTURE = ::DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE,

            /// <summary>
            /// If the culture is Arabic or Farsi, specifies that the number shape
            /// depend on the context. Either traditional or nominal number shape
            /// are used depending on the nearest preceding strong character or (if
            /// there is none) the reading direction of the paragraph.
            /// </summary>
            CONTEXTUAL = ::DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL,

            /// <summary>
            /// Specifies that code points 0x30-0x39 are always rendered as nominal numeral 
            /// shapes (ones of the European number), i.e., no substitution is performed.
            /// </summary>
            NONE = ::DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE,

            /// <summary>
            /// Specifies that number are rendered using the national number shape 
            /// as specified by the LOCALE_SNATIVEDIGITS value of the specified text culture.
            /// </summary>
            NATIONAL = ::DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL,

            /// <summary>
            /// Specifies that number are rendered using the traditional shape
            /// for the specified culture. For most cultures, this is the same as
            /// NativeNational. However, NativeNational results in Latin number
            /// for some Arabic cultures, whereas this value results in Arabic
            /// number for all Arabic cultures.
            /// </summary>
            TRADITIONAL = ::DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL
        };

        /// <summary>
        /// Indicates additional shaping requirements for text.
        /// </summary>
        [System::FlagsAttribute]
        public enum class DWRITE_SCRIPT_SHAPES
        {
            /// <summary>
            /// No additional shaping requirement. Text is shaped with the writing system default behavior.
            /// </summary>
            DEFAULT = 0,

            /// <summary>
            /// Text should leave no visual on display i.e. control or format control characters.
            /// </summary>
            NO_VISUAL = 1
        };

        /// <summary>
        /// Association of text and its writing system script as well as some display attributes.
        /// </summary>
        public value struct DWRITE_SCRIPT_ANALYSIS
        {
            /// <summary>
            /// Zero-based index representation of writing system script.
            /// </summary>
            UINT16 script;

            /// <summary>
            /// Additional shaping requirement of text.
            /// </summary>
            DWriteNet::DWRITE_SCRIPT_SHAPES shapes;
        };

        /// <summary>
        /// Line breakpoint characteristics of a character.
        /// </summary>
        public value struct DWRITE_LINE_BREAKPOINT
        {
        private:
            UINT8 charVector;

        public:
            /// <summary>
            /// Breaking condition before the character.
            /// </summary>
            property DWriteNet::DWRITE_BREAK_CONDITION breakConditionBefore
            {
                DWriteNet::DWRITE_BREAK_CONDITION get()
                {
                    return (DWriteNet::DWRITE_BREAK_CONDITION)(charVector & 0b11U);
                }

                void set(DWriteNet::DWRITE_BREAK_CONDITION value)
                {
                    charVector &= 0b11111100U;
                    charVector |= (UINT8)value;
                }
            }

            /// <summary>
            /// Breaking condition after the character.
            /// </summary>
            property DWriteNet::DWRITE_BREAK_CONDITION breakConditionAfter
            {
                DWriteNet::DWRITE_BREAK_CONDITION get()
                {
                    return (DWriteNet::DWRITE_BREAK_CONDITION)((charVector & 0b1100U) >> 2);
                }

                void set(DWriteNet::DWRITE_BREAK_CONDITION value)
                {
                    charVector &= 0b11110011U;
                    charVector |= ((UINT8)value << 2);
                }
            }

            /// <summary>
            /// The character is some form of whitespace, which may be meaningful
            /// for justification.
            /// </summary>
            property bool isWhitespace
            {
                bool get()
                {
                    return (charVector & (0b10000U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        charVector |= 0b10000U;
                    else
                        charVector &= ~0b10000U;
                }
            }

            /// <summary>
            /// The character is a soft hyphen, often used to indicate hyphenation
            /// points inside words.
            /// </summary>
            property bool isSoftHyphen
            {
                bool get()
                {
                    return (charVector & (0b100000U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        charVector |= 0b100000U;
                    else
                        charVector &= ~0b100000U;
                }
            }
        };

        /// <summary>
        /// Shaping output properties per input character.
        /// </summary>
        public value struct DWRITE_SHAPING_TEXT_PROPERTIES
        {
        private:
            UINT16 propVector;

        public:
            /// <summary>
            /// This character can be shaped independently from the others
            /// (usually set for the space character).
            /// </summary>
            property bool isShapedAlone
            {
                bool get()
                {
                    return (propVector & (0b1U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        propVector |= 0b1U;
                    else
                        propVector &= ~0b1U;
                }
            }

            /// <summary>
            /// Glyph shaping can be cut after this point without affecting shaping
            /// before or after it. Otherwise, splitting a call to GetGlyphs would
            /// cause a reflow of glyph advances and shapes.
            /// </summary>
            property bool canBreakShapingAfter
            {
                bool get()
                {
                    return (propVector & (0b100U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        propVector |= 0b100U;
                    else
                        propVector &= ~0b100U;
                }
            }
        };

        /// <summary>
        /// Shaping output properties per output glyph.
        /// </summary>
        public value struct DWRITE_SHAPING_GLYPH_PROPERTIES
        {
        private:
            UINT16 propVector;

        public:
            /// <summary>
            /// Justification class, whether to use spacing, kashidas, or
            /// another method. This exists for backwards compatibility
            /// with Uniscribe's SCRIPT_JUSTIFY enum.
            /// </summary>
            property UINT16 justification
            {
                UINT16 get()
                {
                    return propVector & 0b1111U;
                }

                void set(UINT16 value)
                {
                    if(value > 0b1111U)
                        return;

                    propVector &= 0b1111111111110000U;
                    propVector |= value;
                }
            }

            /// <summary>
            /// Indicates glyph is the first of a cluster.
            /// </summary>
            property bool isClusterStart
            {
                bool get()
                {
                    return (propVector & (0b10000U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        propVector |= 0b10000U;
                    else
                        propVector &= ~0b10000U;
                }
            }

            /// <summary>
            /// Glyph is a diacritic.
            /// </summary>
            property bool isDiacritic
            {
                bool get()
                {
                    return (propVector & (0b100000U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        propVector |= 0b100000U;
                    else
                        propVector &= ~0b100000U;
                }
            }

            /// <summary>
            /// Glyph has no width, mark, ZWJ, ZWNJ, ZWSP, LRM etc.
            /// This flag is not limited to just U+200B.
            /// </summary>
            property bool isZeroWidthSpace
            {
                bool get()
                {
                    return (propVector & (0b1000000U)) != 0U;
                }

                void set(bool value)
                {
                    if(value)
                        propVector |= 0b1000000U;
                    else
                        propVector &= ~0b1000000U;
                }
            }
        };

        /// <summary>
        /// The DWRITE_TEXTURE_TYPE enumeration identifies a type of alpha texture. An alpha texture is
        /// a bitmap of alpha values, each representing the darkness (i.e., opacity) of a pixel or subpixel.
        /// </summary>
        public enum class DWRITE_TEXTURE_TYPE
        {
            /// <summary>
            /// Specifies an alpha texture for aliased text rendering (i.e., bi-level, where each pixel is either fully opaque or fully transparent),
            /// with one byte per pixel.
            /// </summary>
            ALIASED_1x1,

            /// <summary>
            /// Specifies an alpha texture for ClearType text rendering, with three bytes per pixel in the horizontal dimension and 
            /// one byte per pixel in the vertical dimension.
            /// </summary>
            CLEARTYPE_3x1
        };

        /// <summary>
        /// The DWRITE_GLYPH_RUN_DESCRIPTION structure contains additional properties
        /// related to those in DWRITE_GLYPH_RUN.
        /// </summary>
        public value struct DWRITE_GLYPH_RUN_DESCRIPTION
        {
            /// <summary>
            /// The locale name associated with this run.
            /// This is the pointer to the native string(char array) which is 16-bit UNICODE and
            /// terminates with null.
            /// </summary>
            WCHAR *localeName;

            /// <summary>
            /// The text associated with the glyphs.
            /// This is the pointer to the native string(char array) which is 16-bit UNICODE.
            /// </summary>
            WCHAR *string;

            /// <summary>
            /// The number of characters in the text(UTF16 code-units).
            /// Note that this may be different than the number of glyphs.
            /// </summary>
            UINT32 stringLength;

            /// <summary>
            /// An array of indices to the glyph indices array, of the first glyphs of
            /// all the glyph clusters of the glyphs to render.
            /// This is the pointer to the ushort array.
            /// </summary>
            UINT16 *clusterMap;

            /// <summary>
            /// Corresponding text position in the original string
            /// this glyph run came from.
            /// </summary>
            UINT32 textPosition;
        };
    }
}

#ifndef NEAR
#define NEAR near
#endif

#ifndef FAR
#define FAR far
#endif