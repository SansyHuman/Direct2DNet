#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        // Done.

        /// <summary>
        /// Provides access to an device context that can accept GDI drawing commands.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("e0db51c3-6f77-4bae-b3d5-e47509b35838")]
        public ref class ID2D1GdiInteropRenderTarget : Direct2DNet::IDirect2DObject
        {
        internal:
            ::ID2D1GdiInteropRenderTarget *m_pRenderTarget;

            ID2D1GdiInteropRenderTarget() : m_pRenderTarget(nullptr) {}
            ID2D1GdiInteropRenderTarget(::ID2D1GdiInteropRenderTarget *pRenderTarget) : m_pRenderTarget(pRenderTarget) {}

        public:
            ~ID2D1GdiInteropRenderTarget();
            !ID2D1GdiInteropRenderTarget();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pRenderTarget;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Retrieves the device context associated with this render target.
            /// This command can be called only after BeginDraw and before EndDraw.
            /// </summary>
            /// <param name="mode">
            /// A value that specifies whether the device context should be cleared.
            /// </param>
            /// <param name="hdc">
            /// The device context associated with this render target(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetDC(
                Direct2DNet::D2D1_DC_INITIALIZE_MODE mode,
                [OutAttribute] System::IntPtr %hdc
            );

            /// <summary>
            /// Indicates that drawing with the device context retrieved using the GetDC method is finished.
            /// </summary>
            /// <param name="update">
            /// The modified region of the device context, or null to specify the entire render target.
            /// The default value is null.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT ReleaseDC(
                [OptionalAttribute] System::Nullable<D2DNet::RECT> update
            );
        };
    }
}