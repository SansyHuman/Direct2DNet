#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "../Direct2DNet/Exception/DXException.h"

namespace D2DNet
{
    namespace ComIO
    {
        ref class IStream;
    }

    namespace WICNet
    {
        ref class IWICImagingFactory;
        ref class IWICBitmapSource;
        ref class IWICBitmapFrameDecode;
        ref class IWICBitmapDecoderInfo;
        ref class IWICPalette;
        ref class IWICMetadataQueryReader;
        ref class IWICColorContext;

        // Done.

        /// <summary>
        /// Exposes methods that represent a decoder. The interface provides access to the decoder's
        /// properties such as global thumbnails (if supported), frames, and palette.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("9EDDE9E7-8DEE-47ea-99DF-E6FAF2ED44BF")]
        public ref class IWICBitmapDecoder : WICNet::IWICObject
        {
        internal:
            ::IWICBitmapDecoder *m_pDecoder;

            IWICBitmapDecoder() : m_pDecoder(nullptr) {}

            // CreateDecoderFromFileName
            IWICBitmapDecoder(
                WICNet::IWICImagingFactory ^factory,
                System::String ^filename,
                WICNet::Access desiredAccess,
                WICNet::WICDecodeOptions metadataOptions,
                System::Nullable<System::Guid> %guidVendor
            );

            // CreateDecoderFromStream
            IWICBitmapDecoder(
                WICNet::IWICImagingFactory ^factory,
                ComIO::IStream ^stream,
                WICNet::WICDecodeOptions metadataOptions,
                System::Nullable<System::Guid> %guidVendor
            );

            // CreateDecoderFromFileHandle
            IWICBitmapDecoder(
                WICNet::IWICImagingFactory ^factory,
                Microsoft::Win32::SafeHandles::SafeFileHandle ^hFile,
                WICNet::WICDecodeOptions metadataOptions,
                System::Nullable<System::Guid> %guidVendor
            );

            // CreateDecoder
            IWICBitmapDecoder(
                WICNet::IWICImagingFactory ^factory,
                System::Guid %guidContainerFormat,
                System::Nullable<System::Guid> %guidVendor
            );

            // CreateInstance
            IWICBitmapDecoder(
                WICNet::IWICBitmapDecoderInfo ^info
            );

        public:
            ~IWICBitmapDecoder();
            !IWICBitmapDecoder();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pDecoder;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Retrieves the capabilities of the decoder based on the specified stream.
            /// </summary>
            /// <param name="stream">
            /// The stream to retrieve the decoder capabilities from.
            /// </param>
            /// <param name="capability">
            /// The <see cref="WICNet::WICBitmapDecoderCapabilities"/> of the decoder.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT QueryCapability(
                ComIO::IStream ^stream,
                [OutAttribute] WICNet::WICBitmapDecoderCapabilities %capability
            );

            /// <summary>
            /// Retrieves the capabilities of the decoder based on the specified stream.
            /// </summary>
            /// <param name="stream">
            /// The stream to retrieve the decoder capabilities from.
            /// </param>
            /// <returns>
            /// (HRESULT, <see cref="WICNet::WICBitmapDecoderCapabilities"/>) tuple. If this method succeeds,
            /// HRESULT is S_OK. Otherwise, it is an HRESULT error code.
            /// <see cref="WICNet::WICBitmapDecoderCapabilities"/> is the capabilities of the decoder.
            /// </returns>
            System::ValueTuple<HRESULT, WICNet::WICBitmapDecoderCapabilities> QueryCapability(
                ComIO::IStream ^stream
            );

            /// <summary>
            /// Initializes the decoder with the provided stream.
            /// </summary>
            /// <param name="stream">
            /// The stream to use for initialization.
            /// </param>
            /// <param name="cacheOptions">
            /// The <see cref="WICNet::WICDecodeOptions"/> to use for initialization.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT Initialize(
                ComIO::IStream ^stream,
                WICNet::WICDecodeOptions cacheOptions
            );

            /// <summary>
            /// Retrieves the image's container format.
            /// </summary>
            /// <param name="guidContainerFormat">
            /// A parameter that receives the image's container format GUID(out parameter).
            /// The built-in format GUIDs are defined in <see cref="WICNet::ContainerFormatGUID"/> class.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetContainerFormat(
                [OutAttribute] System::Guid %guidContainerFormat
            );

            /// <summary>
            /// Retrieves an <see cref="WICNet::IWICBitmapDecoderInfo"/> for the image.
            /// </summary>
            /// <param name="decoderInfo">
            /// A parameter that receives an <see cref="WICNet::IWICBitmapDecoderInfo"/>.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetDecoderInfo(
                [OutAttribute] WICNet::IWICBitmapDecoderInfo ^%decoderInfo
            );

            /// <summary>
            /// Copies the decoder's <see cref="WICNet::IWICPalette"/>.
            /// </summary>
            /// <param name="palette">
            /// An <see cref="WICNet::IWICPalette"/> to which the decoder's global palette is to be copied.
            /// Use <see cref="WICNet::IWICImagingFactory::CreatePalette"/> to create the destination
            /// palette before calling CopyPalette.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT CopyPalette(
                WICNet::IWICPalette ^palette
            );

            /// <summary>
            /// Retrieves the metadata query reader from the decoder.
            /// </summary>
            /// <param name="metadataQueryReader">
            /// A parameter that receives the decoder's <see cref="WICNet::IWICMetadataQueryReader"/>.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetMetadataQueryReader(
                [OutAttribute] WICNet::IWICMetadataQueryReader ^%metadataQueryReader
            );

            /// <summary>
            /// Retrieves a preview image, if supported.
            /// </summary>
            /// <param name="bitmapSource">
            /// Receives the preview bitmap if supported(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetPreview(
                [OutAttribute] WICNet::IWICBitmapSource ^%bitmapSource
            );

            /// <summary>
            /// Retrieves the <see cref="WICNet::IWICColorContext"/> objects of the image.
            /// </summary>
            /// <param name="colorContexts">
            /// An array that receives the <see cref="WICNet::IWICColorContext"/> objects.
            /// </param>
            /// <param name="cActualCount">
            /// A parameter that receives the number of color contexts contained in the image.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetColorContexts(
                array<WICNet::IWICColorContext ^> ^colorContexts,
                UINT %cActualCount
            );

            /// <summary>
            /// Retrieves a bitmap thumbnail of the image, if one exists
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

            /// <summary>
            /// Retrieves the total number of frames in the image.
            /// </summary>
            /// <param name="count">
            /// A parameter that receives the total number of frames in the image(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetFrameCount(
                [OutAttribute] UINT %count
            );

            /// <summary>
            /// Retrieves the total number of frames in the image.
            /// </summary>
            /// <returns>
            /// (HRESULT, uint) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. uint is the total number of frames in the image.
            /// </returns>
            System::ValueTuple<HRESULT, UINT> GetFrameCount();

            /// <summary>
            /// Retrieves the specified frame of the image.
            /// </summary>
            /// <param name="index">
            /// The particular frame to retrieve.
            /// </param>
            /// <param name="bitmapFrame">
            /// A parameter that receives the IWICBitmapFrameDecode(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetFrame(
                UINT index,
                [OutAttribute] WICNet::IWICBitmapFrameDecode ^%bitmapFrame
            );
        };
    }
}