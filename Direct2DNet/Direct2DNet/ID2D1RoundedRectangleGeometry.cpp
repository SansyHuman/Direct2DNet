#include "ID2D1RoundedRectangleGeometry.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1RoundedRectangleGeometry::ID2D1RoundedRectangleGeometry(Direct2DNet::ID2D1Factory ^factory, Direct2DNet::D2D1_ROUNDED_RECT %roundedRectangle)
            : Direct2DNet::ID2D1Geometry(factory), m_rect(roundedRectangle)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = factory->m_pFactory->CreateRoundedRectangleGeometry(
                static_cast<::D2D1_ROUNDED_RECT>(roundedRectangle),
                (::ID2D1RoundedRectangleGeometry **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1RoundedRectangleGeometry", (int)hr);
        }
    }
}