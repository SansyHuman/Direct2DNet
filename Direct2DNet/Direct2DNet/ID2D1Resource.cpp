#include "ID2D1Resource.h"
#include "ID2D1Factory.h"

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
}
