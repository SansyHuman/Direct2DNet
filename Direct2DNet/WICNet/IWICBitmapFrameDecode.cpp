#include "IWICBitmapFrameDecode.h"
#include "IWICMetadataQueryReader.h"
#include "IWICColorContext.h"

#include <vector>

namespace D2DNet
{
    namespace WICNet
    {
        HRESULT IWICBitmapFrameDecode::GetMetadataQueryReader(
            WICNet::IWICMetadataQueryReader ^%metadataQueryReader)
        {
            ::IWICMetadataQueryReader *reader = __nullptr;
            HRESULT hr = ((::IWICBitmapFrameDecode *)m_pSource)->GetMetadataQueryReader(&reader);
            if(FAILED(hr) || !reader)
            {
                metadataQueryReader = nullptr;
                return hr;
            }

            metadataQueryReader = gcnew WICNet::IWICMetadataQueryReader(reader);
            return hr;
        }

        HRESULT IWICBitmapFrameDecode::GetColorContexts(
            array<WICNet::IWICColorContext ^> ^colorContexts,
            UINT %cActualCount)
        {
            if(!colorContexts || colorContexts->Length == 0)
            {
                UINT cnt = 0;
                HRESULT hr = ((::IWICBitmapFrameDecode *)m_pSource)->GetColorContexts(0, __nullptr, &cnt);
                cActualCount = cnt;
                return hr;
            }

            UINT cCount = colorContexts->Length;

            std::vector<::IWICColorContext *> contexts(cCount);
            UINT cnt = 0;
            HRESULT hr = ((::IWICBitmapFrameDecode *)m_pSource)->GetColorContexts(
                cCount, contexts.data(), &cnt
            );
            if(FAILED(hr))
            {
                cActualCount = cnt;
                return hr;
            }

            for(UINT i = 0; i < cnt; i++)
            {
                colorContexts[i] = gcnew WICNet::IWICColorContext(contexts[i]);
            }

            cActualCount = cnt;
            return hr;
        }

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