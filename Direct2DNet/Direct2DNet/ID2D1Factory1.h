#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGIDevice;
    }

    namespace ComIO
    {
        ref class Stream;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Device;
        ref class ID2D1StrokeStyle1;
        ref class ID2D1PathGeometry1;
        ref class ID2D1DrawingStateBlock1;
        ref class ID2D1GdiMetafile;
        ref class ID2D1Properties;

        /// <summary>
        /// Creates Direct2D resources.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("A70E1E3C-4E3F-4B28-8F94-D8E2463BD94A")]
        public ref class ID2D1Factory1 : Direct2DNet::ID2D1Factory
        {
        internal:
            // Called by CreateDevice.
            ID2D1Factory1(::ID2D1Factory1 *pFactory);

        protected:
            ID2D1Factory1(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                System::Guid guid
            );

            ID2D1Factory1(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                Direct2DNet::D2D1_FACTORY_OPTIONS %options,
                System::Guid guid
            );

        public:
            /// <summary>
            /// Create <see cref="Direct2DNet::ID2D1Factory1"/> object.
            /// The type of the object can determine whether the factory
            /// and the derived resources can be invoked from single thread
            /// or multi thread.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
            ID2D1Factory1(Direct2DNet::D2D1_FACTORY_TYPE type);

            /// <summary>
            /// Create <see cref="Direct2DNet::ID2D1Factory1"/> object.
            /// The type of the object can determine whether the factory
            /// and the derived resources can be invoked from single thread
            /// or multi thread.
            /// The options determine the debug layer level.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_TYPE"/>
            /// <seealso cref="Direct2DNet::D2D1_FACTORY_OPTIONS"/>
            ID2D1Factory1(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_FACTORY_OPTIONS %options
            );

            /// <summary>
            /// This creates a new Direct2D device from the given IDXGIDevice.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the device.
            /// </exception>
            Direct2DNet::ID2D1Device ^CreateDevice(DXGINet::IDXGIDevice ^dxgiDevice);

            /// <summary>
            /// Creates a stroke style with the ability to preserve stroke width in various
            /// ways.
            /// </summary>
            /// <param name="dashes">
            /// An array whose elements are set to the length of each dash and space in the dash pattern.
            /// The first element sets the length of a dash, the second element sets the length of a space,
            /// the third element sets the length of a dash, and so on.
            /// the length is in unit of stroke width.
            /// This value should be null if you don't use custom dash style. Do not use the empty array.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the stroke style.
            /// </exception>
            /// <seealso cref="Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1"/>
            Direct2DNet::ID2D1StrokeStyle1 ^CreateStrokeStyle(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 %properties,
                array<float> ^dashes
            );

            /// <summary>
            /// Creates a path geometry with new operational methods.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the geometry.
            /// </exception>
            Direct2DNet::ID2D1PathGeometry1 ^CreatePathGeometry1();

            /// <summary>
            /// Creates a new drawing state block, this can be used in subsequent
            /// SaveDrawingState and RestoreDrawingState operations on the render target.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the block.
            /// </exception>
            Direct2DNet::ID2D1DrawingStateBlock1 ^CreateDrawingStateBlock(
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1> description,
                [OptionalAttribute] DWriteNet::IDWriteRenderingParams ^params
            );

            /// <summary>
            /// Creates a new GDI metafile from the stream.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the metafile.
            /// </exception>
            Direct2DNet::ID2D1GdiMetafile ^CreateGdiMetafile(ComIO::Stream ^metafileStream);

            // RegisterEffectFromStream

            // RegisterEffectFromString

            // UnregisterEffect

            // GetRegisteredEffects

            /// <summary>
            /// This retrieves the effect properties for the given effect, all of the effect
            /// properties will be set to a default value since an effect is not instantiated to
            /// implement the returned property interface.
            /// </summary>
             /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to get the properties.
            /// </exception>
            Direct2DNet::ID2D1Properties ^GetEffectProperties(
                [InAttribute][IsReadOnlyAttribute] System::Guid %effectId
            );
        };
    }
}