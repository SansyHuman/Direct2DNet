#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1Resource.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ref class ID2D1RenderTarget;
        ref class ID2D1Factory;

        // Done.

        /// <summary>
        /// Represents a set of vertices that form a list of triangles.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("2cd906c2-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1Mesh : Direct2DNet::ID2D1Resource
        {
        private:
            bool sinkOpened = false;

        internal:
            ::ID2D1TessellationSink *m_pSink;

        internal:
            ID2D1Mesh() : Direct2DNet::ID2D1Resource(), m_pSink(nullptr), sinkOpened(false) {}

            ID2D1Mesh(Direct2DNet::ID2D1RenderTarget ^renderTarget);

            // Called by ID2D1CommandSink
            ID2D1Mesh(Direct2DNet::ID2D1Factory ^factory, ::ID2D1Mesh *pMesh);

        public:
            ~ID2D1Mesh();
            !ID2D1Mesh();

            virtual void HandleCOMInterface(void *obj) override;

            /// <summary>Gets whether the tessellation sink of the mesh is opened.</summary>
            property bool SinkOpened
            {
                bool get()
                {
                    return sinkOpened;
                }
            }

            /// <summary>
            /// Opens the mesh for population.
            /// </summary>
            /// <returns>
            /// S_OK if opening has succeeded. D2DERR_WRONG_STATE if the sink is already opened.
            /// Error code if some other errors occurs.
            /// </returns>
            HRESULT OpenSink();

            /// <summary>
            /// Copies the specified triangles to the sink.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">Thrown when the tessellation sink
            /// for this mesh is not opened.</exception>
            void AddTriangles(... array<Direct2DNet::D2D1_TRIANGLE> ^triangles);


            /// <summary>
            /// Closes the sink and returns its error status.
            /// </summary>
            /// <returns>
            /// S_OK if closing has succeeded. D2DERR_WRONG_STATE if the sink is not opened.
            /// Error code if some other errors occurs.
            /// </returns>
            HRESULT CloseSink();
        };
    }
}