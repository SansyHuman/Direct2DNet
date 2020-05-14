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
        /// Describes a two-dimensional rectangle.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("BF328DCA-243C-4DE4-97FB-E2D75FF0916E")]
        public ref class ID2D1RectangleGeometry : Direct2DNet::ID2D1Geometry
        {
        private:
            Direct2DNet::D2D1_RECT_F m_rect;

        internal:
            ID2D1RectangleGeometry(Direct2DNet::ID2D1Factory ^factory, Direct2DNet::D2D1_RECT_F %rectangle);

        public:
            property Direct2DNet::D2D1_RECT_F Rect
            {
                Direct2DNet::D2D1_RECT_F get()
                {
                    return m_rect;
                }
            }
        };
    }
}