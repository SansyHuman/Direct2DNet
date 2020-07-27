#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIDevice;

        [System::Runtime::InteropServices::GuidAttribute("3d3e0379-f9de-4d58-bb6c-18d62992f1a6")]
        public ref class IDXGIDeviceSubObject abstract : DXGINet::IDXGIObject
        {
        internal:
            ::IDXGIDeviceSubObject *m_pSubObject;

        protected:
            IDXGIDeviceSubObject() : m_pSubObject(nullptr) {}

        public:
            ~IDXGIDeviceSubObject();
            !IDXGIDeviceSubObject();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pSubObject;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            DXGINet::IDXGIDevice ^GetDevice(
                [InteropServices::InAttribute][CompilerServices::IsReadOnlyAttribute] System::Guid %guid
            );
        };
    }
}