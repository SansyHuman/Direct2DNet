#include "Direct2D.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        Direct2DNet::ID2D1Factory ^Direct2D::CreateFactory(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            System::Guid %guid,
            System::Nullable<Direct2DNet::D2D1_FACTORY_OPTIONS> options)
        {
            if(guid == D2DNet::D2DNetGUID::UID_ID2D1Factory)
            {
                if(options.HasValue)
                {
                    return gcnew Direct2DNet::ID2D1Factory(type, options.Value);
                }
                else
                {
                    return gcnew Direct2DNet::ID2D1Factory(type);
                }
            }
            else if(guid == D2DNet::D2DNetGUID::UID_ID2D1Factory1)
            {
                if(options.HasValue)
                {
                    return gcnew Direct2DNet::ID2D1Factory1(type, options.Value);
                }
                else
                {
                    return gcnew Direct2DNet::ID2D1Factory1(type);
                }
            }
            else
            {
                throw gcnew Direct2DNet::Exception::DxException(
                    "Failed to create the factory.", Direct2DNet::D2DError::E_WIN32_ERROR
                );
            }
        }

    }
}