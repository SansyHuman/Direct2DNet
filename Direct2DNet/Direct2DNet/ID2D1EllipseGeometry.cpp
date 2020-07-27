#include "ID2D1EllipseGeometry.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1EllipseGeometry::ID2D1EllipseGeometry(Direct2DNet::ID2D1Factory ^factory, Direct2DNet::D2D1_ELLIPSE %ellipse)
            : Direct2DNet::ID2D1Geometry(factory), m_ellipse(ellipse)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = factory->m_pFactory->CreateEllipseGeometry(
                static_cast<::D2D1_ELLIPSE>(ellipse),
                (::ID2D1EllipseGeometry **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1EllipseGeometry", (int)hr);
        }

        void ID2D1EllipseGeometry::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Geometry::HandleCOMInterface(obj);

            pin_ptr<Direct2DNet::D2D1_ELLIPSE> pEllipse = &m_ellipse;
            ((::ID2D1EllipseGeometry *)m_pResource)->GetEllipse(reinterpret_cast<::D2D1_ELLIPSE *>(pEllipse));
            pEllipse = nullptr;
        }

    }
}