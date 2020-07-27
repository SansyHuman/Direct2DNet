#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1RenderTarget.h"
#include "../DXCommonSettings.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1Factory;

        // Done.

        /// <summary>
        /// Issues drawing commands to a GDI device context.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("1c51bc64-de61-46fd-9899-63a5d8f03950")]
        public ref class ID2D1DCRenderTarget : Direct2DNet::ID2D1RenderTarget
        {
        internal:
            ID2D1DCRenderTarget() : Direct2DNet::ID2D1RenderTarget() {}

            ID2D1DCRenderTarget(
                Direct2DNet::ID2D1Factory ^factory,
                Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %properties
            );

        public:
            /// <summary>
            /// Draws the text within the given layout rectangle and by default also performs
            /// baseline snapping.
            /// </summary>
            /// <param name="hDC">The device context to which the render target issues drawing commands.
            /// </param>
            /// <param name="subRect">The dimensions of the handle to a device context (HDC) to which
            /// the render target is bound.</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT BindDC(
                [InAttribute][IsReadOnlyAttribute] System::IntPtr %hDC,
                [InAttribute][IsReadOnlyAttribute] D2DNet::RECT %subRect
            );
        };
    }
}