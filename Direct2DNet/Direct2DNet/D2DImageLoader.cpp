#include "D2DImageLoader.h"

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

        Direct2DNet::ID2D1Bitmap ^D2DImageLoader::LoadBitmapFromFile(Direct2DNet::ID2D1RenderTarget ^renderTarget, System::String ^filePath)
        {
            marshal_context context;

            PCWSTR nativePath = context.marshal_as<const wchar_t *>(filePath);

            HRESULT hr = S_OK;
            ::ID2D1Bitmap *pBitmap = __nullptr;
            hr = LoadFromFile((::ID2D1RenderTarget *)renderTarget->m_pResource, nativePath, &pBitmap);

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

            hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, __nullptr, 0.0f, WICBitmapPaletteTypeMedianCut);

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