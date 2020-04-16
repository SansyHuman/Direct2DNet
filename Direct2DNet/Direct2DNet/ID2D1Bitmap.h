#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Image.h"

namespace Direct2DNet
{
    ref class ID2D1Factory;
    ref class ID2D1RenderTarget;

    /// <summary>
    /// Root bitmap resource, linearly scaled on a draw call.
    /// </summary>
    [System::Runtime::InteropServices::GuidAttribute("642C965A-0A09-4280-88EC-5C6F999DE7E0")]
    public ref class ID2D1Bitmap : Direct2DNet::ID2D1Image
    {
    private:
        Direct2DNet::D2D1_SIZE_F m_size;
        Direct2DNet::D2D1_SIZE_U m_pixelSize;
        Direct2DNet::D2D1_PIXEL_FORMAT m_pixelFormat;
        float m_dpiX;
        float m_dpiY;

    internal:
        // Only used in D2DImageLoader.
        ID2D1Bitmap(ID2D1Factory ^factory);
        // Only used in D2DImageLoader. Called after loading native ID2D1Bitmap object.
        void UpdateBitmapInfo();

    public:
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

        HRESULT CopyFromBitmap(
            Direct2DNet::D2D1_POINT_2U destPoint,
            Direct2DNet::ID2D1Bitmap ^bitmap,
            Direct2DNet::D2D1_RECT_U srcRect
        );

        HRESULT CopyFromRenderTarget(
            Direct2DNet::D2D1_POINT_2U destPoint,
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::D2D1_RECT_U srcRect
        );

        HRESULT CopyFromMemory(
            Direct2DNet::D2D1_RECT_U dstRect,
            void *srcData,
            unsigned int pitch
        );
    };
}