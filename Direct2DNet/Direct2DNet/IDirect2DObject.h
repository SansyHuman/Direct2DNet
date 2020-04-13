#pragma once

namespace Direct2DNet
{
    /// <summary>
    /// The root interface for all of D2D's objects.
    /// </summary>
    public interface class IDirect2DObject
    {
        /// <summary>
        /// Gets the pointer to the Direct2D interfaces which
        /// wrapper class contains.
        /// </summary>
        property void *NativePointer
        {
            void *get();
        }
    };
}
