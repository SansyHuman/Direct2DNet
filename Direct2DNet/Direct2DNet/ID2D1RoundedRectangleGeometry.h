#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Geometry.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        /// <summary>
        /// Describes a rounded rectangle.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2cd906a3-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1RoundedRectangleGeometry : Direct2DNet::ID2D1Geometry
        {
        private:
            Direct2DNet::D2D1_ROUNDED_RECT m_rect;

        internal:
            ID2D1RoundedRectangleGeometry(Direct2DNet::ID2D1Factory ^factory, Direct2DNet::D2D1_ROUNDED_RECT %roundedRectangle);

        public:
            property Direct2DNet::D2D1_ROUNDED_RECT RoundedRect
            {
                Direct2DNet::D2D1_ROUNDED_RECT get()
                {
                    return m_rect;
                }
            }
        };
    }
}