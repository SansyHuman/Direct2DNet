#pragma once

#include "../IUnknown.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        /// <summary>
        /// The root interface for all of D2D's objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("E5DB6297-76DD-4CC3-B706-70A65BA064C0")]
        public interface class IDirect2DObject : D2DNet::IUnknown
        {

        };
    }
}