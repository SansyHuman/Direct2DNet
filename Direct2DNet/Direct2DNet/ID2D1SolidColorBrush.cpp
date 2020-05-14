#include "ID2D1SolidColorBrush.h"
#include "ID2D1RenderTarget.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1SolidColorBrush::ID2D1SolidColorBrush(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            Direct2DNet::D2D1_COLOR_F %color)
            : Direct2DNet::ID2D1Brush(renderTarget->Factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppBrush = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateSolidColorBrush(
                static_cast<::D2D1_COLOR_F>(color),
                (::ID2D1SolidColorBrush **)ppBrush
            );
            ppBrush = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1SolidColorBrush", (int)hr);
        }
    }
}