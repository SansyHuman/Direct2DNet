#include "ID2D1Factory2.h"
#include "ID2D1Device1.h"
#include "../DXGINet/IDXGIDevice.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Factory2::ID2D1Factory2(Direct2DNet::D2D1_FACTORY_TYPE type)
            : Direct2DNet::ID2D1Factory1(type, D2DNet::D2DNetGUID::UID_ID2D1Factory2)
        {
            
        }

        ID2D1Factory2::ID2D1Factory2(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            Direct2DNet::D2D1_FACTORY_OPTIONS %options)
            : Direct2DNet::ID2D1Factory1(type, options, D2DNet::D2DNetGUID::UID_ID2D1Factory2)
        {
            
        }

        Direct2DNet::ID2D1Device1 ^ID2D1Factory2::CreateDevice1(DXGINet::IDXGIDevice ^dxgiDevice)
        {
            return gcnew Direct2DNet::ID2D1Device1(this, dxgiDevice);
        }

    }
}