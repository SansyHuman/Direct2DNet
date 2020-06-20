#include "ID2D1Factory.h"
#include "ID2D1RectangleGeometry.h"
#include "ID2D1RoundedRectangleGeometry.h"
#include "ID2D1EllipseGeometry.h"
#include "ID2D1GeometryGroup.h"
#include "ID2D1TransformedGeometry.h"
#include "ID2D1PathGeometry.h"
#include "ID2D1DrawingStateBlock.h"
#include "../DWriteNet/IDWriteRenderingParams.h"
#include "ID2D1HwndRenderTarget.h"
#include "ID2D1RenderTarget.h"
#include "../DXGINet/IDXGISurface.h"
#include "ID2D1DCRenderTarget.h"
#include "ID2D1StrokeStyle.h"
#include "ID2D1Multithread.h"
#include "../GUIDs.h"
#include "D2DError.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Factory::ID2D1Factory(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            System::Guid guid)
            : m_type(type)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Factory *> ppFactory = &m_pFactory;

            hr = ::D2D1CreateFactory(
                (::D2D1_FACTORY_TYPE)((int)type),
                D2DNet::DirectX::ToNativeGUID(guid),
                (void **)ppFactory);

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Factory", (int)hr);
        }

        ID2D1Factory::ID2D1Factory(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            Direct2DNet::D2D1_FACTORY_OPTIONS %options,
            System::Guid guid)
            : m_type(type)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Factory *> ppFactory = &m_pFactory;

            hr = ::D2D1CreateFactory(
                (::D2D1_FACTORY_TYPE)((int)type),
                D2DNet::DirectX::ToNativeGUID(guid),
                &static_cast<::D2D1_FACTORY_OPTIONS>(options),
                (void **)ppFactory);

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Factory", (int)hr);
        }

        ID2D1Factory::ID2D1Factory(::ID2D1Factory *pFactory)
        {
            m_pFactory = pFactory;
        }

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

        ID2D1Factory::ID2D1Factory(Direct2DNet::D2D1_FACTORY_TYPE type, Direct2DNet::D2D1_FACTORY_OPTIONS %options)
        {
            m_type = type;

            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Factory *> ppFactory = &m_pFactory;
            hr = ::D2D1CreateFactory(
                (::D2D1_FACTORY_TYPE)((int)type),
                static_cast<::D2D1_FACTORY_OPTIONS>(options),
                (::ID2D1Factory **)ppFactory);
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

        bool ID2D1Factory::Equals(System::Object ^other)
        {
            try
            {
                return this->m_pFactory == safe_cast<Direct2DNet::ID2D1Factory ^>(other)->m_pFactory;
            }
            catch(System::Exception ^)
            {
                return false;
            }
        }

        HRESULT ID2D1Factory::ReloadSystemMetrics()
        {
            return m_pFactory->ReloadSystemMetrics();
        }

        void ID2D1Factory::GetDesktopDpi(float %dpiX, float %dpiY)
        {
            pin_ptr<float> pX = &dpiX, pY = &dpiY;
            m_pFactory->GetDesktopDpi((float *)pX, (float *)pY);
            pX = nullptr, pY = nullptr;
        }

        System::ValueTuple<float, float> ^ID2D1Factory::GetDesktopDpi()
        {
            float x, y;
            pin_ptr<float> pX = &x, pY = &y;
            m_pFactory->GetDesktopDpi(&x, &y);
            pX = nullptr; pY = nullptr;
            return System::ValueTuple<float, float>(x, y);
        }

        Direct2DNet::ID2D1RectangleGeometry ^ID2D1Factory::CreateRectangleGeometry(Direct2DNet::D2D1_RECT_F %rectangle)
        {
            return gcnew Direct2DNet::ID2D1RectangleGeometry(this, rectangle);
        }

        Direct2DNet::ID2D1RoundedRectangleGeometry ^ID2D1Factory::CreateRoundedRectangleGeometry(
            Direct2DNet::D2D1_ROUNDED_RECT %roundedRectangle)
        {
            return gcnew Direct2DNet::ID2D1RoundedRectangleGeometry(this, roundedRectangle);
        }

        Direct2DNet::ID2D1EllipseGeometry ^ID2D1Factory::CreateEllipseGeometry(
            Direct2DNet::D2D1_ELLIPSE %ellipse)
        {
            return gcnew Direct2DNet::ID2D1EllipseGeometry(this, ellipse);
        }

        Direct2DNet::ID2D1GeometryGroup ^ID2D1Factory::CreateGeometryGroup(Direct2DNet::D2D1_FILL_MODE fillMode, ...array<Direct2DNet::ID2D1Geometry ^> ^geometries)
        {
            return gcnew Direct2DNet::ID2D1GeometryGroup(this, fillMode, geometries);
        }

        Direct2DNet::ID2D1TransformedGeometry ^ID2D1Factory::CreateTransformedGeometry(
            Direct2DNet::ID2D1Geometry ^sourceGeometry,
            Direct2DNet::D2D1_MATRIX_3X2_F %transform)
        {
            return gcnew Direct2DNet::ID2D1TransformedGeometry(this, sourceGeometry, transform);
        }

        Direct2DNet::ID2D1PathGeometry ^ID2D1Factory::CreatePathGeometry()
        {
            return gcnew Direct2DNet::ID2D1PathGeometry(this);
        }

        Direct2DNet::ID2D1StrokeStyle ^ID2D1Factory::CreateStrokeStyle(Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES %properties, array<float> ^dashes)
        {
            if(properties.dashStyle == Direct2DNet::D2D1_DASH_STYLE::CUSTOM
                && (dashes == nullptr || dashes->Length <= 0))
                throw gcnew Direct2DNet::Exception::DxException(
                    "Failed to create stroke style. You set the custom dash style, but the dash array is null or has length zero.",
                    E_INVALIDARG);

            return gcnew Direct2DNet::ID2D1StrokeStyle(
                this,
                properties,
                dashes);
        }

        Direct2DNet::ID2D1DrawingStateBlock ^ID2D1Factory::CreateDrawingStateBlock(
            System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION> drawingStateDescription, 
            D2DNet::DWriteNet::IDWriteRenderingParams ^textRenderingParams)
        {
            return gcnew Direct2DNet::ID2D1DrawingStateBlock(
                this, drawingStateDescription, textRenderingParams
            );
        }

        Direct2DNet::ID2D1HwndRenderTarget ^ID2D1Factory::CreateHwndRenderTarget(
            Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties,
            Direct2DNet::D2D1_HWND_RENDER_TARGET_PROPERTIES %hwndRenderTargetProperties)
        {
            return gcnew Direct2DNet::ID2D1HwndRenderTarget(
                this,
                renderTargetProperties,
                hwndRenderTargetProperties);
        }

        Direct2DNet::ID2D1RenderTarget ^ID2D1Factory::CreateDxgiSurfaceRenderTarget(
            DXGINet::IDXGISurface ^dxgiSurface,
            Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties)
        {
            return gcnew Direct2DNet::ID2D1RenderTarget(this, dxgiSurface, renderTargetProperties);
        }

        Direct2DNet::ID2D1DCRenderTarget ^ID2D1Factory::CreateDCRenderTarget(Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES %renderTargetProperties)
        {
            return gcnew Direct2DNet::ID2D1DCRenderTarget(
                this,
                renderTargetProperties
            );
        }

        Direct2DNet::ID2D1Multithread ^ID2D1Factory::QueryToID2D1Multithread()
        {
            ::ID2D1Multithread *pThread = __nullptr;
            HRESULT hr = m_pFactory->QueryInterface(__uuidof(::ID2D1Multithread), (void **)&pThread);

            if(FAILED(hr))
                throw gcnew D2DNet::Direct2DNet::Exception::DxException(
                    "Failed to query ID2D1Multithread.", hr
                );

            return gcnew Direct2DNet::ID2D1Multithread(pThread);
        }

    }
}