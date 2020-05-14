#include "ID2D1Layer.h"
#include "ID2D1RenderTarget.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Layer::ID2D1Layer(
            Direct2DNet::ID2D1RenderTarget ^renderTarget,
            System::Nullable<Direct2DNet::D2D1_SIZE_F> %size)
            : Direct2DNet::ID2D1Resource(renderTarget->m_factory)
        {
            ::D2D1_SIZE_F nativeSize;
            if(size.HasValue)
                nativeSize = static_cast<::D2D1_SIZE_F>(size.Value);

            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateLayer(
                size.HasValue ? &nativeSize : __nullptr,
                (::ID2D1Layer **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Layer", (int)hr);
        }

    }
}