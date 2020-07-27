#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Brush.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1RenderTarget;
        ref class ID2D1Bitmap;
        ref class ID2D1DeviceContext;

        // Done.

        /// <summary>
        /// A bitmap brush allows a bitmap to be used to fill a geometry.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2cd906aa-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1BitmapBrush : Direct2DNet::ID2D1Brush
        {
        private:
            Direct2DNet::ID2D1Bitmap ^m_bitmap;

        internal:
            ID2D1BitmapBrush() : Direct2DNet::ID2D1Brush() {}

            ID2D1BitmapBrush(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                Direct2DNet::ID2D1Bitmap ^bitmap
            );

        protected:
            ID2D1BitmapBrush(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                Direct2DNet::ID2D1Bitmap ^bitmap
            );

        public:
            /// <summary>
            /// Gets and sets how the bitmap is to be treated outside of its natural extent on the X
            /// axis.
            /// </summary>
            property Direct2DNet::D2D1_EXTEND_MODE ExtendModeX
            {
                Direct2DNet::D2D1_EXTEND_MODE get()
                {
                    return (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1BitmapBrush *)m_pResource)->GetExtendModeX());
                }

                void set(Direct2DNet::D2D1_EXTEND_MODE value)
                {
                    ((::ID2D1BitmapBrush *)m_pResource)->SetExtendModeX((::D2D1_EXTEND_MODE)((int)value));
                }
            }

            /// <summary>
            /// Gets and sets how the bitmap is to be treated outside of its natural extent on the Y
            /// axis.
            /// </summary>
            property Direct2DNet::D2D1_EXTEND_MODE ExtendModeY
            {
                Direct2DNet::D2D1_EXTEND_MODE get()
                {
                    return (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1BitmapBrush *)m_pResource)->GetExtendModeY());
                }

                void set(Direct2DNet::D2D1_EXTEND_MODE value)
                {
                    ((::ID2D1BitmapBrush *)m_pResource)->SetExtendModeY((::D2D1_EXTEND_MODE)((int)value));
                }
            }

            /// <summary>
            /// Gets and sets how the bitmap is to be treated outside of its natural extent on the X
            /// and Y axis.
            /// </summary>
            property System::ValueTuple<Direct2DNet::D2D1_EXTEND_MODE, Direct2DNet::D2D1_EXTEND_MODE> ExtendMode
            {
                System::ValueTuple<Direct2DNet::D2D1_EXTEND_MODE, Direct2DNet::D2D1_EXTEND_MODE> get()
                {
                    return System::ValueTuple<Direct2DNet::D2D1_EXTEND_MODE, Direct2DNet::D2D1_EXTEND_MODE>(
                        (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1BitmapBrush *)m_pResource)->GetExtendModeX()),
                        (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1BitmapBrush *)m_pResource)->GetExtendModeY())
                        );
                }

                void set(System::ValueTuple<Direct2DNet::D2D1_EXTEND_MODE, Direct2DNet::D2D1_EXTEND_MODE> value)
                {
                    ((::ID2D1BitmapBrush *)m_pResource)->SetExtendModeX((::D2D1_EXTEND_MODE)((int)value.Item1));
                    ((::ID2D1BitmapBrush *)m_pResource)->SetExtendModeY((::D2D1_EXTEND_MODE)((int)value.Item2));
                }
            }

            /// <summary>
            /// Gets and sets the interpolation mode used when this brush is used.
            /// </summary>
            property Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE InterpolationMode
            {
                Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE get()
                {
                    return (Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE)((int)((::ID2D1BitmapBrush *)m_pResource)->GetInterpolationMode());
                }

                void set(Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE value)
                {
                    ((::ID2D1BitmapBrush *)m_pResource)->SetInterpolationMode((::D2D1_BITMAP_INTERPOLATION_MODE)((int)value));
                }
            }

            /// <summary>
            /// Gets and sets the bitmap associated as the source of this brush.
            /// </summary>
            property Direct2DNet::ID2D1Bitmap ^Bitmap
            {
                Direct2DNet::ID2D1Bitmap ^get()
                {
                    return m_bitmap;
                }

                void set(Direct2DNet::ID2D1Bitmap ^value);
            }
        };
    }
}