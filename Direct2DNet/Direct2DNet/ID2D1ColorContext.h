#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"
#include <msclr/marshal.h>

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext;
        ref class ID2D1Factory1;

        /// <summary>
        /// Represents a color context that can be used with an ID2D1Bitmap1 object.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("1c4820bb-5771-4518-a581-2fe4dd0ec657")]
        public ref class ID2D1ColorContext : Direct2DNet::ID2D1Resource
        {
        private:
            Direct2DNet::D2D1_COLOR_SPACE m_space;
            array<unsigned char> ^m_profile;

        internal:
            ID2D1ColorContext() : Direct2DNet::ID2D1Resource() {}

            ID2D1ColorContext(
                Direct2DNet::ID2D1DeviceContext ^context,
                Direct2DNet::D2D1_COLOR_SPACE space,
                array<unsigned char> ^profile
            );

            ID2D1ColorContext(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                System::String ^filename
            );

            ID2D1ColorContext(Direct2DNet::ID2D1Factory1 ^factory, ::ID2D1ColorContext *pContext);

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Gets the color space of the color context.
            /// </summary>
            property Direct2DNet::D2D1_COLOR_SPACE ColorSpace
            {
                Direct2DNet::D2D1_COLOR_SPACE get()
                {
                    return m_space;
                }
            }

            /// <summary>
            /// Gets the color profile bytes.
            /// </summary>
            property array<unsigned char> ^Profile
            {
                array<unsigned char> ^get()
                {
                    if(m_profile == nullptr)
                        return nullptr;

                    array<unsigned char> ^value = gcnew array<unsigned char>(m_profile->Length);
                    m_profile->CopyTo(value, 0);

                    return value;
                }
            }
        };
    }
}