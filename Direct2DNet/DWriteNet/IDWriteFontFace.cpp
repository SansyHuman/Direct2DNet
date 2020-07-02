#include "IDWriteFontFace.h"
#include "IDWriteFactory.h"
#include "IDWriteFontFile.h"
#include "IDWriteRenderingParams.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        
        IDWriteFontFace::IDWriteFontFace(
            DWriteNet::IDWriteFactory ^factory,
            DWriteNet::DWRITE_FONT_FACE_TYPE fontFaceType,
            array<DWriteNet::IDWriteFontFile ^> ^fontFiles,
            UINT32 faceIndex,
            DWriteNet::DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags)
        {
            std::vector<::IDWriteFontFile *> nativeFontFiles(fontFiles->Length);
            for(int i = 0; i < fontFiles->Length; i++)
            {
                nativeFontFiles[i] = fontFiles[i]->m_pFile;
            }

            pin_ptr<::IDWriteFontFace *> ppFace = &m_pFace;
            HRESULT hr = factory->m_pFactory->CreateFontFace(
                (::DWRITE_FONT_FACE_TYPE)((int)fontFaceType),
                (UINT32)fontFiles->Length,
                nativeFontFiles.data(),
                faceIndex,
                (::DWRITE_FONT_SIMULATIONS)((int)fontFaceSimulationFlags),
                (::IDWriteFontFace **)ppFace
            );
            ppFace = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteFontFace.", (int)hr);

            m_fontFiles = gcnew array<DWriteNet::IDWriteFontFile ^>(fontFiles->Length);
            fontFiles->CopyTo(m_fontFiles, 0);
        }

        IDWriteFontFace::~IDWriteFontFace()
        {
            this->!IDWriteFontFace();
        }

        IDWriteFontFace::!IDWriteFontFace()
        {
            if(m_pFace)
            {
                m_pFace->Release();
                m_pFace = nullptr;
            }
        }

        
        HRESULT IDWriteFontFace::GetDesignGlyphMetrics(
            array<UINT16> ^glyphIndices,
            array<DWriteNet::DWRITE_GLYPH_METRICS> ^%glyphMetrics,
            System::Nullable<bool> isSideways)
        {
            if(!isSideways.HasValue)
                isSideways = false;

            pin_ptr<UINT16> pIndices = &glyphIndices[0];
            glyphMetrics = gcnew array<DWriteNet::DWRITE_GLYPH_METRICS>(glyphIndices->Length);
            pin_ptr<DWriteNet::DWRITE_GLYPH_METRICS> pMetrics = &glyphMetrics[0];

            HRESULT hr = m_pFace->GetDesignGlyphMetrics(
                (UINT16 *)pIndices,
                glyphIndices->Length,
                (::DWRITE_GLYPH_METRICS *)pMetrics,
                System::Convert::ToInt32(isSideways.Value)
            );

            pIndices = nullptr;
            pMetrics = nullptr;

            if(FAILED(hr))
            {
                delete glyphMetrics;
                glyphMetrics = nullptr;
            }

            return hr;
        }

        HRESULT IDWriteFontFace::GetGlyphIndices(array<UINT32> ^codePoints, array<UINT16> ^%glyphIndices)
        {
            pin_ptr<UINT32> pPoints = &codePoints[0];
            glyphIndices = gcnew array<UINT16>(codePoints->Length);
            pin_ptr<UINT16> pIndices = &glyphIndices[0];

            HRESULT hr = m_pFace->GetGlyphIndices(
                (UINT32 *)pPoints,
                codePoints->Length,
                (UINT16 *)pIndices
            );

            pPoints = nullptr;
            pIndices = nullptr;

            if(FAILED(hr))
            {
                delete glyphIndices;
                glyphIndices = nullptr;
            }

            return hr;
        }

        HRESULT IDWriteFontFace::TryGetFontTable(
            UINT32 openTypeTableTag,
            void *%tableData,
            UINT32 %tableSize,
            void *%tableContext,
            bool %exists)
        {
            const void *nativeTableData;
            pin_ptr<UINT32> pTableSize = &tableSize;
            pin_ptr<void *> pTableContext = &tableContext;
            BOOL nativeExists;

            HRESULT hr = m_pFace->TryGetFontTable(
                openTypeTableTag,
                &nativeTableData,
                (UINT32 *)pTableSize,
                (void **)pTableContext,
                &nativeExists
            );

            pTableSize = nullptr;
            pTableContext = nullptr;

            tableData = const_cast<void *>(nativeTableData);
            exists = System::Convert::ToBoolean(nativeExists);

            return hr;
        }

        void IDWriteFontFace::ReleaseFontTable(void *tableContext)
        {
            m_pFace->ReleaseFontTable(tableContext);
        }

        HRESULT IDWriteFontFace::GetGlyphRunOutline(
            float emSize,
            array<UINT16> ^glyphIndices,
            bool isSideways,
            bool isRightToLeft,
            System::IntPtr %geometrySink,
            array<float> ^glyphAdvances,
            array<DWriteNet::DWRITE_GLYPH_OFFSET> ^glyphOffsets)
        {
            HRESULT hr = S_OK;

            if(geometrySink == System::IntPtr::Zero)
                return E_INVALIDARG;

            pin_ptr<UINT16> pIndices = &glyphIndices[0];
            pin_ptr<float> pAdvances = nullptr;
            pin_ptr<DWriteNet::DWRITE_GLYPH_OFFSET> pOffsets = nullptr;

            if(glyphAdvances)
            {
                if(glyphAdvances->Length != glyphIndices->Length)
                    return E_INVALIDARG;
                pAdvances = &glyphAdvances[0];
            }
            if(glyphOffsets)
            {
                if(glyphOffsets->Length != glyphIndices->Length)
                    return E_INVALIDARG;
                pOffsets = &glyphOffsets[0];
            }

            hr = m_pFace->GetGlyphRunOutline(
                emSize,
                (UINT16 *)pIndices,
                (FLOAT *)pAdvances,
                reinterpret_cast<::DWRITE_GLYPH_OFFSET *>(pOffsets),
                (UINT32)glyphIndices->Length,
                System::Convert::ToInt32(isSideways),
                System::Convert::ToInt32(isRightToLeft),
                reinterpret_cast<::IDWriteGeometrySink *>(geometrySink.ToPointer())
            );

            return hr;
        }

        HRESULT IDWriteFontFace::GetRecommendedRenderingMode(
            float emSize,
            float pixelsPerDip,
            DWriteNet::DWRITE_MEASURING_MODE measuringMode,
            DWriteNet::IDWriteRenderingParams ^renderingParams,
            DWriteNet::DWRITE_RENDERING_MODE %renderingMode)
        {
            ::DWRITE_RENDERING_MODE nativeMode;

            HRESULT hr = m_pFace->GetRecommendedRenderingMode(
                emSize,
                pixelsPerDip,
                (::DWRITE_MEASURING_MODE)((int)measuringMode),
                renderingParams->m_pParams,
                &nativeMode
            );

            renderingMode = (DWriteNet::DWRITE_RENDERING_MODE)((int)nativeMode);

            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::DWRITE_RENDERING_MODE> IDWriteFontFace::GetRecommendedRenderingMode(
            float emSize,
            float pixelsPerDip,
            DWriteNet::DWRITE_MEASURING_MODE measuringMode,
            DWriteNet::IDWriteRenderingParams ^renderingParams)
        {
            ::DWRITE_RENDERING_MODE nativeMode;

            HRESULT hr = m_pFace->GetRecommendedRenderingMode(
                emSize,
                pixelsPerDip,
                (::DWRITE_MEASURING_MODE)((int)measuringMode),
                renderingParams->m_pParams,
                &nativeMode
            );

            return System::ValueTuple<HRESULT, DWriteNet::DWRITE_RENDERING_MODE>(
                hr,
                (DWriteNet::DWRITE_RENDERING_MODE)((int)nativeMode)
                );
        }

        HRESULT IDWriteFontFace::GetGdiCompatibleMetrics(
            float emSize,
            float pixelsPerDip,
            DWriteNet::DWRITE_FONT_METRICS %fontFaceMetrics,
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform)
        {
            pin_ptr<DWriteNet::DWRITE_FONT_METRICS> pMetrics = &fontFaceMetrics;

            HRESULT hr = m_pFace->GetGdiCompatibleMetrics(
                emSize,
                pixelsPerDip,
                transform.HasValue ? &static_cast<::DWRITE_MATRIX>(transform.Value) : __nullptr,
                reinterpret_cast<::DWRITE_FONT_METRICS *>(pMetrics)
            );

            pMetrics = nullptr;
            
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::DWRITE_FONT_METRICS> IDWriteFontFace::GetGdiCompatibleMetrics(
            float emSize,
            float pixelsPerDip,
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform)
        {
            DWriteNet::DWRITE_FONT_METRICS metrics;
            pin_ptr<DWriteNet::DWRITE_FONT_METRICS> pMetrics = &metrics;

            HRESULT hr = m_pFace->GetGdiCompatibleMetrics(
                emSize,
                pixelsPerDip,
                transform.HasValue ? &static_cast<::DWRITE_MATRIX>(transform.Value) : __nullptr,
                reinterpret_cast<::DWRITE_FONT_METRICS *>(pMetrics)
            );

            pMetrics = nullptr;

            return System::ValueTuple<HRESULT, DWriteNet::DWRITE_FONT_METRICS>(hr, metrics);
        }

        HRESULT IDWriteFontFace::GetGdiCompatibleGlyphMetrics(
            float emSize,
            float pixelsPerDip,
            bool useGdiNatural,
            array<UINT16> ^glyphIndices,
            array<DWriteNet::DWRITE_GLYPH_METRICS> ^%glyphMetrics,
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform,
            System::Nullable<bool> isSideways)
        {
            if(!isSideways.HasValue)
                isSideways = false;

            glyphMetrics = gcnew array<DWriteNet::DWRITE_GLYPH_METRICS>(glyphIndices->Length);

            pin_ptr<UINT16> pIndices = &glyphIndices[0];
            pin_ptr<DWriteNet::DWRITE_GLYPH_METRICS> pMetrics = &glyphMetrics[0];

            HRESULT hr = m_pFace->GetGdiCompatibleGlyphMetrics(
                emSize,
                pixelsPerDip,
                transform.HasValue ? &static_cast<::DWRITE_MATRIX>(transform.Value) : __nullptr,
                System::Convert::ToInt32(useGdiNatural),
                (UINT16 *)pIndices,
                (UINT32)glyphIndices->Length,
                reinterpret_cast<::DWRITE_GLYPH_METRICS *>(pMetrics),
                System::Convert::ToInt32(isSideways.Value)
            );

            if(FAILED(hr))
            {
                delete glyphMetrics;
                glyphMetrics = nullptr;
            }

            return hr;
        }      
    }
}