#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Brush.h"
#include "ID2D1GradientStopCollection.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1RenderTarget;

        // Done.

        /// <summary>
        /// Paints an area with a radial gradient.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2cd906ac-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1RadialGradientBrush : Direct2DNet::ID2D1Brush
        {
        private:
            Direct2DNet::ID2D1GradientStopCollection ^m_collection;

        internal:
            ID2D1RadialGradientBrush(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                Direct2DNet::D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES %properties,
                Direct2DNet::ID2D1GradientStopCollection ^collection
            );

        public:
            /// <summary>
            /// Gets and sets the center of the radial gradient in local coordinate space.
            /// </summary>
            property Direct2DNet::D2D1_POINT_2F Center
            {
                Direct2DNet::D2D1_POINT_2F get()
                {
                    return static_cast<Direct2DNet::D2D1_POINT_2F>(
                        ((::ID2D1RadialGradientBrush *)m_pResource)->GetCenter()
                        );
                }

                void set(Direct2DNet::D2D1_POINT_2F value)
                {
                    ((::ID2D1RadialGradientBrush *)m_pResource)->SetCenter(
                        static_cast<::D2D1_POINT_2F>(value)
                    );
                }
            }

            /// <summary>
            /// Gets and sets the offset of the origin relative to the radial gradient center.
            /// </summary>
            property Direct2DNet::D2D1_POINT_2F GradientOriginOffset
            {
                Direct2DNet::D2D1_POINT_2F get()
                {
                    return static_cast<Direct2DNet::D2D1_POINT_2F>(
                        ((::ID2D1RadialGradientBrush *)m_pResource)->GetGradientOriginOffset()
                        );
                }

                void set(Direct2DNet::D2D1_POINT_2F value)
                {
                    ((::ID2D1RadialGradientBrush *)m_pResource)->SetGradientOriginOffset(
                        static_cast<::D2D1_POINT_2F>(value)
                    );
                }
            }

            /// <summary>
            /// Gets and sets the x-radius of the gradient ellipse.
            /// </summary>
            property float RadiusX
            {
                float get()
                {
                    return ((::ID2D1RadialGradientBrush *)m_pResource)->GetRadiusX();
                }

                void set(float value)
                {
                    ((::ID2D1RadialGradientBrush *)m_pResource)->SetRadiusX(value);
                }
            }

            /// <summary>
            /// Gets and sets the y-radius of the gradient ellipse.
            /// </summary>
            property float RadiusY
            {
                float get()
                {
                    return ((::ID2D1RadialGradientBrush *)m_pResource)->GetRadiusY();
                }

                void set(float value)
                {
                    ((::ID2D1RadialGradientBrush *)m_pResource)->SetRadiusY(value);
                }
            }

            /// <summary>
            /// Gets and sets the gradient ellipse.
            /// </summary>
            property Direct2DNet::D2D1_ELLIPSE GradientEllipse
            {
                Direct2DNet::D2D1_ELLIPSE get()
                {
                    Direct2DNet::D2D1_ELLIPSE value;
                    value.point = static_cast<Direct2DNet::D2D1_POINT_2F>(((::ID2D1RadialGradientBrush *)m_pResource)->GetCenter());
                    value.radiusX = ((::ID2D1RadialGradientBrush *)m_pResource)->GetRadiusX();
                    value.radiusY = ((::ID2D1RadialGradientBrush *)m_pResource)->GetRadiusY();

                    return value;
                }

                void set(Direct2DNet::D2D1_ELLIPSE value)
                {
                    ((::ID2D1RadialGradientBrush *)m_pResource)->SetCenter(static_cast<::D2D1_POINT_2F>(value.point));
                    ((::ID2D1RadialGradientBrush *)m_pResource)->SetRadiusX(value.radiusX);
                    ((::ID2D1RadialGradientBrush *)m_pResource)->SetRadiusY(value.radiusY);
                }
            }

            /// <summary>
            /// Gets the <see cref="Direct2DNet::ID2D1GradientStopCollection"/> instance 
            /// associated with this radial gradient brush object.
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
}