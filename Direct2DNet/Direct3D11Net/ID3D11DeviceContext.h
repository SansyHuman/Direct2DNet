#pragma once

#include "D3D11NetHeaders.h"
#include "D3D11Settings.h"
#include "ID3D11DeviceChild.h"

namespace D2DNet
{
    namespace Direct3D11Net
    {
        ref class ID3D11Device;

        [System::Runtime::InteropServices::GuidAttribute("c0bfa96c-e089-44fb-8eaf-26f8796190da")]
        public ref class ID3D11DeviceContext : Direct3D11Net::ID3D11DeviceChild
        {
        internal:
            //Called by ID3D11Device constructor.
            ID3D11DeviceContext(Direct3D11Net::ID3D11Device ^device, ::ID3D11DeviceContext *context);
        };

    }
}