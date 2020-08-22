#include "D2DImageLoader.h"
#include "../DXCommonSettings.h"
#include "../WICNet/IWICPalette.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        D2DImageLoader::D2DImageLoader()
        {
            HRESULT hr = S_OK;

            pin_ptr<::IWICImagingFactory *> ppFactory = &m_pFactory;
            hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS((::IWICImagingFactory **)ppFactory));
            ppFactory = nullptr;

            if(FAILED(hr))
                throw gcnew DxException("Failed to create IWICImagingFactory.", hr);
        }

        D2DImageLoader::~D2DImageLoader()
        {
            this->!D2DImageLoader();
        }

        D2DImageLoader::!D2DImageLoader()
        {
            if(m_pFactory)
            {
                m_pFactory->Release();
                m_pFactory = nullptr;
            }
        }

        Direct2DNet::ID2D1Bitmap ^D2DImageLoader::LoadBitmapFromFile(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            System::String ^filePath,
            System::Nullable<System::Guid> format,
            System::Nullable<WICNet::WICBitmapDitherType> dither,
            System::Nullable<double> alphaThresholdPercent,
            System::Nullable<WICNet::WICBitmapPaletteType> paletteTranslate,
            WICNet::IWICPalette ^palette
        )
        {
            if(!format.HasValue)
                format = WICNet::PixelFormatGUID::Format32bppPBGRA;
            
            if(!dither.HasValue)
                dither = WICNet::WICBitmapDitherType::None;

            if(!alphaThresholdPercent.HasValue)
                alphaThresholdPercent = 0;

            if(!paletteTranslate.HasValue)
                paletteTranslate = WICNet::WICBitmapPaletteType::Custom;

            marshal_context context;

            PCWSTR nativePath = context.marshal_as<const wchar_t *>(filePath);

            HRESULT hr = S_OK;
            ::ID2D1Bitmap *pBitmap = __nullptr;
            hr = LoadFromFile(
                (::ID2D1RenderTarget *)renderTarget->m_pResource,
                nativePath,
                DirectX::ToNativeGUID(format.Value),
                (::WICBitmapDitherType)((DWORD)dither.Value),
                alphaThresholdPercent.Value,
                (::WICBitmapPaletteType)((DWORD)paletteTranslate.Value),
                palette ? palette->m_pPalette : __nullptr,
                &pBitmap);

            if(FAILED(hr))
            {
                if(hr == Direct2DNet::D2DError::E_FILE_NOT_FOUND)
                    throw gcnew DxException("The image file does not exists.", hr);
                else
                    throw gcnew DxException("Cannot load the image file.", hr);
            }

            return gcnew Direct2DNet::ID2D1Bitmap(renderTarget->m_factory, pBitmap);
        }

        HRESULT D2DImageLoader::LoadFromFile(
            ::ID2D1RenderTarget *pRenderTarget,
            PCWSTR uri,
            GUID %format,
            ::WICBitmapDitherType dither,
            double alphaThresholdPercent,
            ::WICBitmapPaletteType paletteTranslate,
            ::IWICPalette *pPalette,
            ::ID2D1Bitmap **ppBitmap)
        {
            HRESULT hr = S_OK;

            ::IWICBitmapDecoder *pDecoder = __nullptr;
            ::IWICBitmapFrameDecode *pSource = __nullptr;
            ::IWICFormatConverter *pConverter = __nullptr;

            hr = m_pFactory->CreateDecoderFromFilename(uri, __nullptr, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);

            if(FAILED(hr))
                goto RES_REL;

            hr = pDecoder->GetFrame(0, &pSource);

            if(FAILED(hr))
                goto RES_REL;

            pin_ptr<::IWICFormatConverter *> ppConverter = &pConverter;
            m_pFactory->CreateFormatConverter((::IWICFormatConverter **)ppConverter);
            ppConverter = nullptr;

            if(FAILED(hr))
                goto RES_REL;

            hr = pConverter->Initialize(
                pSource,
                format,
                dither,
                pPalette,
                alphaThresholdPercent,
                paletteTranslate);

            if(FAILED(hr))
                goto RES_REL;

            hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, __nullptr, ppBitmap);

        RES_REL:
            if(pDecoder)
                pDecoder->Release();
            if(pSource)
                pSource->Release();
            if(pConverter)
                pConverter->Release();

            return hr;
        }

    }
}