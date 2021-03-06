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
        /// Represents a geometry that has been transformed.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2cd906bb-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1TransformedGeometry : Direct2DNet::ID2D1Geometry
        {
        private:
            Direct2DNet::ID2D1Geometry ^m_source;
            Direct2DNet::D2D1_MATRIX_3X2_F m_transform;

        internal:
            ID2D1TransformedGeometry() : Direct2DNet::ID2D1Geometry() {}

            ID2D1TransformedGeometry(
                Direct2DNet::ID2D1Factory ^factory,
                Direct2DNet::ID2D1Geometry ^source,
                Direct2DNet::D2D1_MATRIX_3X2_F %transform
            );

        public:
            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>
            /// Gets the source geometry used to make the transformed matrix.
            /// </summary>
            property Direct2DNet::ID2D1Geometry ^SourceGeometry
            {
                Direct2DNet::ID2D1Geometry ^get()
                {
                    return m_source;
                }
            }

            /// <summary>
            /// Gets the transform matrix of the geometry.
            /// </summary>
            property Direct2DNet::D2D1_MATRIX_3X2_F Transform
            {
                Direct2DNet::D2D1_MATRIX_3X2_F get()
                {
                    return m_transform;
                }
            }
        };
    }
}