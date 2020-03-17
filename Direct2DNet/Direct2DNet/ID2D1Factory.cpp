#include "ID2D1Factory.h"
#include "ID2D1HwndRenderTarget.h"
#include "ID2D1StrokeStyle.h"

namespace Direct2DNet
{
    ID2D1Factory::ID2D1Factory(D2D1_FACTORY_TYPE type)
    {
        m_type = type;

        HRESULT hr = S_OK;
        pin_ptr<::ID2D1Factory *> ppFactory = &m_pFactory;
        hr = ::D2D1CreateFactory((::D2D1_FACTORY_TYPE)((int)type), (::ID2D1Factory **)ppFactory);
        ppFactory = nullptr;

        if(FAILED(hr))
            throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Factory", (int)hr);
    }

    ID2D1Factory::~ID2D1Factory()
    {
        this->!ID2D1Factory();
    }

    ID2D1Factory::!ID2D1Factory()
    {
        if(m_pFactory)
        {
            m_pFactory->Release();
            m_pFactory = nullptr;
        }
    }

    ID2D1Factory ^ID2D1Factory::CreateFactory(Direct2DNet::D2D1_FACTORY_TYPE type)
    {
        return gcnew ID2D1Factory(type);
    }

    void ID2D1Factory::ReloadSystemMetrics()
    {
        m_pFactory->ReloadSystemMetrics();
    }

    void ID2D1Factory::GetDesktopDpi(float %dpiX, float %dpiY)
    {
        float x, y;
        m_pFactory->GetDesktopDpi(&x, &y);
        dpiX = x;
        dpiY = y;
    }

    System::Tuple<float, float> ^ID2D1Factory::GetDesktopDpi()
    {
        float x, y;
        m_pFactory->GetDesktopDpi(&x, &y);
        return gcnew System::Tuple<float, float>(x, y);
    }

    Direct2DNet::ID2D1StrokeStyle ^ID2D1Factory::CreateStrokeStyle(Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES properties, array<float> ^dashes)
    {
        return gcnew Direct2DNet::ID2D1StrokeStyle(
            this,
            properties,
            dashes);
    }

    Direct2DNet::ID2D1HwndRenderTarget ^ID2D1Factory::CreateHwndRenderTarget(
        Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES renderTargetProperties,
        Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRenderTargetProperties)
    {
        return gcnew Direct2DNet::ID2D1HwndRenderTarget(
            this,
            renderTargetProperties,
            hwndRenderTargetProperties);
    }
}
