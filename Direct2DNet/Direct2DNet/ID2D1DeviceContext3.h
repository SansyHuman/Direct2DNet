#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1DeviceContext2.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1Device3;
        ref class ID2D1SpriteBatch;
        ref class ID2D1Bitmap;

        // Done.

        /// <summary>
        /// This interface performs all the same functions as the ID2D1DeviceContext2 interface, plus
        /// it enables functionality for creating and drawing sprite batches.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("235a7496-8351-414c-bcd4-6672ab2d8e00")]
        public ref class ID2D1DeviceContext3 : Direct2DNet::ID2D1DeviceContext2
        {
        internal:
            ID2D1DeviceContext3() : Direct2DNet::ID2D1DeviceContext2() {}

            ID2D1DeviceContext3(
                Direct2DNet::ID2D1Device3 ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );

        public:
            /// <summary>
            /// Creates a new sprite batch.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the sprite batch.
            /// </exception>
            Direct2DNet::ID2D1SpriteBatch ^CreateSpriteBatch();

            /// <summary>
            /// Renders part or all of the given sprite batch to the device context using the specified drawing
            /// options.
            /// </summary>
            /// <param name="spriteBatch">
            /// The sprite batch to draw.
            /// </param>
            /// <param name="startIndex">
            /// The index of the first sprite in the sprite batch to draw.
            /// </param>
            /// <param name="spriteCount">
            /// The number of sprites to draw.
            /// </param>
            /// <param name="bitmap">
            /// The bitmap from which the sprites are to be sourced. Each sprite's source rectangle refers to
            /// a portion of this bitmap.
            /// </param>
            /// <param name="interpolationMode">
            /// The interpolation mode to use when drawing this sprite batch. This determines how Direct2D
            /// interpolates pixels within the drawn sprites if scaling is performed. The default value is
            /// <see cref="Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE::LINEAR"/>.
            /// </param>
            /// <param name="spriteOptions">
            /// The additional drawing options, if any, to be used for this sprite batch. The default value is
            /// <see cref="Direct2DNet::D2D1_SPRITE_OPTIONS::NONE"/>.
            /// </param>
            void DrawSpriteBatch(
                Direct2DNet::ID2D1SpriteBatch ^spriteBatch,
                UINT32 startIndex,
                UINT32 spriteCount,
                Direct2DNet::ID2D1Bitmap ^bitmap,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE> interpolationMode,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_SPRITE_OPTIONS> spriteOptions
            );
        };
    }
}