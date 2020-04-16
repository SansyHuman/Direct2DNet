#pragma once

#include <msclr/marshal.h>

#include "D2DNetHeaders.h"
#include "ID2D1RenderTarget.h"
#include "ID2D1Bitmap.h"
#include "D2DError.h"
#include "Exception/DXException.h"

using namespace Direct2DNet::Exception;
using namespace msclr::interop;

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

        marshal_context context;

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
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when the file does not exists or the image cannot be loaded properly.
        /// </exception>
        Direct2DNet::ID2D1Bitmap ^LoadBitmapFromFile(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            System::String ^filePath
        );

    private:
        HRESULT LoadFromFile(
            ::ID2D1RenderTarget *pRenderTarget,
            PCWSTR uri,
            ::ID2D1Bitmap **ppBitmap
        );
    };
}