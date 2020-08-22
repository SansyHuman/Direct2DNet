#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Brush.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext;
        ref class ID2D1Image;

        [System::Runtime::InteropServices::GuidAttribute("fe9e984d-3f95-407c-b5db-cb94d4e8f87c")]
        public ref class ID2D1ImageBrush : Direct2DNet::ID2D1Brush
        {
        private:
            Direct2DNet::ID2D1Image ^m_image;

        internal:
            ID2D1ImageBrush() : Direct2DNet::ID2D1Brush() {}

            ID2D1ImageBrush(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                Direct2DNet::ID2D1Image ^image,
                Direct2DNet::D2D1_IMAGE_BRUSH_PROPERTIES %properties
            );

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Gets and sets the image associated as the source of this brush.
            /// </summary>
            property Direct2DNet::ID2D1Image ^Image
            {
                Direct2DNet::ID2D1Image ^get()
                {
                    return m_image;
                }

                void set(Direct2DNet::ID2D1Image ^value);
            }

            /// <summary>
            /// Gets and sets how the image is to be treated outside of its natural extent on the X
            /// axis.
            /// </summary>
            property Direct2DNet::D2D1_EXTEND_MODE ExtendModeX
            {
                Direct2DNet::D2D1_EXTEND_MODE get()
                {
                    return (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1ImageBrush *)m_pResource)->GetExtendModeX());
                }

                void set(Direct2DNet::D2D1_EXTEND_MODE value)
                {
                    ((::ID2D1ImageBrush *)m_pResource)->SetExtendModeX((::D2D1_EXTEND_MODE)((int)value));
                }
            }

            /// <summary>
            /// Gets and sets how the image is to be treated outside of its natural extent on the Y
            /// axis.
            /// </summary>
            property Direct2DNet::D2D1_EXTEND_MODE ExtendModeY
            {
                Direct2DNet::D2D1_EXTEND_MODE get()
                {
                    return (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1ImageBrush *)m_pResource)->GetExtendModeY());
                }

                void set(Direct2DNet::D2D1_EXTEND_MODE value)
                {
                    ((::ID2D1ImageBrush *)m_pResource)->SetExtendModeY((::D2D1_EXTEND_MODE)((int)value));
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
                        (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1ImageBrush *)m_pResource)->GetExtendModeX()),
                        (Direct2DNet::D2D1_EXTEND_MODE)((int)((::ID2D1ImageBrush *)m_pResource)->GetExtendModeY())
                        );
                }

                void set(System::ValueTuple<Direct2DNet::D2D1_EXTEND_MODE, Direct2DNet::D2D1_EXTEND_MODE> value)
                {
                    ((::ID2D1ImageBrush *)m_pResource)->SetExtendModeX((::D2D1_EXTEND_MODE)((int)value.Item1));
                    ((::ID2D1ImageBrush *)m_pResource)->SetExtendModeY((::D2D1_EXTEND_MODE)((int)value.Item2));
                }
            }

            /// <summary>
            /// Gets and sets the interpolation mode used when this brush is used.
            /// </summary>
            property Direct2DNet::D2D1_INTERPOLATION_MODE InterpolationMode
            {
                Direct2DNet::D2D1_INTERPOLATION_MODE get()
                {
                    return (Direct2DNet::D2D1_INTERPOLATION_MODE)((int)((::ID2D1ImageBrush *)m_pResource)->GetInterpolationMode());
                }

                void set(Direct2DNet::D2D1_INTERPOLATION_MODE value)
                {
                    ((::ID2D1ImageBrush *)m_pResource)->SetInterpolationMode((::D2D1_INTERPOLATION_MODE)((int)value));
                }
            }

            /// <summary>
            /// Gets and sets the source rectangle in the image brush.
            /// </summary>
            property Direct2DNet::D2D1_RECT_F SourceRectangle
            {
                Direct2DNet::D2D1_RECT_F get()
                {
                    Direct2DNet::D2D1_RECT_F rect;
                    ((::ID2D1ImageBrush *)m_pResource)->GetSourceRectangle((::D2D1_RECT_F *)&rect);

                    return rect;
                }

                void set(Direct2DNet::D2D1_RECT_F value)
                {
                    ((::ID2D1ImageBrush *)m_pResource)->SetSourceRectangle(
                        reinterpret_cast<::D2D1_RECT_F *>(&value)
                    );
                }
            }
        };
    }
}