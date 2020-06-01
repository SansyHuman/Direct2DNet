#pragma once

#include "DWNetHeaders.h"
#include "../IUnknown.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        /// <summary>
        /// The root interface for all of DWrite's objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("1A34D762-4FA6-4F04-8F0A-A41C871F17B2")]
        public interface class IDirectWriteObject : D2DNet::IUnknown
        {

        };
    }
}