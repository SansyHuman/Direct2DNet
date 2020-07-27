#include "ID2D1TransformedGeometry.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        Direct2DNet::ID2D1TransformedGeometry::ID2D1TransformedGeometry(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::ID2D1Geometry ^source,
            Direct2DNet::D2D1_MATRIX_3X2_F %transform
        ) : Direct2DNet::ID2D1Geometry(factory), m_source(source), m_transform(transform)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory *)factory->m_pFactory)->CreateTransformedGeometry(
                (::ID2D1Geometry *)source->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(transform),
                (::ID2D1TransformedGeometry **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1TransformedGeometry", (int)hr);
        }

        void ID2D1TransformedGeometry::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Geometry::HandleCOMInterface(obj);

            ::ID2D1Geometry *source = __nullptr;
            ((::ID2D1TransformedGeometry *)m_pResource)->GetSourceGeometry(&source);

            ::ID2D1Factory *factory = __nullptr;
            source->GetFactory(&factory);

            m_source = gcnew Direct2DNet::ID2D1Geometry(
                gcnew Direct2DNet::ID2D1Factory(factory), source
            );

            pin_ptr<Direct2DNet::D2D1_MATRIX_3X2_F> pTransform = &m_transform;
            ((::ID2D1TransformedGeometry *)m_pResource)->GetTransform(reinterpret_cast<::D2D1_MATRIX_3X2_F *>(pTransform));
            pTransform = nullptr;
        }

    }
}