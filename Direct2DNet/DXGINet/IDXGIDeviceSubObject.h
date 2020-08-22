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

        // Done.

        /// <summary>
        /// Inherited from objects that are tied to the device so that they can retrieve a pointer to it.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("3d3e0379-f9de-4d58-bb6c-18d62992f1a6")]
        public ref class IDXGIDeviceSubObject : DXGINet::IDXGIObject
        {
        protected:
            IDXGIDeviceSubObject() : DXGINet::IDXGIObject() {}

        public:
            /// <summary>
            /// Retrieves the device.
            /// </summary>
            /// <param name="guid">The reference id for the device.</param>
            /// <param name="device">The device(out parameter).</param>
            /// <returns>
            /// A code that indicates success or failure.
            /// </returns>
            HRESULT GetDevice(
                [InteropServices::InAttribute][CompilerServices::IsReadOnlyAttribute] System::Guid %guid,
                [InteropServices::OutAttribute] DXGINet::IDXGIDevice ^%device
            );
        };
    }
}