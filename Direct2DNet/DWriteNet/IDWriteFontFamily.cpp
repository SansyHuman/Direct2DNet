#include "IDWriteFontFamily.h"
#include "IDWriteLocalizedStrings.h"
#include "IDWriteFont.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteFontFamily::IDWriteFontFamily(
            ::IDWriteFontFamily *pFamily,
            DWriteNet::IDWriteFontCollection ^fontCollection)
            : DWriteNet::IDWriteFontList(pFamily, fontCollection, this)
        {
            
        }

        HRESULT IDWriteFontFamily::GetFamilyNames(DWriteNet::IDWriteLocalizedStrings ^%names)
        {
            ::IDWriteLocalizedStrings *pStrings = __nullptr;

            HRESULT hr = ((::IDWriteFontFamily *)m_pList)->GetFamilyNames(&pStrings);
            if(FAILED(hr))
            {
                names = nullptr;
                return hr;
            }

            names = gcnew DWriteNet::IDWriteLocalizedStrings(pStrings);
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^> IDWriteFontFamily::GetFamilyNames()
        {
            ::IDWriteLocalizedStrings *pStrings = __nullptr;

            HRESULT hr = ((::IDWriteFontFamily *)m_pList)->GetFamilyNames(&pStrings);
            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^>(hr, nullptr);
            }

            return System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^>(
                hr,
                gcnew DWriteNet::IDWriteLocalizedStrings(pStrings));
        }

        HRESULT IDWriteFontFamily::GetFirstMatchingFont(
            DWriteNet::DWRITE_FONT_WEIGHT weight,
            DWriteNet::DWRITE_FONT_STRETCH stretch,
            DWriteNet::DWRITE_FONT_STYLE style,
            DWriteNet::IDWriteFont ^%matchingFont)
        {
            ::IDWriteFont *pFont = __nullptr;

            HRESULT hr = ((::IDWriteFontFamily *)m_pList)->GetFirstMatchingFont(
                (::DWRITE_FONT_WEIGHT)((int)weight),
                (::DWRITE_FONT_STRETCH)((int)stretch),
                (::DWRITE_FONT_STYLE)((int)style),
                &pFont
            );

            if(FAILED(hr) || !pFont)
            {
                matchingFont = nullptr;
                return hr;
            }

            matchingFont = gcnew DWriteNet::IDWriteFont(pFont, this);
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^> IDWriteFontFamily::GetFirstMatchingFont(
            DWriteNet::DWRITE_FONT_WEIGHT weight,
            DWriteNet::DWRITE_FONT_STRETCH stretch,
            DWriteNet::DWRITE_FONT_STYLE style)
        {
            ::IDWriteFont *pFont = __nullptr;

            HRESULT hr = ((::IDWriteFontFamily *)m_pList)->GetFirstMatchingFont(
                (::DWRITE_FONT_WEIGHT)((int)weight),
                (::DWRITE_FONT_STRETCH)((int)stretch),
                (::DWRITE_FONT_STYLE)((int)style),
                &pFont
            );

            if(FAILED(hr) || !pFont)
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^>(hr, nullptr);
            }

            return System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^>(
                hr,
                gcnew DWriteNet::IDWriteFont(pFont, this));
        }

        HRESULT IDWriteFontFamily::GetMatchingFonts(
            DWriteNet::DWRITE_FONT_WEIGHT weight,
            DWriteNet::DWRITE_FONT_STRETCH stretch,
            DWriteNet::DWRITE_FONT_STYLE style,
            DWriteNet::IDWriteFontList ^%matchingFonts)
        {
            ::IDWriteFontList *pList = __nullptr;

            HRESULT hr = ((::IDWriteFontFamily *)m_pList)->GetMatchingFonts(
                (::DWRITE_FONT_WEIGHT)((int)weight),
                (::DWRITE_FONT_STRETCH)((int)stretch),
                (::DWRITE_FONT_STYLE)((int)style),
                &pList
            );

            if(FAILED(hr) || !pList)
            {
                matchingFonts = nullptr;
                return hr;
            }

            matchingFonts = gcnew DWriteNet::IDWriteFontList(pList, m_fontCollection, this);
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteFontList ^> IDWriteFontFamily::GetMatchingFonts(
            DWriteNet::DWRITE_FONT_WEIGHT weight,
            DWriteNet::DWRITE_FONT_STRETCH stretch,
            DWriteNet::DWRITE_FONT_STYLE style)
        {
            ::IDWriteFontList *pList = __nullptr;

            HRESULT hr = ((::IDWriteFontFamily *)m_pList)->GetMatchingFonts(
                (::DWRITE_FONT_WEIGHT)((int)weight),
                (::DWRITE_FONT_STRETCH)((int)stretch),
                (::DWRITE_FONT_STYLE)((int)style),
                &pList
            );

            if(FAILED(hr) || !pList)
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteFontList ^>(hr, nullptr);
            }

            return System::ValueTuple<HRESULT, DWriteNet::IDWriteFontList ^>(
                hr,
                gcnew DWriteNet::IDWriteFontList(pList, m_fontCollection, this));
        }

    }
}