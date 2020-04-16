#include "ID2D1RenderTarget.h"
#include "ID2D1SolidColorBrush.h"
#include "ID2D1GradientStopCollection.h"
#include "ID2D1LinearGradientBrush.h"
#include "ID2D1Mesh.h"
#include "ID2D1StrokeStyle.h"
#include "ID2D1Geometry.h"

namespace Direct2DNet
{
    ID2D1SolidColorBrush ^Direct2DNet::ID2D1RenderTarget::CreateSolidColorBrush(Direct2DNet::D2D1_COLOR_F color)
    {
        return gcnew Direct2DNet::ID2D1SolidColorBrush(this, color);
    }

    Direct2DNet::ID2D1GradientStopCollection ^ID2D1RenderTarget::CreateGradientStopCollection(
        array<Direct2DNet::D2D1_GRADIENT_STOP> ^gradientStops,
        System::Nullable<Direct2DNet::D2D1_GAMMA> colorInterpolationGamma, 
        System::Nullable<Direct2DNet::D2D1_EXTEND_MODE> extendMode)
    {
        if(!colorInterpolationGamma.HasValue)
            colorInterpolationGamma = Direct2DNet::D2D1_GAMMA::GAMMA_2_2;

        if(!extendMode.HasValue)
            extendMode = Direct2DNet::D2D1_EXTEND_MODE::CLAMP;

        return gcnew Direct2DNet::ID2D1GradientStopCollection(
            this,
            gradientStops,
            colorInterpolationGamma.Value,
            extendMode.Value
        );
    }

    Direct2DNet::ID2D1LinearGradientBrush ^ID2D1RenderTarget::CreateLinearGradientBrush(Direct2DNet::D2D1_POINT_2F startPoint, Direct2DNet::D2D1_POINT_2F endPoint, Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection)
    {
        return gcnew Direct2DNet::ID2D1LinearGradientBrush(this, startPoint, endPoint, gradientStopCollection);
    }

    Direct2DNet::ID2D1LinearGradientBrush ^ID2D1RenderTarget::CreateLinearGradientBrush(Direct2DNet::D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES properties, Direct2DNet::ID2D1GradientStopCollection ^gradientStopCollection)
    {
        return gcnew Direct2DNet::ID2D1LinearGradientBrush(this, properties, gradientStopCollection);
    }

    Direct2DNet::ID2D1Mesh ^ID2D1RenderTarget::CreateMesh()
    {
        return gcnew Direct2DNet::ID2D1Mesh(this);
    }

    void ID2D1RenderTarget::DrawLine(
        Direct2DNet::D2D1_POINT_2F point0,
        Direct2DNet::D2D1_POINT_2F point1,
        Direct2DNet::ID2D1Brush ^brush,
        System::Nullable<float> strokeWidth,
        Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
    {
        if(!strokeWidth.HasValue)
            strokeWidth = 1.0f;

        ((::ID2D1RenderTarget *)m_pResource)->DrawLine(
            static_cast<::D2D1_POINT_2F>(point0),
            static_cast<::D2D1_POINT_2F>(point1),
            (::ID2D1Brush *)brush->m_pResource,
            strokeWidth.Value,
            strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
        );
    }

    void ID2D1RenderTarget::DrawRectangle(
        Direct2DNet::D2D1_RECT_F rect, 
        Direct2DNet::ID2D1Brush ^brush, 
        System::Nullable<float> strokeWidth,
        Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
    {
        if(!strokeWidth.HasValue)
            strokeWidth = 1.0f;

        ((::ID2D1RenderTarget *)m_pResource)->DrawRectangle(
            static_cast<::D2D1_RECT_F>(rect),
            (::ID2D1Brush *)brush->m_pResource,
            strokeWidth.Value,
            strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
        );
    }

    void ID2D1RenderTarget::FillRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush)
    {
        ((::ID2D1RenderTarget *)m_pResource)->FillRectangle(
            static_cast<::D2D1_RECT_F>(rect),
            (::ID2D1Brush *)brush->m_pResource
        );
    }

    void ID2D1RenderTarget::DrawRoundedRectangle(
        Direct2DNet::D2D1_ROUNDED_RECT roundedRect, 
        Direct2DNet::ID2D1Brush ^brush, 
        System::Nullable<float> strokeWidth, 
        Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
    {
        if(!strokeWidth.HasValue)
            strokeWidth = 1.0f;

        ((::ID2D1RenderTarget *)m_pResource)->DrawRoundedRectangle(
            static_cast<::D2D1_ROUNDED_RECT>(roundedRect),
            (::ID2D1Brush *)brush->m_pResource,
            strokeWidth.Value,
            strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
        );
    }

    void ID2D1RenderTarget::FillRoundedRectangle(Direct2DNet::D2D1_ROUNDED_RECT roundedRect, Direct2DNet::ID2D1Brush ^brush)
    {
        ((::ID2D1RenderTarget *)m_pResource)->FillRoundedRectangle(
            static_cast<::D2D1_ROUNDED_RECT>(roundedRect),
            (::ID2D1Brush *)brush->m_pResource
        );
    }

    void ID2D1RenderTarget::DrawEllipse(
        Direct2DNet::D2D1_ELLIPSE ellipse, 
        Direct2DNet::ID2D1Brush ^brush, 
        System::Nullable<float> strokeWidth, 
        Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
    {
        if(!strokeWidth.HasValue)
            strokeWidth = 1.0f;

        ((::ID2D1RenderTarget *)m_pResource)->DrawEllipse(
            static_cast<::D2D1_ELLIPSE>(ellipse),
            (::ID2D1Brush *)brush->m_pResource,
            strokeWidth.Value,
            strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
        );
    }

    void ID2D1RenderTarget::FillEllipse(Direct2DNet::D2D1_ELLIPSE ellipse, Direct2DNet::ID2D1Brush ^brush)
    {
        ((::ID2D1RenderTarget *)m_pResource)->FillEllipse(
            static_cast<::D2D1_ELLIPSE>(ellipse),
            (::ID2D1Brush *)brush->m_pResource
        );
    }

    void ID2D1RenderTarget::DrawGeometry(
        Direct2DNet::ID2D1Geometry ^geometry,
        Direct2DNet::ID2D1Brush ^brush,
        System::Nullable<float> strokeWidth,
        Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
    {
        if(!strokeWidth.HasValue)
            strokeWidth = 1.0f;

        ((::ID2D1RenderTarget *)m_pResource)->DrawGeometry(
            (::ID2D1Geometry *)geometry->m_pResource,
            (::ID2D1Brush *)brush->m_pResource,
            strokeWidth.Value,
            strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource
        );
    }

    void ID2D1RenderTarget::FillGeometry(Direct2DNet::ID2D1Geometry ^geometry, Direct2DNet::ID2D1Brush ^brush)
    {
        ((::ID2D1RenderTarget *)m_pResource)->FillGeometry(
            (::ID2D1Geometry *)geometry->m_pResource,
            (::ID2D1Brush *)brush->m_pResource
        );
    }

    void ID2D1RenderTarget::FillMesh(Direct2DNet::ID2D1Mesh ^mesh, Direct2DNet::ID2D1Brush ^brush)
    {
        if(AntialiasMode != Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED)
        {
            AntialiasMode = Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED;
            System::Console::Error->WriteLine("Direct2DNet Warning: You tried to draw mesh when the antialias mode of the render target is not D2D1_ANTIALIAS_MODE::ALIASED. Forced to change to aliased mode.");
        }
        ((::ID2D1RenderTarget *)m_pResource)->FillMesh(
            (::ID2D1Mesh *)mesh->m_pResource,
            (::ID2D1Brush *)brush->m_pResource
        );
    }

    void ID2D1RenderTarget::Clear(Direct2DNet::D2D1_COLOR_F clearColor)
    {
        ((::ID2D1RenderTarget *)m_pResource)->Clear(
            static_cast<::D2D1_COLOR_F>(clearColor)
        );
    }

    void ID2D1RenderTarget::BeginDraw()
    {
        ((::ID2D1RenderTarget *)m_pResource)->BeginDraw();
    }

    HRESULT ID2D1RenderTarget::EndDraw()
    {
        return ((::ID2D1RenderTarget *)m_pResource)->EndDraw();
    }

    bool ID2D1RenderTarget::IsSupported(Direct2DNet::D2D1_RENDER_TARGET_PROPERTIES properties)
    {
        BOOL result = ((::ID2D1RenderTarget *)m_pResource)->IsSupported(
            &static_cast<::D2D1_RENDER_TARGET_PROPERTIES>(properties)
        );

        return System::Convert::ToBoolean(result);
    }

}