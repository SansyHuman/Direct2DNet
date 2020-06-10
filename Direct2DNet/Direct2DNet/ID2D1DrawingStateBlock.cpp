#include "ID2D1DrawingStateBlock.h"
#include "ID2D1Factory.h"
#include "ID2D1Factory1.h"
#include "../DWriteNet/IDWriteRenderingParams.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DrawingStateBlock::ID2D1DrawingStateBlock(
            Direct2DNet::ID2D1Factory ^factory,
            System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION> %description,
            DWriteNet::IDWriteRenderingParams ^params) : Direct2DNet::ID2D1Resource(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = factory->m_pFactory->CreateDrawingStateBlock(
                description.HasValue ? &static_cast<::D2D1_DRAWING_STATE_DESCRIPTION>(description.Value) : __nullptr,
                params == nullptr ? __nullptr : params->m_pParams,
                (::ID2D1DrawingStateBlock **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DrawingStateBlock", (int)hr);
        }

        ID2D1DrawingStateBlock::ID2D1DrawingStateBlock(Direct2DNet::ID2D1Factory1 ^factory)
            : Direct2DNet::ID2D1Resource(factory)
        {
            
        }

        void ID2D1DrawingStateBlock::TextRenderingParams::set(DWriteNet::IDWriteRenderingParams ^value)
        {
            ((::ID2D1DrawingStateBlock *)m_pResource)->SetTextRenderingParams(
                value == nullptr ? __nullptr : value->m_pParams
            );
            m_params = value;
        }

    }
}