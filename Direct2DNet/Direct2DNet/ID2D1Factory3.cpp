#include "ID2D1Factory3.h"
#include "../DXGINet/IDXGIDevice.h"
#include "ID2D1Device2.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Factory3::ID2D1Factory3(Direct2DNet::D2D1_FACTORY_TYPE type)
            : Direct2DNet::ID2D1Factory2(type, D2DNetGUID::UID_ID2D1Factory3)
        {
            
        }

        ID2D1Factory3::ID2D1Factory3(Direct2DNet::D2D1_FACTORY_TYPE type, Direct2DNet::D2D1_FACTORY_OPTIONS %options)
            : Direct2DNet::ID2D1Factory2(type, options, D2DNetGUID::UID_ID2D1Factory3)
        {
            
        }

        Direct2DNet::ID2D1Device2 ^ID2D1Factory3::CreateDevice2(DXGINet::IDXGIDevice ^dxgiDevice)
        {
            return gcnew Direct2DNet::ID2D1Device2(this, dxgiDevice);
        }

    }
}