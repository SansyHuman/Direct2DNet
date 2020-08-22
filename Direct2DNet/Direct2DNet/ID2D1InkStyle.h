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
        ref class ID2D1DeviceContext2;

        // Done.

        /// <summary>
        /// Represents a collection of style properties to be used by methods like
        /// ID2D1DeviceContext2::DrawInk when rendering ink. The ink style defines the nib
        /// (pen tip) shape and transform.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("bae8b344-23fc-4071-8cb5-d05d6f073848")]
        public ref class ID2D1InkStyle : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1InkStyle() : Direct2DNet::ID2D1Resource() {}

            ID2D1InkStyle(
                Direct2DNet::ID2D1DeviceContext2 ^context,
                System::Nullable<Direct2DNet::D2D1_INK_STYLE_PROPERTIES> %prop
            );

        public:
            /// <summary>
            /// Gets and sets the transform to be applied to this style's nib shape.
            /// </summary>
            property Direct2DNet::D2D1_MATRIX_3X2_F NibTransform
            {
                Direct2DNet::D2D1_MATRIX_3X2_F get()
                {
                    Direct2DNet::D2D1_MATRIX_3X2_F value;
                    ((::ID2D1InkStyle *)m_pResource)->GetNibTransform(
                        (::D2D1_MATRIX_3X2_F *)&value
                    );
                    return value;
                }

                void set(Direct2DNet::D2D1_MATRIX_3X2_F value)
                {
                    ((::ID2D1InkStyle *)m_pResource)->SetNibTransform(
                        (::D2D1_MATRIX_3X2_F *)&value
                    );
                }
            }

            /// <summary>
            /// Gets and sets the pre-transform nib shape for this style.
            /// </summary>
            property Direct2DNet::D2D1_INK_NIB_SHAPE NibShape
            {
                Direct2DNet::D2D1_INK_NIB_SHAPE get()
                {
                    return (Direct2DNet::D2D1_INK_NIB_SHAPE)((int)((::ID2D1InkStyle *)m_pResource)->GetNibShape());
                }

                void set(Direct2DNet::D2D1_INK_NIB_SHAPE value)
                {
                    ((::ID2D1InkStyle *)m_pResource)->SetNibShape((::D2D1_INK_NIB_SHAPE)((int)value));
                }
            }
        };
    }
}