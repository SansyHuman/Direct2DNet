#include "D2DImageLoader.h"

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
        PCWSTR nativePath = context.marshal_as<const wchar_t *>(filePath);
        Direct2DNet::ID2D1Bitmap ^bitmap = gcnew Direct2DNet::ID2D1Bitmap(renderTarget->m_factory);

        HRESULT hr = S_OK;
        pin_ptr<::ID2D1Resource *> ppBitmapResource = &bitmap->m_pResource;
        hr = LoadFromFile((::ID2D1RenderTarget *)renderTarget->m_pResource, nativePath, (::ID2D1Bitmap **)ppBitmapResource);
        ppBitmapResource = nullptr;

        if(FAILED(hr))
        {
            if(hr == Direct2DNet::D2DError::E_FILE_NOT_FOUND)
                throw gcnew DxException("The image file does not exists.", hr);
            else
                throw gcnew DxException("Cannot load the image file.", hr);
        }

        bitmap->UpdateBitmapInfo();

        return bitmap;
    }

    HRESULT D2DImageLoader::LoadFromFile(
        ::ID2D1RenderTarget *pRenderTarget, 
        PCWSTR uri,
        ::ID2D1Bitmap **ppBitmap)
    {
        HRESULT hr = S_OK;

        ::IWICBitmapDecoder *pDecoder = __nullptr;
        pin_ptr<::IWICBitmapDecoder *> ppDecoder = &pDecoder;
        hr = m_pFactory->CreateDecoderFromFilename(uri, __nullptr, GENERIC_READ, WICDecodeMetadataCacheOnLoad, (::IWICBitmapDecoder **)ppDecoder);
        ppDecoder = nullptr;

        if(FAILED(hr))
            return hr;

        ::IWICBitmapFrameDecode *pSource = __nullptr;
        pin_ptr<::IWICBitmapFrameDecode *> ppSource = &pSource;
        hr = pDecoder->GetFrame(0, (::IWICBitmapFrameDecode **)ppSource);
        ppSource = nullptr;

        if(FAILED(hr))
            return hr;

        ::IWICFormatConverter *pConverter = __nullptr;
        pin_ptr<::IWICFormatConverter *> ppConverter = &pConverter;
        m_pFactory->CreateFormatConverter((::IWICFormatConverter **)ppConverter);
        ppConverter = nullptr;

        if(FAILED(hr))
            return hr;

        hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, __nullptr, 0.0f, WICBitmapPaletteTypeMedianCut);

        if(FAILED(hr))
            return hr;

        hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, __nullptr, ppBitmap);
        return hr;
    }

}