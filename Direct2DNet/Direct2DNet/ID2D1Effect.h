#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "D2DBuiltinEffects.h"
#include "ID2D1Properties.h"
#include "../DXCommonSettings.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext;
        ref class ID2D1Image;

        /// <summary>
        /// The effect interface. Properties control how the effect is rendered. The effect
        /// is Drawn with the DrawImage call.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("28211a43-7d89-476f-8181-2d6159b220ad")]
        public ref class ID2D1Effect : Direct2DNet::ID2D1Properties
        {
        private:
            array<Direct2DNet::ID2D1Image ^> ^m_inputs;
            Direct2DNet::ID2D1DeviceContext ^m_deviceContext;

        internal:
            ID2D1Effect(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                System::Guid %effectId
            );

        public:
            /// <summary>
            /// Sets the input to the given effect. The input can be a concrete bitmap or the
            /// output of another effect.
            /// </summary>
            /// <param name="invalidate">Whether to invalidate the graph at the location of the effect input.
            /// The default value is true.</param>
            void SetInput(
                unsigned int index,
                Direct2DNet::ID2D1Image ^input,
                [OptionalAttribute] System::Nullable<bool> invalidate
            );

            /// <summary>
            /// If the effect supports a variable number of inputs, this sets the number of
            /// input that are currently active on the effect.
            /// </summary>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT SetInputCount(unsigned int inputCount);

            /// <summary>
            /// Returns the input image to the effect. The input could be another effect or a
            /// bitmap.
            /// </summary>
            Direct2DNet::ID2D1Image ^GetInput(unsigned int index);

            /// <summary>
            /// Returns the number of input that are bound into this effect.
            /// </summary>
            unsigned int GetInputCount();

            /// <summary>
            /// Gets the output image of the given effect. This can be set as the input to
            /// another effect or can be drawn with DrawImage.
            /// </summary>
            property Direct2DNet::ID2D1Image ^Output
            {
                Direct2DNet::ID2D1Image ^get();
            }

            /// <summary>
            /// Sets the given input effect by index.
            /// </summary>
            void SetInputEffect(
                unsigned int index,
                Direct2DNet::ID2D1Effect ^inputEffect,
                [OptionalAttribute] System::Nullable<bool> invalidate
            );
        };
    }
}