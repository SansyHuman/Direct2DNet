#pragma once

#include "DWNetHeaders.h"
#include "DWriteSettings.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        public ref class DirectWrite abstract sealed
        {
        public:
            static UINT32 MakeOpentypeTag(wchar_t a, wchar_t b, wchar_t c, wchar_t d);
        };
    }
}