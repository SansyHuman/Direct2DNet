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
        ref class IDXGIDevice;

        // Done.

        /// <summary>
        /// The IDXGISurface interface implements methods for image-data objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("cafcb56c-6ac3-4889-bf47-9e23bbd260ec")]
        public ref class IDXGISurface : DXGINet::IDXGIDeviceSubObject
        {
        internal:
            IDXGISurface() : DXGINet::IDXGIDeviceSubObject() {}

            // Called by IDXGISwapChain::GetBufferAsDXGISurface
            IDXGISurface(::IDXGISurface *pSurface);

            IDXGISurface(
                DXGINet::IDXGIDevice ^device,
                DXGINet::DXGI_SURFACE_DESC %desc,
                UINT numSurfaces,
                DXGINet::DXGI_USAGE usage,
                DXGINet::DXGI_CPU_ACCESS cpuAccess,
                [InteropServices::OptionalAttribute] System::Nullable<System::IntPtr> %sharedResource
            );

        public:
            /// <summary>
            /// Gets a description of the surface.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_SURFACE_DESC"/>) tuple. HRESULT is a code that indicates
            /// success or failure. S_OK if successful. <see cref="DXGINet::DXGI_SURFACE_DESC"/> is a
            /// description.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_SURFACE_DESC> GetDesc();

            /// <summary>
            /// Gets a description of the surface.
            /// </summary>
            /// <param name="desc">The surface description(out parameter).</param>
            /// <returns>
            /// Returns a code that indicates success or failure. S_OK if successful.
            /// </returns>
            HRESULT GetDesc(
                [InteropServices::OutAttribute] DXGINet::DXGI_SURFACE_DESC %desc
            );

            /// <summary>
            /// Get a pointer to the data contained in the surface, and deny GPU access to the surface.
            /// </summary>
            /// <param name="mapFlags">
            /// <para>CPU read-write flags. These flags can be combined with a logical OR.</para>
            /// <para>    <see cref="DXGINet::DXGI_MAP::READ"/> - Allow CPU read access.</para>
            /// <para>    <see cref="DXGINet::DXGI_MAP::WRITE"/> - Allow CPU write access.</para>
            /// <para>    <see cref="DXGINet::DXGI_MAP::DISCARD"/> - Discard the previous contents of a
            /// resource when it is mapped.</para>
            /// </param>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_MAPPED_RECT"/>) tuple. HRESULT is a code that indicates
            /// success or failure. S_OK if successful. <see cref="DXGINet::DXGI_MAPPED_RECT"/> is the surface
            /// data.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_MAPPED_RECT> Map(DXGINet::DXGI_MAP mapFlags);

            /// <summary>
            /// Get a pointer to the data contained in the surface, and deny GPU access to the surface.
            /// </summary>
            /// <param name="mapFlags">
            /// <para>CPU read-write flags. These flags can be combined with a logical OR.</para>
            /// <para>    <see cref="DXGINet::DXGI_MAP::READ"/> - Allow CPU read access.</para>
            /// <para>    <see cref="DXGINet::DXGI_MAP::WRITE"/> - Allow CPU write access.</para>
            /// <para>    <see cref="DXGINet::DXGI_MAP::DISCARD"/> - Discard the previous contents of a
            /// resource when it is mapped.</para>
            /// </param>
            /// <param name="lockedRect">The surface data(out parameter).</param>
            /// <returns>
            /// Returns a code that indicates success or failure. S_OK if successful.
            /// </returns>
            HRESULT Map(
                DXGINet::DXGI_MAP mapFlags,
                [InteropServices::OutAttribute] DXGINet::DXGI_MAPPED_RECT %lockedRect
            );

            /// <summary>
            /// Invalidate the pointer to the surface retrieved by IDXGISurface::Map and re-enable GPU
            /// access to the resource.
            /// </summary>
            /// <returns>
            /// Returns a code that indicates success or failure. S_OK if successful.
            /// </returns>
            HRESULT Unmap();

        };
    }
}