#include "ID2D1Effect.h"
#include "ID2D1DeviceContext.h"
#include "ID2D1Image.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Effect::ID2D1Effect(Direct2DNet::ID2D1DeviceContext ^deviceContext, System::Guid %effectId)
            : Direct2DNet::ID2D1Properties()
        {
            HRESULT hr = S_OK;
            pin_ptr<::ID2D1Properties *> ppProperties = &m_pProperties;
            hr = ((::ID2D1DeviceContext *)deviceContext->m_pResource)->CreateEffect(
                D2DNet::DirectX::ToNativeGUID(effectId),
                (::ID2D1Effect **)ppProperties
            );
            ppProperties = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1Effect", (int)hr);

            UINT32 inputCount = ((::ID2D1Effect *)m_pProperties)->GetInputCount();
            m_inputs = gcnew array<Direct2DNet::ID2D1Image ^>(inputCount);
        }

        void ID2D1Effect::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Properties::HandleCOMInterface(obj);

            UINT32 inputCount = ((::ID2D1Effect *)m_pProperties)->GetInputCount();
            m_inputs = gcnew array<Direct2DNet::ID2D1Image ^>(inputCount);

            for(UINT32 i = 0; i < inputCount; i++)
            {
                ::ID2D1Image *input = __nullptr;
                ((::ID2D1Effect *)m_pProperties)->GetInput(i, &input);
                if(!input)
                    m_inputs[i] = nullptr;
                else
                {
                    ::ID2D1Factory *factory = __nullptr;
                    input->GetFactory(&factory);
                    m_inputs[i] = gcnew Direct2DNet::ID2D1Image(
                        gcnew Direct2DNet::ID2D1Factory(factory), input
                    );
                }
            }
        }

        void ID2D1Effect::SetInput(
            unsigned int index,
            Direct2DNet::ID2D1Image ^input,
            System::Nullable<bool> invalidate)
        {
            if(index >= m_inputs->Length)
                return;

            if(!invalidate.HasValue)
                invalidate = true;

            ((::ID2D1Effect *)m_pProperties)->SetInput(
                index,
                input == nullptr ? __nullptr : (::ID2D1Image *)input->m_pResource,
                System::Convert::ToInt32(invalidate.Value)
            );
            m_inputs[index] = input;
        }

        HRESULT ID2D1Effect::SetInputCount(unsigned int inputCount)
        {
            HRESULT hr = ((::ID2D1Effect *)m_pProperties)->SetInputCount(inputCount);
            if(SUCCEEDED(hr))
            {
                array<Direct2DNet::ID2D1Image ^> ^temp = m_inputs;
                m_inputs = gcnew array<Direct2DNet::ID2D1Image ^>(inputCount);
                
                for(int i = 0; (i < temp->Length) && (i < m_inputs->Length); i++)
                {
                    m_inputs[i] = temp[i];
                }
            }

            return hr;
        }

        Direct2DNet::ID2D1Image ^ID2D1Effect::GetInput(unsigned int index)
        {
            if(index >= m_inputs->Length)
                return nullptr;

            return m_inputs[index];
        }

        unsigned int ID2D1Effect::GetInputCount()
        {
            return m_inputs->Length;
        }

        Direct2DNet::ID2D1Image ^ID2D1Effect::Output::get()
        {
            ::ID2D1Image *pImage = __nullptr;

            ((::ID2D1Effect *)m_pProperties)->GetOutput(&pImage);

            Direct2DNet::ID2D1Image ^image = gcnew Direct2DNet::ID2D1Image();
            image->HandleCOMInterface(pImage);
            pImage->Release();

            return image;
        }

        void ID2D1Effect::SetInputEffect(
            unsigned int index,
            Direct2DNet::ID2D1Effect ^inputEffect,
            System::Nullable<bool> invalidate)
        {
            if(index >= m_inputs->Length)
                return;

            if(!invalidate.HasValue)
                invalidate = true;

            Direct2DNet::ID2D1Image ^output = inputEffect->Output;

            this->SetInput(
                index,
                output,
                invalidate
            );
        }

    }
}