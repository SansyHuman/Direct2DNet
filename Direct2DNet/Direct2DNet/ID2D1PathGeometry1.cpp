#include "ID2D1PathGeometry1.h"
#include "ID2D1Factory1.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1PathGeometry1::ID2D1PathGeometry1(Direct2DNet::ID2D1Factory1 ^factory)
            : Direct2DNet::ID2D1PathGeometry(factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1Factory1 *)factory->m_pFactory)->CreatePathGeometry(
                (::ID2D1PathGeometry1 **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1PathGeometry1", (int)hr);
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_POINT_DESCRIPTION> ID2D1PathGeometry1::ComputePointAndSegmentAtLength(
            float length,
            unsigned int startSegment,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;
            ::D2D1_POINT_DESCRIPTION description;

            hr = ((::ID2D1PathGeometry1 *)m_pResource)->ComputePointAndSegmentAtLength(
                length,
                startSegment,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &description
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_POINT_DESCRIPTION>(
                hr,
                static_cast<Direct2DNet::D2D1_POINT_DESCRIPTION>(description)
                );
        }

        HRESULT ID2D1PathGeometry1::ComputePointAndSegmentAtLength(
            Direct2DNet::D2D1_POINT_DESCRIPTION %pointDescription,
            float length,
            unsigned int startSegment,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;
            ::D2D1_POINT_DESCRIPTION description;

            hr = ((::ID2D1PathGeometry1 *)m_pResource)->ComputePointAndSegmentAtLength(
                length,
                startSegment,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &description
            );

            pointDescription = static_cast<Direct2DNet::D2D1_POINT_DESCRIPTION>(description);

            return hr;
        }

    }
}