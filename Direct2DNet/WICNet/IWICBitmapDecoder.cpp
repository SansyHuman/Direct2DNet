#include "IWICBitmapDecoder.h"
#include "IWICImagingFactory.h"
#include "../ComIO/Stream.h"
#include "../DXCommonSettings.h"
#include "IWICBitmapSource.h"
#include "IWICBitmapFrameDecode.h"
#include "IWICBitmapDecoderInfo.h"
#include "IWICPalette.h"

#include <msclr/marshal.h>

using namespace msclr::interop;

namespace D2DNet
{
    namespace WICNet
    {
        IWICBitmapDecoder::IWICBitmapDecoder(
            WICNet::IWICImagingFactory ^factory,
            System::String ^filename,
            WICNet::Access desiredAccess,
            WICNet::WICDecodeOptions metadataOptions,
            System::Nullable<System::Guid> %guidVendor)
        {
            marshal_context context;

            HRESULT hr = S_OK;
            pin_ptr<::IWICBitmapDecoder *> ppDecoder = &m_pDecoder;
            pin_ptr<System::Guid> pVendor = nullptr;
            if(guidVendor.HasValue)
                pVendor = &guidVendor.Value;

            hr = factory->m_pFactory->CreateDecoderFromFilename(
                context.marshal_as<LPCWSTR>(filename),
                reinterpret_cast<GUID *>(pVendor),
                (DWORD)desiredAccess,
                (::WICDecodeOptions)((DWORD)metadataOptions),
                (::IWICBitmapDecoder **)ppDecoder
            );

            ppDecoder = nullptr;
            pVendor = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICBitmapDecoder", (int)hr);
        }

        IWICBitmapDecoder::IWICBitmapDecoder(
            WICNet::IWICImagingFactory ^factory,
            ComIO::Stream ^stream,
            WICNet::WICDecodeOptions metadataOptions,
            System::Nullable<System::Guid> %guidVendor)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IWICBitmapDecoder *> ppDecoder = &m_pDecoder;
            pin_ptr<System::Guid> pVendor = nullptr;
            if(guidVendor.HasValue)
                pVendor = &guidVendor.Value;

            hr = factory->m_pFactory->CreateDecoderFromStream(
                stream->m_pStream,
                reinterpret_cast<GUID *>(pVendor),
                (::WICDecodeOptions)((DWORD)metadataOptions),
                (::IWICBitmapDecoder **)ppDecoder
            );

            ppDecoder = nullptr;
            pVendor = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICBitmapDecoder", (int)hr);
        }

        IWICBitmapDecoder::IWICBitmapDecoder(
            WICNet::IWICImagingFactory ^factory,
            Microsoft::Win32::SafeHandles::SafeFileHandle ^hFile,
            WICNet::WICDecodeOptions metadataOptions,
            System::Nullable<System::Guid> %guidVendor)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IWICBitmapDecoder *> ppDecoder = &m_pDecoder;
            pin_ptr<System::Guid> pVendor = nullptr;
            if(guidVendor.HasValue)
                pVendor = &guidVendor.Value;

            hr = factory->m_pFactory->CreateDecoderFromFileHandle(
                (ULONG_PTR)hFile->DangerousGetHandle().ToInt64(),
                reinterpret_cast<GUID *>(pVendor),
                (::WICDecodeOptions)((DWORD)metadataOptions),
                (::IWICBitmapDecoder **)ppDecoder
            );

            ppDecoder = nullptr;
            pVendor = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICBitmapDecoder", (int)hr);
        }

        IWICBitmapDecoder::IWICBitmapDecoder(WICNet::IWICImagingFactory ^factory, System::Guid %guidContainerFormat, System::Nullable<System::Guid> %guidVendor)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IWICBitmapDecoder *> ppDecoder = &m_pDecoder;
            pin_ptr<System::Guid> pVendor = nullptr;
            if(guidVendor.HasValue)
                pVendor = &guidVendor.Value;

            hr = factory->m_pFactory->CreateDecoder(
                DirectX::ToNativeGUID(guidContainerFormat),
                reinterpret_cast<GUID *>(pVendor),
                (::IWICBitmapDecoder **)ppDecoder
            );

            ppDecoder = nullptr;
            pVendor = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICBitmapDecoder", (int)hr);
        }

        IWICBitmapDecoder::IWICBitmapDecoder(WICNet::IWICBitmapDecoderInfo ^info)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IWICBitmapDecoder *> ppDecoder = &m_pDecoder;
            hr = ((::IWICBitmapDecoderInfo *)info->m_pInfo)->CreateInstance((::IWICBitmapDecoder **)ppDecoder);
            ppDecoder = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICBitmapDecoder", (int)hr);
        }

        void IWICBitmapDecoder::HandleCOMInterface(void *obj)
        {
            if(m_pDecoder)
            {
                m_pDecoder->Release();
            }

            m_pDecoder = (::IWICBitmapDecoder *)obj;
            m_pDecoder->AddRef();
        }

        HRESULT IWICBitmapDecoder::QueryCapability(
            ComIO::Stream ^stream,
            WICNet::WICBitmapDecoderCapabilities %capability)
        {
            DWORD cap = 0;

            HRESULT hr = m_pDecoder->QueryCapability(stream->m_pStream, &cap);

            capability = (WICNet::WICBitmapDecoderCapabilities)cap;
            return hr;
        }

        System::ValueTuple<HRESULT, WICNet::WICBitmapDecoderCapabilities> IWICBitmapDecoder::QueryCapability(
            ComIO::Stream ^stream)
        {
            DWORD cap = 0;

            HRESULT hr = m_pDecoder->QueryCapability(stream->m_pStream, &cap);

            return System::ValueTuple<HRESULT, WICNet::WICBitmapDecoderCapabilities>(
                hr,
                (WICNet::WICBitmapDecoderCapabilities)cap
                );
        }

        HRESULT IWICBitmapDecoder::Initialize(ComIO::Stream ^stream, WICNet::WICDecodeOptions cacheOptions)
        {
            return m_pDecoder->Initialize(stream->m_pStream, (::WICDecodeOptions)(DWORD)(cacheOptions));
        }

        HRESULT IWICBitmapDecoder::GetContainerFormat(System::Guid %guidContainerFormat)
        {
            ::GUID format = { 0 };

            HRESULT hr = m_pDecoder->GetContainerFormat(&format);

            guidContainerFormat = DirectX::ToManagedGUID(format);
            return hr;
        }

        HRESULT IWICBitmapDecoder::GetDecoderInfo(WICNet::IWICBitmapDecoderInfo ^%decoderInfo)
        {
            ::IWICBitmapDecoderInfo *info = __nullptr;
            HRESULT hr = m_pDecoder->GetDecoderInfo(&info);
            if(FAILED(hr) || !info)
            {
                decoderInfo = nullptr;
                return hr;
            }

            decoderInfo = gcnew WICNet::IWICBitmapDecoderInfo(info);
            return hr;
        }

        HRESULT IWICBitmapDecoder::CopyPalette(WICNet::IWICPalette ^palette)
        {
            return m_pDecoder->CopyPalette(palette->m_pPalette);
        }

        HRESULT IWICBitmapDecoder::GetPreview(WICNet::IWICBitmapSource ^%bitmapSource)
        {
            ::IWICBitmapSource *source = __nullptr;

            HRESULT hr = m_pDecoder->GetPreview(&source);
            if(FAILED(hr) || !source)
            {
                bitmapSource = nullptr;
                return hr;
            }

            bitmapSource = gcnew WICNet::IWICBitmapSource(source);
            return hr;
        }

        HRESULT IWICBitmapDecoder::GetThumbnail(WICNet::IWICBitmapSource ^%thumbnail)
        {
            ::IWICBitmapSource *source = __nullptr;

            HRESULT hr = m_pDecoder->GetThumbnail(&source);
            if(FAILED(hr) || !source)
            {
                thumbnail = nullptr;
                return hr;
            }

            thumbnail = gcnew WICNet::IWICBitmapSource(source);
            return hr;
        }

        HRESULT IWICBitmapDecoder::GetFrameCount(UINT %count)
        {
            UINT cnt = 0;
            HRESULT hr = m_pDecoder->GetFrameCount(&cnt);

            count = cnt;
            return hr;
        }

        System::ValueTuple<HRESULT, UINT> IWICBitmapDecoder::GetFrameCount()
        {
            UINT cnt = 0;
            HRESULT hr = m_pDecoder->GetFrameCount(&cnt);

            return System::ValueTuple<HRESULT, UINT>(hr, cnt);
        }

        HRESULT IWICBitmapDecoder::GetFrame(UINT index, WICNet::IWICBitmapFrameDecode ^%bitmapFrame)
        {
            ::IWICBitmapFrameDecode *frame = __nullptr;

            HRESULT hr = m_pDecoder->GetFrame(index, &frame);
            if(FAILED(hr) || !frame)
            {
                bitmapFrame = nullptr;
                return hr;
            }

            bitmapFrame = gcnew WICNet::IWICBitmapFrameDecode(frame);
            return hr;
        }

    }
}