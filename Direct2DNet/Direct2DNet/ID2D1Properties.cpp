#include "ID2D1Properties.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Properties::~ID2D1Properties()
        {
            this->!ID2D1Properties();
        }

        ID2D1Properties::!ID2D1Properties()
        {
            if(m_pProperties)
            {
                m_pProperties->Release();
                m_pProperties = nullptr;
            }
        }

        bool ID2D1Properties::Equals(System::Object ^other)
        {
            try
            {
                return this->m_pProperties == safe_cast<Direct2DNet::ID2D1Properties ^>(other)->m_pProperties;
            }
            catch(System::Exception ^)
            {
                return false;
            }
        }

        unsigned int ID2D1Properties::GetPropertyIndex(System::String ^name)
        {
            marshal_context context;

            unsigned int index =  m_pProperties->GetPropertyIndex(context.marshal_as<PCWSTR>(name));
            return index;
        }

        HRESULT ID2D1Properties::SetValueByName(
            System::String ^name,
            Direct2DNet::D2D1_PROPERTY_TYPE type,
            void *data,
            unsigned int dataSize)
        {
            marshal_context context;

            return m_pProperties->SetValueByName(
                context.marshal_as<PCWSTR>(name),
                (::D2D1_PROPERTY_TYPE)((int)type),
                (BYTE *)data,
                dataSize
            );
        }

        HRESULT ID2D1Properties::SetValue(
            unsigned int index,
            Direct2DNet::D2D1_PROPERTY_TYPE type,
            void *data,
            unsigned int dataSize)
        {
            return m_pProperties->SetValue(
                index,
                (::D2D1_PROPERTY_TYPE)((int)type),
                (BYTE *)data,
                dataSize
            );
        }

        HRESULT ID2D1Properties::GetValueByName(
            System::String ^name,
            Direct2DNet::D2D1_PROPERTY_TYPE type,
            void *data,
            unsigned int dataSize)
        {
            marshal_context context;

            return m_pProperties->GetValueByName(
                context.marshal_as<PCWSTR>(name),
                (::D2D1_PROPERTY_TYPE)((int)type),
                (BYTE *)data,
                dataSize
            );
        }

        HRESULT ID2D1Properties::GetValueByName(System::String ^name, void *data, unsigned int dataSize)
        {
            marshal_context context;

            return m_pProperties->GetValueByName(
                context.marshal_as<PCWSTR>(name),
                ::D2D1_PROPERTY_TYPE_UNKNOWN,
                (BYTE *)data,
                dataSize
            );
        }

        HRESULT ID2D1Properties::GetValue(
            unsigned int index,
            Direct2DNet::D2D1_PROPERTY_TYPE type,
            void *data,
            unsigned int dataSize)
        {
            return m_pProperties->GetValue(
                index,
                (::D2D1_PROPERTY_TYPE)((int)type),
                (BYTE *)data,
                dataSize
            );
        }

        HRESULT ID2D1Properties::GetValue(unsigned int index, void *data, unsigned int dataSize)
        {
            return m_pProperties->GetValue(
                index,
                ::D2D1_PROPERTY_TYPE_UNKNOWN,
                (BYTE *)data,
                dataSize
            );
        }

    }
}