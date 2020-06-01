#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1PathGeometry.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1Factory1;

        // Done.

        /// <summary>
        /// The ID2D1PathGeometry1 interface adds functionality to ID2D1PathGeometry. In
        /// particular, it provides the path geometry-specific
        /// ComputePointAndSegmentAtLength method.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("70368CF7-4350-4ACC-A0F4-55250AE743C2")]
        public ref class ID2D1PathGeometry1 : Direct2DNet::ID2D1PathGeometry
        {
        internal:
            ID2D1PathGeometry1(Direct2DNet::ID2D1Factory1 ^factory);

        public:
            /// <summary>
            /// Computes the point that exists at a given distance along the path geometry along with the
            /// index of the segment the point is on and the directional vector at that point.
            /// </summary>
            /// <param name="length">The distance to walk along the path.</param>
            /// <param name="startSegment">The index of the segment at which to begin walking.
            /// This index is global to the entire path, not just a particular figure.</param>
            /// <param name="worldTransform">The transform to apply to the path prior to walking.
            /// The default value is the identity matrix.</param>
            /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
            /// approximation of the geometry. No point in the polygonal representation will diverge from
            /// the original geometry by more than the flattening tolerance. Smaller values produce more
            /// accurate results but cause slower execution.
            /// The default value is 0.25.</param>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::D2D1_POINT_DESCRIPTION"/>) tuple.
            /// If this method succeeds, HRESULT is S_OK. Otherwise, HRESULT is an error code.
            /// <see cref="Direct2DNet::D2D1_POINT_DESCRIPTION"/> describes a point along a path.
            /// </returns>
            System::ValueTuple<HRESULT, Direct2DNet::D2D1_POINT_DESCRIPTION> ComputePointAndSegmentAtLength(
                float length,
                unsigned int startSegment,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
                [OptionalAttribute] System::Nullable<float> flatteningTolerance
            );

            /// <summary>
            /// Computes the point that exists at a given distance along the path geometry along with the
            /// index of the segment the point is on and the directional vector at that point.
            /// </summary>
            /// <param name="pointDescription">Description of a point along a path(out parameter).</param>
            /// <param name="length">The distance to walk along the path.</param>
            /// <param name="startSegment">The index of the segment at which to begin walking.
            /// This index is global to the entire path, not just a particular figure.</param>
            /// <param name="worldTransform">The transform to apply to the path prior to walking.
            /// The default value is the identity matrix.</param>
            /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
            /// approximation of the geometry. No point in the polygonal representation will diverge from
            /// the original geometry by more than the flattening tolerance. Smaller values produce more
            /// accurate results but cause slower execution.
            /// The default value is 0.25.</param>
            /// <returns>
            /// If this method succeeds, returns S_OK. Otherwise, returns an error code.
            /// </returns>
            HRESULT ComputePointAndSegmentAtLength(
                [OutAttribute] Direct2DNet::D2D1_POINT_DESCRIPTION %pointDescription,
                float length,
                unsigned int startSegment,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
                [OptionalAttribute] System::Nullable<float> flatteningTolerance
            );
        };
    }
}