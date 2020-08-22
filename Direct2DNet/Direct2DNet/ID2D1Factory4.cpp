#include "ID2D1Factory4.h"
#include "../GUIDs.h"
#include "ID2D1Device3.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Factory4::ID2D1Factory4(Direct2DNet::D2D1_FACTORY_TYPE type)
            : Direct2DNet::ID2D1Factory3(type, D2DNet::D2DNetGUID::UID_ID2D1Factory4)
        {
            
        }

        ID2D1Factory4::ID2D1Factory4(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            Direct2DNet::D2D1_FACTORY_OPTIONS %options)
            : Direct2DNet::ID2D1Factory3(type, options, D2DNet::D2DNetGUID::UID_ID2D1Factory4)
        {
            
        }

        Direct2DNet::ID2D1Device3 ^ID2D1Factory4::CreateDevice3(DXGINet::IDXGIDevice ^dxgiDevice)
        {
            return gcnew Direct2DNet::ID2D1Device3(this, dxgiDevice);
        }

    }
}