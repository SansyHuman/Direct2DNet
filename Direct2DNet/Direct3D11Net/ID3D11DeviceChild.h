#pragma once

#include "D3D11NetHeaders.h"
#include "D3D11Settings.h"
#include "IDirect3D11Object.h"

namespace D2DNet
{
    namespace Direct3D11Net
    {
        ref class ID3D11Device;
        
        [System::Runtime::InteropServices::GuidAttribute("1841e5c8-16b0-489b-bcc8-44cfb0d5deae")]
        public ref class ID3D11DeviceChild abstract : Direct3D11Net::IDirect3D11Object
        {
        internal:
            ::ID3D11DeviceChild *m_pChild;
            Direct3D11Net::ID3D11Device ^m_device;

        protected:
            ID3D11DeviceChild(Direct3D11Net::ID3D11Device ^device);

        public:
            ~ID3D11DeviceChild();
            !ID3D11DeviceChild();

        public:
            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pChild;
                }
            }

            property Direct3D11Net::ID3D11Device ^Device
            {
                Direct3D11Net::ID3D11Device ^get()
                {
                    return m_device;
                }
            }
        };
    }
}