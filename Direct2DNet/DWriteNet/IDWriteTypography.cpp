#include "IDWriteTypography.h"
#include "IDWriteFactory.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteTypography::IDWriteTypography(DWriteNet::IDWriteFactory ^factory)
        {
            pin_ptr<::IDWriteTypography *> ppTypo = &m_pTypo;
            HRESULT hr = factory->m_pFactory->CreateTypography((::IDWriteTypography **)ppTypo);
            ppTypo = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteTypography.", (int)hr);
        }

        IDWriteTypography::~IDWriteTypography()
        {
            this->!IDWriteTypography();
        }

        IDWriteTypography::!IDWriteTypography()
        {
            if(m_pTypo)
            {
                m_pTypo->Release();
                m_pTypo = nullptr;
            }
        }

        void IDWriteTypography::HandleCOMInterface(void *obj)
        {
            if(m_pTypo)
            {
                m_pTypo->Release();
            }

            m_pTypo = (::IDWriteTypography *)obj;
            m_pTypo->AddRef();
        }

        HRESULT IDWriteTypography::AddFontFeature(DWriteNet::DWRITE_FONT_FEATURE %fontFeature)
        {
            return m_pTypo->AddFontFeature(static_cast<::DWRITE_FONT_FEATURE>(fontFeature));
        }

        HRESULT IDWriteTypography::GetFontFeature(
            UINT32 fontFeatureIndex,
            DWriteNet::DWRITE_FONT_FEATURE %fontFeature)
        {
            pin_ptr<DWriteNet::DWRITE_FONT_FEATURE> pFeature = &fontFeature;
            return m_pTypo->GetFontFeature(fontFeatureIndex, reinterpret_cast<::DWRITE_FONT_FEATURE *>(pFeature));
        }

        System::ValueTuple<HRESULT, DWriteNet::DWRITE_FONT_FEATURE> IDWriteTypography::GetFontFeature(
            UINT32 fontFeatureIndex)
        {
            ::DWRITE_FONT_FEATURE feature;
            HRESULT hr = m_pTypo->GetFontFeature(fontFeatureIndex, &feature);

            return System::ValueTuple<HRESULT, DWriteNet::DWRITE_FONT_FEATURE>(hr, static_cast<DWriteNet::DWRITE_FONT_FEATURE>(feature));
        }

        DWriteNet::DWRITE_FONT_FEATURE IDWriteTypography::default::get(UINT32 index)
        {
            ::DWRITE_FONT_FEATURE feature;
            HRESULT hr = m_pTypo->GetFontFeature(index, &feature);

            if(FAILED(hr))
                return DWriteNet::DWRITE_FONT_FEATURE(0, 0);

            return static_cast<DWriteNet::DWRITE_FONT_FEATURE>(feature);
        }

    }
}