#include "ID2D1GdiMetafileSink.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1GdiMetafileSink::ID2D1GdiMetafileSink()
        {
            FnPrRec ^processRecord = gcnew FnPrRec(this, &Direct2DNet::ID2D1GdiMetafileSink::ProcessRecord);

            m_processRecord = GCHandle::Alloc(processRecord);

            m_pSink = new Direct2DNet::ID2D1NativeGdiMetafileSink();

            ((Direct2DNet::ID2D1NativeGdiMetafileSink *)m_pSink)->m_processRecord =
                static_cast<fnPrRec>(Marshal::GetFunctionPointerForDelegate(processRecord).ToPointer());
        }

        ID2D1GdiMetafileSink::~ID2D1GdiMetafileSink()
        {
            if(m_processRecord.IsAllocated)
            {
                m_processRecord.Free();
            }

            this->!ID2D1GdiMetafileSink();
        }

        ID2D1GdiMetafileSink::!ID2D1GdiMetafileSink()
        {
            if(m_pSink)
            {
                m_pSink->Release();
                m_pSink = nullptr;
            }
        }

        void ID2D1GdiMetafileSink::HandleCOMInterface(void *obj)
        {
            throw gcnew System::NotSupportedException("It is not supported to change the internal sink since it causes unexpected action.");
        }

    }
}