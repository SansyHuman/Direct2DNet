#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Factory1.h"

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIDevice;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Device1;

        // Done.

        /// <summary>
        /// Creates Direct2D resources. This interface also enables the creation of
        /// ID2D1Device1 objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("94f81a73-9212-4376-9c58-b16a3a0d3992")]
        public ref class ID2D1Factory2 : Direct2DNet::ID2D1Factory1
        {
        internal:
            ID2D1Factory2() : Direct2DNet::ID2D1Factory1() {}

        protected:
            ID2D1Factory2(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                System::Guid guid
            );

            ID2D1Factory2(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                Direct2DNet::D2D1_FACTORY_OPTIONS %options,
                System::Guid guid
            );

        public:
            /// <summary>
            /// Create <see cref="Direct2DNet::ID2D1Factory2"/> object.
            /// The type of the object can determine whether the factory
            /// and the derived resources can be invoked from single thread
            /// or multi thread.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
            ID2D1Factory2(Direct2DNet::D2D1_FACTORY_TYPE type);

            /// <summary>
            /// Create <see cref="Direct2DNet::ID2D1Factory2"/> object.
            /// The type of the object can determine whether the factory
            /// and the derived resources can be invoked from single thread
            /// or multi thread.
            /// The options determine the debug layer level.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_OPTIONS"/>
            ID2D1Factory2(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_FACTORY_OPTIONS %options
            );

            /// <summary>
            /// This creates a new Direct2D device from the given IDXGIDevice.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the device.
            /// </exception>
            Direct2DNet::ID2D1Device1 ^CreateDevice1(DXGINet::IDXGIDevice ^dxgiDevice);
        };
    }
}