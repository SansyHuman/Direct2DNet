#include "IWICColorContext.h"

namespace D2DNet
{
    namespace WICNet
    {
        IWICColorContext::~IWICColorContext()
        {
            this->!IWICColorContext();
        }

        IWICColorContext::!IWICColorContext()
        {
            if(m_pContext)
            {
                m_pContext->Release();
                m_pContext = nullptr;
            }
        }

        void IWICColorContext::HandleCOMInterface(void *obj)
        {
            if(m_pContext)
            {
                m_pContext->Release();
            }

            m_pContext = (::IWICColorContext *)obj;
            m_pContext->AddRef();
        }

        HRESULT IWICColorContext::InitializeFromFilename(System::String ^filename)
        {
            marshal_context context;

            return m_pContext->InitializeFromFilename(
                context.marshal_as<LPCWSTR>(filename)
            );
        }

        HRESULT IWICColorContext::InitializeFromMemory(array<BYTE> ^buffer)
        {
            UINT cbBufferSize = buffer->Length;
            if(cbBufferSize == 0)
                return m_pContext->InitializeFromMemory(__nullptr, 0);

            pin_ptr<BYTE> pbBuffer = &buffer[0];
            return m_pContext->InitializeFromMemory((BYTE *)pbBuffer, cbBufferSize);
        }

        HRESULT IWICColorContext::InitializeFromExifColorSpace(UINT value)
        {
            return m_pContext->InitializeFromExifColorSpace(value);
        }

        HRESULT IWICColorContext::GetType(WICNet::WICColorContextType %type)
        {
            ::WICColorContextType t = (::WICColorContextType)0;
            HRESULT hr = m_pContext->GetType(&t);
            type = (WICNet::WICColorContextType)((int)t);
            return hr;
        }

        System::ValueTuple<HRESULT, WICNet::WICColorContextType> IWICColorContext::GetType()
        {
            ::WICColorContextType t = (::WICColorContextType)0;
            HRESULT hr = m_pContext->GetType(&t);
            return System::ValueTuple<HRESULT, WICNet::WICColorContextType>(
                hr, (WICNet::WICColorContextType)((int)t)
                );
        }

        HRESULT IWICColorContext::GetProfileBytes(UINT %cbActual, array<BYTE> ^buffer)
        {
            if(!buffer)
            {
                UINT actual = 0;
                HRESULT hr = m_pContext->GetProfileBytes(0, __nullptr, &actual);
                cbActual = actual;
                return hr;
            }

            UINT cbBuffer = buffer->Length;
            if(cbBuffer == 0)
            {
                UINT actual = 0;
                HRESULT hr = m_pContext->GetProfileBytes(0, __nullptr, &actual);
                cbActual = actual;
                return hr;
            }

            pin_ptr<BYTE> pbBuffer = &buffer[0];
            UINT actual = 0;
            HRESULT hr = m_pContext->GetProfileBytes(cbBuffer, (BYTE *)pbBuffer, &actual);
            pbBuffer = nullptr;

            cbActual = actual;
            return hr;
        }

        HRESULT IWICColorContext::GetExifColorSpace(UINT %value)
        {
            UINT val = 0;
            HRESULT hr = m_pContext->GetExifColorSpace(&val);
            value = val;
            return hr;
        }

        System::ValueTuple<HRESULT, UINT> IWICColorContext::GetExifColorSpace()
        {
            UINT val = 0;
            HRESULT hr = m_pContext->GetExifColorSpace(&val);
            return System::ValueTuple<HRESULT, UINT>(hr, val);
        }

    }
}