#include "ID2D1SpriteBatch.h"
#include "ID2D1DeviceContext3.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1SpriteBatch::ID2D1SpriteBatch(Direct2DNet::ID2D1DeviceContext3 ^context)
            : Direct2DNet::ID2D1Resource(context->m_factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext3 *)context->m_pResource)->CreateSpriteBatch(
                (::ID2D1SpriteBatch **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1SpriteBatch", (int)hr);
        }

        HRESULT ID2D1SpriteBatch::AddSprites(
            UINT32 spriteCount,
            array<Direct2DNet::D2D1_RECT_F> ^destinationRectangles,
            array<Direct2DNet::D2D1_RECT_U> ^sourceRectangles,
            array<Direct2DNet::D2D1_COLOR_F> ^colors,
            array<Direct2DNet::D2D1_MATRIX_3X2_F> ^transforms,
            System::Nullable<UINT32> destinationRectanglesStride,
            System::Nullable<UINT32> sourceRectanglesStride,
            System::Nullable<UINT32> colorsStride,
            System::Nullable<UINT32> transformsStride)
        {
            if(destinationRectangles->Length == 0)
                return E_INVALIDARG;

            if(!destinationRectanglesStride.HasValue)
                destinationRectanglesStride = sizeof(Direct2DNet::D2D1_RECT_F);

            if(!sourceRectanglesStride.HasValue)
                sourceRectanglesStride = sizeof(Direct2DNet::D2D1_RECT_U);

            if(!colorsStride.HasValue)
                colorsStride = sizeof(Direct2DNet::D2D1_COLOR_F);

            if(!transformsStride.HasValue)
                transformsStride = sizeof(Direct2DNet::D2D1_MATRIX_3X2_F);

            pin_ptr<Direct2DNet::D2D1_RECT_F> pDest = &destinationRectangles[0];

            pin_ptr<Direct2DNet::D2D1_RECT_U> pSrc = nullptr;
            if(sourceRectangles && sourceRectangles->Length > 0)
                pSrc = &sourceRectangles[0];

            pin_ptr<Direct2DNet::D2D1_COLOR_F> pColor = nullptr;
            if(colors && colors->Length > 0)
                pColor = &colors[0];

            pin_ptr<Direct2DNet::D2D1_MATRIX_3X2_F> pTr = nullptr;
            if(transforms && transforms->Length > 0)
                pTr = &transforms[0];

            return ((::ID2D1SpriteBatch *)m_pResource)->AddSprites(
                spriteCount,
                (::D2D1_RECT_F *)pDest,
                (::D2D1_RECT_U *)pSrc,
                (::D2D1_COLOR_F *)pColor,
                (::D2D1_MATRIX_3X2_F *)pTr,
                destinationRectanglesStride.Value,
                sourceRectanglesStride.Value,
                colorsStride.Value,
                transformsStride.Value
            );
        }

        HRESULT ID2D1SpriteBatch::SetSprites(
            UINT32 startIndex,
            UINT32 spriteCount,
            array<Direct2DNet::D2D1_RECT_F> ^destinationRectangles,
            array<Direct2DNet::D2D1_RECT_U> ^sourceRectangles,
            array<Direct2DNet::D2D1_COLOR_F> ^colors,
            array<Direct2DNet::D2D1_MATRIX_3X2_F> ^transforms,
            System::Nullable<UINT32> destinationRectanglesStride,
            System::Nullable<UINT32> sourceRectanglesStride,
            System::Nullable<UINT32> colorsStride,
            System::Nullable<UINT32> transformsStride)
        {
            if(!destinationRectanglesStride.HasValue)
                destinationRectanglesStride = sizeof(Direct2DNet::D2D1_RECT_F);

            if(!sourceRectanglesStride.HasValue)
                sourceRectanglesStride = sizeof(Direct2DNet::D2D1_RECT_U);

            if(!colorsStride.HasValue)
                colorsStride = sizeof(Direct2DNet::D2D1_COLOR_F);

            if(!transformsStride.HasValue)
                transformsStride = sizeof(Direct2DNet::D2D1_MATRIX_3X2_F);

            pin_ptr<Direct2DNet::D2D1_RECT_F> pDest = nullptr;
            if(destinationRectangles && destinationRectangles->Length > 0)
                pDest = &destinationRectangles[0];

            pin_ptr<Direct2DNet::D2D1_RECT_U> pSrc = nullptr;
            if(sourceRectangles && sourceRectangles->Length > 0)
                pSrc = &sourceRectangles[0];

            pin_ptr<Direct2DNet::D2D1_COLOR_F> pColor = nullptr;
            if(colors && colors->Length > 0)
                pColor = &colors[0];

            pin_ptr<Direct2DNet::D2D1_MATRIX_3X2_F> pTr = nullptr;
            if(transforms && transforms->Length > 0)
                pTr = &transforms[0];

            return ((::ID2D1SpriteBatch *)m_pResource)->SetSprites(
                startIndex,
                spriteCount,
                (::D2D1_RECT_F *)pDest,
                (::D2D1_RECT_U *)pSrc,
                (::D2D1_COLOR_F *)pColor,
                (::D2D1_MATRIX_3X2_F *)pTr,
                destinationRectanglesStride.Value,
                sourceRectanglesStride.Value,
                colorsStride.Value,
                transformsStride.Value
            );
        }

        HRESULT ID2D1SpriteBatch::GetSprites(
            UINT32 startIndex,
            UINT32 spriteCount,
            array<Direct2DNet::D2D1_RECT_F> ^destinationRectangles,
            array<Direct2DNet::D2D1_RECT_U> ^sourceRectangles,
            array<Direct2DNet::D2D1_COLOR_F> ^colors,
            array<Direct2DNet::D2D1_MATRIX_3X2_F> ^transforms)
        {
            pin_ptr<Direct2DNet::D2D1_RECT_F> pDest = nullptr;
            if(destinationRectangles && destinationRectangles->Length > 0)
                pDest = &destinationRectangles[0];

            pin_ptr<Direct2DNet::D2D1_RECT_U> pSrc = nullptr;
            if(sourceRectangles && sourceRectangles->Length > 0)
                pSrc = &sourceRectangles[0];

            pin_ptr<Direct2DNet::D2D1_COLOR_F> pColor = nullptr;
            if(colors && colors->Length > 0)
                pColor = &colors[0];

            pin_ptr<Direct2DNet::D2D1_MATRIX_3X2_F> pTr = nullptr;
            if(transforms && transforms->Length > 0)
                pTr = &transforms[0];

            return ((::ID2D1SpriteBatch *)m_pResource)->GetSprites(
                startIndex,
                spriteCount,
                (::D2D1_RECT_F *)pDest,
                (::D2D1_RECT_U *)pSrc,
                (::D2D1_COLOR_F *)pColor,
                (::D2D1_MATRIX_3X2_F *)pTr
            );
        }

        void ID2D1SpriteBatch::Clear()
        {
            ((::ID2D1SpriteBatch *)m_pResource)->Clear();
        }

    }
}