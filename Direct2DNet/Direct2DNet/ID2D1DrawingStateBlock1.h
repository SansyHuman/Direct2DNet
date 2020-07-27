#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1DrawingStateBlock.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteRenderingParams;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Factory1;

        /// <summary>
        /// Represents drawing state.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("689f1f85-c72e-4e33-8f19-85754efd5ace")]
        public ref class ID2D1DrawingStateBlock1 : Direct2DNet::ID2D1DrawingStateBlock
        {
        internal:
            ID2D1DrawingStateBlock1() : Direct2DNet::ID2D1DrawingStateBlock() {}

            ID2D1DrawingStateBlock1(
                Direct2DNet::ID2D1Factory1 ^factory,
                System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1> %description,
                DWriteNet::IDWriteRenderingParams ^params
            );

        public:
            /// <summary>
            /// Gets and sets the state currently contained within this state block resource.
            /// </summary>
            property Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1 Description1
            {
                Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1 get()
                {
                    ::D2D1_DRAWING_STATE_DESCRIPTION1 description;
                    ((::ID2D1DrawingStateBlock1 *)m_pResource)->GetDescription(&description);

                    return static_cast<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1>(description);
                }

                void set(Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1 value)
                {
                    ((::ID2D1DrawingStateBlock1 *)m_pResource)->SetDescription(
                        &static_cast<::D2D1_DRAWING_STATE_DESCRIPTION1>(value)
                    );
                }
            }
        };
    }
}