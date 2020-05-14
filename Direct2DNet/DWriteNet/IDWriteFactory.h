#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "Exception/DWriteException.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteTextFormat;

        // TODO: Implement IDWriteFontCollection.

        /// <summary>
        /// The root factory interface for all DWrite objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("6C56A1CC-811D-43E7-8117-B99A6B687480")]
        public ref class IDWriteFactory : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteFactory *m_pFactory;

        public:
            IDWriteFactory(DWriteNet::DWRITE_FACTORY_TYPE factoryType);
            ~IDWriteFactory();
            !IDWriteFactory();
            
            static DWriteNet::IDWriteFactory ^CreateFactory(DWriteNet::DWRITE_FACTORY_TYPE factoryType);

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pFactory;
                }
            }

            /// <summary>
            /// Create a text format object used for text layout.
            /// </summary>
            /// <param name="fontFamilyName">Name of the font family</param>
            /// <param name="fontWeight">Font weight</param>
            /// <param name="fontStyle">Font style</param>
            /// <param name="fontStretch">Font stretch</param>
            /// <param name="fontSize">Logical size of the font in DIP units. A DIP ("device-independent pixel") equals 1/96 inch.</param>
            /// <param name="localeName">Locale name</param>
            /// <returns>
            /// <see cref="DWriteNet::IDWriteTextFormat"/> instance.
            /// </returns>
            /// <remarks>
            /// The system font collection is used, grouped by typographic family name
            /// (DWRITE_FONT_FAMILY_MODEL_WEIGHT_STRETCH_STYLE) without downloadable fonts.
            /// </remarks>
            DWriteNet::IDWriteTextFormat ^CreateTextFormat(
                System::String ^fontFamilyName,
                DWriteNet::DWRITE_FONT_WEIGHT fontWeight,
                DWriteNet::DWRITE_FONT_STYLE fontStyle,
                DWriteNet::DWRITE_FONT_STRETCH fontStretch,
                float fontSize,
                System::String ^localeName
            );
        };
    }
}