#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "../Direct2DNet/Exception/DXException.h"
#include "../DXCommonSettings.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace ComIO
    {
        ref class Stream;
    }

    namespace WICNet
    {
        ref class IWICBitmapDecoder;
        ref class IWICPalette;
        ref class IWICFormatConverter;

        /// <summary>
        /// Exposes methods used to create components for the Windows Imaging Component (WIC) such as
        /// decoders, encoders and pixel format converters.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("ec5ec8a9-c395-4314-9c77-54d7a935ff70")]
        public ref class IWICImagingFactory : WICNet::IWICObject
        {
        internal:
            ::IWICImagingFactory *m_pFactory;

            IWICImagingFactory() : m_pFactory(nullptr) {}

        public:
            IWICImagingFactory(D2DNet::CLSCTX clsContext);

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pFactory;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Creates a new instance of the <see cref="WICNet::IWICBitmapDecoder"/> class based on the
            /// given file.
            /// </summary>
            /// <param name="filename">
            /// A string that specifies the name of an object to create or open.
            /// </param>
            /// <param name="desiredAccess">
            /// The access to the object, which can be read, write, or both.
            /// </param>
            /// <param name="metadataOptions">
            /// The <see cref="WICNet::WICDecodeOptions"/> to use when creating the decoder.
            /// </param>
            /// <param name="guidVendor">
            /// The optional GUID for the preferred decoder vendor. Use null if no preferred vendor.
            /// Use one of the GUIDs in <see cref="WICNet::VendorGUID"/> class. The default value is null.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the decoder.
            /// </exception>
            WICNet::IWICBitmapDecoder ^CreateDecoderFromFilename(
                System::String ^filename,
                WICNet::Access desiredAccess,
                WICNet::WICDecodeOptions metadataOptions,
                [OptionalAttribute] System::Nullable<System::Guid> guidVendor
            );

            /// <summary>
            /// Creates a new instance of the <see cref="WICNet::IWICBitmapDecoder"/> class based on the
            /// given Stream.
            /// </summary>
            /// <param name="stream">
            /// The stream to create the decoder from.
            /// </param>
            /// <param name="metadataOptions">
            /// The <see cref="WICNet::WICDecodeOptions"/> to use when creating the decoder.
            /// </param>
            /// <param name="guidVendor">
            /// The optional GUID for the preferred decoder vendor. Use null if no preferred vendor.
            /// Use one of the GUIDs in <see cref="WICNet::VendorGUID"/> class. The default value is null.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the decoder.
            /// </exception>
            WICNet::IWICBitmapDecoder ^CreateDecoderFromStream(
                ComIO::Stream ^stream,
                WICNet::WICDecodeOptions metadataOptions,
                [OptionalAttribute] System::Nullable<System::Guid> guidVendor
            );

            /// <summary>
            /// Creates a new instance of the <see cref="WICNet::IWICBitmapDecoder"/> class based on the
            /// given file handle.
            /// </summary>
            /// <param name="hFile">
            /// The file handle to create the decoder from.
            /// </param>
            /// <param name="metadataOptions">
            /// The <see cref="WICNet::WICDecodeOptions"/> to use when creating the decoder.
            /// </param>
            /// <param name="guidVendor">
            /// The optional GUID for the preferred decoder vendor. Use null if no preferred vendor.
            /// Use one of the GUIDs in <see cref="WICNet::VendorGUID"/> class. The default value is null.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the decoder.
            /// </exception>
            WICNet::IWICBitmapDecoder ^CreateDecoderFromFileHandle(
                Microsoft::Win32::SafeHandles::SafeFileHandle ^hFile,
                WICNet::WICDecodeOptions metadataOptions,
                [OptionalAttribute] System::Nullable<System::Guid> guidVendor
            );

            // CreateComponentInfo

            /// <summary>
            /// Creates a new instance of <see cref="WICNet::IWICBitmapDecoder"/>.
            /// </summary>
            /// <param name="guidContainerFormat">
            /// The GUID for the desired container format. The list of built-in container formats are in
            /// <see cref="WICNet::ContainerFormatGUID"/>.
            /// </param>
            /// <param name="guidVendor">
            /// The optional GUID for the preferred decoder vendor. Use null if no preferred vendor.
            /// Use one of the GUIDs in <see cref="WICNet::VendorGUID"/> class. The default value is null.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the decoder.
            /// </exception>
            WICNet::IWICBitmapDecoder ^CreateDecoder(
                [InAttribute][IsReadOnlyAttribute] System::Guid %guidContainerFormat,
                [OptionalAttribute] System::Nullable<System::Guid> guidVendor
            );

            // CreateEncoder

            /// <summary>
            /// Creates a new instance of the <see cref="WICNet::IWICPalette"/> class.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the palette.
            /// </exception>
            WICNet::IWICPalette ^CreatePalette();

            /// <summary>
            /// Creates a new instance of the <see cref="WICNet::IWICFormatConverter"/> class.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the converter.
            /// </exception>
            WICNet::IWICFormatConverter ^CreateFormatConverter();
        };
    }
}