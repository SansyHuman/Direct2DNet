#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Device2.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIDevice;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Factory4;
        ref class ID2D1DeviceContext3;

        // Done.

        /// <summary>
        /// Represents a resource domain whose objects and device contexts can be used together. This
        /// interface performs all the same functions as the ID2D1Device2 interface. It also enables
        /// the creation of ID2D1DeviceContext3 objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("852f2087-802c-4037-ab60-ff2e7ee6fc01")]
        public ref class ID2D1Device3 : Direct2DNet::ID2D1Device2
        {
        internal:
            ID2D1Device3() : Direct2DNet::ID2D1Device2() {}

            ID2D1Device3(Direct2DNet::ID2D1Factory4 ^factory, DXGINet::IDXGIDevice ^device);

        public:
            /// <summary>
            /// Creates a new device context with no initially assigned target.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the context.
            /// </exception>
            Direct2DNet::ID2D1DeviceContext3 ^CreateDeviceContext3(
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );
        };
    }
}