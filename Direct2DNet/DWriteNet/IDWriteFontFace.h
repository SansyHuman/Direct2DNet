#pragma once

#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

#ifdef GetGlyphIndices
#undef GetGlyphIndices
#endif

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1PathGeometry;
    }

    namespace DWriteNet
    {
        // Done.

        ref class IDWriteFactory;
        ref class IDWriteFontFile;
        ref class IDWriteRenderingParams;

        /// <summary>
        /// This interface exposes various font data such as metrics, names, and glyph outlines.
        /// It contains font face type, appropriate file references and face identification data.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("5f49804d-7024-4d43-bfa9-d25984f53849")]
        public ref class IDWriteFontFace : DWriteNet::IDirectWriteObject
        {            
        private:
            array<DWriteNet::IDWriteFontFile ^> ^m_fontFiles;

        internal:
            ::IDWriteFontFace *m_pFace;

            IDWriteFontFace() : m_pFace(nullptr) {}

            IDWriteFontFace(::IDWriteFontFace *pFace);

            IDWriteFontFace(
                DWriteNet::IDWriteFactory ^factory,
                DWriteNet::DWRITE_FONT_FACE_TYPE fontFaceType,
                array<DWriteNet::IDWriteFontFile ^> ^fontFiles,
                UINT32 faceIndex,
                DWriteNet::DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags
            );

        public:
            ~IDWriteFontFace();
            !IDWriteFontFace();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pFace;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Obtains the file format type of a font face.
            /// </summary>
            property DWriteNet::DWRITE_FONT_FACE_TYPE Type
            {
                DWriteNet::DWRITE_FONT_FACE_TYPE get()
                {
                    return (DWriteNet::DWRITE_FONT_FACE_TYPE)((int)m_pFace->GetType());
                }
            }

            /// <summary>
            /// Obtains the font files representing a font face.
            /// </summary>
            /// <param name="numberOfFiles">The number of files representing the font face.</param>
            /// <param name="fontFileBuffer">User provided array that stores font files representing the
            /// font face. This parameter can be null if the user is only interested in the number of files
            /// representing the font face.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFiles(
                UINT32 %numberOfFiles,
                [OptionalAttribute] array<DWriteNet::IDWriteFontFile ^> ^fontFileBuffer
            );

            /// <summary>
            /// Obtains the zero-based index of the font face in its font file or files. If the font
            /// files contain a single face, the return value is zero.
            /// </summary>
            property UINT32 Index
            {
                UINT32 get()
                {
                    return m_pFace->GetIndex();
                }
            }

            /// <summary>
            /// Obtains the algorithmic style simulation flags of a font face.
            /// </summary>
            property DWriteNet::DWRITE_FONT_SIMULATIONS Simulations
            {
                DWriteNet::DWRITE_FONT_SIMULATIONS get()
                {
                    return (DWriteNet::DWRITE_FONT_SIMULATIONS)((int)m_pFace->GetSimulations());
                }
            }

            /// <summary>
            /// Determines whether the font is a symbol font.
            /// </summary>
            property bool IsSymbolFont
            {
                bool get()
                {
                    return System::Convert::ToBoolean(m_pFace->IsSymbolFont());
                }
            }

            /// <summary>
            /// Obtains design units and common metrics for the font face.
            /// These metrics are applicable to all the glyphs within a fontface and are used by
            /// applications for layout calculations.
            /// </summary>
            property DWriteNet::DWRITE_FONT_METRICS Metrics
            {
                DWriteNet::DWRITE_FONT_METRICS get()
                {
                    DWriteNet::DWRITE_FONT_METRICS value = DWriteNet::DWRITE_FONT_METRICS();

                    pin_ptr<DWriteNet::DWRITE_FONT_METRICS> pValue = &value;
                    m_pFace->GetMetrics((::DWRITE_FONT_METRICS *)pValue);
                    pValue = nullptr;

                    return value;
                }
            }

            /// <summary>
            /// Obtains the number of glyphs in the font face.
            /// </summary>
            property UINT16 GlyphCount
            {
                UINT16 get()
                {
                    return m_pFace->GetGlyphCount();
                }
            }

            /// <summary>
            /// Obtains ideal glyph metrics in font design units. Design glyphs metrics are used for
            /// glyph positioning.
            /// </summary>
            /// <param name="glyphIndices">An array of glyph indices to compute the metrics for.</param>
            /// <param name="glyphMetrics">Array of DWRITE_GLYPH_METRICS structures filled by this function.
            /// The metrics returned by this function are in font design units(out parameter).</param>
            /// <param name="isSideways">Indicates whether the font is being used in a sideways run.
            /// This can affect the glyph metrics if the font has oblique simulation
            /// because sideways oblique simulation differs from non-sideways oblique simulation.
            /// The default value is false.</param>
            /// <returns>
            /// Standard HRESULT error code. If any of the input glyph indices are outside of the valid
            /// glyph index range for the current font face, E_INVALIDARG will be returned.
            /// </returns>
            HRESULT GetDesignGlyphMetrics(
                array<UINT16> ^glyphIndices,
                [OutAttribute] array<DWriteNet::DWRITE_GLYPH_METRICS> ^%glyphMetrics,
                [OptionalAttribute] System::Nullable<bool> isSideways
            );

            /// <summary>
            /// Returns the nominal mapping of UTF-32 Unicode code points to glyph indices as defined by
            /// the font 'cmap' table. Note that this mapping is primarily provided for line layout engines
            /// built on top of the physical font API. Because of OpenType glyph substitution and line layout
            /// character substitution, the nominal conversion does not always correspond to how a Unicode
            /// string will map to glyph indices when rendering using a particular font face. Also, note that
            /// Unicode Variation Selectors provide for alternate mappings for character to glyph.
            /// This call will always return the default variant.
            /// </summary>
            /// <param name="codePoints">An array of UTF-32 code points to obtain nominal glyph indices
            /// from.</param>
            /// <param name="glyphIndices">Array of nominal glyph indices filled by this function
            /// (out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetGlyphIndices(
                array<UINT32> ^codePoints,
                [OutAttribute] array<UINT16> ^%glyphIndices
            );

            /// <summary>
            /// Finds the specified OpenType font table if it exists and returns a pointer to it.
            /// The function accesses the underlying font data via the IDWriteFontFileStream interface
            /// implemented by the font file loader.
            /// </summary>
            /// <param name="openTypeTableTag">Four character tag of table to find.
            ///     Use <see cref="DWriteNet::DirectWrite::MakeOpentypeTag"/> method to create it.
            ///     Unlike GDI, it does not support the special TTCF and null tags to access the whole font.
            /// </param>
            /// <param name="tableData">
            ///     Pointer to base of table in memory(out parameter).
            ///     The pointer is only valid so long as the FontFace used to get the font table still exists
            ///     (not any other FontFace, even if it actually refers to the same physical font).
            /// </param>
            /// <param name="tableSize">Byte size of table(out parameter).</param>
            /// <param name="tableContext">
            ///     Opaque context which must be freed by calling ReleaseFontTable(out parameter).
            ///     The context actually comes from the lower level IDWriteFontFileStream,
            ///     which may be implemented by the application or DWrite itself.
            ///     It is possible for a NULL tableContext to be returned, especially if
            ///     the implementation directly memory maps the whole file.
            ///     Nevertheless, always release it later, and do not use it as a test for function success.
            ///     The same table can be queried multiple times,
            ///     but each returned context can be different, so release each separately.
            /// </param>
            /// <param name="exists">True if table exists(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// If a table can not be found, the function will not return an error, but the size will be
            /// 0, table NULL, and exists = FALSE.
            /// The context does not need to be freed if the table was not found.
            /// </returns>
            /// <remarks>
            /// The context for the same tag may be different for each call,
            /// so each one must be held and released separately.
            /// </remarks>
            HRESULT TryGetFontTable(
                UINT32 openTypeTableTag,
                [OutAttribute] void *%tableData,
                [OutAttribute] UINT32 %tableSize,
                [OutAttribute] void *%tableContext,
                [OutAttribute] bool %exists
            );

            /// <summary>
            /// Releases the table obtained earlier from TryGetFontTable.
            /// </summary>
            /// <param name="tableContext">Opaque context from TryGetFontTable.</param>
            void ReleaseFontTable(void *tableContext);

            /// <summary>
            /// Computes the outline of a run of glyphs by calling back to the outline sink interface.
            /// </summary>
            /// <param name="emSize">Logical size of the font in DIP units.
            /// A DIP ("device-independent pixel") equals 1/96 inch.</param>
            /// <param name="glyphIndices">Array of glyph indices.</param>
            /// <param name="isSideways">If true, specifies that glyphs are rotated 90 degrees to the left
            /// and vertical metrics are used. A client can render a vertical run by specifying isSideways =
            /// true and rotating the resulting geometry 90 degrees to the right using a transform.</param>
            /// <param name="isRightToLeft">If true, specifies that the advance direction is right to left.
            /// By default, the advance direction is left to right.</param>
            /// <param name="geometry">Geometry the function calls back to draw each element of the geometry.
            /// </param>
            /// <param name="glyphAdvances">Optional array of glyph advances in DIPs.</param>
            /// <param name="glyphOffsets">Optional array of glyph offsets.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetGlyphRunOutline(
                float emSize,
                array<UINT16> ^glyphIndices,
                bool isSideways,
                bool isRightToLeft,
                Direct2DNet::ID2D1PathGeometry ^geometry,
                [OptionalAttribute] array<float> ^glyphAdvances,
                [OptionalAttribute] array<DWriteNet::DWRITE_GLYPH_OFFSET> ^glyphOffsets
            );

            /// <summary>
            /// Determines the recommended rendering mode for the font given the specified size and
            /// rendering parameters.
            /// </summary>
            /// <param name="emSize">Logical size of the font in DIP units.
            /// A DIP ("device-independent pixel") equals 1/96 inch.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if the DPI of
            /// the rendering surface is 96 this value is 1.0f. If the DPI is 120, this value is
            /// 120.0f/96.</param>
            /// <param name="measuringMode">Specifies measuring mode that will be used for glyphs in the font.
            /// Renderer implementations may choose different rendering modes for given measuring modes, but
            /// best results are seen when the corresponding modes match:
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_NATURAL"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::NATURAL"/>
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_GDI_CLASSIC"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::GDI_CLASSIC"/>
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_GDI_NATURAL"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::GDI_NATURAL"/>
            /// </param>
            /// <param name="renderingParams">Rendering parameters object. This parameter is necessary in
            /// case the rendering parameters object overrides the rendering mode.</param>
            /// <param name="renderingMode">Receives the recommended rendering mode to use
            /// (out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetRecommendedRenderingMode(
                float emSize,
                float pixelsPerDip,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode,
                DWriteNet::IDWriteRenderingParams ^renderingParams,
                [OutAttribute] DWriteNet::DWRITE_RENDERING_MODE %renderingMode
            );

            /// <summary>
            /// Determines the recommended rendering mode for the font given the specified size and
            /// rendering parameters.
            /// </summary>
            /// <param name="emSize">Logical size of the font in DIP units.
            /// A DIP ("device-independent pixel") equals 1/96 inch.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if the DPI of
            /// the rendering surface is 96 this value is 1.0f. If the DPI is 120, this value is
            /// 120.0f/96.</param>
            /// <param name="measuringMode">Specifies measuring mode that will be used for glyphs in the font.
            /// Renderer implementations may choose different rendering modes for given measuring modes, but
            /// best results are seen when the corresponding modes match:
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_NATURAL"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::NATURAL"/>
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_GDI_CLASSIC"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::GDI_CLASSIC"/>
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_GDI_NATURAL"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::GDI_NATURAL"/>
            /// </param>
            /// <param name="renderingParams">Rendering parameters object. This parameter is necessary in
            /// case the rendering parameters object overrides the rendering mode.</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::DWRITE_RENDERING_MODE"/>) tuple. HRESULT is an error code.
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE"/> is the recommended rendering mode to use.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::DWRITE_RENDERING_MODE> GetRecommendedRenderingMode(
                float emSize,
                float pixelsPerDip,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode,
                DWriteNet::IDWriteRenderingParams ^renderingParams
            );

            /// <summary>
            /// Obtains design units and common metrics for the font face.
            /// These metrics are applicable to all the glyphs within a fontface and are used by applications
            /// for layout calculations.
            /// </summary>
            /// <param name="emSize">Logical size of the font in DIP units. A DIP ("device-independent pixel")
            /// equals 1/96 inch.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if the DPI of
            /// the rendering surface is 96 this value is 1.0f. If the DPI is 120, this value is
            /// 120.0f/96.</param>          
            /// <param name="fontFaceMetrics">DWRITE_FONT_METRICS structure to fill in(out parameter).
            /// The metrics returned by this function are in font design units.</param>
            /// <param name="transform">Optional transform applied to the glyphs and their positions.
            /// This transform is applied after the scaling specified by the font size and pixelsPerDip.
            /// The default value is null.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetGdiCompatibleMetrics(
                float emSize,
                float pixelsPerDip,
                [OutAttribute] DWriteNet::DWRITE_FONT_METRICS %fontFaceMetrics,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform
            );

            /// <summary>
            /// Obtains design units and common metrics for the font face.
            /// These metrics are applicable to all the glyphs within a fontface and are used by applications
            /// for layout calculations.
            /// </summary>
            /// <param name="emSize">Logical size of the font in DIP units. A DIP ("device-independent pixel")
            /// equals 1/96 inch.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if the DPI of
            /// the rendering surface is 96 this value is 1.0f. If the DPI is 120, this value is
            /// 120.0f/96.</param>          
            /// <param name="transform">Optional transform applied to the glyphs and their positions.
            /// This transform is applied after the scaling specified by the font size and pixelsPerDip.
            /// The default value is null.</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::DWRITE_FONT_METRICS"/>) tuple. HRESULT is an error code.
            /// <see cref="DWriteNet::DWRITE_FONT_METRICS"/> is the metrics.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::DWRITE_FONT_METRICS> GetGdiCompatibleMetrics(
                float emSize,
                float pixelsPerDip,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform
            );

            /// <summary>
            /// Obtains glyph metrics in font design units with the return values compatible with what
            /// GDI would produce. Glyphs metrics are used for positioning of individual glyphs.
            /// </summary>
            /// <param name="emSize">Logical size of the font in DIP units.
            /// A DIP ("device-independent pixel") equals 1/96 inch.</param>
            /// <param name="pixelsPerDip">Number of physical pixels per DIP. For example, if the DPI of
            /// the rendering surface is 96 this value is 1.0f. If the DPI is 120, this value is 120.0f/96.
            /// </param>
            /// <param name="useGdiNatural">
            /// When set to false, the metrics are the same as the metrics of GDI aliased text.
            /// When set to true, the metrics are the same as the metrics of text measured by GDI using a font
            /// created with CLEARTYPE_NATURAL_QUALITY.
            /// </param>
            /// <param name="glyphIndices">An array of glyph indices to compute the metrics for.</param>
            /// <param name="glyphMetrics">Array of DWRITE_GLYPH_METRICS structures filled by this function.
            /// The metrics returned by this function are in font design units.</param>
            /// <param name="transform">Optional transform applied to the glyphs and their positions.
            /// This transform is applied after the scaling specified by the font size and pixelsPerDip.
            /// The default value is null.</param>
            /// <param name="isSideways">Indicates whether the font is being used in a sideways run.
            /// This can affect the glyph metrics if the font has oblique simulation
            /// because sideways oblique simulation differs from non-sideways oblique simulation.
            /// The default value is false.</param>
            /// <returns>
            /// Standard HRESULT error code. If any of the input glyph indices are outside of the valid glyph index range
            /// for the current font face, E_INVALIDARG will be returned.
            /// </returns>
            HRESULT GetGdiCompatibleGlyphMetrics(
                float emSize,
                float pixelsPerDip,
                bool useGdiNatural,
                array<UINT16> ^glyphIndices,
                [OutAttribute] array<DWriteNet::DWRITE_GLYPH_METRICS> ^%glyphMetrics,
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform,
                [OptionalAttribute] System::Nullable<bool> isSideways
            );
            
        };
    }
}

#ifndef GetGlyphIndices
#define GetGlyphIndices GetGlyphIndicesW
#endif