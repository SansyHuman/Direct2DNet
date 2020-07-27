#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Factory2.h"

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIDevice;
    }

    namespace Direct2DNet
    {
        /// <summary>
        /// Creates Direct2D resources. This interface also enables the creation of
        /// ID2D1Device2 objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("0869759f-4f00-413f-b03e-2bda45404d0f")]
        public ref class ID2D1Factory3 : Direct2DNet::ID2D1Factory2
        {

        };
    }
}