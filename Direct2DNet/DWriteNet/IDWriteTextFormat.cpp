#include "IDWriteTextFormat.h"
#include "IDWriteFactory.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteTextFormat::IDWriteTextFormat(
            DWriteNet::IDWriteFactory ^factory,
            System::String ^fontFamilyName,
            DWriteNet::DWRITE_FONT_WEIGHT fontWeight,
            DWriteNet::DWRITE_FONT_STYLE fontStyle,
            DWriteNet::DWRITE_FONT_STRETCH fontStretch,
            float fontSize,
            System::String ^localeName
        ) : m_fontFamilyName(fontFamilyName), m_fontWeight(fontWeight), m_fontStyle(fontStyle),
            m_fontStretch(fontStretch), m_fontSize(fontSize)
        {
            marshal_context context;

            HRESULT hr = S_OK;
            pin_ptr<::IDWriteTextFormat *> ppFormat = &m_pFormat;
            hr = factory->m_pFactory->CreateTextFormat(
                context.marshal_as<const WCHAR *>(fontFamilyName),
                __nullptr,
                (::DWRITE_FONT_WEIGHT)((int)fontWeight),
                (::DWRITE_FONT_STYLE)((int)fontStyle),
                (::DWRITE_FONT_STRETCH)((int)fontStretch),
                fontSize,
                context.marshal_as<const WCHAR *>(localeName),
                (::IDWriteTextFormat **)ppFormat
            );
            ppFormat = nullptr;

            if(FAILED(hr))
                throw gcnew DWriteNet::Exception::DWriteException("Failed to create IDWriteFactory", (int)hr);

            UINT32 localeNameLength = m_pFormat->GetLocaleNameLength();
            array<WCHAR> ^nLocaleName = gcnew array<WCHAR>(localeNameLength + 1);
            pin_ptr<WCHAR> pLocaleName = &nLocaleName[0];
            hr = m_pFormat->GetLocaleName((WCHAR *)pLocaleName, localeNameLength + 1);
            if(FAILED(hr))
                m_localeName = "";
            else
                m_localeName = gcnew System::String(nLocaleName);
        }

        IDWriteTextFormat::~IDWriteTextFormat()
        {
            this->!IDWriteTextFormat();
        }

        IDWriteTextFormat::!IDWriteTextFormat()
        {
            if(m_pFormat)
            {
                m_pFormat->Release();
                m_pFormat = nullptr;
            }
        }

        HRESULT IDWriteTextFormat::SetTextAlignment(DWriteNet::DWRITE_TEXT_ALIGNMENT textAlignment)
        {
            return m_pFormat->SetTextAlignment((::DWRITE_TEXT_ALIGNMENT)((int)textAlignment));
        }

        HRESULT IDWriteTextFormat::SetParagraphAlignment(DWriteNet::DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment)
        {
            return m_pFormat->SetParagraphAlignment((::DWRITE_PARAGRAPH_ALIGNMENT)((int)paragraphAlignment));
        }

        HRESULT IDWriteTextFormat::SetWordWrapping(DWriteNet::DWRITE_WORD_WRAPPING wordWrapping)
        {
            return m_pFormat->SetWordWrapping((::DWRITE_WORD_WRAPPING)((int)wordWrapping));
        }

        HRESULT IDWriteTextFormat::SetReadingDirection(DWriteNet::DWRITE_READING_DIRECTION readingDirection)
        {
            return m_pFormat->SetReadingDirection((::DWRITE_READING_DIRECTION)((int)readingDirection));
        }

        HRESULT IDWriteTextFormat::SetFlowDirection(DWriteNet::DWRITE_FLOW_DIRECTION flowDirection)
        {
            return m_pFormat->SetFlowDirection((::DWRITE_FLOW_DIRECTION)((int)flowDirection));
        }

        HRESULT IDWriteTextFormat::SetIncrementalTabStop(float incrementalTabStop)
        {
            return m_pFormat->SetIncrementalTabStop(incrementalTabStop);
        }

        HRESULT IDWriteTextFormat::SetTrimming(DWriteNet::DWRITE_TRIMMING %trimmingOptions)
        {
            return m_pFormat->SetTrimming(&static_cast<::DWRITE_TRIMMING>(trimmingOptions), __nullptr);
        }

        HRESULT IDWriteTextFormat::SetLineSpacing(DWriteNet::DWRITE_LINE_SPACING_METHOD lineSpacingMethod, float lineSpacing, float baseline)
        {
            return m_pFormat->SetLineSpacing((::DWRITE_LINE_SPACING_METHOD)((int)lineSpacingMethod), lineSpacing, baseline);
        }

        System::ValueTuple<HRESULT, DWriteNet::DWRITE_TRIMMING> IDWriteTextFormat::GetTrimming()
        {
            ::DWRITE_TRIMMING trimming;
            ::IDWriteInlineObject *object;

            HRESULT hr = m_pFormat->GetTrimming(&trimming, &object);

            return System::ValueTuple<HRESULT, DWriteNet::DWRITE_TRIMMING>(
                hr,
                static_cast<DWriteNet::DWRITE_TRIMMING>(trimming)
                );
        }

        HRESULT IDWriteTextFormat::GetTrimming(DWriteNet::DWRITE_TRIMMING %trimming)
        {
            ::DWRITE_TRIMMING nativeTrimming;
            ::IDWriteInlineObject *object;

            HRESULT hr = m_pFormat->GetTrimming(&nativeTrimming, &object);

            trimming = static_cast<DWriteNet::DWRITE_TRIMMING>(nativeTrimming);

            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::DWRITE_LINE_SPACING_METHOD, float, float> IDWriteTextFormat::GetLineSpacing()
        {
            ::DWRITE_LINE_SPACING_METHOD method;
            float lineSpacing;
            float baseline;

            HRESULT hr = m_pFormat->GetLineSpacing(&method, &lineSpacing, &baseline);

            return System::ValueTuple<HRESULT, DWriteNet::DWRITE_LINE_SPACING_METHOD, float, float>(
                hr,
                static_cast<DWriteNet::DWRITE_LINE_SPACING_METHOD>(method),
                lineSpacing,
                baseline
                );
        }

        HRESULT IDWriteTextFormat::GetLineSpacing(DWriteNet::DWRITE_LINE_SPACING_METHOD %lineSpacingMethod, float %lineSpacing, float %baseline)
        {
            ::DWRITE_LINE_SPACING_METHOD method;

            pin_ptr<float> pLineSpacing = &lineSpacing, pBaseline = &baseline;
            HRESULT hr = m_pFormat->GetLineSpacing(&method, (FLOAT *)pLineSpacing, (FLOAT *)pBaseline);
            pLineSpacing = nullptr;
            pBaseline = nullptr;

            lineSpacingMethod = (DWriteNet::DWRITE_LINE_SPACING_METHOD)((int)method);

            return hr;
        }

    }
}