#include "IDXGIObject.h"
#include "../DXCommonSettings.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace DXGINet
    {
        IDXGIObject::~IDXGIObject()
        {
            this->!IDXGIObject();
        }

        IDXGIObject::!IDXGIObject()
        {
            if(m_pObj)
            {
                m_pObj->Release();
                m_pObj = nullptr;
            }
        }

        void IDXGIObject::HandleCOMInterface(void *obj)
        {
            if(m_pObj)
            {
                m_pObj->Release();
            }

            m_pObj = (::IDXGIObject *)obj;
            m_pObj->AddRef();
        }

        HRESULT IDXGIObject::SetPrivateData(
            System::Guid %name,
            UINT dataSize,
            void *pData)
        {
            return m_pObj->SetPrivateData(
                DirectX::ToNativeGUID(name),
                dataSize,
                pData
            );
        }

        HRESULT IDXGIObject::SetPrivateDataInterface(
            System::Guid %name,
            D2DNet::IUnknown ^unknown
        )
        {
            return m_pObj->SetPrivateDataInterface(
                DirectX::ToNativeGUID(name),
                (::IUnknown *)unknown->NativePointer
            );
        }

        HRESULT IDXGIObject::GetPrivateData(
            System::Guid %name,
            UINT dataSize,
            void *pData)
        {
            return m_pObj->GetPrivateData(
                DirectX::ToNativeGUID(name),
                &dataSize,
                pData
            );
        }

        generic<typename T> where T : D2DNet::IUnknown
        HRESULT IDXGIObject::GetParent(T %parent)
        {
            ::IUnknown *pParent = __nullptr;

            try
            {
                System::Type ^parentType = T::typeid;

                InteropServices::GuidAttribute ^parentUidAttr = (InteropServices::GuidAttribute ^)System::Attribute::GetCustomAttribute(
                    parentType, InteropServices::GuidAttribute::typeid
                );
                ::GUID parentUid = DirectX::ToNativeGUID(System::Guid(parentUidAttr->Value));

                HRESULT hr = m_pObj->GetParent(parentUid, (void **)&pParent);
                if(FAILED(hr) || !pParent)
                {
                    return hr;
                }

                parent = (T)System::Activator::CreateInstance(parentType, true);
                parent->HandleCOMInterface(pParent);

                return hr;
            }
            catch(System::Exception ^e)
            {
                return e->HResult;
            }
            finally
            {
                if(pParent)
                {
                    pParent->Release();
                    pParent = __nullptr;
                }
            }
        }

        HRESULT IDXGIObject::GetParent(System::Guid %riid, D2DNet::IUnknown ^%parent)
        {
            ::IUnknown *pParent = __nullptr;

            try
            {
                if(!D2DNetGUID::uidTypePairs->ContainsKey(riid))
                {
                    parent = nullptr;
                    return E_NOINTERFACE;
                }

                System::Type ^parentType = D2DNetGUID::uidTypePairs[riid];
                ::GUID parentTypeUid = DirectX::ToNativeGUID(riid);

                HRESULT hr = m_pObj->GetParent(parentTypeUid, (void **)&pParent);
                if(FAILED(hr) || !pParent)
                {
                    parent = nullptr;
                    return hr;
                }

                parent = (D2DNet::IUnknown ^)System::Activator::CreateInstance(parentType, true);
                parent->HandleCOMInterface(pParent);

                return hr;
            }
            catch(System::Exception ^e)
            {
                return e->HResult;
            }
            finally
            {
                if(pParent)
                {
                    pParent->Release();
                    pParent = __nullptr;
                }
            }
        }

    }
}