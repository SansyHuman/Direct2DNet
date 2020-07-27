#include "IDWriteTextAnalysisSource.h"
#include "IDWriteNumberSubstitution.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteTextAnalysisSource::IDWriteTextAnalysisSource()
        {
            FnTxtPos ^getTextAtPosition =
                gcnew FnTxtPos(this, &DWriteNet::IDWriteTextAnalysisSource::GetTextAtPositionInternal);
            FnTxtPos ^getTextBeforePosition =
                gcnew FnTxtPos(this, &DWriteNet::IDWriteTextAnalysisSource::GetTextBeforePositionInternal);
            FnRdDir ^getParagraphReadingDirection =
                gcnew FnRdDir(this, &DWriteNet::IDWriteTextAnalysisSource::GetParagraphReadingDirectionInternal);
            FnLocale ^getLocaleName =
                gcnew FnLocale(this, &DWriteNet::IDWriteTextAnalysisSource::GetLocaleNameInternal);
            FnNumSub ^getNumberSubstitution =
                gcnew FnNumSub(this, &DWriteNet::IDWriteTextAnalysisSource::GetNumberSubstitutionInternal);

            m_getTextAtPosition = GCHandle::Alloc(getTextAtPosition);
            m_getTextBeforePosition = GCHandle::Alloc(getTextBeforePosition);
            m_getParagraphReadingDirection = GCHandle::Alloc(getParagraphReadingDirection);
            m_getLocaleName = GCHandle::Alloc(getLocaleName);
            m_getNumberSubstitution = GCHandle::Alloc(getNumberSubstitution);

            m_pSource = new IDWriteNativeTextAnalysisSource();
            IDWriteNativeTextAnalysisSource *source = (IDWriteNativeTextAnalysisSource *)m_pSource;

            source->m_getTextAtPosition =
                static_cast<fnTxtPos>(Marshal::GetFunctionPointerForDelegate(getTextAtPosition).ToPointer());
            source->m_getTextBeforePosition =
                static_cast<fnTxtPos>(Marshal::GetFunctionPointerForDelegate(getTextBeforePosition).ToPointer());
            source->m_getParagraphReadingDirection =
                static_cast<fnRdDir>(Marshal::GetFunctionPointerForDelegate(getParagraphReadingDirection).ToPointer());
            source->m_getLocaleName =
                static_cast<fnLocale>(Marshal::GetFunctionPointerForDelegate(getLocaleName).ToPointer());
            source->m_getNumberSubstitiution =
                static_cast<fnNumSub>(Marshal::GetFunctionPointerForDelegate(getNumberSubstitution).ToPointer());
        }

        IDWriteTextAnalysisSource::~IDWriteTextAnalysisSource()
        {
            if(m_getTextAtPosition.IsAllocated)
                m_getTextAtPosition.Free();
            if(m_getTextBeforePosition.IsAllocated)
                m_getTextBeforePosition.Free();
            if(m_getParagraphReadingDirection.IsAllocated)
                m_getParagraphReadingDirection.Free();
            if(m_getLocaleName.IsAllocated)
                m_getLocaleName.Free();
            if(m_getNumberSubstitution.IsAllocated)
                m_getNumberSubstitution.Free();

            this->!IDWriteTextAnalysisSource();
        }

        IDWriteTextAnalysisSource::!IDWriteTextAnalysisSource()
        {
            if(m_pSource)
            {
                m_pSource->Release();
                m_pSource = nullptr;
            }
        }

        void IDWriteTextAnalysisSource::HandleCOMInterface(void *obj)
        {
            throw gcnew System::NotSupportedException("It is not supported to change the internal source since it causes unexpected action.");
        }

        HRESULT IDWriteTextAnalysisSource::GetTextAtPositionInternal(
            UINT32 textPosition,
            WCHAR const **textString,
            UINT32 *textLength)
        {
            WCHAR *text = __nullptr;
            UINT32 length = 0;

            HRESULT hr = GetTextAtPosition(textPosition, text, length);

            *textString = text;
            *textLength = length;

            return hr;
        }

        HRESULT IDWriteTextAnalysisSource::GetTextBeforePositionInternal(
            UINT32 textPosition,
            WCHAR const **textString,
            UINT32 *textLength)
        {
            WCHAR *text = __nullptr;
            UINT32 length = 0;

            HRESULT hr = GetTextBeforePosition(textPosition, text, length);

            *textString = text;
            *textLength = length;

            return hr;
        }

        ::DWRITE_READING_DIRECTION IDWriteTextAnalysisSource::GetParagraphReadingDirectionInternal()
        {
            return (::DWRITE_READING_DIRECTION)((int)GetParagraphReadingDirection());
        }

        HRESULT IDWriteTextAnalysisSource::GetLocaleNameInternal(
            UINT32 textPosition,
            UINT32 *textLength,
            WCHAR const **localeName)
        {
            UINT32 length = 0;
            WCHAR *locale = __nullptr;

            HRESULT hr = GetLocaleName(textPosition, length, locale);

            *textLength = length;
            *localeName = locale;

            return hr;
        }

        HRESULT IDWriteTextAnalysisSource::GetNumberSubstitutionInternal(
            UINT32 textPosition,
            UINT32 *textLength,
            ::IDWriteNumberSubstitution **numberSubstitution)
        {
            UINT32 length = 0;
            DWriteNet::IDWriteNumberSubstitution ^subs = nullptr;

            HRESULT hr = GetNumberSubstitution(textPosition, length, subs);

            *textLength = length;            
            if(SUCCEEDED(hr))
            {
                *numberSubstitution = subs->m_pSub;
                subs->m_pSub->AddRef();
            }
            else
            {
                *numberSubstitution = __nullptr;
            }

            return hr;
        }

    }
}