#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "../DXCommonSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DWriteNet
    {
        // Done.

        ref class IDWriteRenderingParams;

        /// <summary>
        /// Encapsulates a 32-bit device independent bitmap and device context, which can be used for
        /// rendering glyphs.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("5e5a32a3-8dff-4773-9ff6-0696eab77267")]
        public interface class IDWriteBitmapRenderTarget : DWriteNet::IDirectWriteObject
        {
        public:
            /// <summary>
            /// Draws a run of glyphs to the bitmap.
            /// </summary>
            /// <param name="baselineOriginX">Horizontal position of the baseline origin, in DIPs, relative
            /// to the upper-left corner of the DIB.</param>
            /// <param name="baselineOriginY">Vertical position of the baseline origin, in DIPs, relative
            /// to the upper-left corner of the DIB.</param>
            /// <param name="measuringMode">Specifies measuring mode for glyphs in the run.
            /// Renderer implementations may choose different rendering modes for different measuring
            /// modes, for example
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_NATURAL"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::NATURAL"/>
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_GDI_CLASSIC"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::GDI_CLASSIC"/>
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::CLEARTYPE_GDI_NATURAL"/> for
            /// <see cref="DWriteNet::DWRITE_RENDERING_MODE::GDI_NATURAL"/>
            /// </param>
            /// <param name="glyphRun">Structure containing the properties of the glyph run.</param>
            /// <param name="renderingParams">Object that controls rendering behavior.</param>
            /// <param name="textColor">Specifies the foreground color of the text.</param>
            /// <param name="blackBoxRect">Rectangle that receives the bounding box (in pixels
            /// not DIPs) of all the pixels affected by drawing the glyph run. The black box rectangle
            /// may extend beyond the dimensions of the bitmap.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT DrawGlyphRun(
                float baselineOriginX,
                float baselineOriginY,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode,
                DWriteNet::DWRITE_GLYPH_RUN glyphRun,
                DWriteNet::IDWriteRenderingParams ^renderingParams,
                COLORREF textColor,
                [OutAttribute] D2DNet::RECT %blackBoxRect
            );

            /// <summary>
            /// Gets a handle to the memory device context.
            /// </summary>
            /// <returns>
            /// Returns the device context handle.
            /// </returns>
            /// <remarks>
            /// An application can use the device context to draw using GDI functions. An application
            /// can obtain the bitmap handle by calling GetCurrentObject. An application that wants
            /// information about the underlying bitmap, including a pointer to the pixel data, can call
            /// GetObject to fill in a DIBSECTION structure. The bitmap is always a 32-bit 
            /// top-down DIB.
            /// </remarks>
            property System::IntPtr MemoryDC
            {
                System::IntPtr get();
            }

            /// <summary>
            /// Gets the number of bitmap pixels per DIP. A DIP (device-independent pixel) is 1/96 inch so
            /// this value is the number if pixels per inch divided by 96.
            /// </summary>
            /// <returns>
            /// Returns the number of bitmap pixels per DIP.
            /// </returns>
            float GetPixelsPerDip();

            /// <summary>
            /// Sets the number of bitmap pixels per DIP. A DIP (device-independent pixel) is 1/96 inch so
            /// this value is the number if pixels per inch divided by 96.
            /// </summary>
            /// <param name="pixelsPerDip">Specifies the number of pixels per DIP.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetPixelsPerDip(float pixelsPerDip);

            /// <summary>
            /// Gets the transform that maps abstract coordinate to DIPs. By default this is the identity 
            /// transform. Note that this is unrelated to the world transform of the underlying device
            /// context.
            /// </summary>
            /// <param name="transform">Receives the transform(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetCurrentTransform([OutAttribute] DWriteNet::DWRITE_MATRIX %transform);

            /// <summary>
            /// Sets the transform that maps abstract coordinate to DIPs. This does not affect the world
            /// transform of the underlying device context.
            /// </summary>
            /// <param name="transform">Specifies the new transform. This parameter can be null, in which
            /// case the identity transform is implied.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT SetCurrentTransform(
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform
            );

            /// <summary>
            /// Gets the dimensions of the bitmap.
            /// </summary>
            /// <param name="size">Receives the size of the bitmap in pixels(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetSize([OutAttribute] D2DNet::SIZE %size);

            /// <summary>
            /// Resizes the bitmap.
            /// </summary>
            /// <param name="width">New bitmap width, in pixels.</param>
            /// <param name="height">New bitmap height, in pixels.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT Resize(UINT32 width, UINT32 height);
        };

        ref class IDWriteGdiInterop;

        ref class GdiInteropBitmapRenderTarget : DWriteNet::IDWriteBitmapRenderTarget
        {
        internal:
            ::IDWriteBitmapRenderTarget *m_pTarget;

            GdiInteropBitmapRenderTarget(
                DWriteNet::IDWriteGdiInterop ^interop,
                System::IntPtr %hdc,
                UINT32 width,
                UINT32 height
            );

        public:
            ~GdiInteropBitmapRenderTarget();
            !GdiInteropBitmapRenderTarget();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pTarget;
                }
            }

            virtual void HandleCOMInterface(void *obj) sealed;

            virtual HRESULT DrawGlyphRun(
                float baselineOriginX,
                float baselineOriginY,
                DWriteNet::DWRITE_MEASURING_MODE measuringMode,
                DWriteNet::DWRITE_GLYPH_RUN glyphRun,
                DWriteNet::IDWriteRenderingParams ^renderingParams,
                COLORREF textColor,
                [OutAttribute] D2DNet::RECT %blackBoxRect
            );

            virtual property System::IntPtr MemoryDC
            {
                virtual System::IntPtr get()
                {
                    return System::IntPtr(m_pTarget->GetMemoryDC());
                }
            }

            virtual float GetPixelsPerDip();

            virtual HRESULT SetPixelsPerDip(float pixelsPerDip);

            virtual HRESULT GetCurrentTransform([OutAttribute] DWriteNet::DWRITE_MATRIX %transform);

            virtual HRESULT SetCurrentTransform(
                [OptionalAttribute] System::Nullable<DWriteNet::DWRITE_MATRIX> transform
            );

            virtual HRESULT GetSize([OutAttribute] D2DNet::SIZE %size);

            virtual HRESULT Resize(UINT32 width, UINT32 height);
        };
    }
}