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
        /// <summary>
        /// Defines methods for setting an encoder's properties such as thumbnails, frames, and palettes.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("00000103-a8f2-4877-ba0a-fd2b6645fb94")]
        public ref class IWICBitmapEncoder : WICNet::IWICObject
        {
        internal:
            ::IWICBitmapEncoder *m_pEncoder;

            IWICBitmapEncoder() : m_pEncoder(nullptr) {}

        public:
            ~IWICBitmapEncoder();
            !IWICBitmapEncoder();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pEncoder;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Initializes the encoder with an <see cref="ComIO::IStream"/> which tells the encoder where
            /// to encode the bits.
            /// </summary>
            /// <param name="stream">
            /// The output stream.
            /// </param>
            /// <param name="cacheOptions">
            /// The <see cref="WICNet::WICBitmapEncoderCacheOption"/> used on initialization.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT Initialize(
                ComIO::IStream ^stream,
                WICNet::WICBitmapEncoderCacheOption cacheOption
            );

            /// <summary>
            /// Retrieves the encoder's container format.
            /// </summary>
            /// <param name="guidContainerFormat">
            /// A parameter that receives the encoder's container format GUID(out parameter).
            /// The built-in format GUIDs are defined in <see cref="WICNet::ContainerFormatGUID"/> class.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetContainerFormat(
                [OutAttribute] System::Guid %guidContainerFormat
            );
        };
    }
}