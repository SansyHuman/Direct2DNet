#include "ID2D1DeviceContext3.h"
#include "ID2D1Device3.h"
#include "ID2D1SpriteBatch.h"
#include "ID2D1Bitmap.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DeviceContext3::ID2D1DeviceContext3(
            Direct2DNet::ID2D1Device3 ^device,
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
            : Direct2DNet::ID2D1DeviceContext2(device, options)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = ((::ID2D1Device3 *)device->m_pResource)->CreateDeviceContext(
                (::D2D1_DEVICE_CONTEXT_OPTIONS)((int)options),
                (::ID2D1DeviceContext3 **)ppRenderTarget
            );
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DeviceContext3", (int)hr);
        }

        Direct2DNet::ID2D1SpriteBatch ^ID2D1DeviceContext3::CreateSpriteBatch()
        {
            return gcnew Direct2DNet::ID2D1SpriteBatch(this);
        }

        void ID2D1DeviceContext3::DrawSpriteBatch(
            Direct2DNet::ID2D1SpriteBatch ^spriteBatch,
            UINT32 startIndex,
            UINT32 spriteCount,
            Direct2DNet::ID2D1Bitmap ^bitmap,
            System::Nullable<Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE> interpolationMode,
            System::Nullable<Direct2DNet::D2D1_SPRITE_OPTIONS> spriteOptions)
        {
            if(AntialiasMode != Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED)
            {
                AntialiasMode = Direct2DNet::D2D1_ANTIALIAS_MODE::ALIASED;
                D2DNet::DirectX::PrintDebugMessage("Direct2DNet Warning: You tried to draw sprite when the antialias mode of the render target is not D2D1_ANTIALIAS_MODE::ALIASED. Forced to change to aliased mode.");
            }

            if(!interpolationMode.HasValue)
                interpolationMode = Direct2DNet::D2D1_BITMAP_INTERPOLATION_MODE::LINEAR;

            if(!spriteOptions.HasValue)
                spriteOptions = Direct2DNet::D2D1_SPRITE_OPTIONS::NONE;

            ((::ID2D1DeviceContext3 *)m_pResource)->DrawSpriteBatch(
                (::ID2D1SpriteBatch *)spriteBatch->m_pResource,
                startIndex,
                spriteCount,
                (::ID2D1Bitmap *)bitmap->m_pResource,
                (::D2D1_BITMAP_INTERPOLATION_MODE)((int)interpolationMode.Value),
                (::D2D1_SPRITE_OPTIONS)((int)spriteOptions.Value)
            );
        }

    }
}