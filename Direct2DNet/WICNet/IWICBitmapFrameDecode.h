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
        ref class IWICMetadataQueryReader;
        ref class IWICColorContext;

        // Done.

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
            /// <summary>
            /// Retrieves a metadata query reader for the frame.
            /// </summary>
            /// <param name="metadataQueryReader">
            /// A parameter that receives the frame's metadata query reader(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetMetadataQueryReader(
                [OutAttribute] WICNet::IWICMetadataQueryReader ^%metadataQueryReader
            );

            /// <summary>
            /// Retrieves the <see cref="WICNet::IWICColorContext"/> associated with the image frame.
            /// </summary>
            /// <param name="colorContexts">
            /// An array that receives the <see cref="WICNet::IWICColorContext"/> objects.
            /// </param>
            /// <param name="cActualCount">
            /// A parameter that receives the number of color contexts contained in the image frame.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            /// <remarks>
            /// If null is passed for colorContexts, this method will return the total number of color
            /// contexts in the image in cActualCount.
            /// </remarks>
            HRESULT GetColorContexts(
                array<WICNet::IWICColorContext ^> ^colorContexts,
                UINT %cActualCount
            );

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