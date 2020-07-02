#include "IDWriteFactory.h"
#include "IDWriteFontCollection.h"
#include "IDWriteFontFile.h"
#include "IDWriteRenderingParams.h"
#include "IDWriteTextFormat.h"

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

        DWriteNet::IDWriteFontCollection ^IDWriteFactory::GetSystemFontCollection(
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
                throw gcnew Direct2DNet::Exception::DxException("Failed to get IDWriteFontCollection.", (int)hr);

            return gcnew DWriteNet::IDWriteFontCollection(pCollection);
        }

        DWriteNet::IDWriteFontFile ^IDWriteFactory::CreateFontFileReference(
            System::String ^filePath,
            System::Nullable<InteropServices::ComTypes::FILETIME> lastWriteTime)
        {
            return gcnew DWriteNet::IDWriteFontFile(this, filePath, lastWriteTime);
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

    }
}
