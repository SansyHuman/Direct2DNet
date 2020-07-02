#include "IDWriteRenderingParams.h"
#include "IDWriteFactory.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteRenderingParams::IDWriteRenderingParams(DWriteNet::IDWriteFactory ^factory)
        {
            HRESULT hr = S_OK;

            pin_ptr<::IDWriteRenderingParams *> ppParams = &m_pParams;
            hr = factory->m_pFactory->CreateRenderingParams((::IDWriteRenderingParams **)ppParams);
            ppParams = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteRenderingParams.", (int)hr);
        }

        IDWriteRenderingParams::IDWriteRenderingParams(
            DWriteNet::IDWriteFactory ^factory,
            System::IntPtr %monitor)
        {
            HRESULT hr = S_OK;

            pin_ptr<::IDWriteRenderingParams *> ppParams = &m_pParams;
            hr = factory->m_pFactory->CreateMonitorRenderingParams(
                (HMONITOR)monitor.ToPointer(),
                (::IDWriteRenderingParams **)ppParams
            );
            ppParams = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteRenderingParams.", (int)hr);
        }

        IDWriteRenderingParams::IDWriteRenderingParams(
            DWriteNet::IDWriteFactory ^factory,
            float gamma,
            float enhancedContrast,
            float clearTypeLevel,
            DWriteNet::DWRITE_PIXEL_GEOMETRY pixelGeometry,
            DWriteNet::DWRITE_RENDERING_MODE renderingMode)
        {
            HRESULT hr = S_OK;

            pin_ptr<::IDWriteRenderingParams *> ppParams = &m_pParams;
            hr = factory->m_pFactory->CreateCustomRenderingParams(
                gamma,
                enhancedContrast,
                clearTypeLevel,
                (::DWRITE_PIXEL_GEOMETRY)((int)pixelGeometry),
                (::DWRITE_RENDERING_MODE)((int)renderingMode),
                (::IDWriteRenderingParams **)ppParams
            );
            ppParams = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteRenderingParams.", (int)hr);
        }

        IDWriteRenderingParams::~IDWriteRenderingParams()
        {
            this->!IDWriteRenderingParams();
        }

        IDWriteRenderingParams::!IDWriteRenderingParams()
        {
            if(m_pParams)
            {
                m_pParams->Release();
                m_pParams = nullptr;
            }
        }

    }
}
