#include "DWriteException.h"

D2DNet::DWriteNet::Exception::DWriteException::DWriteException(System::String ^message, int errorCode) : System::Exception(message)
{
    HResult = errorCode;
}