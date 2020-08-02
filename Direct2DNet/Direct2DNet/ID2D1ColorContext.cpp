#include "ID2D1ColorContext.h"
#include "ID2D1DeviceContext.h"
#include "ID2D1Factory1.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1ColorContext::ID2D1ColorContext(
            Direct2DNet::ID2D1DeviceContext ^context,
            Direct2DNet::D2D1_COLOR_SPACE space,
            array<unsigned char> ^profile) : Direct2DNet::ID2D1Resource(context->m_factory), m_space(space)
        {
            HRESULT hr = S_OK;

            pin_ptr<unsigned char> pProfile = profile == nullptr ? nullptr : &profile[0];
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext *)context->m_pResource)->CreateColorContext(
                (::D2D1_COLOR_SPACE)((int)space),
                (BYTE *)pProfile,
                profile == nullptr ? 0 : profile->Length,
                (::ID2D1ColorContext **)ppResource
            );
            pProfile = nullptr;
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1ColorContext", (int)hr);

            if(profile == nullptr)
            {
                m_profile = nullptr;
            }
            else
            {
                m_profile = gcnew array<unsigned char>(profile->Length);
                profile->CopyTo(m_profile, 0);
            }
        }

        ID2D1ColorContext::ID2D1ColorContext(
            Direct2DNet::ID2D1DeviceContext ^deviceContext,
            System::String ^filename) : Direct2DNet::ID2D1Resource(deviceContext->m_factory)
        {
            HRESULT hr = S_OK;

            marshal_context context;
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateColorContextFromFilename(
                context.marshal_as<PCWSTR>(filename),
                (::ID2D1ColorContext **)ppResource
            );
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1ColorContext", (int)hr);

            m_space = (Direct2DNet::D2D1_COLOR_SPACE)((int)((::ID2D1ColorContext *)m_pResource)->GetColorSpace());
            unsigned int profileSize = ((::ID2D1ColorContext *)m_pResource)->GetProfileSize();
            if(profileSize <= 0)
            {
                m_profile = nullptr;
            }
            else
            {
                m_profile = gcnew array<unsigned char>(profileSize);
                pin_ptr<unsigned char> pProfile = &m_profile[0];

                hr = ((::ID2D1ColorContext *)m_pResource)->GetProfile((BYTE *)pProfile, profileSize);
                pProfile = nullptr;

                if(FAILED(hr))
                {
                    delete m_profile;
                    m_profile = nullptr;
                }
            }
        }

        ID2D1ColorContext::ID2D1ColorContext(
            Direct2DNet::ID2D1Factory1 ^factory,
            ::ID2D1ColorContext *pContext)
            : Direct2DNet::ID2D1Resource(factory)
        {
            m_pResource = pContext;

            m_space = (Direct2DNet::D2D1_COLOR_SPACE)((int)pContext->GetColorSpace());
            unsigned int profileSize = ((::ID2D1ColorContext *)m_pResource)->GetProfileSize();
            if(profileSize <= 0)
            {
                m_profile = nullptr;
            }
            else
            {
                m_profile = gcnew array<unsigned char>(profileSize);
                pin_ptr<unsigned char> pProfile = &m_profile[0];

                HRESULT hr = ((::ID2D1ColorContext *)m_pResource)->GetProfile((BYTE *)pProfile, profileSize);
                pProfile = nullptr;

                if(FAILED(hr))
                {
                    delete m_profile;
                    m_profile = nullptr;
                }
            }
        }

        void ID2D1ColorContext::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Resource::HandleCOMInterface(obj);

            m_space = (Direct2DNet::D2D1_COLOR_SPACE)((int)((::ID2D1ColorContext *)m_pResource)->GetColorSpace());
            unsigned int profileSize = ((::ID2D1ColorContext *)m_pResource)->GetProfileSize();
            if(profileSize == 0)
            {
                m_profile = nullptr;
            }
            else
            {
                m_profile = gcnew array<unsigned char>(profileSize);
                pin_ptr<unsigned char> pProfile = &m_profile[0];

                HRESULT hr = ((::ID2D1ColorContext *)m_pResource)->GetProfile((BYTE *)pProfile, profileSize);
                pProfile = nullptr;

                if(FAILED(hr))
                {
                    delete m_profile;
                    m_profile = nullptr;
                }
            }
        }

        HRESULT ID2D1ColorContext::GetProfile(array<unsigned char> ^profileBuffer)
        {
            if(ProfileSize == 0)
                return S_OK;

            if(profileBuffer->Length == 0)
                return D2DERR_INSUFFICIENT_BUFFER;

            if(m_profile)
            {
                if(m_profile->Length > profileBuffer->Length)
                    return D2DERR_INSUFFICIENT_BUFFER;

                m_profile->CopyTo(profileBuffer, 0);
                return S_OK;
            }

            UINT32 profileSize = ProfileSize;
            if(profileSize > profileBuffer->Length)
                return D2DERR_INSUFFICIENT_BUFFER;

            m_profile = gcnew array<unsigned char>(profileSize);

            pin_ptr<BYTE> pBuf = &m_profile[0];
            HRESULT hr = ((::ID2D1ColorContext *)m_pResource)->GetProfile((BYTE *)pBuf, profileSize);
            pBuf = nullptr;

            if(SUCCEEDED(hr))
            {
                m_profile->CopyTo(profileBuffer, 0);
                return hr;
            }

            delete m_profile;
            m_profile = nullptr;
            return hr;
        }

    }
}