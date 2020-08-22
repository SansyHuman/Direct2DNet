#include "IDXGIAdapter.h"
#include "IDXGIFactory.h"
#include "../GUIDs.h"
#include "IDXGIOutput.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIAdapter::IDXGIAdapter(::IDXGIAdapter *pAdapter) : DXGINet::IDXGIObject()
        {
            m_pObj = pAdapter;
        }

        IDXGIAdapter::IDXGIAdapter(DXGINet::IDXGIFactory ^factory, System::IntPtr %module)
            : DXGINet::IDXGIObject()
        {
            pin_ptr<::IDXGIObject *> ppAdapter = &m_pObj;
            HRESULT hr = ((::IDXGIFactory *)factory->m_pObj)->CreateSoftwareAdapter(
                (HMODULE)module.ToPointer(), (::IDXGIAdapter **)ppAdapter
            );
            ppAdapter = nullptr;

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to create IDXGIAdapter", (int)hr);
        }

        HRESULT IDXGIAdapter::EnumOutputs(UINT index, DXGINet::IDXGIOutput ^%output)
        {
            ::IDXGIOutput *pOutput = __nullptr;
            HRESULT hr = ((::IDXGIAdapter *)m_pObj)->EnumOutputs(
                index, &pOutput
            );

            if(FAILED(hr) || !pOutput)
            {
                output = nullptr;
                return hr;
            }

            output = gcnew DXGINet::IDXGIOutput(pOutput);
            return hr;
        }

        HRESULT IDXGIAdapter::GetDesc(DXGINet::DXGI_ADAPTER_DESC %desc)
        {
            ::DXGI_ADAPTER_DESC nDesc = { 0 };
            HRESULT hr = ((::IDXGIAdapter *)m_pObj)->GetDesc(&nDesc);
            desc = static_cast<DXGINet::DXGI_ADAPTER_DESC>(nDesc);
            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_ADAPTER_DESC> IDXGIAdapter::GetDesc()
        {
            ::DXGI_ADAPTER_DESC nDesc = { 0 };
            HRESULT hr = ((::IDXGIAdapter *)m_pObj)->GetDesc(&nDesc);
            return System::ValueTuple<HRESULT, DXGINet::DXGI_ADAPTER_DESC>(
                hr, static_cast<DXGINet::DXGI_ADAPTER_DESC>(nDesc));
        }

        HRESULT IDXGIAdapter::CheckInterfaceSupport(
            System::Guid %interfaceName,
            System::Nullable<D2DNet::LARGE_INTEGER> %umdVersion)
        {
            D2DNet::LARGE_INTEGER version;
            HRESULT hr = ((::IDXGIAdapter *)m_pObj)->CheckInterfaceSupport(
                DirectX::ToNativeGUID(interfaceName),
                (::LARGE_INTEGER *)&version
            );

            if(FAILED(hr))
            {
                umdVersion = System::Nullable<D2DNet::LARGE_INTEGER>();
                return hr;
            }

            umdVersion = version;
            return hr;
        }

        System::ValueTuple<HRESULT, System::Nullable<D2DNet::LARGE_INTEGER>> IDXGIAdapter::CheckInterfaceSupport(System::Guid %interfaceName)
        {
            D2DNet::LARGE_INTEGER version;
            HRESULT hr = ((::IDXGIAdapter *)m_pObj)->CheckInterfaceSupport(
                DirectX::ToNativeGUID(interfaceName),
                (::LARGE_INTEGER *)&version
            );

            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, System::Nullable<D2DNet::LARGE_INTEGER>>(
                    hr, System::Nullable<D2DNet::LARGE_INTEGER>()
                    );
            }

            return System::ValueTuple<HRESULT, System::Nullable<D2DNet::LARGE_INTEGER>>(hr, version);
        }

        HRESULT IDXGIAdapter::GetParentFactory(System::Guid %guid, DXGINet::IDXGIFactory ^%factory)
        {
            if(guid == D2DNetGUID::UID_IDXGIFactory)
            {
                ::IDXGIFactory *pFactory = __nullptr;
                HRESULT hr = ((::IDXGIAdapter *)m_pObj)->GetParent(__uuidof(::IDXGIFactory), (void **)&pFactory);

                if(FAILED(hr))
                {
                    factory = nullptr;
                    return hr;
                }

                factory = gcnew DXGINet::IDXGIFactory(pFactory);
                return hr;
            }
            else
            {
                factory = nullptr;
                return DXGI_ERROR_INVALID_CALL;
            }
        }
    }
}