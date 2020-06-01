#include "ID2D1Bitmap1.h"
#include "ID2D1DeviceContext.h"
#include "../DXGINet/IDXGISurface.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Bitmap1::ID2D1Bitmap1(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            Direct2DNet::D2D1_SIZE_U %size,
            void *sourceData,
            unsigned int pitch,
            Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties) : Direct2DNet::ID2D1Bitmap(deviceContext)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateBitmap(
                static_cast<::D2D1_SIZE_U>(size),
                sourceData,
                pitch,
                static_cast<::D2D1_BITMAP_PROPERTIES1>(bitmapProperties),
                (::ID2D1Bitmap1 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Bitmap1", (int)hr);

            UpdateBitmapInfo();

            m_colorContext = bitmapProperties.colorContext;

            ::IDXGISurface *pSurface = __nullptr;
            hr = ((::ID2D1Bitmap1 *)m_pResource)->GetSurface(&pSurface);
            if(FAILED(hr) || !pSurface)
                m_dxgiSurface = nullptr;
            else
                m_dxgiSurface = gcnew DXGINet::IDXGISurface(pSurface);

            m_options = bitmapProperties.bitmapOptions;
        }

        ID2D1Bitmap1::ID2D1Bitmap1(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            DXGINet::IDXGISurface ^surface,
            Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties) : Direct2DNet::ID2D1Bitmap(deviceContext)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateBitmapFromDxgiSurface(
                (::IDXGISurface *)surface->m_pSubObject,
                static_cast<::D2D1_BITMAP_PROPERTIES1>(bitmapProperties),
                (::ID2D1Bitmap1 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Bitmap1", (int)hr);

            UpdateBitmapInfo();

            m_colorContext = bitmapProperties.colorContext;
            m_dxgiSurface = surface;
            m_options = bitmapProperties.bitmapOptions;
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_MAPPED_RECT> ID2D1Bitmap1::Map(
            Direct2DNet::D2D1_MAP_OPTIONS options)
        {
            ::D2D1_MAPPED_RECT rect;

            HRESULT hr = ((::ID2D1Bitmap1 *)m_pResource)->Map((::D2D1_MAP_OPTIONS)((int)options), &rect);

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_MAPPED_RECT>(
                hr,
                static_cast<Direct2DNet::D2D1_MAPPED_RECT>(rect)
                );
        }

        HRESULT ID2D1Bitmap1::Map(
            Direct2DNet::D2D1_MAP_OPTIONS options,
            Direct2DNet::D2D1_MAPPED_RECT %mappedRect)
        {
            ::D2D1_MAPPED_RECT rect;

            HRESULT hr = ((::ID2D1Bitmap1 *)m_pResource)->Map((::D2D1_MAP_OPTIONS)((int)options), &rect);
            mappedRect = static_cast<Direct2DNet::D2D1_MAPPED_RECT>(rect);

            return hr;
        }

        HRESULT ID2D1Bitmap1::Unmap()
        {
            return ((::ID2D1Bitmap1 *)m_pResource)->Unmap();
        }

    }
}