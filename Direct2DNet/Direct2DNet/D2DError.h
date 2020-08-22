#pragma once

#include "D2DNetHeaders.h"

namespace D2DNet
{
    namespace Direct2DNet
    {

#ifndef D2DNET_ERR
#define D2DNET_ERR(x) literal HRESULT E_ ## x = D2DERR_ ## x
#endif

#ifdef D2DERR_INSUFFICIENT_BUFFER
#undef D2DERR_INSUFFICIENT_BUFFER
#define D2DERR_INSUFFICIENT_BUFFER __HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)
#endif

#ifdef D2DERR_FILE_NOT_FOUND
#undef D2DERR_FILE_NOT_FOUND
#define D2DERR_FILE_NOT_FOUND __HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)
#endif

        /// <summary>
        /// Contains Direct2D error codes.
        /// </summary>
        public ref class D2DError abstract sealed
        {
        public:
            /// <summary>
            /// The number is invalid.
            /// </summary>
            D2DNET_ERR(BAD_NUMBER);

            /// <summary>
            /// You can't draw with a bitmap that is currently bound as the target bitmap.
            /// </summary>
            D2DNET_ERR(BITMAP_BOUND_AS_TARGET);

            /// <summary>
            /// You can't draw with a bitmap that has the D2D1_BITMAP_OPTIONS_CANNOT_DRAW option.
            /// </summary>
            D2DNET_ERR(BITMAP_CANNOT_DRAW);

            /// <summary>
            /// A cycle occurred in the graph.
            /// </summary>
            D2DNET_ERR(CYCLIC_GRAPH);

            /// <summary>
            /// The display format to render is not supported by the hardware device.
            /// </summary>
            D2DNET_ERR(DISPLAY_FORMAT_NOT_SUPPORTED);

            /// <summary>
            /// A valid display state could not be determined.
            /// </summary>
            D2DNET_ERR(DISPLAY_STATE_INVALID);

            /// <summary>
            /// The class ID of the specified effect is not registered by the operating system.
            /// </summary>
            D2DNET_ERR(EFFECT_IS_NOT_REGISTERED);

            /// <summary>
            /// The requested size is larger than the guaranteed supported texture size.
            /// </summary>
            D2DNET_ERR(EXCEEDS_MAX_BITMAP_SIZE);

            /// <summary>
            /// The file specified was not found.
            /// </summary>
            D2DNET_ERR(FILE_NOT_FOUND);

            /// <summary>
            /// The brush types are incompatible for the call.
            /// </summary>
            D2DNET_ERR(INCOMPATIBLE_BRUSH_TYPES);

            /// <summary>
            /// The supplied buffer is too small to accommodate the data.
            /// </summary>
            D2DNET_ERR(INSUFFICIENT_BUFFER);

            /// <summary>
            /// The Direct3D device doesn't have sufficient capabilities to perform the requested action.
            /// </summary>
            D2DNET_ERR(INSUFFICIENT_DEVICE_CAPABILITIES);

            /// <summary>
            /// You can't render the graph with the context's current tiling settings.
            /// </summary>
            D2DNET_ERR(INTERMEDIATE_TOO_LARGE);

            /// <summary>
            /// The application should close this instance of Direct2D and restart it as a new process.
            /// </summary>
            D2DNET_ERR(INTERNAL_ERROR);

            /// <summary>
            /// A call to this method is invalid.
            /// </summary>
            D2DNET_ERR(INVALID_CALL);

            /// <summary>
            /// A configuration error occurred in the graph.
            /// </summary>
            D2DNET_ERR(INVALID_GRAPH_CONFIGURATION);

            /// <summary>
            /// An internal configuration error occurred in the graph.
            /// </summary>
            D2DNET_ERR(INVALID_INTERNAL_GRAPH_CONFIGURATION);

            /// <summary>
            /// The specified property doesn't exist.
            /// </summary>
            D2DNET_ERR(INVALID_PROPERTY);

            /// <summary>
            /// You can't set the image as a target because it is either an effect or
            /// a bitmap that doesn't have the D2D1_BITMAP_OPTIONS_TARGET option. 
            /// </summary>
            D2DNET_ERR(INVALID_TARGET);

            /// <summary>
            /// The application attempted to reuse a layer resource that has not yet been popped off the stack.
            /// </summary>
            D2DNET_ERR(LAYER_ALREADY_IN_USE);

            /// <summary>
            /// The requested DX surface size exceeds the maximum texture size.
            /// </summary>
            D2DNET_ERR(MAX_TEXTURE_SIZE_EXCEEDED);

            /// <summary>
            /// There is no hardware rendering device available for this operation.
            /// </summary>
            D2DNET_ERR(NO_HARDWARE_DEVICE);

            /// <summary>
            /// The specified sub-property doesn't exist.
            /// </summary>
            D2DNET_ERR(NO_SUBPROPERTIES);

            /// <summary>
            /// The object has not yet been initialized.
            /// </summary>
            D2DNET_ERR(NOT_INITIALIZED);

            /// <summary>
            /// The operation failed because the original target isn't currently bound as a target.
            /// </summary>
            D2DNET_ERR(ORIGINAL_TARGET_NOT_BOUND);

            /// <summary>
            /// The operation can't complete while you have outstanding references to the target bitmap.
            /// </summary>
            D2DNET_ERR(OUTSTANDING_BITMAP_REFERENCES);

            /// <summary>
            /// The application attempted to pop a layer off the stack when a clip was
            /// at the top, or pop a clip off the stack when a layer was at the top.
            /// </summary>
            D2DNET_ERR(POP_CALL_DID_NOT_MATCH_PUSH);

            /// <summary>
            /// This error occurs during print control creation to indicate that the
            /// Direct2D print control can't support any of the package target types
            /// that represent printer formats.
            /// </summary>
            D2DNET_ERR(PRINT_FORMAT_NOT_SUPPORTED);

            /// <summary>
            /// The application called ID2D1PrintControl::AddPage or ID2D1PrintControl::Close
            /// after the print job is already finished.
            /// </summary>
            D2DNET_ERR(PRINT_JOB_CLOSED);

            /// <summary>
            /// The application did not pop all clips and layers off the stack, or it
            /// attempted to pop too many clips or layers off the stack.
            /// </summary>
            D2DNET_ERR(PUSH_POP_UNBALANCED);

            /// <summary>
            /// A presentation error has occurred that may be recoverable.
            /// The caller needs to re-create the render target then attempt to render the frame again.
            /// </summary>
            D2DNET_ERR(RECREATE_TARGET);

            /// <summary>
            /// The requested operation cannot be performed until all layers and clips
            /// have been popped off the stack.
            /// </summary>
            D2DNET_ERR(RENDER_TARGET_HAS_LAYER_OR_CLIPRECT);

            /// <summary>
            /// The geometry scanner failed to process the data.
            /// </summary>
            D2DNET_ERR(SCANNER_FAILED);

            /// <summary>
            /// Direct2D could not access the screen.
            /// </summary>
            D2DNET_ERR(SCREEN_ACCESS_DENIED);

            /// <summary>
            /// Shader compilation failed.
            /// </summary>
            D2DNET_ERR(SHADER_COMPILE_FAILED);

            /// <summary>
            /// The render target is not compatible with GDI.
            /// </summary>
            D2DNET_ERR(TARGET_NOT_GDI_COMPATIBLE);

            /// <summary>
            /// A text client drawing effect object is of the wrong type.
            /// </summary>
            D2DNET_ERR(TEXT_EFFECT_IS_WRONG_TYPE);

            /// <summary>
            /// An application is holding a reference to the IDWriteTextRenderer interface
            /// after the corresponding DrawTextor DrawTextLayout call has returned. 
            /// </summary>
            D2DNET_ERR(TEXT_RENDERER_NOT_RELEASED);

            /// <summary>
            /// Shader construction failed because it was too complex.
            /// </summary>
            D2DNET_ERR(TOO_MANY_SHADER_ELEMENTS);

            /// <summary>
            /// An effect attempted to use a transform with too many inputs.
            /// </summary>
            D2DNET_ERR(TOO_MANY_TRANSFORM_INPUTS);

            /// <summary>
            /// The requested operation is not supported.
            /// </summary>
            D2DNET_ERR(UNSUPPORTED_OPERATION);

            /// <summary>
            /// The pixel format is not supported.
            /// </summary>
            D2DNET_ERR(UNSUPPORTED_PIXEL_FORMAT);

            /// <summary>
            /// The requested Direct2D version is not supported.
            /// </summary>
            D2DNET_ERR(UNSUPPORTED_VERSION);

            /// <summary>
            /// An unknown Win32 failure occurred.
            /// </summary>
            D2DNET_ERR(WIN32_ERROR);

            /// <summary>
            /// Objects used together were not all created from the same factory instance.
            /// </summary>
            D2DNET_ERR(WRONG_FACTORY);

            /// <summary>
            /// The resource used was created by a render target in a different resource domain.
            /// </summary>
            D2DNET_ERR(WRONG_RESOURCE_DOMAIN);

            /// <summary>
            /// The object was not in the correct state to process the method.
            /// </summary>
            D2DNET_ERR(WRONG_STATE);

            /// <summary>
            /// The supplied vector is zero.
            /// </summary>
            D2DNET_ERR(ZERO_VECTOR);
        };
    }
}