#include "IDWriteTextAnalyzer.h"
#include "IDWriteFactory.h"
#include "IDWriteTextAnalysisSource.h"
#include "IDWriteTextAnalysisSink.h"
#include "IDWriteFontFace.h"
#include "IDWriteNumberSubstitution.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteTextAnalyzer::IDWriteTextAnalyzer(DWriteNet::IDWriteFactory ^factory)
        {
            pin_ptr<::IDWriteTextAnalyzer *> ppAnal = &m_pAnalyzer;
            HRESULT hr = factory->m_pFactory->CreateTextAnalyzer(
                (::IDWriteTextAnalyzer **)ppAnal
            );
            ppAnal = nullptr;
            
            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteTextAnalyzer.", (int)hr);
        }

        IDWriteTextAnalyzer::~IDWriteTextAnalyzer()
        {
            this->!IDWriteTextAnalyzer();
        }

        IDWriteTextAnalyzer::!IDWriteTextAnalyzer()
        {
            if(m_pAnalyzer)
            {
                m_pAnalyzer->Release();
                m_pAnalyzer = nullptr;
            }
        }

        void IDWriteTextAnalyzer::HandleCOMInterface(void *obj)
        {
            if(m_pAnalyzer)
            {
                m_pAnalyzer->Release();
            }

            m_pAnalyzer = (::IDWriteTextAnalyzer *)obj;
            m_pAnalyzer->AddRef();
        }

        HRESULT IDWriteTextAnalyzer::AnalyzeScript(
            DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
            UINT32 textPosition,
            UINT32 textLength,
            DWriteNet::IDWriteTextAnalysisSink ^analysisSink)
        {
            return m_pAnalyzer->AnalyzeScript(
                analysisSource->m_pSource,
                textPosition,
                textLength,
                analysisSink->m_pSink
            );
        }

        HRESULT IDWriteTextAnalyzer::AnalyzeBidi(
            DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
            UINT32 textPosition,
            UINT32 textLength,
            DWriteNet::IDWriteTextAnalysisSink ^analysisSink)
        {
            return m_pAnalyzer->AnalyzeBidi(
                analysisSource->m_pSource,
                textPosition,
                textLength,
                analysisSink->m_pSink
            );
        }

        HRESULT IDWriteTextAnalyzer::AnalyzeNumberSubstitution(
            DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
            UINT32 textPosition,
            UINT32 textLength,
            DWriteNet::IDWriteTextAnalysisSink ^analysisSink)
        {
            return m_pAnalyzer->AnalyzeNumberSubstitution(
                analysisSource->m_pSource,
                textPosition,
                textLength,
                analysisSink->m_pSink
            );
        }

        HRESULT IDWriteTextAnalyzer::AnalyzeLineBreakpoints(
            DWriteNet::IDWriteTextAnalysisSource ^analysisSource,
            UINT32 textPosition, UINT32 textLength,
            DWriteNet::IDWriteTextAnalysisSink ^analysisSink)
        {
            return m_pAnalyzer->AnalyzeLineBreakpoints(
                analysisSource->m_pSource,
                textPosition,
                textLength,
                analysisSink->m_pSink
            );
        }

        HRESULT IDWriteTextAnalyzer::GetGlyphs(
            System::String ^textString,
            DWriteNet::IDWriteFontFace ^fontFace,
            bool isSideways,
            bool isRightToLeft,
            DWriteNet::DWRITE_SCRIPT_ANALYSIS %scriptAnalysis,
            UINT32 maxGlyphCount,          
            array<UINT16> ^%clusterMap,
            array<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> ^%textProps,
            array<UINT16> ^%glyphIndices,
            array<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> ^%glyphProps,
            UINT32 %actualGlyphCount,
            System::String ^localeName,
            DWriteNet::IDWriteNumberSubstitution ^numberSubstitution,
            array<array<DWriteNet::DWRITE_FONT_FEATURE> ^> ^features,
            array<UINT32> ^featureRangeLengths)
        {
            if(features)
            {
                if(featureRangeLengths)
                {
                    if(features->Length != featureRangeLengths->Length)
                        return E_INVALIDARG;
                }
                else
                    return E_INVALIDARG;
            }
            else
            {
                if(featureRangeLengths)
                {
                    return E_INVALIDARG;
                }
            }

            marshal_context context;

            if(textString->Length == 0)
                return S_OK;

            HRESULT hr = S_OK;

            const WCHAR *nativeText = context.marshal_as<const WCHAR *>(textString);
            UINT32 textLength = wcslen(nativeText);

            pin_ptr<DWriteNet::DWRITE_SCRIPT_ANALYSIS> pAnalysis = &scriptAnalysis;

            const WCHAR *nativeLocale = !localeName ? __nullptr : context.marshal_as<const WCHAR *>(localeName);

            UINT32 featureRanges = features == nullptr ? 0 : features->Length;

            clusterMap = gcnew array<UINT16>(textLength);
            textProps = gcnew array<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES>(textLength);
            glyphIndices = gcnew array<UINT16>(maxGlyphCount);
            glyphProps = gcnew array<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES>(maxGlyphCount);

            pin_ptr<UINT16> pCluster = &clusterMap[0];
            pin_ptr<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> pTextProps = &textProps[0];
            pin_ptr<UINT16> pIndices = &glyphIndices[0];
            pin_ptr<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> pGlyphProps = &glyphProps[0];
            pin_ptr<UINT32> pAGlyphCnt = &actualGlyphCount;

            if(features && featureRanges != 0U)
            {
                std::vector<::DWRITE_TYPOGRAPHIC_FEATURES *> ppFeatures(featureRanges);
                std::vector<::DWRITE_TYPOGRAPHIC_FEATURES> pFeatures(featureRanges);
                array<GCHandle> ^featurePins = gcnew array<GCHandle>(featureRanges);

                for(UINT32 i = 0; i < featureRanges; i++)
                {
                    featurePins[i] = GCHandle::Alloc(features[i], GCHandleType::Pinned);
                    pFeatures[i] = {
                        reinterpret_cast<::DWRITE_FONT_FEATURE *>(featurePins[i].AddrOfPinnedObject().ToPointer()),
                        (UINT32)features[i]->Length
                    };
                    ppFeatures[i] = &pFeatures[i];
                }

                pin_ptr<UINT32> pRangeLens = &featureRangeLengths[0];

                hr = m_pAnalyzer->GetGlyphs(
                    nativeText,
                    textLength,
                    fontFace->m_pFace,
                    System::Convert::ToInt32(isSideways),
                    System::Convert::ToInt32(isRightToLeft),
                    reinterpret_cast<::DWRITE_SCRIPT_ANALYSIS *>(pAnalysis),
                    nativeLocale,
                    !numberSubstitution ? __nullptr : numberSubstitution->m_pSub,
                    (const ::DWRITE_TYPOGRAPHIC_FEATURES **)ppFeatures.data(),
                    reinterpret_cast<UINT32 *>(pRangeLens),
                    featureRanges,
                    maxGlyphCount,
                    reinterpret_cast<UINT16 *>(pCluster),
                    reinterpret_cast<::DWRITE_SHAPING_TEXT_PROPERTIES *>(pTextProps),
                    reinterpret_cast<UINT16 *>(pIndices),
                    reinterpret_cast<::DWRITE_SHAPING_GLYPH_PROPERTIES *>(pGlyphProps),
                    reinterpret_cast<UINT32 *>(pAGlyphCnt)
                );

                for(UINT32 i = 0; i < featureRanges; i++)
                {
                    if(featurePins[i].IsAllocated)
                        featurePins[i].Free();
                }
            }
            else
            {
                hr = m_pAnalyzer->GetGlyphs(
                    nativeText,
                    textLength,
                    fontFace->m_pFace,
                    System::Convert::ToInt32(isSideways),
                    System::Convert::ToInt32(isRightToLeft),
                    reinterpret_cast<::DWRITE_SCRIPT_ANALYSIS *>(pAnalysis),
                    nativeLocale,
                    !numberSubstitution ? __nullptr : numberSubstitution->m_pSub,
                    __nullptr,
                    __nullptr,
                    featureRanges,
                    maxGlyphCount,
                    reinterpret_cast<UINT16 *>(pCluster),
                    reinterpret_cast<::DWRITE_SHAPING_TEXT_PROPERTIES *>(pTextProps),
                    reinterpret_cast<UINT16 *>(pIndices),
                    reinterpret_cast<::DWRITE_SHAPING_GLYPH_PROPERTIES *>(pGlyphProps),
                    reinterpret_cast<UINT32 *>(pAGlyphCnt)
                );
            }

            if(FAILED(hr))
            {
                delete clusterMap;
                clusterMap = nullptr;
                delete textProps;
                textProps = nullptr;
                delete glyphIndices;
                glyphIndices = nullptr;
                delete glyphProps;
                glyphProps = nullptr;
            }

            return hr;
        }

        HRESULT IDWriteTextAnalyzer::GetGlyphPlacements(
            System::String ^textString,
            array<UINT16> ^clusterMap,
            array<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> ^textProps,
            array<UINT16> ^glyphIndices,
            array<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> ^glyphProps,
            DWriteNet::IDWriteFontFace ^fontFace,
            float fontEmSize,
            bool isSideways,
            bool isRightToLeft,
            DWriteNet::DWRITE_SCRIPT_ANALYSIS %scriptAnalysis,
            array<FLOAT> ^%glyphAdvances,
            array<DWriteNet::DWRITE_GLYPH_OFFSET> ^%glyphOffsets,
            System::String ^localeName,
            array<array<DWriteNet::DWRITE_FONT_FEATURE> ^> ^features,
            array<UINT32> ^featureRangeLengths)
        {
            if(features)
            {
                if(featureRangeLengths)
                {
                    if(features->Length != featureRangeLengths->Length)
                        return E_INVALIDARG;
                }
                else
                    return E_INVALIDARG;
            }
            else
            {
                if(featureRangeLengths)
                {
                    return E_INVALIDARG;
                }
            }

            marshal_context context;

            HRESULT hr = S_OK;

            const WCHAR *nativeText = context.marshal_as<const WCHAR *>(textString);
            UINT32 textLength = wcslen(nativeText);
            if(clusterMap->Length != textLength || textProps->Length != textLength)
                return E_INVALIDARG;
            if(textLength == 0)
                return S_OK;

            pin_ptr<UINT16> pCluster = &clusterMap[0];
            pin_ptr<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> pTextProps = &textProps[0];

            UINT32 glyphCount = glyphIndices->Length;
            if(glyphProps->Length != glyphCount || glyphCount == 0)
                return E_INVALIDARG;

            pin_ptr<UINT16> pGlyphInds = &glyphIndices[0];
            pin_ptr<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> pGlyphProps = &glyphProps[0];

            pin_ptr<DWriteNet::DWRITE_SCRIPT_ANALYSIS> pAnal = &scriptAnalysis;

            const WCHAR *nativeLocale = !localeName ? __nullptr : context.marshal_as<const WCHAR *>(localeName);

            UINT32 featureRanges = features == nullptr ? 0 : features->Length;

            glyphAdvances = gcnew array<FLOAT>(glyphCount);
            glyphOffsets = gcnew array<DWriteNet::DWRITE_GLYPH_OFFSET>(glyphCount);
            pin_ptr<FLOAT> pAdvances = &glyphAdvances[0];
            pin_ptr<DWriteNet::DWRITE_GLYPH_OFFSET> pOffsets = &glyphOffsets[0];

            if(features && featureRanges != 0U)
            {
                std::vector<::DWRITE_TYPOGRAPHIC_FEATURES *> ppFeatures(featureRanges);
                std::vector<::DWRITE_TYPOGRAPHIC_FEATURES> pFeatures(featureRanges);
                array<GCHandle> ^featurePins = gcnew array<GCHandle>(featureRanges);

                for(UINT32 i = 0; i < featureRanges; i++)
                {
                    featurePins[i] = GCHandle::Alloc(features[i], GCHandleType::Pinned);
                    pFeatures[i] = {
                        reinterpret_cast<::DWRITE_FONT_FEATURE *>(featurePins[i].AddrOfPinnedObject().ToPointer()),
                        (UINT32)features[i]->Length
                    };
                    ppFeatures[i] = &pFeatures[i];
                }

                pin_ptr<UINT32> pRangeLens = &featureRangeLengths[0];

                hr = m_pAnalyzer->GetGlyphPlacements(
                    nativeText,
                    reinterpret_cast<UINT16 *>(pCluster),
                    reinterpret_cast<::DWRITE_SHAPING_TEXT_PROPERTIES *>(pTextProps),
                    textLength,
                    reinterpret_cast<UINT16 *>(pGlyphInds),
                    reinterpret_cast<::DWRITE_SHAPING_GLYPH_PROPERTIES *>(pGlyphProps),
                    glyphCount,
                    fontFace->m_pFace,
                    fontEmSize,
                    System::Convert::ToInt32(isSideways),
                    System::Convert::ToInt32(isRightToLeft),
                    reinterpret_cast<::DWRITE_SCRIPT_ANALYSIS *>(pAnal),
                    nativeLocale,
                    (const ::DWRITE_TYPOGRAPHIC_FEATURES **)ppFeatures.data(),
                    reinterpret_cast<UINT32 *>(pRangeLens),
                    featureRanges,
                    reinterpret_cast<FLOAT *>(pAdvances),
                    reinterpret_cast<::DWRITE_GLYPH_OFFSET *>(pOffsets)
                );

                for(UINT32 i = 0; i < featureRanges; i++)
                {
                    if(featurePins[i].IsAllocated)
                        featurePins[i].Free();
                }
            }
            else
            {
                hr = m_pAnalyzer->GetGlyphPlacements(
                    nativeText,
                    reinterpret_cast<UINT16 *>(pCluster),
                    reinterpret_cast<::DWRITE_SHAPING_TEXT_PROPERTIES *>(pTextProps),
                    textLength,
                    reinterpret_cast<UINT16 *>(pGlyphInds),
                    reinterpret_cast<::DWRITE_SHAPING_GLYPH_PROPERTIES *>(pGlyphProps),
                    glyphCount,
                    fontFace->m_pFace,
                    fontEmSize,
                    System::Convert::ToInt32(isSideways),
                    System::Convert::ToInt32(isRightToLeft),
                    reinterpret_cast<::DWRITE_SCRIPT_ANALYSIS *>(pAnal),
                    nativeLocale,
                    __nullptr,
                    __nullptr,
                    featureRanges,
                    reinterpret_cast<FLOAT *>(pAdvances),
                    reinterpret_cast<::DWRITE_GLYPH_OFFSET *>(pOffsets)
                );
            }

            if(FAILED(hr))
            {
                delete glyphAdvances;
                glyphAdvances = nullptr;
                delete glyphOffsets;
                glyphOffsets = nullptr;
            }

            return hr;
        }

        HRESULT IDWriteTextAnalyzer::GetGdiCompatibleGlyphPlacements(
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
            DWriteNet::DWRITE_SCRIPT_ANALYSIS %scriptAnalysis,
            array<FLOAT> ^%glyphAdvances,
            array<DWriteNet::DWRITE_GLYPH_OFFSET> ^%glyphOffsets,
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform,
            System::String ^localeName,
            array<array<DWriteNet::DWRITE_FONT_FEATURE> ^> ^features,
            array<UINT32> ^featureRangeLengths)
        {
            if(features)
            {
                if(featureRangeLengths)
                {
                    if(features->Length != featureRangeLengths->Length)
                        return E_INVALIDARG;
                }
                else
                    return E_INVALIDARG;
            }
            else
            {
                if(featureRangeLengths)
                {
                    return E_INVALIDARG;
                }
            }

            marshal_context context;

            HRESULT hr = S_OK;

            const WCHAR *nativeText = context.marshal_as<const WCHAR *>(textString);
            UINT32 textLength = wcslen(nativeText);
            if(clusterMap->Length != textLength || textProps->Length != textLength)
                return E_INVALIDARG;
            if(textLength == 0)
                return S_OK;

            pin_ptr<UINT16> pCluster = &clusterMap[0];
            pin_ptr<DWriteNet::DWRITE_SHAPING_TEXT_PROPERTIES> pTextProps = &textProps[0];

            UINT32 glyphCount = glyphIndices->Length;
            if(glyphProps->Length != glyphCount || glyphCount == 0)
                return E_INVALIDARG;

            pin_ptr<UINT16> pGlyphInds = &glyphIndices[0];
            pin_ptr<DWriteNet::DWRITE_SHAPING_GLYPH_PROPERTIES> pGlyphProps = &glyphProps[0];

            pin_ptr<DWriteNet::DWRITE_MATRIX> pTranform = nullptr;
            if(transform.HasValue)
                pTranform = &transform.Value;

            pin_ptr<DWriteNet::DWRITE_SCRIPT_ANALYSIS> pAnal = &scriptAnalysis;

            const WCHAR *nativeLocale = !localeName ? __nullptr : context.marshal_as<const WCHAR *>(localeName);

            UINT32 featureRanges = features == nullptr ? 0 : features->Length;

            glyphAdvances = gcnew array<FLOAT>(glyphCount);
            glyphOffsets = gcnew array<DWriteNet::DWRITE_GLYPH_OFFSET>(glyphCount);
            pin_ptr<FLOAT> pAdvances = &glyphAdvances[0];
            pin_ptr<DWriteNet::DWRITE_GLYPH_OFFSET> pOffsets = &glyphOffsets[0];

            if(features && featureRanges != 0U)
            {
                std::vector<::DWRITE_TYPOGRAPHIC_FEATURES *> ppFeatures(featureRanges);
                std::vector<::DWRITE_TYPOGRAPHIC_FEATURES> pFeatures(featureRanges);
                array<GCHandle> ^featurePins = gcnew array<GCHandle>(featureRanges);

                for(UINT32 i = 0; i < featureRanges; i++)
                {
                    featurePins[i] = GCHandle::Alloc(features[i], GCHandleType::Pinned);
                    pFeatures[i] = {
                        reinterpret_cast<::DWRITE_FONT_FEATURE *>(featurePins[i].AddrOfPinnedObject().ToPointer()),
                        (UINT32)features[i]->Length
                    };
                    ppFeatures[i] = &pFeatures[i];
                }

                pin_ptr<UINT32> pRangeLens = &featureRangeLengths[0];

                hr = m_pAnalyzer->GetGdiCompatibleGlyphPlacements(
                    nativeText,
                    reinterpret_cast<UINT16 *>(pCluster),
                    reinterpret_cast<::DWRITE_SHAPING_TEXT_PROPERTIES *>(pTextProps),
                    textLength,
                    reinterpret_cast<UINT16 *>(pGlyphInds),
                    reinterpret_cast<::DWRITE_SHAPING_GLYPH_PROPERTIES *>(pGlyphProps),
                    glyphCount,
                    fontFace->m_pFace,
                    fontEmSize,
                    pixelsPerDip,
                    reinterpret_cast<::DWRITE_MATRIX *>(pTranform),
                    System::Convert::ToInt32(useGdiNatural),
                    System::Convert::ToInt32(isSideways),
                    System::Convert::ToInt32(isRightToLeft),
                    reinterpret_cast<::DWRITE_SCRIPT_ANALYSIS *>(pAnal),
                    nativeLocale,
                    (const ::DWRITE_TYPOGRAPHIC_FEATURES **)ppFeatures.data(),
                    reinterpret_cast<UINT32 *>(pRangeLens),
                    featureRanges,
                    reinterpret_cast<FLOAT *>(pAdvances),
                    reinterpret_cast<::DWRITE_GLYPH_OFFSET *>(pOffsets)
                );

                for(UINT32 i = 0; i < featureRanges; i++)
                {
                    if(featurePins[i].IsAllocated)
                        featurePins[i].Free();
                }
            }
            else
            {
                hr = m_pAnalyzer->GetGdiCompatibleGlyphPlacements(
                    nativeText,
                    reinterpret_cast<UINT16 *>(pCluster),
                    reinterpret_cast<::DWRITE_SHAPING_TEXT_PROPERTIES *>(pTextProps),
                    textLength,
                    reinterpret_cast<UINT16 *>(pGlyphInds),
                    reinterpret_cast<::DWRITE_SHAPING_GLYPH_PROPERTIES *>(pGlyphProps),
                    glyphCount,
                    fontFace->m_pFace,
                    fontEmSize,
                    pixelsPerDip,
                    reinterpret_cast<::DWRITE_MATRIX *>(pTranform),
                    System::Convert::ToInt32(useGdiNatural),
                    System::Convert::ToInt32(isSideways),
                    System::Convert::ToInt32(isRightToLeft),
                    reinterpret_cast<::DWRITE_SCRIPT_ANALYSIS *>(pAnal),
                    nativeLocale,
                    __nullptr,
                    __nullptr,
                    featureRanges,
                    reinterpret_cast<FLOAT *>(pAdvances),
                    reinterpret_cast<::DWRITE_GLYPH_OFFSET *>(pOffsets)
                );
            }

            if(FAILED(hr))
            {
                delete glyphAdvances;
                glyphAdvances = nullptr;
                delete glyphOffsets;
                glyphOffsets = nullptr;
            }

            return hr;
        }

    }
}