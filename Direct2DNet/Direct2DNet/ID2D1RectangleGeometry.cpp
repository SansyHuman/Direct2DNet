#include "ID2D1RectangleGeometry.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1RectangleGeometry::ID2D1RectangleGeometry(Direct2DNet::ID2D1Factory ^factory, Direct2DNet::D2D1_RECT_F %rectangle)
            : Direct2DNet::ID2D1Geometry(factory), m_rect(rectangle)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = factory->m_pFactory->CreateRectangleGeometry(
                static_cast<::D2D1_RECT_F>(rectangle),
                (::ID2D1RectangleGeometry **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1RectangleGeometry", (int)hr);
        }
    }
}