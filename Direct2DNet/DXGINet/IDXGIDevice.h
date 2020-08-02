#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../Direct2DNet/Exception/DXException.h"

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIAdapter;

        [System::Runtime::InteropServices::GuidAttribute("54ec77fa-1377-44e6-8c32-88fd5f44c84c")]
        public ref class IDXGIDevice : DXGINet::IDXGIObject
        {
        internal:
            ::IDXGIDevice *m_pDevice;

            IDXGIDevice() : m_pDevice(nullptr) {}

            // Called By D3D11Device::QueryToIDXGIDevice
            IDXGIDevice(::IDXGIDevice *pDevice);

        public:
            ~IDXGIDevice();
            !IDXGIDevice();

        public:
            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pDevice;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            HRESULT GetAdapter(
                [System::Runtime::InteropServices::OutAttribute] DXGINet::IDXGIAdapter ^%adapter
            );
        };
    }
}