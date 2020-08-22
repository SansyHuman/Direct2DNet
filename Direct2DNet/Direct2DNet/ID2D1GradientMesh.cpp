#include "ID2D1GradientMesh.h"
#include "ID2D1DeviceContext2.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GradientMesh::ID2D1GradientMesh(
            Direct2DNet::ID2D1DeviceContext2 ^context,
            array<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> ^patches)
            : Direct2DNet::ID2D1Resource(context->m_factory)
        {
            HRESULT hr = S_OK;

            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            pin_ptr<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> pPatches = &patches[0];
            hr = ((::ID2D1DeviceContext2 *)context->m_pResource)->CreateGradientMesh(
                reinterpret_cast<::D2D1_GRADIENT_MESH_PATCH *>(pPatches),
                patches->Length,
                (::ID2D1GradientMesh **)ppResource
            );
            ppResource = nullptr;
            pPatches = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1GradientMesh", (int)hr);
        }

        HRESULT ID2D1GradientMesh::GetPatches(
            UINT32 startIndex,
            array<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> ^patches)
        {
            if(patches->Length == 0)
                return S_OK;

            pin_ptr<Direct2DNet::D2D1_GRADIENT_MESH_PATCH> pPatches = &patches[0];
            return ((::ID2D1GradientMesh *)m_pResource)->GetPatches(
                startIndex,
                reinterpret_cast<::D2D1_GRADIENT_MESH_PATCH *>(pPatches),
                (UINT32)patches->Length
            );
        }

    }
}