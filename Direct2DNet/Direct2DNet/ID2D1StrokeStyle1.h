#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1StrokeStyle.h"


namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1Factory1;

        // Done.

        /// <summary>
        /// Extends a stroke style to allow nominal width strokes.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("10a72a66-e91c-43f4-993f-ddf4b82b0b4a")]
        public ref class ID2D1StrokeStyle1 : Direct2DNet::ID2D1StrokeStyle
        {
        private:
            Direct2DNet::D2D1_STROKE_TRANSFORM_TYPE m_transformType;

        internal:
            ID2D1StrokeStyle1() : Direct2DNet::ID2D1StrokeStyle() {}

            ID2D1StrokeStyle1(
                Direct2DNet::ID2D1Factory1 ^factory,
                Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 %properties,
                array<float> ^dashes
            );

        public:
            virtual void HandleCOMInterface(void *obj) override;

            property Direct2DNet::D2D1_STROKE_TRANSFORM_TYPE StrokeTransformType
            {
                Direct2DNet::D2D1_STROKE_TRANSFORM_TYPE get()
                {
                    return m_transformType;
                }
            }
        };
    }
}