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

        HRESULT IDWriteFontList::GetFontCollection(DWriteNet::IDWriteFontCollection ^%fontCollection)
        {
            if(m_fontCollection)
            {
                fontCollection = m_fontCollection;
                return S_OK;
            }

            ::IDWriteFontCollection *collection = __nullptr;
            HRESULT hr = m_pList->GetFontCollection(&collection);
            if(FAILED(hr) || !collection)
            {
                fontCollection = nullptr;
                return hr;
            }

            m_fontCollection = gcnew DWriteNet::IDWriteFontCollection(collection);
            fontCollection = m_fontCollection;
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^> IDWriteFontList::GetFontCollection()
        {
            if(m_fontCollection)
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^>(S_OK, m_fontCollection);
            }

            ::IDWriteFontCollection *collection = __nullptr;
            HRESULT hr = m_pList->GetFontCollection(&collection);
            if(FAILED(hr) || !collection)
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^>(hr, nullptr);
            }

            m_fontCollection = gcnew DWriteNet::IDWriteFontCollection(collection);
            return System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^>(hr, m_fontCollection);
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