#include "IDWriteFontList.h"
#include "IDWriteFont.h"
#include "IDWriteFontCollection.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteFontList::IDWriteFontList(
            ::IDWriteFontList *pList,
            DWriteNet::IDWriteFontCollection ^fontCollection)
            : m_pList(pList), m_fontCollection(fontCollection)
        {
            
        }

        IDWriteFontList::IDWriteFontList(::IDWriteFontList *pList)
            : m_pList(pList)
        {
            ::IDWriteFontCollection *collection = __nullptr;
            HRESULT hr = m_pList->GetFontCollection(&collection);
            if(FAILED(hr) || !collection)
                m_fontCollection = nullptr;
            else
                m_fontCollection = gcnew DWriteNet::IDWriteFontCollection(collection);
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

        void IDWriteFontList::HandleCOMInterface(void *obj)
        {
            if(m_pList)
            {
                m_pList->Release();
            }

            m_pList = (::IDWriteFontList *)obj;
            m_pList->AddRef();

            ::IDWriteFontCollection *collection = __nullptr;
            HRESULT hr = m_pList->GetFontCollection(&collection);
            if(FAILED(hr) || !collection)
                m_fontCollection = nullptr;
            else
                m_fontCollection = gcnew DWriteNet::IDWriteFontCollection(collection);
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

            font = gcnew DWriteNet::IDWriteFont(pFont);
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
                gcnew DWriteNet::IDWriteFont(pFont));
        }

        DWriteNet::IDWriteFont ^IDWriteFontList::default::get(UINT32 index)
        {
            ::IDWriteFont *pFont = __nullptr;

            HRESULT hr = m_pList->GetFont(index, &pFont);

            if(FAILED(hr) || !pFont)
            {
                return nullptr;
            }

            return gcnew DWriteNet::IDWriteFont(pFont);
        }

    }
}