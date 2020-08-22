#include "IWICMetadataQueryReader.h"

#include <vector>

namespace D2DNet
{
    namespace WICNet
    {
        void IWICMetadataQueryReader::HandleCOMInterface(void *obj)
        {
            if(m_pReader)
            {
                m_pReader->Release();
            }

            m_pReader = (::IWICMetadataQueryReader *)obj;
            m_pReader->AddRef();
        }

        HRESULT IWICMetadataQueryReader::GetContainerFormat(System::Guid %guidContainerFormat)
        {
            ::GUID format = { 0 };

            HRESULT hr = m_pReader->GetContainerFormat(&format);

            guidContainerFormat = DirectX::ToManagedGUID(format);
            return hr;
        }

        HRESULT IWICMetadataQueryReader::GetLocation(System::String ^%nameSpace)
        {
            UINT cchNamespace = 0;
            HRESULT hr = m_pReader->GetLocation(0, __nullptr, &cchNamespace);
            if(cchNamespace == 0)
            {
                nameSpace = "";
                return S_OK;
            }

            std::vector<WCHAR> wNamespace(cchNamespace);
            UINT cchActual = 0;
            hr = m_pReader->GetLocation(cchNamespace, wNamespace.data(), &cchActual);

            if(FAILED(hr))
            {
                nameSpace = nullptr;
                return hr;
            }

            nameSpace = marshal_as<System::String ^>(wNamespace.data());
            return hr;
        }

        HRESULT IWICMetadataQueryReader::GetMetadataByName(
            System::String ^name,
            D2DNet::PROPVARIANT %varValue)
        {
            marshal_context context;

            pin_ptr<D2DNet::PROPVARIANT> pVar = &varValue;
            return m_pReader->GetMetadataByName(
                context.marshal_as<LPCWSTR>(name),
                (::PROPVARIANT *)pVar
            );
        }

    }
}