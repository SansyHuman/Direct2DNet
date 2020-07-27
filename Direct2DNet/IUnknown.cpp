#include "IUnknown.h"
#include "DXCommonSettings.h"
#include "GUIDs.h"

namespace D2DNet
{
    generic<typename T> where T : D2DNet::IUnknown
    HRESULT D2DNet::IUnknownExtension::QueryInterface(D2DNet::IUnknown ^obj, T %queryObj)
    {
        ::IUnknown *pObj = (::IUnknown *)obj->NativePointer;
        ::IUnknown *pQueryObj = __nullptr;

        try
        {
            System::Type ^originType = obj->GetType();
            System::Type ^queryType = T::typeid;
            if(originType == queryType)
            {
                queryObj = (T)obj;
                return S_OK;
            }

            GuidAttribute ^queryTypeUidAttr = (GuidAttribute ^)System::Attribute::GetCustomAttribute(queryType, GuidAttribute::typeid);
            ::GUID queryTypeUid = DirectX::ToNativeGUID(System::Guid(queryTypeUidAttr->Value));

            HRESULT hr = pObj->QueryInterface(queryTypeUid, (void **)&pQueryObj);
            if(FAILED(hr) || !pQueryObj)
            {
                return hr;
            }

            queryObj = (T)System::Activator::CreateInstance(queryType, true);
            queryObj->HandleCOMInterface(pQueryObj);

            return hr;
        }
        catch(System::Exception ^e)
        {
            return e->HResult;
        }
        finally
        {
            if(pQueryObj)
            {
                pQueryObj->Release();
                pQueryObj = __nullptr;
            }
        }
    }

    HRESULT IUnknownExtension::QueryInterface(
        D2DNet::IUnknown ^obj,
        System::Guid %riid,
        D2DNet::IUnknown ^%queryObj)
    {
        ::IUnknown *pObj = (::IUnknown *)obj->NativePointer;
        ::IUnknown *pQueryObj = __nullptr;

        try
        {
            System::Type ^originType = obj->GetType();
            if(!D2DNetGUID::uidTypePairs->ContainsKey(riid))
            {
                queryObj = nullptr;
                return E_INVALIDARG;
            }
            System::Type ^queryType = D2DNetGUID::uidTypePairs[riid];
            if(originType == queryType)
            {
                queryObj = obj;
                return S_OK;
            }

            ::GUID queryTypeUid = DirectX::ToNativeGUID(riid);

            HRESULT hr = pObj->QueryInterface(queryTypeUid, (void **)&pQueryObj);
            if(FAILED(hr) || !pQueryObj)
            {
                queryObj = nullptr;
                return hr;
            }

            queryObj = (D2DNet::IUnknown ^)System::Activator::CreateInstance(queryType, true);
            queryObj->HandleCOMInterface(pQueryObj);

            return hr;
        }
        catch(System::Exception ^e)
        {
            return e->HResult;
        }
        finally
        {
            if(pQueryObj)
            {
                pQueryObj->Release();
                pQueryObj = __nullptr;
            }
        }
    }

}