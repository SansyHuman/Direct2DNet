#pragma once

#include "DXGINetHeaders.h"
#include "IDXGIObject.h"
#include "DXGISettings.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    interface class IUnknown;

    namespace DXGINet
    {
        ref class IDXGISurface;

        // Done.

        /// <summary>
        /// An IDXGIOutput interface represents an adapter output (such as a monitor).
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("ae02eedb-c735-4690-8d52-5a8dc20213aa")]
        public ref class IDXGIOutput : DXGINet::IDXGIObject
        {
        internal:
            IDXGIOutput() : DXGINet::IDXGIObject() {}

            IDXGIOutput(::IDXGIOutput *pOutput);

        public:
            /// <summary>
            /// Gets a description of the output.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_OUTPUT_DESC"/>) tuple. HRESULT is a code that indicates
            /// success or failure. S_OK if successful. <see cref="DXGINet::DXGI_OUTPUT_DESC"/> is a
            /// description.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_OUTPUT_DESC> GetDesc();

            /// <summary>
            /// Gets a description of the output.
            /// </summary>
            /// <param name="desc">The output description(out parameter).</param>
            /// <returns>
            /// Returns a code that indicates success or failure. S_OK if successful.
            /// </returns>
            HRESULT GetDesc(
                [InteropServices::OutAttribute] DXGINet::DXGI_OUTPUT_DESC %desc
            );

            /// <summary>
            /// Gets the display modes that match the requested format and other input options.
            /// </summary>
            /// <param name="enumFormat">The color format.</param>
            /// <param name="flags">Options for modes to include.
            /// <see cref="DXGINet::DXGI_ENUM_MODES::SCALING"/> needs to be specified to expose the display
            /// modes that require scaling. Centered modes, requiring no scaling and corresponding directly
            /// to the display output, are enumerated by default.</param>
            /// <param name="numModes">Set desc to null so that numModes returns the number of display modes
            /// that match the format and the options. Otherwise, numModes returns the number of display modes
            /// returned in desc.</param>
            /// <param name="desc">A list of display modes; set to null to get the number of display modes.
            /// The default value is null.</param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR. It is rare, but possible, that the display modes
            /// available can change immediately after calling this method, in which case DXGI_ERROR_MORE_DATA
            /// is returned (if there is not enough room for all the display modes).
            /// If GetDisplayModeList is called from a Remote Desktop Services session(formerly Terminal
            /// Services session), DXGI_ERROR_NOT_CURRENTLY_AVAILABLE is returned.
            /// </returns>
            HRESULT GetDisplayModeList(
                DXGINet::DXGI_FORMAT enumFormat,
                DXGINet::DXGI_ENUM_MODES flags,
                UINT %numModes,
                [InteropServices::OptionalAttribute] array<DXGINet::DXGI_MODE_DESC> ^desc
            );

            /// <summary>
            /// Finds the display mode that most closely matches the requested display mode.
            /// </summary>
            /// <param name="modeToMatch">The desired display mode. Members of DXGI_MODE_DESC can be
            /// unspecified indicating no preference for that member. A value of 0 for width or height
            /// indicates the value is unspecified. If either width or height are 0, both must be 0.
            /// A numerator and denominator of 0 in refreshRate indicate it is unspecified. Other members of
            /// DXGI_MODE_DESC have enumeration values indicating the member is unspecified. If
            /// concernedDevice is null, format cannot be
            /// <see cref="DXGINet::DXGI_FORMAT::FORMAT_UNKNOWN"/>.</param>
            /// <param name="closestMatch">The mode that most closely matches modeToMatch.</param>
            /// <param name="concernedDevice">The Direct3D device interface. If this parameter is null, only
            /// modes whose format matches that of modeToMatch will be returned; otherwise, only those formats
            /// that are supported for scan-out by the device are returned. The default value is null.</param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT FindClosestMatchingMode(
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_MODE_DESC %modeToMatch,
                [InteropServices::OutAttribute] DXGINet::DXGI_MODE_DESC %closestMatch,
                [InteropServices::OptionalAttribute] D2DNet::IUnknown ^concernedDevice
            );

            /// <summary>
            /// Finds the display mode that most closely matches the requested display mode.
            /// </summary>
            /// <param name="modeToMatch">The desired display mode. Members of DXGI_MODE_DESC can be
            /// unspecified indicating no preference for that member. A value of 0 for width or height
            /// indicates the value is unspecified. If either width or height are 0, both must be 0.
            /// A numerator and denominator of 0 in refreshRate indicate it is unspecified. Other members of
            /// DXGI_MODE_DESC have enumeration values indicating the member is unspecified. If
            /// concernedDevice is null, format cannot be
            /// <see cref="DXGINet::DXGI_FORMAT::FORMAT_UNKNOWN"/>.</param>
            /// <param name="concernedDevice">The Direct3D device interface. If this parameter is null, only
            /// modes whose format matches that of modeToMatch will be returned; otherwise, only those formats
            /// that are supported for scan-out by the device are returned. The default value is null.</param>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_MODE_DESC"/>) tuple. HRESULT is one of the following
            /// DXGI_ERROR. <see cref="DXGINet::DXGI_MODE_DESC"/> is the mode that most closely matches
            /// modeToMatch.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_MODE_DESC> FindClosestMatchingMode(
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_MODE_DESC %modeToMatch,
                [InteropServices::OptionalAttribute] D2DNet::IUnknown ^concernedDevice
            );

            /// <summary>
            /// Halt a thread until the next vertical blank occurs.
            /// </summary>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            HRESULT WaitForVBlank();

            /// <summary>
            /// Takes ownership of an output.
            /// </summary>
            /// <param name="device">The IUnknown interface of a device.</param>
            /// <param name="exclusive">Set to true to enable other threads or applications to take ownership
            /// of the device; otherwise, set to false.</param>
            /// <returns>
            /// Returns one of the following DXGI_ERROR.
            /// </returns>
            /// <remarks>
            /// When you are finished with the output, call
            /// <see cref="DXGINet::IDXGIOutput::ReleaseOwnership"/>.
            /// </remarks>
            [System::ObsoleteAttribute("TakeOwnership should not be called directly by applications, since results will be unpredictable. It is called implicitly by the DXGI swap chain object during full-screen transitions, and should not be used as a substitute for swap-chain methods.")]
            HRESULT TakeOwnership(
                D2DNet::IUnknown ^device,
                bool exclusive
            );

            /// <summary>
            /// Releases ownership of the output.
            /// </summary>
            /// <remarks>
            /// If you are not using a swap chain, get access to an output by calling
            /// <see cref="DXGINet::IDXGIOutput::TakeOwnership"/>and release it when you are finished by
            /// calling <see cref="DXGINet::IDXGIOutput::ReleaseOwnership"/>.
            /// </remarks>
            [System::ObsoleteAttribute("An application that uses a swap chain will typically not call this method.")]
            void ReleaseOwnership();

            /// <summary>
            /// Gets a description of the gamma-control capabilities.
            /// </summary>
            /// <param name="gammaCaps">A description of the gamma-control capabilities(out parameter).</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            HRESULT GetGammaControlCapabilities(
                [InteropServices::OutAttribute] DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES %gammaCaps
            );

            /// <summary>
            /// Gets a description of the gamma-control capabilities.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES"/>) tuple. HRESULT is one of
            /// the DXGI_ERROR values. <see cref="DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES"/> is the
            /// gamma-control capabilities.
            /// </returns>
            System::ValueTuple<HRESULT, DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES> GetGammaControlCapabilities();

            /// <summary>
            /// Sets the gamma controls.
            /// </summary>
            /// <param name="array">A DXGI_GAMMA_CONTROL structure that describes the gamma curve to set.
            /// </param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            /// <remarks>
            /// Calling this method is only supported while in full-screen mode.
            /// </remarks>
            HRESULT SetGammaControl(
                [InteropServices::InAttribute][IsReadOnlyAttribute] DXGINet::DXGI_GAMMA_CONTROL %array
            );

            /// <summary>
            /// Gets the gamma control settings.
            /// </summary>
            /// <param name="array">An array of gamma control settings.</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            /// <remarks>
            /// Calling this method is only supported while in full-screen mode.
            /// </remarks>
            HRESULT GetGammaControl(
                [InteropServices::OutAttribute] DXGINet::DXGI_GAMMA_CONTROL %array
            );

            /// <summary>
            /// Gets the gamma control settings.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_GAMMA_CONTROL"/>) tuple. HRESULT is one of
            /// the DXGI_ERROR values. <see cref="DXGINet::DXGI_GAMMA_CONTROL"/> is the
            /// gamma control settings.
            /// </returns>
            /// <remarks>
            /// Calling this method is only supported while in full-screen mode.
            /// </remarks>
            System::ValueTuple<HRESULT, DXGINet::DXGI_GAMMA_CONTROL> GetGammaControl();

            /// <summary>
            /// Changes the display mode.
            /// </summary>
            /// <param name="scanoutSurface">A surface used for rendering an image to
            /// the screen. The surface must have been created as a back buffer.</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            /// <remarks>
            /// This method should only be called between <see cref="DXGINet::IDXGIOutput::TakeOwnership"/>
            /// and <see cref="DXGINet::IDXGIOutput::ReleaseOwnership"/> calls.
            /// If a Windows Store app uses SetDisplaySurface, it fails with
            /// DXGI_ERROR_NOT_CURRENTLY_AVAILABLE. 
            /// </remarks>
            [System::ObsoleteAttribute("TakeOwnership should not be called directly by applications, since results will be unpredictable. It is called implicitly by the DXGI swap chain object during full-screen transitions, and should not be used as a substitute for swap-chain methods.")]
            HRESULT SetDisplaySurface(
                DXGINet::IDXGISurface ^scanoutSurface
            );

            /// <summary>
            /// Gets a copy of the current display surface.
            /// </summary>
            /// <param name="destination">A destination surface.</param>
            /// <returns>
            /// Returns one of the DXGI_ERROR values.
            /// </returns>
            /// <remarks>
            /// Use <see cref="DXGINet::IDXGIOutput::GetDesc"/> to determine the size (width and height) of
            /// the output when you want to allocate space for the destination surface. This is true
            /// regardless of target monitor rotation. A destination surface created by a graphics component
            /// (such as Direct3D 10) must be created with CPU-write permission (see D3D10_CPU_ACCESS_WRITE).
            /// Other surfaces should be created with CPU read-write permission (see
            /// D3D10_CPU_ACCESS_READ_WRITE). This method will modify the surface data to fit the destination
            /// surface (stretch, shrink, convert format, rotate). The stretch and shrink is performed with
            /// point-sampling.
            /// </remarks>
            HRESULT GetDisplaySurfaceData(
                DXGINet::IDXGISurface ^destination
            );

            /// <summary>
            /// Gets statistics about recently rendered frames.
            /// </summary>
            /// <param name="stats">A frame statistics(out parameter).</param>
            /// <returns>
            /// If this function succeeds, it returns S_OK. Otherwise, it might return DXGI_ERROR_INVALID_CALL.
            /// </returns>
            /// <remarks>
            /// Calling this method is only supported while in full-screen mode.
            /// </remarks>
            HRESULT GetFrameStatistics(
                [InteropServices::OutAttribute] DXGINet::DXGI_FRAME_STATISTICS %stats
            );

            /// <summary>
            /// Gets statistics about recently rendered frames.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DXGINet::DXGI_FRAME_STATISTICS"/>) tuple. If this function succeeds,
            /// HRESULT is S_OK. Otherwise, it might be DXGI_ERROR_INVALID_CALL.
            /// <see cref="DXGINet::DXGI_FRAME_STATISTICS"/> is the frame statistics.
            /// </returns>
            /// <remarks>
            /// Calling this method is only supported while in full-screen mode.
            /// </remarks>
            System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS> GetFrameStatistics();
        };
    }
}