#include "IDWriteBitmapRenderTarget.h"
#include "IDWriteRenderingParams.h"
#include "IDWriteGdiInterop.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        GdiInteropBitmapRenderTarget::GdiInteropBitmapRenderTarget(
            DWriteNet::IDWriteGdiInterop ^interop,
            System::IntPtr %hdc,
            UINT32 width,
            UINT32 height)
        {
            pin_ptr<::IDWriteBitmapRenderTarget *> ppTarget = &m_pTarget;
            HRESULT hr = interop->m_pInterop->CreateBitmapRenderTarget(
                (HDC)hdc.ToPointer(),
                width, height,
                (::IDWriteBitmapRenderTarget **)ppTarget
            );
            ppTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteBitmapRenderTarget.", (int)hr);
        }

        GdiInteropBitmapRenderTarget::~GdiInteropBitmapRenderTarget()
        {
            this->!GdiInteropBitmapRenderTarget();
        }

        GdiInteropBitmapRenderTarget::!GdiInteropBitmapRenderTarget()
        {
            if(m_pTarget)
            {
                m_pTarget->Release();
                m_pTarget = nullptr;
            }
        }

        void GdiInteropBitmapRenderTarget::HandleCOMInterface(void *obj)
        {
            throw gcnew System::NotSupportedException("It is not supported to change the internal target since it causes unexpected action.");
        }

        HRESULT GdiInteropBitmapRenderTarget::DrawGlyphRun(
            float baselineOriginX,
            float baselineOriginY,
            DWriteNet::DWRITE_MEASURING_MODE measuringMode,
            DWriteNet::DWRITE_GLYPH_RUN glyphRun,
            DWriteNet::IDWriteRenderingParams ^renderingParams,
            COLORREF textColor,
            D2DNet::RECT %blackBoxRect)
        {
            pin_ptr<D2DNet::RECT> pRect = &blackBoxRect;
            return m_pTarget->DrawGlyphRun(
                baselineOriginX,
                baselineOriginY,
                (::DWRITE_MEASURING_MODE)((int)measuringMode),
                &static_cast<::DWRITE_GLYPH_RUN>(glyphRun),
                renderingParams->m_pParams,
                textColor,
                reinterpret_cast<::RECT *>(pRect)
            );
        }

        float GdiInteropBitmapRenderTarget::GetPixelsPerDip()
        {
            return m_pTarget->GetPixelsPerDip();
        }

        HRESULT GdiInteropBitmapRenderTarget::SetPixelsPerDip(float pixelsPerDip)
        {
            return m_pTarget->SetPixelsPerDip(pixelsPerDip);
        }

        HRESULT GdiInteropBitmapRenderTarget::GetCurrentTransform(DWriteNet::DWRITE_MATRIX %transform)
        {
            pin_ptr<DWriteNet::DWRITE_MATRIX> pTransform = &transform;
            return m_pTarget->GetCurrentTransform(reinterpret_cast<::DWRITE_MATRIX *>(pTransform));
        }

        HRESULT GdiInteropBitmapRenderTarget::SetCurrentTransform(
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform)
        {
            pin_ptr<DWriteNet::DWRITE_MATRIX> pTransform = nullptr;
            if(transform.HasValue)
                pTransform = &transform.Value;
            return m_pTarget->SetCurrentTransform(
                reinterpret_cast<::DWRITE_MATRIX *>(pTransform)
            );
        }

        HRESULT GdiInteropBitmapRenderTarget::GetSize(D2DNet::SIZE %size)
        {
            pin_ptr<D2DNet::SIZE> pSize = &size;
            return m_pTarget->GetSize(reinterpret_cast<::SIZE *>(pSize));
        }

        HRESULT GdiInteropBitmapRenderTarget::Resize(UINT32 width, UINT32 height)
        {
            return m_pTarget->Resize(width, height);
        }

    }
}