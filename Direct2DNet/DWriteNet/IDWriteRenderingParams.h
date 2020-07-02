#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;

        /// <summary>
        /// The interface that represents text rendering settings for glyph rasterization and filtering.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2f0da53a-2add-47cd-82ee-d9ec34688e75")]
        public ref class IDWriteRenderingParams : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteRenderingParams *m_pParams;

            IDWriteRenderingParams(DWriteNet::IDWriteFactory ^factory); // CreateRenderingParams

            IDWriteRenderingParams(
                DWriteNet::IDWriteFactory ^factory,
                System::IntPtr %monitor
            ); // CreateMonitorRenderingParams

            IDWriteRenderingParams(
                DWriteNet::IDWriteFactory ^factory,
                float gamma,
                float enhancedContrast,
                float clearTypeLevel,
                DWriteNet::DWRITE_PIXEL_GEOMETRY pixelGeometry,
                DWriteNet::DWRITE_RENDERING_MODE renderingMode
            ); // CreateCustomRenderingParams

            // Used in ID2D1CommandSink
            IDWriteRenderingParams(::IDWriteRenderingParams *pParams) : m_pParams(pParams) {}

            ~IDWriteRenderingParams();
            !IDWriteRenderingParams();

        public:
            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pParams;
                }
            }

            /// <summary>
            /// Gets the gamma value used for gamma correction. Valid values must be
            /// greater than zero and cannot exceed 256.
            /// </summary>
            property float Gamma
            {
                float get()
                {
                    return m_pParams->GetGamma();
                }
            }

            /// <summary>
            /// Gets the amount of contrast enhancement. Valid values are greater than
            /// or equal to zero.
            /// </summary>
            property float EnhancedContrast
            {
                float get()
                {
                    return m_pParams->GetEnhancedContrast();
                }
            }

            /// <summary>
            /// Gets the ClearType level. Valid values range from 0.0f (no ClearType) 
            /// to 1.0f (full ClearType).
            /// </summary>
            property float ClearTypeLevel
            {
                float get()
                {
                    return m_pParams->GetClearTypeLevel();
                }
            }

            /// <summary>
            /// Gets the pixel geometry.
            /// </summary>
            property DWriteNet::DWRITE_PIXEL_GEOMETRY PixelGeometry
            {
                DWriteNet::DWRITE_PIXEL_GEOMETRY get()
                {
                    return (DWriteNet::DWRITE_PIXEL_GEOMETRY)((int)m_pParams->GetPixelGeometry());
                }
            }

            /// <summary>
            /// Gets the rendering mode.
            /// </summary>
            property DWriteNet::DWRITE_RENDERING_MODE RenderingMode
            {
                DWriteNet::DWRITE_RENDERING_MODE get()
                {
                    return (DWriteNet::DWRITE_RENDERING_MODE)((int)m_pParams->GetRenderingMode());
                }
            }
        };
    }
}