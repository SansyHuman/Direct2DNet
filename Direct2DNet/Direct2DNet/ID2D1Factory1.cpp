#include "ID2D1Factory1.h"
#include "ID2D1StrokeStyle1.h"
#include "ID2D1PathGeometry1.h"
#include "../DXGINet/IDXGIDevice.h"
#include "ID2D1Device.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Factory1::ID2D1Factory1(Direct2DNet::D2D1_FACTORY_TYPE type)
            : Direct2DNet::ID2D1Factory(type, D2DNet::D2DNetGUID::UID_ID2D1Factory1)
        {
            
        }

        ID2D1Factory1::ID2D1Factory1(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            Direct2DNet::D2D1_FACTORY_OPTIONS %options)
            : Direct2DNet::ID2D1Factory(type, options, D2DNet::D2DNetGUID::UID_ID2D1Factory1)
        {
            
        }

        Direct2DNet::ID2D1Device ^ID2D1Factory1::CreateDevice(DXGINet::IDXGIDevice ^dxgiDevice)
        {
            return gcnew Direct2DNet::ID2D1Device(this, dxgiDevice);
        }

        Direct2DNet::ID2D1StrokeStyle1 ^ID2D1Factory1::CreateStrokeStyle(
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 %properties,
            array<float> ^dashes)
        {
            if(properties.dashStyle == Direct2DNet::D2D1_DASH_STYLE::CUSTOM
                && (dashes == nullptr || dashes->Length <= 0))
                throw gcnew Direct2DNet::Exception::DxException(
                    "Failed to create stroke style. You set the custom dash style, but the dash array is null or has length zero.",
                    E_INVALIDARG);

            return gcnew Direct2DNet::ID2D1StrokeStyle1(this, properties, dashes);
        }

        Direct2DNet::ID2D1PathGeometry1 ^ID2D1Factory1::CreatePathGeometry()
        {
            return gcnew Direct2DNet::ID2D1PathGeometry1(this);
        }

    }
}