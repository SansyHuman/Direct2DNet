#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1GradientStopCollection.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext;

        /// <summary>
        /// Represents an collection of gradient stops that can then be the source resource
        /// for either a linear or radial gradient brush.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("49880757-D5CC-4B1A-9DDE-6028BB86BC5E")]
        public ref class ID2D1GradientStopCollection1 : Direct2DNet::ID2D1GradientStopCollection
        {
        private:
            Direct2DNet::D2D1_COLOR_SPACE m_preInterpolationSpace;
            Direct2DNet::D2D1_COLOR_SPACE m_postInterpolationSpace;
            Direct2DNet::D2D1_BUFFER_PRECISION m_bufferPrecision;
            Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE m_colorInterpolationMode;

        internal:
            ID2D1GradientStopCollection1(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                array<Direct2DNet::D2D1_GRADIENT_STOP> ^straightAlphaGradientStops,
                Direct2DNet::D2D1_COLOR_SPACE preInterpolationSpace,
                Direct2DNet::D2D1_COLOR_SPACE postInterpolationSpace,
                Direct2DNet::D2D1_BUFFER_PRECISION bufferPrecision,
                Direct2DNet::D2D1_EXTEND_MODE extendMode,
                Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE colorInterpolationMode
            );

        public:
            /// <summary>
            /// Gets the color space in which interpolation occurs.
            /// </summary>
            property Direct2DNet::D2D1_COLOR_SPACE PreInterpolationSpace
            {
                Direct2DNet::D2D1_COLOR_SPACE get()
                {
                    return m_preInterpolationSpace;
                }
            }

            /// <summary>
            /// Gets the color space colors will be converted to after interpolation occurs.
            /// </summary>
            property Direct2DNet::D2D1_COLOR_SPACE PostInterpolationSpace
            {
                Direct2DNet::D2D1_COLOR_SPACE get()
                {
                    return m_postInterpolationSpace;
                }
            }

            /// <summary>
            /// Returns the buffer precision of this gradient.
            /// </summary>
            property Direct2DNet::D2D1_BUFFER_PRECISION BufferPrecision
            {
                Direct2DNet::D2D1_BUFFER_PRECISION get()
                {
                    return m_bufferPrecision;
                }
            }

            /// <summary>
            /// Returns the interpolation mode used to interpolate colors in the gradient.
            /// </summary>
            property Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE ColorInterpolationMode
            {
                Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE get()
                {
                    return m_colorInterpolationMode;
                }
            }
        };
    }
}