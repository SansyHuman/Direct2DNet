#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Device1.h"

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
        ref class ID2D1Factory3;
        ref class ID2D1Bitmap;

        /// <summary>
        /// Represents a resource domain whose objects and device contexts can be used
        /// together. This interface performs all the same functions as the existing
        /// ID2D1Device1 interface. It also enables the creation of ID2D1DeviceContext2
        /// objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("a44472e1-8dfb-4e60-8492-6e2861c9ca8b")]
        public ref class ID2D1Device2 : Direct2DNet::ID2D1Device1
        {
        private:
            DXGINet::IDXGIDevice ^m_device;

        internal:
            ID2D1Device2() : Direct2DNet::ID2D1Device1() {}

            ID2D1Device2(Direct2DNet::ID2D1Factory3 ^factory, DXGINet::IDXGIDevice ^device);

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Flush all device contexts that reference a given bitmap.
            /// </summary>
            void FlushDeviceContexts(Direct2DNet::ID2D1Bitmap ^bitmap);

            /// <summary>
            /// Returns the DXGI device associated with this D2D device.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::IDXGIDevice"/>) tuple. HRESULT is an error code. 
            /// <see cref="DXGINet::IDXGIDevice"/> is the DXGI device.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::IDXGIDevice ^> GetDxgiDevice();

            /// <summary>
            /// Returns the DXGI device associated with this D2D device.
            /// </summary>
            /// <returns>
            /// If this method succeeds, returns S_OK. Otherwise, returns an error code.
            /// </returns>
            HRESULT GetDxgiDevice(
                [OutAttribute] DXGINet::IDXGIDevice ^%dxgiDevice
            );
        };
    }
}