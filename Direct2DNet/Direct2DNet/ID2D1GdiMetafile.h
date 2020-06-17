#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

using namespace System::Runtime;

namespace D2DNet
{
    namespace ComIO
    {
        ref class Stream;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Factory1;
        ref class ID2D1GdiMetafileSink;

        /// <summary>
        /// Interface encapsulating a GDI/GDI+ metafile.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("84FCA72C-D841-4AB6-A83D-31D00A61B0B8")]
        public ref class ID2D1GdiMetafile : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1GdiMetafile(
                Direct2DNet::ID2D1Factory1 ^factory,
                D2DNet::ComIO::Stream ^stream
            );

        public:
            /// <summary>
            /// Play the metafile into a caller-supplied sink interface.
            /// </summary>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT Stream(Direct2DNet::ID2D1GdiMetafileSink ^sink);

            /// <summary>
            /// Gets the bounds of the metafile.
            /// </summary>
            /// <param name="bounds">
            /// The bounds of the metafile(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT GetBounds(
                [InteropServices::OutAttribute] Direct2DNet::D2D1_RECT_F %bounds
            );
        };
    }
}