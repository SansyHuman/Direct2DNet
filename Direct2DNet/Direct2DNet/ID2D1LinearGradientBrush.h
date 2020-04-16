#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Brush.h"
#include "ID2D1GradientStopCollection.h"

namespace Direct2DNet
{
    // Done.
    ref class ID2D1RenderTarget;

    /// <summary>
    /// Paints an area with a linear gradient.
    /// </summary>
    [System::Runtime::InteropServices::GuidAttribute("1C8279B3-DE5C-4E89-97C3-6D49B5B182B7")]
    public ref class ID2D1LinearGradientBrush : Direct2DNet::ID2D1Brush
    {
    private:
        Direct2DNet::ID2D1GradientStopCollection ^m_collection;

    internal:
        ID2D1LinearGradientBrush(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::D2D1_POINT_2F %startPoint,
            Direct2DNet::D2D1_POINT_2F %endPoint,
            Direct2DNet::ID2D1GradientStopCollection ^collection
        );

        ID2D1LinearGradientBrush(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES %properties,
            Direct2DNet::ID2D1GradientStopCollection ^collection
        );

    public:
        /// <summary>
        /// Gets and sets the start point of the gradient in local coordinate space.
        /// </summary>
        property Direct2DNet::D2D1_POINT_2F StartPoint
        {
            Direct2DNet::D2D1_POINT_2F get()
            {
                return static_cast<Direct2DNet::D2D1_POINT_2F>(
                    ((::ID2D1LinearGradientBrush *)m_pResource)->GetStartPoint()
                    );
            }

            void set(Direct2DNet::D2D1_POINT_2F value)
            {
                ((::ID2D1LinearGradientBrush *)m_pResource)->SetStartPoint(
                    static_cast<::D2D1_POINT_2F>(value)
                );
            }
        }

        /// <summary>
        /// Gets and sets the start point of the gradient in local coordinate space.
        /// </summary>
        property Direct2DNet::D2D1_POINT_2F EndPoint
        {
            Direct2DNet::D2D1_POINT_2F get()
            {
                return static_cast<Direct2DNet::D2D1_POINT_2F>(
                    ((::ID2D1LinearGradientBrush *)m_pResource)->GetEndPoint()
                    );
            }

            void set(Direct2DNet::D2D1_POINT_2F value)
            {
                ((::ID2D1LinearGradientBrush *)m_pResource)->SetEndPoint(
                    static_cast<::D2D1_POINT_2F>(value)
                );
            }
        }

        /// <summary>
        /// Gets the <see cref="Direct2DNet::ID2D1GradientStopCollection"/> instance 
        /// associated with this linear gradient brush object.
        /// </summary>
        property Direct2DNet::ID2D1GradientStopCollection ^GradientStopCollection
        {
            Direct2DNet::ID2D1GradientStopCollection ^get()
            {
                return m_collection;
            }
        }
    };
}