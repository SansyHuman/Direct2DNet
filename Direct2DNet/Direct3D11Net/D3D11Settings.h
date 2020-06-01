#pragma once

#include "D3D11NetHeaders.h"

namespace D2DNet
{
    namespace Direct3D11Net
    {
        [System::FlagsAttribute]
        public enum class D3D11_CREATE_DEVICE_FLAG
        {
            SINGLETHREADED = 0x1,
            DEBUG = 0x2,
            SWITCH_TO_REF = 0x4,
            PREVENT_INTERNAL_THREADING_OPTIMIZATIONS = 0x8,
            BGRA_SUPPORT = 0x20,
            DEBUGGABLE = 0x40,
            PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY = 0x80,
            DISABLE_GPU_TIMEOUT = 0x100,
            VIDEO_SUPPORT = 0x800
        };

    }
}