#pragma once

#include "../IUnknown.h"
#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Image.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext2;
        ref class ID2D1ImageSource;

        // Done.

        /// <summary>
        /// Represents a producer of pixels that can fill an arbitrary 2D plane.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("7f1f79e5-2796-416c-8f55-700f911445e5")]
        public ref class ID2D1TransformedImageSource : Direct2DNet::ID2D1Image
        {
        private:
            Direct2DNet::ID2D1ImageSource ^m_source;
            Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES m_properties;

        internal:
            ID2D1TransformedImageSource() : Direct2DNet::ID2D1Image() {}

            ID2D1TransformedImageSource(
                Direct2DNet::ID2D1DeviceContext2 ^context,
                Direct2DNet::ID2D1ImageSource ^imageSource,
                Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES %properties
            );

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Gets the source image used to create the transformed image source.
            /// </summary>
            property Direct2DNet::ID2D1ImageSource ^Source
            {
                Direct2DNet::ID2D1ImageSource ^get();          
            }

            /// <summary>
            /// Gets the properties specified when the transformed image source was created.
            /// </summary>
            property Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES Properties
            {
                Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES get()
                {
                    return m_properties;
                }
            }
        };
    }
}