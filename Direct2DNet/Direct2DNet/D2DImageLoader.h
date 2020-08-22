#pragma once

#include <msclr/marshal.h>

#include "D2DNetHeaders.h"
#include "ID2D1RenderTarget.h"
#include "ID2D1Bitmap.h"
#include "D2DError.h"
#include "Exception/DXException.h"
#include "../WICNet/WICSettings.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace D2DNet::Direct2DNet::Exception;
using namespace msclr::interop;

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICPalette;
    }

    namespace Direct2DNet
    {
        /// <summary>
        /// Class used to load bitmap image from files. Internally uses WIC.
        /// In the future release, D2DNet will implement WIC wrapper classes.
        /// </summary>
        public ref class D2DImageLoader sealed
        {
        private:
            ::IWICImagingFactory *m_pFactory;

        public:
            /// <summary>
            /// Creates the image loader.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when necessary WIC components cannot be created.
            /// </exception>
            D2DImageLoader();
            ~D2DImageLoader();
            !D2DImageLoader();

            /// <summary>
            /// Loads the bitmap from the file and returns <see cref="Direct2DNet::ID2D1Bitmap"/> instance.
            /// </summary>
            /// <param name="renderTarget">
            /// Render target to use when loading bitmap.
            /// </param>
            /// <param name="filePath">
            /// Path of the bitmap file to load.
            /// </param>
            /// <param name="format">
            /// The pixel format GUID. The list of built-in format GUIDs are in
            /// <see cref="WICNet::PixelFormatGUID"/> class. The default value is
            /// <see cref="WICNet::PixelFormatGUID::Format32bppPBGRA"/>.
            /// </param>
            /// <param name="dither">
            /// The <see cref="WICNet::WICBitmapDitherType"/> used for conversion. The default value is
            /// <see cref="WICNet::WICBitmapDitherType::None"/>.
            /// </param>
            /// <param name="alphaThresholdPercent">
            /// The alpha threshold to use for conversion. The default value is 0.
            /// </param>
            /// <param name="paletteTranslate">
            /// The palette translation type to use for conversion. The default value is
            /// <see cref="WICNet::WICBitmapPaletteType::Custom"/>.
            /// </param>
            /// <param name="palette">
            /// The optional palette to use for conversion. The default value is null.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when the file does not exists or the image cannot be loaded properly.
            /// </exception>
            Direct2DNet::ID2D1Bitmap ^LoadBitmapFromFile(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                System::String ^filePath,
                [OptionalAttribute] System::Nullable<System::Guid> format,
                [OptionalAttribute] System::Nullable<WICNet::WICBitmapDitherType> dither,
                [OptionalAttribute] System::Nullable<double> alphaThresholdPercent,
                [OptionalAttribute] System::Nullable<WICNet::WICBitmapPaletteType> paletteTranslate,
                [OptionalAttribute] WICNet::IWICPalette ^palette
            );

        private:
            HRESULT LoadFromFile(
                ::ID2D1RenderTarget *pRenderTarget,
                PCWSTR uri,
                GUID %format,
                ::WICBitmapDitherType dither,
                double alphaThresholdPercent,
                ::WICBitmapPaletteType paletteTranslate,
                ::IWICPalette *pPalette,
                ::ID2D1Bitmap **ppBitmap
            );
        };
    }
}