#include "IDWriteTextAnalysisSink.h"
#include "IDWriteNumberSubstitution.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteTextAnalysisSink::IDWriteTextAnalysisSink()
        {
            FnScAnal ^setScriptAnalysis =
                gcnew FnScAnal(this, &DWriteNet::IDWriteTextAnalysisSink::SetScriptAnalysisInternal);
            FnLnBp ^setLineBreakpoints =
                gcnew FnLnBp(this, &DWriteNet::IDWriteTextAnalysisSink::SetLineBreakpointsInternal);
            FnBdLvl ^setBidiLevel =
                gcnew FnBdLvl(this, &DWriteNet::IDWriteTextAnalysisSink::SetBidiLevelInternal);
            FnNumSubSet ^setNumberSubstitution =
                gcnew FnNumSubSet(this, &DWriteNet::IDWriteTextAnalysisSink::SetNumberSubstitutionInternal);

            m_setScriptAnalysis = GCHandle::Alloc(setScriptAnalysis);
            m_setLineBreakpoints = GCHandle::Alloc(setLineBreakpoints);
            m_setBidiLevel = GCHandle::Alloc(setBidiLevel);
            m_setNumberSubstitution = GCHandle::Alloc(setNumberSubstitution);

            m_pSink = new IDWriteNativeTextAnalysisSink();
            IDWriteNativeTextAnalysisSink *sink = (IDWriteNativeTextAnalysisSink *)m_pSink;

            sink->m_setScriptAnalysis =
                static_cast<fnScAnal>(Marshal::GetFunctionPointerForDelegate(setScriptAnalysis).ToPointer());
            sink->m_setLineBreakpoints =
                static_cast<fnLnBp>(Marshal::GetFunctionPointerForDelegate(setLineBreakpoints).ToPointer());
            sink->m_setBidiLevel =
                static_cast<fnBdLvl>(Marshal::GetFunctionPointerForDelegate(setBidiLevel).ToPointer());
            sink->m_setNumberSubstitution =
                static_cast<fnNumSubSet>(Marshal::GetFunctionPointerForDelegate(setNumberSubstitution).ToPointer());
        }

        IDWriteTextAnalysisSink::~IDWriteTextAnalysisSink()
        {
            if(m_setScriptAnalysis.IsAllocated)
                m_setScriptAnalysis.Free();
            if(m_setLineBreakpoints.IsAllocated)
                m_setLineBreakpoints.Free();
            if(m_setBidiLevel.IsAllocated)
                m_setBidiLevel.Free();
            if(m_setNumberSubstitution.IsAllocated)
                m_setNumberSubstitution.Free();

            this->!IDWriteTextAnalysisSink();
        }

        IDWriteTextAnalysisSink::!IDWriteTextAnalysisSink()
        {
            if(m_pSink)
            {
                m_pSink->Release();
                m_pSink = nullptr;
            }
        }

        void IDWriteTextAnalysisSink::HandleCOMInterface(void *obj)
        {
            throw gcnew System::NotSupportedException("It is not supported to change the internal sink since it causes unexpected action.");
        }

        HRESULT IDWriteTextAnalysisSink::SetScriptAnalysisInternal(
            UINT32 textPosition,
            UINT32 textLength,
            ::DWRITE_SCRIPT_ANALYSIS const *scriptAnalysis)
        {
            DWriteNet::DWRITE_SCRIPT_ANALYSIS analysis;
            analysis.script = scriptAnalysis->script;
            analysis.shapes = (DWriteNet::DWRITE_SCRIPT_SHAPES)((int)scriptAnalysis->shapes);

            return SetScriptAnalysis(textPosition, textLength, analysis);
        }

        HRESULT IDWriteTextAnalysisSink::SetLineBreakpointsInternal(
            UINT32 textPosition,
            UINT32 textLength,
            ::DWRITE_LINE_BREAKPOINT const *lineBreakpoints)
        {
            return SetLineBreakpoints(
                textPosition,
                textLength,
                reinterpret_cast<DWriteNet::DWRITE_LINE_BREAKPOINT *>(
                    const_cast<::DWRITE_LINE_BREAKPOINT *>(lineBreakpoints))
            );
        }

        HRESULT IDWriteTextAnalysisSink::SetBidiLevelInternal(
            UINT32 textPosition,
            UINT32 textLength,
            UINT8 explicitLevel,
            UINT8 resolvedLevel)
        {
            return SetBidiLevel(textPosition, textLength, explicitLevel, resolvedLevel);
        }

        HRESULT IDWriteTextAnalysisSink::SetNumberSubstitutionInternal(
            UINT32 textPosition,
            UINT32 textLength,
            ::IDWriteNumberSubstitution *numberSubstitution)
        {
            DWriteNet::IDWriteNumberSubstitution ^sub = gcnew DWriteNet::IDWriteNumberSubstitution();
            sub->HandleCOMInterface(numberSubstitution);

            return SetNumberSubstitution(textPosition, textLength, sub);
        }

    }
}