#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1ImageSource.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICBitmapSource;
    }

    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext2;

        // Done.

        /// <summary>
        /// Produces 2D pixel data that has been sourced from WIC.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("77395441-1c8f-4555-8683-f50dab0fe792")]
        public ref class ID2D1ImageSourceFromWic : Direct2DNet::ID2D1ImageSource
        {
        internal:
            D2DNet::WICNet::IWICBitmapSource ^m_source;

            ID2D1ImageSourceFromWic() : Direct2DNet::ID2D1ImageSource() {}

        public:
            ID2D1ImageSourceFromWic(
                Direct2DNet::ID2D1DeviceContext2 ^context,
                D2DNet::WICNet::IWICBitmapSource ^wicBitmapSource,
                Direct2DNet::D2D1_IMAGE_SOURCE_LOADING_OPTIONS loadingOptions,
                Direct2DNet::D2D1_ALPHA_MODE alphaMode
            );

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Ensures that a specified region of the image source cache is populated. This method can be
            /// used to minimize glitches by performing expensive work to populate caches outside of a
            /// rendering loop. This method can also be used to speculatively load image data before it
            /// is needed by drawing routines.
            /// </summary>
            /// <param name="rectangleToFill">
            /// The optional region of the image, in pixels, that should be populated in the cache.
            /// By default, this is the entire extent of the image. The default value is null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT EnsureCached(
                [OptionalAttribute] System::Nullable<D2D1_RECT_U> rectangleToFill
            );

            /// <summary>
            /// This method trims the populated regions of the image source cache to just the
            /// specified rectangle.
            /// </summary>
            /// <param name="rectangleToPreserve">
            /// The optional region of the image, in pixels, which should be preserved in the image source
            /// cache. Regions which are outside of the rectangle are evicted from the cache. By default,
            /// this is an empty rectangle, meaning that the entire image is evicted from the cache.
            /// The default value is null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT TrimCache(
                [OptionalAttribute] System::Nullable<D2D1_RECT_U> rectangleToPreserve
            );

            /// <summary>
            /// Gets the underlying bitmap image source from the Windows Imaging Component (WIC).
            /// </summary>
            property D2DNet::WICNet::IWICBitmapSource ^Source
            {
                D2DNet::WICNet::IWICBitmapSource ^get();
            }
        };
    }
}