#pragma once

namespace Direct2DNet
{
    namespace Exception
    {
        public ref class DxException : System::Exception
        {
        public:
            DxException(System::String ^message, int errorCode);
        };
    }
}