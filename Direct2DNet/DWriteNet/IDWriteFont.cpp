#include "IDWriteFont.h"
#include "IDWriteLocalizedStrings.h"
#include "IDWriteFontFace.h"
#include "IDWriteFontFamily.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteFont::IDWriteFont(::IDWriteFont *pFont, DWriteNet::IDWriteFontFamily ^fontFamily)
            : m_pFont(pFont), m_fontFamily(fontFamily)
        {

        }

        IDWriteFont::IDWriteFont(::IDWriteFont *pFont)
            : m_pFont(pFont)
        {
            ::IDWriteFontFamily *fontFamily;
            HRESULT hr = m_pFont->GetFontFamily(&fontFamily);
            if(FAILED(hr) || !fontFamily)
                m_fontFamily = nullptr;
            else
                m_fontFamily = gcnew DWriteNet::IDWriteFontFamily(fontFamily);
        }

        IDWriteFont::~IDWriteFont()
        {
            this->!IDWriteFont();
        }

        IDWriteFont::!IDWriteFont()
        {
            if(m_pFont)
            {
                m_pFont->Release();
                m_pFont = nullptr;
            }
        }

        void IDWriteFont::HandleCOMInterface(void *obj)
        {
            if(m_pFont)
            {
                m_pFont->Release();
            }

            m_pFont = (::IDWriteFont *)obj;
            m_pFont->AddRef();

            ::IDWriteFontFamily *fontFamily;
            HRESULT hr = m_pFont->GetFontFamily(&fontFamily);
            if(FAILED(hr) || !fontFamily)
                m_fontFamily = nullptr;
            else
                m_fontFamily = gcnew DWriteNet::IDWriteFontFamily(fontFamily);
        }

        HRESULT IDWriteFont::GetFaceNames(DWriteNet::IDWriteLocalizedStrings ^%names)
        {
            ::IDWriteLocalizedStrings *pStrings = __nullptr;

            HRESULT hr = m_pFont->GetFaceNames(&pStrings);

            if(FAILED(hr) || !pStrings)
            {
                names = nullptr;
                return hr;
            }

            names = gcnew DWriteNet::IDWriteLocalizedStrings(pStrings);
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^> IDWriteFont::GetFaceNames()
        {
            ::IDWriteLocalizedStrings *pStrings = __nullptr;

            HRESULT hr = m_pFont->GetFaceNames(&pStrings);

            if(FAILED(hr) || !pStrings)
            {
                System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^>(hr, nullptr);
            }
            
            return System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^>(
                hr,
                gcnew DWriteNet::IDWriteLocalizedStrings(pStrings));
        }

        HRESULT IDWriteFont::GetInformationalStrings(
            DWriteNet::DWRITE_INFORMATIONAL_STRING_ID informationalStringID,
            DWriteNet::IDWriteLocalizedStrings ^%informationalStrings,
            bool %exists)
        {
            BOOL nativeExists;
            ::IDWriteLocalizedStrings *pStrings = __nullptr;

            HRESULT hr = m_pFont->GetInformationalStrings(
                (::DWRITE_INFORMATIONAL_STRING_ID)((int)informationalStringID),
                &pStrings,
                &nativeExists
            );

            if(FAILED(hr) || !pStrings)
            {
                informationalStrings = nullptr;
            }
            else
            {
                informationalStrings = gcnew DWriteNet::IDWriteLocalizedStrings(pStrings);
            }

            exists = System::Convert::ToBoolean(nativeExists);

            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^, bool> IDWriteFont::GetInformationalStrings(
            DWriteNet::DWRITE_INFORMATIONAL_STRING_ID informationalStringID)
        {
            BOOL nativeExists;
            ::IDWriteLocalizedStrings *pStrings = __nullptr;

            HRESULT hr = m_pFont->GetInformationalStrings(
                (::DWRITE_INFORMATIONAL_STRING_ID)((int)informationalStringID),
                &pStrings,
                &nativeExists
            );

            if(FAILED(hr) || !pStrings)
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^, bool>(
                    hr,
                    nullptr,
                    System::Convert::ToBoolean(nativeExists)
                    );
            }

            return System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^, bool>(
                hr,
                gcnew DWriteNet::IDWriteLocalizedStrings(pStrings),
                System::Convert::ToBoolean(nativeExists)
                );
        }

        HRESULT IDWriteFont::HasCharacter(UINT32 unicodeValue, bool %exists)
        {
            BOOL nativeExists;

            HRESULT hr = m_pFont->HasCharacter(unicodeValue, &nativeExists);

            exists = System::Convert::ToBoolean(nativeExists);

            return hr;
        }

        System::ValueTuple<HRESULT, bool> IDWriteFont::HasCharacter(UINT32 unicodeValue)
        {
            BOOL nativeExists;

            HRESULT hr = m_pFont->HasCharacter(unicodeValue, &nativeExists);

            return System::ValueTuple<HRESULT, bool>(hr, System::Convert::ToBoolean(nativeExists));
        }

        DWriteNet::IDWriteFontFace ^IDWriteFont::CreateFontFace()
        {
            ::IDWriteFontFace *pFace = __nullptr;
            HRESULT hr = m_pFont->CreateFontFace(&pFace);

            if(FAILED(hr) || !pFace)
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteFontFace.", (int)hr);

            return gcnew DWriteNet::IDWriteFontFace(pFace);
        }

    }
}