#pragma once

#include <msclr/marshal.h>

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "Exception/DWriteException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;

        // TODO: IDWriteInlineObject implementation.

        /// <summary>
        /// The format of text used for text layout.
        /// </summary>
        /// <remarks>
        /// This object may not be thread-safe and it may carry the state of text format change.
        /// </remarks>
        [System::Runtime::InteropServices::GuidAttribute("4A66B759-F56E-4F60-8AA4-C03625F2DB81")]
        public ref class IDWriteTextFormat : DWriteNet::IDirectWriteObject
        {
        private:
            System::String ^m_fontFamilyName;
            DWriteNet::DWRITE_FONT_WEIGHT m_fontWeight;
            DWriteNet::DWRITE_FONT_STYLE m_fontStyle;
            DWriteNet::DWRITE_FONT_STRETCH m_fontStretch;
            float m_fontSize;
            System::String ^m_localeName;

        internal:
            ::IDWriteTextFormat *m_pFormat;

            IDWriteTextFormat(
                DWriteNet::IDWriteFactory ^factory,
                System::String ^fontFamilyName,
                DWriteNet::DWRITE_FONT_WEIGHT fontWeight,
                DWriteNet::DWRITE_FONT_STYLE fontStyle,
                DWriteNet::DWRITE_FONT_STRETCH fontStretch,
                float fontSize,
                System::String ^localeName
            );

        public:
            ~IDWriteTextFormat();
            !IDWriteTextFormat();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pFormat;
                }
            }

            /// <summary>
            /// Set alignment option of text relative to layout box's leading and trailing edge.
            /// </summary>
            /// <param name="textAlignment">Text alignment option</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetTextAlignment(DWriteNet::DWRITE_TEXT_ALIGNMENT textAlignment);

            /// <summary>
            /// Set alignment option of paragraph relative to layout box's top and bottom edge.
            /// </summary>
            /// <param name="paragraphAlignment">Paragraph alignment option</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetParagraphAlignment(DWriteNet::DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment);

            /// <summary>
            /// Set word wrapping option.
            /// </summary>
            /// <param name="wordWrapping">Word wrapping option</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetWordWrapping(DWriteNet::DWRITE_WORD_WRAPPING wordWrapping);

            /// <summary>
            /// Set paragraph reading direction.
            /// </summary>
            /// <param name="readingDirection">Text reading direction</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// The flow direction must be perpendicular to the reading direction.
            /// Setting both to a vertical direction or both to horizontal yields
            /// <see cref="DWriteNet::DWriteError::E_FLOWDIRECTIONCONFLICTS"/> when calling GetMetrics or Draw.
            /// </remarks>
            HRESULT SetReadingDirection(DWriteNet::DWRITE_READING_DIRECTION readingDirection);

            /// <summary>
            /// Set paragraph flow direction.
            /// </summary>
            /// <param name="flowDirection">Paragraph flow direction</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            /// <remarks>
            /// The flow direction must be perpendicular to the reading direction.
            /// Setting both to a vertical direction or both to horizontal yields
            /// <see cref="DWriteNet::DWriteError::E_FLOWDIRECTIONCONFLICTS"/> when calling GetMetrics or Draw.
            /// </remark>
            HRESULT SetFlowDirection(DWriteNet::DWRITE_FLOW_DIRECTION flowDirection);

            /// <summary>
            /// Set incremental tab stop position.
            /// </summary>
            /// <param name="incrementalTabStop">The incremental tab stop value</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetIncrementalTabStop(float incrementalTabStop);

            /// <summary>
            /// Set trimming options for any trailing text exceeding the layout width
            /// or for any far text exceeding the layout height.
            /// </summary>
            /// <param name="trimmingOptions">Text trimming options.</param>
            /// <param name="trimmingSign">Application-defined omission sign. This parameter may be NULL if no trimming sign is desired.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetTrimming(
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TRIMMING %trimmingOptions);

            /// <summary>
            /// Set line spacing.
            /// </summary>
            /// <param name="lineSpacingMethod">How to determine line height.</param>
            /// <param name="lineSpacing">The line height, or rather distance between one baseline to another.</param>
            /// <param name="baseline">Distance from top of line to baseline. A reasonable ratio to lineSpacing is 80%.</param>
            /// <remarks>
            /// For the default method, spacing depends solely on the content.
            /// For uniform spacing, the given line height will override the content.
            /// </remarks>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetLineSpacing(
                DWriteNet::DWRITE_LINE_SPACING_METHOD lineSpacingMethod, float lineSpacing, float baseline);

            /// <summary>
            /// Gets alignment option of text relative to layout box's leading and trailing edge.
            /// </summary>
            property DWriteNet::DWRITE_TEXT_ALIGNMENT TextAlignment
            {
                DWriteNet::DWRITE_TEXT_ALIGNMENT get()
                {
                    return (DWriteNet::DWRITE_TEXT_ALIGNMENT)((int)m_pFormat->GetTextAlignment());
                }
            }

            /// <summary>
            /// Gets alignment option of paragraph relative to layout box's top and bottom edge.
            /// </summary>
            property DWriteNet::DWRITE_PARAGRAPH_ALIGNMENT ParagraphAlignment
            {
                DWriteNet::DWRITE_PARAGRAPH_ALIGNMENT get()
                {
                    return (DWriteNet::DWRITE_PARAGRAPH_ALIGNMENT)((int)m_pFormat->GetParagraphAlignment());
                }
            }

            /// <summary>
            /// Gets word wrapping option.
            /// </summary>
            property DWriteNet::DWRITE_WORD_WRAPPING WordWrapping
            {
                DWriteNet::DWRITE_WORD_WRAPPING get()
                {
                    return (DWriteNet::DWRITE_WORD_WRAPPING)((int)m_pFormat->GetWordWrapping());
                }
            }

            /// <summary>
            /// Gets paragraph reading direction.
            /// </summary>
            property DWriteNet::DWRITE_READING_DIRECTION ReadingDirection
            {
                DWriteNet::DWRITE_READING_DIRECTION get()
                {
                    return (DWriteNet::DWRITE_READING_DIRECTION)((int)m_pFormat->GetReadingDirection());
                }
            }

            /// <summary>
            /// Gets paragraph flow direction.
            /// </summary>
            property DWriteNet::DWRITE_FLOW_DIRECTION FlowDirection
            {
                DWriteNet::DWRITE_FLOW_DIRECTION get()
                {
                    return (DWriteNet::DWRITE_FLOW_DIRECTION)((int)m_pFormat->GetFlowDirection());
                }
            }

            /// <summary>
            /// Gets incremental tab stop position.
            /// </summary>
            property float IncrementalTabStop
            {
                float get()
                {
                    return m_pFormat->GetIncrementalTabStop();
                }
            }

            /// <summary>
            /// Gets trimming options for text overflowing the layout width.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::DWRITE_TRIMMING"/>) tuple.
            /// HRESULT is an error code.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::DWRITE_TRIMMING> GetTrimming();


            /// <summary>
            /// Gets trimming options for text overflowing the layout width.
            /// </summary>
            /// <param name="trimming">The trimming options(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetTrimming([OutAttribute] DWriteNet::DWRITE_TRIMMING %trimming);

            /// <summary>
            /// Gets line spacing.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::DWRITE_LINE_SPACING_METHOD"/>, float, float) tuple.
            /// HRESULT is an error code. The first float is line spacing. The second float ia baseline.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::DWRITE_LINE_SPACING_METHOD, float, float> GetLineSpacing();

            /// <summary>
            /// Gets line spacing.
            /// </summary>
            /// <param name="lineSpacingMethod">The line spacing method(out parameter).</param>
            /// <param name="trimming">The distance between one baseline to another.(out parameter).</param>
            /// <param name="trimming">The distance from top of line to baseline(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetLineSpacing(
                [OutAttribute] DWriteNet::DWRITE_LINE_SPACING_METHOD %lineSpacingMethod,
                [OutAttribute] float %lineSpacing,
                [OutAttribute] float %baseline
            );

            // GetFontCollection

            /// <summary>
            /// Gets the font family name.
            /// </summary>
            property System::String ^FontFamilyName
            {
                System::String ^get()
                {
                    return m_fontFamilyName;
                }
            }

            /// <summary>
            /// Gets the font weight.
            /// </summary>
            property DWriteNet::DWRITE_FONT_WEIGHT FontWeight
            {
                DWriteNet::DWRITE_FONT_WEIGHT get()
                {
                    return m_fontWeight;
                }
            }

            /// <summary>
            /// Gets the font style.
            /// </summary>
            property DWriteNet::DWRITE_FONT_STYLE FontStyle
            {
                DWriteNet::DWRITE_FONT_STYLE get()
                {
                    return m_fontStyle;
                }
            }

            /// <summary>
            /// Gets the font stretch.
            /// </summary>
            property DWriteNet::DWRITE_FONT_STRETCH FontStretch
            {
                DWriteNet::DWRITE_FONT_STRETCH get()
                {
                    return m_fontStretch;
                }
            }

            /// <summary>
            /// Gets the font em height.
            /// </summary>
            property float FontSize
            {
                float get()
                {
                    return m_fontSize;
                }
            }

            /// <summary>
            /// Gets the locale name.
            /// </summary>
            property System::String ^LocaleName
            {
                System::String ^get()
                {
                    return m_localeName;
                }
            }
        };
    }
}