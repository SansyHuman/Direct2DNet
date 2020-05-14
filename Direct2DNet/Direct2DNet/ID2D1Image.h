#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        // Done.

        /// <summary>
        /// Represents a producer of pixels that can fill an arbitrary 2D plane.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("460EA549-0201-40BE-98BF-8659A0D6B568")]
        public ref class ID2D1Image abstract : Direct2DNet::ID2D1Resource
        {
        protected:
            ID2D1Image(Direct2DNet::ID2D1Factory ^factory) : Direct2DNet::ID2D1Resource(factory) {}
        };
    }
}