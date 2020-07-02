#include "IDWriteFontList.h"
#include "IDWriteFont.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteFontList::IDWriteFontList(
            ::IDWriteFontList *pList,
            DWriteNet::IDWriteFontCollection ^fontCollection,
            DWriteNet::IDWriteFontFamily ^fontFamily)
            : m_pList(pList), m_fontCollection(fontCollection), m_fontFamily(fontFamily)
        {
            
        }

        IDWriteFontList::~IDWriteFontList()
        {
            this->!IDWriteFontList();
        }

        IDWriteFontList::!IDWriteFontList()
        {
            if(m_pList)
            {
                m_pList->Release();
                m_pList = nullptr;
            }
        }

        HRESULT IDWriteFontList::GetFont(UINT32 index, DWriteNet::IDWriteFont ^%font)
        {
            ::IDWriteFont *pFont = __nullptr;

            HRESULT hr = m_pList->GetFont(index, &pFont);

            if(FAILED(hr) || !pFont)
            {
                font = nullptr;
                return hr;
            }

            font = gcnew DWriteNet::IDWriteFont(pFont, m_fontFamily);
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^> IDWriteFontList::GetFont(UINT32 index)
        {
            ::IDWriteFont *pFont = __nullptr;

            HRESULT hr = m_pList->GetFont(index, &pFont);

            if(FAILED(hr) || !pFont)
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^>(hr, nullptr);
            }

            return System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^>(
                hr,
                gcnew DWriteNet::IDWriteFont(pFont, m_fontFamily));
        }

        DWriteNet::IDWriteFont ^IDWriteFontList::default::get(UINT32 index)
        {
            ::IDWriteFont *pFont = __nullptr;

            HRESULT hr = m_pList->GetFont(index, &pFont);

            if(FAILED(hr) || !pFont)
            {
                return nullptr;
            }

            return gcnew DWriteNet::IDWriteFont(pFont, m_fontFamily);
        }

    }
}