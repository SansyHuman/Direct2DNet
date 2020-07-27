#include "IDWriteTextLayout.h"
#include "IDWriteFactory.h"
#include "IDWriteFontCollection.h"
#include "IDWriteTypography.h"
#include "IDWriteInlineObject.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteTextLayout::IDWriteTextLayout(
            DWriteNet::IDWriteFactory ^factory,
            System::String ^string,
            DWriteNet::IDWriteTextFormat ^textFormat,
            float maxWidth,
            float maxHeight)
            : DWriteNet::IDWriteTextFormat(factory)
        {
            marshal_context context;

            HRESULT hr = S_OK;
            pin_ptr<::IDWriteTextFormat *> ppFormat = &m_pFormat;
            const WCHAR *wstring = context.marshal_as<const WCHAR *>(string);
            hr = factory->m_pFactory->CreateTextLayout(
                wstring,
                wcslen(wstring),
                textFormat->m_pFormat,
                maxWidth,
                maxHeight,
                (::IDWriteTextLayout **)ppFormat
            );
            ppFormat = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteTextLayout.", (int)hr);
        }

        IDWriteTextLayout::IDWriteTextLayout(
            DWriteNet::IDWriteFactory ^factory,
            System::String ^string,
            DWriteNet::IDWriteTextFormat ^textFormat,
            float layoutWidth,
            float layoutHeight,
            float pixelsPerDip,
            bool useGdiNatural,
            System::Nullable<DWriteNet::DWRITE_MATRIX> %transform)
            : DWriteNet::IDWriteTextFormat(factory)
        {
            marshal_context context;

            HRESULT hr = S_OK;
            pin_ptr<::IDWriteTextFormat *> ppFormat = &m_pFormat;
            const WCHAR *wstring = context.marshal_as<const WCHAR *>(string);
            pin_ptr<DWriteNet::DWRITE_MATRIX> pTransform = nullptr;
            if(transform.HasValue)
                pTransform = &transform.Value;

            hr = factory->m_pFactory->CreateGdiCompatibleTextLayout(
                wstring,
                wcslen(wstring),
                textFormat->m_pFormat,
                layoutWidth,
                layoutHeight,
                pixelsPerDip,
                reinterpret_cast<::DWRITE_MATRIX *>(pTransform),
                System::Convert::ToInt32(useGdiNatural),
                (::IDWriteTextLayout **)ppFormat
            );
            ppFormat = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteTextLayout.", (int)hr);
        }

        HRESULT IDWriteTextLayout::SetMaxWidth(float maxWidth)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetMaxWidth(maxWidth);
        }

        HRESULT IDWriteTextLayout::SetMaxHeight(float maxHeight)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetMaxHeight(maxHeight);
        }

        HRESULT IDWriteTextLayout::SetFontCollection(
            DWriteNet::IDWriteFontCollection ^fontCollection,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetFontCollection(
                fontCollection->m_pCollection,
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetFontFamilyName(
            System::String ^fontFamilyName,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            marshal_context context;

            return ((::IDWriteTextLayout *)m_pFormat)->SetFontFamilyName(
                context.marshal_as<const WCHAR *>(fontFamilyName),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetFontWeight(
            DWriteNet::DWRITE_FONT_WEIGHT fontWeight,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetFontWeight(
                (::DWRITE_FONT_WEIGHT)((int)fontWeight),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetFontStyle(
            DWriteNet::DWRITE_FONT_STYLE fontStyle,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetFontStyle(
                (::DWRITE_FONT_STYLE)((int)fontStyle),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetFontStretch(
            DWriteNet::DWRITE_FONT_STRETCH fontStretch,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetFontStretch(
                (::DWRITE_FONT_STRETCH)((int)fontStretch),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetFontSize(float fontSize, DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetFontSize(
                fontSize,
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetUnderline(bool hasUnderline, DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetUnderline(
                System::Convert::ToInt32(hasUnderline),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetStrikethrough(bool hasStrikethrough, DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetStrikethrough(
                System::Convert::ToInt32(hasStrikethrough),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetDrawingEffect(
            D2DNet::IUnknown ^drawingEffect,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetDrawingEffect(
                reinterpret_cast<::IUnknown *>(drawingEffect->NativePointer),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetInlineObject(
            DWriteNet::IDWriteInlineObject ^inlineObject,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetInlineObject(
                inlineObject->m_pObject,
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetTypography(
            DWriteNet::IDWriteTypography ^typography,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            return ((::IDWriteTextLayout *)m_pFormat)->SetTypography(
                typography->m_pTypo,
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        HRESULT IDWriteTextLayout::SetLocaleName(
            System::String ^localeName,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            marshal_context context;

            return ((::IDWriteTextLayout *)m_pFormat)->SetLocaleName(
                context.marshal_as<const WCHAR *>(localeName),
                static_cast<::DWRITE_TEXT_RANGE>(textRange)
            );
        }

        float IDWriteTextLayout::GetMaxWidth()
        {
            return ((::IDWriteTextLayout *)m_pFormat)->GetMaxWidth();
        }

        float IDWriteTextLayout::GetMaxHeight()
        {
            return ((::IDWriteTextLayout *)m_pFormat)->GetMaxHeight();
        }

        HRESULT IDWriteTextLayout::GetFontCollection(
            UINT32 currentPosition,
            DWriteNet::IDWriteFontCollection ^%fontCollection,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            ::IDWriteFontCollection *pCollection = __nullptr;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetFontCollection(
                currentPosition,
                &pCollection,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            if(FAILED(hr) || !pCollection)
                fontCollection = nullptr;
            else
                fontCollection = gcnew DWriteNet::IDWriteFontCollection(pCollection);

            return hr;
        }

        HRESULT IDWriteTextLayout::GetFontFamilyName(
            UINT32 currentPosition,
            System::String ^%fontFamilyName,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            UINT32 length = 0;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetFontFamilyNameLength(
                currentPosition,
                &length
            );

            if(FAILED(hr))
            {
                fontFamilyName = nullptr;
                return hr;
            }

            length += 1;
            std::vector<WCHAR> name(length);
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            hr = ((::IDWriteTextLayout *)m_pFormat)->GetFontFamilyName(
                currentPosition,
                name.data(),
                length,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            if(FAILED(hr))
                fontFamilyName = nullptr;
            else
                fontFamilyName = marshal_as<System::String ^>(name.data());

            return hr;
        }

        HRESULT IDWriteTextLayout::GetFontWeight(
            UINT32 currentPosition,
            DWriteNet::DWRITE_FONT_WEIGHT %fontWeight,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            pin_ptr<DWriteNet::DWRITE_FONT_WEIGHT> pWeight = &fontWeight;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetFontWeight(
                currentPosition,
                reinterpret_cast<::DWRITE_FONT_WEIGHT *>(pWeight),
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pWeight = nullptr;
            pRange = nullptr;

            return hr;
        }

        HRESULT IDWriteTextLayout::GetFontStyle(
            UINT32 currentPosition,
            DWriteNet::DWRITE_FONT_STYLE %fontStyle,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            pin_ptr<DWriteNet::DWRITE_FONT_STYLE> pStyle = &fontStyle;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetFontStyle(
                currentPosition,
                reinterpret_cast<::DWRITE_FONT_STYLE *>(pStyle),
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pStyle = nullptr;
            pRange = nullptr;

            return hr;
        }

        HRESULT IDWriteTextLayout::GetFontStretch(
            UINT32 currentPosition,
            DWriteNet::DWRITE_FONT_STRETCH %fontStretch,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            pin_ptr<DWriteNet::DWRITE_FONT_STRETCH> pStretch = &fontStretch;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetFontStretch(
                currentPosition,
                reinterpret_cast<::DWRITE_FONT_STRETCH *>(pStretch),
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pStretch = nullptr;
            pRange = nullptr;

            return hr;
        }

        HRESULT IDWriteTextLayout::GetFontSize(
            UINT32 currentPosition,
            float %fontSize,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            pin_ptr<float> pSize = &fontSize;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetFontSize(
                currentPosition,
                reinterpret_cast<FLOAT *>(pSize),
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pSize = nullptr;
            pRange = nullptr;

            return hr;
        }

        HRESULT IDWriteTextLayout::GetUnderline(
            UINT32 currentPosition,
            bool %hasUnderline,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            BOOL underline = FALSE;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetUnderline(
                currentPosition,
                &underline,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            hasUnderline = System::Convert::ToBoolean(underline);

            return hr;
        }

        HRESULT IDWriteTextLayout::GetStrikethrough(
            UINT32 currentPosition,
            bool %hasStrikethrough,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            BOOL strikeThrough = FALSE;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetStrikethrough(
                currentPosition,
                &strikeThrough,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            hasStrikethrough = System::Convert::ToBoolean(strikeThrough);

            return hr;
        }

        HRESULT IDWriteTextLayout::GetDrawingEffect(
            UINT32 currentPosition,
            D2DNet::IUnknown ^%drawingEffect,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            ::IUnknown *pEffect = __nullptr;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetDrawingEffect(
                currentPosition,
                &pEffect,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            if(FAILED(hr) || !pEffect)
                drawingEffect = nullptr;
            else
                drawingEffect = gcnew D2DNet::ComObjectHandle(pEffect);

            if(pEffect)
                pEffect->Release();

            return hr;
        }

        HRESULT IDWriteTextLayout::GetInlineObject(
            UINT32 currentPosition,
            DWriteNet::IDWriteInlineObject ^%inlineObject,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            ::IDWriteInlineObject *pObject = __nullptr;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetInlineObject(
                currentPosition,
                &pObject,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            if(FAILED(hr) || !pObject)
                inlineObject = nullptr;
            else
            {
                System::IntPtr intptr(pObject);
                if(!DWriteNet::IDWriteInlineObject::objList->ContainsKey(intptr))
                {
                    inlineObject = nullptr;
                    return E_FAIL;
                }

                inlineObject = DWriteNet::IDWriteInlineObject::objList[intptr];
            }

            return hr;
        }

        HRESULT IDWriteTextLayout::GetTypography(
            UINT32 currentPosition,
            DWriteNet::IDWriteTypography ^%typography,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            ::IDWriteTypography *pTypo = __nullptr;
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetTypography(
                currentPosition,
                &pTypo,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            if(FAILED(hr) || !pTypo)
                typography = nullptr;
            else
                typography = gcnew DWriteNet::IDWriteTypography(pTypo);

            return hr;
        }

        HRESULT IDWriteTextLayout::GetLocaleName(
            UINT32 currentPosition,
            System::String ^%localeName,
            DWriteNet::DWRITE_TEXT_RANGE %textRange)
        {
            UINT32 length = 0;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetLocaleNameLength(
                currentPosition,
                &length
            );

            if(FAILED(hr))
            {
                localeName = nullptr;
                return hr;
            }

            length += 1;
            std::vector<WCHAR> name(length);
            pin_ptr<DWriteNet::DWRITE_TEXT_RANGE> pRange = &textRange;
            hr = ((::IDWriteTextLayout *)m_pFormat)->GetLocaleName(
                currentPosition,
                name.data(),
                length,
                reinterpret_cast<::DWRITE_TEXT_RANGE *>(pRange)
            );
            pRange = nullptr;

            if(FAILED(hr))
                localeName = nullptr;
            else
                localeName = marshal_as<System::String ^>(name.data());

            return hr;
        }

        HRESULT IDWriteTextLayout::GetLineMetrics(array<DWriteNet::DWRITE_LINE_METRICS> ^%lineMetrics)
        {
            UINT32 lineCount = 0;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetLineMetrics(__nullptr, 0, &lineCount);
            if(SUCCEEDED(hr))
            {
                lineMetrics = gcnew array<DWriteNet::DWRITE_LINE_METRICS>(0);
                return hr;
            }

            lineMetrics = gcnew array<DWriteNet::DWRITE_LINE_METRICS>(lineCount);

            pin_ptr<DWriteNet::DWRITE_LINE_METRICS> pMetrics = &lineMetrics[0];
            hr = ((::IDWriteTextLayout *)m_pFormat)->GetLineMetrics(
                reinterpret_cast<::DWRITE_LINE_METRICS *>(pMetrics),
                lineMetrics->Length,
                &lineCount
            );

            if(FAILED(hr))
            {
                delete lineMetrics;
                lineMetrics = nullptr;
            }

            return hr;
        }

        HRESULT IDWriteTextLayout::GetMetrics(DWriteNet::DWRITE_TEXT_METRICS %textMetrics)
        {
            pin_ptr<DWriteNet::DWRITE_TEXT_METRICS> pMetrics = &textMetrics;
            return ((::IDWriteTextLayout *)m_pFormat)->GetMetrics(
                reinterpret_cast<::DWRITE_TEXT_METRICS *>(pMetrics)
            );
        }

        HRESULT IDWriteTextLayout::GetOverhangMetrics(DWriteNet::DWRITE_OVERHANG_METRICS %textMetrics)
        {
            pin_ptr<DWriteNet::DWRITE_OVERHANG_METRICS> pMetrics = &textMetrics;
            return ((::IDWriteTextLayout *)m_pFormat)->GetOverhangMetrics(
                reinterpret_cast<::DWRITE_OVERHANG_METRICS *>(pMetrics)
            );
        }

        HRESULT IDWriteTextLayout::GetClusterMetrics(
            array<DWriteNet::DWRITE_CLUSTER_METRICS> ^%clusterMetrics)
        {
            UINT32 clusterCount = 0;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->GetClusterMetrics(__nullptr, 0, &clusterCount);
            if(SUCCEEDED(hr))
            {
                clusterMetrics = gcnew array<DWriteNet::DWRITE_CLUSTER_METRICS>(0);
                return hr;
            }

            clusterMetrics = gcnew array<DWriteNet::DWRITE_CLUSTER_METRICS>(clusterCount);

            pin_ptr<DWriteNet::DWRITE_CLUSTER_METRICS> pMetrics = &clusterMetrics[0];
            hr = ((::IDWriteTextLayout *)m_pFormat)->GetClusterMetrics(
                reinterpret_cast<::DWRITE_CLUSTER_METRICS *>(pMetrics),
                clusterMetrics->Length,
                &clusterCount
            );

            if(FAILED(hr))
            {
                delete clusterMetrics;
                clusterMetrics = nullptr;
            }

            return hr;
        }

        HRESULT IDWriteTextLayout::DetermineMinWidth(float %minWidth)
        {
            pin_ptr<float> pWidth = &minWidth;
            return ((::IDWriteTextLayout *)m_pFormat)->DetermineMinWidth(
                reinterpret_cast<FLOAT *>(pWidth)
            );
        }

        HRESULT IDWriteTextLayout::HitTestPoint(
            float pointX,
            float pointY,
            bool %isTrailingHit,
            bool %isInside,
            DWriteNet::DWRITE_HIT_TEST_METRICS %hitTestMetrics)
        {
            BOOL tHit = FALSE;
            BOOL inside = FALSE;
            pin_ptr<DWriteNet::DWRITE_HIT_TEST_METRICS> pMetrics = &hitTestMetrics;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->HitTestPoint(
                pointX,
                pointY,
                &tHit,
                &inside,
                reinterpret_cast<::DWRITE_HIT_TEST_METRICS *>(pMetrics)
            );
            pMetrics = nullptr;

            isTrailingHit = System::Convert::ToBoolean(tHit);
            isInside = System::Convert::ToBoolean(inside);

            return hr;
        }

        HRESULT IDWriteTextLayout::HitTestTextPosition(
            UINT32 textPosition,
            bool isTrailingHit,
            float %pointX,
            float %pointY,
            DWriteNet::DWRITE_HIT_TEST_METRICS %hitTestMetrics)
        {
            pin_ptr<float> pPointX = &pointX;
            pin_ptr<float> pPointY = &pointY;
            pin_ptr<DWriteNet::DWRITE_HIT_TEST_METRICS> pMetrics = &hitTestMetrics;

            return ((::IDWriteTextLayout *)m_pFormat)->HitTestTextPosition(
                textPosition,
                System::Convert::ToInt32(isTrailingHit),
                reinterpret_cast<FLOAT *>(pPointX),
                reinterpret_cast<FLOAT *>(pPointY),
                reinterpret_cast<::DWRITE_HIT_TEST_METRICS *>(pMetrics)
            );
        }

        HRESULT IDWriteTextLayout::HitTestTextRange(
            UINT32 textPosition,
            UINT32 textLength,
            FLOAT originX,
            FLOAT originY,
            array<DWriteNet::DWRITE_HIT_TEST_METRICS> ^%hitTestMetrics)
        {
            UINT32 metricsCount = 0;
            HRESULT hr = ((::IDWriteTextLayout *)m_pFormat)->HitTestTextRange(
                textPosition,
                textLength,
                originX,
                originY,
                __nullptr,
                0,
                &metricsCount
            );
            if(SUCCEEDED(hr))
            {
                hitTestMetrics = gcnew array<DWriteNet::DWRITE_HIT_TEST_METRICS>(0);
                return hr;
            }

            hitTestMetrics = gcnew array<DWriteNet::DWRITE_HIT_TEST_METRICS>(metricsCount);

            pin_ptr<DWriteNet::DWRITE_HIT_TEST_METRICS> pMetrics = &hitTestMetrics[0];
            hr = ((::IDWriteTextLayout *)m_pFormat)->HitTestTextRange(
                textPosition,
                textLength,
                originX,
                originY,
                reinterpret_cast<::DWRITE_HIT_TEST_METRICS *>(pMetrics),
                hitTestMetrics->Length,
                &metricsCount
            );

            if(FAILED(hr))
            {
                delete hitTestMetrics;
                hitTestMetrics = nullptr;
            }

            return hr;
        }

    }
}