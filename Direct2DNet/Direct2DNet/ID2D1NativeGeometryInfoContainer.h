#pragma once

#include "D2DNetHeaders.h"
#include "D2DSettings.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        /*Classes and structs in this header file are unmanaged(native) internal objects.*/

        struct NativeFigure
        {
            enum SegmentType
            {
                LINE = 0,
                BEZIER = 1,
                QUADRATIC_BEZIER = 2,
                ARC = 3
            };

            struct Segment
            {
                SegmentType type;
                ::D2D1_PATH_SEGMENT vertexFlags;

                // To save the memory.
                union
                {
                    ::D2D1_POINT_2F line;
                    ::D2D1_BEZIER_SEGMENT bezier;
                    ::D2D1_QUADRATIC_BEZIER_SEGMENT quadraticBezier;
                    ::D2D1_ARC_SEGMENT arc;
                };
            };

            const ::D2D1_FILL_MODE fillMode;
            const ::D2D1_POINT_2F startPoint;
            const ::D2D1_FIGURE_BEGIN figureBegin;

            std::vector<Segment> segments;

            ::D2D1_FIGURE_END figureEnd;

            NativeFigure(::D2D1_FILL_MODE fillMode, ::D2D1_POINT_2F startPoint, ::D2D1_FIGURE_BEGIN figureBegin)
                : fillMode(fillMode), startPoint(startPoint), figureBegin(figureBegin)
            {
                segments.clear();
            }
        };

        class ID2D1NativeGeometryInfoContainer : public ::ID2D1GeometrySink
        {
        private:
            UINT m_cRef;

            ::D2D1_FILL_MODE m_currentFillmode;
            ::D2D1_PATH_SEGMENT m_currentVertexFlags;

        public:
            std::vector<Direct2DNet::NativeFigure> figures;

        public:
            ID2D1NativeGeometryInfoContainer()
                : m_cRef(1), m_currentFillmode(D2D1_FILL_MODE_ALTERNATE), m_currentVertexFlags(D2D1_PATH_SEGMENT_NONE)
            {
                figures.clear();
            }

            STDMETHOD_(ULONG, AddRef)(void)
            {
                return InterlockedIncrement(reinterpret_cast<LONG volatile *>(&m_cRef));
            }

            STDMETHOD_(ULONG, Release)(void)
            {
                ULONG cRef = static_cast<ULONG>(
                    InterlockedDecrement(reinterpret_cast<LONG volatile *>(&m_cRef)));

                if(0 == cRef)
                {
                    delete this;
                }

                return cRef;
            }

            STDMETHOD(QueryInterface)(THIS_ REFIID iid, void **ppvObject)
            {
                HRESULT hr = S_OK;

                if(__uuidof(::IUnknown) == iid)
                {
                    *ppvObject = static_cast<::IUnknown *>(this);
                    AddRef();
                }
                else if(__uuidof(::ID2D1SimplifiedGeometrySink) == iid)
                {
                    *ppvObject = static_cast<::ID2D1SimplifiedGeometrySink *>(this);
                    AddRef();
                }
                else
                {
                    *ppvObject = NULL;
                    hr = E_NOINTERFACE;
                }

                return hr;
            }

            STDMETHOD_(void, SetFillMode)(::D2D1_FILL_MODE fillMode)
            {
                m_currentFillmode = fillMode;
            }

            STDMETHOD_(void, SetSegmentFlags)(::D2D1_PATH_SEGMENT vertexFlags)
            {
                m_currentVertexFlags = vertexFlags;
            }

            STDMETHOD_(void, BeginFigure)(::D2D1_POINT_2F startPoint, ::D2D1_FIGURE_BEGIN figureBegin)
            {
                figures.push_back(Direct2DNet::NativeFigure(m_currentFillmode, startPoint, figureBegin));
            }

            STDMETHOD_(void, AddLines)(_In_reads_(pointsCount) CONST::D2D1_POINT_2F *points, UINT32 pointsCount)
            {
                for(int i = 0; i < pointsCount; i++)
                    this->AddLine(points[i]);
            }

            STDMETHOD_(void, AddBeziers)(_In_reads_(beziersCount) CONST::D2D1_BEZIER_SEGMENT *beziers, UINT32 beziersCount)
            {
                for(int i = 0; i < beziersCount; i++)
                    this->AddBezier(&beziers[i]);
            }

            STDMETHOD_(void, EndFigure)(::D2D1_FIGURE_END figureEnd)
            {
                figures.back().figureEnd = figureEnd;
            }

            STDMETHOD(Close)()
            {
                return S_OK;
            }

            STDMETHOD_(void, AddLine)(::D2D1_POINT_2F point)
            {
                Direct2DNet::NativeFigure::Segment segment;
                segment.type = NativeFigure::SegmentType::LINE;
                segment.vertexFlags = m_currentVertexFlags;
                segment.line = point;

                figures.back().segments.push_back(segment);
            }

            STDMETHOD_(void, AddBezier)(_In_ CONST::D2D1_BEZIER_SEGMENT *bezier)
            {
                Direct2DNet::NativeFigure::Segment segment;
                segment.type = NativeFigure::SegmentType::BEZIER;
                segment.vertexFlags = m_currentVertexFlags;
                segment.bezier = *bezier;

                figures.back().segments.push_back(segment);
            }

            STDMETHOD_(void, AddQuadraticBezier)(_In_ CONST::D2D1_QUADRATIC_BEZIER_SEGMENT *bezier)
            {
                Direct2DNet::NativeFigure::Segment segment;
                segment.type = NativeFigure::SegmentType::QUADRATIC_BEZIER;
                segment.vertexFlags = m_currentVertexFlags;
                segment.quadraticBezier = *bezier;

                figures.back().segments.push_back(segment);
            }

            STDMETHOD_(void, AddQuadraticBeziers)(_In_reads_(beziersCount) CONST::D2D1_QUADRATIC_BEZIER_SEGMENT *beziers, UINT32 beziersCount)
            {
                for(int i = 0; i < beziersCount; i++)
                    this->AddQuadraticBezier(&beziers[i]);
            }

            STDMETHOD_(void, AddArc)(_In_ CONST::D2D1_ARC_SEGMENT *arc)
            {
                Direct2DNet::NativeFigure::Segment segment;
                segment.type = NativeFigure::SegmentType::ARC;
                segment.vertexFlags = m_currentVertexFlags;
                segment.arc = *arc;

                figures.back().segments.push_back(segment);
            }
        };
    }
}