#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"
#include "ID2D1RenderTarget.h"

namespace Direct2DNet
{
    // Done.
    ref class ID2D1Factory;

    /// <summary>
    /// Renders drawing instructions to a window.
    /// </summary>
    [System::Runtime::InteropServices::GuidAttribute("A804A679-80D3-43FE-93D5-75171B3427E2")]
    public ref class ID2D1HwndRenderTarget : ID2D1RenderTarget
    {
    internal:
        ID2D1HwndRenderTarget(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties,
            Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES %hwndRenderTargetProperties
        );

    public:
        /// <summary>
        /// Gets the current state of the window.
        /// </summary>
        property Direct2DNet::D2D1_WINDOW_STATE WindowState
        {
            Direct2DNet::D2D1_WINDOW_STATE get()
            {
                ::ID2D1HwndRenderTarget *pRenderTarget = (::ID2D1HwndRenderTarget *)m_pResource;
                return (Direct2DNet::D2D1_WINDOW_STATE)((int)pRenderTarget->CheckWindowState());
            }
        }

        /// <summary>
        /// Resize the buffer underlying the render target. This operation might fail if
        /// there is insufficient video memory or system memory, or if the render target is
        /// resized beyond the maximum bitmap size. If the method fails, the render target
        /// will be placed in a zombie state and D2DERR_RECREATE_TARGET will be returned
        /// from it when EndDraw is called. In addition an appropriate failure result will
        /// be returned from Resize.
        /// </summary>
        /// <returns>
        /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
        /// </returns>
        HRESULT Resize(Direct2DNet::D2D1_SIZE_U pixelSize);

        /// <summary>
        /// Resize the buffer underlying the render target. This operation might fail if
        /// there is insufficient video memory or system memory, or if the render target is
        /// resized beyond the maximum bitmap size. If the method fails, the render target
        /// will be placed in a zombie state and D2DERR_RECREATE_TARGET will be returned
        /// from it when EndDraw is called. In addition an appropriate failure result will
        /// be returned from Resize.
        /// </summary>
        /// <returns>
        /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
        /// </returns>
        HRESULT Resize(unsigned int pixelWidth, unsigned int pixelHeight);

        /// <summary>
        /// Gets the handle to the window the render target renders to.
        /// </summary>
        property System::IntPtr HWND
        {
            System::IntPtr get()
            {
                return System::IntPtr(((::ID2D1HwndRenderTarget *)m_pResource)->GetHwnd());
            }
        }
    };
}