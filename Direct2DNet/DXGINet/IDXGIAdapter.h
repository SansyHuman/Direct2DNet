#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../GUIDs.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIFactory;
        ref class IDXGIOutput;

        // Done.

        /// <summary>
        /// The IDXGIAdapter interface represents a display subsystem (including one or more GPUs, DACs
        /// and video memory).
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2411e7e1-12ac-4ccf-bd14-9798e8534dc0")]
        public ref class IDXGIAdapter : DXGINet::IDXGIObject
        {
        internal:
            IDXGIAdapter() : DXGINet::IDXGIObject() {}

            // Called by IDXGIDevice::GetAdapter
            IDXGIAdapter(::IDXGIAdapter *pAdapter);

            IDXGIAdapter(DXGINet::IDXGIFactory ^factory, System::IntPtr %module);

        public:
            /// <summary>
            /// Enumerate adapter (video card) outputs.
            /// </summary>
            /// <param name="index">The index of the output.</param>
            /// <param name="output">An IDXGIOutput object at the position specified by the indx parameter
            /// (out parameter).</param>
            /// <returns>
            /// Returns S_OK if successful; a code that indicates success or failure (see DXGI_ERROR).
            /// DXGI_ERROR_NOT_FOUND is returned if the index is greater than the number of outputs.
            /// </returns>
            HRESULT EnumOutputs(
                UINT index,
                [InteropServices::OutAttribute] DXGINet::IDXGIOutput ^%output
            );

            /// <summary>
            /// Gets a DXGI 1.0 description of an adapter (or video card).
            /// </summary>
            /// <param name="desc">A DXGI_ADAPTER_DESC structure that describes the adapter(out parameter).
            /// On feature level 9 graphics hardware, GetDesc returns zeros for the PCI ID in the VendorId,
            /// DeviceId, SubSysId, and Revision members of DXGI_ADAPTER_DESC and ¡°Software Adapter¡± for the
            /// description string in the Description member.</param>
            /// <returns>
            /// Returns S_OK if successful.
            /// </returns>
            HRESULT GetDesc(
                [InteropServices::OutAttribute] DXGINet::DXGI_ADAPTER_DESC %desc
            );

            /// <summary>
            /// Gets a DXGI 1.0 description of an adapter (or video card).
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_ADAPTER_DESC"/>) tuple. HRESULT is a code that indicates
            /// success or failure. S_OK if successful. <see cref="DXGINet::DXGI_ADAPTER_DESC"/> is a
            /// description.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_ADAPTER_DESC> GetDesc();

            /// <summary>
            /// Checks whether the system supports a device interface for a graphics component.
            /// </summary>
            /// <param name="interfaceName">The GUID of the interface of the device version for which
            /// support is being checked.</param>
            /// <param name="umdVersion">The user mode driver version of interfaceName. This is returned
            /// only if the interface is supported, otherwise this parameter will be null(out parameter).
            /// </param>
            /// <returns>
            /// Returns S_OK if successful; a code that indicates success or failure (see DXGI_ERROR).
            /// DXGI_ERROR_NOT_FOUND is returned if the index is greater than the number of outputs.
            /// </returns>
            HRESULT CheckInterfaceSupport(
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::Guid %interfaceName,
                [InteropServices::OutAttribute] System::Nullable<D2DNet::LARGE_INTEGER> %umdVersion
            );

            /// <summary>
            /// Checks whether the system supports a device interface for a graphics component.
            /// </summary>
            /// <param name="interfaceName">The GUID of the interface of the device version for which
            /// support is being checked.</param>
            /// <returns>
            /// (HRESULT, <see cref="D2DNet::LARGE_INTEGER"/>?) tuple. HRESULT is S_OK if successful; a
            /// code that indicates success or failure (see DXGI_ERROR).
            /// DXGI_ERROR_NOT_FOUND is returned if the index is greater than the number of outputs.
            /// <see cref="D2DNet::LARGE_INTEGER"/>? is a nullable type of the user mode driver version of
            /// interfaceName. This is returned only if the interface is supported, otherwise this will be
            /// null.
            /// </returns>
            System::ValueTuple<HRESULT, System::Nullable<D2DNet::LARGE_INTEGER>> CheckInterfaceSupport(
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::Guid %interfaceName
            );

            /// <summary>
            /// Gets a parent of the adapter as a factory.
            /// </summary>
            /// <param name="guid">The GUID of the factory.</param>
            /// <param name="factory">The parent factory(out parameter).</param>
            /// <returns>
            /// Returns S_OK if successful. if the factory type is not supported, returns
            /// DXGI_ERROR_INVALID_CALL.
            /// </returns>
            HRESULT GetParentFactory(
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::Guid %guid,
                [InteropServices::OutAttribute] DXGINet::IDXGIFactory ^%factory
            );

        };
    }
}