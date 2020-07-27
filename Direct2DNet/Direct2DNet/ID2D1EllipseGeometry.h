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
        [System::Runtime::InteropServices::GuidAttribute("2cd906a4-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1EllipseGeometry : Direct2DNet::ID2D1Geometry
        {
        private:
            Direct2DNet::D2D1_ELLIPSE m_ellipse;

        internal:
            ID2D1EllipseGeometry() : Direct2DNet::ID2D1Geometry() {}

            ID2D1EllipseGeometry(Direct2DNet::ID2D1Factory ^factory, Direct2DNet::D2D1_ELLIPSE %ellipse);

        public:
            virtual void HandleCOMInterface(void *obj) override;

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