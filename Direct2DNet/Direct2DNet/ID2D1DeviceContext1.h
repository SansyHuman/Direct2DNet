#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1DeviceContext.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1Device1;
        ref class ID2D1Device2;
        ref class ID2D1Geometry;
        ref class ID2D1StrokeStyle;
        ref class ID2D1Brush;
        ref class ID2D1GeometryRealization;

        // Done.

        /// <summary>
        /// Enables creation and drawing of geometry realization objects.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("d37f57e4-6908-459f-a199-e72f24f79987")]
        public ref class ID2D1DeviceContext1 : Direct2DNet::ID2D1DeviceContext
        {
        protected:
            ID2D1DeviceContext1(
                Direct2DNet::ID2D1Device2 ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );

        internal:
            ID2D1DeviceContext1() : Direct2DNet::ID2D1DeviceContext() {}

            ID2D1DeviceContext1(
                Direct2DNet::ID2D1Device1 ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options
            );

        public:
            /// <summary>
            /// Creates a device-dependent representation of the fill of the geometry that can be
            /// subsequently rendered.
            /// </summary>
            /// <param name="flatteningTolerance">
            /// The flattening tolerance to use when converting Beziers to line segments.
            /// This parameter shares the same units as the coordinates of the geometry.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the realization.
            /// </exception>
            Direct2DNet::ID2D1GeometryRealization ^CreateFilledGeometryRealization(
                Direct2DNet::ID2D1Geometry ^geometry,
                float flatteningTolerance
            );

            /// <summary>
            /// Creates a device-dependent representation of the stroke of a geometry that can be
            /// subsequently rendered.
            /// </summary>
            /// <param name="flatteningTolerance">
            /// The flattening tolerance to use when converting Beziers to line segments.
            /// This parameter shares the same units as the coordinates of the geometry.
            /// </param>
            /// <param name="strokeWidth">
            /// The width of the stroke. This parameter shares the same units as the coordinates of
            /// the geometry.
            /// </param>
            /// <param name="strokeStyle">
            /// The stroke style (optional). The default value is null.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the realization.
            /// </exception>
            Direct2DNet::ID2D1GeometryRealization ^CreateStrokedGeometryRealization(
                Direct2DNet::ID2D1Geometry ^geometry,
                float flatteningTolerance,
                float strokeWidth,
                [OptionalAttribute] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            );

            /// <summary>
            /// Renders a given geometry realization to the target with the specified brush.
            /// </summary>
            void DrawGeometryRealization(
                Direct2DNet::ID2D1GeometryRealization ^geometryRealization,
                Direct2DNet::ID2D1Brush ^brush
            );
        };
    }
}