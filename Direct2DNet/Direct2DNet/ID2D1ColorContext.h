#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"
#include <msclr/marshal.h>

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICColorContext;
    }

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

            ID2D1ColorContext(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                D2DNet::WICNet::IWICColorContext ^wicColorContext
            );

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

            property UINT32 ProfileSize
            {
                UINT32 get()
                {
                    return ((::ID2D1ColorContext *)m_pResource)->GetProfileSize();
                }
            }

            /// <summary>
            /// Retrieves the color profile bytes.
            /// </summary>
            /// <param name="profileBuffer">The array to retrieve the profile bytes.</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetProfile(
                array<unsigned char> ^profileBuffer
            );
        };
    }
}