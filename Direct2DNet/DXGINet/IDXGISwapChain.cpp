#include "IDXGISwapChain.h"
#include "IDXGIFactory.h"
#include "IDXGISurface.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGISwapChain::IDXGISwapChain(
            DXGINet::IDXGIFactory ^factory,
            D2DNet::IUnknown ^device,
            DXGINet::DXGI_SWAP_CHAIN_DESC %desc)
            : DXGINet::IDXGIDeviceSubObject()
        {
            HRESULT hr = S_OK;
            pin_ptr<::IDXGIDeviceSubObject *> ppSubObject = &m_pSubObject;
            hr = factory->m_pFactory->CreateSwapChain(
                (::IUnknown *)device->NativePointer,
                &static_cast<::DXGI_SWAP_CHAIN_DESC>(desc),
                (::IDXGISwapChain **)ppSubObject
            );
            ppSubObject = nullptr;

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to create IDXGISwapChain", (int)hr);
        }

        HRESULT IDXGISwapChain::Present(unsigned int syncInterval, DXGINet::DXGI_PRESENT flags)
        {
            return ((::IDXGISwapChain *)m_pSubObject)->Present(syncInterval, (UINT)flags);
        }

        DXGINet::IDXGISurface ^IDXGISwapChain::GetBufferAsDXGISurface(unsigned int buffer, System::Guid %guid)
        {
            if(guid == D2DNet::D2DNetGUID::UID_IDXGISurface)
            {
                ::IDXGISurface *pSurface = __nullptr;
                HRESULT hr = ((::IDXGISwapChain *)m_pSubObject)->GetBuffer(
                    buffer,
                    __uuidof(::IDXGISurface),
                    (void **)&pSurface
                );

                if(FAILED(hr))
                    throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                        "Failed to get buffer as IDXGISurface.", (int)hr);

                return gcnew DXGINet::IDXGISurface(pSurface);
            }
            else
            {
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to get buffer as IDXGISurface.", (int)DXGI_ERROR_INVALID_CALL);
            }
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_SWAP_CHAIN_DESC> IDXGISwapChain::GetDesc()
        {
            ::DXGI_SWAP_CHAIN_DESC nativeDesc;

            HRESULT hr = ((::IDXGISwapChain *)m_pSubObject)->GetDesc(&nativeDesc);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_SWAP_CHAIN_DESC>(
                hr,
                static_cast<DXGINet::DXGI_SWAP_CHAIN_DESC>(nativeDesc)
                );
        }

        HRESULT IDXGISwapChain::GetDesc(DXGINet::DXGI_SWAP_CHAIN_DESC %desc)
        {
            ::DXGI_SWAP_CHAIN_DESC nativeDesc;

            HRESULT hr = ((::IDXGISwapChain *)m_pSubObject)->GetDesc(&nativeDesc);
            desc = static_cast<DXGINet::DXGI_SWAP_CHAIN_DESC>(nativeDesc);

            return hr;
        }

        HRESULT IDXGISwapChain::ResizeBuffers(
            unsigned int bufferCount,
            unsigned int width,
            unsigned int height,
            DXGINet::DXGI_FORMAT newFormat,
            DXGINet::DXGI_SWAP_CHAIN_FLAG swapChainFlags)
        {
            return ((::IDXGISwapChain *)m_pSubObject)->ResizeBuffers(
                bufferCount,
                width,
                height,
                (::DXGI_FORMAT)((int)newFormat),
                (UINT)swapChainFlags
            );
        }

        HRESULT IDXGISwapChain::ResizeTarget(DXGINet::DXGI_MODE_DESC %newTargetParameters)
        {
            return ((::IDXGISwapChain *)m_pSubObject)->ResizeTarget(
                &static_cast<::DXGI_MODE_DESC>(newTargetParameters)
            );
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS> IDXGISwapChain::GetFrameStatistics()
        {
            ::DXGI_FRAME_STATISTICS nativeStats;

            HRESULT hr = ((::IDXGISwapChain *)m_pSubObject)->GetFrameStatistics(&nativeStats);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS>(
                hr,
                static_cast<DXGINet::DXGI_FRAME_STATISTICS>(nativeStats)
                );
        }

        HRESULT IDXGISwapChain::GetFrameStatistics(DXGINet::DXGI_FRAME_STATISTICS %stats)
        {
            ::DXGI_FRAME_STATISTICS nativeStats;

            HRESULT hr = ((::IDXGISwapChain *)m_pSubObject)->GetFrameStatistics(&nativeStats);
            stats = static_cast<DXGINet::DXGI_FRAME_STATISTICS>(nativeStats);

            return hr;
        }

        System::ValueTuple<HRESULT, unsigned int> IDXGISwapChain::GetLastPresentCount()
        {
            unsigned int count = 0;

            HRESULT hr = ((::IDXGISwapChain *)m_pSubObject)->GetLastPresentCount(&count);

            return System::ValueTuple<HRESULT, unsigned int>(hr, count);
        }

        HRESULT IDXGISwapChain::GetLastPresentCount(unsigned int %lastPresentCount)
        {
            unsigned int count = 0;

            HRESULT hr = ((::IDXGISwapChain *)m_pSubObject)->GetLastPresentCount(&count);
            lastPresentCount = count;

            return hr;
        }

    }
}