#include "IWICBitmapSource.h"
#include "IWICPalette.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace WICNet
    {
        IWICBitmapSource::~IWICBitmapSource()
        {
            this->!IWICBitmapSource();
        }

        IWICBitmapSource::!IWICBitmapSource()
        {
            if(m_pSource)
            {
                m_pSource->Release();
                m_pSource = nullptr;
            }
        }

        void IWICBitmapSource::HandleCOMInterface(void *obj)
        {
            if(m_pSource)
            {
                m_pSource->Release();
            }

            m_pSource = (::IWICBitmapSource *)obj;
            m_pSource->AddRef();
        }

        HRESULT IWICBitmapSource::GetSize(UINT %width, UINT %height)
        {
            UINT w = 0, h = 0;
            HRESULT hr = m_pSource->GetSize(&w, &h);

            width = w;
            height = h;
            return hr;
        }

        System::ValueTuple<HRESULT, UINT, UINT> IWICBitmapSource::GetSize()
        {
            UINT w = 0, h = 0;
            HRESULT hr = m_pSource->GetSize(&w, &h);

            return System::ValueTuple<HRESULT, UINT, UINT>(hr, w, h);
        }

        HRESULT IWICBitmapSource::GetPixelFormat(System::Guid %pixelFormat)
        {
            ::GUID format = { 0 };
            HRESULT hr = m_pSource->GetPixelFormat(&format);

            pixelFormat = DirectX::ToManagedGUID(format);
            return hr;
        }

        HRESULT IWICBitmapSource::GetResolution(double %dpiX, double %dpiY)
        {
            double x = 0, y = 0;
            HRESULT hr = m_pSource->GetResolution(&x, &y);

            dpiX = x;
            dpiY = y;
            return hr;
        }

        System::ValueTuple<HRESULT, double, double> IWICBitmapSource::GetResolution()
        {
            double x = 0, y = 0;
            HRESULT hr = m_pSource->GetResolution(&x, &y);

            return System::ValueTuple<HRESULT, double, double>(hr, x, y);
        }

        HRESULT IWICBitmapSource::CopyPalette(WICNet::IWICPalette ^palette)
        {
            return m_pSource->CopyPalette(palette->m_pPalette);
        }

        HRESULT IWICBitmapSource::CopyPixels(
            UINT cbStride,
            array<BYTE> ^buffer,
            System::Nullable<WICNet::WICRect> rc)
        {
            UINT cbBufferSize = buffer->Length;
            if(cbBufferSize == 0)
                return E_INVALIDARG;

            pin_ptr<BYTE> pBuffer = &buffer[0];
            return m_pSource->CopyPixels(
                rc.HasValue ? (::WICRect *)&rc.Value : __nullptr,
                cbStride,
                cbBufferSize,
                (BYTE *)pBuffer
            );
        }

    }
}