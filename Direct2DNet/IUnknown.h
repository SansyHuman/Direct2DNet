#pragma once

namespace D2DNet
{
    [System::Runtime::InteropServices::GuidAttribute("00000000-0000-0000-C000-000000000046")]
    public interface class IUnknown
    {
        /// <summary>
        /// Gets the pointer to the COM interfaces which
        /// wrapper class contains.
        /// </summary>
        property void *NativePointer
        {
            void *get();
        }
    };
}