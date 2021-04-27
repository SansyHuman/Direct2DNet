#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICPalette;

        // Done.

        /// <summary>
        /// Exposes methods that refers to a source from which pixels are retrieved, but cannot be written
        /// back to.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("00000120-a8f2-4877-ba0a-fd2b6645fb94")]
        public ref class IWICBitmapSource : WICNet::IWICObject
        {
        internal:
            ::IWICBitmapSource *m_pSource;

            IWICBitmapSource() : m_pSource(nullptr) {}

            IWICBitmapSource(::IWICBitmapSource *pSource) : m_pSource(pSource) {}

        public:
            ~IWICBitmapSource();
            !IWICBitmapSource();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pSource;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Retrieves the pixel width and height of the bitmap.
            /// </summary>
            /// <param name="width">
            /// A parameter that receives the pixel width of the bitmap(out parameter).
            /// </param>
            /// <param name="height">
            /// A parameter that receives the pixel height of the bitmap(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetSize(
                [OutAttribute] UINT %width,
                [OutAttribute] UINT %height
            );

            /// <summary>
            /// Retrieves the pixel width and height of the bitmap.
            /// </summary>
            /// <returns>
            /// (HRESULT, uint, uint) tuple.  If this method succeeds, HRESULT is S_OK. Otherwise, it is
            /// an HRESULT error code. First uint is the pixel width of the bitmap. Second uint is the pixel
            /// height of the bitmap.
            /// </returns>
            System::ValueTuple<HRESULT, UINT, UINT> GetSize();

            /// <summary>
            /// Retrieves the pixel format of the bitmap source.
            /// </summary>
            /// <param name="pixelFormat">
            /// Receives the pixel format GUID the bitmap is stored in(out parameter). For a list of
            /// available pixel formats, see <see cref="WICNet::PixelFormatGUID"/> class.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetPixelFormat(
                [OutAttribute] System::Guid %pixelFormat
            );

            /// <summary>
            /// Retrieves the sampling rate between pixels and physical world measurements.
            /// </summary>
            /// <param name="dpiX">
            /// A parameter that receives the x-axis dpi resolution(out parameter).
            /// </param>
            /// <param name="dpiY">
            /// A parameter that receives the y-axis dpi resolution(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetResolution(
                [OutAttribute] double %dpiX,
                [OutAttribute] double %dpiY
            );

            /// <summary>
            /// Retrieves the sampling rate between pixels and physical world measurements.
            /// </summary>
            /// <returns>
            /// (HRESULT, double, double) tuple.  If this method succeeds, HRESULT is S_OK. Otherwise, it is
            /// an HRESULT error code. First double is the x-axis dpi resolution. Second double is the y-axis
            /// dpi resolution.
            /// </returns>
            System::ValueTuple<HRESULT, double, double> GetResolution();

            /// <summary>
            /// Retrieves the color table for indexed pixel formats.
            /// </summary>
            /// <param name="palette">
            /// An <see cref="WICNet::IWICPalette"/>. A palette can be created using the
            /// <see cref="WICNet::IWICImagingFactory::CreatePalette"/> method.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT CopyPalette(
                WICNet::IWICPalette ^palette
            );

            /// <summary>
            /// Instructs the object to produce pixels.
            /// </summary>
            /// <param name="cbStride">
            /// The stride of the bitmap in bytes.
            /// </param>
            /// <param name="buffer">
            /// A buffer to receive pixel data.
            /// </param>
            /// <param name="rc">
            /// An optional rectangle to copy. A null value specifies the entire bitmap. The default value is
            /// null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT CopyPixels(
                UINT cbStride,
                array<BYTE> ^buffer,
                [OptionalAttribute] System::Nullable<WICNet::WICRect> rc
            );
        };
    }
}