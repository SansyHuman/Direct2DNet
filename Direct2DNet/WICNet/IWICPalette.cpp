#include "IWICPalette.h"
#include "IWICImagingFactory.h"
#include "IWICBitmapSource.h"

namespace D2DNet
{
    namespace WICNet
    {
        IWICPalette::IWICPalette(WICNet::IWICImagingFactory ^factory)
        {
            HRESULT hr = S_OK;
            pin_ptr<::IWICPalette *> ppPalette = &m_pPalette;
            hr = factory->m_pFactory->CreatePalette((::IWICPalette **)ppPalette);
            ppPalette = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IWICPalette", (int)hr);
        }

        void IWICPalette::HandleCOMInterface(void *obj)
        {
            if(m_pPalette)
            {
                m_pPalette->Release();
            }

            m_pPalette = (::IWICPalette *)obj;
            m_pPalette->AddRef();
        }

        HRESULT IWICPalette::InitializePredefined(
            WICNet::WICBitmapPaletteType paletteType,
            bool addTransparentColor)
        {
            return m_pPalette->InitializePredefined(
                (::WICBitmapPaletteType)((DWORD)paletteType),
                System::Convert::ToInt32(addTransparentColor)
            );
        }

        HRESULT IWICPalette::InitializeCustom(array<WICColor> ^colors)
        {
            UINT32 cCount = colors->Length;
            if(cCount == 0)
                return E_INVALIDARG;

            pin_ptr<WICColor> pColor = &colors[0];
            return m_pPalette->InitializeCustom((WICColor *)pColor, cCount);
        }

        HRESULT IWICPalette::InitializeFromBitmap(
            WICNet::IWICBitmapSource ^surface,
            UINT cCount,
            bool addTransparentColor)
        {
            return m_pPalette->InitializeFromBitmap(surface->m_pSource, cCount, System::Convert::ToInt32(addTransparentColor));
        }

        HRESULT IWICPalette::InitializeFromPalette(WICNet::IWICPalette ^palette)
        {
            return m_pPalette->InitializeFromPalette(palette->m_pPalette);
        }

        HRESULT IWICPalette::GetType(WICNet::WICBitmapPaletteType %paletteType)
        {
            ::WICBitmapPaletteType type = (::WICBitmapPaletteType)0;
            HRESULT hr = m_pPalette->GetType(&type);
            paletteType = (WICNet::WICBitmapPaletteType)((DWORD)type);
            return hr;
        }

        System::ValueTuple<HRESULT, WICNet::WICBitmapPaletteType> IWICPalette::GetType()
        {
            ::WICBitmapPaletteType type = (::WICBitmapPaletteType)0;
            HRESULT hr = m_pPalette->GetType(&type);
            return System::ValueTuple<HRESULT, WICNet::WICBitmapPaletteType>(
                hr, (WICNet::WICBitmapPaletteType)((DWORD)type)
                );
        }

        HRESULT IWICPalette::GetColorCount(UINT %cCount)
        {
            UINT cnt = 0;
            HRESULT hr = m_pPalette->GetColorCount(&cnt);
            cCount = cnt;
            return hr;
        }

        System::ValueTuple<HRESULT, UINT> IWICPalette::GetColorCount()
        {
            UINT cnt = 0;
            HRESULT hr = m_pPalette->GetColorCount(&cnt);
            return System::ValueTuple<HRESULT, UINT>(hr, cnt);
        }

        HRESULT IWICPalette::GetColors(array<WICColor> ^colors, UINT %cActualColors)
        {
            UINT cCount = colors->Length;
            if(cCount == 0)
            {
                UINT actualCount = 0;
                HRESULT hr = m_pPalette->GetColors(0, __nullptr, &actualCount);

                cActualColors = actualCount;
                return hr;
            }

            pin_ptr<WICColor> pColors = &colors[0];
            UINT actualCount = 0;
            HRESULT hr = m_pPalette->GetColors(cCount, (WICColor *)pColors, &actualCount);
            pColors = nullptr;

            cActualColors = actualCount;
            return hr;
        }

        HRESULT IWICPalette::IsBlackWhite(bool %isBlackWhite)
        {
            BOOL is = FALSE;
            HRESULT hr = m_pPalette->IsBlackWhite(&is);
            isBlackWhite = System::Convert::ToBoolean(is);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICPalette::IsBlackWhite()
        {
            BOOL is = FALSE;
            HRESULT hr = m_pPalette->IsBlackWhite(&is);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(is)
                );
        }

        HRESULT IWICPalette::IsGrayscale(bool %isGrayscale)
        {
            BOOL is = FALSE;
            HRESULT hr = m_pPalette->IsGrayscale(&is);
            isGrayscale = System::Convert::ToBoolean(is);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICPalette::IsGrayscale()
        {
            BOOL is = FALSE;
            HRESULT hr = m_pPalette->IsGrayscale(&is);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(is)
                );
        }

        HRESULT IWICPalette::HasAlpha(bool %hasAlpha)
        {
            BOOL has = FALSE;
            HRESULT hr = m_pPalette->HasAlpha(&has);
            hasAlpha = System::Convert::ToBoolean(has);
            return hr;
        }

        System::ValueTuple<HRESULT, bool> IWICPalette::HasAlpha()
        {
            BOOL has = FALSE;
            HRESULT hr = m_pPalette->HasAlpha(&has);
            return System::ValueTuple<HRESULT, bool>(
                hr, System::Convert::ToBoolean(has)
                );
        }

    }
}