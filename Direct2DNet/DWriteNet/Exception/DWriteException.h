#pragma once


namespace D2DNet
{
    namespace DWriteNet
    {
        namespace Exception
        {
            /// <summary>
            /// Exception thrown when there are critical error
            /// when calling functions in DWriteNet library.
            /// Use <see cref="Exception::HResult"/> property
            /// to get DirectWrite error code.
            /// </summary>
            public ref class DWriteException : System::Exception
            {
            public:
                DWriteException(System::String ^message, int errorCode);
            };
        }
    }
}