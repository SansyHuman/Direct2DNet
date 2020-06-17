#include "ID2D1GdiMetafile.h"
#include "ID2D1Factory1.h"
#include "ID2D1GdiMetafileSink.h"
#include "../ComIO/Stream.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GdiMetafile::ID2D1GdiMetafile(Direct2DNet::ID2D1Factory1 ^factory, D2DNet::ComIO::Stream ^stream)
            : Direct2DNet::ID2D1Resource(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory1 *)factory->m_pFactory)->CreateGdiMetafile(
                stream->m_pStream,
                (::ID2D1GdiMetafile **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GdiMetafile", (int)hr);
        }

        HRESULT ID2D1GdiMetafile::Stream(Direct2DNet::ID2D1GdiMetafileSink ^sink)
        {
            return ((::ID2D1GdiMetafile *)m_pResource)->Stream(sink->m_pSink);
        }

        HRESULT ID2D1GdiMetafile::GetBounds(Direct2DNet::D2D1_RECT_F %bounds)
        {
            ::D2D1_RECT_F nativeBounds = { 0 };
            HRESULT hr = ((::ID2D1GdiMetafile *)m_pResource)->GetBounds(&nativeBounds);
            bounds = static_cast<Direct2DNet::D2D1_RECT_F>(nativeBounds);
            return hr;
        }

    }
}