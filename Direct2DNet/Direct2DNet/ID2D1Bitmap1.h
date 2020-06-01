#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Bitmap.h"

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGISurface;
    }

    namespace Direct2DNet
    {
        ref class ID2D1ColorContext;

        /// <summary>
        /// Represents a bitmap that can be used as a surface for an ID2D1DeviceContext or
        /// mapped into system memory, and can contain additional color context information.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("5B40DE1D-5911-4498-A37D-4782F3E7F409")]
        public ref class ID2D1Bitmap1 : Direct2DNet::ID2D1Bitmap
        {
        private:
            Direct2DNet::ID2D1ColorContext ^m_colorContext;
            DXGINet::IDXGISurface ^m_dxgiSurface;
            Direct2DNet::D2D1_BITMAP_OPTIONS m_options;

        internal:
            ID2D1Bitmap1(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                Direct2DNet::D2D1_SIZE_U %size,
                void *sourceData,
                unsigned int pitch,
                Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties
            );

            ID2D1Bitmap1(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                DXGINet::IDXGISurface ^surface,
                Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties
            );

        public:
            /// <summary>
            /// Gets the color context information associated with the bitmap.
            /// </summary>
            property Direct2DNet::ID2D1ColorContext ^ColorContext
            {
                Direct2DNet::ID2D1ColorContext ^get()
                {
                    return m_colorContext;
                }
            }

            /// <summary>
            /// Gets the bitmap options used when creating the API.
            /// </summary>
            property Direct2DNet::D2D1_BITMAP_OPTIONS Options
            {
                Direct2DNet::D2D1_BITMAP_OPTIONS get()
                {
                    return m_options;
                }
            }

            /// <summary>
            /// Gets the DXGI surface from the corresponding bitmap, if the bitmap was
            /// created from a device derived from a D3D device. If there is no surface,
            /// null is returned.
            /// </summary>
            property DXGINet::IDXGISurface ^Surface
            {
                DXGINet::IDXGISurface ^get()
                {
                    return m_dxgiSurface;
                }
            }

            /// <summary>
            /// Maps the given bitmap into memory. The bitmap must have been created with the
            /// D2D1_BITMAP_OPTIONS_CPU_READ flag.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_ROUNDED_RECT"/>) tuple.
            /// If this method succeeds, HRESULT is S_OK(0). Otherwise, it is an error code.
            /// </returns>
            System::ValueTuple<HRESULT, Direct2DNet::D2D1_MAPPED_RECT> Map(
                Direct2DNet::D2D1_MAP_OPTIONS options
            );

            /// <summary>
            /// Maps the given bitmap into memory. The bitmap must have been created with the
            /// D2D1_BITMAP_OPTIONS_CPU_READ flag.
            /// </summary>
            /// <param name="mappedRect">Mapped rectangle(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT Map(
                Direct2DNet::D2D1_MAP_OPTIONS options,
                [OutAttribute] Direct2DNet::D2D1_MAPPED_RECT %mappedRect
            );

            /// <summary>
            /// Unmaps the given bitmap from memory.
            /// </summary>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT Unmap();
        };
    }
}