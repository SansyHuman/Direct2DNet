#pragma once

#include "DXGINetHeaders.h"

namespace D2DNet
{
    namespace DXGINet
    {
#ifndef DXGINET_ERROR
#define DXGINET_ERROR(x) literal HRESULT E_ ## x = DXGI_ERROR_ ## x
#endif

#ifndef DXGINET_STATUS
#define DXGINET_STATUS(x) literal HRESULT x = DXGI_STATUS_ ## x
#endif

        /// <summary>
        /// Contains DXGI error codes.
        /// </summary>
        public ref class DXGIError abstract sealed
        {
        public:
            /// <summary>
            /// You tried to use a resource to which you did not have the required access privileges.
            /// This error is most typically caused when you write to a shared resource with read-only access.
            /// </summary>
            DXGINET_ERROR(ACCESS_DENIED);

            /// <summary>
            /// The desktop duplication interface is invalid. The desktop duplication interface typically
            /// becomes invalid when a different type of image is displayed on the desktop.
            /// </summary>
            DXGINET_ERROR(ACCESS_LOST);

            /// <summary>
            /// The desired element already exists. This is returned by DXGIDeclareAdapterRemovalSupport
            /// if it is not the first time that the function is called.
            /// </summary>
            DXGINET_ERROR(ALREADY_EXISTS);

            /// <summary>
            /// DXGI can't provide content protection on the swap chain. This error is typically caused by
            /// an older driver, or when you use a swap chain that is incompatible with content protection.
            /// </summary>
            DXGINET_ERROR(CANNOT_PROTECT_CONTENT);

            /// <summary>
            /// The application's device failed due to badly formed commands sent by the application.
            /// This is an design-time issue that should be investigated and fixed.
            /// </summary>
            DXGINET_ERROR(DEVICE_HUNG);

            /// <summary>
            /// The video card has been physically removed from the system, or a driver upgrade for the
            /// video card has occurred. The application should destroy and recreate the device.
            /// </summary>
            DXGINET_ERROR(DEVICE_REMOVED);

            /// <summary>
            /// The device failed due to a badly formed command. This is a run-time issue;
            /// The application should destroy and recreate the device.
            /// </summary>
            DXGINET_ERROR(DEVICE_RESET);

            /// <summary>
            /// The driver encountered a problem and was put into the device removed state.
            /// </summary>
            DXGINET_ERROR(DRIVER_INTERNAL_ERROR);

            /// <summary>
            /// An event (for example, a power cycle) interrupted the gathering of presentation statistics.
            /// </summary>
            DXGINET_ERROR(FRAME_STATISTICS_DISJOINT);

            /// <summary>
            /// The application attempted to acquire exclusive ownership of an output, but failed because
            /// some other application (or device within the application) already acquired ownership.
            /// </summary>
            DXGINET_ERROR(GRAPHICS_VIDPN_SOURCE_IN_USE);

            /// <summary>
            /// The application provided invalid parameter data; this must be debugged and fixed before
            /// the application is released.
            /// </summary>
            DXGINET_ERROR(INVALID_CALL);

            /// <summary>
            /// The buffer supplied by the application is not big enough to hold the requested data.
            /// </summary>
            DXGINET_ERROR(MORE_DATA);

            /// <summary>
            /// The supplied name of a resource in a call to IDXGIResource1::CreateSharedHandle is
            /// already associated with some other resource.
            /// </summary>
            DXGINET_ERROR(NAME_ALREADY_EXISTS);

            /// <summary>
            /// A global counter resource is in use, and the Direct3D device can't currently use the
            /// counter resource.
            /// </summary>
            DXGINET_ERROR(NONEXCLUSIVE);

            /// <summary>
            /// The resource or request is not currently available, but it might become available later.
            /// </summary>
            DXGINET_ERROR(NOT_CURRENTLY_AVAILABLE);

            /// <summary>
            /// When calling IDXGIObject::GetPrivateData, the GUID passed in is not recognized as one
            /// previously passed to IDXGIObject::SetPrivateData or IDXGIObject::SetPrivateDataInterface.
            /// When calling IDXGIFactory::EnumAdapters or IDXGIAdapter::EnumOutputs, the enumerated
            /// ordinal is out of range.
            /// </summary>
            DXGINET_ERROR(NOT_FOUND);

            /// <summary>
            /// The application's remote device has been removed due to session disconnect or network
            /// disconnect. The application should call IDXGIFactory1::IsCurrent to find out when the
            /// remote device becomes available again.
            /// </summary>
            DXGINET_ERROR(REMOTE_CLIENT_DISCONNECTED);

            /// <summary>
            /// The device has been removed during a remote session because the remote computer ran out 
            /// of memory.
            /// </summary>
            DXGINET_ERROR(REMOTE_OUTOFMEMORY);

            /// <summary>
            /// The DXGI output (monitor) to which the swap chain content was restricted is now disconnected
            /// or changed.
            /// </summary>
            DXGINET_ERROR(RESTRICT_TO_OUTPUT_STALE);

            /// <summary>
            /// The operation depends on an SDK component that is missing or mismatched.
            /// </summary>
            DXGINET_ERROR(SDK_COMPONENT_MISSING);

            /// <summary>
            /// The Remote Desktop Services session is currently disconnected.
            /// </summary>
            DXGINET_ERROR(SESSION_DISCONNECTED);

            /// <summary>
            /// The requested functionality is not supported by the device or the driver.
            /// </summary>
            DXGINET_ERROR(UNSUPPORTED);

            /// <summary>
            /// The time-out interval elapsed before the next desktop frame was available.
            /// </summary>
            DXGINET_ERROR(WAIT_TIMEOUT);

            /// <summary>
            /// The GPU was busy at the moment when a call was made to perform an operation, and did
            /// not execute or schedule the operation.
            /// </summary>
            DXGINET_ERROR(WAS_STILL_DRAWING);
        };

        /// <summary>
        /// Contains DXGI status codes.
        /// </summary>
        public ref class DXGIStatus abstract sealed
        {
        public:
            /// <summary>
            /// The window content is not visible. When receiving this status, an application can stop
            /// rendering and use DXGI_PRESENT_TEST to determine when to resume rendering.
            /// </summary>
            DXGINET_STATUS(OCCLUDED);

            /// <summary>
            /// The Present operation was partially invisible to the user.
            /// </summary>
            DXGINET_STATUS(CLIPPED);

            /// <summary>
            /// The driver is requesting that the DXGI runtime not use shared resources to communicate with
            /// the Desktop Window Manager.
            /// </summary>
            DXGINET_STATUS(NO_REDIRECTION);

            /// <summary>
            /// The Present operation was not visible because the Windows session has switched to another
            /// desktop (for example, ctrl-alt-del).
            /// </summary>
            DXGINET_STATUS(NO_DESKTOP_ACCESS);

            /// <summary>
            /// The Present operation was not visible because the target monitor was being used for some
            /// other purpose.
            /// </summary>
            DXGINET_STATUS(GRAPHICS_VIDPN_SOURCE_IN_USE);

            /// <summary>
            /// The desktop display mode has been changed, there might be color conversion/stretching.
            /// The application should call IDXGISwapChain::ResizeBuffers to match the new display mode.
            /// </summary>
            DXGINET_STATUS(MODE_CHANGED);

            /// <summary>
            /// IDXGISwapChain::ResizeTarget and IDXGISwapChain::SetFullscreenState will return
            /// MODE_CHANGE_IN_PROGRESS if a fullscreen/windowed mode transition is occurring
            /// when either API is called.
            /// </summary>
            DXGINET_STATUS(MODE_CHANGE_IN_PROGRESS);
        };
    }
}