#pragma once

#include "D3D11NetHeaders.h"
#include "../DXCommonSettings.h"
#include "D3D11Settings.h"
#include "IDirect3D11Object.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIDevice;
    }

    namespace Direct3D11Net
    {
        ref class ID3D11DeviceContext;

        [System::Runtime::InteropServices::GuidAttribute("db6f6ddb-ac77-4e88-8253-819df9bbf140")]
        public ref class ID3D11Device : Direct3D11Net::IDirect3D11Object
        {
        internal:
            ::ID3D11Device *m_pDevice;

            ID3D11Device() : m_pDevice(nullptr) {}

            ID3D11Device(::ID3D11Device *pDevice);

        public:
            ID3D11Device(
                D2DNet::D3D_DRIVER_TYPE driverType,
                Direct3D11Net::D3D11_CREATE_DEVICE_FLAG flags,
                array<D2DNet::D3D_FEATURE_LEVEL> ^featureLevels,
                [OutAttribute] D2DNet::D3D_FEATURE_LEVEL %featureLevel,
                [OutAttribute] Direct3D11Net::ID3D11DeviceContext ^%immediateContext
            );

            ~ID3D11Device();
            !ID3D11Device();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pDevice;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            DXGINet::IDXGIDevice ^QueryToIDXGIDevice();
        };
    }
}