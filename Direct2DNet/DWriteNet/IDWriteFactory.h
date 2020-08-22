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
        ref class IDWriteFontFace;
        ref class IDWriteTypography;
        ref class IDWriteGdiInterop;
        ref class IDWriteTextLayout;
        ref class IDWriteInlineObject;
        ref class IDWriteTextAnalyzer;
        ref class IDWriteNumberSubstitution;
        ref class IDWriteGlyphRunAnalysis;

        /// <summary>
        /// The root factory interface for all DWrite objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("b859ee5a-d838-4b5b-a2e8-1adc7d93db48")]
        public ref class IDWriteFactory : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteFactory *m_pFactory;

            IDWriteFactory() : m_pFactory(nullptr) {}

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

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Gets a font collection representing the set of installed fonts.
            /// </summary>
            /// <param name="fontCollection">Receives the system font collection object, or null in case
            /// of failure(out parameter).</param>
            /// <param name="checkForUpdates">If this parameter is true, the function performs an immediate
            /// check for changes to the set of installed fonts. If this parameter is false, the function
            /// will still detect changes if the font cache service is running, but there may be some latency.
            /// For example, an application might specify true if it has itself just installed a font and
            /// wants to be sure the font collection contains that font. The default value is false.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetSystemFontCollection(
                [OutAttribute] DWriteNet::IDWriteFontCollection ^%fontCollection,
                [OptionalAttribute] System::Nullable<bool> checkForUpdates
            );

            /// <summary>
            /// Gets a font collection representing the set of installed fonts.
            /// </summary>
            /// <param name="checkForUpdates">If this parameter is true, the function performs an immediate
            /// check for changes to the set of installed fonts. If this parameter is false, the function
            /// will still detect changes if the font cache service is running, but there may be some latency.
            /// For example, an application might specify true if it has itself just installed a font and
            /// wants to be sure the font collection contains that font. The default value is false.</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::IDWriteFontCollection"/>) tuple. HRESULT is an error code.
            /// <see cref="DWriteNet::IDWriteFontCollection"/> is the newly created font collection if
            /// successful or null otherwise.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^> GetSystemFontCollection(
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
            /// Creates a font face object.
            /// </summary>
            /// <param name="fontFaceType">The file format of the font face.</param>
            /// <param name="fontFiles">Font files representing the font face. Since IDWriteFontFace
            /// maintains its own references to the input font file objects, it's OK to release them after
            /// this call.</param>
            /// <param name="faceIndex">The zero based index of a font face in cases when the font files
            /// contain a collection of font faces. If the font files contain a single face, this value
            /// should be zero.</param>
            /// <param name="fontFaceSimulationFlags">Font face simulation flags for algorithmic emboldening
            /// and italicization.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the face.
            /// </exception>
            DWriteNet::IDWriteFontFace ^CreateFontFace(
                DWriteNet::DWRITE_FONT_FACE_TYPE fontFaceType,
                array<DWriteNet::IDWriteFontFile ^> ^fontFiles,
                UINT32 faceIndex,
                DWriteNet::DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags
            );

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

            // RegisterFontFileLoader

            // UnregisterFontFileLoader

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

            /// <summary>
            /// Create a typography object used in conjunction with text format for text layout.
            /// </summary>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the typography.
            /// </exception>
            DWriteNet::IDWriteTypography ^CreateTypography();

            /// <summary>
            /// Create an object used for interoperability with GDI.
            /// </summary>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the interop.
            /// </exception>
            DWriteNet::IDWriteGdiInterop ^GetGdiInterop();

            /// <summary>
            /// CreateTextLayout takes a string, format, and associated constraints
            /// and produces an object representing the fully analyzed
            /// and formatted result.
            /// </summary>
            /// <param name="string">The string to layout.</param>
            /// <param name="textFormat">The format to apply to the string.</param>
            /// <param name="maxWidth">Width of the layout box.</param>
            /// <param name="maxHeight">Height of the layout box.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the layout.
            /// </exception>
            DWriteNet::IDWriteTextLayout ^CreateTextLayout(
                System::String ^string,
                DWriteNet::IDWriteTextFormat ^textFormat,
                float maxWidth,
                float maxHeight
            );

            /// <summary>
            /// CreateGdiCompatibleTextLayout takes a string, format, and associated constraints
            /// and produces and object representing the result formatted for a particular display resolution
            /// and measuring mode. The resulting text layout should only be used for the intended resolution,
            /// and for cases where text scalability is desired, CreateTextLayout should be used instead.
            /// </summary>
            /// <param name="string">The string to layout.</param>
            /// <param name="textFormat">The format to apply to the string.</param>
            /// <param name="layoutWidth">Width of the layout box.</param>
            /// <param name="layoutHeight">Height of the layout box.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if rendering onto
            /// a 96 DPI device then pixelsPerDip is 1. If rendering onto a 120 DPI device then pixelsPerDip
            /// is 120/96.</param>
            /// <param name="useGdiNatural">
            /// When set to false, instructs the text layout to use the same metrics as GDI aliased text.
            /// When set to true, instructs the text layout to use the same metrics as text measured by
            /// GDI using a font created with CLEARTYPE_NATURAL_QUALITY.
            /// </param>
            /// <param name="transform">Optional transform applied to the glyphs and their positions. This
            /// transform is applied after the scaling specified the font size and pixelsPerDip.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the layout.
            /// </exception>           
            DWriteNet::IDWriteTextLayout ^CreateGdiCompatibleTextLayout(
                System::String ^string,
                DWriteNet::IDWriteTextFormat ^textFormat,
                float layoutWidth,
                float layoutHeight,
                float pixelsPerDip,
                bool useGdiNatural,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform
            );

            /// <summary>
            /// The application may call this function to create an inline object for trimming, using an
            /// ellipsis as the omission sign.
            /// The ellipsis will be created using the current settings of the format, including base font,
            /// style, and any effects.
            /// Alternate omission signs can be created by the application by implementing IDWriteInlineObject.
            /// </summary>
            /// <param name="textFormat">Text format used as a template for the omission sign.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the trimming sign.
            /// </exception>  
            DWriteNet::IDWriteInlineObject ^CreateEllipsisTrimmingSign(
                DWriteNet::IDWriteTextFormat ^textFormat
            );

            /// <summary>
            /// Return an interface to perform text analysis with.
            /// </summary>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the analyzer.
            /// </exception>  
            DWriteNet::IDWriteTextAnalyzer ^CreateTextAnalyzer();

            /// <summary>
            /// Creates a number substitution object using a locale name,
            /// substitution method, and whether to ignore user overrides (uses NLS
            /// defaults for the given culture instead).
            /// </summary>
            /// <param name="substitutionMethod">Method of number substitution to use.</param>
            /// <param name="localeName">Which locale to obtain the digits from.</param>
            /// <param name="ignoreUserOverride">Ignore the user's settings and use the locale defaults</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the substitution.
            /// </exception>  
            DWriteNet::IDWriteNumberSubstitution ^CreateNumberSubstitution(
                DWriteNet::DWRITE_NUMBER_SUBSTITUTION_METHOD substitutionMethod,
                System::String ^localeName,
                bool ignoreUserOverride
            );

            /// <summary>
            /// Creates a glyph run analysis object, which encapsulates information
            /// used to render a glyph run.
            /// </summary>
            /// <param name="glyphRun">Structure specifying the properties of the glyph run.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if rendering onto
            /// a 96 DPI bitmap then pixelsPerDip is 1. If rendering onto a 120 DPI bitmap then pixelsPerDip
            /// is 120/96.</param>
            /// <param name="transform">Optional transform applied to the glyphs and their positions. This
            /// transform is applied after the scaling specified by the emSize and pixelsPerDip.</param>
            /// <param name="renderingMode">Specifies the rendering mode, which must be one of the 
            /// aster rendering modes (i.e., not default and not outline).</param>
            /// <param name="measuringMode">Specifies the method to measure glyphs.</param>
            /// <param name="baselineOriginX">Horizontal position of the baseline origin, in DIPs.</param>
            /// <param name="baselineOriginY">Vertical position of the baseline origin, in DIPs.</param>
            /// <exception cref="DWriteNet::Exception::DWriteException">
            /// Thrown when it failed to create the analysis.
            /// </exception>  
            DWriteNet::IDWriteGlyphRunAnalysis ^CreateGlyphRunAnalysis(
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
                float pixelsPerDip,
                DWriteNet::DWRITE_RENDERING_MODE renderingMode,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode,
                float baselineOriginX,
                float baselineOriginY,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform
            );
        };
    }
}