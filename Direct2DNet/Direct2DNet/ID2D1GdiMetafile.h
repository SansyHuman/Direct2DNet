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
        ref class IStream;
    }

    namespace Direct2DNet
    {
        ref class ID2D1Factory;
        ref class ID2D1Factory1;
        ref class ID2D1GdiMetafileSink;

        /// <summary>
        /// Interface encapsulating a GDI/GDI+ metafile.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2f543dc3-cfc1-4211-864f-cfd91c6f3395")]
        public ref class ID2D1GdiMetafile : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1GdiMetafile() : Direct2DNet::ID2D1Resource() {}

            ID2D1GdiMetafile(
                Direct2DNet::ID2D1Factory1 ^factory,
                D2DNet::ComIO::IStream ^stream
            );

            // Used in ID2D1CommandSink
            ID2D1GdiMetafile(
                Direct2DNet::ID2D1Factory ^factory,
                ::ID2D1GdiMetafile *pMetafile
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