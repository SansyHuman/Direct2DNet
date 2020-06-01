#include "ID2D1Image.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Image::ID2D1Image(Direct2DNet::ID2D1Factory ^factory, ::ID2D1Image *pImage)
            : Direct2DNet::ID2D1Resource(factory)
        {
            m_pResource = pImage;
        }
    }
}