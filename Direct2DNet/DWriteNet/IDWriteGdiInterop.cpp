#include "IDWriteGdiInterop.h"
#include "IDWriteFactory.h"
#include "IDWriteFont.h"
#include "IDWriteFontCollection.h"
#include "IDWriteFontFamily.h"
#include "IDWriteFontFace.h"
#include "IDWriteBitmapRenderTarget.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteGdiInterop::IDWriteGdiInterop(DWriteNet::IDWriteFactory ^factory)
        {
            pin_ptr<::IDWriteGdiInterop *> ppInterop = &m_pInterop;
            HRESULT hr = factory->m_pFactory->GetGdiInterop((::IDWriteGdiInterop **)ppInterop);
            ppInterop = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteGdiInterop.", (int)hr);
        }

        IDWriteGdiInterop::~IDWriteGdiInterop()
        {
            this->!IDWriteGdiInterop();
        }

        IDWriteGdiInterop::!IDWriteGdiInterop()
        {
            if(m_pInterop)
            {
                m_pInterop->Release();
                m_pInterop = nullptr;
            }
        }

        void IDWriteGdiInterop::HandleCOMInterface(void *obj)
        {
            if(m_pInterop)
            {
                m_pInterop->Release();
            }

            m_pInterop = (::IDWriteGdiInterop *)obj;
            m_pInterop->AddRef();
        }

        DWriteNet::IDWriteFont ^IDWriteGdiInterop::CreateFontFromLOGFONT(D2DNet::LOGFONTW %logFont)
        {
            ::IDWriteFont *pFont = __nullptr;

            HRESULT hr = m_pInterop->CreateFontFromLOGFONT(&static_cast<::LOGFONTW>(logFont), &pFont);
            if(FAILED(hr) || !pFont)
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteFont.", (int)hr);

            return gcnew DWriteNet::IDWriteFont(pFont);
        }

        HRESULT IDWriteGdiInterop::ConvertFontToLOGFONT(
            DWriteNet::IDWriteFont ^font,
            D2DNet::LOGFONTW %logFont,
            bool %isSystemFont)
        {
            ::LOGFONTW nativeLogFont = { 0 };
            BOOL nativeSystemFont = FALSE;

            HRESULT hr = m_pInterop->ConvertFontToLOGFONT(font->m_pFont, &nativeLogFont, &nativeSystemFont);

            logFont = static_cast<D2DNet::LOGFONTW>(nativeLogFont);
            isSystemFont = System::Convert::ToBoolean(nativeSystemFont);

            return hr;
        }

        System::ValueTuple<HRESULT, D2DNet::LOGFONTW, bool> IDWriteGdiInterop::ConvertFontToLOGFONT(
            DWriteNet::IDWriteFont ^font)
        {
            ::LOGFONTW nativeLogFont = { 0 };
            BOOL nativeSystemFont = FALSE;

            HRESULT hr = m_pInterop->ConvertFontToLOGFONT(font->m_pFont, &nativeLogFont, &nativeSystemFont);

            return System::ValueTuple<HRESULT, D2DNet::LOGFONTW, bool>(
                hr,
                static_cast<D2DNet::LOGFONTW>(nativeLogFont),
                System::Convert::ToBoolean(nativeSystemFont)
                );
        }

        HRESULT IDWriteGdiInterop::ConvertFontFaceToLOGFONT(
            DWriteNet::IDWriteFontFace ^font,
            D2DNet::LOGFONTW %logFont)
        {
            ::LOGFONTW nativeLogFont = { 0 };

            HRESULT hr = m_pInterop->ConvertFontFaceToLOGFONT(font->m_pFace, &nativeLogFont);

            logFont = static_cast<D2DNet::LOGFONTW>(nativeLogFont);
            
            return hr;
        }

        System::ValueTuple<HRESULT, D2DNet::LOGFONTW> IDWriteGdiInterop::ConvertFontFaceToLOGFONT(
            DWriteNet::IDWriteFontFace ^font)
        {
            ::LOGFONTW nativeLogFont = { 0 };

            HRESULT hr = m_pInterop->ConvertFontFaceToLOGFONT(font->m_pFace, &nativeLogFont);

            return System::ValueTuple<HRESULT, D2DNet::LOGFONTW>(
                hr,
                static_cast<D2DNet::LOGFONTW>(nativeLogFont)
                );
        }

        DWriteNet::IDWriteFontFace ^IDWriteGdiInterop::CreateFontFaceFromHdc(System::IntPtr %hdc)
        {
            ::IDWriteFontFace *pFace = __nullptr;

            HRESULT hr = m_pInterop->CreateFontFaceFromHdc((HDC)hdc.ToPointer(), &pFace);
            if(FAILED(hr) || !pFace)
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteFontFace.", (int)hr);

            return gcnew DWriteNet::IDWriteFontFace(pFace);
        }

        
        DWriteNet::IDWriteBitmapRenderTarget ^IDWriteGdiInterop::CreateBitmapRenderTarget(
            System::IntPtr %hdc,
            UINT32 width,
            UINT32 height)
        {
            return gcnew DWriteNet::GdiInteropBitmapRenderTarget(this, hdc, width, height);
        }
        
    }
}