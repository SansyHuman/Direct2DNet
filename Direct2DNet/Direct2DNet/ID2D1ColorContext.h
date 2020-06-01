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

        /// <summary>
        /// Represents a color context that can be used with an ID2D1Bitmap1 object.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("24A02A55-B0D8-4ED1-A96C-E060A49601F9")]
        public ref class ID2D1ColorContext : Direct2DNet::ID2D1Resource
        {
        private:
            Direct2DNet::D2D1_COLOR_SPACE m_space;
            array<unsigned char> ^m_profile;

        internal:
            ID2D1ColorContext(
                Direct2DNet::ID2D1DeviceContext ^context,
                Direct2DNet::D2D1_COLOR_SPACE space,
                array<unsigned char> ^profile
            );

            ID2D1ColorContext(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                System::String ^filename
            );

        public:
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
                    array<unsigned char> ^value = gcnew array<unsigned char>(m_profile->Length);
                    m_profile->CopyTo(value, 0);

                    return value;
                }
            }
        };
    }
}