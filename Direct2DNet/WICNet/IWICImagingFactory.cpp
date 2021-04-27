#include "IWICImagingFactory.h"
#include "IWICBitmapDecoder.h"
#include "IWICPalette.h"
#include "IWICFormatConverter.h"
#include "IWICComponentInfo.h"

namespace D2DNet
{
    namespace WICNet
    {
        IWICImagingFactory::IWICImagingFactory(D2DNet::CLSCTX clsContext)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IWICImagingFactory *> ppFactory = &m_pFactory;
            hr = CoCreateInstance(
                CLSID_WICImagingFactory,
                __nullptr,
                (DWORD)clsContext,
                __uuidof(::IWICImagingFactory),
                (LPVOID *)ppFactory
            );
            ppFactory = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICImagingFactory", (int)hr);
        }

        IWICImagingFactory::~IWICImagingFactory()
        {
            this->!IWICImagingFactory();
        }

        IWICImagingFactory::!IWICImagingFactory()
        {
            if(m_pFactory)
            {
                m_pFactory->Release();
                m_pFactory = nullptr;
            }
        }

        void IWICImagingFactory::HandleCOMInterface(void *obj)
        {
            if(m_pFactory)
            {
                m_pFactory->Release();
            }

            m_pFactory = (::IWICImagingFactory *)obj;
            m_pFactory->AddRef();
        }

        WICNet::IWICBitmapDecoder ^IWICImagingFactory::CreateDecoderFromFilename(
            System::String ^filename,
            WICNet::Access desiredAccess,
            WICNet::WICDecodeOptions metadataOptions,
            System::Nullable<System::Guid> guidVendor)
        {
            return gcnew WICNet::IWICBitmapDecoder(
                this,
                filename,
                desiredAccess,
                metadataOptions,
                guidVendor
            );
        }

        WICNet::IWICBitmapDecoder ^IWICImagingFactory::CreateDecoderFromStream(ComIO::IStream ^stream, WICNet::WICDecodeOptions metadataOptions, System::Nullable<System::Guid> guidVendor)
        {
            return gcnew WICNet::IWICBitmapDecoder(
                this,
                stream,
                metadataOptions,
                guidVendor
            );
        }

        WICNet::IWICBitmapDecoder ^IWICImagingFactory::CreateDecoderFromFileHandle(
            Microsoft::Win32::SafeHandles::SafeFileHandle ^hFile,
            WICNet::WICDecodeOptions metadataOptions,
            System::Nullable<System::Guid> guidVendor)
        {
            return gcnew WICNet::IWICBitmapDecoder(
                this,
                hFile,
                metadataOptions,
                guidVendor
            );
        }

        WICNet::IWICComponentInfo ^IWICImagingFactory::CreateComponentInfo(System::Guid %clsidComponent)
        {
            return gcnew WICNet::IWICComponentInfo(this, clsidComponent);
        }

        WICNet::IWICBitmapDecoder ^IWICImagingFactory::CreateDecoder(
            System::Guid %guidContainerFormat,
            System::Nullable<System::Guid> guidVendor)
        {
            return gcnew WICNet::IWICBitmapDecoder(this, guidContainerFormat, guidVendor);
        }

        WICNet::IWICPalette ^IWICImagingFactory::CreatePalette()
        {
            return gcnew WICNet::IWICPalette(this);
        }

        WICNet::IWICFormatConverter ^IWICImagingFactory::CreateFormatConverter()
        {
            return gcnew WICNet::IWICFormatConverter(this);
        }

    }
}