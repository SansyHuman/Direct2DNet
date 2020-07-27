#include "ID2D1GdiInteropRenderTarget.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GdiInteropRenderTarget::~ID2D1GdiInteropRenderTarget()
        {
            this->!ID2D1GdiInteropRenderTarget();
        }

        ID2D1GdiInteropRenderTarget::!ID2D1GdiInteropRenderTarget()
        {
            if(m_pRenderTarget)
            {
                m_pRenderTarget->Release();
                m_pRenderTarget = nullptr;
            }
        }

        void ID2D1GdiInteropRenderTarget::HandleCOMInterface(void *obj)
        {
            if(m_pRenderTarget)
            {
                m_pRenderTarget->Release();
            }

            m_pRenderTarget = (::ID2D1GdiInteropRenderTarget *)obj;
            m_pRenderTarget->AddRef();
        }

        HRESULT ID2D1GdiInteropRenderTarget::GetDC(Direct2DNet::D2D1_DC_INITIALIZE_MODE mode, System::IntPtr %hdc)
        {
            HDC dc = __nullptr;
            HRESULT hr = m_pRenderTarget->GetDC(
                (::D2D1_DC_INITIALIZE_MODE)((int)mode),
                &dc
            );

            if(FAILED(hr))
            {
                hdc = System::IntPtr::Zero;
                return hr;
            }

            hdc = System::IntPtr((void *)dc);
            return hr;
        }

        HRESULT ID2D1GdiInteropRenderTarget::ReleaseDC(System::Nullable<D2DNet::RECT> update)
        {
            return m_pRenderTarget->ReleaseDC(
                update.HasValue ? &static_cast<::RECT>(update.Value) : __nullptr
            );
        }

    }
}