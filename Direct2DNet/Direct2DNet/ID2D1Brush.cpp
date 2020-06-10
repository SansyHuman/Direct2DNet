#include "ID2D1Brush.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Brush::ID2D1Brush(Direct2DNet::ID2D1Factory ^factory, ::ID2D1Brush *pBrush)
            : Direct2DNet::ID2D1Resource(factory)
        {
            m_pResource = pBrush;
        }
    }
}