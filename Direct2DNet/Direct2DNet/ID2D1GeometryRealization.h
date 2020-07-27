#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext1;
        ref class ID2D1Geometry;
        ref class ID2D1StrokeStyle;

        /// <summary>
        /// Encapsulates a device- and transform-dependent representation of a filled or
        /// stroked geometry.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("a16907d7-bc02-4801-99e8-8cf7f485f774")]
        public ref class ID2D1GeometryRealization : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1GeometryRealization() : Direct2DNet::ID2D1Resource() {}

            ID2D1GeometryRealization(
                Direct2DNet::ID2D1DeviceContext1 ^context,
                Direct2DNet::ID2D1Geometry ^geometry,
                float flatteningTolerance
            );

            ID2D1GeometryRealization(
                Direct2DNet::ID2D1DeviceContext1 ^context,
                Direct2DNet::ID2D1Geometry ^geometry,
                float flatteningTolerance,
                float strokeWidth,
                Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            );
        };
    }
}