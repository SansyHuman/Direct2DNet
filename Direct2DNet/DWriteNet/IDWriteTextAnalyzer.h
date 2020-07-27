#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"
#include <msclr/marshal.h>
#include <wchar.h>

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;
        ref class IDWriteTextAnalysisSource;
        ref class IDWriteTextAnalysisSink;
        ref class IDWriteFontFace;
        ref class IDWriteNumberSubstitution;

        /// <summary>
        /// Analyzes various text properties for complex script processing.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("b7e6163e-7f46-43b4-84b3-e4e6249c365d")]
        public ref class IDWriteTextAnalyzer : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteTextAnalyzer *m_pAnalyzer;

            IDWriteTextAnalyzer(DWriteNet::IDWriteFactory ^factory);

            IDWriteTextAnalyzer() : m_pAnalyzer(nullptr) {}

        public:
            ~IDWriteTextAnalyzer();
            !IDWriteTextAnalyzer();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pAnalyzer;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Analyzes a text range for script boundaries, reading text attributes
            /// from the source and reporting the Unicode script ID to the sink 
            /// callback SetScript.
            /// </summary>
            /// <param name="analysisSource">Source object to analyze.</param>
            /// <param name="textPosition">Starting position within the source object.</param>
            /// <param name="textLength">Length to analyze.</param>
            /// <param name="analysisSink">Callback object.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT AnalyzeScript(
                DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
                UINT32 textPosition,
                UINT32 textLength,
                DWriteNet::IDWriteTextAnalysisSink ^analysisSink
            );

            /// <summary>
            /// Analyzes a text range for script directionality, reading attributes
            /// from the source and reporting levels to the sink callback SetBidiLevel.
            /// </summary>
            /// <param name="analysisSource">Source object to analyze.</param>
            /// <param name="textPosition">Starting position within the source object.</param>
            /// <param name="textLength">Length to analyze.</param>
            /// <param name="analysisSink">Callback object.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// While the function can handle multiple paragraphs, the text range
            /// should not arbitrarily split the middle of paragraphs. Otherwise the
            /// returned levels may be wrong, since the Bidi algorithm is meant to
            /// apply to the paragraph as a whole.
            /// </remarks>
            /// <remarks>
            /// Embedded control codes (LRE/LRO/RLE/RLO/PDF) are taken into account.
            /// </remarks>
            HRESULT AnalyzeBidi(
                DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
                UINT32 textPosition,
                UINT32 textLength,
                DWriteNet::IDWriteTextAnalysisSink ^analysisSink
            );

            /// <summary>
            /// Analyzes a text range for spans where number substitution is applicable,
            /// reading attributes from the source and reporting substitutable ranges
            /// to the sink callback SetNumberSubstitution.
            /// </summary>
            /// <param name="analysisSource">Source object to analyze.</param>
            /// <param name="textPosition">Starting position within the source object.</param>
            /// <param name="textLength">Length to analyze.</param>
            /// <param name="analysisSink">Callback object.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// While the function can handle multiple ranges of differing number
            /// substitutions, the text ranges should not arbitrarily split the
            /// middle of numbers. Otherwise it will treat the numbers separately
            /// and will not translate any intervening punctuation.
            /// </remarks>
            /// <remarks>
            /// Embedded control codes (LRE/LRO/RLE/RLO/PDF) are taken into account.
            /// </remarks>
            HRESULT AnalyzeNumberSubstitution(
                DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
                UINT32 textPosition,
                UINT32 textLength,
                DWriteNet::IDWriteTextAnalysisSink ^analysisSink
            );

            /// <summary>
            /// Analyzes a text range for potential breakpoint opportunities, reading
            /// attributes from the source and reporting breakpoint opportunities to
            /// the sink callback SetLineBreakpoints.
            /// </summary>
            /// <param name="analysisSource">Source object to analyze.</param>
            /// <param name="textPosition">Starting position within the source object.</param>
            /// <param name="textLength">Length to analyze.</param>
            /// <param name="analysisSink">Callback object.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// While the function can handle multiple paragraphs, the text range
            /// should not arbitrarily split the middle of paragraphs, unless the
            /// given text span is considered a whole unit. Otherwise the
            /// returned properties for the first and last characters will
            /// inappropriately allow breaks.
            /// </remarks>
            /// <remarks>
            /// Special cases include the first, last, and surrogate characters. Any
            /// text span is treated as if adjacent to inline objects on either side.
            /// So the rules with contingent-break opportunities are used, where the 
            /// edge between text and inline objects is always treated as a potential
            /// break opportunity, dependent on any overriding rules of the adjacent
            /// objects to prohibit or force the break (see Unicode TR #14).
            /// Surrogate pairs never break between.
            /// </remarks>
            HRESULT AnalyzeLineBreakpoints(
                DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
                UINT32 textPosition,
                UINT32 textLength,
                DWriteNet::IDWriteTextAnalysisSink ^analysisSink
            );

            /// <summary>
            /// Parses the input text string and maps it to the set of glyphs and associated glyph data
            /// according to the font and the writing system's rendering rules.
            /// </summary>
            /// <param name="textString">The string to convert to glyphs.</param>
            /// <param name="fontFace">The font face to get glyphs from.</param>
            /// <param name="isSideways">Set to true if the text is intended to be
            /// drawn vertically.</param>
            /// <param name="isRightToLeft">Set to true for right-to-left text.</param>
            /// <param name="scriptAnalysis">Script analysis result from AnalyzeScript.</param>
            /// <param name="maxGlyphCount">The maximum number of glyphs that can be
            /// returned.</param>           
            /// <param name="clusterMap">The mapping from character ranges to glyph 
            /// ranges(out parameter).</param>
            /// <param name="textProps">Per-character output properties(out parameter).</param>
            /// <param name="glyphIndices">Output glyph indices(out parameter).</param>
            /// <param name="glyphProps">Per-glyph output properties(out parameter).</param>
            /// <param name="actualGlyphCount">The actual number of glyphs returned if
            /// the call succeeds(out parameter).</param>
            /// <param name="localeName">The optional locale to use when selecting glyphs.
            /// e.g. the same character may map to different glyphs for ja-jp vs zh-chs.
            /// If this is null then the default mapping based on the script is used.</param>
            /// <param name="numberSubstitution">Optional number substitution which
            /// selects the appropriate glyphs for digits and related numeric characters,
            /// depending on the results obtained from AnalyzeNumberSubstitution. Passing
            /// null indicates that no substitution is needed and that the digits should
            /// receive nominal glyphs.</param>
            /// <param name="features">An optional array of arrays of the sets of font 
            /// features to use in each feature range.</param>
            /// <param name="featureRangeLengths">The length of each feature range, in characters.  
            /// The sum of all lengths should be equal to text length.</param>       
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// Note that the mapping from characters to glyphs is, in general, many-
            /// to-many.  The recommended estimate for the per-glyph output buffers is
            /// (3 * textLength / 2 + 16).  This is not guaranteed to be sufficient.
            ///
            /// The value of the actualGlyphCount parameter is only valid if the call
            /// succeeds.  In the event that maxGlyphCount is not big enough
            /// E_NOT_SUFFICIENT_BUFFER, which is equivalent to HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER),
            /// will be returned.
            /// </remarks>
            HRESULT GetGlyphs(
                System::String ^textString,
                DWriteNet::IDWriteFontFace ^fontFace,
                bool isSideways,
                bool isRightToLeft,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_SCRIPT_ANALYSIS %scriptAnalysis,
                UINT32 maxGlyphCount,                
                [OutAttribute] array<UINT16> ^%clusterMap,
                [OutAttribute] array<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> ^%textProps,
                [OutAttribute] array<UINT16> ^%glyphIndices,
                [OutAttribute] array<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> ^%glyphProps,
                [OutAttribute] UINT32 %actualGlyphCount,
                [OptionalAttribute] System::String ^localeName,
                [OptionalAttribute] DWriteNet::IDWriteNumberSubstitution ^numberSubstitution,
                [OptionalAttribute] array<array<DWriteNet::DWRITE_FONT_FEATURE> ^> ^features,
                [OptionalAttribute] array<UINT32> ^featureRangeLengths
            );

            /// <summary>
            /// Place glyphs output from the GetGlyphs method according to the font 
            /// and the writing system's rendering rules.
            /// </summary>
            /// <param name="textString">The original string the glyphs came from.</param>
            /// <param name="clusterMap">The mapping from character ranges to glyph 
            /// ranges. Returned by GetGlyphs.</param>
            /// <param name="textProps">Per-character properties. Returned by 
            /// GetGlyphs.</param>
            /// <param name="glyphIndices">Glyph indices. See GetGlyphs</param>
            /// <param name="glyphProps">Per-glyph properties. See GetGlyphs</param>
            /// <param name="fontFace">The font face the glyphs came from.</param>
            /// <param name="fontEmSize">Logical font size in DIP's.</param>
            /// <param name="isSideways">Set to true if the text is intended to be
            /// drawn vertically.</param>
            /// <param name="isRightToLeft">Set to true for right-to-left text.</param>
            /// <param name="scriptAnalysis">Script analysis result from AnalyzeScript.</param>
            /// <param name="glyphAdvances">The advance width of each glyph(out parameter).</param>
            /// <param name="glyphOffsets">The offset of the origin of each glyph(out parameter).</param>
            /// <param name="localeName">The optional locale to use when selecting glyphs.
            /// e.g. the same character may map to different glyphs for ja-jp vs zh-chs.
            /// If this is null then the default mapping based on the script is used.</param>
            /// <param name="features">An optional array of arrays of the sets of font 
            /// features to use in each feature range.</param>
            /// <param name="featureRangeLengths">The length of each feature range, in characters.  
            /// The sum of all lengths should be equal to textLength.</param>           
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetGlyphPlacements(
                System::String ^textString,
                array<UINT16> ^clusterMap,
                array<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> ^textProps,
                array<UINT16> ^glyphIndices,
                array<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> ^glyphProps,
                DWriteNet::IDWriteFontFace ^fontFace,
                float fontEmSize,
                bool isSideways,
                bool isRightToLeft,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_SCRIPT_ANALYSIS %scriptAnalysis,
                [OutAttribute] array<FLOAT> ^%glyphAdvances,
                [OutAttribute] array<DWriteNet::DWRITE_GLYPH_OFFSET> ^%glyphOffsets,
                [OptionalAttribute] System::String ^localeName,
                [OptionalAttribute] array<array<DWriteNet::DWRITE_FONT_FEATURE> ^> ^features,
                [OptionalAttribute] array<UINT32> ^featureRangeLengths
            );

            /// <summary>
            /// Place glyphs output from the GetGlyphs method according to the font 
            /// and the writing system's rendering rules.
            /// </summary>
            /// <param name="textString">The original string the glyphs came from.</param>
            /// <param name="clusterMap">The mapping from character ranges to glyph 
            /// ranges. Returned by GetGlyphs.</param>
            /// <param name="textProps">Per-character properties. Returned by 
            /// GetGlyphs.</param>
            /// <param name="glyphIndices">Glyph indices. See GetGlyphs</param>
            /// <param name="glyphProps">Per-glyph properties. See GetGlyphs</param>
            /// <param name="fontFace">The font face the glyphs came from.</param>
            /// <param name="fontEmSize">Logical font size in DIP's.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if the DPI of
            /// the rendering surface is 96 this value is 1.0f. If the DPI is 120, this value is 120.0f/96.
            /// </param>
            /// <param name="useGdiNatural">
            /// When set to false, the metrics are the same as the metrics of GDI aliased text.
            /// When set to true, the metrics are the same as the metrics of text measured by GDI using a font
            /// created with CLEARTYPE_NATURAL_QUALITY.
            /// </param>
            /// <param name="isSideways">Set to true if the text is intended to be
            /// drawn vertically.</param>
            /// <param name="isRightToLeft">Set to true for right-to-left text.</param>
            /// <param name="scriptAnalysis">Script analysis result from AnalyzeScript.</param>
            /// <param name="glyphAdvances">The advance width of each glyph(out parameter).</param>
            /// <param name="glyphOffsets">The offset of the origin of each glyph(out parameter).</param>
            /// <param name="transform">Optional transform applied to the glyphs and their positions.
            /// This transform is applied after the scaling specified by the font size and pixelsPerDip.
            /// </param>
            /// <param name="localeName">The optional locale to use when selecting glyphs.
            /// e.g. the same character may map to different glyphs for ja-jp vs zh-chs.
            /// If this is null then the default mapping based on the script is used.</param>
            /// <param name="features">An optional array of arrays of the sets of font 
            /// features to use in each feature range.</param>
            /// <param name="featureRangeLengths">The length of each feature range, in characters.  
            /// The sum of all lengths should be equal to textLength.</param>           
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetGdiCompatibleGlyphPlacements(
                System::String ^textString,
                array<UINT16> ^clusterMap,
                array<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> ^textProps,
                array<UINT16> ^glyphIndices,
                array<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> ^glyphProps,
                DWriteNet::IDWriteFontFace ^fontFace,
                float fontEmSize,
                float pixelsPerDip,
                bool useGdiNatural,
                bool isSideways,
                bool isRightToLeft,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_SCRIPT_ANALYSIS %scriptAnalysis,
                [OutAttribute] array<FLOAT> ^%glyphAdvances,
                [OutAttribute] array<DWriteNet::DWRITE_GLYPH_OFFSET> ^%glyphOffsets,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform,
                [OptionalAttribute] System::String ^localeName,
                [OptionalAttribute] array<array<DWriteNet::DWRITE_FONT_FEATURE> ^> ^features,
                [OptionalAttribute] array<UINT32> ^featureRangeLengths
            );
        };
    }
}