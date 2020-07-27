#include "IDWriteNumberSubstitution.h"
#include "IDWriteFactory.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteNumberSubstitution::IDWriteNumberSubstitution(
            DWriteNet::IDWriteFactory ^factory,
            DWriteNet::DWRITE_NUMBER_SUBSTITUTION_METHOD method,
            System::String ^localeName,
            bool ignoreUserOverride)
        {
            marshal_context context;

            pin_ptr<::IDWriteNumberSubstitution *> ppSub = &m_pSub;
            HRESULT hr = factory->m_pFactory->CreateNumberSubstitution(
                (::DWRITE_NUMBER_SUBSTITUTION_METHOD)((int)method),
                context.marshal_as<const WCHAR *>(localeName),
                System::Convert::ToInt32(ignoreUserOverride),
                (::IDWriteNumberSubstitution **)ppSub
            );

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteNumberSubstitution.", (int)hr);
        }

        IDWriteNumberSubstitution::~IDWriteNumberSubstitution()
        {
            this->!IDWriteNumberSubstitution();
        }

        IDWriteNumberSubstitution::!IDWriteNumberSubstitution()
        {
            if(m_pSub)
            {
                m_pSub->Release();
                m_pSub = nullptr;
            }
        }

        void IDWriteNumberSubstitution::HandleCOMInterface(void *obj)
        {
            if(m_pSub)
            {
                m_pSub->Release();
            }

            m_pSub = (::IDWriteNumberSubstitution *)obj;
            m_pSub->AddRef();
        }

    }
}