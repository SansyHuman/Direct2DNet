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
    public ref class ID2D1StrokeStyle : Direct2DNet::ID2D1Resource
    {
    internal:
        ID2D1StrokeStyle(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES properties,
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
                return static_cast<Direct2DNet::D2D1_CAP_STYLE>(
                    ((::ID2D1StrokeStyle *)m_pResource)->GetStartCap());
            }
        }

        /// <summary>
        /// Gets the end cap style.
        /// </summary>
        property Direct2DNet::D2D1_CAP_STYLE EndCap
        {
            Direct2DNet::D2D1_CAP_STYLE get()
            {
                return static_cast<Direct2DNet::D2D1_CAP_STYLE>(
                    ((::ID2D1StrokeStyle *)m_pResource)->GetEndCap());
            }
        }

        /// <summary>
        /// Gets the dash cap style.
        /// </summary>
        property Direct2DNet::D2D1_CAP_STYLE DashCap
        {
            Direct2DNet::D2D1_CAP_STYLE get()
            {
                return static_cast<Direct2DNet::D2D1_CAP_STYLE>(
                    ((::ID2D1StrokeStyle *)m_pResource)->GetDashCap());
            }
        }

        /// <summary>
        /// Gets the miter limit.
        /// </summary>
        property float MiterLimit
        {
            float get()
            {
                return ((::ID2D1StrokeStyle *)m_pResource)->GetMiterLimit();
            }
        }

        /// <summary>
        /// Gets the line join style.
        /// </summary>
        property Direct2DNet::D2D1_LINE_JOIN LineJoin
        {
            Direct2DNet::D2D1_LINE_JOIN get()
            {
                return static_cast<Direct2DNet::D2D1_LINE_JOIN>(
                    ((::ID2D1StrokeStyle *)m_pResource)->GetLineJoin());
            }
        }

        /// <summary>
        /// Gets the dash offset in the unit of stroke width.
        /// </summary>
        property float DashOffset
        {
            float get()
            {
                return ((::ID2D1StrokeStyle *)m_pResource)->GetDashOffset();
            }
        }

        /// <summary>
        /// Gets the dash style.
        /// </summary>
        property Direct2DNet::D2D1_DASH_STYLE DashStyle
        {
            Direct2DNet::D2D1_DASH_STYLE get()
            {
                return static_cast<Direct2DNet::D2D1_DASH_STYLE>(
                    ((::ID2D1StrokeStyle *)m_pResource)->GetDashStyle());
            }
        }

        /// <summary>
        /// Gets the number of custom dash settings.
        /// </summary>
        property unsigned int DashesCount
        {
            unsigned int get()
            {
                return ((::ID2D1StrokeStyle *)m_pResource)->GetDashesCount();
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

                pin_ptr<float> pValue = &value[0];
                ((::ID2D1StrokeStyle *)m_pResource)->GetDashes((float *)pValue, count);
                pValue = nullptr;

                return value;
            }
        }
    };
}