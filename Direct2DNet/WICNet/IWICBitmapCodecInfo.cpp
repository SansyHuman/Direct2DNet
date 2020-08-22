#include "IWICBitmapCodecInfo.h"

#include <vector>

namespace D2DNet
{
    namespace WICNet
    {
        HRESULT IWICBitmapCodecInfo::GetContainerFormat(System::Guid %guidContainerFormat)
        {
            pin_ptr<System::Guid> pGuid = &guidContainerFormat;
            return ((::IWICBitmapCodecInfo *)m_pInfo)->GetContainerFormat((::GUID *)pGuid);
        }

        HRESULT IWICBitmapCodecInfo::GetPixelFormats(array<System::Guid> ^guidPixelFormats, UINT %cActual)
        {
            if(!guidPixelFormats)
            {
                UINT actual = 0;
                HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetPixelFormats(0, __nullptr, &actual);
                cActual = actual;
                return hr;
            }

            UINT cFormats = guidPixelFormats->Length;
            if(cFormats == 0)
            {
                UINT actual = 0;
                HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetPixelFormats(0, __nullptr, &actual);
                cActual = actual;
                return hr;
            }

            pin_ptr<System::Guid> pFormats = &guidPixelFormats[0];
            pin_ptr<UINT> pcActual = &cActual;

            return ((::IWICBitmapCodecInfo *)m_pInfo)->GetPixelFormats(cFormats, (::GUID *)pFormats, (UINT *)pcActual);
        }

        HRESULT IWICBitmapCodecInfo::GetColorManagementVersion(System::String ^%colorManagementVersion)
        {
            UINT cchVersion = 0;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetColorManagementVersion(0, __nullptr, &cchVersion);
            if(cchVersion == 0)
            {
                colorManagementVersion = "";
                return S_OK;
            }

            std::vector<WCHAR> wVersion(cchVersion);
            UINT cchActual = 0;
            hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetColorManagementVersion(cchVersion, wVersion.data(), &cchActual);

            if(FAILED(hr))
            {
                colorManagementVersion = nullptr;
                return hr;
            }

            colorManagementVersion = marshal_as<System::String ^>(wVersion.data());
            return hr;
        }

        HRESULT IWICBitmapCodecInfo::GetDeviceManufacturer(System::String ^%deviceManufacturer)
        {
            UINT cchDevice = 0;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetDeviceManufacturer(0, __nullptr, &cchDevice);
            if(cchDevice == 0)
            {
                deviceManufacturer = "";
                return S_OK;
            }

            std::vector<WCHAR> wDevice(cchDevice);
            UINT cchActual = 0;
            hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetDeviceManufacturer(cchDevice, wDevice.data(), &cchActual);

            if(FAILED(hr))
            {
                deviceManufacturer = nullptr;
                return hr;
            }

            deviceManufacturer = marshal_as<System::String ^>(wDevice.data());
            return hr;
        }

        HRESULT IWICBitmapCodecInfo::GetDeviceModels(System::String ^%deviceModels)
        {
            UINT cchDevice = 0;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetDeviceModels(0, __nullptr, &cchDevice);
            if(cchDevice == 0)
            {
                deviceModels = "";
                return S_OK;
            }

            std::vector<WCHAR> wDevice(cchDevice);
            UINT cchActual = 0;
            hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetDeviceModels(cchDevice, wDevice.data(), &cchActual);

            if(FAILED(hr))
            {
                deviceModels = nullptr;
                return hr;
            }

            deviceModels = marshal_as<System::String ^>(wDevice.data());
            return hr;
        }

        HRESULT IWICBitmapCodecInfo::GetMimeTypes(System::String ^%mimeTypes)
        {
            UINT cchMime = 0;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetMimeTypes(0, __nullptr, &cchMime);
            if(cchMime == 0)
            {
                mimeTypes = "";
                return S_OK;
            }

            std::vector<WCHAR> wMime(cchMime);
            UINT cchActual = 0;
            hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetMimeTypes(cchMime, wMime.data(), &cchActual);

            if(FAILED(hr))
            {
                mimeTypes = nullptr;
                return hr;
            }

            mimeTypes = marshal_as<System::String ^>(wMime.data());
            return hr;
        }

        HRESULT IWICBitmapCodecInfo::GetFileExtensions(System::String ^%fileExtensions)
        {
            UINT cchFile = 0;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetFileExtensions(0, __nullptr, &cchFile);
            if(cchFile == 0)
            {
                fileExtensions = "";
                return S_OK;
            }

            std::vector<WCHAR> wFile(cchFile);
            UINT cchActual = 0;
            hr = ((::IWICBitmapCodecInfo *)m_pInfo)->GetFileExtensions(cchFile, wFile.data(), &cchActual);

            if(FAILED(hr))
            {
                fileExtensions = nullptr;
                return hr;
            }

            fileExtensions = marshal_as<System::String ^>(wFile.data());
            return hr;
        }

        HRESULT IWICBitmapCodecInfo::DoesSupportAnimation(bool %supportAnimation)
        {
            BOOL anim = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportAnimation(&anim);
            supportAnimation = System::Convert::ToBoolean(anim);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICBitmapCodecInfo::DoesSupportAnimation()
        {
            BOOL anim = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportAnimation(&anim);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(anim)
                );
        }

        HRESULT IWICBitmapCodecInfo::DoesSupportChromakey(bool %supportChromakey)
        {
            BOOL chro = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportChromakey(&chro);
            supportChromakey = System::Convert::ToBoolean(chro);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICBitmapCodecInfo::DoesSupportChromakey()
        {
            BOOL chro = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportChromakey(&chro);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(chro)
                );
        }

        HRESULT IWICBitmapCodecInfo::DoesSupportLossless(bool %supportLossless)
        {
            BOOL loss = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportLossless(&loss);
            supportLossless = System::Convert::ToBoolean(loss);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICBitmapCodecInfo::DoesSupportLossless()
        {
            BOOL loss = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportLossless(&loss);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(loss)
                );
        }

        HRESULT IWICBitmapCodecInfo::DoesSupportMultiframe(bool %supportMultiframe)
        {
            BOOL mult = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportMultiframe(&mult);
            supportMultiframe = System::Convert::ToBoolean(mult);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICBitmapCodecInfo::DoesSupportMultiframe()
        {
            BOOL mult = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->DoesSupportMultiframe(&mult);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(mult)
                );
        }

        HRESULT IWICBitmapCodecInfo::MatchesMimeType(System::String ^mimeType, bool %matches)
        {
            marshal_context context;

            BOOL matc = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->MatchesMimeType(
                context.marshal_as<LPCWSTR>(mimeType), &matc
            );
            matches = System::Convert::ToBoolean(matc);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICBitmapCodecInfo::MatchesMimeType(System::String ^mimeType)
        {
            marshal_context context;

            BOOL matc = FALSE;
            HRESULT hr = ((::IWICBitmapCodecInfo *)m_pInfo)->MatchesMimeType(
                context.marshal_as<LPCWSTR>(mimeType), &matc
            );
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(matc)
                );
        }

    }
}