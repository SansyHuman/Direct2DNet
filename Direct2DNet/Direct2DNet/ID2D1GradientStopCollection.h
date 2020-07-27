#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1RenderTarget;
        ref class ID2D1DeviceContext;

        // Done.

        /// <summary>
        /// Represents an collection of gradient stops that can then be the source resource
        /// for either a linear or radial gradient brush.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2cd906a7-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1GradientStopCollection : Direct2DNet::ID2D1Resource
        {
        protected:
            array<Direct2DNet::D2D1_GRADIENT_STOP> ^m_gradientStops;
            Direct2DNet::D2D1_GAMMA m_gamma;
            Direct2DNet::D2D1_EXTEND_MODE m_extendMode;

        internal:
            ID2D1GradientStopCollection() : Direct2DNet::ID2D1Resource() {}

            ID2D1GradientStopCollection(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                array<Direct2DNet::D2D1_GRADIENT_STOP> ^gradientStops,
                Direct2DNet::D2D1_GAMMA gamma,
                Direct2DNet::D2D1_EXTEND_MODE extendMode
            );

        protected:
            ID2D1GradientStopCollection(
                Direct2DNet::ID2D1DeviceContext ^deviceContext
            );

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Gets the copy of gradient stops.
            /// </summary>
            property array<Direct2DNet::D2D1_GRADIENT_STOP> ^GradientStops
            {
                array<Direct2DNet::D2D1_GRADIENT_STOP> ^get()
                {
                    array<Direct2DNet::D2D1_GRADIENT_STOP> ^value = gcnew array<Direct2DNet::D2D1_GRADIENT_STOP>(m_gradientStops->Length);
                    m_gradientStops->CopyTo(value, 0);

                    return value;
                }
            }

            /// <summary>
            /// Gets whether the interpolation occurs with 1.0 or 2.2 gamma.
            /// </summary>
            property Direct2DNet::D2D1_GAMMA ColorInterpolationGamma
            {
                Direct2DNet::D2D1_GAMMA get()
                {
                    return m_gamma;
                }
            }

            /// <summary>
            /// Gets the extend mode.
            /// </summary>
            property Direct2DNet::D2D1_EXTEND_MODE ExtendMode
            {
                Direct2DNet::D2D1_EXTEND_MODE get()
                {
                    return m_extendMode;
                }
            }
        };
    }
}