#include "IDXGIKeyedMutex.h"

namespace D2DNet
{
    namespace DXGINet
    {
        HRESULT IDXGIKeyedMutex::AcquireSync(UINT64 key, DWORD milliseconds)
        {
            return ((::IDXGIKeyedMutex *)m_pObj)->AcquireSync(key, milliseconds);
        }

        HRESULT IDXGIKeyedMutex::ReleaseSync(UINT64 key)
        {
            return ((::IDXGIKeyedMutex *)m_pObj)->ReleaseSync(key);
        }

    }
}