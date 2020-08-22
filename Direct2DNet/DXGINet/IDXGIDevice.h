#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIAdapter;
        ref class IDXGISurface;

        // Done.

        /// <summary>
        /// An IDXGIDevice interface implements a derived class for DXGI objects that produce image data.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("54ec77fa-1377-44e6-8c32-88fd5f44c84c")]
        public ref class IDXGIDevice : DXGINet::IDXGIObject
        {
        internal:
            IDXGIDevice() : DXGINet::IDXGIObject() {}

            // Called By D3D11Device::QueryToIDXGIDevice
            IDXGIDevice(::IDXGIDevice *pDevice);

        public:
            /// <summary>
            /// Returns the adapter for the specified device.
            /// </summary>
            /// <param name="adapter">An IDXGIAdapter object to the adapter(out parameter).</param>
            /// <returns>
            /// Returns S_OK if successful; otherwise, returns one of the DXGI_ERROR that indicates failure.
            /// </returns>
            HRESULT GetAdapter(
                [InteropServices::OutAttribute] DXGINet::IDXGIAdapter ^%adapter
            );

            /// <summary>
            /// Returns a surface.
            /// </summary>
            /// <param name="desc">A DXGI_SURFACE_DESC structure that describes the surface.</param>
            /// <param name="numSurfaces">The number of surfaces to create.</param>
            /// <param name="usage">A DXGI_USAGE flag that specifies how the surface is expected to be used.
            /// </param>
            /// <param name="cpuAccess">A DXGI_CPU_ACCESS flag that specifies how the surface is expected to
            /// be accessed by CPU.
            /// </param>
            /// <param name="sharedResource">An optional pointer to the shared resource information for
            /// opening views of such resources.
            /// </param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the surface.
            /// </exception>
            [System::ObsoleteAttribute("This method is used internally and you should not call it directly in your application.")]
            DXGINet::IDXGISurface ^CreateSurface(
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_SURFACE_DESC %desc,
                UINT numSurfaces,
                DXGINet::DXGI_USAGE usage,
                DXGINet::DXGI_CPU_ACCESS cpuAccess,
                [InteropServices::OptionalAttribute] System::Nullable<System::IntPtr> sharedResource
            );

            /// <summary>
            /// Gets the residency status of an array of resources.
            /// </summary>
            /// <param name="resources">An array of IDXGIResource interfaces.</param>
            /// <param name="residencyStatus">An array of DXGI_RESIDENCY flags. Each element describes
            /// the residency status for corresponding element in the resources argument array. The input
            /// residencyStatus array should have the same length with resources array.</param>
            /// <returns>
            /// Returns S_OK if successful; otherwise, returns DXGI_ERROR_DEVICE_REMOVED, E_INVALIDARG,
            /// or E_POINTER.
            /// </returns>
            HRESULT QueryResourceResidency(
                array<D2DNet::IUnknown ^> ^resources,
                array<DXGINet::DXGI_RESIDENCY> ^residencyStatus
            );

            /// <summary>
            /// Sets the GPU thread priority.
            /// </summary>
            /// <param name="priority">A value that specifies the required GPU thread priority. This value
            /// is between -7(NEG_7) and 7(POS_7), inclusive, where 0(NORMAL) represents normal priority.
            /// </param>
            /// <returns>
            /// Return S_OK if successful; otherwise, returns E_INVALIDARG if the priority parameter
            /// is invalid.
            /// </returns>
            HRESULT SetGPUThreadPriority(DXGINet::DXGI_GPU_THREAD_PRIORITY priority);

            /// <summary>
            /// Gets the GPU thread priority.
            /// </summary>
            /// <param name="priority">A value that specifies the required GPU thread priority. This value
            /// is between -7(NEG_7) and 7(POS_7), inclusive, where 0(NORMAL) represents normal priority.
            /// </param>
            /// <returns>
            /// Return S_OK if successful.
            /// </returns>
            HRESULT GetGPUThreadPriority(
                [InteropServices::OutAttribute] DXGINet::DXGI_GPU_THREAD_PRIORITY %priority
            );

            /// <summary>
            /// Gets the GPU thread priority.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_GPU_THREAD_PRIORITY"/>) tuple. HRESULT is S_OK
            /// if successful. <see cref="DXGINet::DXGI_GPU_THREAD_PRIORITY"/> is the GPU thread priority.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_GPU_THREAD_PRIORITY> GetGPUThreadPriority();
        };
    }
}