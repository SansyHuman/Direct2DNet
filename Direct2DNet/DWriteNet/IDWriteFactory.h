#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFontCollection;
        ref class IDWriteFontFile;
        ref class IDWriteRenderingParams;
        ref class IDWriteTextFormat;

        /// <summary>
        /// The root factory interface for all DWrite objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("b859ee5a-d838-4b5b-a2e8-1adc7d93db48")]
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
            /// Gets a font collection representing the set of installed fonts.
            /// </summary>
            /// <param name="checkForUpdates">If this parameter is true, the function performs an immediate
            /// check for changes to the set of installed fonts. If this parameter is false, the function
            /// will still detect changes if the font cache service is running, but there may be some latency.
            /// For example, an application might specify true if it has itself just installed a font and
            /// wants to be sure the font collection contains that font. The default value is false.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to get the collection.
            /// </exception>
            DWriteNet::IDWriteFontCollection ^GetSystemFontCollection(
                [OptionalAttribute] System::Nullable<bool> checkForUpdates
            );

            // CreateCustomFontCollection

            // RegisterFontCollectionLoader

            // UnregisterFontCollectionLoader

            /// <summary>
            /// CreateFontFileReference creates a font file reference object from a local font file.
            /// </summary>
            /// <param name="filePath">Absolute file path. Subsequent operations on the constructed object
            /// may fail if the user provided filePath doesn't correspond to a valid file on the disk.</param>
            /// <param name="lastWriteTime">Last modified time of the input file path. If the parameter
            /// is omitted, the function will access the font file to obtain its last write time, so the
            /// clients are encouraged to specify this value to avoid extra disk access. Subsequent operations
            /// on the constructed object may fail if the user provided lastWriteTime doesn't match the file
            /// on the disk. The default value is null.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to get the file.
            /// </exception>
            DWriteNet::IDWriteFontFile ^CreateFontFileReference(
                System::String ^filePath,
                [OptionalAttribute] System::Nullable<InteropServices::ComTypes::FILETIME> lastWriteTime
            );

            // CreateCustomFontFileReference

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