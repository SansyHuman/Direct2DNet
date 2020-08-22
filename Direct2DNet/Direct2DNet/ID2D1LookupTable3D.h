#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{

namespace Direct2DNet
{
    ref class ID2D1DeviceContext2;

    namespace Effects
    {
        // Done.

        /// <summary>
        /// A container for 3D lookup table data that can be passed to the LookupTable3D
        /// effect.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("53dd9855-a3b0-4d5b-82e1-26e25c5e5797")]
        public ref class ID2D1LookupTable3D : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1LookupTable3D() : Direct2DNet::ID2D1Resource() {}

            ID2D1LookupTable3D(
                Direct2DNet::ID2D1DeviceContext2 ^context,
                Direct2DNet::D2D1_BUFFER_PRECISION precision,
                System::ValueTuple<UINT32, UINT32, UINT32> %extents,
                array<BYTE> ^data,
                System::ValueTuple<UINT32, UINT32> %strides
            );
        };
    }
}
}