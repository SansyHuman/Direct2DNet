#include "ID2D1DeviceContext2.h"
#include "ID2D1Device2.h"
#include "ID2D1Ink.h"
#include "ID2D1InkStyle.h"
#include "ID2D1GradientMesh.h"
#include "ID2D1LookupTable3D.h"
#include "ID2D1ImageSource.h"
#include "ID2D1ImageSourceFromWic.h"
#include "ID2D1Brush.h"
#include "ID2D1GdiMetafile.h"
#include "ID2D1TransformedImageSource.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1DeviceContext2::ID2D1DeviceContext2(
            Direct2DNet::ID2D1Device3 ^device,
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
            : Direct2DNet::ID2D1DeviceContext1((Direct2DNet::ID2D1Device2 ^)device, options)
        {
            
        }

        ID2D1DeviceContext2::ID2D1DeviceContext2(
            Direct2DNet::ID2D1Device2 ^device,
            Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options)
            : Direct2DNet::ID2D1DeviceContext1(device, options)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppRenderTarget = &m_pResource;
            hr = ((::ID2D1Device2 *)device->m_pResource)->CreateDeviceContext(
                (::D2D1_DEVICE_CONTEXT_OPTIONS)((int)options),
                (::ID2D1DeviceContext2 **)ppRenderTarget
            );
            ppRenderTarget = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1DeviceContext2", (int)hr);
        }

        Direct2DNet::ID2D1Ink ^ID2D1DeviceContext2::CreateInk(Direct2DNet::D2D1_INK_POINT %startPoint)
        {
            return gcnew Direct2DNet::ID2D1Ink(this, startPoint);
        }

        Direct2DNet::ID2D1InkStyle ^ID2D1DeviceContext2::CreateInkStyle(
            System::Nullable<Direct2DNet::D2D1_INK_STYLE_PROPERTIES> inkStyleProperties)
        {
            return gcnew Direct2DNet::ID2D1InkStyle(this, inkStyleProperties);
        }

        Direct2DNet::ID2D1GradientMesh ^ID2D1DeviceContext2::CreateGradientMesh(
            ...array<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> ^patches)
        {
            return gcnew Direct2DNet::ID2D1GradientMesh(this, patches);
        }

        Direct2DNet::ID2D1ImageSourceFromWic ^ID2D1DeviceContext2::CreateImageSourceFromWic(
            D2DNet::WICNet::IWICBitmapSource ^wicBitmapSource,
            Direct2DNet::D2D1_IMAGE_SOURCE_LOADING_OPTIONS loadingOptions,
            Direct2DNet::D2D1_ALPHA_MODE alphaMode)
        {
            return gcnew Direct2DNet::ID2D1ImageSourceFromWic(this, wicBitmapSource, loadingOptions, alphaMode);
        }

        Direct2DNet::Effects::ID2D1LookupTable3D ^ID2D1DeviceContext2::CreateLookupTable3D(
            Direct2DNet::D2D1_BUFFER_PRECISION precision,
            System::ValueTuple<UINT32, UINT32, UINT32> %extents,
            array<BYTE> ^data,
            System::ValueTuple<UINT32, UINT32> %strides)
        {
            return gcnew Direct2DNet::Effects::ID2D1LookupTable3D(
                this,
                precision,
                extents,
                data,
                strides
            );
        }

        Direct2DNet::ID2D1ImageSource ^ID2D1DeviceContext2::CreateImageSourceFromDxgi(
            array<DXGINet::IDXGISurface ^> ^surfaces,
            DXGINet::DXGI_COLOR_SPACE_TYPE colorSpace,
            Direct2DNet::D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS options)
        {
            return gcnew Direct2DNet::ID2D1ImageSource(this, surfaces, colorSpace, options);
        }

        HRESULT ID2D1DeviceContext2::GetGradientMeshWorldBounds(
            Direct2DNet::ID2D1GradientMesh ^gradientMesh,
            Direct2DNet::D2D1_RECT_F %bounds)
        {
            pin_ptr<Direct2DNet::D2D1_RECT_F> pBounds = &bounds;
            return ((::ID2D1DeviceContext2 *)m_pResource)->GetGradientMeshWorldBounds(
                (::ID2D1GradientMesh *)gradientMesh->m_pResource,
                reinterpret_cast<::D2D1_RECT_F *>(pBounds)
            );
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> ID2D1DeviceContext2::GetGradientMeshWorldBounds(
            Direct2DNet::ID2D1GradientMesh ^gradientMesh)
        {
            Direct2DNet::D2D1_RECT_F bounds;
            HRESULT hr = ((::ID2D1DeviceContext2 *)m_pResource)->GetGradientMeshWorldBounds(
                (::ID2D1GradientMesh *)gradientMesh->m_pResource,
                reinterpret_cast<::D2D1_RECT_F *>(&bounds)
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F>(hr, bounds);
        }

        void ID2D1DeviceContext2::DrawInk(
            Direct2DNet::ID2D1Ink ^ink,
            Direct2DNet::ID2D1Brush ^brush,
            Direct2DNet::ID2D1InkStyle ^inkStyle)
        {
            ((::ID2D1DeviceContext2 *)m_pResource)->DrawInk(
                (::ID2D1Ink *)ink->m_pResource,
                (::ID2D1Brush *)brush->m_pResource,
                inkStyle ? (::ID2D1InkStyle *)inkStyle->m_pResource : __nullptr
            );
        }

        void ID2D1DeviceContext2::DrawGradientMesh(Direct2DNet::ID2D1GradientMesh ^gradientMesh)
        {
            ((::ID2D1DeviceContext2 *)m_pResource)->DrawGradientMesh(
                (::ID2D1GradientMesh *)gradientMesh->m_pResource
            );
        }

        void ID2D1DeviceContext2::DrawGdiMetafile(
            Direct2DNet::ID2D1GdiMetafile ^gdiMetafile,
            System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
            System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle)
        {
            ((::ID2D1DeviceContext2 *)m_pResource)->DrawGdiMetafile(
                (::ID2D1GdiMetafile *)gdiMetafile->m_pResource,
                destinationRectangle.HasValue ? (::D2D1_RECT_F *)&destinationRectangle.Value : __nullptr,
                sourceRectangle.HasValue ? (::D2D1_RECT_F *)&sourceRectangle.Value : __nullptr
            );
        }

        Direct2DNet::ID2D1TransformedImageSource ^ID2D1DeviceContext2::CreateTransformedImageSource(
            Direct2DNet::ID2D1ImageSource ^imageSource,
            Direct2DNet::D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES %properties)
        {
            return gcnew Direct2DNet::ID2D1TransformedImageSource(this, imageSource, properties);
        }

    }
}