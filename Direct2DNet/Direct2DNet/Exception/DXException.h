#pragma once

namespace Direct2DNet
{
    namespace Exception
    {
        /// <summary>
        /// Exception thrown when there are critical error
        /// when calling functions in Direct2DNet library.
        /// Use <see cref="Exception::HResult"/> property
        /// to get Direct2D error code.
        /// </summary>
        public ref class DxException : System::Exception
        {
        public:
            DxException(System::String ^message, int errorCode);
        };
    }
}