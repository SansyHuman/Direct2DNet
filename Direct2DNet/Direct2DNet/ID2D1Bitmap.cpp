#include "ID2D1Bitmap.h"
#include "ID2D1Factory.h"
#include "ID2D1RenderTarget.h"

namespace Direct2DNet
{
    ID2D1Bitmap::ID2D1Bitmap(ID2D1Factory ^factory) : Direct2DNet::ID2D1Image(factory)
    {
        
    }

    void ID2D1Bitmap::UpdateBitmapInfo()
    {
        if(!m_pResource)
            return;

        ::ID2D1Bitmap *pBitmap = reinterpret_cast<::ID2D1Bitmap *>(m_pResource);

        m_size = static_cast<Direct2DNet::D2D1_SIZE_F>(pBitmap->GetSize());
        m_pixelSize = static_cast<Direct2DNet::D2D1_SIZE_U>(pBitmap->GetPixelSize());
        m_pixelFormat = static_cast<Direct2DNet::D2D1_PIXEL_FORMAT>(pBitmap->GetPixelFormat());
        pin_ptr<float> pDpiX = &m_dpiX, pDpiY = &m_dpiY;
        pBitmap->GetDpi((float *)pDpiX, (float *)pDpiY);
        pDpiX = nullptr; pDpiY = nullptr;
    }

    HRESULT ID2D1Bitmap::CopyFromBitmap(
        Direct2DNet::D2D1_POINT_2U destPoint,
        Direct2DNet::ID2D1Bitmap ^bitmap,
        Direct2DNet::D2D1_RECT_U srcRect)
    {
        return ((::ID2D1Bitmap *)m_pResource)->CopyFromBitmap(
            &static_cast<::D2D1_POINT_2U>(destPoint),
            (::ID2D1Bitmap *)bitmap->m_pResource,
            &static_cast<::D2D1_RECT_U>(srcRect)
        );
    }

    HRESULT ID2D1Bitmap::CopyFromRenderTarget(
        Direct2DNet::D2D1_POINT_2U destPoint,
        Direct2DNet::ID2D1RenderTarget ^renderTarget,
        Direct2DNet::D2D1_RECT_U srcRect)
    {
        return ((::ID2D1Bitmap *)m_pResource)->CopyFromRenderTarget(
            &static_cast<::D2D1_POINT_2U>(destPoint),
            (::ID2D1RenderTarget *)renderTarget->m_pResource,
            &static_cast<::D2D1_RECT_U>(srcRect)
        );
    }

    HRESULT ID2D1Bitmap::CopyFromMemory(Direct2DNet::D2D1_RECT_U dstRect, void *srcData, unsigned int pitch)
    {
        return ((::ID2D1Bitmap *)m_pResource)->CopyFromMemory(
            &static_cast<::D2D1_RECT_U>(dstRect),
            srcData,
            pitch
        );
    }

}