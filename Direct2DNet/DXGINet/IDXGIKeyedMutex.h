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
        /// Represents a keyed mutex, which allows exclusive access to a shared resource that is used
        /// by multiple devices.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("9d8e1289-d7b3-465f-8126-250e349af85d")]
        public ref class IDXGIKeyedMutex : DXGINet::IDXGIDeviceSubObject
        {
        internal:
            IDXGIKeyedMutex() : DXGINet::IDXGIDeviceSubObject() {}

        public:
            /// <summary>
            /// The shared surface and keyed mutex are no longer in a consistent state.
            /// </summary>
            literal HRESULT ABANDONED = WAIT_ABANDONED;

            /// <summary>
            /// The time-out interval elapsed before the specified key was released.
            /// </summary>
            literal HRESULT TIMEOUT = WAIT_TIMEOUT;

            /// <summary>
            /// Using a key, acquires exclusive rendering access to a shared resource.
            /// </summary>
            /// <param name="key">A value that indicates which device to give access to. This method will
            /// succeed when the device that currently owns the surface calls the
            /// <see cref="DXGINet::IDXGIKeyedMutex::ReleaseSync"/> method using the same value. This value
            /// can be any UINT64 value.</param>
            /// <param name="milliseconds">The time-out interval, in milliseconds. This method will return
            /// if the interval elapses, and the keyed mutex has not been released using the specified Key.
            /// If this value is set to zero, the AcquireSync method will test to see if the keyed mutex has
            /// been released and returns immediately. If this value is set to UInt32::MaxValue, the time-out
            /// interval will never elapse.</param>
            /// <returns>
            /// <para>
            /// Return S_OK if successful. If the owning device attempted to create another keyed mutex on
            /// the same shared resource, AcquireSync returns E_FAIL. AcquireSync can also return the
            /// following DWORD constants.Therefore, you should explicitly check for these constants.
            /// If you only use the SUCCEEDED macro on the return value to determine if AcquireSync succeeded,
            /// you will not catch these constants.
            /// </para>
            /// <para>
            /// <see cref="DXGINet::IDXGIKeyedMutex::ABANDONED"/> - The shared surface and keyed mutex are
            /// no longer in a consistent state. If AcquireSync returns this value, you should release and
            /// recreate both the keyed mutex and the shared surface.
            /// </para>
            /// <para>
            /// <see cref="DXGINet::IDXGIKeyedMutex::TIMEOUT"/> - The time-out interval elapsed before
            /// the specified key was released.
            /// </para>
            /// </returns>
            HRESULT AcquireSync(UINT64 key, DWORD milliseconds);

            /// <summary>
            /// Using a key, releases exclusive rendering access to a shared resource.
            /// </summary>
            /// <param name="key">A value that indicates which device to give access to. This method
            /// succeeds when the device that currently owns the surface calls the ReleaseSync method using
            /// the same value. This value can be any UINT64 value.</param>
            /// <returns>
            /// Returns S_OK if successful. If the device attempted to release a keyed mutex that is not
            /// valid or owned by the device, ReleaseSync returns E_FAIL.
            /// </returns>
            HRESULT ReleaseSync(UINT64 key);
        };
    }
}