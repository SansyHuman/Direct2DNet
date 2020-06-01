#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1RenderTarget.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace DXGINet
    {
        ref class IDXGISurface;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Device;
        ref class ID2D1Image;
        ref class ID2D1Bitmap1;
        ref class ID2D1ColorContext;
        ref class ID2D1Effect;
        ref class ID2D1GradientStopCollection1;

        /// <summary>
        /// The device context represents a set of state and a command buffer that is used
        /// to render to a target bitmap.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("16E6ED08-F319-45FA-9B13-DA9E1E47CE6F")]
        public ref class ID2D1DeviceContext : Direct2DNet::ID2D1RenderTarget
        {
        private:
            Direct2DNet::ID2D1Device ^m_device;
            Direct2DNet::ID2D1Image ^m_target;

        internal:
            ID2D1DeviceContext(
                Direct2DNet::ID2D1Device ^device,
                Direct2DNet::D2D1_DEVICE_CONTEXT_OPTIONS options);

        public:
            /// <summary>
            /// Creates a bitmap with extended bitmap properties, potentially from a block of
            /// memory.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the bitmap.
            /// </exception>
            Direct2DNet::ID2D1Bitmap1 ^CreateBitmap(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_U %size,
                void *sourceData,
                unsigned int pitch,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties
            );

            // CreateBitmapFromWicBitmap

            /// <summary>
            /// Creates a color context.
            /// </summary>
            /// <param name="profile">
            /// A buffer containing the ICC profile bytes used to initialize the color context when
            /// space is <see cref="Direct2DNet::D2D1_COLOR_SPACE::CUSTOM"/>. For other types, the parameter
            /// is ignored and should be set to NULL.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the color context.
            /// </exception>
            Direct2DNet::ID2D1ColorContext ^CreateColorContext(
                Direct2DNet::D2D1_COLOR_SPACE space,
                array<unsigned char> ^profile
            );

            /// <summary>
            /// Creates a color context by loading it from the specified filename.
            /// The profile bytes are the contents of the file specified by Filename.
            /// </summary>
            /// <param name="filename">
            /// The path to the file containing the profile bytes to initialize the color context with.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the color context.
            /// </exception>
            Direct2DNet::ID2D1ColorContext ^CreateColorContextFromFilename(
                System::String ^filename
            );

            /// <summary>
            /// Creates a bitmap from a DXGI surface with a set of extended properties.
            /// </summary>
            Direct2DNet::ID2D1Bitmap1 ^CreateBitmapFromDxgiSurface(
                DXGINet::IDXGISurface ^surface,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_BITMAP_PROPERTIES1 %bitmapProperties
            );

            /// <summary>
            /// Create a new effect, the effect must either be built in or previously registered
            /// through ID2D1Factory1::RegisterEffectFromStream or
            /// ID2D1Factory1::RegisterEffectFromString.
            /// </summary>
            Direct2DNet::ID2D1Effect ^CreateEffect([InAttribute][IsReadOnlyAttribute] System::Guid %effectId);

            /// <summary>
            /// Creates a gradient stop collection represents a set of stops in an ideal unit length.
            /// This is the source resource for a linear gradient and radial gradient brush.
            /// </summary>
            /// <param name="preInterpolationSpace">Specifies both the input color space and the
            /// space in which the color interpolation occurs.</param>
            /// <param name="postInterpolationSpace">Specifies the color space colors will be
            /// converted to after interpolation occurs.</param>
            /// <param name="bufferPrecision">Specifies the precision in which the gradient
            /// buffer will be held.</param>
            /// <param name="extendMode">Specifies how the gradient will be extended outside of
            /// the unit length.</param>
            /// <param name="colorInterpolationMode">Determines if colors will be interpolated
            /// in straight alpha or premultiplied alpha space.</param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the collection.
            /// </exception>
            Direct2DNet::ID2D1GradientStopCollection1 ^CreateGradientStopCollection(
                array<Direct2DNet::D2D1_GRADIENT_STOP> ^straightAlphaGradientStops,
                Direct2DNet::D2D1_COLOR_SPACE preInterpolationSpace,
                Direct2DNet::D2D1_COLOR_SPACE postInterpolationSpace,
                Direct2DNet::D2D1_BUFFER_PRECISION bufferPrecision,
                Direct2DNet::D2D1_EXTEND_MODE extendMode,
                Direct2DNet::D2D1_COLOR_INTERPOLATION_MODE colorInterpolationMode
            );

            /// <summary>
            /// Gets the device associated with this device context.
            /// </summary>
            property Direct2DNet::ID2D1Device ^Device
            {
                Direct2DNet::ID2D1Device ^get()
                {
                    return m_device;
                }
            }

            /// <summary>
            /// Gets and sets the target for this device context to point to the given image. The image
            /// can be a command list or a bitmap created with the 
            /// <see cref="Direct2DNet::D2D1_BITMAP_OPTIONS::TARGET"/> flag.
            /// </summary>
            property Direct2DNet::ID2D1Image ^Target
            {
                Direct2DNet::ID2D1Image ^get();
                void set(Direct2DNet::ID2D1Image ^value);
            }
        };
    }
}