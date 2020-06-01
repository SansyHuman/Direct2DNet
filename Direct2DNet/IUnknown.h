#pragma once

namespace D2DNet
{
    [System::Runtime::InteropServices::GuidAttribute("9C2AC6F8-A880-460F-993E-435128D4598F")]
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