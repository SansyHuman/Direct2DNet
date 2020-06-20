#include "ID2D1CommandSink1.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1CommandSink1::ID2D1CommandSink1()
            : Direct2DNet::ID2D1CommandSink1(D2DNetGUID::UID_ID2D1CommandSink1)
        {
            
        }

        ID2D1CommandSink1::ID2D1CommandSink1(System::Guid riid) : Direct2DNet::ID2D1CommandSink(riid)
        {
            FnHrPB ^setPrimitiveBlend1 =
                gcnew FnHrPB(this, &Direct2DNet::ID2D1CommandSink1::SetPrimitiveBlend1Internal);

            m_setPrimitiveBlend1 = GCHandle::Alloc(setPrimitiveBlend1);

            Direct2DNet::ID2D1NativeCommandSink1 *sink = (Direct2DNet::ID2D1NativeCommandSink1 *)m_pSink;
            sink->m_setPrimitiveBlend1 =
                static_cast<fnHrPB>(Marshal::GetFunctionPointerForDelegate(setPrimitiveBlend1).ToPointer());
        }

        ID2D1CommandSink1::~ID2D1CommandSink1()
        {
            if(m_setPrimitiveBlend1.IsAllocated)
                m_setPrimitiveBlend1.Free();
        }

        HRESULT ID2D1CommandSink1::SetPrimitiveBlend1Internal(::D2D1_PRIMITIVE_BLEND primitiveBlend)
        {
            return SetPrimitiveBlend1((Direct2DNet::D2D1_PRIMITIVE_BLEND)(int)primitiveBlend);
        }

    }
}