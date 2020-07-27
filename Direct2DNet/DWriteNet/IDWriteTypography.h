#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DWriteNet
    {
        // Done.

        ref class IDWriteFactory;

        /// <summary>
        /// Font typography setting.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("55f1112b-1dc2-4b3c-9541-f46894ed85b6")]
        public ref class IDWriteTypography : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteTypography *m_pTypo;

            IDWriteTypography() : m_pTypo(nullptr) {}

            IDWriteTypography(DWriteNet::IDWriteFactory ^factory);

            // Used in IDWriteTextLayout::GetTypography.
            IDWriteTypography(::IDWriteTypography *pTypo) : m_pTypo(pTypo) {}

        public:
            ~IDWriteTypography();
            !IDWriteTypography();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pTypo;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Adds font feature.
            /// </summary>
            /// <param name="fontFeature">The font feature to add.</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT AddFontFeature(
                [InAttribute][IsReadOnlyAttribute] DWriteNet::DWRITE_FONT_FEATURE %fontFeature
            );

            /// <summary>
            /// Gets the number of font features.
            /// </summary>
            property UINT32 FontFeatureCount
            {
                UINT32 get()
                {
                    return m_pTypo->GetFontFeatureCount();
                }
            }

            /// <summary>
            /// Gets the font feature at the specified index.
            /// </summary>
            /// <param name="fontFeatureIndex">The zero-based index of the font feature to get.</param>
            /// <param name="fontFeature">The font feature(out parameter).</param>
            /// <returns>
            /// Standard HRESULT error code.
            /// </returns>
            HRESULT GetFontFeature(
                UINT32 fontFeatureIndex,
                [OutAttribute] DWriteNet::DWRITE_FONT_FEATURE %fontFeature
            );

            /// <summary>
            /// Gets the font feature at the specified index.
            /// </summary>
            /// <param name="fontFeatureIndex">The zero-based index of the font feature to get.</param>
            /// <returns>
            /// (HRESULT, <see cref="DWriteNet::DWRITE_FONT_FEATURE"/>) tuple. HRESULT if an error code.
            /// <see cref="DWriteNet::DWRITE_FONT_FEATURE"/> is the font feature.
            /// </returns>
            System::ValueTuple<HRESULT, DWriteNet::DWRITE_FONT_FEATURE> GetFontFeature(
                UINT32 fontFeatureIndex
            );

            /// <summary>
            /// Gets the font feature at the specified index.
            /// </summary>
            /// <returns>
            /// Font feature. If failed, the font feature is {0, 0}.
            /// </returns>
            property DWriteNet::DWRITE_FONT_FEATURE default[UINT32]
            {
                DWriteNet::DWRITE_FONT_FEATURE get(UINT32 index);
            }
        };
    }
}