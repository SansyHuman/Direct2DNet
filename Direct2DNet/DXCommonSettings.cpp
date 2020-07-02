#include "DXCommonSettings.h"
#include "Direct2DNet/Exception/DXException.h"

namespace D2DNet
{
    System::Guid DirectX::ToManagedGUID(const _GUID &guid)
    {
        return System::Guid(guid.Data1, guid.Data2, guid.Data3,
            guid.Data4[0], guid.Data4[1],
            guid.Data4[2], guid.Data4[3],
            guid.Data4[4], guid.Data4[5],
            guid.Data4[6], guid.Data4[7]);
    }

    _GUID DirectX::ToNativeGUID(System::Guid %guid)
    {
        array<System::Byte> ^guidData = guid.ToByteArray();
        pin_ptr<System::Byte> data = &(guidData[0]);

        return *(_GUID *)data;
    }

    void DirectX::ThrowIfFailed(HRESULT hr)
    {
        if(FAILED(hr))
        {
            _com_error error(hr);
            throw gcnew Direct2DNet::Exception::DxException(
                marshal_as<System::String ^>(error.ErrorMessage()), hr
            );
        }

    }

    System::String ^DirectX::GetErrorMessage(HRESULT hr)
    {
        _com_error error(hr);
        return marshal_as<System::String ^>(error.ErrorMessage());
    }

    void DirectX::PrintDebugMessage(System::String ^message)
    {
        DirectX::OnDebugMessage(message);
    }

}