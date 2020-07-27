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
        // Done.

        ref class IDWriteFontCollection;
        ref class IDWriteFontFamily;
        ref class IDWriteFont;

        /// <summary>
        /// The IDWriteFontList interface represents an ordered set of fonts that are part of an IDWriteFontCollection.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("1a0d8438-1d97-4ec1-aef9-a2fb86ed6acb")]
        public ref class IDWriteFontList : DWriteNet::IDirectWriteObject
        {
        protected:
            DWriteNet::IDWriteFontCollection ^m_fontCollection;

        internal:
            ::IDWriteFontList *m_pList;

            IDWriteFontList() : m_pList(nullptr) {}

            IDWriteFontList(
                ::IDWriteFontList *pList,
                DWriteNet::IDWriteFontCollection ^fontCollection
            );

            IDWriteFontList(::IDWriteFontList *pList);

        public:
            ~IDWriteFontList();
            !IDWriteFontList();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pList;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Gets the font collection that contains the fonts.
            /// </summary>
            property DWriteNet::IDWriteFontCollection ^FontCollection
            {
                DWriteNet::IDWriteFontCollection ^get()
                {
                    return m_fontCollection;
                }
            }

            /// <summary>
            /// Gets the number of fonts in the font list.
            /// </summary>
            property UINT32 FontCount
            {
                UINT32 get()
                {
                    return m_pList->GetFontCount();
                }
            }

            /// <summary>
            /// Gets a font given its zero-based index.
            /// </summary>
            /// <param name="index">Zero-based index of the font in the font list.</param>
            /// <param name="font">Receives the newly created font object(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFont(
                UINT32 index,
                [OutAttribute] DWriteNet::IDWriteFont ^%font
            );

            /// <summary>
            /// Gets a font given its zero-based index.
            /// </summary>
            /// <param name="index">Zero-based index of the font in the font list.</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteFont"/>) tuple. HRESULT is an error code.
            /// <see cref="DWriteNet::IDWriteFont"/> is the font.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteFont ^> GetFont(
                UINT32 index
            );

            /// <summary>
            /// Gets a font given its zero-based index.
            /// </summary>
            property DWriteNet::IDWriteFont ^default[UINT32]
            {
                DWriteNet::IDWriteFont ^get(UINT32 index);
            }
        };
    }
}