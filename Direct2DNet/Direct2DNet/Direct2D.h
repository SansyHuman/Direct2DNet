#pragma once

#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "D2DError.h"
#include "Exception/DXException.h"
#include "ID2D1Factory.h"
#include "ID2D1Factory1.h"
#include "../GUIDs.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        public ref class Direct2D abstract sealed
        {
        public:
            literal int APPEND_ALIGNED_ELEMENT = D2D1_APPEND_ALIGNED_ELEMENT;
            literal float DEFAULT_FLATTENING_TOLERANCE = D2D1_DEFAULT_FLATTENING_TOLERANCE;
            literal unsigned int INVALID_PROPERTY_INDEX = D2D1_INVALID_PROPERTY_INDEX;
            literal unsigned long long INVALID_TAG = D2D1_INVALID_TAG;
            literal float SCENE_REFERRED_SDR_WHITE_LEVEL = D2D1_SCENE_REFERRED_SDR_WHITE_LEVEL;

            generic<typename T> where T : Direct2DNet::ID2D1Factory
                static T CreateFactory(
                    Direct2DNet::D2D1_FACTORY_TYPE type,
                    [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_FACTORY_OPTIONS> options
                )
            {
                GuidAttribute ^guid = (GuidAttribute ^)System::Attribute::GetCustomAttribute(
                    T::typeid,
                    GuidAttribute::typeid
                );

                System::Guid factoryGuid(guid->Value);
                
                if(factoryGuid == D2DNet::D2DNetGUID::UID_ID2D1Factory)
                {
                    if(options.HasValue)
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory(type, options.Value);
                    }
                    else
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory(type);
                    }
                }
                else if(factoryGuid == D2DNet::D2DNetGUID::UID_ID2D1Factory1)
                {
                    if(options.HasValue)
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory1(type, options.Value);
                    }
                    else
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory1(type);
                    }
                }
                else
                {
                    throw gcnew Direct2DNet::Exception::DxException(
                        "Failed to create the factory.", Direct2DNet::D2DError::E_WIN32_ERROR
                    );
                }
            }

            static Direct2DNet::ID2D1Factory ^CreateFactory(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                [InAttribute][IsReadOnlyAttribute] System::Guid %guid,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_FACTORY_OPTIONS> options
            );
        };
    }
}