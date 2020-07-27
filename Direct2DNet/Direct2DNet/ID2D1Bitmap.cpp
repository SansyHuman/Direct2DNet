#include "ID2D1Bitmap.h"
#include "ID2D1Factory.h"
#include "ID2D1RenderTarget.h"
#include "ID2D1DeviceContext.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Bitmap::ID2D1Bitmap(ID2D1Factory ^factory, ::ID2D1Bitmap *pBitmap)
            : Direct2DNet::ID2D1Image(factory)
        {
            m_pResource = pBitmap;

            UpdateBitmapInfo();
        }

        ID2D1Bitmap::ID2D1Bitmap(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::D2D1_SIZE_U %size,
            Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
        ) : Direct2DNet::ID2D1Image(renderTarget->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateBitmap(
                static_cast<::D2D1_SIZE_U>(size),
                static_cast<::D2D1_BITMAP_PROPERTIES>(bitmapProperties),
                (::ID2D1Bitmap **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Bitmap", (int)hr);

            UpdateBitmapInfo();
        }

        ID2D1Bitmap::ID2D1Bitmap(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::D2D1_SIZE_U %size,
            void *srcData,
            unsigned int pitch,
            Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
        ) : Direct2DNet::ID2D1Image(renderTarget->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateBitmap(
                static_cast<::D2D1_SIZE_U>(size),
                srcData,
                pitch,
                static_cast<::D2D1_BITMAP_PROPERTIES>(bitmapProperties),
                (::ID2D1Bitmap **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Bitmap", (int)hr);

            UpdateBitmapInfo();
        }

        ID2D1Bitmap::ID2D1Bitmap(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            System::Guid %guid,
            D2DNet::IUnknown ^data,
            Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties)
            : Direct2DNet::ID2D1Image(renderTarget->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateSharedBitmap(
                D2DNet::DirectX::ToNativeGUID(guid),
                data->NativePointer,
                &static_cast<::D2D1_BITMAP_PROPERTIES>(bitmapProperties),
                (::ID2D1Bitmap **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Bitmap", (int)hr);

            UpdateBitmapInfo();
        }

        ID2D1Bitmap::ID2D1Bitmap(Direct2DNet::ID2D1DeviceContext ^deviceContext)
            : Direct2DNet::ID2D1Image(deviceContext->m_factory)
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

        void ID2D1Bitmap::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Image::HandleCOMInterface(obj);

            m_size = static_cast<Direct2DNet::D2D1_SIZE_F>(((::ID2D1Bitmap *)m_pResource)->GetSize());
            m_pixelSize = static_cast<Direct2DNet::D2D1_SIZE_U>(((::ID2D1Bitmap *)m_pResource)->GetPixelSize());
            m_pixelFormat = static_cast<Direct2DNet::D2D1_PIXEL_FORMAT>(((::ID2D1Bitmap *)m_pResource)->GetPixelFormat());
            pin_ptr<float> pDpiX = &m_dpiX, pDpiY = &m_dpiY;
            ((::ID2D1Bitmap *)m_pResource)->GetDpi((FLOAT *)pDpiX, (FLOAT *)pDpiY);
            pDpiX = nullptr; pDpiY = nullptr;
        }

        HRESULT ID2D1Bitmap::CopyFromBitmap(
            Direct2DNet::ID2D1Bitmap ^bitmap,
            System::Nullable<Direct2DNet::D2D1_POINT_2U> destPoint,
            System::Nullable<Direct2DNet::D2D1_RECT_U> srcRect)
        {
            return ((::ID2D1Bitmap *)m_pResource)->CopyFromBitmap(
                destPoint.HasValue ? &static_cast<::D2D1_POINT_2U>(destPoint.Value) : __nullptr,
                (::ID2D1Bitmap *)bitmap->m_pResource,
                srcRect.HasValue ? &static_cast<::D2D1_RECT_U>(srcRect.Value) : __nullptr
            );
        }

        HRESULT ID2D1Bitmap::CopyFromRenderTarget(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            System::Nullable<Direct2DNet::D2D1_POINT_2U> destPoint,
            System::Nullable<Direct2DNet::D2D1_RECT_U> srcRect)
        {
            return ((::ID2D1Bitmap *)m_pResource)->CopyFromRenderTarget(
                destPoint.HasValue ? &static_cast<::D2D1_POINT_2U>(destPoint.Value) : __nullptr,
                (::ID2D1RenderTarget *)renderTarget->m_pResource,
                srcRect.HasValue ? &static_cast<::D2D1_RECT_U>(srcRect.Value) : __nullptr
            );
        }

        HRESULT ID2D1Bitmap::CopyFromMemory(
            void *srcData, 
            unsigned int pitch,
            System::Nullable<Direct2DNet::D2D1_RECT_U> dstRect)
        {
            return ((::ID2D1Bitmap *)m_pResource)->CopyFromMemory(
                dstRect.HasValue ? &static_cast<::D2D1_RECT_U>(dstRect.Value) : __nullptr,
                srcData,
                pitch
            );
        }

    }
}