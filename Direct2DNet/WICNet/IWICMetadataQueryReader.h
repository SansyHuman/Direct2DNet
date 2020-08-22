#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "../Direct2DNet/Exception/DXException.h"
#include "../DXCommonSettings.h"
#include <msclr/marshal.h>

using namespace msclr::interop;

namespace D2DNet
{
    namespace WICNet
    {
        /// <summary>
        /// Exposes methods that represent a decoder. The interface provides access to the decoder's
        /// properties such as global thumbnails (if supported), frames, and palette.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("30989668-E1C9-4597-B395-458EEDB808DF")]
        public ref class IWICMetadataQueryReader : WICNet::IWICObject
        {
        internal:
            ::IWICMetadataQueryReader *m_pReader;

            IWICMetadataQueryReader() : m_pReader(nullptr) {}

        public:
            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pReader;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Gets the metadata query readers container format.
            /// </summary>
            /// <param name="guidContainerFormat">
            /// A parameter that receives the cointainer format GUID(out parameter).
            /// The built-in format GUIDs are defined in <see cref="WICNet::ContainerFormatGUID"/> class.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetContainerFormat(
                [OutAttribute] System::Guid %guidContainerFormat
            );

            /// <summary>
            /// Retrieves the current path relative to the root metadata block.
            /// </summary>
            /// <param name="nameSpace">
            /// A parameter that receives the current namespace location(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetLocation(
                [OutAttribute] System::String ^%nameSpace
            );

            /// <summary>
            /// Retrieves the metadata block or item identified by a metadata query expression.
            /// </summary>
            /// <param name="name">
            /// The query expression to the requested metadata block or item.
            /// </param>
            /// <param name="varValue">
            /// A parameter that receives the metadata block or item requested(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetMetadataByName(
                System::String ^name,
                [OutAttribute] D2DNet::PROPVARIANT %varValue
            );
        };
    }
}