#include "ID2D1LookupTable3D.h"
#include "ID2D1DeviceContext2.h"

namespace D2DNet
{

namespace Direct2DNet
{

    namespace Effects
    {
        ID2D1LookupTable3D::ID2D1LookupTable3D(
            Direct2DNet::ID2D1DeviceContext2 ^context,
            Direct2DNet::D2D1_BUFFER_PRECISION precision,
            System::ValueTuple<UINT32, UINT32, UINT32> %extents,
            array<BYTE> ^data,
            System::ValueTuple<UINT32, UINT32> %strides)
            : Direct2DNet::ID2D1Resource(context->m_factory)
        {
            HRESULT hr = S_OK;

            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            UINT32 nExtents[] = { extents.Item1, extents.Item2, extents.Item3 };
            pin_ptr<BYTE> pData = &data[0];
            UINT32 nStrides[] = { strides.Item1, strides.Item2 };

            hr = ((::ID2D1DeviceContext2 *)context->m_pResource)->CreateLookupTable3D(
                (::D2D1_BUFFER_PRECISION)((int)precision),
                &nExtents[0],
                (BYTE *)pData,
                data->Length,
                &nStrides[0],
                (::ID2D1LookupTable3D **)ppResource
            );

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1LookupTable3D", (int)hr);
        }

    }
}
}