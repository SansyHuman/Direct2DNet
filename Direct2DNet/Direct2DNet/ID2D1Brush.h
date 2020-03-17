#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

namespace Direct2DNet
{
    // Done.

    /// <summary>
    /// The root brush class. All brushes can be used to fill or pen a geometry.
    /// </summary>
    public ref class ID2D1Brush abstract : Direct2DNet::ID2D1Resource
    {
    protected:
        ID2D1Brush(Direct2DNet::ID2D1Factory ^factory) : ID2D1Resource(factory) {}

    public:
        /// <summary>
        /// Gets and sets the opacity for when the brush is drawn over the entire fill of the brush.
        /// </summary>
        property float Opacity
        {
            float get()
            {
                return ((::ID2D1Brush *)m_pResource)->GetOpacity();
            }

            void set(float value)
            {
                float temp = value;
                if(temp < 0)
                    temp = 0;
                if(temp > 1)
                    temp = 1;
                ((::ID2D1Brush *)m_pResource)->SetOpacity(temp);
            }
        }

        /// <summary>
        /// Gets and sets the transform that applies to everything drawn by the brush.
        /// </summary>
        property Direct2DNet::D2D1_MATRIX_3X2_F Transform
        {
            Direct2DNet::D2D1_MATRIX_3X2_F get()
            {
                ::D2D1_MATRIX_3X2_F temp;
                ((::ID2D1Brush *)m_pResource)->GetTransform(&temp);
                return static_cast<Direct2DNet::D2D1_MATRIX_3X2_F>(temp);
            }

            void set(Direct2DNet::D2D1_MATRIX_3X2_F value)
            {
                ((::ID2D1Brush *)m_pResource)->SetTransform(static_cast<::D2D1_MATRIX_3X2_F>(value));
            }
        }
    };
}