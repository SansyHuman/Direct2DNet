#pragma once

#include "DWNetHeaders.h"

namespace D2DNet
{
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
    }
}

#ifndef NEAR
#define NEAR near
#endif

#ifndef FAR
#define FAR far
#endif