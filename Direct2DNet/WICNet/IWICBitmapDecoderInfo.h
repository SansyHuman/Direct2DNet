#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "IWICBitmapCodecInfo.h"

using namespace msclr::interop;

namespace D2DNet
{
    namespace ComIO
    {
        ref class IStream;
    }

    namespace WICNet
    {
        ref class IWICBitmapDecoder;

        // Done.

        /// <summary>
        /// Exposes methods that provide information about a particular codec.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("D8CD007F-D08F-4191-9BFC-236EA7F0E4B5")]
        public ref class IWICBitmapDecoderInfo : WICNet::IWICBitmapCodecInfo
        {
        internal:
            IWICBitmapDecoderInfo() : WICNet::IWICBitmapCodecInfo() {}

            IWICBitmapDecoderInfo(::IWICBitmapDecoderInfo *pInfo) : WICNet::IWICBitmapCodecInfo(pInfo) {}

        public:
            /// <summary>
            /// Retrieves the file pattern signatures supported by the decoder.
            /// </summary>
            /// <param name="cbSizePatterns">
            /// The byte size of the pPatterns buffer.
            /// </param>
            /// <param name="pPatterns">
            /// A buffer that receives a list of WICBitmapPattern objects supported by the decoder.
            /// This pointer is the start address of the byte array with the size of
            /// <paramref name="cbSizePatterns"/> or the address of memory in native heap allocated by
            /// Marshal::AllocHGlobal or Marshal::AllocCoTaskMem.
            /// </param>
            /// <param name="cPatterns">
            /// Receives the number of patterns the decoder supports(out parameter).
            /// </param>
            /// <param name="cbPatternsActual">
            /// Receives the actual buffer size needed to retrieve all pattern signatures supported by
            /// the decoder(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            /// <remarks>
            /// <para>
            /// To retrieve all pattern signatures, this method should first be called with pPatterns set to
            /// <see cref="System::IntPtr::Zero"/> to retrieve the actual buffer size needed through
            /// cbPatternsActual. Once the needed buffer size is known, allocate a buffer of the needed
            /// size and call GetPatterns again with the allocated buffer.
            /// </para>
            /// <para>
            /// The byte size of the buffer includes the space for pattern and mask data of each
            /// <see cref="WICNet::WICBitmapPattern"/> struct. The first <paramref name="cPatterns"/>
            /// * sizeof(<see cref="WICNet::WICBitmapPattern"/>) byte includes the array of
            /// <see cref="WICNet::WICBitmapPattern"/> struct. The remaining bytes stores pattern and mask
            /// data.
            /// </para>
            /// </remarks>
            HRESULT GetPatterns(
                UINT cbSizePatterns,
                [InAttribute][IsReadOnlyAttribute] System::IntPtr %pPatterns,
                [OutAttribute] UINT %cPatterns,
                [OutAttribute] UINT %cbPatternsActual
            );

            /// <summary>
            /// Retrieves a value that indicates whether the codec recognizes the pattern within a
            /// specified stream.
            /// </summary>
            /// <param name="stream">
            /// The stream to pattern match within.
            /// </param>
            /// <param name="matches">
            /// A parameter that receives true if the patterns match; otherwise, false(out paramter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT MatchesPattern(
                ComIO::IStream ^stream,
                [OutAttribute] bool %matches
            );

            /// <summary>
            /// Retrieves a value that indicates whether the codec recognizes the pattern within a
            /// specified stream.
            /// </summary>
            /// <param name="stream">
            /// The stream to pattern match within.
            /// </param>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is true if the patterns match; otherwise, false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> MatchesPattern(
                ComIO::IStream ^stream
            );

            /// <summary>
            /// Creates a new <see cref="WICNet::IWICBitmapDecoder"/> instance.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the decoder.
            /// </exception>
            WICNet::IWICBitmapDecoder ^CreateInstance();
        };
    }
}