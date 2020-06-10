#include "D2DSettings.h"
#include "ID2D1Geometry.h"
#include "ID2D1Brush.h"
#include "ID2D1ColorContext.h"
#include "ID2D1Effect.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        D2D1_LAYER_PARAMETERS::operator ::D2D1_LAYER_PARAMETERS(Direct2DNet::D2D1_LAYER_PARAMETERS %rhs)
        {
            ::D2D1_LAYER_PARAMETERS value;
            value.contentBounds = static_cast<::D2D1_RECT_F>(rhs.contentBounds);
            value.geometricMask = rhs.geometricMask == nullptr ? __nullptr : (::ID2D1Geometry *)rhs.geometricMask->m_pResource;
            value.maskAntialiasMode = (::D2D1_ANTIALIAS_MODE)((int)rhs.maskAntialiasMode);
            value.maskTransform = static_cast<::D2D1_MATRIX_3X2_F>(rhs.maskTransform);
            value.opacity = rhs.opacity;
            value.opacityBrush = rhs.opacityBrush == nullptr ? __nullptr : (::ID2D1Brush *)rhs.opacityBrush->m_pResource;
            value.layerOptions = (::D2D1_LAYER_OPTIONS)((int)rhs.layerOptions);

            return value;
        }

        D2D1_BITMAP_PROPERTIES1::operator ::D2D1_BITMAP_PROPERTIES1(Direct2DNet::D2D1_BITMAP_PROPERTIES1 %rhs)
        {
            ::D2D1_BITMAP_PROPERTIES1 value;
            value.pixelFormat = static_cast<::D2D1_PIXEL_FORMAT>(rhs.pixelFormat);
            value.dpiX = rhs.dpiX;
            value.dpiY = rhs.dpiY;
            value.bitmapOptions = (::D2D1_BITMAP_OPTIONS)((int)rhs.bitmapOptions);
            value.colorContext = 
                rhs.colorContext == nullptr ? __nullptr : (::ID2D1ColorContext *)rhs.colorContext->m_pResource;

            return value;
        }

        D2D1_LAYER_PARAMETERS1::operator::D2D1_LAYER_PARAMETERS1(Direct2DNet::D2D1_LAYER_PARAMETERS1 %rhs)
        {
            ::D2D1_LAYER_PARAMETERS1 value;
            value.contentBounds = static_cast<::D2D1_RECT_F>(rhs.contentBounds);
            value.geometricMask = rhs.geometricMask == nullptr ? __nullptr : (::ID2D1Geometry *)rhs.geometricMask->m_pResource;
            value.maskAntialiasMode = (::D2D1_ANTIALIAS_MODE)((int)rhs.maskAntialiasMode);
            value.maskTransform = static_cast<::D2D1_MATRIX_3X2_F>(rhs.maskTransform);
            value.opacity = rhs.opacity;
            value.opacityBrush = rhs.opacityBrush == nullptr ? __nullptr : (::ID2D1Brush *)rhs.opacityBrush->m_pResource;
            value.layerOptions = (::D2D1_LAYER_OPTIONS1)((int)rhs.layerOptions);

            return value;
        }

        D2D1_EFFECT_INPUT_DESCRIPTION::operator::D2D1_EFFECT_INPUT_DESCRIPTION(
            Direct2DNet::D2D1_EFFECT_INPUT_DESCRIPTION %rhs)
        {
            ::D2D1_EFFECT_INPUT_DESCRIPTION value;
            value.effect = (::ID2D1Effect *)rhs.effect->m_pProperties;
            value.inputIndex = rhs.inputIndex;
            value.inputRectangle = static_cast<::D2D1_RECT_F>(rhs.inputRectangle);

            return value;
        }

    }
}