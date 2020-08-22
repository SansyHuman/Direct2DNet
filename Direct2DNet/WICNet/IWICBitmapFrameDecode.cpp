#include "IWICBitmapFrameDecode.h"

namespace D2DNet
{
    namespace WICNet
    {
        HRESULT IWICBitmapFrameDecode::GetThumbnail(WICNet::IWICBitmapSource ^%thumbnail)
        {
            ::IWICBitmapSource *source = __nullptr;

            HRESULT hr = ((::IWICBitmapFrameDecode *)m_pSource)->GetThumbnail(&source);
            if(FAILED(hr) || !source)
            {
                thumbnail = nullptr;
                return hr;
            }

            thumbnail = gcnew WICNet::IWICBitmapSource(source);
            return hr;
        }
    }
}