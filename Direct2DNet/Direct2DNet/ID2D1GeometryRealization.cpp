#include "ID2D1GeometryRealization.h"
#include "ID2D1DeviceContext1.h"
#include "ID2D1Geometry.h"
#include "ID2D1StrokeStyle.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GeometryRealization::ID2D1GeometryRealization(
            Direct2DNet::ID2D1DeviceContext1 ^context,
            Direct2DNet::ID2D1Geometry ^geometry,
            float flatteningTolerance)
            : Direct2DNet::ID2D1Resource(context->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext1 *)context->m_pResource)->CreateFilledGeometryRealization(
                (::ID2D1Geometry *)geometry->m_pResource,
                flatteningTolerance,
                (::ID2D1GeometryRealization **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GeometryRealization", (int)hr);
        }

        ID2D1GeometryRealization::ID2D1GeometryRealization(
            Direct2DNet::ID2D1DeviceContext1 ^context,
            Direct2DNet::ID2D1Geometry ^geometry,
            float flatteningTolerance,
            float strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
            : Direct2DNet::ID2D1Resource(context->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext1 *)context->m_pResource)->CreateStrokedGeometryRealization(
                (::ID2D1Geometry *)geometry->m_pResource,
                flatteningTolerance,
                strokeWidth,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource,
                (::ID2D1GeometryRealization **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GeometryRealization", (int)hr);
        }

    }
}