#include "IDWriteFontCollection.h"
#include "IDWriteFontFamily.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteFontCollection::~IDWriteFontCollection()
        {
            this->!IDWriteFontCollection();
        }

        IDWriteFontCollection::!IDWriteFontCollection()
        {
            if(m_pCollection)
            {
                m_pCollection->Release();
                m_pCollection = nullptr;
            }
        }

        HRESULT IDWriteFontCollection::GetFontFamily(UINT32 index, DWriteNet::IDWriteFontFamily ^%fontFamily)
        {
            ::IDWriteFontFamily *pFamily = __nullptr;

            HRESULT hr = m_pCollection->GetFontFamily(index, &pFamily);

            if(FAILED(hr))
                fontFamily = nullptr;
            else
                fontFamily = gcnew DWriteNet::IDWriteFontFamily(pFamily, this);

            return hr;
        }

        DWriteNet::IDWriteFontFamily ^IDWriteFontCollection::default::get(UINT32 index)
        {
            DWriteNet::IDWriteFontFamily ^family = nullptr;

            HRESULT hr = this->GetFontFamily(index, family);

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to get IDWriteFontCollection", hr);

            return family;
        }

        HRESULT IDWriteFontCollection::FindFamilyName(System::String ^familyName, UINT32 %index, bool %exists)
        {
            marshal_context context;

            pin_ptr<UINT32> pIndex = &index;
            BOOL nativeExists;

            HRESULT hr = m_pCollection->FindFamilyName(
                context.marshal_as<const WCHAR *>(familyName),
                (UINT32 *)pIndex,
                &nativeExists
            );

            pIndex = nullptr;
            exists = System::Convert::ToBoolean(nativeExists);

            return hr;
        }

        System::ValueTuple<HRESULT, UINT32, bool> IDWriteFontCollection::FindFamilyName(
            System::String ^familyName)
        {
            marshal_context context;

            UINT32 index;
            BOOL exists;

            HRESULT hr = m_pCollection->FindFamilyName(
                context.marshal_as<const WCHAR *>(familyName),
                &index,
                &exists
            );

            return System::ValueTuple<HRESULT, UINT32, bool>(
                hr, index, System::Convert::ToBoolean(exists)
                );
        }

    }
}