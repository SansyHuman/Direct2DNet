#include "IDWriteGlyphRunAnalysis.h"
#include "IDWriteFactory.h"
#include "IDWriteRenderingParams.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteGlyphRunAnalysis::IDWriteGlyphRunAnalysis(
            DWriteNet::IDWriteFactory ^factory,
            DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
            float pixelsPerDip,
            DWriteNet::DWRITE_RENDERING_MODE renderingMode,
            DWriteNet::DWRITE_MEASURING_MODE measuringMode,
            float baselineOriginX,
            float baselineOriginY,
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform)
        {
            ::DWRITE_GLYPH_RUN run = static_cast<::DWRITE_GLYPH_RUN>(glyphRun);
            pin_ptr<::IDWriteGlyphRunAnalysis *> ppAnal = &m_pAnal;

            HRESULT hr = factory->m_pFactory->CreateGlyphRunAnalysis(
                &run,
                pixelsPerDip,
                transform.HasValue ? reinterpret_cast<::DWRITE_MATRIX *>(&transform.Value) : __nullptr,
                (::DWRITE_RENDERING_MODE)((int)renderingMode),
                (::DWRITE_MEASURING_MODE)((int)measuringMode),
                baselineOriginX,
                baselineOriginY,
                (::IDWriteGlyphRunAnalysis **)ppAnal
            );
            ppAnal = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteGlyphRunAnalysis.", (int)hr);
        }

        IDWriteGlyphRunAnalysis::~IDWriteGlyphRunAnalysis()
        {
            this->!IDWriteGlyphRunAnalysis();
        }

        IDWriteGlyphRunAnalysis::!IDWriteGlyphRunAnalysis()
        {
            if(m_pAnal)
            {
                m_pAnal->Release();
                m_pAnal = nullptr;
            }
        }

        void IDWriteGlyphRunAnalysis::HandleCOMInterface(void *obj)
        {
            if(m_pAnal)
            {
                m_pAnal->Release();
            }

            m_pAnal = (::IDWriteGlyphRunAnalysis *)obj;
            m_pAnal->AddRef();
        }

        HRESULT IDWriteGlyphRunAnalysis::GetAlphaTextureBounds(
            DWriteNet::DWRITE_TEXTURE_TYPE textureType,
            D2DNet::RECT %textureBounds)
        {
            pin_ptr<D2DNet::RECT> pBounds = &textureBounds;
            return m_pAnal->GetAlphaTextureBounds(
                (::DWRITE_TEXTURE_TYPE)((int)textureType),
                reinterpret_cast<::RECT *>(pBounds)
            );
        }

        HRESULT IDWriteGlyphRunAnalysis::CreateAlphaTexture(DWriteNet::DWRITE_TEXTURE_TYPE textureType, D2DNet::RECT %textureBounds, array<BYTE> ^alphaValues)
        {
            UINT32 length = alphaValues->Length;

            pin_ptr<D2DNet::RECT> pBounds = &textureBounds;
            pin_ptr<BYTE> pValues = length == 0 ? __nullptr : &alphaValues[0];

            return m_pAnal->CreateAlphaTexture(
                (::DWRITE_TEXTURE_TYPE)((int)textureType),
                reinterpret_cast<::RECT *>(pBounds),
                (BYTE *)pValues,
                length
            );
        }

        HRESULT IDWriteGlyphRunAnalysis::GetAlphaBlendParams(
            DWriteNet::IDWriteRenderingParams ^renderingParams,
            FLOAT %blendGamma,
            FLOAT %blendEnhancedContrast,
            FLOAT %blendClearTypeLevel)
        {
            FLOAT gamma = 0, contrast = 0, level = 0;

            HRESULT hr = m_pAnal->GetAlphaBlendParams(
                renderingParams->m_pParams,
                &gamma, &contrast, &level
            );

            blendGamma = gamma;
            blendEnhancedContrast = contrast;
            blendClearTypeLevel = level;

            return hr;
        }

    }
}