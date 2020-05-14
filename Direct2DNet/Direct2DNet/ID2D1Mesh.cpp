#include "ID2D1Mesh.h"
#include "ID2D1RenderTarget.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Mesh::ID2D1Mesh(Direct2DNet::ID2D1RenderTarget ^renderTarget)
            : Direct2DNet::ID2D1Resource(renderTarget->Factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1RenderTarget *)renderTarget->m_pResource)->CreateMesh(
                (::ID2D1Mesh **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Mesh", (int)hr);
        }

        ID2D1Mesh::~ID2D1Mesh()
        {
            this->!ID2D1Mesh();
        }

        ID2D1Mesh::!ID2D1Mesh()
        {
            if(m_pSink)
            {
                m_pSink->Release();
                m_pSink = nullptr;
            }
        }

        HRESULT ID2D1Mesh::OpenSink()
        {
            if(sinkOpened)
                return D2DERR_WRONG_STATE;

            HRESULT hr = S_OK;

            pin_ptr<::ID2D1TessellationSink *> ppSink = &m_pSink;
            hr = ((::ID2D1Mesh *)m_pResource)->Open((::ID2D1TessellationSink **)ppSink);
            ppSink = nullptr;

            if(SUCCEEDED(hr))
                sinkOpened = true;

            return hr;
        }

        void ID2D1Mesh::AddTriangles(...array<Direct2DNet::D2D1_TRIANGLE> ^triangles)
        {
            if(!sinkOpened)
                throw gcnew Direct2DNet::Exception::DxException("The tessellation sink for this mesh is not opened.", D2DERR_WRONG_STATE);

            std::vector<::D2D1_TRIANGLE> nativeTriangles(triangles->Length);
            for(int i = 0; i < triangles->Length; i++)
            {
                nativeTriangles[i] = static_cast<::D2D1_TRIANGLE>(triangles[i]);
            }

            m_pSink->AddTriangles(nativeTriangles.data(), nativeTriangles.size());
        }

        HRESULT ID2D1Mesh::CloseSink()
        {
            if(!sinkOpened)
                return D2DERR_WRONG_STATE;

            HRESULT hr = S_OK;
            hr = m_pSink->Close();

            if(SUCCEEDED(hr))
            {
                sinkOpened = false;
                m_pSink->Release();
                m_pSink = nullptr;
            }

            return hr;
        }

    }
}