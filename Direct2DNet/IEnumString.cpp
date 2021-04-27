#include "IEnumString.h"

#include <vector>

namespace D2DNet
{
    IEnumString::~IEnumString()
    {
        this->!IEnumString();
    }

    IEnumString::!IEnumString()
    {
        if(m_pStr)
        {
            m_pStr->Release();
            m_pStr = nullptr;
        }
    }

    void IEnumString::HandleCOMInterface(void *obj)
    {
        if(m_pStr)
        {
            m_pStr->Release();
        }

        m_pStr = (::IEnumString *)obj;
        m_pStr->AddRef();
    }

    HRESULT IEnumString::Next(array<System::String ^> ^rgelt, ULONG %celtFetched)
    {
        ULONG celt = rgelt->Length;
        if(celt == 0)
        {
            celtFetched = 0;
            return S_OK;
        }

        std::vector<LPOLESTR> elt(celt);

        ULONG fetched = 0;
        HRESULT hr = m_pStr->Next(celt, elt.data(), &fetched);
        if(FAILED(hr))
        {
            celtFetched = 0;
            return hr;
        }

        for(ULONG i = 0; i < fetched; i++)
        {
            rgelt[i] = marshal_as<System::String ^>(elt[i]);
            ::CoTaskMemFree(elt[i]);
        }

        celtFetched = fetched;
        return hr;
    }

    HRESULT IEnumString::Skip(ULONG celt)
    {
        return m_pStr->Skip(celt);
    }

    HRESULT IEnumString::Reset()
    {
        return m_pStr->Reset();
    }

    HRESULT IEnumString::Clone(D2DNet::IEnumString ^%enumStr)
    {
        ::IEnumString *str = __nullptr;
        HRESULT hr = m_pStr->Clone(&str);
        if(FAILED(hr) || !str)
        {
            enumStr = nullptr;
            return hr;
        }

        enumStr = gcnew D2DNet::IEnumString(str);
        return hr;
    }

}