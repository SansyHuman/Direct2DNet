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

        [System::Runtime::InteropServices::GuidAttribute("62A0F8C4-F96D-4F3A-83EC-294A198CAA59")]
        public ref class IDXGIDeviceSubObject abstract : DXGINet::IDXGIObject
        {
        internal:
            ::IDXGIDeviceSubObject *m_pSubObject;

        protected:
            IDXGIDeviceSubObject() {}

        public:
            ~IDXGIDeviceSubObject();
            !IDXGIDeviceSubObject();

        public:
            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pSubObject;
                }
            }

            DXGINet::IDXGIDevice ^GetDevice(
                [InteropServices::InAttribute][CompilerServices::IsReadOnlyAttribute] System::Guid %guid
            );
        };
    }
}