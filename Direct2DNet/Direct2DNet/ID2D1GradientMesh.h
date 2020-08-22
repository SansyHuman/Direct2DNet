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
        ref class ID2D1DeviceContext2;

        // Done.

        /// <summary>
        /// Represents a device-dependent representation of a gradient mesh composed of
        /// patches. Use the ID2D1DeviceContext2::CreateGradientMesh method to create an
        /// instance of ID2D1GradientMesh.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("f292e401-c050-4cde-83d7-04962d3b23c2")]
        public ref class ID2D1GradientMesh : Direct2DNet::ID2D1Resource
        {
        internal:
            ID2D1GradientMesh() : Direct2DNet::ID2D1Resource() {}

            ID2D1GradientMesh(
                Direct2DNet::ID2D1DeviceContext2 ^context,
                array<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> ^patches
            );

        public:
            /// <summary>
            /// Gets the number of patches of the gradient mesh.
            /// </summary>
            property UINT32 PatchCount
            {
                UINT32 get()
                {
                    return ((::ID2D1GradientMesh *)m_pResource)->GetPatchCount();
                }
            }

            /// <summary>
            /// Retrieves the patch data stored in the gradient mesh.
            /// </summary>
            /// <param name="startIndex">
            /// Index of the first patch to return.
            /// </param>
            /// <param name="patches">
            /// The buffer array to be filled with the patch data. The number of patches to retrieve is the
            /// length of the buffer.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK(0). Otherwise, it returns an error code.
            /// </returns>
            HRESULT GetPatches(
                UINT32 startIndex,
                array<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> ^patches
            );
        };
    }
}