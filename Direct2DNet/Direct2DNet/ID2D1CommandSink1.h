#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "ID2D1CommandSink.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        class ID2D1NativeCommandSink1 : public ::ID2D1CommandSink1
        {
        private:
            UINT m_cRef;

        public:
            // From ID2D1CommandSink
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

            // From ID2D1CommandSink1
            fnHrPB m_setPrimitiveBlend1;

            ID2D1NativeCommandSink1() : m_cRef(1) {}


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
                else if(__uuidof(::ID2D1CommandSink1) == iid)
                {
                    *ppvObject = static_cast<::ID2D1CommandSink1 *>(this);
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
                _In_opt_::IDWriteRenderingParams *textRenderingParams
                ) override
            {
                return m_setTextRenderingParams(textRenderingParams);
            }

            STDMETHOD(SetTransform)(
                _In_ CONST::D2D1_MATRIX_3X2_F *transform
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
                _In_opt_ CONST::D2D1_COLOR_F *color
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
                _In_::ID2D1Bitmap *bitmap,
                _In_opt_ CONST::D2D1_RECT_F *destinationRectangle,
                FLOAT opacity,
                ::D2D1_INTERPOLATION_MODE interpolationMode,
                _In_opt_ CONST::D2D1_RECT_F *sourceRectangle,
                _In_opt_ CONST::D2D1_MATRIX_4X4_F *perspectiveTransform
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
                _In_::ID2D1GdiMetafile *gdiMetafile,
                _In_opt_ CONST::D2D1_POINT_2F *targetOffset
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
                _In_::ID2D1Bitmap *opacityMask,
                _In_::ID2D1Brush *brush,
                _In_opt_ CONST::D2D1_RECT_F *destinationRectangle,
                _In_opt_ CONST::D2D1_RECT_F *sourceRectangle
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
                _In_ CONST::D2D1_RECT_F *clipRect,
                ::D2D1_ANTIALIAS_MODE antialiasMode
                ) override
            {
                return m_pushAxisAlignedClip(const_cast<::D2D1_RECT_F *>(clipRect), antialiasMode);
            }

            STDMETHOD(PushLayer)(
                _In_ CONST::D2D1_LAYER_PARAMETERS1 *layerParameters1,
                _In_opt_::ID2D1Layer *layer
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


            STDMETHOD(SetPrimitiveBlend1)(
                ::D2D1_PRIMITIVE_BLEND primitiveBlend
                ) override
            {
                return m_setPrimitiveBlend1(primitiveBlend);
            }
        };

        /// <summary>
        /// This interface performs all the same functions as the existing ID2D1CommandSink
        /// interface. It also enables access to the new primitive blend modes, MIN and ADD,
        /// through its SetPrimitiveBlend1 method.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("9eb767fd-4269-4467-b8c2-eb30cb305743")]
        public ref class ID2D1CommandSink1 abstract : Direct2DNet::ID2D1CommandSink
        {
        private:
            GCHandle m_setPrimitiveBlend1;

        protected:
            ID2D1CommandSink1();

        internal:
            ID2D1CommandSink1(System::Guid riid);

        public:
            ~ID2D1CommandSink1();

        private:
            HRESULT SetPrimitiveBlend1Internal(::D2D1_PRIMITIVE_BLEND primitiveBlend);

        protected:
            /// <summary>
            /// This method is called if primitiveBlend value was added after Windows 8.
            /// SetPrimitiveBlend method is used for Win8 values (_SOURCE_OVER and _COPY).
            /// </summary>
            virtual HRESULT SetPrimitiveBlend1(Direct2DNet::D2D1_PRIMITIVE_BLEND primitiveBlend) abstract;
        };
    }
}