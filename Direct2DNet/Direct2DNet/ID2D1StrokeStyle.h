#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"
#include "Exception/DXException.h"

namespace Direct2DNet
{
    //Done.

    /// <summary>
    /// Resource class that holds pen style properties.
    /// </summary>
    [System::Runtime::InteropServices::GuidAttribute("0B571E07-A5DB-48E2-B1DC-F1F180C67CDE")]
    public ref class ID2D1StrokeStyle : Direct2DNet::ID2D1Resource
    {
    private:
        Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES m_properties;
        array<float> ^m_dashes;

    internal:
        ID2D1StrokeStyle(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES %properties,
            array<float> ^dashes
        );

    public:
        /// <summary>
        /// Gets the start cap style.
        /// </summary>
        property Direct2DNet::D2D1_CAP_STYLE StartCap
        {
            Direct2DNet::D2D1_CAP_STYLE get()
            {
                return m_properties.startCap;
            }
        }

        /// <summary>
        /// Gets the end cap style.
        /// </summary>
        property Direct2DNet::D2D1_CAP_STYLE EndCap
        {
            Direct2DNet::D2D1_CAP_STYLE get()
            {
                return m_properties.endCap;
            }
        }

        /// <summary>
        /// Gets the dash cap style.
        /// </summary>
        property Direct2DNet::D2D1_CAP_STYLE DashCap
        {
            Direct2DNet::D2D1_CAP_STYLE get()
            {
                return m_properties.dashCap;
            }
        }

        /// <summary>
        /// Gets the miter limit.
        /// </summary>
        property float MiterLimit
        {
            float get()
            {
                return m_properties.miterLimit;
            }
        }

        /// <summary>
        /// Gets the line join style.
        /// </summary>
        property Direct2DNet::D2D1_LINE_JOIN LineJoin
        {
            Direct2DNet::D2D1_LINE_JOIN get()
            {
                return m_properties.lineJoin;
            }
        }

        /// <summary>
        /// Gets the dash offset in the unit of stroke width.
        /// </summary>
        property float DashOffset
        {
            float get()
            {
                return m_properties.dashOffset;
            }
        }

        /// <summary>
        /// Gets the dash style.
        /// </summary>
        property Direct2DNet::D2D1_DASH_STYLE DashStyle
        {
            Direct2DNet::D2D1_DASH_STYLE get()
            {
                return m_properties.dashStyle;
            }
        }

        /// <summary>
        /// Gets the number of custom dash settings.
        /// </summary>
        property unsigned int DashesCount
        {
            unsigned int get()
            {
                return m_dashes->Length;
            }
        }

        /// <summary>
        /// Gets the array of custom dash settings in the unit of stroke width.
        /// </summary>
        property array<float> ^Dashes
        {
            array<float> ^get()
            {
                unsigned int count = DashesCount;
                array<float> ^value = gcnew array<float>(count);

                m_dashes->CopyTo(value, 0);

                return value;
            }
        }
    };
}