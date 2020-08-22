#include "ID2D1PathGeometry.h"
#include "ID2D1Factory.h"
#include "ID2D1Factory1.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        System::String ^D2D1GeometryInfoContainer::Figure::Segment::ToString()
        {
            System::Text::StringBuilder builder;
            builder.Append("Segment type: "); builder.Append(type.ToString()); builder.AppendLine();
            builder.Append("Vertex flag: "); builder.Append(vertexFlags.ToString()); builder.AppendLine();

            switch(type)
            {
            case D2D1GeometryInfoContainer::Figure::SegmentType::LINE:
                builder.Append("End point: "); builder.Append(line); builder.AppendLine();
                break;
            case D2D1GeometryInfoContainer::Figure::SegmentType::BEZIER:
                builder.Append("Point 1: "); builder.Append(bezier.point1); builder.AppendLine();
                builder.Append("Point 2: "); builder.Append(bezier.point2); builder.AppendLine();
                builder.Append("Point 3: "); builder.Append(bezier.point3); builder.AppendLine();
                break;
            case D2D1GeometryInfoContainer::Figure::SegmentType::QUADRATIC_BEZIER:
                builder.Append("Point 1: "); builder.Append(quadraticBezier.point1); builder.AppendLine();
                builder.Append("Point 2: "); builder.Append(quadraticBezier.point2); builder.AppendLine();
                break;
            case D2D1GeometryInfoContainer::Figure::SegmentType::ARC:
                builder.Append("End point: "); builder.Append(arc.point); builder.AppendLine();
                builder.Append("X radius: " + arc.size.width); builder.AppendLine();
                builder.Append("Y radius: " + arc.size.height); builder.AppendLine();
                builder.Append("Rotation angle: " + arc.rotationAngle); builder.AppendLine();
                builder.Append("Sweep direction: ");
                if(arc.sweepDirection == Direct2DNet::D2D1_SWEEP_DIRECTION::COUNTER_CLOCKWISE)
                    builder.Append("counterclockwise\n");
                else if(arc.sweepDirection == Direct2DNet::D2D1_SWEEP_DIRECTION::CLOCKWISE)
                    builder.Append("clockwise\n");
                builder.Append("Arc size: ");
                if(arc.arcSize == Direct2DNet::D2D1_ARC_SIZE::SMALL)
                    builder.Append("small\n");
                else if(arc.arcSize == Direct2DNet::D2D1_ARC_SIZE::LARGE)
                    builder.Append("large\n");
                break;
            }

            return builder.ToString();
        }

        System::String ^D2D1GeometryInfoContainer::Figure::ToString()
        {
            System::Text::StringBuilder builder;

            builder.Append("Fill mode: "); builder.Append(fillMode.ToString()); builder.AppendLine();
            builder.Append("Start point: "); builder.Append(startPoint); builder.AppendLine();
            builder.Append("Figure type: ");
            if(figureBegin == Direct2DNet::D2D1_FIGURE_BEGIN::FILLED)
                builder.Append("filled, ");
            else if(figureBegin == Direct2DNet::D2D1_FIGURE_BEGIN::HOLLOW)
                builder.Append("hollow, ");
            if(figureEnd == Direct2DNet::D2D1_FIGURE_END::OPEN)
                builder.Append("open");
            else if(figureEnd == Direct2DNet::D2D1_FIGURE_END::CLOSED)
                builder.Append("closed");
            builder.AppendLine();

            for(int i = 0; i < segments->Count; i++)
            {
                builder.Append("\n=== Segment " + (i + 1) + " ===\n");
                builder.Append(segments[i]);
            }

            return builder.ToString();
        }

        ID2D1PathGeometry::ID2D1PathGeometry(Direct2DNet::ID2D1Factory ^factory) : Direct2DNet::ID2D1Geometry(factory), m_pSink(nullptr)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = factory->m_pFactory->CreatePathGeometry(
                (::ID2D1PathGeometry **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1PathGeometry", (int)hr);
        }

        ID2D1PathGeometry::ID2D1PathGeometry(Direct2DNet::ID2D1Factory1 ^factory1)
            : Direct2DNet::ID2D1Geometry(factory1), m_pSink(nullptr)
        {
            
        }

        ID2D1PathGeometry::~ID2D1PathGeometry()
        {
            this->!ID2D1PathGeometry();
        }

        ID2D1PathGeometry::!ID2D1PathGeometry()
        {
            if(m_pSink)
            {
                m_pSink->Release();
                m_pSink = nullptr;
            }
        }

        void ID2D1PathGeometry::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Geometry::HandleCOMInterface(obj);

            if(m_pSink)
            {
                m_pSink->Release();
                m_pSink = nullptr;
            }

            sinkOpened = false;
        }

        HRESULT ID2D1PathGeometry::OpenSink()
        {
            if(sinkOpened)
                return D2DERR_WRONG_STATE;

            HRESULT hr = S_OK;

            pin_ptr<::ID2D1GeometrySink *> ppSink = &m_pSink;
            hr = ((::ID2D1PathGeometry *)m_pResource)->Open((::ID2D1GeometrySink **)ppSink);
            ppSink = nullptr;

            if(SUCCEEDED(hr))
                sinkOpened = true;

            return hr;
        }

        void ID2D1PathGeometry::SetFillMode(Direct2DNet::D2D1_FILL_MODE fillMode)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->SetFillMode((::D2D1_FILL_MODE)((int)fillMode));
        }

        void ID2D1PathGeometry::SetSegmentFlags(Direct2DNet::D2D1_PATH_SEGMENT vertexFlags)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->SetSegmentFlags((::D2D1_PATH_SEGMENT)((int)vertexFlags));
        }

        void ID2D1PathGeometry::BeginFigure(
            Direct2DNet::D2D1_POINT_2F %startPoint,
            Direct2DNet::D2D1_FIGURE_BEGIN figureBegin)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->BeginFigure(
                static_cast<::D2D1_POINT_2F>(startPoint),
                (::D2D1_FIGURE_BEGIN)((int)figureBegin)
            );
        }

        void ID2D1PathGeometry::AddLine(Direct2DNet::D2D1_POINT_2F %point)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->AddLine(static_cast<::D2D1_POINT_2F>(point));
        }

        void ID2D1PathGeometry::AddLines(...array<Direct2DNet::D2D1_POINT_2F> ^points)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            if(points->Length == 0)
                return;

            pin_ptr<Direct2DNet::D2D1_POINT_2F> pPoints = &points[0];

            m_pSink->AddLines(reinterpret_cast<::D2D1_POINT_2F *>(pPoints), points->Length);
        }

        void ID2D1PathGeometry::AddBezier(Direct2DNet::D2D1_BEZIER_SEGMENT %bezier)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->AddBezier(static_cast<::D2D1_BEZIER_SEGMENT>(bezier));
        }

        void ID2D1PathGeometry::AddBeziers(...array<Direct2DNet::D2D1_BEZIER_SEGMENT> ^beziers)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            if(beziers->Length == 0)
                return;

            pin_ptr<Direct2DNet::D2D1_BEZIER_SEGMENT> pBeziers = &beziers[0];

            m_pSink->AddBeziers(reinterpret_cast<::D2D1_BEZIER_SEGMENT *>(pBeziers), beziers->Length);
        }

        void ID2D1PathGeometry::AddQuadraticBezier(Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT %bezier)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->AddQuadraticBezier(static_cast<::D2D1_QUADRATIC_BEZIER_SEGMENT>(bezier));
        }

        void ID2D1PathGeometry::AddQuadraticBeziers(...array<Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT> ^beziers)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            if(beziers->Length == 0)
                return;

            pin_ptr<Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT> pBeziers = &beziers[0];

            m_pSink->AddQuadraticBeziers(reinterpret_cast<::D2D1_QUADRATIC_BEZIER_SEGMENT *>(pBeziers), beziers->Length);
        }

        void ID2D1PathGeometry::AddArc(Direct2DNet::D2D1_ARC_SEGMENT %arc)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->AddArc(static_cast<::D2D1_ARC_SEGMENT>(arc));
        }

        void ID2D1PathGeometry::EndFigure(Direct2DNet::D2D1_FIGURE_END figureEnd)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The geometry sink for this path geometry is not opened.", D2DERR_WRONG_STATE);

            m_pSink->EndFigure((::D2D1_FIGURE_END)((int)figureEnd));
        }

        HRESULT ID2D1PathGeometry::CloseSink()
        {
            if(!sinkOpened)
                return D2DERR_WRONG_STATE;

            HRESULT hr = S_OK;
            hr = m_pSink->Close();

            if(SUCCEEDED(hr))
            {
                sinkOpened = false;
                m_pSink->Release();
                m_pSink = nullptr;
            }

            return hr;
        }

        HRESULT ID2D1PathGeometry::Stream(Direct2DNet::D2D1GeometryInfoContainer ^container)
        {
            HRESULT hr = S_OK;

            if(!container->m_pNativeInfo)
                return E_FAIL;

            hr = ((::ID2D1PathGeometry *)m_pResource)->Stream(container->m_pNativeInfo);
            for(int i = 0; i < container->m_pNativeInfo->figures.size(); i++)
            {
                container->figures->Add(
                    static_cast<D2D1GeometryInfoContainer::Figure>(container->m_pNativeInfo->figures[i]));
            }

            return hr;
        }

        HRESULT ID2D1PathGeometry::Stream(Direct2DNet::ID2D1PathGeometry ^geometry)
        {
            HRESULT hr = S_OK;

            if(!geometry->m_pSink)
                return D2DERR_WRONG_STATE;

            hr = ((::ID2D1PathGeometry *)m_pResource)->Stream(geometry->m_pSink);

            return hr;
        }

        System::ValueTuple<HRESULT, unsigned int> ID2D1PathGeometry::GetSegmentCount()
        {
            unsigned int count = 0;
            HRESULT hr = S_OK;

            hr = ((::ID2D1PathGeometry *)m_pResource)->GetSegmentCount(&count);

            return System::ValueTuple<HRESULT, unsigned int>(hr, count);
        }

        HRESULT ID2D1PathGeometry::GetSegmentCount(unsigned int %count)
        {
            HRESULT hr = S_OK;

            pin_ptr<unsigned int> pCount = &count;
            hr = ((::ID2D1PathGeometry *)m_pResource)->GetSegmentCount((UINT32 *)pCount);
            pCount = nullptr;

            return hr;
        }

        System::ValueTuple<HRESULT, unsigned int> ID2D1PathGeometry::GetFigureCount()
        {
            unsigned int count = 0;
            HRESULT hr = S_OK;

            hr = ((::ID2D1PathGeometry *)m_pResource)->GetFigureCount(&count);

            return System::ValueTuple<HRESULT, unsigned int>(hr, count);
        }

        HRESULT ID2D1PathGeometry::GetFigureCount(unsigned int %count)
        {
            HRESULT hr = S_OK;

            pin_ptr<unsigned int> pCount = &count;
            hr = ((::ID2D1PathGeometry *)m_pResource)->GetFigureCount((UINT32 *)pCount);
            pCount = nullptr;

            return hr;
        }

    }
}