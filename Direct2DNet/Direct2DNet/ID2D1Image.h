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
        [System::Runtime::InteropServices::GuidAttribute("65019f75-8da2-497c-b32c-dfa34e48ede6")]
        public ref class ID2D1Image : Direct2DNet::ID2D1Resource
        {
        protected:
            ID2D1Image(Direct2DNet::ID2D1Factory ^factory) : Direct2DNet::ID2D1Resource(factory) {}

        internal:
            // Used by ID2D1Effect::GetOutput
            ID2D1Image(Direct2DNet::ID2D1Factory ^factory, ::ID2D1Image *pImage);
        };
    }
}