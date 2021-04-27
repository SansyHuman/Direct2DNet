#include "ID2D1Factory1.h"
#include "../DXGINet/IDXGIDevice.h"
#include "ID2D1Device.h"
#include "ID2D1StrokeStyle1.h"
#include "ID2D1PathGeometry1.h"
#include "ID2D1DrawingStateBlock1.h"
#include "ID2D1GdiMetafile.h"
#include "../ComIO/IStream.h"
#include "ID2D1Properties.h"
#include "../GUIDs.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Factory1::ID2D1Factory1(::ID2D1Factory1 *pFactory) : Direct2DNet::ID2D1Factory(pFactory)
        {
            
        }

        ID2D1Factory1::ID2D1Factory1(Direct2DNet::D2D1_FACTORY_TYPE type, System::Guid guid)
            : Direct2DNet::ID2D1Factory(type, guid)
        {
            
        }

        ID2D1Factory1::ID2D1Factory1(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            Direct2DNet::D2D1_FACTORY_OPTIONS %options,
            System::Guid guid)
            : Direct2DNet::ID2D1Factory(type, options, guid)
        {
            
        }

        ID2D1Factory1::ID2D1Factory1(Direct2DNet::D2D1_FACTORY_TYPE type)
            : Direct2DNet::ID2D1Factory(type, D2DNet::D2DNetGUID::UID_ID2D1Factory1)
        {
            
        }

        ID2D1Factory1::ID2D1Factory1(
            Direct2DNet::D2D1_FACTORY_TYPE type,
            Direct2DNet::D2D1_FACTORY_OPTIONS %options)
            : Direct2DNet::ID2D1Factory(type, options, D2DNet::D2DNetGUID::UID_ID2D1Factory1)
        {
            
        }

        Direct2DNet::ID2D1Device ^ID2D1Factory1::CreateDevice(DXGINet::IDXGIDevice ^dxgiDevice)
        {
            return gcnew Direct2DNet::ID2D1Device(this, dxgiDevice);
        }

        Direct2DNet::ID2D1StrokeStyle1 ^ID2D1Factory1::CreateStrokeStyle(
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 %properties,
            array<float> ^dashes)
        {
            if(properties.dashStyle == Direct2DNet::D2D1_DASH_STYLE::CUSTOM
                && (dashes == nullptr || dashes->Length <= 0))
                throw gcnew Direct2DNet::Exception::DxException(
                    "Failed to create stroke style. You set the custom dash style, but the dash array is null or has length zero.",
                    E_INVALIDARG);

            return gcnew Direct2DNet::ID2D1StrokeStyle1(this, properties, dashes);
        }

        Direct2DNet::ID2D1PathGeometry1 ^ID2D1Factory1::CreatePathGeometry1()
        {
            return gcnew Direct2DNet::ID2D1PathGeometry1(this);
        }

        Direct2DNet::ID2D1DrawingStateBlock1 ^ID2D1Factory1::CreateDrawingStateBlock(
            System::Nullable<Direct2DNet::D2D1_DRAWING_STATE_DESCRIPTION1> description,
            DWriteNet::IDWriteRenderingParams ^params)
        {
            return gcnew Direct2DNet::ID2D1DrawingStateBlock1(
                this,
                description,
                params
            );
        }

        Direct2DNet::ID2D1GdiMetafile ^ID2D1Factory1::CreateGdiMetafile(ComIO::IStream ^metafileStream)
        {
            return gcnew Direct2DNet::ID2D1GdiMetafile(this, metafileStream);
        }

        HRESULT ID2D1Factory1::GetRegisteredEffects(
            array<System::Guid> ^effects,
            UINT32 %effectsReturned,
            UINT32 %effectsRegistered)
        {
            if(!effects || effects->Length == 0)
            {
                UINT32 returned = 0, registered = 0;
                HRESULT hr = ((::ID2D1Factory1 *)m_pFactory)->GetRegisteredEffects(
                    __nullptr, 0, &returned, &registered
                );
                effectsReturned = returned;
                effectsRegistered = registered;
                return hr;
            }

            UINT32 effectsCount = effects->Length;
            UINT32 returned = 0, registered = 0;
            pin_ptr<System::Guid> pEffects = &effects[0];
            HRESULT hr = ((::ID2D1Factory1 *)m_pFactory)->GetRegisteredEffects(
                (::CLSID *)pEffects, effectsCount, &returned, &registered
            );
            pEffects = nullptr;

            effectsReturned = returned;
            effectsRegistered = registered;
            return hr;
        }

        HRESULT ID2D1Factory1::GetEffectProperties(
            System::Guid %effectId,
            Direct2DNet::ID2D1Properties ^%properties)
        {
            ::ID2D1Properties *pProperties = __nullptr;

            HRESULT hr = ((::ID2D1Factory1 *)m_pFactory)->GetEffectProperties(
                DirectX::ToNativeGUID(effectId),
                &pProperties
            );

            if(FAILED(hr))
            {
                properties = nullptr;
                return hr;
            }

            properties = gcnew Direct2DNet::ID2D1Properties(pProperties);
            return hr;
        }

        System::ValueTuple<HRESULT, Direct2DNet::ID2D1Properties ^> ID2D1Factory1::GetEffectProperties(
            System::Guid %effectId)
        {
            ::ID2D1Properties *pProperties = __nullptr;

            HRESULT hr = ((::ID2D1Factory1 *)m_pFactory)->GetEffectProperties(
                DirectX::ToNativeGUID(effectId),
                &pProperties
            );

            if(FAILED(hr))
            {
                return System::ValueTuple<HRESULT, Direct2DNet::ID2D1Properties ^>(hr, nullptr);
            }

            return System::ValueTuple<HRESULT, Direct2DNet::ID2D1Properties ^>(
                hr,
                gcnew Direct2DNet::ID2D1Properties(pProperties)
                );
        }

    }
}