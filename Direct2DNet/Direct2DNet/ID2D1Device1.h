#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Device.h"

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
        ref class ID2D1Factory2;
        ref class ID2D1Factory3;
        ref class ID2D1DeviceContext1;

        /// <summary>
        /// Represents a resource domain whose objects and device contexts can be used
        /// together.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("d21768e1-23a4-4823-a14b-7c3eba85d658")]
        public ref class ID2D1Device1 : Direct2DNet::ID2D1Device
        {
        internal:
            ID2D1Device1() : Direct2DNet::ID2D1Device() {}

            ID2D1Device1(Direct2DNet::ID2D1Factory2 ^factory, DXGINet::IDXGIDevice ^device);

        protected:
            ID2D1Device1(Direct2DNet::ID2D1Factory3 ^factory)
                : Direct2DNet::ID2D1Device((Direct2DNet::ID2D1Factory2 ^)factory) {}

        public:
            /// <summary>
            /// Gets and sets the rendering priority currently set on the device.
            /// </summary>
            property Direct2DNet::D2D1_RENDERING_PRIORITY RenderingPriority
            {
                Direct2DNet::D2D1_RENDERING_PRIORITY get()
                {
                    return (Direct2DNet::D2D1_RENDERING_PRIORITY)((int)
                        ((::ID2D1Device1 *)m_pResource)->GetRenderingPriority()
                        );
                }

                void set(Direct2DNet::D2D1_RENDERING_PRIORITY value)
                {
                    ((::ID2D1Device1 *)m_pResource)->SetRenderingPriority(
                        (::D2D1_RENDERING_PRIORITY)((int)value)
                    );
                }
            }

            /// <summary>
            /// Creates a new device context with no initially assigned target.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the context.
            /// </exception>
            Direct2DNet::ID2D1DeviceContext1 ^CreateDeviceContext1(
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );
        };
    }
}