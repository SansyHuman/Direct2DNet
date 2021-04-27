#include "IWICBitmapEncoder.h"
#include "../ComIO/IStream.h"

namespace D2DNet
{
    namespace WICNet
    {
        IWICBitmapEncoder::~IWICBitmapEncoder()
        {
            this->!IWICBitmapEncoder();
        }

        IWICBitmapEncoder::!IWICBitmapEncoder()
        {
            if(m_pEncoder)
            {
                m_pEncoder->Release();
                m_pEncoder = nullptr;
            }
        }

        void IWICBitmapEncoder::HandleCOMInterface(void *obj)
        {
            if(m_pEncoder)
            {
                m_pEncoder->Release();
            }

            m_pEncoder = (::IWICBitmapEncoder *)obj;
            m_pEncoder->AddRef();
        }

        HRESULT IWICBitmapEncoder::Initialize(
            ComIO::IStream ^stream,
            WICNet::WICBitmapEncoderCacheOption cacheOption)
        {
            return m_pEncoder->Initialize(stream->m_pStream, (::WICBitmapEncoderCacheOption)((int)cacheOption));
        }

        HRESULT IWICBitmapEncoder::GetContainerFormat(System::Guid %guidContainerFormat)
        {
            pin_ptr<System::Guid> pGuid = &guidContainerFormat;
            return m_pEncoder->GetContainerFormat((::GUID *)pGuid);
        }

    }
}