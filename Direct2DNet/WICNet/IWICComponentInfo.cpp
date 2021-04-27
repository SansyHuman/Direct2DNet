#include "IWICComponentInfo.h"
#include "IWICImagingFactory.h"
#include "../DXCommonSettings.h"

#include <vector>

namespace D2DNet
{
    namespace WICNet
    {
        IWICComponentInfo::IWICComponentInfo(WICNet::IWICImagingFactory ^factory, System::Guid %clsid)
        {
            HRESULT hr = S_OK;

            pin_ptr<::IWICComponentInfo *> ppInfo = &m_pInfo;
            hr = factory->m_pFactory->CreateComponentInfo(
                DirectX::ToNativeGUID(clsid),
                (::IWICComponentInfo **)ppInfo
            );
            ppInfo = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICComponentInfo", (int)hr);
        }

        IWICComponentInfo::~IWICComponentInfo()
        {
            this->!IWICComponentInfo();
        }

        IWICComponentInfo::!IWICComponentInfo()
        {
            if(m_pInfo)
            {
                m_pInfo->Release();
                m_pInfo = nullptr;
            }
        }

        void IWICComponentInfo::HandleCOMInterface(void *obj)
        {
            if(m_pInfo)
            {
                m_pInfo->Release();
            }

            m_pInfo = (::IWICComponentInfo *)obj;
            m_pInfo->AddRef();
        }

        HRESULT IWICComponentInfo::GetComponentType(WICNet::WICComponentType %type)
        {
            ::WICComponentType t = (::WICComponentType)0;

            HRESULT hr = m_pInfo->GetComponentType(&t);
            type = (WICNet::WICComponentType)((DWORD)t);
            return hr;
        }

        System::ValueTuple<HRESULT, WICNet::WICComponentType> IWICComponentInfo::GetComponentType()
        {
            ::WICComponentType t = (::WICComponentType)0;

            HRESULT hr = m_pInfo->GetComponentType(&t);

            return System::ValueTuple<HRESULT, WICNet::WICComponentType>(
                hr, (WICNet::WICComponentType)((DWORD)t)
                );
        }

        HRESULT IWICComponentInfo::GetCLSID(System::Guid %clsid)
        {
            pin_ptr<System::Guid> pClsid = &clsid;
            return m_pInfo->GetCLSID((::CLSID *)pClsid);
        }

        HRESULT IWICComponentInfo::GetSigningStatus(WICNet::WICComponentSigning %status)
        {
            DWORD st = 0;
            HRESULT hr = m_pInfo->GetSigningStatus(&st);
            status = (WICNet::WICComponentSigning)st;
            return hr;
        }

        System::ValueTuple<HRESULT, WICNet::WICComponentSigning> IWICComponentInfo::GetSigningStatus()
        {
            DWORD st = 0;
            HRESULT hr = m_pInfo->GetSigningStatus(&st);
            return System::ValueTuple<HRESULT, WICNet::WICComponentSigning>(
                hr, (WICNet::WICComponentSigning)st
                );
        }

        HRESULT IWICComponentInfo::GetAuthor(System::String ^%author)
        {
            UINT cchAuthor = 0;
            HRESULT hr = m_pInfo->GetAuthor(0, __nullptr, &cchAuthor);
            if(cchAuthor == 0)
            {
                author = "";
                return S_OK;
            }

            std::vector<WCHAR> wAuthor(cchAuthor);
            UINT cchActual = 0;
            hr = m_pInfo->GetAuthor(cchAuthor, wAuthor.data(), &cchActual);

            if(FAILED(hr))
            {
                author = nullptr;
                return hr;
            }

            author = marshal_as<System::String ^>(wAuthor.data());
            return hr;
        }

        HRESULT IWICComponentInfo::GetVendorGUID(System::Guid %guidVendor)
        {
            pin_ptr<System::Guid> pGuid = &guidVendor;
            return m_pInfo->GetVendorGUID((::GUID *)pGuid);
        }

        HRESULT IWICComponentInfo::GetVersion(System::String ^%version)
        {
            UINT cchVersion = 0;
            HRESULT hr = m_pInfo->GetVersion(0, __nullptr, &cchVersion);
            if(cchVersion == 0)
            {
                version = "";
                return S_OK;
            }

            std::vector<WCHAR> wVersion(cchVersion);
            UINT cchActual = 0;
            hr = m_pInfo->GetVersion(cchVersion, wVersion.data(), &cchActual);

            if(FAILED(hr))
            {
                version = nullptr;
                return hr;
            }

            version = marshal_as<System::String ^>(wVersion.data());
            return hr;
        }

        HRESULT IWICComponentInfo::GetSpecVersion(System::String ^%specVersion)
        {
            UINT cchVersion = 0;
            HRESULT hr = m_pInfo->GetSpecVersion(0, __nullptr, &cchVersion);
            if(cchVersion == 0)
            {
                specVersion = "";
                return S_OK;
            }

            std::vector<WCHAR> wVersion(cchVersion);
            UINT cchActual = 0;
            hr = m_pInfo->GetSpecVersion(cchVersion, wVersion.data(), &cchActual);

            if(FAILED(hr))
            {
                specVersion = nullptr;
                return hr;
            }

            specVersion = marshal_as<System::String ^>(wVersion.data());
            return hr;
        }

        HRESULT IWICComponentInfo::GetFriendlyName(System::String ^%friendlyName)
        {
            UINT cchName = 0;
            HRESULT hr = m_pInfo->GetFriendlyName(0, __nullptr, &cchName);
            if(cchName == 0)
            {
                friendlyName = "";
                return S_OK;
            }

            std::vector<WCHAR> wName(cchName);
            UINT cchActual = 0;
            hr = m_pInfo->GetFriendlyName(cchName, wName.data(), &cchActual);

            if(FAILED(hr))
            {
                friendlyName = nullptr;
                return hr;
            }

            friendlyName = marshal_as<System::String ^>(wName.data());
            return hr;
        }

    }
}