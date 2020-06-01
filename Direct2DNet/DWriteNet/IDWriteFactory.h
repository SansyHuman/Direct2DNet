#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "Exception/DWriteException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteTextFormat;
        ref class IDWriteRenderingParams;

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
            /// Creates a rendering parameters object with default settings for the primary monitor.
            /// </summary>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the rendering params.
            /// </exception>
            DWriteNet::IDWriteRenderingParams ^CreateRenderingParams();

            /// <summary>
            /// Creates a rendering parameters object with default settings for the specified monitor.
            /// </summary>
            /// <param name="monitor">The monitor to read the default values from.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the rendering params.
            /// </exception>
            DWriteNet::IDWriteRenderingParams ^CreateMonitorRenderingParams(
                [InAttribute][IsReadOnlyAttribute] System::IntPtr %monitor
            );

            /// <summary>
            /// Creates a rendering parameters object with the specified properties.
            /// </summary>
            /// <param name="gamma">The gamma value used for gamma correction, which must be greater than
            /// zero and cannot exceed 256.</param>
            /// <param name="enhancedContrast">The amount of contrast enhancement, zero or greater.</param>
            /// <param name="clearTypeLevel">The degree of ClearType level, from 0.0f (no ClearType) to
            /// 1.0f (full ClearType).</param>
            /// <param name="pixelGeometry">The geometry of a device pixel.</param>
            /// <param name="renderingMode">Method of rendering glyphs. In most cases, this should be
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::DEFAULT"/> to automatically use an appropriate
            /// mode.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the rendering params.
            /// </exception>
            DWriteNet::IDWriteRenderingParams ^CreateCustomRenderingParams(
                float gamma,
                float enhancedContrast,
                float clearTypeLevel,
                DWriteNet::DWRITE_PIXEL_GEOMETRY pixelGeometry,
                DWriteNet::DWRITE_RENDERING_MODE renderingMode
            );

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
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the text format.
            /// </exception>
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