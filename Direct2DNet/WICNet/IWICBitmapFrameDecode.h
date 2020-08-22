#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "IWICBitmapSource.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {
        /// <summary>
        /// Defines methods for decoding individual image frames of an encoded file.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("3B16811B-6A43-4ec9-A813-3D930C13B940")]
        public ref class IWICBitmapFrameDecode : WICNet::IWICBitmapSource
        {
        internal:
            IWICBitmapFrameDecode() : WICNet::IWICBitmapSource() {}

            IWICBitmapFrameDecode(::IWICBitmapFrameDecode *pDecode) : WICNet::IWICBitmapSource(pDecode) {}

        public:
            // GetMetadataQueryReader

            // GetColorContexts

            /// <summary>
            /// Retrieves a small preview of the frame, if supported by the codec.
            /// </summary>
            /// <param name="thumbnail">
            /// A parameter that receives the IWICBitmapSource of the thumbnail(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetThumbnail(
                [OutAttribute] WICNet::IWICBitmapSource ^%thumbnail
            );
        };
    }
}