#include "IWICBitmapDecoderInfo.h"
#include "../ComIO/Stream.h"
#include "IWICBitmapDecoder.h"

namespace D2DNet
{
    namespace WICNet
    {
        HRESULT IWICBitmapDecoderInfo::GetPatterns(
            UINT cbSizePatterns,
            System::IntPtr %pPatterns,
            UINT %cPatterns,
            UINT %cbPatternsActual)
        {
            if(pPatterns == System::IntPtr::Zero)
            {
                UINT patterns = 0;
                UINT patternsActual = 0;
                HRESULT hr = ((::IWICBitmapDecoderInfo *)m_pInfo)->GetPatterns(
                    0,
                    __nullptr,
                    &patterns,
                    &patternsActual
                );

                cPatterns = patterns;
                cbPatternsActual = patternsActual;
                return hr;
            }

            UINT patterns = 0;
            UINT patternsActual = 0;
            HRESULT hr = ((::IWICBitmapDecoderInfo *)m_pInfo)->GetPatterns(
                cbSizePatterns,
                (::WICBitmapPattern *)pPatterns.ToPointer(),
                &patterns,
                &patternsActual
            );

            cPatterns = patterns;
            cbPatternsActual = patternsActual;
            return hr;
        }

        HRESULT IWICBitmapDecoderInfo::MatchesPattern(ComIO::Stream ^stream, bool %matches)
        {
            BOOL match = FALSE;
            HRESULT hr = ((::IWICBitmapDecoderInfo *)m_pInfo)->MatchesPattern(stream->m_pStream, &match);
            matches = System::Convert::ToBoolean(match);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICBitmapDecoderInfo::MatchesPattern(ComIO::Stream ^stream)
        {
            BOOL match = FALSE;
            HRESULT hr = ((::IWICBitmapDecoderInfo *)m_pInfo)->MatchesPattern(stream->m_pStream, &match);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(match)
                );
        }

        WICNet::IWICBitmapDecoder ^IWICBitmapDecoderInfo::CreateInstance()
        {
            return gcnew WICNet::IWICBitmapDecoder(this);
        }

    }
}