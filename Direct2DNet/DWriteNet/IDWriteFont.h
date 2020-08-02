#pragma once

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

        ref class IDWriteFontFamily;
        ref class IDWriteLocalizedStrings;
        ref class IDWriteFontFace;

        /// <summary>
        /// The IDWriteFont interface represents a physical font in a font collection.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("acd16696-8c14-4f5d-877e-fe3fc1d32737")]
        public ref class IDWriteFont : DWriteNet::IDirectWriteObject
        {
        protected:
            DWriteNet::IDWriteFontFamily ^m_fontFamily;

        internal:
            ::IDWriteFont *m_pFont;

            IDWriteFont() : m_pFont(nullptr) {}

            IDWriteFont(
                ::IDWriteFont *pFont,
                DWriteNet::IDWriteFontFamily ^fontFamily
            );

            IDWriteFont(::IDWriteFont *pFont);

        public:
            ~IDWriteFont();
            !IDWriteFont();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pFont;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Gets the font family to which the specified font belongs.
            /// </summary>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontFamily(
                [OutAttribute] DWriteNet::IDWriteFontFamily ^%fontFamily
            );

            /// <summary>
            /// Gets the weight of the specified font.
            /// </summary>
            property DWriteNet::DWRITE_FONT_WEIGHT Weight
            {
                DWriteNet::DWRITE_FONT_WEIGHT get()
                {
                    return (DWriteNet::DWRITE_FONT_WEIGHT)((int)m_pFont->GetWeight());
                }
            }

            /// <summary>
            /// Gets the stretch (aka. width) of the specified font.
            /// </summary>
            property DWriteNet::DWRITE_FONT_STRETCH Stretch
            {
                DWriteNet::DWRITE_FONT_STRETCH get()
                {
                    return (DWriteNet::DWRITE_FONT_STRETCH)((int)m_pFont->GetStretch());
                }
            }

            /// <summary>
            /// Gets the style (aka. slope) of the specified font.
            /// </summary>
            property DWriteNet::DWRITE_FONT_STYLE Style
            {
                DWriteNet::DWRITE_FONT_STYLE get()
                {
                    return (DWriteNet::DWRITE_FONT_STYLE)((int)m_pFont->GetStyle());
                }
            }

            /// <summary>
            /// Returns TRUE if the font is a symbol font or FALSE if not.
            /// </summary>
            property bool IsSymbolFont
            {
                bool get()
                {
                    return System::Convert::ToBoolean(m_pFont->IsSymbolFont());
                }
            }

            /// <summary>
            /// Gets a localized strings collection containing the face names for the font
            /// (e.g., Regular or Bold), indexed by locale name.
            /// </summary>
            /// <param name="names">Receives the newly created localized strings object(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFaceNames(
                [OutAttribute] DWriteNet::IDWriteLocalizedStrings ^%names
            );

            /// <summary>
            /// Gets a localized strings collection containing the face names for the font
            /// (e.g., Regular or Bold), indexed by locale name.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteLocalizedStrings"/>) tuple.
            /// HRESULT is an error code. If failed, <see cref="DWriteNet::IDWriteLocalizedStrings"/> is null.
            /// <see cref="DWriteNet::IDWriteLocalizedStrings"/> is the localized strings.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^> GetFaceNames();

            /// <summary>
            /// Gets a localized strings collection containing the specified informational strings,
            /// indexed by locale name.
            /// </summary>
            /// <param name="informationalStringID">Identifies the string to get.</param>
            /// <param name="informationalStrings">Receives the newly created localized
            /// strings object(out parameter).</param>
            /// <param name="exists">Receives the value true if the font contains the specified string ID
            /// or false if not(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code. If the font does not contain the specified string, the
            /// return value is S_OK but informationalStrings receives null and exists receives the
            /// value false.
            /// </returns>
            HRESULT GetInformationalStrings(
                DWriteNet::DWRITE_INFORMATIONAL_STRING_ID informationalStringID,
                [OutAttribute] DWriteNet::IDWriteLocalizedStrings ^%informationalStrings,
                [OutAttribute] bool %exists
            );

            /// <summary>
            /// Gets a localized strings collection containing the specified informational strings,
            /// indexed by locale name.
            /// </summary>
            /// <param name="informationalStringID">Identifies the string to get.</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteLocalizedStrings"/>, bool) tuple.
            /// HRESULT is an error code. If the font does not contain the specified string, the
            /// HRESULT is S_OK but <see cref="DWriteNet::IDWriteLocalizedStrings"/> is null and bool
            /// is false. <see cref="DWriteNet::IDWriteLocalizedStrings"/> is the localized strings.
            /// bool is true if the font contains the specified string ID or false if not.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteLocalizedStrings ^, bool> GetInformationalStrings(
                DWriteNet::DWRITE_INFORMATIONAL_STRING_ID informationalStringID
            );

            /// <summary>
            /// Gets a value that indicates what simulation are applied to the specified font.
            /// </summary>
            property DWriteNet::DWRITE_FONT_SIMULATIONS Simulations
            {
                DWriteNet::DWRITE_FONT_SIMULATIONS get()
                {
                    return (DWriteNet::DWRITE_FONT_SIMULATIONS)((int)m_pFont->GetSimulations());
                }
            }

            /// <summary>
            /// Gets the metrics for the font.
            /// </summary>
            property DWriteNet::DWRITE_FONT_METRICS Metrics
            {
                DWriteNet::DWRITE_FONT_METRICS get()
                {
                    DWriteNet::DWRITE_FONT_METRICS value = DWriteNet::DWRITE_FONT_METRICS();

                    pin_ptr<DWriteNet::DWRITE_FONT_METRICS> pValue = &value;
                    m_pFont->GetMetrics((::DWRITE_FONT_METRICS *)pValue);
                    pValue = nullptr;

                    return value;
                }
            }

            /// <summary>
            /// Determines whether the font supports the specified character.
            /// </summary>
            /// <param name="unicodeValue">Unicode (UCS-4) character value.</param>
            /// <param name="exists">Receives the value true if the font supports the specified character
            /// or false if not(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT HasCharacter(
                UINT32 unicodeValue,
                [OutAttribute] bool %exists
            );

            /// <summary>
            /// Determines whether the font supports the specified character.
            /// </summary>
            /// <param name="unicodeValue">Unicode (UCS-4) character value.</param>
            /// <returns>
            /// (HRESULT, bool) tuple. HRESULT is an error code. bool is true if the font supports the
            /// specified character or false if not.
            /// </returns>
            System::ValueTuple<HRESULT, bool> HasCharacter(
                UINT32 unicodeValue
            );

            /// <summary>
            /// Creates a font face object for the font.
            /// </summary>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the face.
            /// </exception>
            DWriteNet::IDWriteFontFace ^CreateFontFace();
        };
    }
}