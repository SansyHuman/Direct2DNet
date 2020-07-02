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
        ref class IDWriteFontFamily;

        /// <summary>
        /// The IDWriteFontCollection encapsulates a collection of font families.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("a84cee02-3eea-4eee-a827-87c1a02a0fcc")]
        public ref class IDWriteFontCollection : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteFontCollection *m_pCollection;

            IDWriteFontCollection(::IDWriteFontCollection *pCollection) : m_pCollection(pCollection) {}

        public:
            ~IDWriteFontCollection();
            !IDWriteFontCollection();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pCollection;
                }
            }

            property UINT32 FontFamilyCount
            {
                UINT32 get()
                {
                    return m_pCollection->GetFontFamilyCount();
                }
            }

            /// <summary>
            /// Creates a font family object given a zero-based font family index.
            /// </summary>
            /// <param name="index">Zero-based index of the font family.</param>
            /// <param name="fontFamily">Receives the newly created font family object(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontFamily(
                UINT32 index,
                [OutAttribute] DWriteNet::IDWriteFontFamily ^%fontFamily
            );

            property DWriteNet::IDWriteFontFamily ^default[UINT32]
            {
                DWriteNet::IDWriteFontFamily ^get(UINT32 index);
            }

            /// <summary>
            /// Finds the font family with the specified family name.
            /// </summary>
            /// <param name="familyName">Name of the font family. The name is not case-sensitive but
            /// must otherwise exactly match a family name in the collection.</param>
            /// <param name="index">Receives the zero-based index of the matching font family if the
            /// family name was found or UINT_MAX otherwise(out parameter).</param>
            /// <param name="exists">Receives true if the family name exists or false otherwise
            /// (out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code. If the specified family name does not exist, the return value
            /// is S_OK, but index is UINT_MAX and exists is false.
            /// </returns>
            HRESULT FindFamilyName(
                System::String ^familyName,
                [OutAttribute] UINT32 %index,
                [OutAttribute] bool %exists
            );

            /// <summary>
            /// Finds the font family with the specified family name.
            /// </summary>
            /// <param name="familyName">Name of the font family. The name is not case-sensitive but
            /// must otherwise exactly match a family name in the collection.</param>
            /// <returns>
            /// (HRESULT, uint, bool) error code. HRESULT is the error code. uint is the index of the font
            /// family. bool is true if the family name exists or false otherwise.
            /// If the specified family name does not exist, HRESULT is S_OK, but uint is UINT_MAX and bool
            /// is false.
            /// </returns>
            System::ValueTuple<HRESULT, UINT32, bool> FindFamilyName(
                System::String ^familyName
            );

            // GetFontFromFontFace
        };
    }
}