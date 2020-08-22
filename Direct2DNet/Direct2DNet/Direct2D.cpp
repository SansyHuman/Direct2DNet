#include "Direct2D.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        Direct2DNet::ID2D1Factory ^Direct2D::CreateFactory(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            System::Guid %guid,
            System::Nullable<Direct2DNet::D2D1_FACTORY_OPTIONS> options)
        {
            if(guid == D2DNet::D2DNetGUID::UID_ID2D1Factory)
            {
                if(options.HasValue)
                {
                    return gcnew Direct2DNet::ID2D1Factory(type, options.Value);
                }
                else
                {
                    return gcnew Direct2DNet::ID2D1Factory(type);
                }
            }
            else if(guid == D2DNet::D2DNetGUID::UID_ID2D1Factory1)
            {
                if(options.HasValue)
                {
                    return gcnew Direct2DNet::ID2D1Factory1(type, options.Value);
                }
                else
                {
                    return gcnew Direct2DNet::ID2D1Factory1(type);
                }
            }
            else if(guid == D2DNet::D2DNetGUID::UID_ID2D1Factory2)
            {
                if(options.HasValue)
                {
                    return gcnew Direct2DNet::ID2D1Factory2(type, options.Value);
                }
                else
                {
                    return gcnew Direct2DNet::ID2D1Factory2(type);
                }
            }
            else if(guid == D2DNet::D2DNetGUID::UID_ID2D1Factory3)
            {
                if(options.HasValue)
                {
                    return gcnew Direct2DNet::ID2D1Factory3(type, options.Value);
                }
                else
                {
                    return gcnew Direct2DNet::ID2D1Factory3(type);
                }
            }
            else if(guid == D2DNet::D2DNetGUID::UID_ID2D1Factory4)
            {
                if(options.HasValue)
                {
                    return gcnew Direct2DNet::ID2D1Factory4(type, options.Value);
                }
                else
                {
                    return gcnew Direct2DNet::ID2D1Factory4(type);
                }
            }
            else
            {
                throw gcnew Direct2DNet::Exception::DxException(
                    "Failed to create the factory.", E_NOINTERFACE
                );
            }
        }

        Direct2DNet::D2D1_COLOR_F Direct2D::ConvertColorSpace(
            Direct2DNet::D2D1_COLOR_SPACE sourceColorSpace,
            Direct2DNet::D2D1_COLOR_SPACE destinationColorSpace,
            Direct2DNet::D2D1_COLOR_F %color)
        {
            return static_cast<Direct2DNet::D2D1_COLOR_F>(
                D2D1ConvertColorSpace(
                (::D2D1_COLOR_SPACE)((int)sourceColorSpace),
                    (::D2D1_COLOR_SPACE)((int)destinationColorSpace),
                    &static_cast<::D2D1_COLOR_F>(color)
                )
                );
        }

        Direct2DNet::ID2D1Device ^Direct2D::CreateDevice(
            DXGINet::IDXGIDevice ^dxgiDevice,
            System::Nullable<Direct2DNet::D2D1_CREATION_PROPERTIES> creationProperties)
        {
            return gcnew Direct2DNet::ID2D1Device(dxgiDevice, creationProperties);
        }

        Direct2DNet::ID2D1DeviceContext ^Direct2D::CreateDeviceContext(
            DXGINet::IDXGISurface ^dxgiSurface,
            System::Nullable<Direct2DNet::D2D1_CREATION_PROPERTIES> creationProperties)
        {
            return gcnew Direct2DNet::ID2D1DeviceContext(dxgiSurface, creationProperties);
        }

        HRESULT Direct2D::SetDpiCompensatedEffectInput(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            Direct2DNet::ID2D1Effect ^effect,
            unsigned int inputIndex,
            Direct2DNet::ID2D1Bitmap ^inputBitmap,
            System::Nullable<Direct2DNet::D2D1_INTERPOLATION_MODE> interpolationMode,
            System::Nullable<Direct2DNet::Effects::D2D1_BORDER_MODE> borderMode)
        {
            if(!interpolationMode.HasValue)
                interpolationMode = Direct2DNet::D2D1_INTERPOLATION_MODE::LINEAR;
            
            if(!borderMode.HasValue)
                borderMode = Direct2DNet::Effects::D2D1_BORDER_MODE::HARD;

            HRESULT hr = S_OK;
            Direct2DNet::ID2D1Effect ^dpiCompensationEffect = nullptr;
            
            try
            {
                dpiCompensationEffect = deviceContext->CreateEffect(D2DNet::DirectX::ToManagedGUID(::CLSID_D2D1DpiCompensation));
            }
            catch(Direct2DNet::Exception::DxException ^e)
            {
                hr = e->HResult;
            }

            if(SUCCEEDED(hr))
            {
                if(SUCCEEDED(hr))
                {
                    dpiCompensationEffect->SetInput(0, inputBitmap, true);

                    Direct2DNet::D2D1_POINT_2F bitmapDpi;
                    bitmapDpi.x = inputBitmap->DpiX;
                    bitmapDpi.y = inputBitmap->DpiY;
                    hr = dpiCompensationEffect->SetValue(Effects::D2D1_DPICOMPENSATION_PROP::INPUT_DPI, bitmapDpi);
                }

                if(SUCCEEDED(hr))
                {
                    hr = dpiCompensationEffect->SetValue(Effects::D2D1_DPICOMPENSATION_PROP::INTERPOLATION_MODE, interpolationMode.Value);
                }

                if(SUCCEEDED(hr))
                {
                    hr = dpiCompensationEffect->SetValue(Effects::D2D1_DPICOMPENSATION_PROP::BORDER_MODE, borderMode.Value);
                }

                if(SUCCEEDED(hr))
                {
                    effect->SetInputEffect(inputIndex, dpiCompensationEffect, true);
                }
            }

            return hr;
        }

        float Direct2D::ComputeMaximumScaleFactor(Direct2DNet::D2D1_MATRIX_3X2_F %matrix)
        {
            return D2D1ComputeMaximumScaleFactor(
                &static_cast<::D2D1_MATRIX_3X2_F>(matrix)
            );
        }

        float Direct2D::ComputeFlatteningTolerance(Direct2DNet::D2D1_MATRIX_3X2_F %matrix, System::Nullable<float> dpiX, System::Nullable<float> dpiY, System::Nullable<float> maxZoomFactor)
        {
            if(!dpiX.HasValue)
                dpiX = 96.0f;

            if(!dpiY.HasValue)
                dpiY = 96.0f;

            if(!maxZoomFactor.HasValue)
                maxZoomFactor = 1.0f;

            Direct2DNet::D2D1_MATRIX_3X2_F dpiDependentTransform = matrix * Direct2DNet::D2D1_MATRIX_3X2_F::Scale(
                dpiX.Value / 96.0f,
                dpiY.Value / 96.0f,
                Direct2DNet::D2D1_POINT_2F(0, 0));

            float absMaxZoomFactor = (maxZoomFactor.Value > 0) ? maxZoomFactor.Value : -maxZoomFactor.Value;

            return Direct2D::DEFAULT_FLATTENING_TOLERANCE /
                (absMaxZoomFactor * ComputeMaximumScaleFactor(dpiDependentTransform));
        }

        Direct2DNet::D2D1_GRADIENT_MESH_PATCH Direct2D::GradientMeshPatchFromCoonsPatch(
            Direct2DNet::D2D1_POINT_2F point0,
            Direct2DNet::D2D1_POINT_2F point1,
            Direct2DNet::D2D1_POINT_2F point2,
            Direct2DNet::D2D1_POINT_2F point3,
            Direct2DNet::D2D1_POINT_2F point4,
            Direct2DNet::D2D1_POINT_2F point5,
            Direct2DNet::D2D1_POINT_2F point6,
            Direct2DNet::D2D1_POINT_2F point7,
            Direct2DNet::D2D1_POINT_2F point8,
            Direct2DNet::D2D1_POINT_2F point9,
            Direct2DNet::D2D1_POINT_2F point10,
            Direct2DNet::D2D1_POINT_2F point11,
            Direct2DNet::D2D1_COLOR_F color0,
            Direct2DNet::D2D1_COLOR_F color1,
            Direct2DNet::D2D1_COLOR_F color2,
            Direct2DNet::D2D1_COLOR_F color3,
            Direct2DNet::D2D1_PATCH_EDGE_MODE topEdgeMode,
            Direct2DNet::D2D1_PATCH_EDGE_MODE leftEdgeMode,
            Direct2DNet::D2D1_PATCH_EDGE_MODE bottomEdgeMode,
            Direct2DNet::D2D1_PATCH_EDGE_MODE rightEdgeMode)
        {
            Direct2DNet::D2D1_GRADIENT_MESH_PATCH newPatch;
            newPatch.point00 = point0;
            newPatch.point01 = point1;
            newPatch.point02 = point2;
            newPatch.point03 = point3;
            newPatch.point13 = point4;
            newPatch.point23 = point5;
            newPatch.point33 = point6;
            newPatch.point32 = point7;
            newPatch.point31 = point8;
            newPatch.point30 = point9;
            newPatch.point20 = point10;
            newPatch.point10 = point11;

            ::D2D1GetGradientMeshInteriorPointsFromCoonsPatch(
                (::D2D1_POINT_2F *)&point0,
                (::D2D1_POINT_2F *)&point1,
                (::D2D1_POINT_2F *)&point2,
                (::D2D1_POINT_2F *)&point3,
                (::D2D1_POINT_2F *)&point4,
                (::D2D1_POINT_2F *)&point5,
                (::D2D1_POINT_2F *)&point6,
                (::D2D1_POINT_2F *)&point7,
                (::D2D1_POINT_2F *)&point8,
                (::D2D1_POINT_2F *)&point9,
                (::D2D1_POINT_2F *)&point10,
                (::D2D1_POINT_2F *)&point11,
                (::D2D1_POINT_2F *)&newPatch.point11,
                (::D2D1_POINT_2F *)&newPatch.point12,
                (::D2D1_POINT_2F *)&newPatch.point21,
                (::D2D1_POINT_2F *)&newPatch.point22
            );

            newPatch.color00 = color0;
            newPatch.color03 = color1;
            newPatch.color33 = color2;
            newPatch.color30 = color3;
            newPatch.topEdgeMode = topEdgeMode;
            newPatch.leftEdgeMode = leftEdgeMode;
            newPatch.bottomEdgeMode = bottomEdgeMode;
            newPatch.rightEdgeMode = rightEdgeMode;

            return newPatch;
        }

    }
}