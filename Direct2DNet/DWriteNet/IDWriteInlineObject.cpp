#include "IDWriteInlineObject.h"
#include "IDWriteFactory.h"
#include "IDWriteTextFormat.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteInlineObject::IDWriteInlineObject(::IDWriteInlineObject *pObject)
            : m_pObject(pObject)
        {

        }

        IDWriteInlineObject::IDWriteInlineObject()
        {
            FnMet ^getMetrics =
                gcnew FnMet(this, &DWriteNet::IDWriteInlineObject::GetMetricsInternal);
            FnOhMet ^getOverhangMetrics =
                gcnew FnOhMet(this, &DWriteNet::IDWriteInlineObject::GetOverhangMetricsInternal);
            FnBC ^getBreakConditions =
                gcnew FnBC(this, &DWriteNet::IDWriteInlineObject::GetBreakConditionsInternal);

            m_getMetrics = GCHandle::Alloc(getMetrics);
            m_getOverhangMetrics = GCHandle::Alloc(getOverhangMetrics);
            m_getBreakConditions = GCHandle::Alloc(getBreakConditions);

            m_pObject = new DWriteNet::IDWriteNativeInlineObject();
            IDWriteNativeInlineObject *object = (IDWriteNativeInlineObject *)m_pObject;

            object->m_getMetrics =
                static_cast<fnMet>(Marshal::GetFunctionPointerForDelegate(getMetrics).ToPointer());
            object->m_getOverhangMetrics =
                static_cast<fnOhMet>(Marshal::GetFunctionPointerForDelegate(getOverhangMetrics).ToPointer());
            object->m_getBreakConditions =
                static_cast<fnBC>(Marshal::GetFunctionPointerForDelegate(getBreakConditions).ToPointer());

            DWriteNet::IDWriteInlineObject::objList->Add(System::IntPtr(m_pObject), this);
        }

        IDWriteInlineObject::~IDWriteInlineObject()
        {
            if(m_getMetrics.IsAllocated)
                m_getMetrics.Free();
            if(m_getOverhangMetrics.IsAllocated)
                m_getOverhangMetrics.Free();
            if(m_getBreakConditions.IsAllocated)
                m_getBreakConditions.Free();

            objList->Remove(System::IntPtr(m_pObject));

            this->!IDWriteInlineObject();
        }

        IDWriteInlineObject::!IDWriteInlineObject()
        {
            if(m_pObject)
            {
                m_pObject->Release();
                m_pObject = nullptr;
            }
        }

        void IDWriteInlineObject::HandleCOMInterface(void *obj)
        {
            throw gcnew System::NotSupportedException("It is not supported to change the internal object since it causes unexpected action.");
        }

        HRESULT IDWriteInlineObject::GetMetricsInternal(::DWRITE_INLINE_OBJECT_METRICS *metrics)
        {
            DWriteNet::DWRITE_INLINE_OBJECT_METRICS mMetrics;
            HRESULT hr = GetMetrics(mMetrics);
            *metrics = *(::DWRITE_INLINE_OBJECT_METRICS *)&mMetrics;
            return hr;
        }

        HRESULT IDWriteInlineObject::GetOverhangMetricsInternal(::DWRITE_OVERHANG_METRICS *overhangs)
        {
            DWriteNet::DWRITE_OVERHANG_METRICS mOverhangs;
            HRESULT hr = GetOverhangMetrics(mOverhangs);
            *overhangs = *(::DWRITE_OVERHANG_METRICS *)&mOverhangs;
            return hr;
        }

        HRESULT IDWriteInlineObject::GetBreakConditionsInternal(
            ::DWRITE_BREAK_CONDITION *breakConditionBefore,
            ::DWRITE_BREAK_CONDITION *breakConditionAfter)
        {
            DWriteNet::DWRITE_BREAK_CONDITION mBefore, mAfter;
            HRESULT hr = GetBreakConditions(mBefore, mAfter);
            *breakConditionBefore = (::DWRITE_BREAK_CONDITION)((int)mBefore);
            *breakConditionAfter = (::DWRITE_BREAK_CONDITION)((int)mAfter);
            return hr;
        }

        EllipsisInlineObject::EllipsisInlineObject(
            DWriteNet::IDWriteFactory ^factory,
            DWriteNet::IDWriteTextFormat ^format)
            : DWriteNet::IDWriteInlineObject(nullptr)
        {
            pin_ptr<::IDWriteInlineObject *> ppObject = &m_pObject;
            HRESULT hr = factory->m_pFactory->CreateEllipsisTrimmingSign(
                format->m_pFormat,
                (::IDWriteInlineObject **)ppObject
            );

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteInlineObject.", (int)hr);

            DWriteNet::IDWriteInlineObject::objList->Add(System::IntPtr(m_pObject), this);
        }

        HRESULT EllipsisInlineObject::GetMetrics(DWriteNet::DWRITE_INLINE_OBJECT_METRICS %metrics)
        {
            pin_ptr<DWriteNet::DWRITE_INLINE_OBJECT_METRICS> pMetrics = &metrics;
            return m_pObject->GetMetrics(
                reinterpret_cast<::DWRITE_INLINE_OBJECT_METRICS *>(pMetrics)
            );
        }

        HRESULT EllipsisInlineObject::GetOverhangMetrics(DWriteNet::DWRITE_OVERHANG_METRICS %overhangs)
        {
            pin_ptr<DWriteNet::DWRITE_OVERHANG_METRICS> pOverhangs = &overhangs;
            return m_pObject->GetOverhangMetrics(
                reinterpret_cast<::DWRITE_OVERHANG_METRICS *>(pOverhangs)
            );
        }

        HRESULT EllipsisInlineObject::GetBreakConditions(DWriteNet::DWRITE_BREAK_CONDITION %breakConditionBefore, DWriteNet::DWRITE_BREAK_CONDITION %breakConditionAfter)
        {
            ::DWRITE_BREAK_CONDITION before;
            ::DWRITE_BREAK_CONDITION after;

            HRESULT hr = m_pObject->GetBreakConditions(&before, &after);

            breakConditionBefore = (DWriteNet::DWRITE_BREAK_CONDITION)((int)before);
            breakConditionAfter = (DWriteNet::DWRITE_BREAK_CONDITION)((int)after);

            return hr;
        }

    }
}