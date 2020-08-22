#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext2;
        ref class ID2D1PathGeometry;
        ref class ID2D1InkStyle;

        // Done.

        /// <summary>
        /// Represents a single continuous stroke of variable-width ink, as defined by a
        /// series of Bezier segments and widths.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("b499923b-7029-478f-a8b3-432c7c5f5312")]
        public ref class ID2D1Ink : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1Ink() : Direct2DNet::ID2D1Resource() {}

            ID2D1Ink(
                Direct2DNet::ID2D1DeviceContext2 ^context,
                Direct2DNet::D2D1_INK_POINT %start
            );

        public:
            /// <summary>
            /// Gets and sets the ink start point.
            /// </summary>
            property Direct2DNet::D2D1_INK_POINT StartPoint
            {
                Direct2DNet::D2D1_INK_POINT get()
                {
                    ::D2D1_INK_POINT value = ((::ID2D1Ink *)m_pResource)->GetStartPoint();
                    return *(Direct2DNet::D2D1_INK_POINT *)&value;
                }

                void set(Direct2DNet::D2D1_INK_POINT value)
                {
                    ((::ID2D1Ink *)m_pResource)->SetStartPoint(
                        (::D2D1_INK_POINT *)&value
                    );
                }
            }

            /// <summary>
            /// Adds one or more segments to the end of the ink.
            /// </summary>
            /// <param name="segments">
            /// An array of segments to be added to this ink object.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT AddSegments(
                ... array<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> ^segments
            );

            /// <summary>
            /// Remove one or more segments from the end of the ink.
            /// </summary>
            /// <param name="segmentsCount">
            /// The number of segments to be removed from the end of this ink object. Note that
            /// segmentsCount must be less or equal to the number of segments in the ink object.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT RemoveSegmentsAtEnd(UINT32 segmentsCount);

            /// <summary>
            /// Updates the specified segments with new control points.
            /// </summary>
            /// <param name="startSegment">
            /// The index of the first segment in this ink object to update.
            /// </param>
            /// <param name="segments">
            /// The array of segment data to be used in the update.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT SetSegments(
                UINT32 startSegment,
                ... array<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> ^segments
            );

            /// <summary>
            /// Update the last segment with new control points.
            /// </summary>
            /// <param name="segment">
            /// The segment data with which to overwrite this ink object's last segment. Note that if there
            /// are currently no segments in the ink object, SetSegmentsAtEnd will return an error.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT SetSegmentAtEnd(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_INK_BEZIER_SEGMENT %segment
            );

            /// <summary>
            /// Gets the number of segments the ink is composed of.
            /// </summary>
            property UINT32 SegmentCount
            {
                UINT32 get()
                {
                    return ((::ID2D1Ink *)m_pResource)->GetSegmentCount();
                }
            }

            /// <summary>
            /// Retrieve the segments stored in the ink.
            /// </summary>
            /// <param name="startSegment">
            /// The index of the first segment in this ink object to retrieve.
            /// </param>
            /// <param name="segments">
            /// The buffer array to receive the segments. The number of segments to retrieve is the length
            /// of the buffer.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetSegments(
                UINT32 startSegment,
                array<Direct2DNet::D2D1_INK_BEZIER_SEGMENT> ^segments
            );

            /// <summary>
            /// Retrieve the segments stored in the ink.
            /// </summary>
            /// <param name="flatteningTolerance">
            /// The flattening tolerance to be used in determining the geometric representation.
            /// </param>
            /// <param name="geometry">
            /// The path geometry to which the geometry representation will be streamed. Note that the
            /// sink of the path geometry should be opened, or the method will return D2DERR_WRONG_STATE.
            /// </param>
            /// <param name="inkStyle">
            /// Optional ink style to be used in determining the geometric representation. The default value
            /// is null.
            /// </param>
            /// <param name="worldTransform">
            /// Optional world transform to be used in determining the geometric representation.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT StreamAsGeometry(
                float flatteningTolerance,
                Direct2DNet::ID2D1PathGeometry ^geometry,
                [OptionalAttribute] Direct2DNet::ID2D1InkStyle ^inkStyle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform
            );

            /// <summary>
            /// Retrieve the bounds of the geometry, with an optional applied transform.
            /// </summary>
            /// <param name="bounds">
            /// When this method returns, contains the bounds of this ink object(out parameter).
            /// </param>
            /// <param name="inkStyle">
            /// Optional ink style to be used in determining the bounds of this ink object. The default value
            /// is null.
            /// </param>
            /// <param name="worldTransform">
            /// Optional world transform to be used in determining the bounds of this ink object.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetBounds(
                [OutAttribute] Direct2DNet::D2D1_RECT_F %bounds,
                [OptionalAttribute] Direct2DNet::ID2D1InkStyle ^inkStyle,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform
            );
        };
    }
}