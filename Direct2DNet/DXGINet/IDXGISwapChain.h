#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "IDXGIDeviceSubObject.h"
#include "../IUnknown.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIFactory;
        ref class IDXGISurface;
        ref class IDXGIOutput;

        // Done.

        /// <summary>
        /// An IDXGISwapChain interface implements one or more surfaces for storing rendered data
        /// before presenting it to an output.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("310d36a0-d2e7-4c0a-aa04-6a9d23b8886a")]
        public ref class IDXGISwapChain : DXGINet::IDXGIDeviceSubObject
        {
        internal:
            IDXGISwapChain() : DXGINet::IDXGIDeviceSubObject() {}

            IDXGISwapChain(
                DXGINet::IDXGIFactory ^factory,
                D2DNet::IUnknown ^device,
                DXGINet::DXGI_SWAP_CHAIN_DESC %desc
            );

        public:
            /// <summary>
            /// Presents a rendered image to the user.
            /// </summary>
            /// <param name="syncInterval">
            /// <para>An integer that specifies how to synchronize presentation of a frame with the
            /// vertical blank.</para>
            /// <para>For the bit-block transfer (bitblt) model
            /// (<see cref="DXGINet::DXGI_SWAP_EFFECT::DISCARD"/> or
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::SEQUENTIAL"/>), values are:</para>
            /// <para>    0 - The presentation occurs immediately, there is no synchronization.</para>
            /// <para>    1 through 4 - Synchronize presentation after the nth vertical blank.</para>
            /// <para>For the flip model (<see cref="DXGINet::DXGI_SWAP_EFFECT::FLIP_SEQUENTIAL"/>),
            /// values are:</para>
            /// <para>    0 - Cancel the remaining time on the previously presented frame and discard this
            /// frame if a newer frame is queued.</para>
            /// <para>    1 through 4 - Synchronize presentation for at least n vertical blanks.</para>
            /// <para>If the update region straddles more than one output (each represented by IDXGIOutput),
            /// Present performs the synchronization to the output that contains the largest sub-rectangle
            /// of the target window's client area.</para>
            /// </param>
            /// <param name="flags">An integer value that contains swap-chain presentation options.</param>
            /// <returns>
            /// Possible return values include: S_OK, DXGI_ERROR_DEVICE_RESET or DXGI_ERROR_DEVICE_REMOVED
            /// (see DXGI_ERROR), DXGI_STATUS_OCCLUDED (see DXGI_STATUS), or D3DDDIERR_DEVICEREMOVED.
            /// </returns>
            HRESULT Present(
                unsigned int syncInterval,
                DXGINet::DXGI_PRESENT flags
            );

            /// <summary>
            /// Accesses one of the swap-chain's back buffers as IDXGISurface.
            /// </summary>
            /// <param name="buffer">
            /// <para>A zero-based buffer index.</para>
            /// <para>If the swap chain's swap effect is <see cref="DXGINet::DXGI_SWAP_EFFECT::DISCARD"/>,
            /// this method can only access the first buffer; for this situation, set the index to zero.
            /// </para>
            /// <para>If the swap chain's swap effect is either
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::SEQUENTIAL"/> or
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::FLIP_SEQUENTIAL"/>, only the swap chain's zero-index
            /// buffer can be read from and written to. The swap chain's buffers with indexes greater than
            /// zero can only be read from.
            /// </para>
            /// </param>
            /// <param name="guid">The type of interface used to manipulate the buffer.</param>
            /// <param name="surface">The back buffer(out parameter).</param>
            /// <returns>
            /// Returns S_OK if successful; otherwise, returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT GetBufferAsDXGISurface(
                unsigned int buffer,
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::Guid %guid,
                [InteropServices::OutAttribute] DXGINet::IDXGISurface ^%surface
            );

            /// <summary>
            /// Accesses one of the swap-chain's back buffers.
            /// </summary>
            /// <typeparam name="T">A type that inherits from the IUnknown interface.</typeparam>
            /// <param name="buffer">
            /// <para>A zero-based buffer index.</para>
            /// <para>If the swap chain's swap effect is <see cref="DXGINet::DXGI_SWAP_EFFECT::DISCARD"/>,
            /// this method can only access the first buffer; for this situation, set the index to zero.
            /// </para>
            /// <para>If the swap chain's swap effect is either
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::SEQUENTIAL"/> or
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::FLIP_SEQUENTIAL"/>, only the swap chain's zero-index
            /// buffer can be read from and written to. The swap chain's buffers with indexes greater than
            /// zero can only be read from.
            /// </para>
            /// </param>
            /// <param name="surface">The back buffer(out parameter).</param>
            /// <returns>
            /// Returns S_OK if successful; otherwise, returns one of the following DXGI_ERROR.
            /// </returns>
            generic<typename T> where T : D2DNet::IUnknown
            HRESULT GetBuffer(
                UINT buffer,
                [InteropServices::OutAttribute] T %surface
            );

            /// <summary>
            /// Accesses one of the swap-chain's back buffers.
            /// </summary>
            /// <param name="buffer">
            /// <para>A zero-based buffer index.</para>
            /// <para>If the swap chain's swap effect is <see cref="DXGINet::DXGI_SWAP_EFFECT::DISCARD"/>,
            /// this method can only access the first buffer; for this situation, set the index to zero.
            /// </para>
            /// <para>If the swap chain's swap effect is either
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::SEQUENTIAL"/> or
            /// <see cref="DXGINet::DXGI_SWAP_EFFECT::FLIP_SEQUENTIAL"/>, only the swap chain's zero-index
            /// buffer can be read from and written to. The swap chain's buffers with indexes greater than
            /// zero can only be read from.
            /// </para>
            /// </param>
            /// <param name="guid">The type of interface used to manipulate the buffer.</param>
            /// <param name="surface">The back buffer(out parameter).</param>
            /// <returns>
            /// Returns S_OK if successful; otherwise, returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT GetBuffer(
                UINT buffer,
                [InteropServices::InAttribute][IsReadOnlyAttribute] System::Guid %guid,
                [InteropServices::OutAttribute] D2DNet::IUnknown ^%surface
            );

            /// <summary>
            /// Sets the display state to windowed or full screen.
            /// </summary>
            /// <param name="fullscreen">
            /// A Boolean value that specifies whether to set the display state to windowed or full screen.
            /// true for full screen, and false for windowed.
            /// </param>
            /// <param name="target">If you pass true to the Fullscreen parameter to set the display state to
            /// full screen, you can optionally set this parameter to a pointer to an IDXGIOutput interface
            /// for the output target that contains the swap chain. If you set this parameter to null, DXGI
            /// will choose the output based on the swap-chain's device and the output window's placement.
            /// If you pass false to Fullscreen, then you must set this parameter to null. The default value
            /// is null.</param>
            /// <returns>
            /// <para>This method returns one of these values.</para>
            /// <para>S_OK if the action succeeded andthe swap chain was placed in the requested state.</para>
            /// <para>DXGI_ERROR_NOT_CURRENTLY_AVAILABLE if the action failed.When this error is returned,
            /// your application can continue to run in windowed mode and try to switch to full-screen
            /// mode later.There are many reasons why a windowed-mode swap chain cannot switch to
            /// full-screen mode.Here are some examples.</para>
            /// <para>    The application is running over Terminal Server.</para>
            /// <para>    The output window is occluded.</para>
            /// <para>    The output window does not have keyboard focus.</para>
            /// <para>    Another application is already in full - screen mode.</para>
            /// <para>    DXGI_STATUS_MODE_CHANGE_IN_PROGRESS is returned if a fullscreen/windowed mode
            /// transition is occurring when this API is called.</para>
            /// <para>    Other error codes if you run out of memory or encounter another unexpected fault;
            /// these codes may be treated as hard, non - continuable errors.</para>
            /// </returns>
            HRESULT SetFullscreenState(
                bool fullscreen,
                [InteropServices::OptionalAttribute] DXGINet::IDXGIOutput ^target
            );

            /// <summary>
            /// Sets the display state to windowed or full screen.
            /// </summary>
            /// <param name="fullscreen">
            /// A Boolean value that specifies whether to set the display state to windowed or full screen.
            /// true for full screen, and false for windowed(out parameter).
            /// </param>
            /// <param name="target">The output target (see IDXGIOutput) when the mode is full screen;
            /// otherwise null.</param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT GetFullscreenState(
                [InteropServices::OutAttribute] bool %fullscreen,
                [InteropServices::OutAttribute] DXGINet::IDXGIOutput ^%target
            );

            /// <summary>
            /// Get a description of the swap chain.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_SWAP_CHAIN_DESC"/>) tuple. HRESULT is one of the following
            /// DXGI_ERROR. <see cref="DXGINet::DXGI_SWAP_CHAIN_DESC"/> is a description.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_SWAP_CHAIN_DESC> GetDesc();

            /// <summary>
            /// Get a description of the swap chain.
            /// </summary>
            /// <param name="desc">
            /// The swap-chain description(out parameter).
            /// </param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT GetDesc(
                [InteropServices::OutAttribute] DXGINet::DXGI_SWAP_CHAIN_DESC %desc
            );

            /// <summary>
            /// Changes the swap chain's back buffer size, format, and number of buffers.
            /// This should be called when the application window is resized.
            /// </summary>
            /// <param name="bufferCount">
            /// The number of buffers in the swap chain (including all back and front buffers). This number
            /// can be different from the number of buffers with which you created the swap chain. This
            /// number can't be greater than DXGI_MAX_SWAP_CHAIN_BUFFERS. Set this number to zero to preserve
            /// the existing number of buffers in the swap chain. You can't specify less than two buffers
            /// for the flip presentation model.
            /// </param>
            /// <param name="width">
            /// The new width of the back buffer. If you specify zero, DXGI will use the width of the client
            /// area of the target window. You can't specify the width as zero if the swap chain is for a
            /// composition surface.
            /// </param>
            /// <param name="height">
            /// The new height of the back buffer. If you specify zero, DXGI will use the height of the
            /// client area of the target window. You can't specify the height as zero if the swap chain is
            /// for a composition surface.
            /// </param>
            /// <param name="newFormat">
            /// A DXGI_FORMAT-typed value for the new format of the back buffer. Set this value to
            /// <see cref="DXGINet::DXGI_FORMAT::FORMAT_UNKNOWN"/> to preserve the existing format of the
            // back buffer. The flip presentation model supports a more restricted set of formats than the
            /// bit-block transfer (bitblt) model.
            /// </param>
            /// <param name="swapChainFlags">
            /// A combination of DXGI_SWAP_CHAIN_FLAG-typed values that are combined by using a bitwise
            /// OR operation. The resulting value specifies options for swap-chain behavior.
            /// </param>
            /// <returns>
            /// Returns S_OK if successful; an error code otherwise. For a list of error codes, see DXGI_ERROR.
            /// </returns>
            HRESULT ResizeBuffers(
                unsigned int bufferCount,
                unsigned int width,
                unsigned int height,
                DXGINet::DXGI_FORMAT newFormat,
                DXGINet::DXGI_SWAP_CHAIN_FLAG swapChainFlags);

            /// <summary>
            /// Resizes the output target.
            /// </summary>
            /// <param name="newTargetParameters">
            /// A DXGI_MODE_DESC structure that describes the mode, which specifies the new width, height,
            /// format, and refresh rate of the target. If the format is
            /// <see cref="DXGINet::DXGI_FORMAT::FORMAT_UNKNOWN"/>, ResizeTarget uses the existing format.
            /// We only recommend that you use <see cref="DXGINet::DXGI_FORMAT::FORMAT_UNKNOWN"/> when the
            /// swap chain is in full-screen mode as this method is not thread safe.
            /// </param>
            /// <returns>
            /// Returns a code that indicates success or failure. DXGI_STATUS_MODE_CHANGE_IN_PROGRESS
            /// is returned if a full-screen/windowed mode transition is occurring when this API is called.
            // See DXGI_ERROR for additional DXGI error codes.
            /// </returns>
            HRESULT ResizeTarget(
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_MODE_DESC %newTargetParameters
            );

            /// <summary>
            /// Get the output (the display monitor) that contains the majority of the client area of
            /// the target window.
            /// </summary>
            /// <param name="output">
            /// The output object(out parameter).
            /// </param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT GetContainingOutput(
                [InteropServices::OutAttribute] DXGINet::IDXGIOutput ^%output
            );

            /// <summary>
            /// Gets performance statistics about the last render frame.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_FRAME_STATISTICS"/>) tuple. HRESULT is one of the following
            /// DXGI_ERROR. <see cref="DXGINet::DXGI_FRAME_STATISTICS"/> is a statistics.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS> GetFrameStatistics();

            /// <summary>
            /// Gets performance statistics about the last render frame.
            /// </summary>
            /// <param name="stats">
            /// A DXGI_FRAME_STATISTICS structure for the frame statistics(out parameter).
            /// </param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT GetFrameStatistics(
                [InteropServices::OutAttribute] DXGINet::DXGI_FRAME_STATISTICS %stats
            );

            /// <summary>
            /// Gets the number of times that IDXGISwapChain::Present or IDXGISwapChain1::Present1 has
            /// been called.
            /// </summary>
            /// <returns>
            /// (HRESULT, uint) tuple. HRESULT is one of the following DXGI_ERROR. uint is the present count.
            /// </returns>
            System::ValueTuple<HRESULT, unsigned int> GetLastPresentCount();

            /// <summary>
            /// Gets the number of times that IDXGISwapChain::Present or IDXGISwapChain1::Present1 has
            /// been called.
            /// </summary>
            /// <param name="lastPresentCount">
            /// A variable that receives the number of calls(out parameter).
            /// </param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT GetLastPresentCount(
                [InteropServices::OutAttribute] unsigned int %lastPresentCount
            );
        };
}
}