#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "../Direct2DNet/Exception/DXException.h"
#include <msclr/marshal.h>

using namespace msclr::interop;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {
        // Done.

        /// <summary>
        /// Exposes methods for color management.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("3C613A02-34B2-44ea-9A7C-45AEA9C6FD6D")]
        public ref class IWICColorContext : WICNet::IWICObject
        {
        internal:
            ::IWICColorContext *m_pContext;

            IWICColorContext() : m_pContext(nullptr) {}
            IWICColorContext(::IWICColorContext *pContext) : m_pContext(pContext) {}

        public:
            ~IWICColorContext();
            !IWICColorContext();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pContext;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// The value of sRGB color space.
            /// </summary>
            literal UINT EXIF_SRGB = 1;

            /// <summary>
            /// The value of Adobe RGB color space.
            /// </summary>
            literal UINT EXIF_ADOBE = 2;

            /// <summary>
            /// Initializes the color context from the given file.
            /// </summary>
            /// <param name="filename">
            /// The name of the file.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT InitializeFromFilename(System::String ^filename);

            /// <summary>
            /// Initializes the color context from a memory block.
            /// </summary>
            /// <param name="buffer">
            /// The buffer used to initialize the IWICColorContext.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT InitializeFromMemory(array<BYTE> ^buffer);

            /// <summary>
            /// Initializes the color context using an Exchangeable Image File (EXIF) color space.
            /// </summary>
            /// <param name="value">
            /// The value of the EXIF color space. 1 is a sRGB color space. 2 is an Adobe RGB color space.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT InitializeFromExifColorSpace(UINT value);

            /// <summary>
            /// Retrieves the color context type.
            /// </summary>
            /// <param name="value">
            /// A parameter that receives the <see cref="WICNet::WICColorContextType"/> of the color context
            /// (out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetType(
                [OutAttribute] WICNet::WICColorContextType %type
            );

            /// <summary>
            /// Retrieves the color context type.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="WICNet::WICColorContextType"/>) tuple. If this method succeeds,
            /// HRESULT is S_OK. Otherwise, it is an HRESULT error code.
            /// <see cref="WICNet::WICColorContextType"/> is the color context type.
            /// </returns>
            System::ValueTuple<HRESULT, WICNet::WICColorContextType> GetType();

            /// <summary>
            /// Retrieves the color context profile.
            /// </summary>
            /// <param name="cbActual">
            /// A parameter that receives the actual buffer size needed to retrieve the entire color context
            /// profile.
            /// </param>
            /// <param name="buffer">
            /// An array that receives the color context profile. Set this to null to receive the required
            /// buffer size through cbActual. The default value is null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetProfileBytes(
                UINT %cbActual,
                [OptionalAttribute] array<BYTE> ^buffer
            );

            /// <summary>
            /// Retrieves the Exchangeable Image File (EXIF) color space color context.
            /// </summary>
            /// <param name="value">
            /// A parameter that receives the EXIF color space color context(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetExifColorSpace(
                [OutAttribute] UINT %value
            );

            /// <summary>
            /// Retrieves the Exchangeable Image File (EXIF) color space color context.
            /// </summary>
            /// <returns>
            /// (HRESULT, uint) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. uint is the EXIF color space color context.
            /// </returns>
            System::ValueTuple<HRESULT, UINT> GetExifColorSpace();
        };
    }
}