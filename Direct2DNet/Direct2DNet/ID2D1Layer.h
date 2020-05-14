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

        // Done.

        /// <summary>
        /// Represents the backing store required to render a layer.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("926446E6-AC46-40B2-8753-B8DA0570A5EA")]
        public ref class ID2D1Layer : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1Layer(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                System::Nullable<Direct2DNet::D2D1_SIZE_F> %size);

        public:
            /// <summary>
            /// Gets the size of the layer in device-independent pixels.
            /// </summary>
            property Direct2DNet::D2D1_SIZE_F Size
            {
                Direct2DNet::D2D1_SIZE_F get()
                {
                    return static_cast<Direct2DNet::D2D1_SIZE_F>(((::ID2D1Layer *)m_pResource)->GetSize());
                }
            }
        };
    }
}