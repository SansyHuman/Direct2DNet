#include "ID2D1BitmapBrush.h"
#include "ID2D1RenderTarget.h"
#include "ID2D1Bitmap.h"
#include "ID2D1DeviceContext.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1BitmapBrush::ID2D1BitmapBrush(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::ID2D1Bitmap ^bitmap
        ) : Direct2DNet::ID2D1Brush(renderTarget->m_factory), m_bitmap(bitmap)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateBitmapBrush(
                bitmap == nullptr ? __nullptr : (::ID2D1Bitmap *)bitmap->m_pResource,
                (::ID2D1BitmapBrush **)ppBrush
            );
            ppBrush = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1BitmapBrush", (int)hr);
        }

        ID2D1BitmapBrush::ID2D1BitmapBrush(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            Direct2DNet::ID2D1Bitmap ^bitmap)
            : Direct2DNet::ID2D1Brush(deviceContext->m_factory), m_bitmap(bitmap)
        {
            
        }

        void ID2D1BitmapBrush::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Brush::HandleCOMInterface(obj);

            ::ID2D1Bitmap *bitmap = __nullptr;
            ((::ID2D1BitmapBrush *)m_pResource)->GetBitmap(&bitmap);
            if(!bitmap)
                m_bitmap = nullptr;
            else
            {
                m_bitmap = gcnew Direct2DNet::ID2D1Bitmap();
                m_bitmap->HandleCOMInterface(bitmap);
                bitmap->Release();
            }
        }

        void ID2D1BitmapBrush::Bitmap::set(Direct2DNet::ID2D1Bitmap ^value)
        {
            ((::ID2D1BitmapBrush *)m_pResource)->SetBitmap(
                value == nullptr ? __nullptr : (::ID2D1Bitmap *)value->m_pResource
            );
            m_bitmap = value;
        }

    }
}