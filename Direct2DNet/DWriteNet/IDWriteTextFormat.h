#pragma once

#include <msclr/marshal.h>

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;
        ref class IDWriteFontCollection;
        ref class IDWriteInlineObject;

        // Done.

        /// <summary>
        /// The format of text used for text layout.
        /// </summary>
        /// <remarks>
        /// This object may not be thread-safe and it may carry the state of text format change.
        /// </remarks>
        [System::Runtime::InteropServices::GuidAttribute("9c906818-31d7-4fd3-a151-7c5e225db55a")]
        public ref class IDWriteTextFormat : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteTextFormat *m_pFormat;

            IDWriteTextFormat() : m_pFormat(nullptr) {}

            IDWriteTextFormat(
                DWriteNet::IDWriteFactory ^factory,
                System::String ^fontFamilyName,
                DWriteNet::DWRITE_FONT_WEIGHT fontWeight,
                DWriteNet::DWRITE_FONT_STYLE fontStyle,
                DWriteNet::DWRITE_FONT_STRETCH fontStretch,
                float fontSize,
                System::String ^localeName
            );

        protected:
            IDWriteTextFormat(
                DWriteNet::IDWriteFactory ^factory
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

            virtual void HandleCOMInterface(void *obj);

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
            /// <param name="trimmingSign">Application-defined omission sign. This parameter may be null if 
            /// no trimming sign is desired.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetTrimming(
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_TRIMMING %trimmingOptions,
                [OptionalAttribute] DWriteNet::IDWriteInlineObject ^trimmingSign
            );

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
            /// <param name="trimmingOptions">The trimming options(out parameter).</param>
            /// <param name="trimmingSign">Trimming omission sign(out parameter). This parameter may be null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetTrimming(
                [OutAttribute] DWriteNet::DWRITE_TRIMMING %trimmingOptions,
                [OutAttribute] DWriteNet::IDWriteInlineObject ^%trimmingSign
            );

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

            /// <summary>
            /// Get the font collection.
            /// </summary>
            /// <param name="fontCollection">The current font collection(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontCollection(
                [OutAttribute] DWriteNet::IDWriteFontCollection ^%fontCollection
            );

            /// <summary>
            /// Get the font collection.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteFontCollection"/>) tuple. HRESULT is an error code.
            /// <see cref="DWriteNet::IDWriteFontCollection"/> is the font collection
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^> GetFontCollection();

            /// <summary>
            /// Gets the font family name.
            /// </summary>
            property System::String ^FontFamilyName
            {
                System::String ^get()
                {
                    UINT32 length = m_pFormat->GetFontFamilyNameLength() + 1;
                    std::vector<WCHAR> name(length);
                    m_pFormat->GetFontFamilyName(name.data(), length);

                    return marshal_as<System::String ^>(name.data());
                }
            }

            /// <summary>
            /// Gets the font weight.
            /// </summary>
            property DWriteNet::DWRITE_FONT_WEIGHT FontWeight
            {
                DWriteNet::DWRITE_FONT_WEIGHT get()
                {
                    return (DWriteNet::DWRITE_FONT_WEIGHT)((int)m_pFormat->GetFontWeight());
                }
            }

            /// <summary>
            /// Gets the font style.
            /// </summary>
            property DWriteNet::DWRITE_FONT_STYLE FontStyle
            {
                DWriteNet::DWRITE_FONT_STYLE get()
                {
                    return (DWriteNet::DWRITE_FONT_STYLE)((int)m_pFormat->GetFontStyle());
                }
            }

            /// <summary>
            /// Gets the font stretch.
            /// </summary>
            property DWriteNet::DWRITE_FONT_STRETCH FontStretch
            {
                DWriteNet::DWRITE_FONT_STRETCH get()
                {
                    return (DWriteNet::DWRITE_FONT_STRETCH)((int)m_pFormat->GetFontStretch());
                }
            }

            /// <summary>
            /// Gets the font em height.
            /// </summary>
            property float FontSize
            {
                float get()
                {
                    return m_pFormat->GetFontSize();
                }
            }

            /// <summary>
            /// Gets the locale name.
            /// </summary>
            property System::String ^LocaleName
            {
                System::String ^get()
                {
                    UINT32 length = m_pFormat->GetLocaleNameLength() + 1;
                    std::vector<WCHAR> name(length);
                    m_pFormat->GetLocaleName(name.data(), length);

                    return marshal_as<System::String ^>(name.data());
                }
            }
        };
    }
}