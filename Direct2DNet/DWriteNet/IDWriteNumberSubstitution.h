#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"
#include "IDirectWriteObject.h"
#include "../Direct2DNet/Exception/DXException.h"
#include <msclr/marshal.h>

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteFactory;

        // Done.

        /// <summary>
        /// Holds the appropriate digits and numeric punctuation for a given locale.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("14885CC9-BAB0-4f90-B6ED-5C366A2CD03D")]
        public ref class IDWriteNumberSubstitution : DWriteNet::IDirectWriteObject
        {
        internal:
            ::IDWriteNumberSubstitution *m_pSub;

            IDWriteNumberSubstitution() : m_pSub(nullptr) {}

            IDWriteNumberSubstitution(
                DWriteNet::IDWriteFactory ^factory,
                DWriteNet::DWRITE_NUMBER_SUBSTITUTION_METHOD method,
                System::String ^localeName,
                bool ignoreUserOverride
            );

        public:
            ~IDWriteNumberSubstitution();
            !IDWriteNumberSubstitution();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pSub;
                }
            }

            virtual void HandleCOMInterface(void *obj);
        };
    }
}