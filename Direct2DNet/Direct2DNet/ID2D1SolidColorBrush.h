#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Brush.h"

namespace Direct2DNet
{
    // Done.
    ref class ID2D1RenderTarget;

    /// <summary>
    /// Paints an area with a solid color.
    /// </summary>
    public ref class ID2D1SolidColorBrush : Direct2DNet::ID2D1Brush
    {
    internal:
        ID2D1SolidColorBrush(Direct2DNet::ID2D1RenderTarget ^renderTarget, Direct2DNet::D2D1_COLOR_F %color);

    public:
        /// <summary>
        /// Gets and sets the color of the brush.
        /// </summary>
        property Direct2DNet::D2D1_COLOR_F Color
        {
            Direct2DNet::D2D1_COLOR_F get()
            {
                return static_cast<Direct2DNet::D2D1_COLOR_F>(
                    ((::ID2D1SolidColorBrush *)m_pResource)->GetColor());
            }

            void set(Direct2DNet::D2D1_COLOR_F value)
            {
                ((::ID2D1SolidColorBrush *)m_pResource)->SetColor(
                    static_cast<::D2D1_COLOR_F>(value)
                );
            }
        }
    };
}