#include "ID3D11DeviceChild.h"
#include "ID3D11Device.h"

namespace D2DNet
{
    namespace Direct3D11Net
    {
        ID3D11DeviceChild::ID3D11DeviceChild(Direct3D11Net::ID3D11Device ^device) : m_device(device)
        {
            
        }

        ID3D11DeviceChild::~ID3D11DeviceChild()
        {
            this->!ID3D11DeviceChild();
        }

        ID3D11DeviceChild::!ID3D11DeviceChild()
        {
            if(m_pChild)
            {
                m_pChild->Release();
                m_pChild = nullptr;
            }
        }

        void ID3D11DeviceChild::HandleCOMInterface(void *obj)
        {
            if(m_pChild)
            {
                m_pChild->Release();
            }

            m_pChild = (::ID3D11DeviceChild *)obj;
            m_pChild->AddRef();

            ::ID3D11Device *device = __nullptr;
            m_pChild->GetDevice(&device);
            m_device = gcnew Direct3D11Net::ID3D11Device(device);
        }

    }
}