#include "ID2D1BitmapBrush1.h"
#include "ID2D1DeviceContext.h"
#include "ID2D1Bitmap.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1BitmapBrush1::ID2D1BitmapBrush1(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            Direct2DNet::ID2D1Bitmap ^bitmap)
            : Direct2DNet::ID2D1BitmapBrush(deviceContext, bitmap)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateBitmapBrush(
                bitmap == nullptr ? __nullptr : (::ID2D1Bitmap *)bitmap->m_pResource,
                (::ID2D1BitmapBrush1 **)ppBrush
            );
            ppBrush = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1BitmapBrush1", (int)hr);
        }
    }
}