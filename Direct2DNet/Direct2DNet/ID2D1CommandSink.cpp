#include "ID2D1CommandSink.h"
#include "../DWriteNet/IDWriteRenderingParams.h"
#include "../DWriteNet/IDWriteFontFace.h"
#include "ID2D1Brush.h"
#include "ID2D1Factory.h"
#include "ID2D1StrokeStyle.h"
#include "ID2D1Geometry.h"
#include "ID2D1Bitmap.h"
#include "ID2D1Image.h"
#include "ID2D1GdiMetafile.h"
#include "ID2D1Mesh.h"
#include "ID2D1Layer.h"
#include "ID2D1CommandSink1.h"
#include "../GUIDs.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1CommandSink::ID2D1CommandSink() : Direct2DNet::ID2D1CommandSink(D2DNetGUID::UID_ID2D1CommandSink)
        {

        }

        ID2D1CommandSink::ID2D1CommandSink(System::Guid riid)
        {
            FnHrVoid ^beginDraw =
                gcnew FnHrVoid(this, &Direct2DNet::ID2D1CommandSink::BeginDrawInternal);
            FnHrVoid ^endDraw =
                gcnew FnHrVoid(this, &Direct2DNet::ID2D1CommandSink::EndDrawInternal);
            FnHrAntmode ^setAntialiasMode =
                gcnew FnHrAntmode(this, &Direct2DNet::ID2D1CommandSink::SetAntialiasModeInternal);
            FnHr2Tag ^setTags =
                gcnew FnHr2Tag(this, &Direct2DNet::ID2D1CommandSink::SetTagsInternal);
            FnHrTxtAntmode ^setTextAntialiasMode =
                gcnew FnHrTxtAntmode(this, &Direct2DNet::ID2D1CommandSink::SetTextAntialiasModeInternal);
            FnHrDWRP ^setTextRenderingParams =
                gcnew FnHrDWRP(this, &Direct2DNet::ID2D1CommandSink::SetTextRenderingParamsInternal);
            FnHrMat32 ^setTransform =
                gcnew FnHrMat32(this, &Direct2DNet::ID2D1CommandSink::SetTransformInternal);
            FnHrPB ^setPrimitiveBlend =
                gcnew FnHrPB(this, &Direct2DNet::ID2D1CommandSink::SetPrimitiveBlendInternal);
            FnHrUnit ^setUnitMode =
                gcnew FnHrUnit(this, &Direct2DNet::ID2D1CommandSink::SetUnitModeInternal);
            FnHrClr ^clear =
                gcnew FnHrClr(this, &Direct2DNet::ID2D1CommandSink::ClearInternal);
            FnGlyph ^drawGlyphRun =
                gcnew FnGlyph(this, &Direct2DNet::ID2D1CommandSink::DrawGlyphRunInternal);
            FnDrLine ^drawLine =
                gcnew FnDrLine(this, &Direct2DNet::ID2D1CommandSink::DrawLineInternal);
            FnDrGeo ^drawGeometry =
                gcnew FnDrGeo(this, &Direct2DNet::ID2D1CommandSink::DrawGeometryInternal);
            FnDrRect ^drawRectangle =
                gcnew FnDrRect(this, &Direct2DNet::ID2D1CommandSink::DrawRectangleInternal);
            FnDrBit ^drawBitmap =
                gcnew FnDrBit(this, &Direct2DNet::ID2D1CommandSink::DrawBitmapInternal);
            FnDrIm ^drawImage =
                gcnew FnDrIm(this, &Direct2DNet::ID2D1CommandSink::DrawImageInternal);
            FnDrGdi ^drawGdiMetafile =
                gcnew FnDrGdi(this, &Direct2DNet::ID2D1CommandSink::DrawGdiMetafileInternal);
            FnFllMesh ^fillMesh =
                gcnew FnFllMesh(this, &Direct2DNet::ID2D1CommandSink::FillMeshInternal);
            FnFllOpMsk ^fillOpacityMask =
                gcnew FnFllOpMsk(this, &Direct2DNet::ID2D1CommandSink::FillOpacityMaskInternal);
            FnFllGeo ^fillGeometry =
                gcnew FnFllGeo(this, &Direct2DNet::ID2D1CommandSink::FillGeometryInternal);
            FnFllRect ^fillRectangle =
                gcnew FnFllRect(this, &Direct2DNet::ID2D1CommandSink::FillRectangleInternal);
            FnPshAxis ^pushAxisAlignedClip =
                gcnew FnPshAxis(this, &Direct2DNet::ID2D1CommandSink::PushAxisAlignedClipInternal);
            FnPshLyr ^pushLayer =
                gcnew FnPshLyr(this, &Direct2DNet::ID2D1CommandSink::PushLayerInternal);
            FnHrVoid ^popAxisAlignedClip =
                gcnew FnHrVoid(this, &Direct2DNet::ID2D1CommandSink::PopAxisAlignedClipInternal);
            FnHrVoid ^popLayer =
                gcnew FnHrVoid(this, &Direct2DNet::ID2D1CommandSink::PopLayerInternal);

            m_beginDraw = GCHandle::Alloc(beginDraw);
            m_endDraw = GCHandle::Alloc(endDraw);
            m_setAntialiasMode = GCHandle::Alloc(setAntialiasMode);
            m_setTags = GCHandle::Alloc(setTags);
            m_setTextAntialiasMode = GCHandle::Alloc(setTextAntialiasMode);
            m_setTextRenderingParams = GCHandle::Alloc(setTextRenderingParams);
            m_setTransform = GCHandle::Alloc(setTransform);
            m_setPrimitiveBlend = GCHandle::Alloc(setPrimitiveBlend);
            m_setUnitMode = GCHandle::Alloc(setUnitMode);
            m_clear = GCHandle::Alloc(clear);
            m_drawGlyphRun = GCHandle::Alloc(drawGlyphRun);
            m_drawLine = GCHandle::Alloc(drawLine);
            m_drawGeometry = GCHandle::Alloc(drawGeometry);
            m_drawRectangle = GCHandle::Alloc(drawRectangle);
            m_drawBitmap = GCHandle::Alloc(drawBitmap);
            m_drawImage = GCHandle::Alloc(drawImage);
            m_drawGdiMetafile = GCHandle::Alloc(drawGdiMetafile);
            m_fillMesh = GCHandle::Alloc(fillMesh);
            m_fillOpacityMask = GCHandle::Alloc(fillOpacityMask);
            m_fillGeometry = GCHandle::Alloc(fillGeometry);
            m_fillRectangle = GCHandle::Alloc(fillRectangle);
            m_pushAxisAlignedClip = GCHandle::Alloc(pushAxisAlignedClip);
            m_pushLayer = GCHandle::Alloc(pushLayer);
            m_popAxisAlignedClip = GCHandle::Alloc(popAxisAlignedClip);
            m_popLayer = GCHandle::Alloc(popLayer);

            if(riid == D2DNetGUID::UID_ID2D1CommandSink)
            {
                m_pSink = new Direct2DNet::ID2D1NativeCommandSink();

                Direct2DNet::ID2D1NativeCommandSink *sink = (Direct2DNet::ID2D1NativeCommandSink *)m_pSink;

                sink->m_beginDraw =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(beginDraw).ToPointer());
                sink->m_endDraw =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(endDraw).ToPointer());
                sink->m_setAntialiasMode =
                    static_cast<fnHrAntmode>(Marshal::GetFunctionPointerForDelegate(setAntialiasMode).ToPointer());
                sink->m_setTags =
                    static_cast<fnHr2Tag>(Marshal::GetFunctionPointerForDelegate(setTags).ToPointer());
                sink->m_setTextAntialiasMode =
                    static_cast<fnHrTxtAntmode>(Marshal::GetFunctionPointerForDelegate(setTextAntialiasMode).ToPointer());
                sink->m_setTextRenderingParams =
                    static_cast<fnHrDWRP>(Marshal::GetFunctionPointerForDelegate(setTextRenderingParams).ToPointer());
                sink->m_setTransform =
                    static_cast<fnHrMat32>(Marshal::GetFunctionPointerForDelegate(setTransform).ToPointer());
                sink->m_setPrimitiveBlend =
                    static_cast<fnHrPB>(Marshal::GetFunctionPointerForDelegate(setPrimitiveBlend).ToPointer());
                sink->m_setUnitMode =
                    static_cast<fnHrUnit>(Marshal::GetFunctionPointerForDelegate(setUnitMode).ToPointer());
                sink->m_clear =
                    static_cast<fnHrClr>(Marshal::GetFunctionPointerForDelegate(clear).ToPointer());
                sink->m_drawGlyphRun =
                    static_cast<fnGlyph>(Marshal::GetFunctionPointerForDelegate(drawGlyphRun).ToPointer());
                sink->m_drawLine =
                    static_cast<fnDrLine>(Marshal::GetFunctionPointerForDelegate(drawLine).ToPointer());
                sink->m_drawGeometry =
                    static_cast<fnDrGeo>(Marshal::GetFunctionPointerForDelegate(drawGeometry).ToPointer());
                sink->m_drawRectangle =
                    static_cast<fnDrRect>(Marshal::GetFunctionPointerForDelegate(drawRectangle).ToPointer());
                sink->m_drawBitmap =
                    static_cast<fnDrBit>(Marshal::GetFunctionPointerForDelegate(drawBitmap).ToPointer());
                sink->m_drawImage =
                    static_cast<fnDrIm>(Marshal::GetFunctionPointerForDelegate(drawImage).ToPointer());
                sink->m_drawGdiMetafile =
                    static_cast<fnDrGdi>(Marshal::GetFunctionPointerForDelegate(drawGdiMetafile).ToPointer());
                sink->m_fillMesh =
                    static_cast<fnFllMesh>(Marshal::GetFunctionPointerForDelegate(fillMesh).ToPointer());
                sink->m_fillOpacityMask =
                    static_cast<fnFllOpMsk>(Marshal::GetFunctionPointerForDelegate(fillOpacityMask).ToPointer());
                sink->m_fillGeometry =
                    static_cast<fnFllGeo>(Marshal::GetFunctionPointerForDelegate(fillGeometry).ToPointer());
                sink->m_fillRectangle =
                    static_cast<fnFllRect>(Marshal::GetFunctionPointerForDelegate(fillRectangle).ToPointer());
                sink->m_pushAxisAlignedClip =
                    static_cast<fnPshAxis>(Marshal::GetFunctionPointerForDelegate(pushAxisAlignedClip).ToPointer());
                sink->m_pushLayer =
                    static_cast<fnPshLyr>(Marshal::GetFunctionPointerForDelegate(pushLayer).ToPointer());
                sink->m_popAxisAlignedClip =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(popAxisAlignedClip).ToPointer());
                sink->m_popLayer =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(popLayer).ToPointer());
            }
            else if(riid == D2DNetGUID::UID_ID2D1CommandSink1)
            {
                m_pSink = new Direct2DNet::ID2D1NativeCommandSink1();

                Direct2DNet::ID2D1NativeCommandSink1 *sink = (Direct2DNet::ID2D1NativeCommandSink1 *)m_pSink;

                sink->m_beginDraw =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(beginDraw).ToPointer());
                sink->m_endDraw =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(endDraw).ToPointer());
                sink->m_setAntialiasMode =
                    static_cast<fnHrAntmode>(Marshal::GetFunctionPointerForDelegate(setAntialiasMode).ToPointer());
                sink->m_setTags =
                    static_cast<fnHr2Tag>(Marshal::GetFunctionPointerForDelegate(setTags).ToPointer());
                sink->m_setTextAntialiasMode =
                    static_cast<fnHrTxtAntmode>(Marshal::GetFunctionPointerForDelegate(setTextAntialiasMode).ToPointer());
                sink->m_setTextRenderingParams =
                    static_cast<fnHrDWRP>(Marshal::GetFunctionPointerForDelegate(setTextRenderingParams).ToPointer());
                sink->m_setTransform =
                    static_cast<fnHrMat32>(Marshal::GetFunctionPointerForDelegate(setTransform).ToPointer());
                sink->m_setPrimitiveBlend =
                    static_cast<fnHrPB>(Marshal::GetFunctionPointerForDelegate(setPrimitiveBlend).ToPointer());
                sink->m_setUnitMode =
                    static_cast<fnHrUnit>(Marshal::GetFunctionPointerForDelegate(setUnitMode).ToPointer());
                sink->m_clear =
                    static_cast<fnHrClr>(Marshal::GetFunctionPointerForDelegate(clear).ToPointer());
                sink->m_drawGlyphRun =
                    static_cast<fnGlyph>(Marshal::GetFunctionPointerForDelegate(drawGlyphRun).ToPointer());
                sink->m_drawLine =
                    static_cast<fnDrLine>(Marshal::GetFunctionPointerForDelegate(drawLine).ToPointer());
                sink->m_drawGeometry =
                    static_cast<fnDrGeo>(Marshal::GetFunctionPointerForDelegate(drawGeometry).ToPointer());
                sink->m_drawRectangle =
                    static_cast<fnDrRect>(Marshal::GetFunctionPointerForDelegate(drawRectangle).ToPointer());
                sink->m_drawBitmap =
                    static_cast<fnDrBit>(Marshal::GetFunctionPointerForDelegate(drawBitmap).ToPointer());
                sink->m_drawImage =
                    static_cast<fnDrIm>(Marshal::GetFunctionPointerForDelegate(drawImage).ToPointer());
                sink->m_drawGdiMetafile =
                    static_cast<fnDrGdi>(Marshal::GetFunctionPointerForDelegate(drawGdiMetafile).ToPointer());
                sink->m_fillMesh =
                    static_cast<fnFllMesh>(Marshal::GetFunctionPointerForDelegate(fillMesh).ToPointer());
                sink->m_fillOpacityMask =
                    static_cast<fnFllOpMsk>(Marshal::GetFunctionPointerForDelegate(fillOpacityMask).ToPointer());
                sink->m_fillGeometry =
                    static_cast<fnFllGeo>(Marshal::GetFunctionPointerForDelegate(fillGeometry).ToPointer());
                sink->m_fillRectangle =
                    static_cast<fnFllRect>(Marshal::GetFunctionPointerForDelegate(fillRectangle).ToPointer());
                sink->m_pushAxisAlignedClip =
                    static_cast<fnPshAxis>(Marshal::GetFunctionPointerForDelegate(pushAxisAlignedClip).ToPointer());
                sink->m_pushLayer =
                    static_cast<fnPshLyr>(Marshal::GetFunctionPointerForDelegate(pushLayer).ToPointer());
                sink->m_popAxisAlignedClip =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(popAxisAlignedClip).ToPointer());
                sink->m_popLayer =
                    static_cast<fnHrVoid>(Marshal::GetFunctionPointerForDelegate(popLayer).ToPointer());
            }
            else
            {
                System::Diagnostics::Debug::Assert(false, "ID2D1CommandSink accepted unknown guid.");
            }
        }

        ID2D1CommandSink::~ID2D1CommandSink()
        {
            if(m_beginDraw.IsAllocated)
                m_beginDraw.Free();

            if(m_endDraw.IsAllocated)
                m_endDraw.Free();

            if(m_setAntialiasMode.IsAllocated)
                m_setAntialiasMode.Free();

            if(m_setTags.IsAllocated)
                m_setTags.Free();

            if(m_setTextAntialiasMode.IsAllocated)
                m_setTextAntialiasMode.Free();

            if(m_setTextRenderingParams.IsAllocated)
                m_setTextRenderingParams.Free();

            if(m_setTransform.IsAllocated)
                m_setTransform.Free();

            if(m_setPrimitiveBlend.IsAllocated)
                m_setPrimitiveBlend.Free();

            if(m_setUnitMode.IsAllocated)
                m_setUnitMode.Free();

            if(m_clear.IsAllocated)
                m_clear.Free();

            if(m_drawGlyphRun.IsAllocated)
                m_drawGlyphRun.Free();

            if(m_drawLine.IsAllocated)
                m_drawLine.Free();

            if(m_drawGeometry.IsAllocated)
                m_drawGeometry.Free();

            if(m_drawRectangle.IsAllocated)
                m_drawRectangle.Free();

            if(m_drawBitmap.IsAllocated)
                m_drawBitmap.Free();

            if(m_drawImage.IsAllocated)
                m_drawImage.Free();

            if(m_drawGdiMetafile.IsAllocated)
                m_drawGdiMetafile.Free();

            if(m_fillMesh.IsAllocated)
                m_fillMesh.Free();

            if(m_fillOpacityMask.IsAllocated)
                m_fillOpacityMask.Free();

            if(m_fillGeometry.IsAllocated)
                m_fillGeometry.Free();

            if(m_fillRectangle.IsAllocated)
                m_fillRectangle.Free();

            if(m_pushAxisAlignedClip.IsAllocated)
                m_pushAxisAlignedClip.Free();

            if(m_pushLayer.IsAllocated)
                m_pushLayer.Free();

            if(m_popAxisAlignedClip.IsAllocated)
                m_popAxisAlignedClip.Free();

            if(m_popLayer.IsAllocated)
                m_popLayer.Free();

            this->!ID2D1CommandSink();
        }

        ID2D1CommandSink::!ID2D1CommandSink()
        {
            if(m_pSink)
            {
                m_pSink->Release();
                m_pSink = nullptr;
            }
        }

        void ID2D1CommandSink::HandleCOMInterface(void *obj)
        {
            throw gcnew System::NotSupportedException("It is not supported to change the internal sink since it causes unexpected action.");
        }

        bool ID2D1CommandSink::Equals(System::Object ^other)
        {
            try
            {
                return this->m_pSink == safe_cast<Direct2DNet::ID2D1CommandSink ^>(other)->m_pSink;
            }
            catch(System::Exception ^)
            {
                return false;
            }
        }

        HRESULT ID2D1CommandSink::BeginDrawInternal()
        {
            return BeginDraw();
        }

        HRESULT ID2D1CommandSink::EndDrawInternal()
        {
            return EndDraw();
        }

        HRESULT ID2D1CommandSink::SetAntialiasModeInternal(::D2D1_ANTIALIAS_MODE antialiasMode)
        {
            return SetAntialiasMode((Direct2DNet::D2D1_ANTIALIAS_MODE)((int)antialiasMode));
        }

        HRESULT ID2D1CommandSink::SetTagsInternal(::D2D1_TAG tag1, D2D1_TAG tag2)
        {
            return SetTags(tag1, tag2);
        }

        HRESULT ID2D1CommandSink::SetTextAntialiasModeInternal(::D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode)
        {
            return SetTextAntialiasMode((Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE)((int)textAntialiasMode));
        }

        HRESULT ID2D1CommandSink::SetTextRenderingParamsInternal(::IDWriteRenderingParams *textRenderingParams)
        {
            if(!textRenderingParams)
            {
                return SetTextRenderingParams(nullptr);
            }
            DWriteNet::IDWriteRenderingParams ^params = gcnew DWriteNet::IDWriteRenderingParams(textRenderingParams);
            textRenderingParams->AddRef();
            return SetTextRenderingParams(params);
        }

        HRESULT ID2D1CommandSink::SetTransformInternal(::D2D1_MATRIX_3X2_F *transform)
        {
            return SetTransform(static_cast<Direct2DNet::D2D1_MATRIX_3X2_F>(*transform));
        }

        HRESULT ID2D1CommandSink::SetPrimitiveBlendInternal(::D2D1_PRIMITIVE_BLEND primitiveBlend)
        {
            return SetPrimitiveBlend((Direct2DNet::D2D1_PRIMITIVE_BLEND)((int)primitiveBlend));
        }

        HRESULT ID2D1CommandSink::SetUnitModeInternal(::D2D1_UNIT_MODE unitMode)
        {
            return SetUnitMode((Direct2DNet::D2D1_UNIT_MODE)((int)unitMode));
        }

        HRESULT ID2D1CommandSink::ClearInternal(::D2D1_COLOR_F *color)
        {
            if(!color)
            {
                return Clear();
            }
            return Clear(static_cast<Direct2DNet::D2D1_COLOR_F>(*color));
        }

        HRESULT ID2D1CommandSink::DrawGlyphRunInternal(::D2D1_POINT_2F baselineOrigin, ::DWRITE_GLYPH_RUN *glyphRun, ::DWRITE_GLYPH_RUN_DESCRIPTION *glyphRunDescription, ::ID2D1Brush *foregroundBrush, ::DWRITE_MEASURING_MODE measuringMode)
        {
            DWriteNet::IDWriteFontFace ^fontFace = gcnew DWriteNet::IDWriteFontFace();
            fontFace->HandleCOMInterface(glyphRun->fontFace);

            DWriteNet::DWRITE_GLYPH_RUN mGlyphRun;
            mGlyphRun.fontFace = fontFace;
            mGlyphRun.fontEmSize = glyphRun->fontEmSize;
            mGlyphRun.glyphCount = glyphRun->glyphCount;
            mGlyphRun.glyphIndices = const_cast<UINT16 *>(glyphRun->glyphIndices);
            mGlyphRun.glyphAdvances = const_cast<FLOAT *>(glyphRun->glyphAdvances);
            mGlyphRun.glyphOffsets = reinterpret_cast<DWriteNet::DWRITE_GLYPH_OFFSET *>(const_cast<::DWRITE_GLYPH_OFFSET *>(glyphRun->glyphOffsets));
            mGlyphRun.isSideways = System::Convert::ToBoolean(glyphRun->isSideways);
            mGlyphRun.bidiLevel = glyphRun->bidiLevel;

            ::ID2D1Factory *pFactory = __nullptr;
            foregroundBrush->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Brush ^mForegreoundBrush = gcnew Direct2DNet::ID2D1Brush(factory, foregroundBrush);
            foregroundBrush->AddRef();

            return DrawGlyphRun(
                static_cast<Direct2DNet::D2D1_POINT_2F>(baselineOrigin),
                mGlyphRun,
                mForegreoundBrush,
                (DWriteNet::DWRITE_MEASURING_MODE)((int)measuringMode),
                glyphRunDescription ?
                *(DWriteNet::DWRITE_GLYPH_RUN_DESCRIPTION *)glyphRunDescription
                : System::Nullable<DWriteNet::DWRITE_GLYPH_RUN_DESCRIPTION>()
            );
        }

        HRESULT ID2D1CommandSink::DrawLineInternal(::D2D1_POINT_2F point0, ::D2D1_POINT_2F point1, ::ID2D1Brush *brush, FLOAT strokeWidth, ::ID2D1StrokeStyle *strokeStyle)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            brush->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Brush ^brush2 = gcnew Direct2DNet::ID2D1Brush(factory, brush);
            brush->AddRef();

            Direct2DNet::ID2D1StrokeStyle ^strokeStyle2;
            if(!strokeStyle)
            {
                strokeStyle2 = nullptr;
            }
            else
            {
                ::ID2D1Factory *pFactory2 = __nullptr;
                strokeStyle->GetFactory(&pFactory2);
                if(pFactory != pFactory2)
                {
                    factory = gcnew Direct2DNet::ID2D1Factory(pFactory2);
                }
                else
                {
                    pFactory2->Release();
                }

                strokeStyle2 = gcnew Direct2DNet::ID2D1StrokeStyle(factory, strokeStyle);
                strokeStyle->AddRef();
            }

            return DrawLine(
                static_cast<Direct2DNet::D2D1_POINT_2F>(point0),
                static_cast<Direct2DNet::D2D1_POINT_2F>(point1),
                brush2,
                strokeWidth,
                strokeStyle2
            );
        }

        HRESULT ID2D1CommandSink::DrawGeometryInternal(::ID2D1Geometry *geometry, ::ID2D1Brush *brush, FLOAT strokeWidth, ::ID2D1StrokeStyle *strokeStyle)
        {
            ::ID2D1Factory *pFactory1 = __nullptr;
            geometry->GetFactory(&pFactory1);

            Direct2DNet::ID2D1Factory ^factory1 = gcnew Direct2DNet::ID2D1Factory(pFactory1);

            Direct2DNet::ID2D1Geometry ^geometry2 = gcnew Direct2DNet::ID2D1Geometry(factory1, geometry);
            geometry->AddRef();

            ::ID2D1Factory *pFactory2 = __nullptr;
            brush->GetFactory(&pFactory2);

            Direct2DNet::ID2D1Factory ^factory2;
            if(pFactory1 == pFactory2)
            {
                factory2 = factory1;
                pFactory2->Release();
            }
            else
            {
                factory2 = gcnew Direct2DNet::ID2D1Factory(pFactory2);
            }

            Direct2DNet::ID2D1Brush ^brush2 = gcnew Direct2DNet::ID2D1Brush(factory2, brush);
            brush->AddRef();

            Direct2DNet::ID2D1StrokeStyle ^strokeStyle2;
            if(!strokeStyle)
            {
                strokeStyle2 = nullptr;
            }
            else
            {
                ::ID2D1Factory *pFactory3 = __nullptr;
                strokeStyle->GetFactory(&pFactory3);

                Direct2DNet::ID2D1Factory ^factory3;
                if(pFactory1 == pFactory3)
                {
                    factory3 = factory1;
                    pFactory3->Release();
                }
                else if(pFactory2 == pFactory3)
                {
                    factory3 = factory2;
                    pFactory3->Release();
                }
                else
                {
                    factory3 = gcnew Direct2DNet::ID2D1Factory(pFactory3);
                }

                strokeStyle2 = gcnew Direct2DNet::ID2D1StrokeStyle(factory3, strokeStyle);
                strokeStyle->AddRef();
            }

            return DrawGeometry(geometry2, brush2, strokeWidth, strokeStyle2);
        }

        HRESULT ID2D1CommandSink::DrawRectangleInternal(::D2D1_RECT_F *rect, ::ID2D1Brush *brush, FLOAT strokeWidth, ::ID2D1StrokeStyle *strokeStyle)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            brush->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Brush ^brush2 = gcnew Direct2DNet::ID2D1Brush(factory, brush);
            brush->AddRef();

            Direct2DNet::ID2D1StrokeStyle ^strokeStyle2;
            if(!strokeStyle)
            {
                strokeStyle2 = nullptr;
            }
            else
            {
                ::ID2D1Factory *pFactory2 = __nullptr;
                strokeStyle->GetFactory(&pFactory2);
                if(pFactory != pFactory2)
                {
                    factory = gcnew Direct2DNet::ID2D1Factory(pFactory2);
                }
                else
                {
                    pFactory2->Release();
                }

                strokeStyle2 = gcnew Direct2DNet::ID2D1StrokeStyle(factory, strokeStyle);
                strokeStyle->AddRef();
            }

            return DrawRectangle(
                static_cast<Direct2DNet::D2D1_RECT_F>(*rect),
                brush2,
                strokeWidth,
                strokeStyle2
            );
        }

        HRESULT ID2D1CommandSink::DrawBitmapInternal(::ID2D1Bitmap *bitmap, ::D2D1_RECT_F *destinationRectangle, FLOAT opacity, ::D2D1_INTERPOLATION_MODE interpolationMode, ::D2D1_RECT_F *sourceRectangle, ::D2D1_MATRIX_4X4_F *perspectiveTransform)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            bitmap->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Bitmap ^bitmap2 = gcnew Direct2DNet::ID2D1Bitmap(factory, bitmap);
            bitmap->AddRef();

            return DrawBitmap(
                bitmap2,
                opacity,
                (Direct2DNet::D2D1_INTERPOLATION_MODE)((int)interpolationMode),
                destinationRectangle ? static_cast<Direct2DNet::D2D1_RECT_F>(*destinationRectangle) : Nullable<Direct2DNet::D2D1_RECT_F>(),
                sourceRectangle ? static_cast<Direct2DNet::D2D1_RECT_F>(*sourceRectangle) : Nullable<Direct2DNet::D2D1_RECT_F>(),
                perspectiveTransform ? static_cast<Direct2DNet::D2D1_MATRIX_4X4_F>(*perspectiveTransform) : Nullable<Direct2DNet::D2D1_MATRIX_4X4_F>()
            );
        }

        HRESULT ID2D1CommandSink::DrawImageInternal(::ID2D1Image *image, ::D2D1_POINT_2F *targetOffset, ::D2D1_RECT_F *imageRectangle, ::D2D1_INTERPOLATION_MODE interpolationMode, ::D2D1_COMPOSITE_MODE compositeMode)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            image->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Image ^image2 = gcnew Direct2DNet::ID2D1Image(factory, image);
            image->AddRef();

            return DrawImage(
                image2,
                (Direct2DNet::D2D1_INTERPOLATION_MODE)((int)interpolationMode),
                (Direct2DNet::D2D1_COMPOSITE_MODE)((int)compositeMode),
                targetOffset ? static_cast<Direct2DNet::D2D1_POINT_2F>(*targetOffset) : Nullable<Direct2DNet::D2D1_POINT_2F>(),
                imageRectangle ? static_cast<Direct2DNet::D2D1_RECT_F>(*imageRectangle) : Nullable<Direct2DNet::D2D1_RECT_F>()
            );
        }

        HRESULT ID2D1CommandSink::DrawGdiMetafileInternal(::ID2D1GdiMetafile *gdiMetafile, ::D2D1_POINT_2F *targetOffset)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            gdiMetafile->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1GdiMetafile ^metafile = gcnew Direct2DNet::ID2D1GdiMetafile(factory, gdiMetafile);
            gdiMetafile->AddRef();

            return DrawGdiMetafile(
                metafile,
                targetOffset ? static_cast<Direct2DNet::D2D1_POINT_2F>(*targetOffset) : Nullable<Direct2DNet::D2D1_POINT_2F>()
            );
        }

        HRESULT ID2D1CommandSink::FillMeshInternal(::ID2D1Mesh *mesh, ::ID2D1Brush *brush)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            mesh->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Mesh ^mesh2 = gcnew Direct2DNet::ID2D1Mesh(factory, mesh);
            mesh->AddRef();

            ::ID2D1Factory *pFactory2 = __nullptr;
            brush->GetFactory(&pFactory2);
            if(pFactory != pFactory2)
            {
                factory = gcnew Direct2DNet::ID2D1Factory(pFactory2);
            }
            else
            {
                pFactory2->Release();
            }

            Direct2DNet::ID2D1Brush ^brush2 = gcnew Direct2DNet::ID2D1Brush(factory, brush);
            brush->AddRef();

            return FillMesh(mesh2, brush2);
        }

        HRESULT ID2D1CommandSink::FillOpacityMaskInternal(::ID2D1Bitmap *opacityMask, ::ID2D1Brush *brush, ::D2D1_RECT_F *destinationRectangle, ::D2D1_RECT_F *sourceRectangle)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            opacityMask->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Bitmap ^opacityMask2 = gcnew Direct2DNet::ID2D1Bitmap(factory, opacityMask);
            opacityMask->AddRef();

            ::ID2D1Factory *pFactory2 = __nullptr;
            brush->GetFactory(&pFactory2);
            if(pFactory != pFactory2)
            {
                factory = gcnew Direct2DNet::ID2D1Factory(pFactory2);
            }
            else
            {
                pFactory2->Release();
            }

            Direct2DNet::ID2D1Brush ^brush2 = gcnew Direct2DNet::ID2D1Brush(factory, brush);
            brush->AddRef();

            return FillOpacityMask(
                opacityMask2,
                brush2,
                destinationRectangle ? static_cast<Direct2DNet::D2D1_RECT_F>(*destinationRectangle) : Nullable<Direct2DNet::D2D1_RECT_F>(),
                sourceRectangle ? static_cast<Direct2DNet::D2D1_RECT_F>(*sourceRectangle) : Nullable<Direct2DNet::D2D1_RECT_F>()
            );
        }

        HRESULT ID2D1CommandSink::FillGeometryInternal(::ID2D1Geometry *geometry, ::ID2D1Brush *brush, ::ID2D1Brush *opacityBrush)
        {
            ::ID2D1Factory *pFactory1 = __nullptr;
            geometry->GetFactory(&pFactory1);

            Direct2DNet::ID2D1Factory ^factory1 = gcnew Direct2DNet::ID2D1Factory(pFactory1);

            Direct2DNet::ID2D1Geometry ^geometry2 = gcnew Direct2DNet::ID2D1Geometry(factory1, geometry);
            geometry->AddRef();

            ::ID2D1Factory *pFactory2 = __nullptr;
            brush->GetFactory(&pFactory2);

            Direct2DNet::ID2D1Factory ^factory2;
            if(pFactory1 == pFactory2)
            {
                factory2 = factory1;
                pFactory2->Release();
            }
            else
            {
                factory2 = gcnew Direct2DNet::ID2D1Factory(pFactory2);
            }

            Direct2DNet::ID2D1Brush ^brush2 = gcnew Direct2DNet::ID2D1Brush(factory2, brush);
            brush->AddRef();

            Direct2DNet::ID2D1Brush ^opacityBrush2;
            if(!opacityBrush)
            {
                opacityBrush2 = nullptr;
            }
            else
            {
                ::ID2D1Factory *pFactory3 = __nullptr;
                opacityBrush->GetFactory(&pFactory3);

                Direct2DNet::ID2D1Factory ^factory3;
                if(pFactory1 == pFactory3)
                {
                    factory3 = factory1;
                    pFactory3->Release();
                }
                else if(pFactory2 == pFactory3)
                {
                    factory3 = factory2;
                    pFactory3->Release();
                }
                else
                {
                    factory3 = gcnew Direct2DNet::ID2D1Factory(pFactory3);
                }

                opacityBrush2 = gcnew Direct2DNet::ID2D1Brush(factory3, opacityBrush);
                opacityBrush->AddRef();
            }

            return FillGeometry(geometry2, brush2, opacityBrush2);
        }

        HRESULT ID2D1CommandSink::FillRectangleInternal(::D2D1_RECT_F *rect, ::ID2D1Brush *brush)
        {
            ::ID2D1Factory *pFactory = __nullptr;
            brush->GetFactory(&pFactory);

            Direct2DNet::ID2D1Factory ^factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

            Direct2DNet::ID2D1Brush ^brush2 = gcnew Direct2DNet::ID2D1Brush(factory, brush);
            brush->AddRef();

            return FillRectangle(static_cast<Direct2DNet::D2D1_RECT_F>(*rect), brush2);
        }

        HRESULT ID2D1CommandSink::PushAxisAlignedClipInternal(::D2D1_RECT_F *clipRect, ::D2D1_ANTIALIAS_MODE antialiasMode)
        {
            return PushAxisAlignedClip(
                static_cast<Direct2DNet::D2D1_RECT_F>(*clipRect),
                (Direct2DNet::D2D1_ANTIALIAS_MODE)((int)antialiasMode)
            );
        }

        HRESULT ID2D1CommandSink::PushLayerInternal(::D2D1_LAYER_PARAMETERS1 *layerParameters1, ::ID2D1Layer *layer)
        {
            Direct2DNet::D2D1_LAYER_PARAMETERS1 params;
            params.contentBounds = static_cast<Direct2DNet::D2D1_RECT_F>(layerParameters1->contentBounds);

            ::ID2D1Factory *pFactory = __nullptr;
            Direct2DNet::ID2D1Factory ^factory = nullptr;
            if(!(layerParameters1->geometricMask))
            {
                params.geometricMask = nullptr;
            }
            else
            {
                layerParameters1->geometricMask->GetFactory(&pFactory);

                factory = gcnew Direct2DNet::ID2D1Factory(pFactory);

                params.geometricMask = gcnew Direct2DNet::ID2D1Geometry(factory, layerParameters1->geometricMask);
                layerParameters1->geometricMask->AddRef();
            }

            params.maskAntialiasMode = (Direct2DNet::D2D1_ANTIALIAS_MODE)((int)layerParameters1->maskAntialiasMode);
            params.maskTransform = static_cast<Direct2DNet::D2D1_MATRIX_3X2_F>(layerParameters1->maskTransform);
            params.opacity = layerParameters1->opacity;

            ::ID2D1Factory *pFactory2 = __nullptr;
            Direct2DNet::ID2D1Factory ^factory2 = nullptr;
            if(!(layerParameters1->opacityBrush))
            {
                params.opacityBrush = nullptr;
            }
            else
            {
                layerParameters1->opacityBrush->GetFactory(&pFactory2);
                if(pFactory == pFactory2)
                {
                    factory2 = factory;
                    pFactory2->Release();
                }
                else
                {
                    factory2 = gcnew Direct2DNet::ID2D1Factory(pFactory2);
                }

                params.opacityBrush = gcnew Direct2DNet::ID2D1Brush(factory2, layerParameters1->opacityBrush);
                layerParameters1->opacityBrush->AddRef();
            }

            params.layerOptions = (Direct2DNet::D2D1_LAYER_OPTIONS1)((int)layerParameters1->layerOptions);

            ::ID2D1Factory *pFactory3 = __nullptr;
            Direct2DNet::ID2D1Factory ^factory3 = nullptr;
            layer->GetFactory(&pFactory3);

            if(pFactory == pFactory3)
            {
                factory3 = factory;
                pFactory3->Release();
            }
            else if(pFactory2 == pFactory3)
            {
                factory3 = factory2;
                pFactory3->Release();
            }
            else
            {
                factory3 = gcnew Direct2DNet::ID2D1Factory(pFactory3);
            }

            Direct2DNet::ID2D1Layer ^layer2 = gcnew Direct2DNet::ID2D1Layer(factory3, layer);
            layer->AddRef();

            return PushLayer(params, layer2);
        }

        HRESULT ID2D1CommandSink::PopAxisAlignedClipInternal()
        {
            return PopAxisAlignedClip();
        }

        HRESULT ID2D1CommandSink::PopLayerInternal()
        {
            return PopLayer();
        }

    }
}