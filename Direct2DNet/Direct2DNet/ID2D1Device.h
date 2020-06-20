#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

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
        ref class ID2D1Factory1;
        ref class ID2D1Factory2;
        ref class ID2D1DeviceContext;

        /// <summary>
        /// The device defines a resource domain whose objects and device contexts can be
        /// used together.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("47dd575d-ac05-4cdd-8049-9b02cd16f44c")]
        public ref class ID2D1Device : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1Device(Direct2DNet::ID2D1Factory1 ^factory, DXGINet::IDXGIDevice ^device);
            ID2D1Device(
                DXGINet::IDXGIDevice ^device,
                System::Nullable<Direct2DNet::D2D1_CREATION_PROPERTIES> %creationProperties
            );

            // Called by ID2D1DeviceContext.
            ID2D1Device(Direct2DNet::ID2D1Factory1 ^factory, ::ID2D1Device *pDevice);

        protected:
            ID2D1Device(Direct2DNet::ID2D1Factory2 ^factory);

        public:
            /// <summary>
            /// Creates a new device context with no initially assigned target.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the context.
            /// </exception>
            Direct2DNet::ID2D1DeviceContext ^CreateDeviceContext(
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );

            // CreatePrintControl

            /// <summary>
            /// Gets and sets the maximum amount of texture memory to maintain before evicting caches.
            /// </summary>
            property UINT64 MaximumTextureMemory
            {
                UINT64 get()
                {
                    return ((::ID2D1Device *)m_pResource)->GetMaximumTextureMemory();
                }

                void set(UINT64 value)
                {
                    ((::ID2D1Device *)m_pResource)->SetMaximumTextureMemory(value);
                }
            }

            /// <summary>
            /// Clears all resources that are cached but not held in use by the application
            /// through an interface reference.
            /// </summary>
            /// <param name="millisecondsSinceUse">
            /// Discards only resources that haven't been used for greater than the specified time
            /// in milliseconds. The default is 0 milliseconds.
            /// </param>
            void ClearResources(
                [OptionalAttribute] System::Nullable<UINT64> millisecondsSinceUse
            );

        };
    }
}