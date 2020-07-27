#include "IDWriteFactory.h"
#include "IDWriteFontCollection.h"
#include "IDWriteFontFile.h"
#include "IDWriteFontFace.h"
#include "IDWriteRenderingParams.h"
#include "IDWriteTextFormat.h"
#include "IDWriteTypography.h"
#include "IDWriteGdiInterop.h"
#include "IDWriteTextLayout.h"
#include "IDWriteInlineObject.h"
#include "IDWriteTextAnalyzer.h"
#include "IDWriteNumberSubstitution.h"
#include "IDWriteGlyphRunAnalysis.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteFactory::IDWriteFactory(DWriteNet::DWRITE_FACTORY_TYPE factoryType)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IDWriteFactory *> ppFactory = &m_pFactory;
            hr = ::DWriteCreateFactory(
                (::DWRITE_FACTORY_TYPE)((int)factoryType),
                __uuidof(m_pFactory),
                (::IUnknown **)ppFactory);
            ppFactory = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteFactory.", (int)hr);
        }

        IDWriteFactory::~IDWriteFactory()
        {
            this->!IDWriteFactory();
        }

        IDWriteFactory::!IDWriteFactory()
        {
            if(m_pFactory)
            {
                m_pFactory->Release();
                m_pFactory = nullptr;
            }
        }

        DWriteNet::IDWriteFactory ^IDWriteFactory::CreateFactory(DWriteNet::DWRITE_FACTORY_TYPE factoryType)
        {
            return gcnew DWriteNet::IDWriteFactory(factoryType);
        }

        void IDWriteFactory::HandleCOMInterface(void *obj)
        {
            if(m_pFactory)
            {
                m_pFactory->Release();
            }

            m_pFactory = (::IDWriteFactory *)obj;
            m_pFactory->AddRef();
        }

        HRESULT IDWriteFactory::GetSystemFontCollection(
            DWriteNet::IDWriteFontCollection ^%fontCollection,
            System::Nullable<bool> checkForUpdates)
        {
            if(!checkForUpdates.HasValue)
                checkForUpdates = false;

            ::IDWriteFontCollection *pCollection = __nullptr;

            HRESULT hr = m_pFactory->GetSystemFontCollection(
                &pCollection,
                System::Convert::ToInt32(checkForUpdates.Value)
            );

            if(FAILED(hr))
            {
                fontCollection = nullptr;
                return hr;
            }

            fontCollection = gcnew DWriteNet::IDWriteFontCollection(pCollection);
            return hr;
        }

        System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^> IDWriteFactory::GetSystemFontCollection(System::Nullable<bool> checkForUpdates)
        {
            if(!checkForUpdates.HasValue)
                checkForUpdates = false;

            ::IDWriteFontCollection *pCollection = __nullptr;

            HRESULT hr = m_pFactory->GetSystemFontCollection(
                &pCollection,
                System::Convert::ToInt32(checkForUpdates.Value)
            );

            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^>(hr, nullptr);
            }

            return System::ValueTuple<HRESULT, DWriteNet::IDWriteFontCollection ^>(
                hr,
                gcnew DWriteNet::IDWriteFontCollection(pCollection)
                );
        }

        DWriteNet::IDWriteFontFile ^IDWriteFactory::CreateFontFileReference(
            System::String ^filePath,
            System::Nullable<InteropServices::ComTypes::FILETIME> lastWriteTime)
        {
            return gcnew DWriteNet::IDWriteFontFile(this, filePath, lastWriteTime);
        }

        DWriteNet::IDWriteFontFace ^IDWriteFactory::CreateFontFace(
            DWriteNet::DWRITE_FONT_FACE_TYPE fontFaceType,
            array<DWriteNet::IDWriteFontFile ^> ^fontFiles,
            UINT32 faceIndex,
            DWriteNet::DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags)
        {
            return gcnew DWriteNet::IDWriteFontFace(this, fontFaceType, fontFiles, faceIndex, fontFaceSimulationFlags);
        }

        DWriteNet::IDWriteRenderingParams ^IDWriteFactory::CreateRenderingParams()
        {
            return gcnew DWriteNet::IDWriteRenderingParams(this);
        }

        DWriteNet::IDWriteRenderingParams ^IDWriteFactory::CreateMonitorRenderingParams(
            System::IntPtr %monitor)
        {
            return gcnew DWriteNet::IDWriteRenderingParams(this, monitor);
        }

        DWriteNet::IDWriteRenderingParams ^IDWriteFactory::CreateCustomRenderingParams(
            float gamma, 
            float enhancedContrast, 
            float clearTypeLevel, 
            DWriteNet::DWRITE_PIXEL_GEOMETRY pixelGeometry, 
            DWriteNet::DWRITE_RENDERING_MODE renderingMode)
        {
            return gcnew DWriteNet::IDWriteRenderingParams(this,
                gamma,
                enhancedContrast,
                clearTypeLevel,
                pixelGeometry,
                renderingMode
            );
        }

        DWriteNet::IDWriteTextFormat ^IDWriteFactory::CreateTextFormat(
            System::String ^fontFamilyName,
            DWriteNet::DWRITE_FONT_WEIGHT fontWeight,
            DWriteNet::DWRITE_FONT_STYLE fontStyle,
            DWriteNet::DWRITE_FONT_STRETCH fontStretch,
            float fontSize,
            System::String ^localeName)
        {
            return gcnew DWriteNet::IDWriteTextFormat(
                this,
                fontFamilyName,
                fontWeight,
                fontStyle,
                fontStretch,
                fontSize,
                localeName
            );
        }

        DWriteNet::IDWriteTypography ^IDWriteFactory::CreateTypography()
        {
            return gcnew DWriteNet::IDWriteTypography(this);
        }

        DWriteNet::IDWriteGdiInterop ^IDWriteFactory::GetGdiInterop()
        {
            return gcnew DWriteNet::IDWriteGdiInterop(this);
        }

        DWriteNet::IDWriteTextLayout ^IDWriteFactory::CreateTextLayout(
            System::String ^string,
            DWriteNet::IDWriteTextFormat ^textFormat,
            float maxWidth,
            float maxHeight)
        {
            return gcnew DWriteNet::IDWriteTextLayout(this, string, textFormat, maxWidth, maxHeight);
        }

        DWriteNet::IDWriteTextLayout ^IDWriteFactory::CreateGdiCompatibleTextLayout(
            System::String ^string,
            DWriteNet::IDWriteTextFormat ^textFormat,
            float layoutWidth,
            float layoutHeight,
            float pixelsPerDip,
            bool useGdiNatural,
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform)
        {
            return gcnew DWriteNet::IDWriteTextLayout(
                this,
                string,
                textFormat,
                layoutWidth,
                layoutHeight,
                pixelsPerDip,
                useGdiNatural,
                transform
            );
        }

        DWriteNet::IDWriteInlineObject ^IDWriteFactory::CreateEllipsisTrimmingSign(
            DWriteNet::IDWriteTextFormat ^textFormat)
        {
            return gcnew DWriteNet::EllipsisInlineObject(this, textFormat);
        }

        DWriteNet::IDWriteTextAnalyzer ^IDWriteFactory::CreateTextAnalyzer()
        {
            return gcnew DWriteNet::IDWriteTextAnalyzer(this);
        }

        DWriteNet::IDWriteNumberSubstitution ^IDWriteFactory::CreateNumberSubstitution(
            DWriteNet::DWRITE_NUMBER_SUBSTITUTION_METHOD substitutionMethod,
            System::String ^localeName,
            bool ignoreUserOverride)
        {
            return gcnew DWriteNet::IDWriteNumberSubstitution(this, substitutionMethod, localeName, ignoreUserOverride);
        }

        DWriteNet::IDWriteGlyphRunAnalysis ^IDWriteFactory::CreateGlyphRunAnalysis(
            DWriteNet::DWRITE_GLYPH_RUN %glyphRun,
            float pixelsPerDip,
            DWriteNet::DWRITE_RENDERING_MODE renderingMode,
            DWriteNet::DWRITE_MEASURING_MODE measuringMode,
            float baselineOriginX, float baselineOriginY,
            System::Nullable<DWriteNet::DWRITE_MATRIX> transform)
        {
            return gcnew DWriteNet::IDWriteGlyphRunAnalysis(
                this,
                glyphRun,
                pixelsPerDip,
                renderingMode,
                measuringMode,
                baselineOriginX,
                baselineOriginY,
                transform
            );
        }

    }
}
