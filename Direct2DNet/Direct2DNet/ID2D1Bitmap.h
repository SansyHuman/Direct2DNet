#pragma once

#include "../IUnknown.h"
#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Image.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGISurface;
    }

    namespace WICNet
    {
        ref class IWICBitmapSource;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Factory;
        ref class ID2D1RenderTarget;
        ref class ID2D1DeviceContext;

        /// <summary>
        /// Root bitmap resource, linearly scaled on a draw call.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("a2296057-ea42-4099-983b-539fb6505426")]
        public ref class ID2D1Bitmap : Direct2DNet::ID2D1Image
        {
        private:
            Direct2DNet::D2D1_SIZE_F m_size;
            Direct2DNet::D2D1_SIZE_U m_pixelSize;
            Direct2DNet::D2D1_PIXEL_FORMAT m_pixelFormat;
            float m_dpiX;
            float m_dpiY;

        internal:
            ID2D1Bitmap() : Direct2DNet::ID2D1Image() {}

            ID2D1Bitmap(Direct2DNet::ID2D1Factory ^factory, ::ID2D1Bitmap *pBitmap);

            ID2D1Bitmap(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                Direct2DNet::D2D1_SIZE_U %size,
                Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
            );

            ID2D1Bitmap(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                Direct2DNet::D2D1_SIZE_U %size,
                void *srcData,
                unsigned int pitch,
                Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
            );

            ID2D1Bitmap(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                System::Guid %guid,
                D2DNet::IUnknown ^data,
                Direct2DNet::D2D1_BITMAP_PROPERTIES %bitmapProperties
            );

            ID2D1Bitmap(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                WICNet::IWICBitmapSource ^wicBitmapSource,
                System::Nullable<Direct2DNet::D2D1_BITMAP_PROPERTIES> %bitmapProperties
            );

        protected:
            ID2D1Bitmap(
                Direct2DNet::ID2D1DeviceContext ^deviceContext
            );

            // Called after loading native ID2D1Bitmap object.
            void UpdateBitmapInfo();

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Gets the size of the bitmap in resolution independent units.
            /// </summary>
            property Direct2DNet::D2D1_SIZE_F Size
            {
                Direct2DNet::D2D1_SIZE_F get()
                {
                    return m_size;
                }
            }

            /// <summary>
            /// Gets the size of the bitmap in resolution dependent units, (pixels).
            /// </summary>
            property Direct2DNet::D2D1_SIZE_U PixelSize
            {
                Direct2DNet::D2D1_SIZE_U get()
                {
                    return m_pixelSize;
                }
            }

            /// <summary>
            /// Gets the format of the bitmap.
            /// </summary>
            property Direct2DNet::D2D1_PIXEL_FORMAT PixelFormat
            {
                Direct2DNet::D2D1_PIXEL_FORMAT get()
                {
                    return m_pixelFormat;
                }
            }

            /// <summary>
            /// Gets the DPI of the bitmap. The tuple is (dpiX, dpiY).
            /// </summary>
            property System::ValueTuple<float, float> Dpi
            {
                System::ValueTuple<float, float> get()
                {
                    return System::ValueTuple<float, float>(m_dpiX, m_dpiY);
                }
            }

            /// <summary>
            /// Gets the x-axis DPI of the bitmap.
            /// </summary>
            property float DpiX
            {
                float get()
                {
                    return m_dpiX;
                }
            }

            /// <summary>
            /// Gets the y-axis DPI of the bitmap.
            /// </summary>
            property float  DpiY
            {
                float get()
                {
                    return m_dpiY;
                }
            }

            /// <summary>
            /// Copies the specified region from the specified bitmap into the current bitmap.
            /// </summary>
            /// <param name="destPoint">In the current bitmap, the upper-left corner of the area to which
            /// the region specified by srcRect is copied.</param>
            /// <param name="srcRect">The area of bitmap to copy.</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT CopyFromBitmap(
                Direct2DNet::ID2D1Bitmap ^bitmap,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_POINT_2U> destPoint,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_U> srcRect
            );

            /// <summary>
            /// Copies the specified region from the specified render target into the current bitmap.
            /// </summary>
            /// <param name="destPoint">In the current bitmap, the upper-left corner of the area to which
            /// the region specified by srcRect is copied.</param>
            /// <param name="srcRect">The area of render target to copy.</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT CopyFromRenderTarget(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_POINT_2U> destPoint,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_U> srcRect
            );

            /// <summary>
            /// Copies the specified region from memory into the current bitmap.
            /// </summary>
            /// <param name="pitch">The stride, or pitch, of the source bitmap stored in srcData.
            /// The stride is the byte count of a scanline (one row of pixels in memory).
            /// The stride can be computed from the following formula:
            /// pixel width * bytes per pixel + memory padding.</param>
            /// <param name="dstRect">In the current bitmap, the rectangle to which the region specified
            /// by srcRect is copied.</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT CopyFromMemory(
                void *srcData,
                unsigned int pitch,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_RECT_U> dstRect
            );
        };
    }
}