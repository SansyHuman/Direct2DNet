#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"

using namespace System;
using namespace System::Runtime;

#define GCHandle InteropServices::GCHandle
#define Marshal InteropServices::Marshal
#define In InteropServices::InAttribute
#define IsReadOnly CompilerServices::IsReadOnlyAttribute
#define Optional InteropServices::OptionalAttribute

namespace D2DNet
{
    namespace DWriteNet
    {
        ref class IDWriteRenderingParams;
    }

    namespace Direct2DNet
    {
        using fnHrVoid = HRESULT(__stdcall *)(void);
        using fnHrAntmode = HRESULT(__stdcall *)(::D2D1_ANTIALIAS_MODE);
        using fnHr2Tag = HRESULT(__stdcall *)(::D2D1_TAG, ::D2D1_TAG);
        using fnHrTxtAntmode = HRESULT(__stdcall *)(::D2D1_TEXT_ANTIALIAS_MODE);
        using fnHrDWRP = HRESULT(__stdcall *)(::IDWriteRenderingParams *);
        using fnHrMat32 = HRESULT(__stdcall *)(::D2D1_MATRIX_3X2_F *);
        using fnHrPB = HRESULT(__stdcall *)(::D2D1_PRIMITIVE_BLEND);
        using fnHrUnit = HRESULT(__stdcall *)(::D2D1_UNIT_MODE);
        using fnHrClr = HRESULT(__stdcall *)(::D2D1_COLOR_F *);
        using fnGlyph = HRESULT(__stdcall *)(::D2D1_POINT_2F, ::DWRITE_GLYPH_RUN *, ::DWRITE_GLYPH_RUN_DESCRIPTION *, ::ID2D1Brush *, ::DWRITE_MEASURING_MODE);
        using fnDrLine = HRESULT(__stdcall *)(::D2D1_POINT_2F, ::D2D1_POINT_2F, ::ID2D1Brush *, float, ::ID2D1StrokeStyle *);
        using fnDrGeo = HRESULT(__stdcall *)(::ID2D1Geometry *, ::ID2D1Brush *, float, ::ID2D1StrokeStyle *);
        using fnDrRect = HRESULT(__stdcall *)(::D2D1_RECT_F *, ::ID2D1Brush *, float, ::ID2D1StrokeStyle *);
        using fnDrBit = HRESULT(__stdcall *)(::ID2D1Bitmap *, ::D2D1_RECT_F *, float, ::D2D1_INTERPOLATION_MODE, ::D2D1_RECT_F *, ::D2D1_MATRIX_4X4_F *);
        using fnDrIm = HRESULT(__stdcall *)(::ID2D1Image *, ::D2D1_POINT_2F *, ::D2D1_RECT_F *, ::D2D1_INTERPOLATION_MODE, ::D2D1_COMPOSITE_MODE);
        using fnDrGdi = HRESULT(__stdcall *)(::ID2D1GdiMetafile *, ::D2D1_POINT_2F *);
        using fnFllMesh = HRESULT(__stdcall *)(::ID2D1Mesh *, ::ID2D1Brush *);
        using fnFllOpMsk = HRESULT(__stdcall *)(::ID2D1Bitmap *, ::ID2D1Brush *, ::D2D1_RECT_F *, ::D2D1_RECT_F *);
        using fnFllGeo = HRESULT(__stdcall *)(::ID2D1Geometry *, ::ID2D1Brush *, ::ID2D1Brush *);
        using fnFllRect = HRESULT(__stdcall *)(::D2D1_RECT_F *, ::ID2D1Brush *);
        using fnPshAxis = HRESULT(__stdcall *)(::D2D1_RECT_F *, ::D2D1_ANTIALIAS_MODE);
        using fnPshLyr = HRESULT(__stdcall *)(::D2D1_LAYER_PARAMETERS1 *, ::ID2D1Layer *);

        class ID2D1NativeCommandSink : public ::ID2D1CommandSink
        {
        private:
            UINT m_cRef;

        public:
            fnHrVoid m_beginDraw;
            fnHrVoid m_endDraw;
            fnHrAntmode m_setAntialiasMode;
            fnHr2Tag m_setTags;
            fnHrTxtAntmode m_setTextAntialiasMode;
            fnHrDWRP m_setTextRenderingParams;
            fnHrMat32 m_setTransform;
            fnHrPB m_setPrimitiveBlend;
            fnHrUnit m_setUnitMode;
            fnHrClr m_clear;
            fnGlyph m_drawGlyphRun;
            fnDrLine m_drawLine;
            fnDrGeo m_drawGeometry;
            fnDrRect m_drawRectangle;
            fnDrBit m_drawBitmap;
            fnDrIm m_drawImage;
            fnDrGdi m_drawGdiMetafile;
            fnFllMesh m_fillMesh;
            fnFllOpMsk m_fillOpacityMask;
            fnFllGeo m_fillGeometry;
            fnFllRect m_fillRectangle;
            fnPshAxis m_pushAxisAlignedClip;
            fnPshLyr m_pushLayer;
            fnHrVoid m_popAxisAlignedClip;
            fnHrVoid m_popLayer;

            ID2D1NativeCommandSink() : m_cRef(1) {}

            STDMETHOD_(ULONG, AddRef)(void) override
            {
                return InterlockedIncrement(reinterpret_cast<LONG volatile *>(&m_cRef));
            }

            STDMETHOD_(ULONG, Release)(void) override
            {
                ULONG cRef = static_cast<ULONG>(
                    InterlockedDecrement(reinterpret_cast<LONG volatile *>(&m_cRef)));

                if(0 == cRef)
                {
                    delete this;
                }

                return cRef;
            }

            STDMETHOD(QueryInterface)(THIS_ REFIID iid, void **ppvObject) override
            {
                HRESULT hr = S_OK;

                if(__uuidof(::IUnknown) == iid)
                {
                    *ppvObject = static_cast<::IUnknown *>(this);
                    AddRef();
                }
                else if(__uuidof(::ID2D1CommandSink) == iid)
                {
                    *ppvObject = static_cast<::ID2D1CommandSink *>(this);
                    AddRef();
                }
                else
                {
                    *ppvObject = NULL;
                    hr = E_NOINTERFACE;
                }

                return hr;
            }

            STDMETHOD(BeginDraw)() override
            {
                return m_beginDraw();
            }

            STDMETHOD(EndDraw)() override
            {
                return m_endDraw();
            }

            STDMETHOD(SetAntialiasMode)(
                ::D2D1_ANTIALIAS_MODE antialiasMode
                ) override
            {
                return m_setAntialiasMode(antialiasMode);
            }

            STDMETHOD(SetTags)(
                ::D2D1_TAG tag1,
                ::D2D1_TAG tag2
                ) override
            {
                return m_setTags(tag1, tag2);
            }

            STDMETHOD(SetTextAntialiasMode)(
                ::D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
                ) override
            {
                return m_setTextAntialiasMode(textAntialiasMode);
            }

            STDMETHOD(SetTextRenderingParams)(
                _In_opt_ ::IDWriteRenderingParams *textRenderingParams
                ) override
            {
                return m_setTextRenderingParams(textRenderingParams);
            }

            STDMETHOD(SetTransform)(
                _In_ CONST ::D2D1_MATRIX_3X2_F *transform
                ) override
            {
                return m_setTransform(const_cast<::D2D1_MATRIX_3X2_F *>(transform));
            }

            STDMETHOD(SetPrimitiveBlend)(
                ::D2D1_PRIMITIVE_BLEND primitiveBlend
                ) override
            {
                return m_setPrimitiveBlend(primitiveBlend);
            }

            STDMETHOD(SetUnitMode)(
                ::D2D1_UNIT_MODE unitMode
                ) override
            {
                return m_setUnitMode(unitMode);
            }

            STDMETHOD(Clear)(
                _In_opt_ CONST ::D2D1_COLOR_F *color
                ) override
            {
                return m_clear(const_cast<::D2D1_COLOR_F *>(color));
            }

            STDMETHOD(DrawGlyphRun)(
                ::D2D1_POINT_2F baselineOrigin,
                _In_ CONST::DWRITE_GLYPH_RUN *glyphRun,
                _In_opt_ CONST::DWRITE_GLYPH_RUN_DESCRIPTION *glyphRunDescription,
                _In_::ID2D1Brush *foregroundBrush,
                ::DWRITE_MEASURING_MODE measuringMode
                ) override
            {
                return m_drawGlyphRun(
                    baselineOrigin,
                    const_cast<::DWRITE_GLYPH_RUN *>(glyphRun),
                    const_cast<::DWRITE_GLYPH_RUN_DESCRIPTION *>(glyphRunDescription),
                    foregroundBrush,
                    measuringMode
                );
            }

            STDMETHOD(DrawLine)(
                ::D2D1_POINT_2F point0,
                ::D2D1_POINT_2F point1,
                _In_::ID2D1Brush *brush,
                FLOAT strokeWidth,
                _In_opt_::ID2D1StrokeStyle *strokeStyle
                ) override
            {
                return m_drawLine(point0, point1, brush, strokeWidth, strokeStyle);
            }

            STDMETHOD(DrawGeometry)(
                _In_::ID2D1Geometry *geometry,
                _In_::ID2D1Brush *brush,
                FLOAT strokeWidth,
                _In_opt_::ID2D1StrokeStyle *strokeStyle
                ) override
            {
                return m_drawGeometry(geometry, brush, strokeWidth, strokeStyle);
            }

            STDMETHOD(DrawRectangle)(
                _In_ CONST::D2D1_RECT_F *rect,
                _In_::ID2D1Brush *brush,
                FLOAT strokeWidth,
                _In_opt_::ID2D1StrokeStyle *strokeStyle
                ) override
            {
                return m_drawRectangle(const_cast<::D2D1_RECT_F *>(rect), brush, strokeWidth, strokeStyle);
            }

            STDMETHOD(DrawBitmap)(
                _In_ ::ID2D1Bitmap *bitmap,
                _In_opt_ CONST ::D2D1_RECT_F *destinationRectangle,
                FLOAT opacity,
                ::D2D1_INTERPOLATION_MODE interpolationMode,
                _In_opt_ CONST ::D2D1_RECT_F *sourceRectangle,
                _In_opt_ CONST ::D2D1_MATRIX_4X4_F *perspectiveTransform
                ) override
            {
                return m_drawBitmap(
                    bitmap,
                    const_cast<::D2D1_RECT_F *>(destinationRectangle),
                    opacity,
                    interpolationMode,
                    const_cast<::D2D1_RECT_F *>(sourceRectangle),
                    const_cast<::D2D1_MATRIX_4X4_F *>(perspectiveTransform)
                );
            }

            STDMETHOD(DrawImage)(
                _In_::ID2D1Image *image,
                _In_opt_ CONST::D2D1_POINT_2F *targetOffset,
                _In_opt_ CONST::D2D1_RECT_F *imageRectangle,
                ::D2D1_INTERPOLATION_MODE interpolationMode,
                ::D2D1_COMPOSITE_MODE compositeMode
                ) override
            {
                return m_drawImage(
                    image,
                    const_cast<::D2D1_POINT_2F *>(targetOffset),
                    const_cast<::D2D1_RECT_F *>(imageRectangle),
                    interpolationMode,
                    compositeMode
                );
            }

            STDMETHOD(DrawGdiMetafile)(
                _In_ ::ID2D1GdiMetafile *gdiMetafile,
                _In_opt_ CONST ::D2D1_POINT_2F *targetOffset
                ) override
            {
                return m_drawGdiMetafile(gdiMetafile, const_cast<::D2D1_POINT_2F *>(targetOffset));
            }

            STDMETHOD(FillMesh)(
                _In_::ID2D1Mesh *mesh,
                _In_::ID2D1Brush *brush
                ) override
            {
                return m_fillMesh(mesh, brush);
            }

            STDMETHOD(FillOpacityMask)(
                _In_ ::ID2D1Bitmap *opacityMask,
                _In_ ::ID2D1Brush *brush,
                _In_opt_ CONST ::D2D1_RECT_F *destinationRectangle,
                _In_opt_ CONST ::D2D1_RECT_F *sourceRectangle
                ) override
            {
                return m_fillOpacityMask(
                    opacityMask,
                    brush,
                    const_cast<::D2D1_RECT_F *>(destinationRectangle),
                    const_cast<::D2D1_RECT_F *>(sourceRectangle)
                );
            }

            STDMETHOD(FillGeometry)(
                _In_::ID2D1Geometry *geometry,
                _In_::ID2D1Brush *brush,
                _In_opt_::ID2D1Brush *opacityBrush
                ) override
            {
                return m_fillGeometry(geometry, brush, opacityBrush);
            }

            STDMETHOD(FillRectangle)(
                _In_ CONST::D2D1_RECT_F *rect,
                _In_::ID2D1Brush *brush
                ) override
            {
                return m_fillRectangle(const_cast<::D2D1_RECT_F *>(rect), brush);
            }

            STDMETHOD(PushAxisAlignedClip)(
                _In_ CONST ::D2D1_RECT_F *clipRect,
                ::D2D1_ANTIALIAS_MODE antialiasMode
                ) override
            {
                return m_pushAxisAlignedClip(const_cast<::D2D1_RECT_F *>(clipRect), antialiasMode);
            }

            STDMETHOD(PushLayer)(
                _In_ CONST ::D2D1_LAYER_PARAMETERS1 *layerParameters1,
                _In_opt_ ::ID2D1Layer *layer
                ) override
            {
                return m_pushLayer(const_cast<::D2D1_LAYER_PARAMETERS1 *>(layerParameters1), layer);
            }

            STDMETHOD(PopAxisAlignedClip)() override
            {
                return m_popAxisAlignedClip();
            }

            STDMETHOD(PopLayer)() override
            {
                return m_popLayer();
            }
        };

        ref class ID2D1Bitmap;
        ref class ID2D1Brush;
        ref class ID2D1StrokeStyle;
        ref class ID2D1Geometry;
        ref class ID2D1Image;
        ref class ID2D1Mesh;
        ref class ID2D1Layer;

        /// <summary>
        /// Caller-supplied implementation of an interface to receive the recorded command
        /// list.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("3BCD55A5-F17C-43F4-8695-D0FE3CE4029F")]
        public ref class ID2D1CommandSink abstract : Direct2DNet::IDirect2DObject
        {
        protected:
            delegate HRESULT FnHrVoid(void);
            delegate HRESULT FnHrAntmode(::D2D1_ANTIALIAS_MODE);
            delegate HRESULT FnHr2Tag(::D2D1_TAG, ::D2D1_TAG);
            delegate HRESULT FnHrTxtAntmode(::D2D1_TEXT_ANTIALIAS_MODE);
            delegate HRESULT FnHrDWRP(::IDWriteRenderingParams *);
            delegate HRESULT FnHrMat32(::D2D1_MATRIX_3X2_F *);
            delegate HRESULT FnHrPB(::D2D1_PRIMITIVE_BLEND);
            delegate HRESULT FnHrUnit(::D2D1_UNIT_MODE);
            delegate HRESULT FnHrClr(::D2D1_COLOR_F *);
            delegate HRESULT FnGlyph(::D2D1_POINT_2F, ::DWRITE_GLYPH_RUN *, ::DWRITE_GLYPH_RUN_DESCRIPTION *, ::ID2D1Brush *, ::DWRITE_MEASURING_MODE);
            delegate HRESULT FnDrLine(::D2D1_POINT_2F, ::D2D1_POINT_2F, ::ID2D1Brush *, float, ::ID2D1StrokeStyle *);
            delegate HRESULT FnDrGeo(::ID2D1Geometry *, ::ID2D1Brush *, float, ::ID2D1StrokeStyle *);
            delegate HRESULT FnDrRect(::D2D1_RECT_F *, ::ID2D1Brush *, float, ::ID2D1StrokeStyle *);
            delegate HRESULT FnDrBit(::ID2D1Bitmap *, ::D2D1_RECT_F *, float, ::D2D1_INTERPOLATION_MODE, ::D2D1_RECT_F *, ::D2D1_MATRIX_4X4_F *);
            delegate HRESULT FnDrIm(::ID2D1Image *, ::D2D1_POINT_2F *, ::D2D1_RECT_F *, ::D2D1_INTERPOLATION_MODE, ::D2D1_COMPOSITE_MODE);
            delegate HRESULT FnDrGdi(::ID2D1GdiMetafile *, ::D2D1_POINT_2F *);
            delegate HRESULT FnFllMesh(::ID2D1Mesh *, ::ID2D1Brush *);
            delegate HRESULT FnFllOpMsk(::ID2D1Bitmap *, ::ID2D1Brush *, ::D2D1_RECT_F *, ::D2D1_RECT_F *);
            delegate HRESULT FnFllGeo(::ID2D1Geometry *, ::ID2D1Brush *, ::ID2D1Brush *);
            delegate HRESULT FnFllRect(::D2D1_RECT_F *, ::ID2D1Brush *);
            delegate HRESULT FnPshAxis(::D2D1_RECT_F *, ::D2D1_ANTIALIAS_MODE);
            delegate HRESULT FnPshLyr(::D2D1_LAYER_PARAMETERS1 *, ::ID2D1Layer *);

        internal:
            ::ID2D1CommandSink *m_pSink;

        private:
            GCHandle m_beginDraw;
            GCHandle m_endDraw;
            GCHandle m_setAntialiasMode;
            GCHandle m_setTags;
            GCHandle m_setTextAntialiasMode;
            GCHandle m_setTextRenderingParams;
            GCHandle m_setTransform;
            GCHandle m_setPrimitiveBlend;
            GCHandle m_setUnitMode;
            GCHandle m_clear;
            GCHandle m_drawGlyphRun;
            GCHandle m_drawLine;
            GCHandle m_drawGeometry;
            GCHandle m_drawRectangle;
            GCHandle m_drawBitmap;
            GCHandle m_drawImage;
            GCHandle m_drawGdiMetafile;
            GCHandle m_fillMesh;
            GCHandle m_fillOpacityMask;
            GCHandle m_fillGeometry;
            GCHandle m_fillRectangle;
            GCHandle m_pushAxisAlignedClip;
            GCHandle m_pushLayer;
            GCHandle m_popAxisAlignedClip;
            GCHandle m_popLayer;

        protected:
            ID2D1CommandSink();

        public:
            ~ID2D1CommandSink();
            !ID2D1CommandSink();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return reinterpret_cast<void *>(m_pSink);
                }
            }

            virtual bool Equals(System::Object ^other) override;

        private:
            HRESULT BeginDrawInternal();

            HRESULT EndDrawInternal();

            HRESULT SetAntialiasModeInternal(::D2D1_ANTIALIAS_MODE antialiasMode);

            HRESULT SetTagsInternal(::D2D1_TAG tag1,D2D1_TAG tag2);

            HRESULT SetTextAntialiasModeInternal(
                ::D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
                );

            HRESULT SetTextRenderingParamsInternal(
                ::IDWriteRenderingParams *textRenderingParams
                );

            HRESULT SetTransformInternal(
                ::D2D1_MATRIX_3X2_F *transform
                );

            HRESULT SetPrimitiveBlendInternal(
                ::D2D1_PRIMITIVE_BLEND primitiveBlend
                );

            HRESULT SetUnitModeInternal(
                ::D2D1_UNIT_MODE unitMode
                );

            HRESULT ClearInternal(
                ::D2D1_COLOR_F *color
                );

            HRESULT DrawGlyphRunInternal(
                ::D2D1_POINT_2F baselineOrigin,
                ::DWRITE_GLYPH_RUN *glyphRun,
                ::DWRITE_GLYPH_RUN_DESCRIPTION *glyphRunDescription,
                ::ID2D1Brush *foregroundBrush,
                ::DWRITE_MEASURING_MODE measuringMode
                );

            HRESULT DrawLineInternal(
                ::D2D1_POINT_2F point0,
                ::D2D1_POINT_2F point1,
                ::ID2D1Brush *brush,
                FLOAT strokeWidth,
                ::ID2D1StrokeStyle *strokeStyle
                );

            HRESULT DrawGeometryInternal(
                ::ID2D1Geometry *geometry,
                ::ID2D1Brush *brush,
                FLOAT strokeWidth,
                ::ID2D1StrokeStyle *strokeStyle
                );

            HRESULT DrawRectangleInternal(
                ::D2D1_RECT_F *rect,
                ::ID2D1Brush *brush,
                FLOAT strokeWidth,
                ::ID2D1StrokeStyle *strokeStyle
                );

            HRESULT DrawBitmapInternal(
                ::ID2D1Bitmap *bitmap,
                ::D2D1_RECT_F *destinationRectangle,
                FLOAT opacity,
                ::D2D1_INTERPOLATION_MODE interpolationMode,
                ::D2D1_RECT_F *sourceRectangle,
                ::D2D1_MATRIX_4X4_F *perspectiveTransform
                );

            HRESULT DrawImageInternal(
                ::ID2D1Image *image,
                ::D2D1_POINT_2F *targetOffset,
                ::D2D1_RECT_F *imageRectangle,
                ::D2D1_INTERPOLATION_MODE interpolationMode,
                ::D2D1_COMPOSITE_MODE compositeMode
                );

            HRESULT DrawGdiMetafileInternal(
                ::ID2D1GdiMetafile *gdiMetafile,
                ::D2D1_POINT_2F *targetOffset
                );

            HRESULT FillMeshInternal(
                ::ID2D1Mesh *mesh,
                ::ID2D1Brush *brush
                );

            HRESULT FillOpacityMaskInternal(
                ::ID2D1Bitmap *opacityMask,
                ::ID2D1Brush *brush,
                ::D2D1_RECT_F *destinationRectangle,
                ::D2D1_RECT_F *sourceRectangle
                );

            HRESULT FillGeometryInternal(
                ::ID2D1Geometry *geometry,
                ::ID2D1Brush *brush,
                ::ID2D1Brush *opacityBrush
                );

            HRESULT FillRectangleInternal(
                ::D2D1_RECT_F *rect,
                ::ID2D1Brush *brush
                );

            HRESULT PushAxisAlignedClipInternal(
                ::D2D1_RECT_F *clipRect,
                ::D2D1_ANTIALIAS_MODE antialiasMode
                );

            HRESULT PushLayerInternal(
                ::D2D1_LAYER_PARAMETERS1 *layerParameters1,
                ::ID2D1Layer *layer
                );

            HRESULT PopAxisAlignedClipInternal();

            HRESULT PopLayerInternal();

        protected:
            virtual HRESULT BeginDraw() abstract;

            virtual HRESULT EndDraw() abstract;

            virtual HRESULT SetAntialiasMode(Direct2DNet::D2D1_ANTIALIAS_MODE antialiasMode) abstract;

            virtual HRESULT SetTags(D2D1_TAG tag1, D2D1_TAG tag2) abstract;

            virtual HRESULT SetTextAntialiasMode(
                Direct2DNet::D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
            ) abstract;

            virtual HRESULT SetTextRenderingParams(
                DWriteNet::IDWriteRenderingParams ^textRenderingParams
            ) abstract;

            virtual HRESULT SetTransform(
                [In][IsReadOnly] Direct2DNet::D2D1_MATRIX_3X2_F %transform
            ) abstract;

            virtual HRESULT SetPrimitiveBlend(
                Direct2DNet::D2D1_PRIMITIVE_BLEND primitiveBlend
            ) abstract;

            virtual HRESULT SetUnitMode(
                Direct2DNet::D2D1_UNIT_MODE unitMode
            ) abstract;

            virtual HRESULT Clear(
                [In][IsReadOnly] Direct2DNet::D2D1_COLOR_F %color
            ) abstract;

            virtual HRESULT Clear() abstract;

            // DrawGlyphRun

            virtual HRESULT DrawLine(
                [In][IsReadOnly] Direct2DNet::D2D1_POINT_2F %point0,
                [In][IsReadOnly] Direct2DNet::D2D1_POINT_2F %point1,
                Direct2DNet::ID2D1Brush ^brush,
                float strokeWidth,
                [Optional] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            ) abstract;

            virtual HRESULT DrawGeometry(
                Direct2DNet::ID2D1Geometry ^geometry,
                Direct2DNet::ID2D1Brush ^brush,
                float strokeWidth,
                [Optional] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            ) abstract;

            virtual HRESULT DrawRectangle(
                [In][IsReadOnly] Direct2DNet::D2D1_RECT_F %rect,
                Direct2DNet::ID2D1Brush ^brush,
                float strokeWidth,
                [Optional] Direct2DNet::ID2D1StrokeStyle ^strokeStyle
            ) abstract;

            virtual HRESULT DrawBitmap(
                Direct2DNet::ID2D1Bitmap ^bitmap,
                float opacity,
                Direct2DNet::D2D1_INTERPOLATION_MODE interpolationMode,
                [Optional] System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
                [Optional] System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle,
                [Optional] System::Nullable<Direct2DNet::D2D1_MATRIX_4X4_F> perspectiveTransform
            ) abstract;

            virtual HRESULT DrawImage(
                Direct2DNet::ID2D1Image ^image,
                Direct2DNet::D2D1_INTERPOLATION_MODE interpolationMode,
                Direct2DNet::D2D1_COMPOSITE_MODE compositeMode,
                [Optional] System::Nullable<Direct2DNet::D2D1_POINT_2F> targetOffset,
                [Optional] System::Nullable<Direct2DNet::D2D1_RECT_F> imageRectangle
            ) abstract;

            // DrawGdiMetafile

            virtual HRESULT FillMesh(
                Direct2DNet::ID2D1Mesh ^mesh,
                Direct2DNet::ID2D1Brush ^brush
            ) abstract;

            virtual HRESULT FillOpacityMask(
                Direct2DNet::ID2D1Bitmap ^opacityMask,
                Direct2DNet::ID2D1Brush ^brush,
                [Optional] System::Nullable<Direct2DNet::D2D1_RECT_F> destinationRectangle,
                [Optional] System::Nullable<Direct2DNet::D2D1_RECT_F> sourceRectangle
            ) abstract;

            virtual HRESULT FillGeometry(
                Direct2DNet::ID2D1Geometry ^geometry,
                Direct2DNet::ID2D1Brush ^brush,
                [Optional] Direct2DNet::ID2D1Brush ^opacityBrush
            ) abstract;

            virtual HRESULT FillRectangle(
                [In][IsReadOnly] Direct2DNet::D2D1_RECT_F %rect,
                Direct2DNet::ID2D1Brush ^brush
            ) abstract;

            virtual HRESULT PushAxisAlignedClip(
                [In][IsReadOnly] Direct2DNet::D2D1_RECT_F %clipRect,
                Direct2DNet::D2D1_ANTIALIAS_MODE antialiasMode
            ) abstract;

            virtual HRESULT PushLayer(
                [In][IsReadOnly] Direct2DNet::D2D1_LAYER_PARAMETERS1 %layerParameters1,
                Direct2DNet::ID2D1Layer ^layer
            ) abstract;

            virtual HRESULT PopAxisAlignedClip() abstract;

            virtual HRESULT PopLayer() abstract;

        };
    }
}