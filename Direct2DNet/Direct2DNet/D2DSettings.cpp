#include "D2DSettings.h"
#include "ID2D1Geometry.h"
#include "ID2D1Brush.h"

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
    }
}