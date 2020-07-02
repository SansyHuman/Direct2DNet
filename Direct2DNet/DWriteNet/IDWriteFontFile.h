#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

#include <msclr/marshal.h>

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;

        /// <summary>
        /// The interface that represents a reference to a font file.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("739d886a-cef5-47dc-8769-1a8b41bebbb0")]
        public ref class IDWriteFontFile : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteFontFile *m_pFile;

            // IDWriteFontFace::ctor
            IDWriteFontFile(::IDWriteFontFile *pFile);

            // IDWriteFactory::CreateFontFileReference
            IDWriteFontFile(
                DWriteNet::IDWriteFactory ^factory,
                System::String ^filePath,
                System::Nullable<InteropServices::ComTypes::FILETIME> lastWriteTime
                );
            
        public:
            ~IDWriteFontFile();
            !IDWriteFontFile();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pFile;
                }
            }

            /// <summary>
            /// This method obtains the pointer to the reference key of a font file. The pointer is only
            /// valid until the object that refers to it is released.
            /// </summary>
            /// <param name="fontFileReferenceKey">Pointer to the font file reference key(out parameter).
            /// IMPORTANT: The pointer value is valid until the font file reference object it is obtained
            /// from is released.</param>
            /// <param name="fontFileReferenceKeySize">Size of font file reference key in bytes
            /// (out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetReferenceKey(
                [OutAttribute] void *%fontFileReferenceKey,
                [OutAttribute] UINT32 %fontFileReferenceKeySize
            );

            // GetLoader

            /// <summary>
            /// Analyzes a file and returns whether it represents a font, and whether the font type is
            /// supported by the font system.
            /// </summary>
            /// <param name="isSupportedFontType">true if the font type is supported by the font system,
            /// false otherwise.</param>
            /// <param name="fontFileType">The type of the font file. Note that even if isSupportedFontType
            /// is false, the fontFileType value may be different from
            /// <see cref="DWriteNet::DWRITE_FONT_FILE_TYPE::UNKNOWN"/>.</param>
            /// <param name="fontFaceType">The type of the font face that can be constructed from the
            /// font file. Note that even if isSupportedFontType is FALSE, the fontFaceType value may
            /// be different from <see cref="DWriteNet::DWRITE_FONT_FACE_TYPE::UNKNOWN"/>.</param>
            /// <param name="numberOfFaces">Number of font faces contained in the font file.</param>
            /// <returns>
            /// Standard HRESULT error code if there was a processing error during analysis.
            /// </returns>
            /// <remarks>
            /// IMPORTANT: certain font file types are recognized, but not supported by the font system.
            /// For example, the font system will recognize a file as a Type 1 font file,
            /// but will not be able to construct a font face object from it. In such situations, Analyze
            /// will set isSupportedFontType output parameter to FALSE.
            /// </remarks>
            HRESULT Analyze(
                [OutAttribute] bool %isSupportedFontType,
                [OutAttribute] DWriteNet::DWRITE_FONT_FILE_TYPE %fontFileType,
                [OutAttribute] DWriteNet::DWRITE_FONT_FACE_TYPE %fontFaceType,
                [OutAttribute] UINT32 %numberOfFaces
            );
        };
    }
}