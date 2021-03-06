#include "ID2D1Resource.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Resource::ID2D1Resource(Direct2DNet::ID2D1Factory ^factory)
        {
            this->m_factory = factory;
        }

        ID2D1Resource::~ID2D1Resource()
        {
            m_factory = nullptr;
            this->!ID2D1Resource();
        }

        ID2D1Resource::!ID2D1Resource()
        {
            if(m_pResource)
            {
                m_pResource->Release();
                m_pResource = nullptr;
            }
        }

        bool ID2D1Resource::Equals(System::Object ^other)
        {
            try
            {
                return this->m_pResource == safe_cast<Direct2DNet::ID2D1Resource ^>(other)->m_pResource;
            }
            catch(System::Exception ^)
            {
                return false;
            }
        }

        void ID2D1Resource::HandleCOMInterface(void *obj)
        {
            if(m_pResource)
            {
                m_pResource->Release();
            }

            m_pResource = (::ID2D1Resource *)obj;
            m_pResource->AddRef();

            ::ID2D1Factory *factory = __nullptr;
            m_pResource->GetFactory(&factory);

            m_factory = gcnew Direct2DNet::ID2D1Factory(factory);
        }

    }
}