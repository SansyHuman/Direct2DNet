#include "IDXGIOutput.h"
#include "../IUnknown.h"
#include "../DXCommonSettings.h"
#include "IDXGISurface.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIOutput::IDXGIOutput(::IDXGIOutput *pOutput) : DXGINet::IDXGIObject()
        {
            m_pObj = pOutput;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_OUTPUT_DESC> IDXGIOutput::GetDesc()
        {
            ::DXGI_OUTPUT_DESC nDesc = { 0 };

            HRESULT hr = ((::IDXGIOutput *)m_pObj)->GetDesc(&nDesc);
            return System::ValueTuple<HRESULT, DXGINet::DXGI_OUTPUT_DESC>(
                hr, static_cast<DXGINet::DXGI_OUTPUT_DESC>(nDesc));
        }

        HRESULT IDXGIOutput::GetDesc(DXGINet::DXGI_OUTPUT_DESC %desc)
        {
            ::DXGI_OUTPUT_DESC nDesc = { 0 };

            HRESULT hr = ((::IDXGIOutput *)m_pObj)->GetDesc(&nDesc);
            desc = static_cast<DXGINet::DXGI_OUTPUT_DESC>(nDesc);
            return hr;
        }

        HRESULT IDXGIOutput::GetDisplayModeList(
            DXGINet::DXGI_FORMAT enumFormat,
            DXGINet::DXGI_ENUM_MODES flags,
            UINT %numModes,
            array<DXGINet::DXGI_MODE_DESC> ^desc)
        {
            if(!desc)
            {
                pin_ptr<UINT> pNum = &numModes;
                return ((::IDXGIOutput *)m_pObj)->GetDisplayModeList(
                    (::DXGI_FORMAT)((int)enumFormat),
                    (UINT)flags,
                    (UINT *)pNum,
                    __nullptr
                );
            }

            if(numModes > desc->Length || desc->Length == 0)
                return DXGI_ERROR_INVALID_CALL;

            pin_ptr<DXGINet::DXGI_MODE_DESC> pDesc = &desc[0];
            pin_ptr<UINT> pNum = &numModes;
            return ((::IDXGIOutput *)m_pObj)->GetDisplayModeList(
                (::DXGI_FORMAT)((int)enumFormat),
                (UINT)flags,
                (UINT *)pNum,
                (::DXGI_MODE_DESC *)pDesc
            );
        }

        HRESULT IDXGIOutput::FindClosestMatchingMode(
            DXGINet::DXGI_MODE_DESC %modeToMatch,
            DXGINet::DXGI_MODE_DESC %closestMatch,
            D2DNet::IUnknown ^concernedDevice)
        {
            pin_ptr<DXGINet::DXGI_MODE_DESC> pTo = &modeToMatch, pCl = &closestMatch;
            return ((::IDXGIOutput *)m_pObj)->FindClosestMatchingMode(
                reinterpret_cast<::DXGI_MODE_DESC *>(pTo),
                reinterpret_cast<::DXGI_MODE_DESC *>(pCl),
                concernedDevice ? (::IUnknown *)concernedDevice->NativePointer : __nullptr
            );
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_MODE_DESC> IDXGIOutput::FindClosestMatchingMode(
            DXGINet::DXGI_MODE_DESC %modeToMatch,
            D2DNet::IUnknown ^concernedDevice)
        {
            pin_ptr<DXGINet::DXGI_MODE_DESC> pTo = &modeToMatch;
            DXGINet::DXGI_MODE_DESC closest;
            HRESULT hr = ((::IDXGIOutput *)m_pObj)->FindClosestMatchingMode(
                reinterpret_cast<::DXGI_MODE_DESC *>(pTo),
                reinterpret_cast<::DXGI_MODE_DESC *>(&closest),
                concernedDevice ? (::IUnknown *)concernedDevice->NativePointer : __nullptr
            );

            return System::ValueTuple<HRESULT, DXGINet::DXGI_MODE_DESC>(hr, closest);
        }

        HRESULT IDXGIOutput::WaitForVBlank()
        {
            return ((::IDXGIOutput *)m_pObj)->WaitForVBlank();
        }

        HRESULT IDXGIOutput::TakeOwnership(D2DNet::IUnknown ^device, bool exclusive)
        {
            return ((::IDXGIOutput *)m_pObj)->TakeOwnership(
                (::IUnknown *)device->NativePointer,
                System::Convert::ToInt32(exclusive)
            );
        }

        void IDXGIOutput::ReleaseOwnership()
        {
            ((::IDXGIOutput *)m_pObj)->ReleaseOwnership();
        }

        HRESULT IDXGIOutput::GetGammaControlCapabilities(DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES %gammaCaps)
        {
            ::DXGI_GAMMA_CONTROL_CAPABILITIES caps = { 0 };
            HRESULT hr = ((::IDXGIOutput *)m_pObj)->GetGammaControlCapabilities(&caps);
            gammaCaps = static_cast<DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES>(caps);
            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES> IDXGIOutput::GetGammaControlCapabilities()
        {
            ::DXGI_GAMMA_CONTROL_CAPABILITIES caps = { 0 };
            HRESULT hr = ((::IDXGIOutput *)m_pObj)->GetGammaControlCapabilities(&caps);
            return System::ValueTuple<HRESULT, DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES>(
                hr, static_cast<DXGINet::DXGI_GAMMA_CONTROL_CAPABILITIES>(caps));
        }

        HRESULT IDXGIOutput::SetGammaControl(DXGINet::DXGI_GAMMA_CONTROL %array)
        {
            try
            {
                HRESULT hr = ((::IDXGIOutput *)m_pObj)->SetGammaControl(
                    &static_cast<::DXGI_GAMMA_CONTROL>(array)
                );
                return hr;
            }
            catch(System::Exception ^e)
            {
#if defined(DEBUG) || defined(_DEBUG)
                DirectX::PrintDebugMessage(e->Message);
                DirectX::PrintDebugMessage(e->StackTrace);

                return e->HResult;
#endif
            }
        }

        HRESULT IDXGIOutput::GetGammaControl(DXGINet::DXGI_GAMMA_CONTROL %array)
        {
            ::DXGI_GAMMA_CONTROL value = { 0 };
            HRESULT hr = ((::IDXGIOutput *)m_pObj)->GetGammaControl(&value);
            array = static_cast<DXGINet::DXGI_GAMMA_CONTROL>(value);
            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_GAMMA_CONTROL> IDXGIOutput::GetGammaControl()
        {
            ::DXGI_GAMMA_CONTROL value = { 0 };
            HRESULT hr = ((::IDXGIOutput *)m_pObj)->GetGammaControl(&value);
            return System::ValueTuple<HRESULT, DXGINet::DXGI_GAMMA_CONTROL>(
                hr, static_cast<DXGINet::DXGI_GAMMA_CONTROL>(value));
        }

        HRESULT IDXGIOutput::SetDisplaySurface(DXGINet::IDXGISurface ^scanoutSurface)
        {
            return ((::IDXGIOutput *)m_pObj)->SetDisplaySurface(
                (::IDXGISurface *)scanoutSurface->m_pObj
            );
        }

        HRESULT IDXGIOutput::GetDisplaySurfaceData(DXGINet::IDXGISurface ^destination)
        {
            return ((::IDXGIOutput *)m_pObj)->GetDisplaySurfaceData(
                (::IDXGISurface *)destination->m_pObj
            );
        }

        HRESULT IDXGIOutput::GetFrameStatistics(DXGINet::DXGI_FRAME_STATISTICS %stats)
        {
            pin_ptr<DXGINet::DXGI_FRAME_STATISTICS> pStats = &stats;
            return ((::IDXGIOutput *)m_pObj)->GetFrameStatistics(
                reinterpret_cast<::DXGI_FRAME_STATISTICS *>(pStats)
            );
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS> IDXGIOutput::GetFrameStatistics()
        {
            DXGINet::DXGI_FRAME_STATISTICS stats;
            HRESULT hr = ((::IDXGIOutput *)m_pObj)->GetFrameStatistics(
                reinterpret_cast<::DXGI_FRAME_STATISTICS *>(&stats)
            );
            return System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS>(hr, stats);
        }

    }
}
