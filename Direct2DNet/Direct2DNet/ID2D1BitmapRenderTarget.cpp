#include "ID2D1BitmapRenderTarget.h"
#include "ID2D1Factory.h"
#include "ID2D1Bitmap.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1BitmapRenderTarget::ID2D1BitmapRenderTarget(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            System::Nullable<Direct2DNet::D2D1_SIZE_F> %desiredSize,
            System::Nullable<Direct2DNet::D2D1_SIZE_U> %desiredPixelSize,
            System::Nullable<Direct2DNet::D2D1_PIXEL_FORMAT> %desiredFormat,
            Direct2DNet::D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options
        ) : Direct2DNet::ID2D1RenderTarget(renderTarget->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateCompatibleRenderTarget(
                desiredSize.HasValue ? &static_cast<::D2D1_SIZE_F>(desiredSize.Value) : __nullptr,
                desiredPixelSize.HasValue ? &static_cast<::D2D1_SIZE_U>(desiredPixelSize.Value) : __nullptr,
                desiredFormat.HasValue ? &static_cast<::D2D1_PIXEL_FORMAT>(desiredFormat.Value) : __nullptr,
                (::D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS)((int)options),
                (::ID2D1BitmapRenderTarget **)ppRenderTarget
            );
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1BitmapRenderTarget", (int)hr);
        }

        System::ValueTuple<HRESULT, Direct2DNet::ID2D1Bitmap ^> ID2D1BitmapRenderTarget::GetBitmap()
        {
            HRESULT hr = S_OK;
            ::ID2D1Bitmap *nativeBitmap = __nullptr;

            hr = ((::ID2D1BitmapRenderTarget *)m_pResource)->GetBitmap(&nativeBitmap);

            if(FAILED(hr) || !nativeBitmap)
                return System::ValueTuple<HRESULT, Direct2DNet::ID2D1Bitmap ^>(hr, nullptr);

            return System::ValueTuple<HRESULT, Direct2DNet::ID2D1Bitmap ^>(
                hr,
                gcnew Direct2DNet::ID2D1Bitmap(m_factory, nativeBitmap)
                );
        }

        HRESULT ID2D1BitmapRenderTarget::GetBitmap(ID2D1Bitmap ^%bitmap)
        {
            HRESULT hr = S_OK;
            ::ID2D1Bitmap *nativeBitmap = __nullptr;

            hr = ((::ID2D1BitmapRenderTarget *)m_pResource)->GetBitmap(&nativeBitmap);

            if(FAILED(hr) || !nativeBitmap)
            {
                bitmap = nullptr;
                return hr;
            }

            bitmap = gcnew Direct2DNet::ID2D1Bitmap(m_factory, nativeBitmap);

            return hr;
        }

    }
}