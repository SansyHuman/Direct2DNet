#include "ID2D1HwndRenderTarget.h"
#include "ID2D1Factory.h"

namespace Direct2DNet
{
    ID2D1HwndRenderTarget::ID2D1HwndRenderTarget(
        Direct2DNet::ID2D1Factory ^factory,
        Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties,
        Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES %hwndRenderTargetProperties
    ) : Direct2DNet::ID2D1RenderTarget(factory)
    {
        HRESULT hr = S_OK;
        pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
        hr = factory->m_pFactory->CreateHwndRenderTarget(
            static_cast<::D2D1_RENDER_TARGET_PROPERTIES>(renderTargetProperties),
            static_cast<::D2D1_HWND_RENDER_TARGET_PROPERTIES>(hwndRenderTargetProperties),
            (::ID2D1HwndRenderTarget **)ppRenderTarget);
        ppRenderTarget = nullptr;

        if(FAILED(hr))
            throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1HwndRenderTarget", (int)hr);
    }

    HRESULT ID2D1HwndRenderTarget::Resize(Direct2DNet::D2D1_SIZE_U pixelSize)
    {
        return ((::ID2D1HwndRenderTarget *)m_pResource)->Resize(static_cast<::D2D1_SIZE_U>(pixelSize));
    }

    HRESULT ID2D1HwndRenderTarget::Resize(unsigned int pixelWidth, unsigned int pixelHeight)
    {
        return ((::ID2D1HwndRenderTarget *)m_pResource)->Resize(D2D1::SizeU(pixelWidth, pixelHeight));
    }

}