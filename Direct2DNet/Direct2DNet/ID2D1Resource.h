#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"

namespace Direct2DNet
{
    // Done.
    ref class ID2D1Factory;

    /// <summary>
    /// The root class for all resources in Direct2DNet.
    /// </summary>
    public ref class ID2D1Resource abstract : IDirect2DObject
    {
    internal:
        ::ID2D1Resource *m_pResource;
        Direct2DNet::ID2D1Factory ^factory;

    protected:
        ID2D1Resource(Direct2DNet::ID2D1Factory ^factory);

    public:
        ~ID2D1Resource();
        !ID2D1Resource();

    public:
        /// <summary>
        /// Gets the factory associated with this resource.
        /// </summary>
        property Direct2DNet::ID2D1Factory ^Factory
        {
            Direct2DNet::ID2D1Factory ^get()
            {
                return factory;
            }
        }
    };
}