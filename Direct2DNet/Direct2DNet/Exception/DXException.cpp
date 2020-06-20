#include "DXException.h"

namespace D2DNet
{
    Direct2DNet::Exception::DxException::DxException(System::String ^message, int errorCode) : System::Exception(message + "\n" + D2DNet::DirectX::GetErrorMessage(errorCode))
    {
        HResult = errorCode;
    }
}