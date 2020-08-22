#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "IDXGIDeviceSubObject.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        // Done.

        /// <summary>
        /// An IDXGIResource interface allows resource sharing and identifies the memory that a
        /// resource resides in.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("035f3ab4-482e-4e50-b41f-8a7f8bd8960b")]
        public ref class IDXGIResource : DXGINet::IDXGIDeviceSubObject
        {
        internal:
            IDXGIResource() : DXGINet::IDXGIDeviceSubObject() {}

        public:
            /// <summary>
            /// Gets the handle to a shared resource.
            /// </summary>
            /// <param name="sharedHandle">A handle to a resource(out parameter).</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            HRESULT GetSharedHandle(
                [InteropServices::OutAttribute] System::IntPtr %sharedHandle
            );

            /// <summary>
            /// Gets the expected resource usage.
            /// </summary>
            /// <param name="usage">A usage flag(out parameter).</param>
            /// <param name="cpuAccess">A CPU access flag(out parameter).</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            HRESULT GetUsage(
                [InteropServices::OutAttribute] DXGINet::DXGI_USAGE %usage,
                [InteropServices::OutAttribute] DXGINet::DXGI_CPU_ACCESS %cpuAccess
            );

            /// <summary>
            /// Sets the priority for evicting the resource from memory.
            /// </summary>
            /// <param name="evictionPriority">The priority.
            /// See <see cref="DXGINet::DXGI_RESOURCE_PRIORITY"/> for more information.</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            HRESULT SetEvictionPriority(UINT evictionPriority);

            /// <summary>
            /// Gets the eviction priority.
            /// </summary>
            /// <param name="evictionPriority">The priority(out parameter).
            /// See <see cref="DXGINet::DXGI_RESOURCE_PRIORITY"/> for more information.</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            HRESULT GetEvictionPriority(
                [InteropServices::OutAttribute] UINT %evictionPriority
            );
        };
    }
}