#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Geometry.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        // Done.

        /// <summary>
        /// Represents an ellipse.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("E5DB6297-76DD-4CC3-B706-70A65BA064C0")]
        public ref class ID2D1EllipseGeometry : Direct2DNet::ID2D1Geometry
        {
        private:
            Direct2DNet::D2D1_ELLIPSE m_ellipse;

        internal:
            ID2D1EllipseGeometry(Direct2DNet::ID2D1Factory ^factory, Direct2DNet::D2D1_ELLIPSE %ellipse);

        public:
            property Direct2DNet::D2D1_ELLIPSE Ellipse
            {
                Direct2DNet::D2D1_ELLIPSE get()
                {
                    return m_ellipse;
                }
            }
        };
    }
}