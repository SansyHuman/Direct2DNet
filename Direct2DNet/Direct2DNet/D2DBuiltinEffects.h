#pragma once

#include "D2DNetHeaders.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
#ifndef D2DEFFECT_GUID
#define D2DEFFECT_GUID(name) static initonly System::Guid name
#endif

#ifndef D2DEFFECT_GET_GUID
#define D2DEFFECT_GET_GUID(name) name = D2DNet::DirectX::ToManagedGUID(:: ## name)
#endif

        /// <summary>
        /// GUID holder of all Direct2D builtin effects.
        /// </summary>
        public value struct D2DBuiltinEffects abstract sealed
        {
        public:
            D2DEFFECT_GUID(CLSID_D2D12DAffineTransform);
            D2DEFFECT_GUID(CLSID_D2D13DPerspectiveTransform);
            D2DEFFECT_GUID(CLSID_D2D13DTransform);
            D2DEFFECT_GUID(CLSID_D2D1ArithmeticComposite);
            D2DEFFECT_GUID(CLSID_D2D1Atlas);
            D2DEFFECT_GUID(CLSID_D2D1BitmapSource);
            D2DEFFECT_GUID(CLSID_D2D1Blend);
            D2DEFFECT_GUID(CLSID_D2D1Border);
            D2DEFFECT_GUID(CLSID_D2D1Brightness);
            D2DEFFECT_GUID(CLSID_D2D1ColorManagement);
            D2DEFFECT_GUID(CLSID_D2D1ColorMatrix);
            D2DEFFECT_GUID(CLSID_D2D1Composite);
            D2DEFFECT_GUID(CLSID_D2D1ConvolveMatrix);
            D2DEFFECT_GUID(CLSID_D2D1Crop);
            D2DEFFECT_GUID(CLSID_D2D1DirectionalBlur);
            D2DEFFECT_GUID(CLSID_D2D1DiscreteTransfer);
            D2DEFFECT_GUID(CLSID_D2D1DisplacementMap);
            D2DEFFECT_GUID(CLSID_D2D1DistantDiffuse);
            D2DEFFECT_GUID(CLSID_D2D1DistantSpecular);
            D2DEFFECT_GUID(CLSID_D2D1DpiCompensation);
            D2DEFFECT_GUID(CLSID_D2D1Flood);
            D2DEFFECT_GUID(CLSID_D2D1GammaTransfer);
            D2DEFFECT_GUID(CLSID_D2D1GaussianBlur);
            D2DEFFECT_GUID(CLSID_D2D1Scale);
            D2DEFFECT_GUID(CLSID_D2D1Histogram);
            D2DEFFECT_GUID(CLSID_D2D1HueRotation);
            D2DEFFECT_GUID(CLSID_D2D1LinearTransfer);
            D2DEFFECT_GUID(CLSID_D2D1LuminanceToAlpha);
            D2DEFFECT_GUID(CLSID_D2D1Morphology);
            D2DEFFECT_GUID(CLSID_D2D1OpacityMetadata);
            D2DEFFECT_GUID(CLSID_D2D1PointDiffuse);
            D2DEFFECT_GUID(CLSID_D2D1PointSpecular);
            D2DEFFECT_GUID(CLSID_D2D1Premultiply);
            D2DEFFECT_GUID(CLSID_D2D1Saturation);
            D2DEFFECT_GUID(CLSID_D2D1Shadow);
            D2DEFFECT_GUID(CLSID_D2D1SpotDiffuse);
            D2DEFFECT_GUID(CLSID_D2D1SpotSpecular);
            D2DEFFECT_GUID(CLSID_D2D1TableTransfer);
            D2DEFFECT_GUID(CLSID_D2D1Tile);
            D2DEFFECT_GUID(CLSID_D2D1Turbulence);
            D2DEFFECT_GUID(CLSID_D2D1UnPremultiply);

            D2DEFFECT_GUID(CLSID_D2D1Contrast);
            D2DEFFECT_GUID(CLSID_D2D1RgbToHue);
            D2DEFFECT_GUID(CLSID_D2D1HueToRgb);
            D2DEFFECT_GUID(CLSID_D2D1ChromaKey);
            D2DEFFECT_GUID(CLSID_D2D1Emboss);
            D2DEFFECT_GUID(CLSID_D2D1Exposure);
            D2DEFFECT_GUID(CLSID_D2D1Grayscale);
            D2DEFFECT_GUID(CLSID_D2D1Invert);
            D2DEFFECT_GUID(CLSID_D2D1Posterize);
            D2DEFFECT_GUID(CLSID_D2D1Sepia);
            D2DEFFECT_GUID(CLSID_D2D1Sharpen);
            D2DEFFECT_GUID(CLSID_D2D1Straighten);
            D2DEFFECT_GUID(CLSID_D2D1TemperatureTint);
            D2DEFFECT_GUID(CLSID_D2D1Vignette);
            D2DEFFECT_GUID(CLSID_D2D1EdgeDetection);
            D2DEFFECT_GUID(CLSID_D2D1HighlightsShadows);
            D2DEFFECT_GUID(CLSID_D2D1LookupTable3D);
            D2DEFFECT_GUID(CLSID_D2D1Opacity);
            D2DEFFECT_GUID(CLSID_D2D1AlphaMask);
            D2DEFFECT_GUID(CLSID_D2D1CrossFade);
            D2DEFFECT_GUID(CLSID_D2D1Tint);
            D2DEFFECT_GUID(CLSID_D2D1WhiteLevelAdjustment);
            D2DEFFECT_GUID(CLSID_D2D1HdrToneMap);

            static D2DBuiltinEffects()
            {
                D2DEFFECT_GET_GUID(CLSID_D2D12DAffineTransform);
                D2DEFFECT_GET_GUID(CLSID_D2D13DPerspectiveTransform);
                D2DEFFECT_GET_GUID(CLSID_D2D13DTransform);
                D2DEFFECT_GET_GUID(CLSID_D2D1ArithmeticComposite);
                D2DEFFECT_GET_GUID(CLSID_D2D1Atlas);
                D2DEFFECT_GET_GUID(CLSID_D2D1BitmapSource);
                D2DEFFECT_GET_GUID(CLSID_D2D1Blend);
                D2DEFFECT_GET_GUID(CLSID_D2D1Border);
                D2DEFFECT_GET_GUID(CLSID_D2D1Brightness);
                D2DEFFECT_GET_GUID(CLSID_D2D1ColorManagement);
                D2DEFFECT_GET_GUID(CLSID_D2D1ColorMatrix);
                D2DEFFECT_GET_GUID(CLSID_D2D1Composite);
                D2DEFFECT_GET_GUID(CLSID_D2D1ConvolveMatrix);
                D2DEFFECT_GET_GUID(CLSID_D2D1Crop);
                D2DEFFECT_GET_GUID(CLSID_D2D1DirectionalBlur);
                D2DEFFECT_GET_GUID(CLSID_D2D1DiscreteTransfer);
                D2DEFFECT_GET_GUID(CLSID_D2D1DisplacementMap);
                D2DEFFECT_GET_GUID(CLSID_D2D1DistantDiffuse);
                D2DEFFECT_GET_GUID(CLSID_D2D1DistantSpecular);
                D2DEFFECT_GET_GUID(CLSID_D2D1DpiCompensation);
                D2DEFFECT_GET_GUID(CLSID_D2D1Flood);
                D2DEFFECT_GET_GUID(CLSID_D2D1GammaTransfer);
                D2DEFFECT_GET_GUID(CLSID_D2D1GaussianBlur);
                D2DEFFECT_GET_GUID(CLSID_D2D1Scale);
                D2DEFFECT_GET_GUID(CLSID_D2D1Histogram);
                D2DEFFECT_GET_GUID(CLSID_D2D1HueRotation);
                D2DEFFECT_GET_GUID(CLSID_D2D1LinearTransfer);
                D2DEFFECT_GET_GUID(CLSID_D2D1LuminanceToAlpha);
                D2DEFFECT_GET_GUID(CLSID_D2D1Morphology);
                D2DEFFECT_GET_GUID(CLSID_D2D1OpacityMetadata);
                D2DEFFECT_GET_GUID(CLSID_D2D1PointDiffuse);
                D2DEFFECT_GET_GUID(CLSID_D2D1PointSpecular);
                D2DEFFECT_GET_GUID(CLSID_D2D1Premultiply);
                D2DEFFECT_GET_GUID(CLSID_D2D1Saturation);
                D2DEFFECT_GET_GUID(CLSID_D2D1Shadow);
                D2DEFFECT_GET_GUID(CLSID_D2D1SpotDiffuse);
                D2DEFFECT_GET_GUID(CLSID_D2D1SpotSpecular);
                D2DEFFECT_GET_GUID(CLSID_D2D1TableTransfer);
                D2DEFFECT_GET_GUID(CLSID_D2D1Tile);
                D2DEFFECT_GET_GUID(CLSID_D2D1Turbulence);
                D2DEFFECT_GET_GUID(CLSID_D2D1UnPremultiply);

                D2DEFFECT_GET_GUID(CLSID_D2D1Contrast);
                D2DEFFECT_GET_GUID(CLSID_D2D1RgbToHue);
                D2DEFFECT_GET_GUID(CLSID_D2D1HueToRgb);
                D2DEFFECT_GET_GUID(CLSID_D2D1ChromaKey);
                D2DEFFECT_GET_GUID(CLSID_D2D1Emboss);
                D2DEFFECT_GET_GUID(CLSID_D2D1Exposure);
                D2DEFFECT_GET_GUID(CLSID_D2D1Grayscale);
                D2DEFFECT_GET_GUID(CLSID_D2D1Invert);
                D2DEFFECT_GET_GUID(CLSID_D2D1Posterize);
                D2DEFFECT_GET_GUID(CLSID_D2D1Sepia);
                D2DEFFECT_GET_GUID(CLSID_D2D1Sharpen);
                D2DEFFECT_GET_GUID(CLSID_D2D1Straighten);
                D2DEFFECT_GET_GUID(CLSID_D2D1TemperatureTint);
                D2DEFFECT_GET_GUID(CLSID_D2D1Vignette);
                D2DEFFECT_GET_GUID(CLSID_D2D1EdgeDetection);
                D2DEFFECT_GET_GUID(CLSID_D2D1HighlightsShadows);
                D2DEFFECT_GET_GUID(CLSID_D2D1LookupTable3D);
                D2DEFFECT_GET_GUID(CLSID_D2D1Opacity);
                D2DEFFECT_GET_GUID(CLSID_D2D1AlphaMask);
                D2DEFFECT_GET_GUID(CLSID_D2D1CrossFade);
                D2DEFFECT_GET_GUID(CLSID_D2D1Tint);
                D2DEFFECT_GET_GUID(CLSID_D2D1WhiteLevelAdjustment);
                D2DEFFECT_GET_GUID(CLSID_D2D1HdrToneMap);
            }
        };


    }
}