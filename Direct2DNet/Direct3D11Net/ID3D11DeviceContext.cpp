#include "ID3D11DeviceContext.h"
#include "ID3D11Device.h"

namespace D2DNet
{
    namespace Direct3D11Net
    {
        ID3D11DeviceContext::ID3D11DeviceContext(
            Direct3D11Net::ID3D11Device ^device,
            ::ID3D11DeviceContext *context)
            : Direct3D11Net::ID3D11DeviceChild(device)
        {
            m_pChild = context;
        }

    }
}