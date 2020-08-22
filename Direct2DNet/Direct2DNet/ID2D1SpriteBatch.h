#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext3;

        // Done.

        /// <summary>
        /// Represents a single group of sprites with their associated drawing properties.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("4dc583bf-3a10-438a-8722-e9765224f1f1")]
        public ref class ID2D1SpriteBatch : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1SpriteBatch() : Direct2DNet::ID2D1Resource() {}

            ID2D1SpriteBatch(Direct2DNet::ID2D1DeviceContext3 ^context);

        public:
            /// <summary>
            /// Adds sprites to the end of the sprite batch.
            /// </summary>
            /// <param name="spriteCount">
            /// The number of sprites to be added. This determines how many strides into each give
            /// array Direct2D will read.
            /// </param>
            /// <param name="destinationRectangles">
            /// An array containing the destination rectangles specifying where to draw the sprites on the
            /// destination device context.
            /// </param>
            /// <param name="sourceRectangles">
            /// An optional array containing the source rectangles specifying the regions of the source bitmap
            /// to draw as sprites. Direct2D will use the entire source bitmap for sprites that are assigned a
            /// null value or the InfiniteRectU. If this parameter is omitted entirely or set to a null value,
            /// then Direct2D will use the entire source bitmap for all the added sprites. The default value is
            /// null.
            /// </param>
            /// <param name="colors">
            /// An optional array containing the colors to apply to each sprite. The output color is the
            /// result of component-wise multiplication of the source bitmap color and the provided color.
            /// The output color is not clamped. Direct2D will not change the color of sprites that are
            /// assigned a null value. If this parameter is omitted entirely or set to a null value, then
            /// Direct2D will not change the color of any of the added sprites. The default value is null.
            /// </param>
            /// <param name="transforms">
            /// An optional array containing the transforms to apply to each sprite¡¯s destination rectangle.
            /// Direct2D will not transform the destination rectangle of any sprites that are assigned a null
            /// value. If this parameter is omitted entirely or set to a null value, then Direct2D will not
            /// transform the destination rectangle of any of the added sprites. The default value is null.
            /// </param>
            /// <param name="destinationRectanglesStride">
            /// Specifies the distance, in bytes, between each rectangle in the destinationRectangles array.
            /// If you provide a stride of 0, then the same destination rectangle will be used for each
            /// added sprite. The default value is sizeof(D2D1_RECT_F).
            /// </param>
            /// <param name="sourceRectanglesStride">
            /// Specifies the distance, in bytes, between each rectangle in the sourceRectangles array (if that
            /// array is given). If you provide a stride of 0, then the same source rectangle will be used
            /// for each added sprite. The default value is sizeof(D2D1_RECT_U).
            /// </param>
            /// <param name="colorsStride">
            /// Specifies the distance, in bytes, between each color in the colors array (if that array is
            /// given). If you provide a stride of 0, then the same color will be used for each added sprite.
            /// The default value is sizeof(D2D1_COLOR_F).
            /// </param>
            /// <param name="transformsStride">
            /// Specifies the distance, in bytes, between each transform in the transforms array (if that
            /// array is given). If you provide a stride of 0, then the same transform will be used for each
            /// added sprite. The default value is sizeof(D2D1_MATRIX_3X2_F).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT AddSprites(
                UINT32 spriteCount,
                array<Direct2DNet::D2D1_RECT_F> ^destinationRectangles,
                [OptionalAttribute] array<Direct2DNet::D2D1_RECT_U> ^sourceRectangles,
                [OptionalAttribute] array<Direct2DNet::D2D1_COLOR_F> ^colors,
                [OptionalAttribute] array<Direct2DNet::D2D1_MATRIX_3X2_F> ^transforms,
                [OptionalAttribute] System::Nullable<UINT32> destinationRectanglesStride,
                [OptionalAttribute] System::Nullable<UINT32> sourceRectanglesStride,
                [OptionalAttribute] System::Nullable<UINT32> colorsStride,
                [OptionalAttribute] System::Nullable<UINT32> transformsStride
            );

            /// <summary>
            /// Set properties for existing sprites. All properties not specified are
            /// unmodified.
            /// </summary>
            /// <param name="startIndex">
            /// The index of the first sprite in this sprite batch to update.
            /// </param>
            /// <param name="spriteCount">
            /// The number of sprites to be added. This determines how many strides into each give
            /// array Direct2D will read.
            /// </param>
            /// <param name="destinationRectangles">
            /// An optional array containing the destination rectangles specifying where to draw the sprites
            /// on the destination device context. The default value is null.
            /// </param>
            /// <param name="sourceRectangles">
            /// An optional array containing the source rectangles specifying the regions of the source bitmap
            /// to draw as sprites. Direct2D will use the entire source bitmap for sprites that are assigned a
            /// null value or the InfiniteRectU. If this parameter is omitted entirely or set to a null value,
            /// then Direct2D will use the entire source bitmap for all the added sprites. The default value is
            /// null.
            /// </param>
            /// <param name="colors">
            /// An optional array containing the colors to apply to each sprite. The output color is the
            /// result of component-wise multiplication of the source bitmap color and the provided color.
            /// The output color is not clamped. Direct2D will not change the color of sprites that are
            /// assigned a null value. If this parameter is omitted entirely or set to a null value, then
            /// Direct2D will not change the color of any of the added sprites. The default value is null.
            /// </param>
            /// <param name="transforms">
            /// An optional array containing the transforms to apply to each sprite¡¯s destination rectangle.
            /// Direct2D will not transform the destination rectangle of any sprites that are assigned a null
            /// value. If this parameter is omitted entirely or set to a null value, then Direct2D will not
            /// transform the destination rectangle of any of the added sprites. The default value is null.
            /// </param>
            /// <param name="destinationRectanglesStride">
            /// Specifies the distance, in bytes, between each rectangle in the destinationRectangles array.
            /// If you provide a stride of 0, then the same destination rectangle will be used for each
            /// added sprite. The default value is sizeof(D2D1_RECT_F).
            /// </param>
            /// <param name="sourceRectanglesStride">
            /// Specifies the distance, in bytes, between each rectangle in the sourceRectangles array (if that
            /// array is given). If you provide a stride of 0, then the same source rectangle will be used
            /// for each added sprite. The default value is sizeof(D2D1_RECT_U).
            /// </param>
            /// <param name="colorsStride">
            /// Specifies the distance, in bytes, between each color in the colors array (if that array is
            /// given). If you provide a stride of 0, then the same color will be used for each added sprite.
            /// The default value is sizeof(D2D1_COLOR_F).
            /// </param>
            /// <param name="transformsStride">
            /// Specifies the distance, in bytes, between each transform in the transforms array (if that
            /// array is given). If you provide a stride of 0, then the same transform will be used for each
            /// added sprite. The default value is sizeof(D2D1_MATRIX_3X2_F).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT SetSprites(
                UINT32 startIndex,
                UINT32 spriteCount,
                [OptionalAttribute] array<Direct2DNet::D2D1_RECT_F> ^destinationRectangles,
                [OptionalAttribute] array<Direct2DNet::D2D1_RECT_U> ^sourceRectangles,
                [OptionalAttribute] array<Direct2DNet::D2D1_COLOR_F> ^colors,
                [OptionalAttribute] array<Direct2DNet::D2D1_MATRIX_3X2_F> ^transforms,
                [OptionalAttribute] System::Nullable<UINT32> destinationRectanglesStride,
                [OptionalAttribute] System::Nullable<UINT32> sourceRectanglesStride,
                [OptionalAttribute] System::Nullable<UINT32> colorsStride,
                [OptionalAttribute] System::Nullable<UINT32> transformsStride
            );

            /// <summary>
            /// Retrieves sprite properties.
            /// </summary>
            /// <param name="startIndex">
            /// The index of the first sprite in this sprite batch to retrieve.
            /// </param>
            /// <param name="spriteCount">
            /// The number of sprites to retrieve.
            /// </param>
            /// <param name="destinationRectangles">
            /// An array buffer that receives the destination rectangles for the retrieved sprites.
            /// The default value is null.
            /// </param>
            /// <param name="sourceRectangles">
            /// An array buffer that receives the source rectangles for the retrieved sprites. The
            /// InfiniteRectU is returned for any sprites that were not assigned a source rectangle.
            /// The default value is null.
            /// </param>
            /// <param name="colors">
            /// An array buffer that receives the colors to be applied to the retrieved sprites. The colo
            /// { 1.0f, 1.0f, 1.0f, 1.0f } is returned for any sprites that were not assigned a color.
            /// The default value is null.
            /// </param>
            /// <param name="transforms">
            /// An array buffer that receives the transforms to be applied to the retrieved sprites.
            /// The identity matrix is returned for any sprites that were not assigned a transform.
            /// The default value is null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetSprites(
                UINT32 startIndex,
                UINT32 spriteCount,
                [OptionalAttribute] array<Direct2DNet::D2D1_RECT_F> ^destinationRectangles,
                [OptionalAttribute] array<Direct2DNet::D2D1_RECT_U> ^sourceRectangles,
                [OptionalAttribute] array<Direct2DNet::D2D1_COLOR_F> ^colors,
                [OptionalAttribute] array<Direct2DNet::D2D1_MATRIX_3X2_F> ^transforms
            );

            /// <summary>
            /// Retrieves the number of sprites in the sprite batch.
            /// </summary>
            property UINT32 SpriteCount
            {
                UINT32 get()
                {
                    return ((::ID2D1SpriteBatch *)m_pResource)->GetSpriteCount();
                }
            }

            /// <summary>
            /// Removes all sprites from the sprite batch.
            /// </summary>
            void Clear();
        };
    }
}