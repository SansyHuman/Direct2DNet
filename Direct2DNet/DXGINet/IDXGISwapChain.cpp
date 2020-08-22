#include "IDXGISwapChain.h"
#include "IDXGIFactory.h"
#include "IDXGISurface.h"
#include "IDXGIOutput.h"
#include "../GUIDs.h"
#include "../DXCommonSettings.h"

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
            pin_ptr<::IDXGIObject *> ppSubObject = &m_pObj;
            hr = ((::IDXGIFactory *)(factory->m_pObj))->CreateSwapChain(
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
            return ((::IDXGISwapChain *)m_pObj)->Present(syncInterval, (UINT)flags);
        }

        HRESULT IDXGISwapChain::GetBufferAsDXGISurface(
            unsigned int buffer,
            System::Guid %guid,
            DXGINet::IDXGISurface ^%surface)
        {
            if(guid == D2DNet::D2DNetGUID::UID_IDXGISurface)
            {
                ::IDXGISurface *pSurface = __nullptr;
                HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetBuffer(
                    buffer,
                    __uuidof(::IDXGISurface),
                    (void **)&pSurface
                );

                if(FAILED(hr))
                {
                    surface = nullptr;
                    return hr;
                }

                surface = gcnew DXGINet::IDXGISurface(pSurface);
                return hr;
            }
            else
            {
                surface = nullptr;
                return DXGI_ERROR_INVALID_CALL;
            }
        }

        generic<typename T> where T : D2DNet::IUnknown
        HRESULT D2DNet::DXGINet::IDXGISwapChain::GetBuffer(UINT buffer, T %surface)
        {
            ::IUnknown *pSurface = __nullptr;

            try
            {
                System::Type ^bufferType = T::typeid;
                InteropServices::GuidAttribute ^bufferUidAttr = (InteropServices::GuidAttribute ^)System::Attribute::GetCustomAttribute(bufferType, InteropServices::GuidAttribute::typeid);
                ::GUID bufferUid = DirectX::ToNativeGUID(System::Guid(bufferUidAttr->Value));

                HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetBuffer(
                    buffer,
                    bufferUid,
                    (void **)&pSurface
                );

                if(FAILED(hr) || !pSurface)
                {
                    return hr;
                }

                surface = (T)System::Activator::CreateInstance(bufferType, true);
                surface->HandleCOMInterface(pSurface);

                return hr;
            }
            catch(System::Exception ^e)
            {
                return e->HResult;
            }
            finally
            {
                if(pSurface)
                {
                    pSurface->Release();
                    pSurface = __nullptr;
                }
            }
        }

        HRESULT IDXGISwapChain::GetBuffer(UINT buffer, System::Guid %guid, D2DNet::IUnknown ^%surface)
        {
            ::IUnknown *pSurface = __nullptr;

            try
            {
                if(!D2DNetGUID::uidTypePairs->ContainsKey(guid))
                {
                    surface = nullptr;
                    return DXGI_ERROR_INVALID_CALL;
                }
                System::Type ^bufferType = D2DNetGUID::uidTypePairs[guid];

                ::GUID bufferUid = DirectX::ToNativeGUID(guid);

                HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetBuffer(
                    buffer,
                    bufferUid,
                    (void **)&pSurface
                );

                if(FAILED(hr) || !pSurface)
                {
                    surface = nullptr;
                    return hr;
                }

                surface = (D2DNet::IUnknown ^)System::Activator::CreateInstance(bufferType, true);
                surface->HandleCOMInterface(pSurface);

                return hr;
            }
            catch(System::Exception ^ e)
            {
                return e->HResult;
            }
            finally
            {
                if(pSurface)
                {
                    pSurface->Release();
                    pSurface = __nullptr;
                }
            }
        }

        HRESULT IDXGISwapChain::SetFullscreenState(bool fullscreen, DXGINet::IDXGIOutput ^target)
        {
            return ((::IDXGISwapChain *)m_pObj)->SetFullscreenState(
                System::Convert::ToInt32(fullscreen),
                target ? (::IDXGIOutput *)target->m_pObj : __nullptr
            );
        }

        HRESULT IDXGISwapChain::GetFullscreenState(bool %fullscreen, DXGINet::IDXGIOutput ^%target)
        {
            BOOL Fullscreen = FALSE;
            ::IDXGIOutput *pTarget = __nullptr;
            HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetFullscreenState(
                &Fullscreen, &pTarget
            );

            if(FAILED(hr) || !pTarget)
            {
                fullscreen = System::Convert::ToBoolean(Fullscreen);
                target = nullptr;
                return hr;
            }

            fullscreen = System::Convert::ToBoolean(Fullscreen);
            target = gcnew DXGINet::IDXGIOutput(pTarget);
            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_SWAP_CHAIN_DESC> IDXGISwapChain::GetDesc()
        {
            ::DXGI_SWAP_CHAIN_DESC nativeDesc = { 0 };

            HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetDesc(&nativeDesc);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_SWAP_CHAIN_DESC>(
                hr,
                static_cast<DXGINet::DXGI_SWAP_CHAIN_DESC>(nativeDesc)
                );
        }

        HRESULT IDXGISwapChain::GetDesc(DXGINet::DXGI_SWAP_CHAIN_DESC %desc)
        {
            ::DXGI_SWAP_CHAIN_DESC nativeDesc = { 0 };

            HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetDesc(&nativeDesc);
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
            return ((::IDXGISwapChain *)m_pObj)->ResizeBuffers(
                bufferCount,
                width,
                height,
                (::DXGI_FORMAT)((int)newFormat),
                (UINT)swapChainFlags
            );
        }

        HRESULT IDXGISwapChain::ResizeTarget(DXGINet::DXGI_MODE_DESC %newTargetParameters)
        {
            return ((::IDXGISwapChain *)m_pObj)->ResizeTarget(
                &static_cast<::DXGI_MODE_DESC>(newTargetParameters)
            );
        }

        HRESULT IDXGISwapChain::GetContainingOutput(DXGINet::IDXGIOutput ^%output)
        {
            ::IDXGIOutput *pOutput = __nullptr;
            HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetContainingOutput(&pOutput);
            if(FAILED(hr) || !pOutput)
            {
                output = nullptr;
                return hr;
            }

            output = gcnew DXGINet::IDXGIOutput(pOutput);
            return hr;
        }

        System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS> IDXGISwapChain::GetFrameStatistics()
        {
            ::DXGI_FRAME_STATISTICS nativeStats = { 0 };

            HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetFrameStatistics(&nativeStats);

            return System::ValueTuple<HRESULT, DXGINet::DXGI_FRAME_STATISTICS>(
                hr,
                static_cast<DXGINet::DXGI_FRAME_STATISTICS>(nativeStats)
                );
        }

        HRESULT IDXGISwapChain::GetFrameStatistics(DXGINet::DXGI_FRAME_STATISTICS %stats)
        {
            pin_ptr<DXGINet::DXGI_FRAME_STATISTICS> pStats = &stats;
            return ((::IDXGISwapChain *)m_pObj)->GetFrameStatistics(
                (::DXGI_FRAME_STATISTICS *)pStats
            );
        }

        System::ValueTuple<HRESULT, unsigned int> IDXGISwapChain::GetLastPresentCount()
        {
            unsigned int count = 0;

            HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetLastPresentCount(&count);

            return System::ValueTuple<HRESULT, unsigned int>(hr, count);
        }

        HRESULT IDXGISwapChain::GetLastPresentCount(unsigned int %lastPresentCount)
        {
            unsigned int count = 0;

            HRESULT hr = ((::IDXGISwapChain *)m_pObj)->GetLastPresentCount(&count);
            lastPresentCount = count;

            return hr;
        }

    }
}