#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteRenderingParams;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Factory;
        ref class ID2D1Factory1;

        /// <summary>
        /// Represents the drawing state of a render target: the antialiasing mode,
        /// transform, tags, and text-rendering options.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("28506e39-ebf6-46a1-bb47-fd85565ab957")]
        public ref class ID2D1DrawingStateBlock : Direct2DNet::ID2D1Resource
        {
        private:
            DWriteNet::IDWriteRenderingParams ^m_params = nullptr;

        internal:
            ID2D1DrawingStateBlock(
                Direct2DNet::ID2D1Factory ^factory,
                System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION> %description,
                DWriteNet::IDWriteRenderingParams ^params
            );

        protected:
            // Used by ID2D1DrawingStateBlock1
            ID2D1DrawingStateBlock(
                Direct2DNet::ID2D1Factory1 ^factory
            );

        public:
            /// <summary>
            /// Gets and sets the state description of this state block resource.
            /// </summary>
            property Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION Description
            {
                Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION get()
                {
                    ::D2D1_DRAWING_STATE_DESCRIPTION description;
                    ((::ID2D1DrawingStateBlock *)m_pResource)->GetDescription(&description);

                    return static_cast<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION>(description);
                }

                void set(Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION value)
                {
                    ((::ID2D1DrawingStateBlock *)m_pResource)->SetDescription(
                        static_cast<::D2D1_DRAWING_STATE_DESCRIPTION>(value)
                    );
                }
            }

            /// <summary>
            /// Gets and sets the text rendering parameters of this state block resource.
            /// If you set the rendering parameters to null, it will use the default settings.
            /// </summary>
            property DWriteNet::IDWriteRenderingParams ^TextRenderingParams
            {
                DWriteNet::IDWriteRenderingParams ^get()
                {
                    return m_params;
                }

                void set(DWriteNet::IDWriteRenderingParams ^value);
            }
        };
    }
}