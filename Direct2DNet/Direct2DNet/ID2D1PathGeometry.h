#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Geometry.h"
#include "Exception/DXException.h"
#include "ID2D1NativeGeometryInfoContainer.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        /// <summary>
        /// Contains information of figures and strokes of <see cref="Direct2DNet::ID2D1PathGeometry"/>.
        /// This class is used on
        /// <see cref="Direct2DNet::ID2D1PathGeometry::Stream(Direct2DNet::D2D1GeometryInfoContainer ^)"/>.
        /// </summary>
        public ref class D2D1GeometryInfoContainer
        {
        internal:
            Direct2DNet::ID2D1NativeGeometryInfoContainer *m_pNativeInfo;

        public:
            /// <summary>
            /// Contains information of the figure.
            /// </summary>
            value struct Figure
            {
                /// <summary>
                /// Represents the type of the segment.
                /// </summary>
                enum class SegmentType
                {
                    /// <summary>
                    /// Line segment.
                    /// </summary>
                    LINE = 0,

                    /// <summary>
                    /// Cubic Bezier segment.
                    /// </summary>
                    BEZIER = 1,

                    /// <summary>
                    /// Quadratic Bezier segment.
                    /// </summary>
                    QUADRATIC_BEZIER = 2,

                    /// <summary>
                    /// Arc segment.
                    /// </summary>
                    ARC = 3
                };

                /// <summary>
                /// Represents the segment.
                /// </summary>
                value struct Segment
                {
                    /// <summary>
                    /// Type of the segment stored in the struct.
                    /// </summary>
                    D2D1GeometryInfoContainer::Figure::SegmentType type;

                    /// <summary>
                    /// Flags of this segment.
                    /// </summary>
                    Direct2DNet::D2D1_PATH_SEGMENT vertexFlags;

                    Direct2DNet::D2D1_POINT_2F line;
                    Direct2DNet::D2D1_BEZIER_SEGMENT bezier;
                    Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT quadraticBezier;
                    Direct2DNet::D2D1_ARC_SEGMENT arc;

                    /// <summary>
                    /// Returns the information of this segment.
                    /// </summary>
                    virtual System::String ^ToString() override;

                internal:
                    static operator D2D1GeometryInfoContainer::Figure::Segment(Direct2DNet::NativeFigure::Segment %rhs)
                    {
                        D2D1GeometryInfoContainer::Figure::Segment value;
                        value.type = (D2D1GeometryInfoContainer::Figure::SegmentType)((int)rhs.type);
                        value.vertexFlags = (Direct2DNet::D2D1_PATH_SEGMENT)((int)rhs.vertexFlags);

                        switch(rhs.type)
                        {
                        case Direct2DNet::NativeFigure::SegmentType::LINE:
                            value.line = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.line);
                            break;
                        case Direct2DNet::NativeFigure::SegmentType::BEZIER:
                            value.bezier = static_cast<Direct2DNet::D2D1_BEZIER_SEGMENT>(rhs.bezier);
                            break;
                        case Direct2DNet::NativeFigure::SegmentType::QUADRATIC_BEZIER:
                            value.quadraticBezier = static_cast<Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT>(rhs.quadraticBezier);
                            break;
                        case Direct2DNet::NativeFigure::SegmentType::ARC:
                            value.arc = static_cast<Direct2DNet::D2D1_ARC_SEGMENT>(rhs.arc);
                            break;
                        }

                        return value;
                    }
                };

                /// <summary>
                /// Fill mode of this figure.
                /// </summary>
                Direct2DNet::D2D1_FILL_MODE fillMode;

                /// <summary>
                /// Start point of this figure.
                /// </summary>
                Direct2DNet::D2D1_POINT_2F startPoint;

                /// <summary>
                /// Describes whether this figure is filled or hollow.
                /// </summary>
                Direct2DNet::D2D1_FIGURE_BEGIN figureBegin;

                /// <summary>
                /// List of segments in this figure.
                /// </summary>
                System::Collections::Generic::List<D2D1GeometryInfoContainer::Figure::Segment> ^segments;

                /// <summary>
                /// Describes whether this figure is open or closed.
                /// </summary>
                Direct2DNet::D2D1_FIGURE_END figureEnd;

                /// <summary>
                /// Returns the information of this figure.
                /// </summary>
                virtual System::String ^ToString() override;

            internal:
                static operator D2D1GeometryInfoContainer::Figure(Direct2DNet::NativeFigure %rhs)
                {
                    D2D1GeometryInfoContainer::Figure value;
                    value.fillMode = (Direct2DNet::D2D1_FILL_MODE)((int)rhs.fillMode);
                    value.startPoint = static_cast<Direct2DNet::D2D1_POINT_2F>(::D2D1_POINT_2F(rhs.startPoint));
                    value.figureBegin = (Direct2DNet::D2D1_FIGURE_BEGIN)((int)rhs.figureBegin);

                    value.segments = gcnew System::Collections::Generic::List< D2D1GeometryInfoContainer::Figure::Segment>(rhs.segments.size());

                    for(int i = 0; i < rhs.segments.size(); i++)
                    {
                        value.segments->Add(static_cast<D2D1GeometryInfoContainer::Figure::Segment>(rhs.segments[i]));
                    }

                    value.figureEnd = (Direct2DNet::D2D1_FIGURE_END)((int)rhs.figureEnd);

                    return value;
                }
            };

            /// <summary>
            /// List of figures in the geometry.
            /// </summary>
            System::Collections::Generic::List<D2D1GeometryInfoContainer::Figure> ^figures;

            /// <summary>
            /// Basic constructor of <see cref="Direct2DNet::D2D1GeometryInfoContainer"/>.
            /// </summary>
            D2D1GeometryInfoContainer()
            {
                figures = gcnew System::Collections::Generic::List<D2D1GeometryInfoContainer::Figure>();
                m_pNativeInfo = nullptr;
                m_pNativeInfo = new Direct2DNet::ID2D1NativeGeometryInfoContainer();
            }

            ~D2D1GeometryInfoContainer()
            {
                this->!D2D1GeometryInfoContainer();
            }

            !D2D1GeometryInfoContainer()
            {
                if(m_pNativeInfo)
                {
                    m_pNativeInfo->Release();
                    m_pNativeInfo = nullptr;
                }
            }
        };

        // Done.

        /// <summary>
        /// Represents a complex shape that may be composed of arcs, curves, and lines.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("B3FA79A9-E5C3-4A64-8223-245E966B155F")]
        public ref class ID2D1PathGeometry : Direct2DNet::ID2D1Geometry
        {
        private:
            bool sinkOpened = false;

        internal:
            ::ID2D1GeometrySink *m_pSink;

        internal:
            ID2D1PathGeometry(Direct2DNet::ID2D1Factory ^factory);

        public:
            ~ID2D1PathGeometry();
            !ID2D1PathGeometry();

            /// <summary>Gets whether the geometry sink of the path is opened.</summary>
            property bool SinkOpened
            {
                bool get()
                {
                    return sinkOpened;
                }
            }

            /// <summary>
            /// Opens a geometry sink that will be used to create this path geometry.
            /// </summary>
            /// <returns>
            /// S_OK if opening has succeeded. D2DERR_WRONG_STATE if the sink is already opened.
            /// Error code if some other errors occurs.
            /// </returns>
            HRESULT OpenSink();

            /// <summary>
            /// Specifies the method used to determine which points are inside the geometry described
            /// by this geometry sink and which points are outside.
            /// </summary>
            /// <remarks>
            /// The fill mode defaults to <see cref="Direct2DNet::D2D1_FILL_MODE::MODE_ALTERNATE"/>.
            /// To set the fill mode, call SetFillMode before the first call to BeginFigure.
            /// Not doing will put the geometry sink in an error state.
            /// </remarks>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_FILL_MODE"/>
            void SetFillMode(Direct2DNet::D2D1_FILL_MODE fillMode);

            /// <summary>
            /// Specifies stroke and join options to be applied to new segments added to the geometry sink.
            /// </summary>
            /// <remarks>
            /// After this method is called, the specified segment flags are applied to each segment
            /// subsequently added to the sink. The segment flags are applied to every additional segment
            /// until this method is called again and a different set of segment flags is specified.
            /// </remarks>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_PATH_SEGMENT"/>
            void SetSegmentFlags(Direct2DNet::D2D1_PATH_SEGMENT vertexFlags);

            /// <summary>
            /// Starts a new figure at the specified point.
            /// </summary>
            /// <remarks>
            /// If this method is called while a figure is currently in progress, the interface is
            /// invalidated and all future methods will fail.
            /// </remarks>
            /// <param name="figureBegin">Whether the new figure should be hollow or filled.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_FIGURE_BEGIN"/>
            void BeginFigure(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %startPoint,
                Direct2DNet::D2D1_FIGURE_BEGIN figureBegin);

            /// <summary>
            /// Creates a line segment between the current point and the specified end point and adds it
            /// to the geometry sink.
            /// </summary>
            /// <param name="point">End point of the line.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            void AddLine([InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %point);

            /// <summary>
            /// Creates a sequence of lines using the specified points and adds them to the geometry sink.
            /// </summary>
            /// <param name="points">End points of lines.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            void AddLines(... array<Direct2DNet::D2D1_POINT_2F> ^points);

            /// <summary>
            /// Creates a cubic Bezier curve between the current point and the specified end point.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_BEZIER_SEGMENT"/>
            void AddBezier([InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BEZIER_SEGMENT %bezier);

            /// <summary>
            /// Creates a sequence of cubic Bezier curves and adds them to the geometry sink.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_BEZIER_SEGMENT"/>
            void AddBeziers(... array<Direct2DNet::D2D1_BEZIER_SEGMENT> ^beziers);

            /// <summary>
            /// Creates a quadratic Bezier curve between the current point and the specified end point
            /// and adds it to the geometry sink. 
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT"/>
            void AddQuadraticBezier(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT %bezier);

            /// <summary>
            /// Adds a sequence of quadratic Bezier segments as an array in a single call.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT"/>
            void AddQuadraticBeziers(... array<Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT> ^beziers);

            /// <summary>
            /// Adds a single arc to the path geometry.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            /// <seealso cref="Direct2DNet::D2D1_ARC_SEGMENT"/>
            void AddArc([InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_ARC_SEGMENT %arc);

            /// <summary>
            /// Ends the current figure; optionally, closes it.
            /// </summary>
            /// <remarks>
            /// Calling this method without a matching call to
            /// <see cref="Direct2DNet::ID2D1PathGeometry::BeginFigure"/> places the geometry sink in an
            /// error state; subsequent calls are ignored, and the overall failure will be returned when
            /// the <see cref="Direct2DNet::ID2D1PathGeometry::CloseSink"/> method is called.
            /// </remarks>
            /// <param name="figureEnd">A value that indicates whether the current figure is closed.
            /// If the figure is closed, a line is drawn between the current point and the start point
            /// specified by <see cref="Direct2DNet::ID2D1PathGeometry::BeginFigure"/>.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the geometry sink
            /// for this path geometry is not opened.</exception>
            void EndFigure(Direct2DNet::D2D1_FIGURE_END figureEnd);

            /// <summary>
            /// Closes the geometry sink of the path, indicates whether it is in an error state,
            /// and resets the sink's error state.
            /// </summary>
            /// <remarks>
            /// Do not close the geometry sink while a figure is still in progress;
            /// doing so puts the geometry sink in an error state. For the close operation to be successful,
            /// there must be one <see cref="Direct2DNet::ID2D1PathGeometry::EndFigure"/> call for each call
            /// to <see cref="Direct2DNet::ID2D1PathGeometry::BeginFigure"/>.
            /// After calling this method, the geometry sink might not be usable. Direct2DNet implementations
            /// of the native ID2D1PathGeometry interface do not allow the geometry sink to be modified after
            /// it is closed, but other implementations might not impose this restriction.
            /// </remarks>
            /// <returns>
            /// S_OK if closing has succeeded. D2DERR_WRONG_STATE if the sink is not opened.
            /// Error code if some other errors occurs.
            /// </returns>
            HRESULT CloseSink();

            /// <summary>
            /// Retrieve the contents of this geometry. The caller passes 
            /// <see cref="Direct2DNet::D2D1GeometryInfoContainer"/> to receive the data.
            /// </summary>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT Stream(Direct2DNet::D2D1GeometryInfoContainer ^container);

            /// <summary>
            /// Copies this geometry to other geometry.
            /// </summary>
            /// <param name="geometry">Path geometry to which this path geometry's contents are copied.</param>
            HRESULT Stream(Direct2DNet::ID2D1PathGeometry ^geometry);

            /// <summary>
            /// Retrieves the number of segments in the path geometry.
            /// </summary>
            /// <returns>
            /// Tuple with two values. First value is the error code.
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// Second value is the segment count.
            /// </returns>
            System::ValueTuple<HRESULT, unsigned int> GetSegmentCount();

            /// <summary>
            /// Retrieves the number of segments in the path geometry.
            /// </summary>
            /// <param name="count">The segment count(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetSegmentCount([OutAttribute] unsigned int %count);

            /// <summary>
            /// Retrieves the number of figures in the path geometry.
            /// </summary>
            /// <returns>
            /// Tuple with two values. First value is the error code.
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// Second value is the figure count.
            /// </returns>
            System::ValueTuple<HRESULT, unsigned int> GetFigureCount();

            /// <summary>
            /// Retrieves the number of figures in the path geometry.
            /// </summary>
            /// <param name="count">The segment count(out parameter).</param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetFigureCount([OutAttribute] unsigned int %count);
        };
    }
}