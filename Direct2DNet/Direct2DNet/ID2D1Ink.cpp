#include "ID2D1Ink.h"
#include "ID2D1DeviceContext2.h"
#include "ID2D1PathGeometry.h"
#include "ID2D1InkStyle.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Ink::ID2D1Ink(Direct2DNet::ID2D1DeviceContext2 ^context, Direct2DNet::D2D1_INK_POINT %start)
            : Direct2DNet::ID2D1Resource(context->m_factory)
        {
            HRESULT hr = S_OK;

            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            pin_ptr<Direct2DNet::D2D1_INK_POINT> pStart = &start;
            hr = ((::ID2D1DeviceContext2 *)context->m_pResource)->CreateInk(
                reinterpret_cast<::D2D1_INK_POINT *>(pStart),
                (::ID2D1Ink **)ppResource
            );
            ppResource = nullptr;
            pStart = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Ink", (int)hr);
        }

        HRESULT ID2D1Ink::AddSegments(...array<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> ^segments)
        {
            if(segments->Length == 0)
                return S_OK;

            pin_ptr<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> pSegments = &segments[0];
            return ((::ID2D1Ink *)m_pResource)->AddSegments(
                reinterpret_cast<::D2D1_INK_BEZIER_SEGMENT *>(pSegments),
                (UINT32)segments->Length
            );
        }

        HRESULT ID2D1Ink::RemoveSegmentsAtEnd(UINT32 segmentsCount)
        {
            return ((::ID2D1Ink *)m_pResource)->RemoveSegmentsAtEnd(segmentsCount);
        }

        HRESULT ID2D1Ink::SetSegments(
            UINT32 startSegment,
            ...array<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> ^segments)
        {
            if(segments->Length == 0)
                return S_OK;

            pin_ptr<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> pSegments = &segments[0];
            return ((::ID2D1Ink *)m_pResource)->SetSegments(
                startSegment,
                reinterpret_cast<::D2D1_INK_BEZIER_SEGMENT *>(pSegments),
                (UINT32)segments->Length
            );
        }

        HRESULT ID2D1Ink::SetSegmentAtEnd(Direct2DNet::D2D1_INK_BEZIER_SEGMENT %segment)
        {
            pin_ptr<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> pSegment = &segment;
            return ((::ID2D1Ink *)m_pResource)->SetSegmentAtEnd(
                reinterpret_cast<::D2D1_INK_BEZIER_SEGMENT *>(pSegment)
            );
        }

        HRESULT ID2D1Ink::GetSegments(
            UINT32 startSegment,
            array<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> ^segments)
        {
            if(segments->Length == 0)
                return S_OK;

            pin_ptr<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> pSegments = &segments[0];
            return ((::ID2D1Ink *)m_pResource)->GetSegments(
                startSegment,
                reinterpret_cast<::D2D1_INK_BEZIER_SEGMENT *>(pSegments),
                (UINT32)segments->Length
            );
        }

        HRESULT ID2D1Ink::StreamAsGeometry(
            float flatteningTolerance,
            Direct2DNet::ID2D1PathGeometry ^geometry,
            Direct2DNet::ID2D1InkStyle ^inkStyle,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform)
        {
            if(!geometry->m_pSink)
                return D2DERR_WRONG_STATE;

            return ((::ID2D1Ink *)m_pResource)->StreamAsGeometry(
                inkStyle ? (::ID2D1InkStyle *)inkStyle->m_pResource : __nullptr,
                worldTransform.HasValue ? reinterpret_cast<::D2D1_MATRIX_3X2_F *>(&worldTransform.Value) : __nullptr,
                flatteningTolerance,
                (::ID2D1SimplifiedGeometrySink *)geometry->m_pSink
            );
        }

        HRESULT ID2D1Ink::GetBounds(
            Direct2DNet::D2D1_RECT_F %bounds,
            Direct2DNet::ID2D1InkStyle ^inkStyle,
            System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform)
        {
            pin_ptr<Direct2DNet::D2D1_RECT_F> pBounds = &bounds;

            return ((::ID2D1Ink *)m_pResource)->GetBounds(
                inkStyle ? (::ID2D1InkStyle *)inkStyle->m_pResource : __nullptr,
                worldTransform.HasValue ? reinterpret_cast<::D2D1_MATRIX_3X2_F *>(&worldTransform.Value) : __nullptr,
                reinterpret_cast<::D2D1_RECT_F *>(pBounds)
            );
        }

    }
}