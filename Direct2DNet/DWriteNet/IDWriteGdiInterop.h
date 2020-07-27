#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "../DXCommonSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DWriteNet
    {
        // Done.

        ref class IDWriteFactory;
        ref class IDWriteFont;
        ref class IDWriteFontFace;
        interface class IDWriteBitmapRenderTarget;

        /// <summary>
        /// The GDI interop interface provides interoperability with GDI.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("1edd9491-9853-4299-898f-6432983b6f3a")]
        public ref class IDWriteGdiInterop : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteGdiInterop *m_pInterop;

            IDWriteGdiInterop() : m_pInterop(nullptr) {}

            IDWriteGdiInterop(DWriteNet::IDWriteFactory ^factory);

        public:
            ~IDWriteGdiInterop();
            !IDWriteGdiInterop();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pInterop;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Creates a font object that matches the properties specified by the LOGFONT structure
            /// in the system font collection (GetSystemFontCollection).
            /// </summary>
            /// <param name="logFont">Structure containing a GDI-compatible font description.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the font.
            /// </exception>
            DWriteNet::IDWriteFont ^CreateFontFromLOGFONT(
                [InAttribute][IsReadOnlyAttribute] D2DNet::LOGFONTW %logFont
            );

            /// <summary>
            /// Initializes a LOGFONT structure based on the GDI-compatible properties of the specified font.
            /// </summary>
            /// <param name="font">Specifies a font.</param>
            /// <param name="logFont">Structure that receives a GDI-compatible font description
            /// (out paramter).</param>
            /// <param name="isSystemFont">Contains true if the specified font object is part of the system
            /// font collection or false otherwise(out paramter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT ConvertFontToLOGFONT(
                DWriteNet::IDWriteFont ^font,
                [OutAttribute] D2DNet::LOGFONTW %logFont,
                [OutAttribute] bool %isSystemFont
            );

            /// <summary>
            /// Initializes a LOGFONT structure based on the GDI-compatible properties of the specified font.
            /// </summary>
            /// <param name="font">Specifies a font.</param>
            /// <returns>
            /// (HRESULT, <see cref="D2DNet::LOGFONTW"/>, bool) tuple. HREULST is an error code.
            /// <see cref="D2DNet::LOGFONTW"/> is the structure that contains a GDI-compatible font
            /// description. bool contains true if the specified font object is part of the system
            /// font collection or false otherwise.
            /// </returns>
            System::ValueTuple<HRESULT, D2DNet::LOGFONTW, bool> ConvertFontToLOGFONT(
                DWriteNet::IDWriteFont ^font
            );

            /// <summary>
            /// Initializes a LOGFONT structure based on the GDI-compatible properties of the specified font.
            /// </summary>
            /// <param name="font">Specifies a font face.</param>
            /// <param name="logFont">Structure that receives a GDI-compatible font description(out
            /// parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT ConvertFontFaceToLOGFONT(
                DWriteNet::IDWriteFontFace ^font,
                [OutAttribute] D2DNet::LOGFONTW %logFont
            );

            /// <summary>
            /// Initializes a LOGFONT structure based on the GDI-compatible properties of the specified font.
            /// </summary>
            /// <param name="font">Specifies a font face.</param>
            /// <returns>
            /// (HRESULT, <see cref="D2DNet::LOGFONTW"/>) tuple. HREULST is an error code.
            /// <see cref="D2DNet::LOGFONTW"/> is the structure that contains a GDI-compatible font
            /// description.
            /// </returns>
            System::ValueTuple<HRESULT, D2DNet::LOGFONTW> ConvertFontFaceToLOGFONT(
                DWriteNet::IDWriteFontFace ^font
            );

            /// <summary>
            /// Creates a font face object that corresponds to the currently selected HFONT.
            /// </summary>
            /// <param name="hdc">Handle to a device context into which a font has been selected. It is
            /// assumed that the client has already performed font mapping and that the font selected into
            /// the DC is the actual font that would be used for rendering glyphs.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the font face.
            /// </exception>
            DWriteNet::IDWriteFontFace ^CreateFontFaceFromHdc(
                [InAttribute][IsReadOnlyAttribute] System::IntPtr %hdc
            );

            
            /// <summary>
            /// Creates an object that encapsulates a bitmap and memory DC which can be used for rendering glyphs.
            /// </summary>
            /// <param name="hdc">Optional device context used to create a compatible memory DC.
            /// If there is no DC, then use IntPtr::Zero.</param>
            /// <param name="width">Width of the bitmap.</param>
            /// <param name="height">Height of the bitmap.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the render target.
            /// </exception>
            DWriteNet::IDWriteBitmapRenderTarget ^CreateBitmapRenderTarget(
                [InAttribute][IsReadOnlyAttribute] System::IntPtr %hdc,
                UINT32 width,
                UINT32 height
            );
            
        };
    }
}