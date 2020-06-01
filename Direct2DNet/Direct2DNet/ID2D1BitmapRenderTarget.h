#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"
#include "ID2D1RenderTarget.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        // Done.
        ref class ID2D1RenderTarget;
        ref class ID2D1Bitmap;

        /// <summary>
        /// Renders to an intermediate texture created by the CreateCompatibleRenderTarget
        /// method.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("6DCB190A-D3EA-40CD-A21B-B5D31A84C8D7")]
        public ref class ID2D1BitmapRenderTarget : Direct2DNet::ID2D1RenderTarget
        {
        internal:
            ID2D1BitmapRenderTarget(
                Direct2DNet::ID2D1RenderTarget ^renderTarget,
                System::Nullable<Direct2DNet::D2D1_SIZE_F> %desiredSize,
                System::Nullable<Direct2DNet::D2D1_SIZE_U> %desiredPixelSize,
                System::Nullable<Direct2DNet::D2D1_PIXEL_FORMAT> %desiredFormat,
                Direct2DNet::D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options
            );

        public:
            System::ValueTuple<HRESULT, Direct2DNet::ID2D1Bitmap ^> GetBitmap();

            HRESULT GetBitmap([OutAttribute] ID2D1Bitmap ^%bitmap);
        };
    }
}