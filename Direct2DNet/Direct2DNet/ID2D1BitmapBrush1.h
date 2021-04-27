#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1BitmapBrush.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext;
        ref class ID2D1Bitmap;

        // Done.

        /// <summary>
        /// Paints an area with a bitmap.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("41343a53-e41a-49a2-91cd-21793bbb62e5")]
        public ref class ID2D1BitmapBrush1 : Direct2DNet::ID2D1BitmapBrush
        {
        internal:
            ID2D1BitmapBrush1() : Direct2DNet::ID2D1BitmapBrush() {}

            ID2D1BitmapBrush1(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                Direct2DNet::ID2D1Bitmap ^bitmap
            );

        public:
            /// <summary>
            /// Gets and sets the interpolation mode used when this brush is used.
            /// </summary>
            property Direct2DNet::D2D1_INTERPOLATION_MODE InterpolationMode1
            {
                Direct2DNet::D2D1_INTERPOLATION_MODE get()
                {
                    return (Direct2DNet::D2D1_INTERPOLATION_MODE)((int)((::ID2D1BitmapBrush1 *)m_pResource)->GetInterpolationMode1());
                }

                void set(Direct2DNet::D2D1_INTERPOLATION_MODE value)
                {
                    ((::ID2D1BitmapBrush1 *)m_pResource)->SetInterpolationMode1((::D2D1_INTERPOLATION_MODE)((int)value));
                }
            }
        };
    }
}