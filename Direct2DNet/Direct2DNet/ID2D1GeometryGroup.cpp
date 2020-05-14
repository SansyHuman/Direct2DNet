#include "ID2D1GeometryGroup.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GeometryGroup::ID2D1GeometryGroup(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_FILL_MODE fillMode,
            array<Direct2DNet::ID2D1Geometry ^> ^geometries
        ) : Direct2DNet::ID2D1Geometry(factory), m_fillMode(fillMode), m_geometries(geometries)
        {
            HRESULT hr = S_OK;

            std::vector<::ID2D1Geometry *> nativeGeometries(geometries->Length);
            for(int i = 0; i < geometries->Length; i++)
            {
                nativeGeometries[i] = (::ID2D1Geometry *)geometries[i]->m_pResource;
            }

            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = factory->m_pFactory->CreateGeometryGroup(
                (::D2D1_FILL_MODE)((int)fillMode),
                nativeGeometries.data(),
                nativeGeometries.size(),
                (::ID2D1GeometryGroup **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GeometryGroup", (int)hr);
        }
    }
}