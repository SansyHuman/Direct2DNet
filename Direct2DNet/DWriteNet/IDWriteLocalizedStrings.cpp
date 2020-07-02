#include "IDWriteLocalizedStrings.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteLocalizedStrings::~IDWriteLocalizedStrings()
        {
            this->!IDWriteLocalizedStrings();
        }

        IDWriteLocalizedStrings::!IDWriteLocalizedStrings()
        {
            if(m_pStrings)
            {
                m_pStrings->Release();
                m_pStrings = nullptr;
            }
        }

        HRESULT IDWriteLocalizedStrings::FindLocaleName(
            System::String ^localeName,
            UINT32 %index,
            bool %exists)
        {
            marshal_context context;

            pin_ptr<UINT32> pIndex = &index;
            BOOL nativeExists;

            HRESULT hr = m_pStrings->FindLocaleName(
                context.marshal_as<const WCHAR *>(localeName),
                (UINT32 *)pIndex,
                &nativeExists
            );

            pIndex = nullptr;
            exists = System::Convert::ToBoolean(nativeExists);

            return hr;
        }

        System::ValueTuple<HRESULT, UINT32, bool> IDWriteLocalizedStrings::FindLocaleName(
            System::String ^localeName)
        {
            marshal_context context;

            UINT32 index;
            BOOL exists;

            HRESULT hr = m_pStrings->FindLocaleName(
                context.marshal_as<const WCHAR *>(localeName),
                &index,
                &exists
            );

            return System::ValueTuple<HRESULT, UINT32, bool>(
                hr,
                index,
                System::Convert::ToBoolean(exists)
                );
        }

        HRESULT IDWriteLocalizedStrings::GetLocaleName(UINT32 index, System::String ^%localeName)
        {
            UINT32 nameLength = 0;

            HRESULT hr = m_pStrings->GetLocaleNameLength(index, &nameLength);
            if(FAILED(hr))
            {
                localeName = nullptr;
                return hr;
            }

            std::vector<WCHAR> nativeLocaleName(nameLength + 1);

            hr = m_pStrings->GetLocaleName(index, nativeLocaleName.data(), nameLength + 1);
            if(FAILED(hr))
                localeName = nullptr;
            else
                localeName = marshal_as<System::String ^>(nativeLocaleName.data());

            return hr;
        }

        System::ValueTuple<HRESULT, System::String ^> IDWriteLocalizedStrings::GetLocaleName(UINT32 index)
        {
            UINT32 nameLength = 0;

            HRESULT hr = m_pStrings->GetLocaleNameLength(index, &nameLength);
            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, System::String ^>(hr, nullptr);
            }

            std::vector<WCHAR> nativeLocaleName(nameLength + 1);

            hr = m_pStrings->GetLocaleName(index, nativeLocaleName.data(), nameLength + 1);
            if(FAILED(hr))
                return System::ValueTuple<HRESULT, System::String ^>(hr, nullptr);

            return System::ValueTuple<HRESULT, System::String ^>(
                    hr,
                    marshal_as<System::String ^>(nativeLocaleName.data()));
        }

        HRESULT IDWriteLocalizedStrings::GetString(UINT32 index, System::String ^%string)
        {
            UINT32 stringLength = 0;

            HRESULT hr = m_pStrings->GetStringLength(index, &stringLength);
            if(FAILED(hr))
            {
                string = nullptr;
                return hr;
            }

            std::vector<WCHAR> nativeString(stringLength + 1);

            hr = m_pStrings->GetString(index, nativeString.data(), stringLength + 1);
            if(FAILED(hr))
                string = nullptr;
            else
                string = marshal_as<System::String ^>(nativeString.data());

            return hr;
        }

        System::ValueTuple<HRESULT, System::String ^> IDWriteLocalizedStrings::GetString(UINT32 index)
        {
            UINT32 stringLength = 0;

            HRESULT hr = m_pStrings->GetStringLength(index, &stringLength);
            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, System::String ^>(hr, nullptr);
            }

            std::vector<WCHAR> nativeString(stringLength + 1);

            hr = m_pStrings->GetString(index, nativeString.data(), stringLength + 1);
            if(FAILED(hr))
                return System::ValueTuple<HRESULT, System::String ^>(hr, nullptr);

            return System::ValueTuple<HRESULT, System::String ^>(
                hr,
                marshal_as<System::String ^>(nativeString.data()));
        }

        System::String ^IDWriteLocalizedStrings::default::get(System::String ^localeName)
        {
            UINT32 index; bool exists;
            HRESULT hr = this->FindLocaleName(localeName, index, exists);
            if(FAILED(hr) || !exists)
                return nullptr;

            System::String ^string;
            hr = this->GetString(index, string);
            if(FAILED(hr))
                return nullptr;

            return string;
        }

    }
}