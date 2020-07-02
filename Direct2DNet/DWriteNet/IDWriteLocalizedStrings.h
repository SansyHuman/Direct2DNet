#pragma once

#include <msclr/marshal.h>

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        /// <summary>
        /// Represents a collection of strings indexed by locale name.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("08256209-099a-4b34-b86d-c22b110e7771")]
        public ref class IDWriteLocalizedStrings : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteLocalizedStrings *m_pStrings;

            IDWriteLocalizedStrings(::IDWriteLocalizedStrings *pStrings) : m_pStrings(pStrings) {}

        public:
            ~IDWriteLocalizedStrings();
            !IDWriteLocalizedStrings();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pStrings;
                }
            }

            /// <summary>
            /// Gets the number of language/string pairs.
            /// </summary>
            property UINT32 Count
            {
                UINT32 get()
                {
                    return m_pStrings->GetCount();
                }
            }

            /// <summary>
            /// Gets the index of the item with the specified locale name.
            /// </summary>
            /// <param name="localeName">Locale name to look for.</param>
            /// <param name="index">Receives the zero-based index of the locale name/string
            /// pair(out parameter).</param>
            /// <param name="exists">Receives true if the locale name exists or false if
            /// not(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code. If the specified locale name does not exist, the return value
            /// is S_OK, but index is UINT_MAX and exists is false.
            /// </returns>
            HRESULT FindLocaleName(
                System::String ^localeName,
                [OutAttribute] UINT32 %index,
                [OutAttribute] bool %exists
            );

            /// <summary>
            /// Gets the index of the item with the specified locale name.
            /// </summary>
            /// <param name="localeName">Locale name to look for.</param>
            /// <returns>
            /// (HRESULT, uint, bool) tuple. HRESULT is an error code. If the specified locale name does
            /// not exist, HRESULT is S_OK, but uint is UINT_MAX and bool is false.
            /// uint is the index of the locale name/string pair. bool is true if the locale name exists
            /// or false if not.
            /// </returns>
            System::ValueTuple<HRESULT, UINT32, bool> FindLocaleName(System::String ^localeName);

            /// <summary>
            /// Receives the locale name with the specified index to the localeName.
            /// </summary>
            /// <param name="index">Zero-based index of the locale name.</param>
            /// <param name="localeName">String that receives the locale name(out attribute).</param>
            /// <returns>
            /// Standard HRESULT error code. Also, if failed, localeName is null.
            /// </returns>
            HRESULT GetLocaleName(
                UINT32 index,
                [OutAttribute] System::String ^%localeName
            );

            /// <summary>
            /// Receives the locale name with the specified index to the localeName.
            /// </summary>
            /// <param name="index">Zero-based index of the locale name.</param>
            /// <returns>
            /// (HRESULT, string) tuple. HRESULT is an error code. If failed, string is null.
            /// string is the locale name.
            /// </returns>
            System::ValueTuple<HRESULT, System::String ^>GetLocaleName(UINT32 index);

            /// <summary>
            /// Copies the string with the specified index to the specified array.
            /// </summary>
            /// <param name="index">Zero-based index of the string.</param>
            /// <param name="string">string that receives the string(out attribute).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetString(
                UINT32 index,
                [OutAttribute] System::String ^%string
            );

            /// <summary>
            /// Gets the string with the specified index.
            /// </summary>
            /// <param name="index">Zero-based index of the string.</param>
            /// <returns>
            /// (HRESULT, string) tuple.HRESULT is an error code.If failed, string is null.
            /// string is the string.
            /// </returns>
            System::ValueTuple<HRESULT, System::String ^> GetString(UINT32 index);

            /// <summary>
            /// Gets the string with the specified locale name.
            /// </summary>
            /// <returns>
            /// The string correspond to the locale name. null if does not exist.
            /// </returns>
            property System::String ^default[System::String ^]
            {
                System::String ^get(System::String ^localeName);
            }
        };
    }
}