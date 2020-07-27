#include "ID2D1StrokeStyle.h"
#include "ID2D1Factory.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1StrokeStyle::ID2D1StrokeStyle(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES %properties,
            array<float> ^dashes
        ) : Direct2DNet::ID2D1Resource(factory), m_properties(properties)
        {
            HRESULT hr = S_OK;
            pin_ptr<Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES> pProperties = &properties;
            pin_ptr<float> pDashes = dashes == nullptr ? nullptr : &dashes[0];
            pin_ptr<::ID2D1Resource *> ppResource = &m_pResource;
            hr = factory->m_pFactory->CreateStrokeStyle(
                reinterpret_cast<::D2D1_STROKE_STYLE_PROPERTIES *>(pProperties),
                (float *)pDashes,
                dashes == nullptr ? 0 : dashes->Length,
                (::ID2D1StrokeStyle **)ppResource
            );
            pProperties = nullptr;
            pDashes = nullptr;
            ppResource = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create ID2D1StrokeStyle", (int)hr);

            if(dashes == nullptr)
            {
                m_dashes = nullptr;
            }
            else
            {
                m_dashes = gcnew array<float>(dashes->Length);
                dashes->CopyTo(m_dashes, 0);
            }
        }

        ID2D1StrokeStyle::ID2D1StrokeStyle(Direct2DNet::ID2D1Factory ^factory, ::ID2D1StrokeStyle *pStrokeStyle) : Direct2DNet::ID2D1Resource(factory)
        {
            m_pResource = pStrokeStyle;
            m_properties = Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES(
                (Direct2DNet::D2D1_CAP_STYLE)((int)pStrokeStyle->GetStartCap()),
                (Direct2DNet::D2D1_CAP_STYLE)((int)pStrokeStyle->GetEndCap()),
                (Direct2DNet::D2D1_CAP_STYLE)((int)pStrokeStyle->GetDashCap()),
                (Direct2DNet::D2D1_LINE_JOIN)((int)pStrokeStyle->GetLineJoin()),
                pStrokeStyle->GetMiterLimit(),
                (Direct2DNet::D2D1_DASH_STYLE)((int)pStrokeStyle->GetDashStyle()),
                pStrokeStyle->GetDashOffset()
            );

            if(m_properties.dashStyle == Direct2DNet::D2D1_DASH_STYLE::CUSTOM)
            {
                UINT dashCnt = pStrokeStyle->GetDashesCount();

                if(dashCnt == 0)
                    m_dashes = nullptr;
                else
                {
                    m_dashes = gcnew array<float>(dashCnt);

                    pin_ptr<float> pDashes = &m_dashes[0];
                    pStrokeStyle->GetDashes((float *)pDashes, dashCnt);
                    pDashes = nullptr;
                }
            }
            else
            {
                m_dashes = nullptr;
            }
        }

        ID2D1StrokeStyle::ID2D1StrokeStyle(
            Direct2DNet::ID2D1Factory ^factory,
            Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES1 %properties,
            array<float> ^dashes
        ) : Direct2DNet::ID2D1Resource(factory)
        {
            if(dashes == nullptr)
            {
                m_dashes = nullptr;
            }
            else
            {
                m_dashes = gcnew array<float>(dashes->Length);
                dashes->CopyTo(m_dashes, 0);
            }

            m_properties = Direct2DNet::D2D1_STROKE_STYLE_PROPERTIES(
                properties.startCap,
                properties.endCap,
                properties.dashCap,
                properties.lineJoin,
                properties.miterLimit,
                properties.dashStyle,
                properties.dashOffset
            );
        }

        void ID2D1StrokeStyle::HandleCOMInterface(void *obj)
        {
            Direct2DNet::ID2D1Resource::HandleCOMInterface(obj);

            m_properties.startCap = (Direct2DNet::D2D1_CAP_STYLE)((int)((::ID2D1StrokeStyle *)m_pResource)->GetStartCap());
            m_properties.endCap = (Direct2DNet::D2D1_CAP_STYLE)((int)((::ID2D1StrokeStyle *)m_pResource)->GetEndCap());
            m_properties.dashCap = (Direct2DNet::D2D1_CAP_STYLE)((int)((::ID2D1StrokeStyle *)m_pResource)->GetDashCap());
            m_properties.miterLimit = ((::ID2D1StrokeStyle *)m_pResource)->GetMiterLimit();
            m_properties.lineJoin = (Direct2DNet::D2D1_LINE_JOIN)((int)((::ID2D1StrokeStyle *)m_pResource)->GetLineJoin());
            m_properties.dashOffset = ((::ID2D1StrokeStyle *)m_pResource)->GetDashOffset();
            m_properties.dashStyle = (Direct2DNet::D2D1_DASH_STYLE)((int)((::ID2D1StrokeStyle *)m_pResource)->GetDashStyle());
            UINT dashCnt = ((::ID2D1StrokeStyle *)m_pResource)->GetDashesCount();

            if(dashCnt == 0)
                m_dashes = nullptr;
            else
            {
                m_dashes = gcnew array<float>(dashCnt);

                pin_ptr<float> pDashes = &m_dashes[0];
                ((::ID2D1StrokeStyle *)m_pResource)->GetDashes((float *)pDashes, dashCnt);
                pDashes = nullptr;
            }
        }

    }
}