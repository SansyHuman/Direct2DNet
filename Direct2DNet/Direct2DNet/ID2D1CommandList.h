#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Image.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1DeviceContext;
        ref class ID2D1CommandSink;

        /// <summary>
        /// Represents a sequence of commands that can be recorded and played back.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("16E6ED08-F319-45FA-9B13-DA9E1E47CE6F")]
        public ref class ID2D1CommandList : Direct2DNet::ID2D1Image
        {
        internal:
            ID2D1CommandList(Direct2DNet::ID2D1DeviceContext ^deviceContext);

        public:
            /// <summary>
            /// Play the command list into a caller-supplied sink interface.
            /// </summary>
            HRESULT Stream(Direct2DNet::ID2D1CommandSink ^sink);

            /// <summary>
            /// Marks the command list as ready for use.
            /// </summary>
            HRESULT Close();
        };
    }
}