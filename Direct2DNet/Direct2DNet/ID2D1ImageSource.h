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
    namespace DXGINet
    {
        ref class IDXGISurface;
    }

    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext2;

        // Done.

        /// <summary>
        /// Represents a producer of pixels that can fill an arbitrary 2D plane.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("c9b664e5-74a1-4378-9ac2-eefc37a3f4d8")]
        public ref class ID2D1ImageSource : Direct2DNet::ID2D1Image
        {
        internal:
            ID2D1ImageSource() : Direct2DNet::ID2D1Image() {}

            ID2D1ImageSource(
                Direct2DNet::ID2D1DeviceContext2 ^context,
                array<DXGINet::IDXGISurface ^> ^surfaces,
                DXGINet::DXGI_COLOR_SPACE_TYPE colorSpace,
                Direct2DNet::D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS options
            );

        public:
            /// <summary>
            /// Allows the operating system to free the video memory of resources by discarding their content.
            /// </summary>
            /// <returns>
            /// S_OK if resources were successfully offered, E_INVALIDARG if a resource in the array or
            /// the priority is invalid.
            /// </returns>
            HRESULT OfferResources();

            /// <summary>
            /// Restores access to resources that were previously offered by calling OfferResources.
            /// </summary>
            /// <param name="resourcesDiscarded">
            /// Returns with true if the corresponding resource¡¯s content was discarded and is now undefined,
            /// or false if the corresponding resource¡¯s old content is still intact(out parameter).
            /// </param>
            /// <returns>
            /// S_OK if resources were successfully reclaimed, E_INVALIDARG if the resources are invalid.
            /// </returns>
            HRESULT TryReclaimResources(
                [OutAttribute] bool %resourcesDiscarded
            );
        };
    }
}