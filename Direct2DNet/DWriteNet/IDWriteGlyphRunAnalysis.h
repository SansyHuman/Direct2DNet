#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"
#include "../DXCommonSettings.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;
        ref class IDWriteRenderingParams;

        /// <summary>
        /// Interface that encapsulates information used to render a glyph run.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("7d97dbf7-e085-42d4-81e3-6a883bded118")]
        public ref class IDWriteGlyphRunAnalysis : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteGlyphRunAnalysis *m_pAnal;

            IDWriteGlyphRunAnalysis() : m_pAnal(nullptr) {}

            IDWriteGlyphRunAnalysis(
                DWriteNet::IDWriteFactory ^factory,
                DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
                float pixelsPerDip,
                DWriteNet::DWRITE_RENDERING_MODE renderingMode,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode,
                float baselineOriginX,
                float baselineOriginY,
                System::Nullable<DWriteNet::DWRITE_MATRIX> transform
            );

        public:
            ~IDWriteGlyphRunAnalysis();
            !IDWriteGlyphRunAnalysis();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pAnal;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Gets the bounding rectangle of the physical pixels affected by the glyph run.
            /// </summary>
            /// <param name="textureType">Specifies the type of texture requested. If a bi-level texture
            /// is requested, the bounding rectangle includes only bi-level glyphs. Otherwise, the bounding
            /// rectangle includes only anti-aliased glyphs.</param>
            /// <param name="textureBounds">Receives the bounding rectangle, or an empty rectangle if there
            /// are no glyphs if the specified type(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetAlphaTextureBounds(
                DWriteNet::DWRITE_TEXTURE_TYPE textureType,
                [OutAttribute] D2DNet::RECT %textureBounds
            );

            /// <summary>
            /// Creates an alpha texture of the specified type.
            /// </summary>
            /// <param name="textureType">Specifies the type of texture requested. If a bi-level texture
            /// is requested, the texture contains only bi-level glyphs. Otherwise, the texture contains
            /// only anti-aliased glyphs.</param>
            /// <param name="textureBounds">Specifies the bounding rectangle of the texture, which can
            /// be different than the bounding rectangle returned by GetAlphaTextureBounds.</param>
            /// <param name="alphaValues">The pre-allocated buffer of alpha values. The minimum size of buffer
            /// depends on the dimensions of the rectangle and the type of texture requested.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT CreateAlphaTexture(
                DWriteNet::DWRITE_TEXTURE_TYPE textureType,
                [InAttribute][IsReadOnlyAttribute] D2DNet::RECT %textureBounds,
                array<BYTE> ^alphaValues
            );

            /// <summary>
            /// Gets properties required for ClearType blending.
            /// </summary>
            /// <param name="renderingParams">Rendering parameters object. In most cases, the values
            /// returned in the output parameters are based on the properties of this object. The exception
            /// is if a GDI-compatible rendering mode is specified.</param>
            /// <param name="blendGamma">Receives the gamma value to use for gamma correction(out parameter).
            /// </param>
            /// <param name="blendEnhancedContrast">Receives the enhanced contrast value(out parameter).
            /// </param>
            /// <param name="blendClearTypeLevel">Receives the ClearType level(out parameter).</param>
            HRESULT GetAlphaBlendParams(
                DWriteNet::IDWriteRenderingParams ^renderingParams,
                [OutAttribute] FLOAT %blendGamma,
                [OutAttribute] FLOAT %blendEnhancedContrast,
                [OutAttribute] FLOAT %blendClearTypeLevel
            );
        };
    }
}