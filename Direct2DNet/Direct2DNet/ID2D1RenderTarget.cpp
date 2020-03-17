#include "ID2D1RenderTarget.h"
#include "ID2D1SolidColorBrush.h"
#include "ID2D1StrokeStyle.h"

namespace Direct2DNet
{
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

    ID2D1SolidColorBrush ^Direct2DNet::ID2D1RenderTarget::CreateSolidColorBrush(Direct2DNet::D2D1_COLOR_F color)
    {
        return gcnew Direct2DNet::ID2D1SolidColorBrush(this, color);
    }

    void ID2D1RenderTarget::DrawRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush)
    {
        ((::ID2D1RenderTarget *)m_pResource)->DrawRectangle(
            static_cast<::D2D1_RECT_F>(rect),
            (::ID2D1Brush *)brush->m_pResource
        );
    }

    void ID2D1RenderTarget::DrawRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush, float strokeWidth)
    {
        ((::ID2D1RenderTarget *)m_pResource)->DrawRectangle(
            static_cast<::D2D1_RECT_F>(rect),
            (::ID2D1Brush *)brush->m_pResource,
            strokeWidth
        );
    }

    void ID2D1RenderTarget::DrawRectangle(
        Direct2DNet::D2D1_RECT_F rect, 
        Direct2DNet::ID2D1Brush ^brush, 
        float strokeWidth, 
        Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
    {
        ((::ID2D1RenderTarget *)m_pResource)->DrawRectangle(
            static_cast<::D2D1_RECT_F>(rect),
            (::ID2D1Brush *)brush->m_pResource,
            strokeWidth,
            (::ID2D1StrokeStyle *)strokeStyle->m_pResource
        );
    }

    void ID2D1RenderTarget::FillRectangle(Direct2DNet::D2D1_RECT_F rect, Direct2DNet::ID2D1Brush ^brush)
    {
        ((::ID2D1RenderTarget *)m_pResource)->FillRectangle(
            static_cast<::D2D1_RECT_F>(rect),
            (::ID2D1Brush *)brush->m_pResource
        );
    }

    void ID2D1RenderTarget::SetTransform(Direct2DNet::D2D1_MATRIX_3X2_F transform)
    {
        ((::ID2D1RenderTarget *)m_pResource)->SetTransform(
            static_cast<::D2D1_MATRIX_3X2_F>(transform)
        );
    }

    void ID2D1RenderTarget::Clear(Direct2DNet::D2D1_COLOR_F clearColor)
    {
        ((::ID2D1RenderTarget *)m_pResource)->Clear(
            static_cast<::D2D1_COLOR_F>(clearColor)
        );
    }

}