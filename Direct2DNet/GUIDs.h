#pragma once

#include "Direct2DNet/D2DNet_core.h"
#include "Direct2DNet/D2DNet_brush.h"
#include "Direct2DNet/D2DNet_geometry.h"
#include "Direct2DNet/D2DNet_image.h"

#include "Direct3D11Net/D3D11Net_core.h"

#include "DXGINet/DXGINet_core.h"

#include "DWriteNet/DWNet_core.h"
#include "DWriteNet/DWNet_font.h"
#include "DWriteNet/DWNet_glyph.h"
#include "DWriteNet/DWNet_text.h"

#include "DXCommonSettings.h"

namespace D2DNet
{
    using namespace System::Runtime::InteropServices;

#ifndef D2DNET_GUID
#define D2DNET_GUID(type) static initonly System::Guid UID_ ## type
#endif

#ifndef D2DNET_GET_GUID
#if defined(DEBUG) || defined(_DEBUG)
#define D2DNET_GET_GUID(namespace, type, attributeHolder) \
attributeHolder = (GuidAttribute ^)System::Attribute::GetCustomAttribute(namespace ## :: ## type ## ::typeid, GuidAttribute::typeid); \
UID_ ## type = System::Guid(attributeHolder->Value); \
if(UID_ ## type != D2DNet::DirectX::ToManagedGUID(__uuidof(:: ## type))) \
{ \
    throw gcnew System::Exception("Different Guid"); \
} \
uidTypePairs->Add(System::Guid(attributeHolder->Value), namespace ## :: ## type ## ::typeid);
#else
#define D2DNET_GET_GUID(namespace, type, attributeHolder) \
attributeHolder = (GuidAttribute ^)System::Attribute::GetCustomAttribute(namespace ## :: ## type ## ::typeid, GuidAttribute::typeid); \
UID_ ## type = System::Guid(attributeHolder->Value); \
uidTypePairs->Add(System::Guid(attributeHolder->Value), namespace ## :: ## type ## ::typeid);
#endif
#endif

    /// <summary>
    /// GUID holder of all D2DNet classes.
    /// </summary>
    public value struct D2DNetGUID abstract sealed
    {
    public:
        D2DNET_GUID(ID2D1BitmapRenderTarget);
        D2DNET_GUID(ID2D1CommandList);
        D2DNET_GUID(ID2D1CommandSink);
        D2DNET_GUID(ID2D1CommandSink1);
        D2DNET_GUID(ID2D1DCRenderTarget);
        D2DNET_GUID(ID2D1Device);
        D2DNET_GUID(ID2D1Device1);
        D2DNET_GUID(ID2D1DeviceContext);
        D2DNET_GUID(ID2D1DeviceContext1);
        D2DNET_GUID(ID2D1DrawingStateBlock);
        D2DNET_GUID(ID2D1DrawingStateBlock1);
        D2DNET_GUID(ID2D1Factory);
        D2DNET_GUID(ID2D1Factory1);
        D2DNET_GUID(ID2D1Factory2);
        D2DNET_GUID(ID2D1Factory3);
        D2DNET_GUID(ID2D1GdiInteropRenderTarget);
        D2DNET_GUID(ID2D1HwndRenderTarget);
        D2DNET_GUID(ID2D1Layer);
        D2DNET_GUID(ID2D1Multithread);
        D2DNET_GUID(ID2D1RenderTarget);
        D2DNET_GUID(ID2D1Resource);

        D2DNET_GUID(ID2D1BitmapBrush);
        D2DNET_GUID(ID2D1BitmapBrush1);
        D2DNET_GUID(ID2D1Brush);
        D2DNET_GUID(ID2D1GradientStopCollection);
        D2DNET_GUID(ID2D1GradientStopCollection1);
        D2DNET_GUID(ID2D1ImageBrush);
        D2DNET_GUID(ID2D1LinearGradientBrush);
        D2DNET_GUID(ID2D1RadialGradientBrush);
        D2DNET_GUID(ID2D1SolidColorBrush);
        D2DNET_GUID(ID2D1StrokeStyle);
        D2DNET_GUID(ID2D1StrokeStyle1);

        D2DNET_GUID(ID2D1EllipseGeometry);
        D2DNET_GUID(ID2D1Geometry);
        D2DNET_GUID(ID2D1GeometryGroup);
        D2DNET_GUID(ID2D1GeometryRealization);
        D2DNET_GUID(ID2D1Mesh);
        D2DNET_GUID(ID2D1PathGeometry);
        D2DNET_GUID(ID2D1PathGeometry1);
        D2DNET_GUID(ID2D1RectangleGeometry);
        D2DNET_GUID(ID2D1RoundedRectangleGeometry);
        D2DNET_GUID(ID2D1TransformedGeometry);

        D2DNET_GUID(ID2D1Bitmap);
        D2DNET_GUID(ID2D1Bitmap1);
        D2DNET_GUID(ID2D1ColorContext);
        D2DNET_GUID(ID2D1Effect);
        D2DNET_GUID(ID2D1GdiMetafile);
        D2DNET_GUID(ID2D1GdiMetafileSink);
        D2DNET_GUID(ID2D1Image);
        D2DNET_GUID(ID2D1Properties);


        D2DNET_GUID(ID3D11Device);
        D2DNET_GUID(ID3D11DeviceChild);
        D2DNET_GUID(ID3D11DeviceContext);


        D2DNET_GUID(IDXGIAdapter);
        D2DNET_GUID(IDXGIDevice);
        D2DNET_GUID(IDXGIDeviceSubObject);
        D2DNET_GUID(IDXGIFactory);
        D2DNET_GUID(IDXGIObject);
        D2DNET_GUID(IDXGISurface);
        D2DNET_GUID(IDXGISwapChain);


        D2DNET_GUID(IDWriteBitmapRenderTarget);
        D2DNET_GUID(IDWriteFactory);
        D2DNET_GUID(IDWriteGdiInterop);
        D2DNET_GUID(IDWriteLocalizedStrings);
        D2DNET_GUID(IDWriteRenderingParams);        

        D2DNET_GUID(IDWriteFont);
        D2DNET_GUID(IDWriteFontCollection);
        D2DNET_GUID(IDWriteFontFace);
        D2DNET_GUID(IDWriteFontFamily);
        D2DNET_GUID(IDWriteFontFile);
        D2DNET_GUID(IDWriteFontList);
        D2DNET_GUID(IDWriteTypography);

        D2DNET_GUID(IDWriteGlyphRunAnalysis);

        D2DNET_GUID(IDWriteInlineObject);
        D2DNET_GUID(IDWriteNumberSubstitution);
        D2DNET_GUID(IDWriteTextAnalysisSink);
        D2DNET_GUID(IDWriteTextAnalysisSource);
        D2DNET_GUID(IDWriteTextAnalyzer);
        D2DNET_GUID(IDWriteTextFormat);
        D2DNET_GUID(IDWriteTextLayout);

    internal:
        static System::Collections::Generic::Dictionary<System::Guid, System::Type ^> ^uidTypePairs;

    public:
        static D2DNetGUID()
        {
            uidTypePairs = gcnew System::Collections::Generic::Dictionary<System::Guid, System::Type ^>();

            GuidAttribute ^guid;

            D2DNET_GET_GUID(Direct2DNet, ID2D1BitmapRenderTarget, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1CommandList, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1CommandSink, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1CommandSink1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1DCRenderTarget, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Device, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Device1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1DeviceContext, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1DeviceContext1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1DrawingStateBlock, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1DrawingStateBlock1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Factory, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Factory1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Factory2, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Factory3, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1GdiInteropRenderTarget, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1HwndRenderTarget, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Layer, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Multithread, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1RenderTarget, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Resource, guid);

            D2DNET_GET_GUID(Direct2DNet, ID2D1BitmapBrush, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1BitmapBrush1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Brush, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1GradientStopCollection, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1GradientStopCollection1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1ImageBrush, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1LinearGradientBrush, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1RadialGradientBrush, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1SolidColorBrush, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1StrokeStyle, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1StrokeStyle1, guid);

            D2DNET_GET_GUID(Direct2DNet, ID2D1EllipseGeometry, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Geometry, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1GeometryGroup, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1GeometryRealization, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Mesh, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1PathGeometry, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1PathGeometry1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1RectangleGeometry, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1RoundedRectangleGeometry, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1TransformedGeometry, guid);

            D2DNET_GET_GUID(Direct2DNet, ID2D1Bitmap, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Bitmap1, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1ColorContext, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Effect, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1GdiMetafile, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1GdiMetafileSink, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Image, guid);
            D2DNET_GET_GUID(Direct2DNet, ID2D1Properties, guid);

            
            D2DNET_GET_GUID(Direct3D11Net, ID3D11Device, guid);
            D2DNET_GET_GUID(Direct3D11Net, ID3D11DeviceChild, guid);
            D2DNET_GET_GUID(Direct3D11Net, ID3D11DeviceContext, guid);


            D2DNET_GET_GUID(DXGINet, IDXGIAdapter, guid);
            D2DNET_GET_GUID(DXGINet, IDXGIDevice, guid);
            D2DNET_GET_GUID(DXGINet, IDXGIDeviceSubObject, guid);
            D2DNET_GET_GUID(DXGINet, IDXGIFactory, guid);
            D2DNET_GET_GUID(DXGINet, IDXGIObject, guid);
            D2DNET_GET_GUID(DXGINet, IDXGISurface, guid);
            D2DNET_GET_GUID(DXGINet, IDXGISwapChain, guid);


            D2DNET_GET_GUID(DWriteNet, IDWriteBitmapRenderTarget, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteFactory, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteGdiInterop, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteLocalizedStrings, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteRenderingParams, guid);          

            D2DNET_GET_GUID(DWriteNet, IDWriteFont, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteFontCollection, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteFontFace, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteFontFamily, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteFontFile, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteFontList, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteTypography, guid);

            D2DNET_GET_GUID(DWriteNet, IDWriteGlyphRunAnalysis, guid);

            D2DNET_GET_GUID(DWriteNet, IDWriteInlineObject, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteNumberSubstitution, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteTextAnalysisSink, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteTextAnalysisSource, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteTextAnalyzer, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteTextFormat, guid);
            D2DNET_GET_GUID(DWriteNet, IDWriteTextLayout, guid);
        }
    };
}