#include "ID2D1DCRenderTarget.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DCRenderTarget::ID2D1DCRenderTarget(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %properties
        ) : Direct2DNet::ID2D1RenderTarget(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES> pProperties = &properties;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = factory->m_pFactory->CreateDCRenderTarget(
                reinterpret_cast<::D2D1_RENDER_TARGET_PROPERTIES *>(pProperties),
                (::ID2D1DCRenderTarget **)ppRenderTarget);
            pProperties = nullptr;
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DCRenderTarget", (int)hr);
        }

        HRESULT ID2D1DCRenderTarget::BindDC(System::IntPtr %hDC, D2DNet::RECT %subRect)
        {
            pin_ptr<D2DNet::RECT> pRect = &subRect;
            return ((::ID2D1DCRenderTarget *)m_pResource)->BindDC(
                (HDC)hDC.ToPointer(),
                reinterpret_cast<::RECT *>(pRect)
            );
        }

    }
}