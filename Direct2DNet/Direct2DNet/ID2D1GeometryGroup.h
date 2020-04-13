#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Geometry.h"

namespace Direct2DNet
{
    // Done.

    /// <summary>
    /// Represents a composite geometry, composed of other
    /// <see cref="Direct2DNet::ID2D1Geometry"/> objects.
    /// </summary>
    public ref class ID2D1GeometryGroup : Direct2DNet::ID2D1Geometry
    {
    private:
        Direct2DNet::D2D1_FILL_MODE m_fillMode;
        array<Direct2DNet::ID2D1Geometry ^> ^m_geometries;

    internal:
        ID2D1GeometryGroup(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_FILL_MODE fillMode,
            array<Direct2DNet::ID2D1Geometry ^> ^geometries
        );

    public:
        /// <summary>
        /// Gets the fill mode of the geometry group.
        /// </summary>
        property Direct2DNet::D2D1_FILL_MODE FillMode
        {
            Direct2DNet::D2D1_FILL_MODE get()
            {
                return m_fillMode;
            }
        }

        /// <summary>
        /// Gets the array of source geometries of the geometry group.
        /// </summary>
        property array<Direct2DNet::ID2D1Geometry ^> ^SourceGeometries
        {
            array<Direct2DNet::ID2D1Geometry ^> ^get()
            {
                return m_geometries;
            }
        }
    };
}