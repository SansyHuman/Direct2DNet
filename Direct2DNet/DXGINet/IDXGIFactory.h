#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../Direct2DNet/Exception/DXException.h"
#include "../IUnknown.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGISwapChain;
        ref class IDXGIAdapter;

        // Done.

        /// <summary>
        /// An IDXGIFactory interface implements methods for generating DXGI objects (which handle full
        /// screen transitions).
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("7b7166ec-21c7-44ae-b21a-c9ae321ae369")]
        public ref class IDXGIFactory : DXGINet::IDXGIObject
        {
        internal:
            // Called by IDXGIAdapter::GetParentFactory
            IDXGIFactory(::IDXGIFactory *pFactory);
            IDXGIFactory(int);
            IDXGIFactory() : DXGINet::IDXGIObject() {}

        public:          
            DXGINet::IDXGIFactory ^CreateFactory();

            /// <summary>
            /// Enumerates the adapters (video cards).
            /// </summary>
            /// <param name="index">The index of the adapter to enumerate.</param>
            /// <param name="adapter">The IDXGIAdapter object at the position specified by the Adapter
            /// parameter(out parameter).</param>
            /// <returns>
            /// Returns S_OK if successful; otherwise, returns DXGI_ERROR_NOT_FOUND if the index is greater
            /// than or equal to the number of adapters in the local system
            /// </returns>
            HRESULT EnumAdapters(
                UINT index,
                [InteropServices::OutAttribute] DXGINet::IDXGIAdapter ^%adapter
            );

            /// <summary>
            /// Allows DXGI to monitor an application's message queue for the alt-enter key sequence (which
            /// causes the application to switch from windowed to full screen or vice versa).
            /// </summary>
            /// <param name="windowHandle">The handle of the window that is to be monitored. This parameter
            /// can be IntPtr::Zero; but only if the flags are also NONE.</param>
            /// <param name="flags"><para>One or more of the following values:</para>
            /// <para>NO_WINDOW_CHANGES - Prevent DXGI from monitoring an applications message queue;
            /// this makes DXGI unable to respond to mode changes.</para>
            /// <para>NO_ALT_ENTER - Prevent DXGI from responding to an alt-enter sequence.</para>
            /// <para>NO_PRINT_SCREEN - Prevent DXGI from responding to a print-screen key.</para>
            /// </param>
            /// <returns>
            /// Returns S_OK if successful; otherwise, DXGI_ERROR_INVALID_CALL if WindowHandle is invalid,
            /// or E_OUTOFMEMORY.
            /// </returns>
            /// <remarks>
            /// If a Windows Store app calls MakeWindowAssociation, it fails with
            /// DXGI_ERROR_NOT_CURRENTLY_AVAILABLE. A Microsoft Win32 application can use
            /// MakeWindowAssociation to control full-screen transitions through the Alt + Enter key
            /// combination and print screen behavior for full screen.For Windows Store apps, because
            /// DXGI can't perform full-screen transitions, a Windows Store app has no way to control
            /// full-screen transitions.
            /// </remarks>
            HRESULT MakeWindowAssociation(
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::IntPtr %windowHandle,
                DXGINet::DXGI_MWA flags
            );

            /// <summary>
            /// Gets the window through which the user controls the transition to and from full screen.
            /// </summary>
            /// <param name="windowHandle">A pointer to a window handle(out parameter).</param>
            /// <returns>
            /// Returns a code that indicates success or failure. S_OK indicates success.
            /// </returns>
            HRESULT GetWindowAssociation(
                [InteropServices::OutAttribute] System::IntPtr %windowHandle
            );

            /// <summary>
            /// Gets the window through which the user controls the transition to and from full screen.
            /// </summary>
            /// <returns>
            /// (HRESULT, IntPtr) tuple. HRESULT is a code that indicates success or failure. S_OK indicates
            /// success. IntPtr is a pointer to a window handle.
            /// </returns>
            System::ValueTuple<HRESULT, System::IntPtr> GetWindowAssociation();

            /// <summary>
            /// Creates a swap chain.
            /// </summary>
            /// <param name="device">For Direct3D 11, and earlier versions of Direct3D, this is a pointer to
            /// the Direct3D device for the swap chain. For Direct3D 12 this is a pointer to a direct command
            /// queue (refer to ID3D12CommandQueue). This parameter cannot be null.</param>
            /// <param name="desc">The swap-chain description.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the swap chain.
            /// </exception>
            DXGINet::IDXGISwapChain ^CreateSwapChain(
                D2DNet::IUnknown ^device,
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_SWAP_CHAIN_DESC %desc
            );

            /// <summary>
            /// Create an adapter interface that represents a software adapter.
            /// </summary>
            /// <param name="module">Handle to the software adapter's dll.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the swap chain.
            /// </exception>
            /// <remarks>
            /// <para>
            /// A software adapter is a DLL that implements the entirety of a device driver interface, plus
            /// emulation, if necessary, of kernel-mode graphics components for Windows. Details on
            /// implementing a software adapter can be found in the Windows Vista Driver Development Kit.
            /// This is a very complex development task, and is not recommended for general readers.</para>
            /// <para>
            /// Calling this method will increment the module's reference count by one. The reference count
            /// can be decremented by calling FreeLibrary.</para>
            /// <para>
            /// The typical calling scenario is to call LoadLibrary, pass the handle to CreateSoftwareAdapter,
            /// then immediately call FreeLibrary on the DLL andforget the DLL's HMODULE. Since the software
            /// adapter calls FreeLibrary when it is destroyed, the lifetime of the DLL will now be owned by
            /// the adapter, and the application is free of any further consideration of its lifetime.</para>
            /// </remarks>
            DXGINet::IDXGIAdapter ^CreateSoftwareAdapter(
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::IntPtr %module
            );
        };
    }
}