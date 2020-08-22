#include "ID2D1InkStyle.h"
#include "ID2D1DeviceContext2.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1InkStyle::ID2D1InkStyle(
            Direct2DNet::ID2D1DeviceContext2 ^context, 
            System::Nullable<Direct2DNet::D2D1_INK_STYLE_PROPERTIES> %prop)
            : Direct2DNet::ID2D1Resource(context->m_factory)
        {
            HRESULT hr = S_OK;

            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            pin_ptr<Direct2DNet::D2D1_INK_STYLE_PROPERTIES> pProp = nullptr;
            if(prop.HasValue)
                pProp = &prop.Value;
            hr = ((::ID2D1DeviceContext2 *)context->m_pResource)->CreateInkStyle(
                reinterpret_cast<::D2D1_INK_STYLE_PROPERTIES *>(pProp),
                (::ID2D1InkStyle **)ppResource
            );
            ppResource = nullptr;
            pProp = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1InkStyle", (int)hr);
        }
    }
}