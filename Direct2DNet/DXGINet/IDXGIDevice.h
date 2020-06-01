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

        [System::Runtime::InteropServices::GuidAttribute("FD599ED2-0A03-4AFA-9590-65B70076B104")]
        public ref class IDXGIDevice : DXGINet::IDXGIObject
        {
        internal:
            ::IDXGIDevice *m_pDevice;

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

            DXGINet::IDXGIAdapter ^GetAdapter();
        };
    }
}