#include "IWICFormatConverter.h"
#include "IWICImagingFactory.h"
#include "IWICPalette.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace WICNet
    {
        IWICFormatConverter::IWICFormatConverter(WICNet::IWICImagingFactory ^factory)
            : WICNet::IWICBitmapSource()
        {
            HRESULT hr = S_OK;
            pin_ptr<::IWICBitmapSource *> ppSource = &m_pSource;
            hr = factory->m_pFactory->CreateFormatConverter((::IWICFormatConverter **)ppSource);
            ppSource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICFormatConverter", (int)hr);
        }

        HRESULT IWICFormatConverter::Initialize(
            WICNet::IWICBitmapSource ^source,
            System::Guid %dstFormat,
            WICNet::WICBitmapDitherType dither,
            double alphaThresholdPercent,
            WICNet::WICBitmapPaletteType paletteTranslate,
            WICNet::IWICPalette ^palette)
        {
            return ((::IWICFormatConverter *)m_pSource)->Initialize(
                source->m_pSource,
                DirectX::ToNativeGUID(dstFormat),
                (::WICBitmapDitherType)((DWORD)dither),
                palette ? palette->m_pPalette : __nullptr,
                alphaThresholdPercent,
                (::WICBitmapPaletteType)((DWORD)paletteTranslate)
            );
        }

        HRESULT IWICFormatConverter::CanConvert(
            System::Guid %srcPixelFormat,
            System::Guid %dstPixelFormat,
            bool %canConvert)
        {
            BOOL conv = FALSE;
            HRESULT hr = ((::IWICFormatConverter *)m_pSource)->CanConvert(
                DirectX::ToNativeGUID(srcPixelFormat),
                DirectX::ToNativeGUID(dstPixelFormat),
                &conv
            );

            canConvert = System::Convert::ToBoolean(conv);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICFormatConverter::CanConvert(
            System::Guid %srcPixelFormat,
            System::Guid %dstPixelFormat)
        {
            BOOL conv = FALSE;
            HRESULT hr = ((::IWICFormatConverter *)m_pSource)->CanConvert(
                DirectX::ToNativeGUID(srcPixelFormat),
                DirectX::ToNativeGUID(dstPixelFormat),
                &conv
            );

            return System::ValueTuple<HRESULT, bool>(
                hr,
                System::Convert::ToBoolean(conv)
                );
        }

    }
}