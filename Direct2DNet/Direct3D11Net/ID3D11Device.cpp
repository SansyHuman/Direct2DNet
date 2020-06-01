#include "ID3D11Device.h"
#include "ID3D11DeviceContext.h"
#include "../DXGINet/IDXGIDevice.h"
#include <vector>

namespace D2DNet
{
    namespace Direct3D11Net
    {
        ID3D11Device::ID3D11Device(
            D2DNet::D3D_DRIVER_TYPE driverType,
            Direct3D11Net::D3D11_CREATE_DEVICE_FLAG flags,
            array<D2DNet::D3D_FEATURE_LEVEL> ^featureLevels,
            [OutAttribute] D2DNet::D3D_FEATURE_LEVEL %featureLevel,
            [OutAttribute] Direct3D11Net::ID3D11DeviceContext ^%immediateContext
        )
        {
            ::D3D_FEATURE_LEVEL nativeFeatureLevel;
            ::ID3D11DeviceContext *context = __nullptr;

            std::vector<::D3D_FEATURE_LEVEL> nativeFeatureLevels(featureLevels->Length);
            for(int i = 0; i < featureLevels->Length; i++)
                nativeFeatureLevels[i] = (::D3D_FEATURE_LEVEL)((int)featureLevels[i]);

            HRESULT hr = S_OK;
            pin_ptr<::ID3D11Device *> ppDevice = &m_pDevice;

            hr = ::D3D11CreateDevice(
                __nullptr,
                (::D3D_DRIVER_TYPE)((int)driverType),
                0,
                (UINT)flags,
                nativeFeatureLevels.data(),
                nativeFeatureLevels.size(),
                D3D11_SDK_VERSION,
                (::ID3D11Device **)ppDevice,
                &nativeFeatureLevel,
                &context
            );

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to create ID3D11Device.", hr
                );

            featureLevel = (D2DNet::D3D_FEATURE_LEVEL)((int)nativeFeatureLevel);
            immediateContext = gcnew Direct3D11Net::ID3D11DeviceContext(this, context);
        }

        ID3D11Device::~ID3D11Device()
        {
            this->!ID3D11Device();
        }

        ID3D11Device::!ID3D11Device()
        {
            if(m_pDevice)
            {
                m_pDevice->Release();
                m_pDevice = nullptr;
            }
        }

        DXGINet::IDXGIDevice ^ID3D11Device::QueryToIDXGIDevice()
        {
            ::IDXGIDevice *pDevice = __nullptr;
            HRESULT hr = m_pDevice->QueryInterface(__uuidof(::IDXGIDevice), reinterpret_cast<void **>(&pDevice));

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to query IDXGIDevice.", hr
                );

            return gcnew DXGINet::IDXGIDevice(pDevice);
        }

    }
}