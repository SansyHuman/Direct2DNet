#include "ID2D1DeviceContext1.h"
#include "ID2D1Device1.h"
#include "ID2D1GeometryRealization.h"
#include "ID2D1Geometry.h"
#include "ID2D1StrokeStyle.h"
#include "ID2D1Brush.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DeviceContext1::ID2D1DeviceContext1(
            Direct2DNet::ID2D1Device1 ^device,
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
            : Direct2DNet::ID2D1DeviceContext(device, options)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = ((::ID2D1Device1 *)device->m_pResource)->CreateDeviceContext(
                (::D2D1_DEVICE_CONTEXT_OPTIONS)((int)options),
                (::ID2D1DeviceContext1 **)ppRenderTarget
            );
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DeviceContext1", (int)hr);
        }

        Direct2DNet::ID2D1GeometryRealization ^ID2D1DeviceContext1::CreateFilledGeometryRealization(
            Direct2DNet::ID2D1Geometry ^geometry,
            float flatteningTolerance)
        {
            return gcnew Direct2DNet::ID2D1GeometryRealization(this, geometry, flatteningTolerance);
        }

        Direct2DNet::ID2D1GeometryRealization ^ID2D1DeviceContext1::CreateStrokedGeometryRealization(
            Direct2DNet::ID2D1Geometry ^geometry,
            float flatteningTolerance,
            float strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle)
        {
            return gcnew Direct2DNet::ID2D1GeometryRealization(this, geometry, flatteningTolerance, strokeWidth, strokeStyle);
        }

        void ID2D1DeviceContext1::DrawGeometryRealization(
            Direct2DNet::ID2D1GeometryRealization ^geometryRealization,
            Direct2DNet::ID2D1Brush ^brush)
        {
            ((::ID2D1DeviceContext1 *)m_pResource)->DrawGeometryRealization(
                (::ID2D1GeometryRealization *)geometryRealization->m_pResource,
                (::ID2D1Brush *)brush->m_pResource
            );
        }

    }
}