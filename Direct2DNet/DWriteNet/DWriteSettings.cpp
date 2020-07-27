#include "DWriteSettings.h"
#include "../Direct2DNet/D2DMath.h"
#include "IDWriteFontFace.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        DWRITE_MATRIX::operator Direct2DNet::D2D1_MATRIX_3X2_F(DWriteNet::DWRITE_MATRIX %rhs)
        {
            Direct2DNet::D2D1_MATRIX_3X2_F value;
            value.m11 = rhs.m11;
            value.m12 = rhs.m12;
            value.m21 = rhs.m21;
            value.m22 = rhs.m22;
            value.dx = rhs.dx;
            value.dy = rhs.dy;

            return value;
        }

        DWRITE_MATRIX::operator DWriteNet::DWRITE_MATRIX(Direct2DNet::D2D1_MATRIX_3X2_F %rhs)
        {
            DWriteNet::DWRITE_MATRIX value;
            value.m11 = rhs.m11;
            value.m12 = rhs.m12;
            value.m21 = rhs.m21;
            value.m22 = rhs.m22;
            value.dx = rhs.dx;
            value.dy = rhs.dy;

            return value;
        }

        DWRITE_GLYPH_RUN::operator ::DWRITE_GLYPH_RUN(DWriteNet::DWRITE_GLYPH_RUN %rhs)
        {
            ::DWRITE_GLYPH_RUN value;
            value.fontFace = rhs.fontFace->m_pFace;
            value.fontEmSize = rhs.fontEmSize;
            value.glyphCount = rhs.glyphCount;
            value.glyphIndices = rhs.glyphIndices;
            value.glyphAdvances = rhs.glyphAdvances;
            value.glyphOffsets = reinterpret_cast<::DWRITE_GLYPH_OFFSET *>(rhs.glyphOffsets);
            value.isSideways = rhs.isSideways;
            value.bidiLevel = rhs.bidiLevel;

            return value;
        }
    }
}