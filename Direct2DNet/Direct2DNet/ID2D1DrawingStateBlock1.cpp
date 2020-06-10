#include "ID2D1DrawingStateBlock1.h"
#include "ID2D1Factory1.h"
#include "../DWriteNet/IDWriteRenderingParams.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DrawingStateBlock1::ID2D1DrawingStateBlock1(
            Direct2DNet::ID2D1Factory1 ^factory,
            System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1> %description,
            DWriteNet::IDWriteRenderingParams ^params) : Direct2DNet::ID2D1DrawingStateBlock(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory1 *)factory->m_pFactory)->CreateDrawingStateBlock(
                description.HasValue ? &static_cast<::D2D1_DRAWING_STATE_DESCRIPTION1>(description.Value) : __nullptr,
                params == nullptr ? __nullptr : params->m_pParams,
                (::ID2D1DrawingStateBlock1 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DrawingStateBlock1", (int)hr);
        }
    }
}