#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

using namespace System::Runtime::InteropServices;

namespace Direct2DNet
{
    ref class ID2D1Factory;
    ref class ID2D1StrokeStyle;
    ref class ID2D1PathGeometry;
    ref class ID2D1Mesh;

    // Done.

    /// <summary>
    /// Represents a geometry resource and defines a set of helper methods for
    /// manipulating and measuring geometric shapes. Interfaces that inherit from
    /// ID2D1Geometry define specific shapes.
    /// </summary>
    public ref class ID2D1Geometry abstract : Direct2DNet::ID2D1Resource
    {
    protected:
        ID2D1Geometry(Direct2DNet::ID2D1Factory ^factory) : Direct2DNet::ID2D1Resource(factory) {}

    public:
        /// <summary>
        /// Retrieve the bounds of the geometry, with an optional applied transform.
        /// </summary>
        /// <param name="worldTransform">The transform applied to the geometry.
        /// The default value is the identity matrix.</param>
        /// <returns>
        /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// <see cref="Direct2DNet::D2D1_RECT_F"/> is the bounds of the geometry.
        /// </returns>
        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> GetBounds(
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform);

        /// <summary>
        /// Gets the bounds of the geometry after it has been widened by the specified stroke width
        /// and style and transformed by the specified matrix.
        /// </summary>
        /// <param name="strokeStyle">Stroke style applied to the geometry.
        /// This parameter can be null. The default value is null.</param>
        /// <param name="worldTransform">The transform applied to the geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// (HRESULT, <see cref="Direct2DNet::D2D1_RECT_F"/>) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// <see cref="Direct2DNet::D2D1_RECT_F"/> is the bounds of the geometry.
        /// </returns>
        System::ValueTuple<HRESULT, Direct2DNet::D2D1_RECT_F> GetWidenedBounds(
            float strokeWidth,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Checks to see whether the corresponding penned and widened geometry contains the
        /// given point.
        /// </summary>
        /// <param name="strokeStyle">Stroke style applied to the geometry.
        /// This parameter can be null. The default value is null.</param>
        /// <param name="worldTransform">The transform applied to the geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// (HRESULT, bool) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// If the stroke contains the point, bool is true. Otherwise, bool is false.
        /// </returns>
        System::ValueTuple<HRESULT, bool> StrokeContainsPoint(
            Direct2DNet::D2D1_POINT_2F point,
            float strokeWidth,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Test whether the given fill of this geometry would contain this point.
        /// </summary>
        /// <param name="worldTransform">The transform applied to the geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// (HRESULT, bool) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// If the fill contains the point, bool is true. Otherwise, bool is false.
        /// </returns>
        System::ValueTuple<HRESULT, bool> FillContainsPoint(
            Direct2DNet::D2D1_POINT_2F point,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Compare how one geometry intersects or contains another geometry.
        /// </summary>
        /// <param name="inputGeometry">The other geometry to compare.</param>
        /// <param name="inputGeometryTransform">The transform applied to the input geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// (HRESULT, <see cref="Direct2DNet::D2D1_GEOMETRY_RELATION"/>) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// <see cref="Direct2DNet::D2D1_GEOMETRY_RELATION"/> is the relation of two geometries.
        /// </returns>
        System::ValueTuple<HRESULT, Direct2DNet::D2D1_GEOMETRY_RELATION> CompareWithGeometry(
            Direct2DNet::ID2D1Geometry ^inputGeometry,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> inputGeometryTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Converts a geometry to a simplified geometry that has arcs and quadratic beziers
        /// removed.
        /// </summary>
        /// <param name="simplificationOption">A value that specifies whether the simplified geometry
        /// should contain curves.</param>
        /// <param name="dstGeometry">The path geometry to which the simplified geometry is appended.</param>
        /// <param name="worldTransform">The transform applied to the geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
        /// </returns>
        HRESULT Simplify(
            Direct2DNet::D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption,
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );
        
        /// <summary>
        /// Tessellates a geometry into triangles.
        /// </summary>
        /// <param name="mesh">The mesh to which the tessellated is appended.</param>
        /// <param name="worldTransform">The transform applied to the geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
        /// </returns>
        HRESULT Tessellate(
            Direct2DNet::ID2D1Mesh ^mesh,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Performs a combine operation between the two geometries to produce a resulting
        /// geometry.
        /// </summary>
        /// <param name="inputGeometry">The geometry to combine.</param>
        /// <param name="combineMode">Combine mode of two geometries.</param>
        /// <param name="dstGeometry">Path geometry to whice the combined geometry is appended.</param>
        /// <param name="inputGeometryTransform">The transform applied to the input geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
        /// </returns>
        HRESULT CombineWithGeometry(
            Direct2DNet::ID2D1Geometry ^inputGeometry,
            Direct2DNet::D2D1_COMBINE_MODE combineMode,
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> inputGeometryTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Computes the outline of the geometry. The result is written back into a
        /// path geometry.
        /// </summary>
        /// <param name="dstGeometry">Path geometry to whice the outline is appended.</param>
        /// <param name="worldTransform">The transform applied to the input geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
        /// </returns>
        HRESULT Outline(
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Computes the area of the geometry.
        /// </summary>
        /// <param name="worldTransform">The transform applied to the input geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// (HRESULT, float) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// float is the area of the geometry.
        /// </returns>
        System::ValueTuple<HRESULT, float> ComputeArea(
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Computes the length of the geometry.
        /// </summary>
        /// <param name="worldTransform">The transform applied to the input geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// (HRESULT, float) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// float is the length of the geometry.
        /// </returns>
        System::ValueTuple<HRESULT, float> ComputeLength(
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Computes the point and tangent a given distance along the path.
        /// </summary>
        /// <param name="length">The distance along the geometry of the point and tangent to find.
        /// If this distance is less then 0, this method calculates the first point in the geometry.
        /// If this distance is greater than the length of the geometry, this method calculates the
        /// last point in the geometry.</param>
        /// <param name="worldTransform">The transform applied to the input geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// (HRESULT, <see cref="Direct2DNet::D2D1_POINT_2F"/>, <see cref="Direct2DNet::D2D1_POINT_2F"/>) tuple.
        /// If this method succeeds, HRESULT S_OK. Otherwise, HRESULT is an error code.
        /// The first <see cref="Direct2DNet::D2D1_POINT_2F"/> is the location at the specified
        /// distance along the geometry. If the geometry is empty, this point contains NaN as its
        /// x and y values.
        /// The second <see cref="Direct2DNet::D2D1_POINT_2F"/> is the tangent vector at the specified
        /// distance along the geometry. If the geometry is empty, this vector contains NaN as its
        /// x and y values.
        /// </returns>
        System::ValueTuple<HRESULT, Direct2DNet::D2D1_POINT_2F, Direct2DNet::D2D1_POINT_2F> ComputePointAtLength(
            float length,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Get the geometry and widen it as well as apply an optional pen style.
        /// </summary>
        /// <param name="strokeWidth">Width of the stroke.</param>
        /// <param name="dstGeometry">Path geometry to which the widened geometry is appended.</param>
        /// <param name="strokeStyle">Stroke style applied to the geometry.
        /// This parameter can be null. The default value is null.</param>
        /// <param name="worldTransform">The transform applied to the input geometry.
        /// The default value is the identity matrix.</param>
        /// <param name="flatteningTolerance">The maximum error allowed when constructing a polygonal
        /// approximation of the geometry. No point in the polygonal representation will diverge from
        /// the original geometry by more than the flattening tolerance. Smaller values produce more
        /// accurate results but cause slower execution.
        /// The default value is 0.25.</param>
        /// <returns>
        /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
        /// </returns>
        HRESULT Widen(
            float strokeWidth,
            Direct2DNet::ID2D1PathGeometry ^dstGeometry,
            [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle,
            [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_MATRIX_3X2_F> worldTransform,
            [OptionalAttribute] System::Nullable<float> flatteningTolerance
        );

        /// <summary>
        /// Operator that combines two geometry in union mode.
        /// The rhs is (<see cref="Direct2DNet::ID2D1Factory"/>, <see cref="Direct2DNet::ID2D1Geometry"/>)
        /// tuple.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to combine the geometries.
        /// </exception>
        static Direct2DNet::ID2D1PathGeometry ^operator|(
            ID2D1Geometry ^lhs,
            System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs
        );

        /// <summary>
        /// Operator that combines two geometry in intersect mode.
        /// The rhs is (<see cref="Direct2DNet::ID2D1Factory"/>, <see cref="Direct2DNet::ID2D1Geometry"/>)
        /// tuple.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to combine the geometries.
        /// </exception>
        static Direct2DNet::ID2D1PathGeometry ^operator&(
            ID2D1Geometry ^lhs,
            System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs
            );

        /// <summary>
        /// Operator that combines two geometry in xor mode.
        /// The rhs is (<see cref="Direct2DNet::ID2D1Factory"/>, <see cref="Direct2DNet::ID2D1Geometry"/>)
        /// tuple.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to combine the geometries.
        /// </exception>
        static Direct2DNet::ID2D1PathGeometry ^operator^(
            ID2D1Geometry ^lhs,
            System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs
        );

        /// <summary>
        /// Operator that combines two geometry in exclude mode.
        /// The rhs is (<see cref="Direct2DNet::ID2D1Factory"/>, <see cref="Direct2DNet::ID2D1Geometry"/>)
        /// tuple.
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when it failed to combine the geometries.
        /// </exception>
        static Direct2DNet::ID2D1PathGeometry ^operator-(
            ID2D1Geometry ^lhs,
            System::ValueTuple<Direct2DNet::ID2D1Factory ^, ID2D1Geometry ^> rhs
        );
    };
}