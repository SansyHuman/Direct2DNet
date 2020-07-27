#include "DirectWrite.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        UINT32 DirectWrite::MakeOpentypeTag(wchar_t a, wchar_t b, wchar_t c, wchar_t d)
        {
            auto bytes = System::Text::Encoding::ASCII->GetBytes(gcnew array<wchar_t>{ a, b, c, d } );
            return DWRITE_MAKE_OPENTYPE_TAG(bytes[0], bytes[1], bytes[2], bytes[3]);
        }

        UINT32 DirectWrite::MakeFontFeatureTag(wchar_t a, wchar_t b, wchar_t c, wchar_t d)
        {
            return DirectWrite::MakeOpentypeTag(a, b, c, d);
        }

        COLORREF DirectWrite::MakeRGB(BYTE r, BYTE g, BYTE b)
        {
            return RGB(r, g, b);
        }

    }
}