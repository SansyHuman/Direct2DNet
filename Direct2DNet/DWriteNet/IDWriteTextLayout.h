#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "IDWriteTextFormat.h"
#include <msclr/marshal.h>

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;
        ref class IDWriteFontCollection;
        ref class IDWriteTypography;
        ref class IDWriteInlineObject;

        /// <summary>
        /// The IDWriteTextLayout interface represents a block of text after it has
        /// been fully analyzed and formatted.
        ///
        /// All coordinates are in device independent pixels (DIPs).
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("53737037-6d14-410b-9bfe-0b182bb70961")]
        public ref class IDWriteTextLayout : DWriteNet::IDWriteTextFormat
        {
        internal:
            IDWriteTextLayout() : DWriteNet::IDWriteTextFormat() {}

            IDWriteTextLayout(
                DWriteNet::IDWriteFactory ^factory,
                System::String ^string,
                DWriteNet::IDWriteTextFormat ^textFormat,
                float maxWidth,
                float maxHeight
            );

            IDWriteTextLayout(
                DWriteNet::IDWriteFactory ^factory,
                System::String ^string,
                DWriteNet::IDWriteTextFormat ^textFormat,
                float layoutWidth,
                float layoutHeight,
                float pixelsPerDip,
                bool useGdiNatural,
                System::Nullable<DWriteNet::DWRITE_MATRIX> %transform
            );

        public:
            /// <summary>
            /// Sets layout maximum width
            /// </summary>
            /// <param name="maxWidth">Layout maximum width</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetMaxWidth(float maxWidth);

            /// <summary>
            /// Sets layout maximum height
            /// </summary>
            /// <param name="maxHeight">Layout maximum height</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetMaxHeight(float maxHeight);

            /// <summary>
            /// Sets the font collection.
            /// </summary>
            /// <param name="fontCollection">The font collection to set</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetFontCollection(
                DWriteNet::IDWriteFontCollection ^fontCollection,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets font family name.
            /// </summary>
            /// <param name="fontFamilyName">Font family name</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetFontFamilyName(
                System::String ^fontFamilyName,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets font weight.
            /// </summary>
            /// <param name="fontWeight">Font weight</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetFontWeight(
                DWriteNet::DWRITE_FONT_WEIGHT fontWeight,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets font style.
            /// </summary>
            /// <param name="fontStyle">Font style</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetFontStyle(
                DWriteNet::DWRITE_FONT_STYLE fontStyle,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets font stretch.
            /// </summary>
            /// <param name="fontStretch">font stretch</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetFontStretch(
                DWriteNet::DWRITE_FONT_STRETCH fontStretch,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets font em height.
            /// </summary>
            /// <param name="fontSize">Font em height</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetFontSize(
                float fontSize,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets underline.
            /// </summary>
            /// <param name="hasUnderline">The Boolean flag indicates whether underline takes place</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetUnderline(
                bool hasUnderline,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets strikethrough.
            /// </summary>
            /// <param name="hasStrikethrough">The Boolean flag indicates whether strikethrough takes place
            /// </param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetStrikethrough(
                bool hasStrikethrough,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets application-defined drawing effect.
            /// </summary>
            /// <param name="drawingEffect">An application-defined drawing effect.</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// An ID2D1Brush, such as a color or gradient brush, can be set as a drawing effect if you
            /// are using the ID2D1RenderTarget::DrawTextLayout to draw text and that brush will be used
            /// to draw the specified range of text.
            /// This drawing effect is associated with the specified range and will be passed back
            /// to the application via the callback when the range is drawn at drawing time.
            /// </remarks>
            HRESULT SetDrawingEffect(
                D2DNet::IUnknown ^drawingEffect,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Set inline object.
            /// </summary>
            /// <param name="inlineObject">An application-implemented inline object.</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// This inline object applies to the specified range and will be passed back
            /// to the application via the DrawInlineObject callback when the range is drawn.
            /// Any text in that range will be suppressed.
            /// </remarks>
            HRESULT SetInlineObject(
                DWriteNet::IDWriteInlineObject ^inlineObject,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets font typography features.
            /// </summary>
            /// <param name="typography">Font typography setting.</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetTypography(
                DWriteNet::IDWriteTypography ^typography,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Sets locale name.
            /// </summary>
            /// <param name="localeName">Locale name</param>
            /// <param name="textRange">Text range to which this change applies.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetLocaleName(
                System::String ^localeName,
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets layout maximum width
            /// </summary>
            float GetMaxWidth();

            /// <summary>
            /// Gets layout maximum height
            /// </summary>
            float GetMaxHeight();

            /// <summary>
            /// Gets the font collection where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="fontCollection">The current font collection(out parameter).</param>
            /// <param name="textRange">Text range to which this change applies(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontCollection(
                UINT32 currentPosition,
                [OutAttribute] DWriteNet::IDWriteFontCollection ^%fontCollection,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Copies the font family name where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="fontFamilyName">String that receives the current font family name
            /// (out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontFamilyName(
                UINT32 currentPosition,
                [OutAttribute] System::String ^%fontFamilyName,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the font weight where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="fontWeight">The current font weight(out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontWeight(
                UINT32 currentPosition,
                [OutAttribute] DWriteNet::DWRITE_FONT_WEIGHT %fontWeight,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the font style where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="fontStyle">The current font style(out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontStyle(
                UINT32 currentPosition,
                [OutAttribute] DWriteNet::DWRITE_FONT_STYLE %fontStyle,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the font stretch where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="fontStretch">The current font stretch(out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontStretch(
                UINT32 currentPosition,
                [OutAttribute] DWriteNet::DWRITE_FONT_STRETCH %fontStretch,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the font em height where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="fontSize">The current font em height(out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontSize(
                UINT32 currentPosition,
                [OutAttribute] float %fontSize,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the underline presence where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="hasUnderline">The Boolean flag indicates whether text is underlined
            /// (out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetUnderline(
                UINT32 currentPosition,
                [OutAttribute] bool %hasUnderline,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the strikethrough presence where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="hasStrikethrough">The Boolean flag indicates whether text has strikethrough
            /// (out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetStrikethrough(
                UINT32 currentPosition,
                [OutAttribute] bool %hasStrikethrough,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the application-defined drawing effect where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="drawingEffect">The current application-defined drawing effect(out parameter).
            /// </param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetDrawingEffect(
                UINT32 currentPosition,
                [OutAttribute] D2DNet::IUnknown ^%drawingEffect,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Get the inline object at the given position.
            /// </summary>
            /// <param name="currentPosition">The given text position.</param>
            /// <param name="inlineObject">The inline object(out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetInlineObject(
                UINT32 currentPosition,
                [OutAttribute] DWriteNet::IDWriteInlineObject ^%inlineObject,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Gets the typography setting where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="typography">The current typography setting(out parameter).</param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetTypography(
                UINT32 currentPosition,
                [OutAttribute] DWriteNet::IDWriteTypography ^%typography,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            /// <summary>
            /// Get the locale name where the current position is at.
            /// </summary>
            /// <param name="currentPosition">The current text position.</param>
            /// <param name="localeName">Character array that receives the current locale name(out parameter).
            /// </param>
            /// <param name="textRange">The position range of the current format(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetLocaleName(
                UINT32 currentPosition,
                [OutAttribute] System::String ^%localeName,
                [OutAttribute] DWriteNet::DWRITE_TEXT_RANGE %textRange
            );

            // Draw

            /// <summary>
            /// GetLineMetrics returns properties of each line.
            /// </summary>
            /// <param name="lineMetrics">The array to fill with line information(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetLineMetrics(
                [OutAttribute] array<DWriteNet::DWRITE_LINE_METRICS> ^%lineMetrics
            );

            /// <summary>
            /// GetMetrics retrieves overall metrics for the formatted string.
            /// </summary>
            /// <param name="textMetrics">The returned metrics(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// Drawing effects like underline and strikethrough do not contribute
            /// to the text size, which is essentially the sum of advance widths and
            /// line heights. Additionally, visible swashes and other graphic
            /// adornments may extend outside the returned width and height.
            /// </remarks>
            HRESULT GetMetrics(
                [OutAttribute] DWriteNet::DWRITE_TEXT_METRICS %textMetrics
            );

            /// <summary>
            /// GetOverhangMetrics returns the overhangs (in DIPs) of the layout and all
            /// objects contained in it, including text glyphs and inline objects.
            /// </summary>
            /// <param name="overhangs">Overshoots of visible extents (in DIPs) outside the layout
            /// (out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// Any underline and strikethrough do not contribute to the black box
            /// determination, since these are actually drawn by the renderer, which
            /// is allowed to draw them in any variety of styles.
            /// </remarks>
            HRESULT GetOverhangMetrics(
                [OutAttribute] DWriteNet::DWRITE_OVERHANG_METRICS %overhangs
            );

            /// <summary>
            /// Retrieve logical properties and measurement of each cluster.
            /// </summary>
            /// <param name="clusterMetrics">The array to fill with cluster information(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetClusterMetrics(
                [OutAttribute] array<DWriteNet::DWRITE_CLUSTER_METRICS> ^%clusterMetrics
            );

            /// <summary>
            /// Determines the minimum possible width the layout can be set to without
            /// emergency breaking between the characters of whole words.
            /// </summary>
            /// <param name="minWidth">Minimum width(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT DetermineMinWidth(
                [OutAttribute] float %minWidth
            );

            /// <summary>
            /// Given a coordinate (in DIPs) relative to the top-left of the layout box,
            /// this returns the corresponding hit-test metrics of the text string where
            /// the hit-test has occurred. This is useful for mapping mouse clicks to caret
            /// positions. When the given coordinate is outside the text string, the function
            /// sets the output value *isInside to false but returns the nearest character
            /// position.
            /// </summary>
            /// <param name="pointX">X coordinate to hit-test, relative to the top-left location of the
            /// layout box.</param>
            /// <param name="pointY">Y coordinate to hit-test, relative to the top-left location of the
            /// layout box.</param>
            /// <param name="isTrailingHit">Output flag indicating whether the hit-test location is at
            /// the leading or the trailing side of the character(out parameter). When the output isInside
            /// value is set to false, this value is set according to the output position value to represent
            /// the edge closest to the hit-test location. </param>
            /// <param name="isInside">Output flag indicating whether the hit-test location is inside the
            /// text string(out parameter). When false, the position nearest the text's edge is returned.
            /// </param>
            /// <param name="hitTestMetrics">Output geometry fully enclosing the hit-test location(out
            /// parameter). When the output isInside value is set to false, this structure represents the
            /// geometry enclosing the edge closest to the hit-test location.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT HitTestPoint(
                float pointX,
                float pointY,
                [OutAttribute] bool %isTrailingHit,
                [OutAttribute] bool %isInside,
                [OutAttribute] DWriteNet::DWRITE_HIT_TEST_METRICS %hitTestMetrics
            );

            /// <summary>
            /// Given a text position and whether the caret is on the leading or trailing
            /// edge of that position, this returns the corresponding coordinate (in DIPs)
            /// relative to the top-left of the layout box. This is most useful for drawing
            /// the caret's current position, but it could also be used to anchor an IME to the
            /// typed text or attach a floating menu near the point of interest. It may also be
            /// used to programmatically obtain the geometry of a particular text position
            /// for UI automation.
            /// </summary>
            /// <param name="textPosition">Text position to get the coordinate of.</param>
            /// <param name="isTrailingHit">Flag indicating whether the location is of the leading or the
            /// trailing side of the specified text position. </param>
            /// <param name="pointX">Output caret X, relative to the top-left of the layout box
            /// (out parameter).</param>
            /// <param name="pointY">Output caret Y, relative to the top-left of the layout box
            /// (out parameter).</param>
            /// <param name="hitTestMetrics">Output geometry fully enclosing the specified text position
            /// (out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// When drawing a caret at the returned X,Y, it should be centered on X
            /// and drawn from the Y coordinate down. The height will be the size of the
            /// hit-tested text (which can vary in size within a line).
            /// Reading direction also affects which side of the character the caret is drawn.
            /// However, the returned X coordinate will be correct for either case.
            /// You can get a text length back that is larger than a single character.
            /// This happens for complex scripts when multiple characters form a single cluster,
            /// when diacritics join their base character, or when you test a surrogate pair.
            /// </remarks>
            HRESULT HitTestTextPosition(
                UINT32 textPosition,
                bool isTrailingHit,
                [OutAttribute] float %pointX,
                [OutAttribute] float %pointY,
                [OutAttribute] DWriteNet::DWRITE_HIT_TEST_METRICS %hitTestMetrics
            );

            /// <summary>
            /// The application calls this function to get a set of hit-test metrics
            /// corresponding to a range of text positions. The main usage for this
            /// is to draw highlighted selection of the text string.
            /// </summary>
            /// <param name="textPosition">First text position of the specified range.</param>
            /// <param name="textLength">Number of positions of the specified range.</param>
            /// <param name="originX">Offset of the X origin (left of the layout box) which is added to each
            /// of the hit-test metrics returned.</param>
            /// <param name="originY">Offset of the Y origin (top of the layout box) which is added to each
            /// of the hit-test metrics returned.</param>
            /// <param name="hitTestMetrics">An array of the output geometry fully enclosing
            /// the specified position range(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// There are no gaps in the returned metrics. While there could be visual gaps,
            /// depending on bidi ordering, each range is contiguous and reports all the text,
            /// including any hidden characters and trimmed text.
            /// The height of each returned range will be the same within each line, regardless
            /// of how the font sizes vary.
            /// </remarks>
            HRESULT HitTestTextRange(
                UINT32 textPosition,
                UINT32 textLength,
                FLOAT originX,
                FLOAT originY,
                [OutAttribute] array<DWriteNet::DWRITE_HIT_TEST_METRICS> ^%hitTestMetrics
            );
        };
    }
}