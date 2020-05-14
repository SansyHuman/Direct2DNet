#include "ID2D1Geometry.h"
#include "ID2D1StrokeStyle.h"
#include "ID2D1PathGeometry.h"
#include "ID2D1Mesh.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> ID2D1Geometry::GetBounds(System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            ::D2D1_RECT_F bounds;
            HRESULT hr = S_OK;

            hr = ((::ID2D1Geometry *)m_pResource)->GetBounds(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                &bounds
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F>(
                hr,
                static_cast<Direct2DNet::D2D1_RECT_F>(bounds)
                );
        }

        HRESULT ID2D1Geometry::GetBounds(
            Direct2DNet::D2D1_RECT_F %bounds, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            ::D2D1_RECT_F nativeBounds;
            HRESULT hr = S_OK;

            hr = ((::ID2D1Geometry *)m_pResource)->GetBounds(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                &nativeBounds
            );

            bounds = static_cast<Direct2DNet::D2D1_RECT_F>(nativeBounds);

            return hr;
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> ID2D1Geometry::GetWidenedBounds(
            float strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            ::D2D1_RECT_F bounds;

            HRESULT hr = S_OK;
            hr = ((::ID2D1Geometry *)m_pResource)->GetWidenedBounds(
                strokeWidth,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &bounds
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F>(
                hr,
                static_cast<Direct2DNet::D2D1_RECT_F>(bounds)
                );
        }

        HRESULT ID2D1Geometry::GetWidenedBounds(
            Direct2DNet::D2D1_RECT_F %bounds, 
            float strokeWidth, 
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform, 
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            ::D2D1_RECT_F nativeBounds;

            HRESULT hr = S_OK;
            hr = ((::ID2D1Geometry *)m_pResource)->GetWidenedBounds(
                strokeWidth,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &nativeBounds
            );

            bounds = static_cast<Direct2DNet::D2D1_RECT_F>(nativeBounds);

            return hr;
        }

        System::ValueTuple<HRESULT, bool> ID2D1Geometry::StrokeContainsPoint(
            Direct2DNet::D2D1_POINT_2F %point,
            float strokeWidth,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            BOOL contains;
            HRESULT hr = S_OK;

            hr = ((::ID2D1Geometry *)m_pResource)->StrokeContainsPoint(
                static_cast<::D2D1_POINT_2F>(point),
                strokeWidth,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &contains
            );

            return System::ValueTuple<HRESULT, bool>(
                hr,
                System::Convert::ToBoolean(contains)
                );
        }

        HRESULT ID2D1Geometry::StrokeContainsPoint(
            bool %contains, 
            Direct2DNet::D2D1_POINT_2F %point, 
            float strokeWidth, 
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform, 
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            pin_ptr<bool> pContains = &contains;
            hr = ((::ID2D1Geometry *)m_pResource)->StrokeContainsPoint(
                static_cast<::D2D1_POINT_2F>(point),
                strokeWidth,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                (BOOL *)pContains
            );
            pContains = nullptr;

            return hr;
        }

        System::ValueTuple<HRESULT, bool> ID2D1Geometry::FillContainsPoint(
            Direct2DNet::D2D1_POINT_2F %point,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            BOOL contains;
            HRESULT hr = S_OK;

            hr = ((::ID2D1Geometry *)m_pResource)->FillContainsPoint(
                point,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &contains
            );

            return System::ValueTuple<HRESULT, bool>(
                hr,
                System::Convert::ToBoolean(contains)
                );
        }

        HRESULT ID2D1Geometry::FillContainsPoint(
            bool %contains, 
            Direct2DNet::D2D1_POINT_2F %point, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform, 
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            pin_ptr<bool> pContains = &contains;
            hr = ((::ID2D1Geometry *)m_pResource)->FillContainsPoint(
                point,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                (BOOL *)pContains
            );
            pContains = nullptr;

            return hr;
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_GEOMETRY_RELATION> ID2D1Geometry::CompareWithGeometry(
            Direct2DNet::ID2D1Geometry ^inputGeometry,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> inputGeometryTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!inputGeometryTransform.HasValue)
                inputGeometryTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            ::D2D1_GEOMETRY_RELATION relation = D2D1_GEOMETRY_RELATION_UNKNOWN;
            HRESULT hr = S_OK;

            hr = ((::ID2D1Geometry *)m_pResource)->CompareWithGeometry(
                (::ID2D1Geometry *)inputGeometry->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(inputGeometryTransform.Value),
                flatteningTolerance.Value,
                &relation
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_GEOMETRY_RELATION>(
                hr,
                (Direct2DNet::D2D1_GEOMETRY_RELATION)((int)relation)
                );
        }

        HRESULT ID2D1Geometry::CompareWithGeometry(
            Direct2DNet::D2D1_GEOMETRY_RELATION %relation,
            Direct2DNet::ID2D1Geometry ^inputGeometry, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> inputGeometryTransform, 
            System::Nullable<float> flatteningTolerance)
        {
            if(!inputGeometryTransform.HasValue)
                inputGeometryTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            ::D2D1_GEOMETRY_RELATION nativeRelation = D2D1_GEOMETRY_RELATION_UNKNOWN;
            HRESULT hr = S_OK;

            hr = ((::ID2D1Geometry *)m_pResource)->CompareWithGeometry(
                (::ID2D1Geometry *)inputGeometry->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(inputGeometryTransform.Value),
                flatteningTolerance.Value,
                &nativeRelation
            );

            relation = (Direct2DNet::D2D1_GEOMETRY_RELATION)((int)nativeRelation);

            return hr;
        }

        HRESULT ID2D1Geometry::Simplify(
            Direct2DNet::D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption,
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;
            if(!dstGeometry->SinkOpened)
                return D2DERR_WRONG_STATE;

            hr = ((::ID2D1Geometry *)m_pResource)->Simplify(
                (::D2D1_GEOMETRY_SIMPLIFICATION_OPTION)((int)simplificationOption),
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                dstGeometry->m_pSink
            );

            return hr;
        }

        HRESULT ID2D1Geometry::Tessellate(
            Direct2DNet::ID2D1Mesh ^mesh,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;
            if(!mesh->SinkOpened)
                return D2DERR_WRONG_STATE;

            hr = ((::ID2D1Geometry *)m_pResource)->Tessellate(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                mesh->m_pSink
            );

            return hr;
        }

        HRESULT ID2D1Geometry::CombineWithGeometry(
            Direct2DNet::ID2D1Geometry ^inputGeometry,
            Direct2DNet::D2D1_COMBINE_MODE combineMode,
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> inputGeometryTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!inputGeometryTransform.HasValue)
                inputGeometryTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;
            if(!dstGeometry->SinkOpened)
                return D2DERR_WRONG_STATE;

            hr = ((::ID2D1Geometry *)m_pResource)->CombineWithGeometry(
                (::ID2D1Geometry *)inputGeometry->m_pResource,
                (::D2D1_COMBINE_MODE)((int)combineMode),
                static_cast<::D2D1_MATRIX_3X2_F>(inputGeometryTransform.Value),
                flatteningTolerance.Value,
                dstGeometry->m_pSink
            );

            return hr;
        }

        HRESULT ID2D1Geometry::Outline(
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;
            if(!dstGeometry->SinkOpened)
                return D2DERR_WRONG_STATE;

            hr = ((::ID2D1Geometry *)m_pResource)->Outline(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                dstGeometry->m_pSink
            );

            return hr;
        }

        System::ValueTuple<HRESULT, float> ID2D1Geometry::ComputeArea(
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            float area = 0;
            hr = ((::ID2D1Geometry *)m_pResource)->ComputeArea(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &area
            );

            return System::ValueTuple<HRESULT, float>(hr, area);
        }

        HRESULT ID2D1Geometry::ComputeArea(
            float %area, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform, 
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            pin_ptr<float> pArea = &area;
            hr = ((::ID2D1Geometry *)m_pResource)->ComputeArea(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                (FLOAT *)pArea
            );
            pArea = nullptr;

            return hr;
        }

        System::ValueTuple<HRESULT, float> ID2D1Geometry::ComputeLength(
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            float length = 0;
            hr = ((::ID2D1Geometry *)m_pResource)->ComputeLength(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &length
            );

            return System::ValueTuple<HRESULT, float>(hr, length);
        }

        HRESULT ID2D1Geometry::ComputeLength(
            float %length, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform, 
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            pin_ptr<float> pLength = &length;
            hr = ((::ID2D1Geometry *)m_pResource)->ComputeLength(
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                (FLOAT *)pLength
            );
            pLength = nullptr;

            return hr;
        }

        System::ValueTuple<HRESULT, Direct2DNet::D2D1_POINT_2F, Direct2DNet::D2D1_POINT_2F> ID2D1Geometry::ComputePointAtLength(
            float length,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            ::D2D1_POINT_2F point;
            ::D2D1_POINT_2F tangent;
            hr = ((::ID2D1Geometry *)m_pResource)->ComputePointAtLength(
                length,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &point,
                &tangent
            );

            return System::ValueTuple<HRESULT, Direct2DNet::D2D1_POINT_2F, Direct2DNet::D2D1_POINT_2F>(
                hr,
                static_cast<Direct2DNet::D2D1_POINT_2F>(point),
                static_cast<Direct2DNet::D2D1_POINT_2F>(tangent)
                );
        }

        HRESULT ID2D1Geometry::ComputePointAtLength(
            Direct2DNet::D2D1_POINT_2F %point, 
            Direct2DNet::D2D1_POINT_2F %tangent, 
            float length, 
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform, 
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            ::D2D1_POINT_2F nativePoint;
            ::D2D1_POINT_2F nativeTangent;
            hr = ((::ID2D1Geometry *)m_pResource)->ComputePointAtLength(
                length,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                &nativePoint,
                &nativeTangent
            );

            point = static_cast<Direct2DNet::D2D1_POINT_2F>(nativePoint);
            tangent = static_cast<Direct2DNet::D2D1_POINT_2F>(nativeTangent);

            return hr;
        }

        HRESULT ID2D1Geometry::Widen(
            float strokeWidth,
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            Direct2DNet::ID2D1StrokeStyle ^strokeStyle,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            System::Nullable<float> flatteningTolerance)
        {
            if(!worldTransform.HasValue)
                worldTransform = Direct2DNet::D2D1_MATRIX_3X2_F::Identity;

            if(!flatteningTolerance.HasValue)
                flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE;

            HRESULT hr = S_OK;

            hr = ((::ID2D1Geometry *)m_pResource)->Widen(
                strokeWidth,
                strokeStyle == nullptr ? __nullptr : (::ID2D1StrokeStyle *)strokeStyle->m_pResource,
                static_cast<::D2D1_MATRIX_3X2_F>(worldTransform.Value),
                flatteningTolerance.Value,
                dstGeometry->m_pSink
            );

            return hr;
        }

        Direct2DNet::ID2D1PathGeometry ^ID2D1Geometry::operator|(
            ID2D1Geometry ^lhs,
            System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs)
        {
            Direct2DNet::ID2D1PathGeometry ^or = rhs.Item1->CreatePathGeometry();
            or ->OpenSink();
            HRESULT hr = lhs->CombineWithGeometry(rhs.Item2, Direct2DNet::D2D1_COMBINE_MODE::MODE_UNION, or , Direct2DNet::D2D1_MATRIX_3X2_F::Identity, D2D1_DEFAULT_FLATTENING_TOLERANCE);
            or ->CloseSink();

            if(FAILED(hr))
            {
                delete or ;
                throw gcnew Direct2DNet::Exception::DxException("Failed to combine two geometries", hr);
            }

            return or ;
        }

        Direct2DNet::ID2D1PathGeometry ^ID2D1Geometry::operator&(
            ID2D1Geometry ^lhs,
            System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs)
        {
            Direct2DNet::ID2D1PathGeometry ^and= rhs.Item1->CreatePathGeometry();
            and ->OpenSink();
            HRESULT hr = lhs->CombineWithGeometry(rhs.Item2, Direct2DNet::D2D1_COMBINE_MODE::MODE_INTERSECT, and, Direct2DNet::D2D1_MATRIX_3X2_F::Identity, D2D1_DEFAULT_FLATTENING_TOLERANCE);
            and ->CloseSink();

            if(FAILED(hr))
            {
                delete and;
                throw gcnew Direct2DNet::Exception::DxException("Failed to combine two geometries", hr);
            }

            return and;
        }

        Direct2DNet::ID2D1PathGeometry ^ID2D1Geometry::operator^(
            ID2D1Geometry ^lhs,
            System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs)
        {
            Direct2DNet::ID2D1PathGeometry ^xor= rhs.Item1->CreatePathGeometry();
            xor->OpenSink();
            HRESULT hr = lhs->CombineWithGeometry(rhs.Item2, Direct2DNet::D2D1_COMBINE_MODE::MODE_XOR, xor, Direct2DNet::D2D1_MATRIX_3X2_F::Identity, D2D1_DEFAULT_FLATTENING_TOLERANCE);
            xor->CloseSink();

            if(FAILED(hr))
            {
                delete xor;
                throw gcnew Direct2DNet::Exception::DxException("Failed to combine two geometries", hr);
            }

            return xor;
        }

        Direct2DNet::ID2D1PathGeometry ^ID2D1Geometry::operator-(ID2D1Geometry ^lhs, System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs)
        {
            Direct2DNet::ID2D1PathGeometry ^sub = rhs.Item1->CreatePathGeometry();
            sub->OpenSink();
            HRESULT hr = lhs->CombineWithGeometry(rhs.Item2, Direct2DNet::D2D1_COMBINE_MODE::MODE_EXCLUDE, sub, Direct2DNet::D2D1_MATRIX_3X2_F::Identity, D2D1_DEFAULT_FLATTENING_TOLERANCE);
            sub->CloseSink();

            if(FAILED(hr))
            {
                delete sub;
                throw gcnew Direct2DNet::Exception::DxException("Failed to combine two geometries", hr);
            }

            return sub;
        }

    }
}