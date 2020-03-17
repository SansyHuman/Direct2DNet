#include "DXException.h"

Direct2DNet::Exception::DxException::DxException(System::String ^message, int errorCode) : System::Exception(message)
{
    HResult = errorCode;
}