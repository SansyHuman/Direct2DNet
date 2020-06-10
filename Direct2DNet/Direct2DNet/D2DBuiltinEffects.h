#pragma once

#include "D2DNetHeaders.h"
#include "../DXCommonSettings.h"

namespace D2DNet
{

namespace Direct2DNet
{
    namespace Effects
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

            D2DEFFECT_GUID(CLSID_D2D1YCbCr);

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

                D2DEFFECT_GET_GUID(CLSID_D2D1YCbCr);

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

        /// <summary>
        /// Specifies how the Crop effect handles the crop rectangle falling on fractional
        /// pixel coordinates.
        /// </summary>
        public enum class D2D1_BORDER_MODE : unsigned int
        {
            /// <summary>
            /// If the crop rectangle falls on fractional pixel coordinates, the effect applies
            /// antialiasing which results in a soft edge.
            /// </summary>
            SOFT = 0,

            /// <summary>
            /// If the crop rectangle falls on fractional pixel coordinates, the effect clamps which
            /// results in a hard edge.
            /// </summary>
            HARD = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies the color channel the Displacement map effect extracts the intensity
        /// from and uses it to spatially displace the image in the X or Y direction.
        /// </summary>
        public enum class D2D1_CHANNEL_SELECTOR : unsigned int
        {
            /// <summary>
            /// The effect extracts the intensity output from the red channel.
            /// </summary>
            R = 0,

            /// <summary>
            /// The effect extracts the intensity output from the green channel.
            /// </summary>
            G = 1,

            /// <summary>
            /// The effect extracts the intensity output from the blue channel.
            /// </summary>
            B = 2,

            /// <summary>
            /// The effect extracts the intensity output from the alpha channel.
            /// </summary>
            A = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Speficies whether a flip and/or rotation operation should be performed by the
        /// Bitmap source effect
        /// </summary>
        public enum class D2D1_BITMAPSOURCE_ORIENTATION : unsigned int
        {
            /// <summary>
            /// The effect doesn't change the orientation of the input.
            /// </summary>
            DEFAULT = 1,

            /// <summary>
            /// Flips the image horizontally.
            /// </summary>
            FLIP_HORIZONTAL = 2,

            /// <summary>
            /// Rotates the image clockwise 180 degrees.
            /// </summary>
            ROTATE_CLOCKWISE180 = 3,

            /// <summary>
            /// Rotates the image clockwise 180 degrees and flips it horizontally.
            /// </summary>
            ROTATE_CLOCKWISE180_FLIP_HORIZONTAL = 4,

            /// <summary>
            /// Rotates the image clockwise 270 degrees and flips it horizontally.
            /// </summary>
            ROTATE_CLOCKWISE270_FLIP_HORIZONTAL = 5,

            /// <summary>
            /// Rotates the image clockwise 90 degrees.
            /// </summary>
            ROTATE_CLOCKWISE90 = 6,

            /// <summary>
            /// Rotates the image clockwise 90 degrees and flips it horizontally.
            /// </summary>
            ROTATE_CLOCKWISE90_FLIP_HORIZONTAL = 7,

            /// <summary>
            /// Rotates the image clockwise 270 degrees.
            /// </summary>
            ROTATE_CLOCKWISE270 = 8,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Gaussian Blur effect's top level properties.
        /// Effect description: Applies a gaussian blur to a bitmap with the specified blur
        /// radius and angle.
        /// </summary>
        public enum class D2D1_GAUSSIANBLUR_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "StandardDeviation"
            /// Property Type: FLOAT
            /// </summary>
            STANDARD_DEVIATION = 0,

            /// <summary>
            /// Property Name: "Optimization"
            /// Property Type: D2D1_GAUSSIANBLUR_OPTIMIZATION
            /// </summary>
            OPTIMIZATION = 1,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The optimization mode for the Gaussian blur effect.
        /// </summary>
        public enum class D2D1_GAUSSIANBLUR_OPTIMIZATION : unsigned int
        {
            /// <summary>
            /// Applies internal optimizations such as pre-scaling at relatively small radii.
            /// Uses linear filtering.
            /// </summary>
            SPEED = 0,

            /// <summary>
            /// Uses the same optimization thresholds as Speed mode, but uses trilinear filtering.
            /// </summary>
            BALANCED = 1,

            /// <summary>
            /// Only uses internal optimizations with large blur radii, where approximations are less
            /// likely to be visible. Uses trilinear filtering.
            /// </summary>
            QUALITY = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Directional Blur effect's top level properties.
        /// Effect description: Applies a directional blur to a bitmap with the specified
        /// blur radius and angle.
        /// </summary>
        public enum class D2D1_DIRECTIONALBLUR_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "StandardDeviation"
            /// Property Type: FLOAT
            /// </summary>
            STANDARD_DEVIATION = 0,

            /// <summary>
            /// Property Name: "Angle"
            /// Property Type: FLOAT
            /// </summary>
            ANGLE = 1,

            /// <summary>
            /// Property Name: "Optimization"
            /// Property Type: D2D1_DIRECTIONALBLUR_OPTIMIZATION
            /// </summary>
            OPTIMIZATION = 2,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies the optimization mode for the Directional blur effect.
        /// </summary>
        public enum class D2D1_DIRECTIONALBLUR_OPTIMIZATION : unsigned int
        {
            /// <summary>
            /// Applies internal optimizations such as pre-scaling at relatively small radii.
            /// Uses linear filtering.
            /// </summary>
            SPEED = 0,

            /// <summary>
            /// Uses the same optimization thresholds as Speed mode, but uses trilinear filtering.
            /// </summary>
            BALANCED = 1,

            /// <summary>
            /// Only uses internal optimizations with large blur radii, where approximations are less
            /// likely to be visible. Uses trilinear filtering.
            /// </summary>
            QUALITY = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Shadow effect's top level properties.
        /// Effect description: Applies a shadow to a bitmap based on its alpha channel.
        /// </summary>
        public enum class D2D1_SHADOW_PROP : unsigned int
        {

            /// <summary>
            /// Property Name: "BlurStandardDeviation"
            /// Property Type: FLOAT
            /// </summary>
            BLUR_STANDARD_DEVIATION = 0,

            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            COLOR = 1,

            /// <summary>
            /// Property Name: "Optimization"
            /// Property Type: D2D1_SHADOW_OPTIMIZATION
            /// </summary>
            OPTIMIZATION = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The level of performance optimization for the Shadow effect.
        /// </summary>
        public enum class D2D1_SHADOW_OPTIMIZATION : unsigned int
        {
            /// <summary>
            /// Applies internal optimizations such as pre-scaling at relatively small radii.
            /// Uses linear filtering.
            /// </summary>
            SPEED = 0,

            /// <summary>
            /// Uses the same optimization thresholds as Speed mode, but uses trilinear filtering.
            /// </summary>
            BALANCED = 1,

            /// <summary>
            /// Only uses internal optimizations with large blur radii, where approximations are less
            /// likely to be visible. Uses trilinear filtering.
            /// </summary>
            QUALITY = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Blend effect's top level properties.
        /// Effect description: Blends a foreground and background using a pre-defined blend
        /// mode.
        /// </summary>
        public enum class D2D1_BLEND_PROP : unsigned int
        {

            /// <summary>
            /// Property Name: "Mode"
            /// Property Type: D2D1_BLEND_MODE
            /// </summary>
            MODE = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

#ifdef DIFFERENCE
#undef DIFFERENCE
#endif

        /// <summary>
        /// The blend mode used for the Blend effect.
        /// </summary>
        public enum class D2D1_BLEND_MODE : unsigned int
        {
            MULTIPLY = 0,
            SCREEN = 1,
            DARKEN = 2,
            LIGHTEN = 3,
            DISSOLVE = 4,
            COLOR_BURN = 5,
            LINEAR_BURN = 6,
            DARKER_COLOR = 7,
            LIGHTER_COLOR = 8,
            COLOR_DODGE = 9,
            LINEAR_DODGE = 10,
            OVERLAY = 11,
            SOFT_LIGHT = 12,
            HARD_LIGHT = 13,
            VIVID_LIGHT = 14,
            LINEAR_LIGHT = 15,
            PIN_LIGHT = 16,
            HARD_MIX = 17,
            DIFFERENCE = 18,
            EXCLUSION = 19,
            HUE = 20,
            SATURATION = 21,
            COLOR = 22,
            LUMINOSITY = 23,
            SUBTRACT = 24,
            DIVISION = 25,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

#ifndef DIFFERENCE
#define DIFFERENCE     11
#endif

        /// <summary>
        /// The enumeration of the Saturation effect's top level properties.
        /// Effect description: Alters the saturation of the bitmap based on the user
        /// specified saturation value.
        /// </summary>
        public enum class D2D1_SATURATION_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Saturation"
            /// Property Type: FLOAT
            /// </summary>
            SATURATION = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Hue Rotation effect's top level properties.
        /// Effect description: Changes the Hue of a bitmap based on a user specified Hue
        /// Rotation angle.
        /// </summary>
        public enum class D2D1_HUEROTATION_PROP : unsigned int
        {

            /// <summary>
            /// Property Name: "Angle"
            /// Property Type: FLOAT
            /// </summary>
            ANGLE = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Color Matrix effect's top level properties.
        /// Effect description: Applies a user specified color matrix to each channel of the
        /// input bitmap.
        /// </summary>
        public enum class D2D1_COLORMATRIX_PROP : unsigned int
        {

            /// <summary>
            /// Property Name: "ColorMatrix"
            /// Property Type: D2D1_MATRIX_5X4_F
            /// </summary>
            COLOR_MATRIX = 0,

            /// <summary>
            /// Property Name: "AlphaMode"
            /// Property Type: D2D1_COLORMATRIX_ALPHA_MODE
            /// </summary>
            ALPHA_MODE = 1,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The alpha mode of the output of the Color matrix effect.
        /// </summary>
        public enum class D2D1_COLORMATRIX_ALPHA_MODE : unsigned int
        {
            /// <summary>
            /// The effect un-premultiplies the input, applies the color matrix, and premultiplies the output.
            /// </summary>
            PREMULTIPLIED = 1,

            /// <summary>
            /// The effect applies the color matrix directly to the input, and doesn't premultiply the output.
            /// </summary>
            STRAIGHT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Bitmap Source effect's top level properties.
        /// Effect description: Provides an image source.
        /// </summary>
        public enum class D2D1_BITMAPSOURCE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "WicBitmapSource"
            /// Property Type: IUnknown *
            /// </summary>
            WIC_BITMAP_SOURCE = 0,

            /// <summary>
            /// Property Name: "Scale"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            SCALE = 1,

            /// <summary>
            /// Property Name: "InterpolationMode"
            /// Property Type: D2D1_BITMAPSOURCE_INTERPOLATION_MODE
            /// </summary>
            INTERPOLATION_MODE = 2,

            /// <summary>
            /// Property Name: "EnableDPICorrection"
            /// Property Type: BOOL
            /// </summary>
            ENABLE_DPI_CORRECTION = 3,

            /// <summary>
            /// Property Name: "AlphaMode"
            /// Property Type: D2D1_BITMAPSOURCE_ALPHA_MODE
            /// </summary>
            ALPHA_MODE = 4,

            /// <summary>
            /// Property Name: "Orientation"
            /// Property Type: D2D1_BITMAPSOURCE_ORIENTATION
            /// </summary>
            ORIENTATION = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode used to scale the image in the Bitmap source effect.
        /// If the mode disables the mipmap, then BitmapSouce will cache the image at the resolution
        /// determined by the Scale and EnableDPICorrection properties.
        /// </summary>
        public enum class D2D1_BITMAPSOURCE_INTERPOLATION_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. Doesn't generate a mipmap.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. Doesn't generate a mipmap.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. Doesn't generate a mipmap.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses the WIC fant interpolation, the same as the IWICBitmapScaler interface.
            /// Doesn't generate a mipmap.
            /// </summary>
            FANT = 6,

            /// <summary>
            /// Generates mipmap chain in system memory using bilinear interpolation.
            /// For each mipmap the effect scales to the nearest multiple of 0.5 using bilinear
            /// interpolation and then scales the remaining amount using linear interpolation.
            /// </summary>
            MIPMAP_LINEAR = 7,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies the alpha mode of the output of the Bitmap source effect.
        /// </summary>
        public enum class D2D1_BITMAPSOURCE_ALPHA_MODE : unsigned int
        {
            /// <summary>
            /// The effect output uses premultiplied alpha.
            /// </summary>
            PREMULTIPLIED = 1,

            /// <summary>
            /// The effect output uses straight alpha.
            /// </summary>
            STRAIGHT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Composite effect's top level properties.
        /// Effect description: Composites foreground and background images using the
        /// selected composition mode.
        /// </summary>
        public enum class D2D1_COMPOSITE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Mode"
            /// Property Type: D2D1_COMPOSITE_MODE
            /// </summary>
            MODE = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the 3D Transform effect's top level properties.
        /// Effect description: Applies a 3D transform to a bitmap.
        /// </summary>
        public enum class D2D1_3DTRANSFORM_PROP : unsigned int
        {

            /// <summary>
            /// Property Name: "InterpolationMode"
            /// Property Type: D2D1_3DTRANSFORM_INTERPOLATION_MODE
            /// </summary>
            INTERPOLATION_MODE = 0,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 1,

            /// <summary>
            /// Property Name: "TransformMatrix"
            /// Property Type: D2D1_MATRIX_4X4_F
            /// </summary>
            TRANSFORM_MATRIX = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the 3D transform effect uses on the image.
        /// There are 5 scale modes that range in quality and speed.
        /// </summary>
        public enum class D2D1_3DTRANSFORM_INTERPOLATION_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode uses more processing
            /// time than the nearest neighbor mode, but outputs a higher quality image.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is
            /// good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape
            /// of the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the 3D Perspective Transform effect's top level properties.
        /// Effect description: Applies a 3D perspective transform to a bitmap.
        /// </summary>
        public enum class D2D1_3DPERSPECTIVETRANSFORM_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "InterpolationMode"
            /// Property Type: D2D1_3DPERSPECTIVETRANSFORM_INTERPOLATION_MODE
            /// </summary>
            INTERPOLATION_MODE = 0,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 1,

            /// <summary>
            /// Property Name: "Depth"
            /// Property Type: FLOAT
            /// </summary>
            DEPTH = 2,

            /// <summary>
            /// Property Name: "PerspectiveOrigin"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            PERSPECTIVE_ORIGIN = 3,

            /// <summary>
            /// Property Name: "LocalOffset"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            LOCAL_OFFSET = 4,

            /// <summary>
            /// Property Name: "GlobalOffset"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            GLOBAL_OFFSET = 5,

            /// <summary>
            /// Property Name: "RotationOrigin"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            ROTATION_ORIGIN = 6,

            /// <summary>
            /// Property Name: "Rotation"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            ROTATION = 7,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the 3D perspective transform effect uses on the image.
        /// There are 5 scale modes that range in quality and speed.
        /// </summary>
        public enum class D2D1_3DPERSPECTIVETRANSFORM_INTERPOLATION_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode uses more processing
            /// time than the nearest neighbor mode, but outputs a higher quality image.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing.
            /// This mode is good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape
            /// of the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the 2D Affine Transform effect's top level properties.
        /// Effect description: Applies a 2D affine transform to a bitmap.
        /// </summary>
        public enum class D2D1_2DAFFINETRANSFORM_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "InterpolationMode"
            /// Property Type: D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE
            /// </summary>
            INTERPOLATION_MODE = 0,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 1,

            /// <summary>
            /// Property Name: "TransformMatrix"
            /// Property Type: D2D1_MATRIX_3X2_F
            /// </summary>
            TRANSFORM_MATRIX = 2,

            /// <summary>
            /// Property Name: "Sharpness"
            /// Property Type: FLOAT
            /// </summary>
            SHARPNESS = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the 2D Affine Transform effect's top level properties.
        /// Effect description: Applies a 2D affine transform to a bitmap.
        /// </summary>
        public enum class D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode uses more processing
            /// time than the nearest neighbor mode, but outputs a higher quality image.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing.
            /// This mode is good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape
            /// of the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the DPI Compensation effect's top level properties.
        /// Effect description: Scales according to the input DPI and the current context
        /// DPI
        /// </summary>
        public enum class D2D1_DPICOMPENSATION_PROP : unsigned int
        {

            /// <summary>
            /// Property Name: "InterpolationMode"
            /// Property Type: D2D1_DPICOMPENSATION_INTERPOLATION_MODE
            /// </summary>
            INTERPOLATION_MODE = 0,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 1,

            /// <summary>
            /// Property Name: "InputDpi"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            INPUT_DPI = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the DPI compensation effect uses to scale the image.
        /// </summary>
        public enum class D2D1_DPICOMPENSATION_INTERPOLATION_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode uses more processing
            /// time than the nearest neighbor mode, but outputs a higher quality image.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing.
            /// This mode is good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape
            /// of the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Scale effect's top level properties.
        /// Effect description: Applies scaling operation to the bitmap.
        /// </summary>
        public enum class D2D1_SCALE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Scale"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            SCALE = 0,

            /// <summary>
            /// Property Name: "CenterPoint"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            CENTER_POINT = 1,

            /// <summary>
            /// Property Name: "InterpolationMode"
            /// Property Type: D2D1_SCALE_INTERPOLATION_MODE
            /// </summary>
            INTERPOLATION_MODE = 2,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 3,

            /// <summary>
            /// Property Name: "Sharpness"
            /// Property Type: FLOAT
            /// </summary>
            SHARPNESS = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the Scale effect uses to scale the image. There are 6 scale modes
        /// that range in quality and speed.
        /// </summary>
        public enum class D2D1_SCALE_INTERPOLATION_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode uses more processing
            /// time than the nearest neighbor mode, but outputs a higher quality image.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing.
            /// This mode is good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape
            /// of the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Turbulence effect's top level properties.
        /// Effect description: Generates a bitmap based on the Perlin noise turbulence
        /// function.
        /// </summary>
        public enum class D2D1_TURBULENCE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Offset"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            OFFSET = 0,

            /// <summary>
            /// Property Name: "Size"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            SIZE = 1,

            /// <summary>
            /// Property Name: "BaseFrequency"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            BASE_FREQUENCY = 2,

            /// <summary>
            /// Property Name: "NumOctaves"
            /// Property Type: UINT32
            /// </summary>
            NUM_OCTAVES = 3,

            /// <summary>
            /// Property Name: "Seed"
            /// Property Type: INT32
            /// </summary>
            SEED = 4,

            /// <summary>
            /// Property Name: "Noise"
            /// Property Type: D2D1_TURBULENCE_NOISE
            /// </summary>
            NOISE = 5,

            /// <summary>
            /// Property Name: "Stitchable"
            /// Property Type: BOOL
            /// </summary>
            STITCHABLE = 6,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The turbulence noise mode for the Turbulence effect. Indicates whether to generate a bitmap
        /// based on Fractal Noise or the Turbulence function.
        /// </summary>
        public enum class D2D1_TURBULENCE_NOISE : unsigned int
        {
            /// <summary>
            /// Computes a sum of the octaves, shifting the output range from [-1, 1], to [0, 1].
            /// </summary>
            FRACTAL_SUM = 0,

            /// <summary>
            /// Computes a sum of the absolute value of each octave.
            /// </summary>
            TURBULENCE = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Displacement Map effect's top level properties.
        /// Effect description: Displaces a bitmap based on user specified setting and
        /// another bitmap.
        /// </summary>
        public enum class D2D1_DISPLACEMENTMAP_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Scale"
            /// Property Type: FLOAT
            /// </summary>
            SCALE = 0,

            /// <summary>
            /// Property Name: "XChannelSelect"
            /// Property Type: D2D1_CHANNEL_SELECTOR
            /// </summary>
            X_CHANNEL_SELECT = 1,

            /// <summary>
            /// Property Name: "YChannelSelect"
            /// Property Type: D2D1_CHANNEL_SELECTOR
            /// </summary>
            Y_CHANNEL_SELECT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Color Management effect's top level properties.
        /// Effect description: Changes colors based on user provided color contexts.
        /// </summary>
        public enum class D2D1_COLORMANAGEMENT_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "SourceColorContext"
            /// Property Type: ID2D1ColorContext *
            /// </summary>
            SOURCE_COLOR_CONTEXT = 0,

            /// <summary>
            /// Property Name: "SourceRenderingIntent"
            /// Property Type: D2D1_COLORMANAGEMENT_RENDERING_INTENT
            /// </summary>
            SOURCE_RENDERING_INTENT = 1,

            /// <summary>
            /// Property Name: "DestinationColorContext"
            /// Property Type: ID2D1ColorContext *
            /// </summary>
            DESTINATION_COLOR_CONTEXT = 2,

            /// <summary>
            /// Property Name: "DestinationRenderingIntent"
            /// Property Type: D2D1_COLORMANAGEMENT_RENDERING_INTENT
            /// </summary>
            DESTINATION_RENDERING_INTENT = 3,

            /// <summary>
            /// Property Name: "AlphaMode"
            /// Property Type: D2D1_COLORMANAGEMENT_ALPHA_MODE
            /// </summary>
            ALPHA_MODE = 4,

            /// <summary>
            /// Property Name: "Quality"
            /// Property Type: D2D1_COLORMANAGEMENT_QUALITY
            /// </summary>
            QUALITY = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Indicates how the Color management effect should interpret alpha data that is contained
        /// in the input image.
        /// </summary>
        public enum class D2D1_COLORMANAGEMENT_ALPHA_MODE : unsigned int
        {
            /// <summary>
            /// The effect assumes the alpha mode is premultiplied.
            /// </summary>
            PREMULTIPLIED = 1,

            /// <summary>
            /// The effect assumes the alpha mode is straight.
            /// </summary>
            STRAIGHT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The quality level of the transform for the Color management effect.
        /// </summary>
        public enum class D2D1_COLORMANAGEMENT_QUALITY : unsigned int
        {
            /// <summary>
            /// The lowest quality mode. This mode requires feature level 9_1 or above.
            /// </summary>
            PROOF = 0,

            /// <summary>
            /// Normal quality mode. This mode requires feature level 9_1 or above.
            /// </summary>
            NORMAL = 1,

            /// <summary>
            /// The best quality mode. This mode requires feature level 10_0 or above, as well as
            /// floating point precision buffers. This mode supports floating point precision as well
            /// as extended range as defined in the ICC v4.3 specification.
            /// </summary>
            BEST = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies which ICC rendering intent the Color management effect should use.
        /// </summary>
        public enum class D2D1_COLORMANAGEMENT_RENDERING_INTENT : unsigned int
        {
            /// <summary>
            /// The effect compresses or expands the full color gamut of the image to fill the color gamut
            /// of the device, so that gray balance is preserved but colorimetric accuracy may not be
            /// preserved.
            /// </summary>
            PERCEPTUAL = 0,

            /// <summary>
            /// The effect preserves the chroma of colors in the image at the possible expense of
            /// hue and lightness.
            /// </summary>
            RELATIVE_COLORIMETRIC = 1,

            /// <summary>
            /// The effect adjusts colors that fall outside the range of colors the output device renders
            /// to the closest color available. It does not preserve the white point.
            /// </summary>
            SATURATION = 2,

            /// <summary>
            /// The effect adjusts any colors that fall outside the range that the output device can render
            /// to the closest color that can be rendered. The effect does not change the other colors
            /// and preserves the white point.
            /// </summary>
            ABSOLUTE_COLORIMETRIC = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Histogram effect's top level properties.
        /// Effect description: Computes the histogram of an image.
        /// </summary>
        public enum class D2D1_HISTOGRAM_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "NumBins"
            /// Property Type: UINT32
            /// </summary>
            NUM_BINS = 0,

            /// <summary>
            /// Property Name: "ChannelSelect"
            /// Property Type: D2D1_CHANNEL_SELECTOR
            /// </summary>
            CHANNEL_SELECT = 1,

            /// <summary>
            /// Property Name: "HistogramOutput"
            /// Property Type: FLOAT[](blob)
            /// </summary>
            HISTOGRAM_OUTPUT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Point-Specular effect's top level properties.
        /// Effect description: Creates a specular lighting effect with a point light
        /// source.
        /// </summary>
        public enum class D2D1_POINTSPECULAR_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "LightPosition"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            LIGHT_POSITION = 0,

            /// <summary>
            /// Property Name: "SpecularExponent"
            /// Property Type: FLOAT
            /// </summary>
            SPECULAR_EXPONENT = 1,

            /// <summary>
            /// Property Name: "SpecularConstant"
            /// Property Type: FLOAT
            /// </summary>
            SPECULAR_CONSTANT = 2,

            /// <summary>
            /// Property Name: "SurfaceScale"
            /// Property Type: FLOAT
            /// </summary>
            SURFACE_SCALE = 3,

            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            COLOR = 4,

            /// <summary>
            /// Property Name: "KernelUnitLength"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_UNIT_LENGTH = 5,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_POINTSPECULAR_SCALE_MODE
            /// </summary>
            SCALE_MODE = 6,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the Point-specular lighting effect uses to scale the image to
        /// the corresponding kernel unit length. There are six scale modes that range in quality and speed.
        /// </summary>
        public enum class D2D1_POINTSPECULAR_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode outputs a higher quality
            /// image than nearest neighbor.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is
            /// good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape
            /// of the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Spot-Specular effect's top level properties.
        /// Effect description: Creates a specular lighting effect with a spot light source.
        /// </summary>
        public enum class D2D1_SPOTSPECULAR_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "LightPosition"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            LIGHT_POSITION = 0,

            /// <summary>
            /// Property Name: "PointsAt"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            POINTS_AT = 1,

            /// <summary>
            /// Property Name: "Focus"
            /// Property Type: FLOAT
            /// </summary>
            FOCUS = 2,

            /// <summary>
            /// Property Name: "LimitingConeAngle"
            /// Property Type: FLOAT
            /// </summary>
            LIMITING_CONE_ANGLE = 3,

            /// <summary>
            /// Property Name: "SpecularExponent"
            /// Property Type: FLOAT
            /// </summary>
            SPECULAR_EXPONENT = 4,

            /// <summary>
            /// Property Name: "SpecularConstant"
            /// Property Type: FLOAT
            /// </summary>
            SPECULAR_CONSTANT = 5,

            /// <summary>
            /// Property Name: "SurfaceScale"
            /// Property Type: FLOAT
            /// </summary>
            SURFACE_SCALE = 6,

            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            COLOR = 7,

            /// <summary>
            /// Property Name: "KernelUnitLength"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_UNIT_LENGTH = 8,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_SPOTSPECULAR_SCALE_MODE
            /// </summary>
            SCALE_MODE = 9,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the Spot-specular lighting effect uses to scale the image to the
        /// corresponding kernel unit length. There are six scale modes that range in quality and speed.
        /// </summary>
        public enum class D2D1_SPOTSPECULAR_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode outputs a higher quality
            /// image than nearest neighbor.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is
            /// good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape of
            /// the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Distant-Specular effect's top level properties.
        /// Effect description: Creates a specular lighting effect with a distant light
        /// source.
        /// </summary>
        public enum class D2D1_DISTANTSPECULAR_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Azimuth"
            /// Property Type: FLOAT
            /// </summary>
            AZIMUTH = 0,

            /// <summary>
            /// Property Name: "Elevation"
            /// Property Type: FLOAT
            /// </summary>
            ELEVATION = 1,

            /// <summary>
            /// Property Name: "SpecularExponent"
            /// Property Type: FLOAT
            /// </summary>
            SPECULAR_EXPONENT = 2,

            /// <summary>
            /// Property Name: "SpecularConstant"
            /// Property Type: FLOAT
            /// </summary>
            SPECULAR_CONSTANT = 3,

            /// <summary>
            /// Property Name: "SurfaceScale"
            /// Property Type: FLOAT
            /// </summary>
            SURFACE_SCALE = 4,

            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            COLOR = 5,

            /// <summary>
            /// Property Name: "KernelUnitLength"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_UNIT_LENGTH = 6,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_DISTANTSPECULAR_SCALE_MODE
            /// </summary>
            SCALE_MODE = 7,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Distant-Specular effect's top level properties.
        /// Effect description: Creates a specular lighting effect with a distant light
        /// source.
        /// </summary>
        public enum class D2D1_DISTANTSPECULAR_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode outputs a higher quality
            /// image than nearest neighbor.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is
            /// good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape of
            /// the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Point-Diffuse effect's top level properties.
        /// Effect description: Creates a diffuse lighting effect with a point light source.
        /// </summary>
        public enum class D2D1_POINTDIFFUSE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "LightPosition"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            LIGHT_POSITION = 0,

            /// <summary>
            /// Property Name: "DiffuseConstant"
            /// Property Type: FLOAT
            /// </summary>
            DIFFUSE_CONSTANT = 1,

            /// <summary>
            /// Property Name: "SurfaceScale"
            /// Property Type: FLOAT
            /// </summary>
            SURFACE_SCALE = 2,

            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            COLOR = 3,

            /// <summary>
            /// Property Name: "KernelUnitLength"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_UNIT_LENGTH = 4,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_POINTDIFFUSE_SCALE_MODE
            /// </summary>
            SCALE_MODE = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the Point-diffuse lighting effect uses to scale the image to the
        /// corresponding kernel unit length. There are six scale modes that range in quality and speed
        /// </summary>
        public enum class D2D1_POINTDIFFUSE_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode outputs a higher quality
            /// image than nearest neighbor.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is
            /// good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape of
            /// the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Spot-Diffuse effect's top level properties.
        /// Effect description: Creates a diffuse lighting effect with a spot light source.
        /// </summary>
        public enum class D2D1_SPOTDIFFUSE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "LightPosition"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            LIGHT_POSITION = 0,

            /// <summary>
            /// Property Name: "PointsAt"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            POINTS_AT = 1,

            /// <summary>
            /// Property Name: "Focus"
            /// Property Type: FLOAT
            /// </summary>
            FOCUS = 2,

            /// <summary>
            /// Property Name: "LimitingConeAngle"
            /// Property Type: FLOAT
            /// </summary>
            LIMITING_CONE_ANGLE = 3,

            /// <summary>
            /// Property Name: "DiffuseConstant"
            /// Property Type: FLOAT
            /// </summary>
            DIFFUSE_CONSTANT = 4,

            /// <summary>
            /// Property Name: "SurfaceScale"
            /// Property Type: FLOAT
            /// </summary>
            SURFACE_SCALE = 5,

            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            COLOR = 6,

            /// <summary>
            /// Property Name: "KernelUnitLength"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_UNIT_LENGTH = 7,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_SPOTDIFFUSE_SCALE_MODE
            /// </summary>
            SCALE_MODE = 8,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the Spot-diffuse lighting effect uses to scale the image to the
        /// corresponding kernel unit length. There are six scale modes that range in quality and speed.
        /// </summary>
        public enum class D2D1_SPOTDIFFUSE_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode outputs a higher quality
            /// image than nearest neighbor.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is
            /// good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape of
            /// the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Distant-Diffuse effect's top level properties.
        /// Effect description: Creates a diffuse lighting effect with a distant light
        /// source.
        /// </summary>
        public enum class D2D1_DISTANTDIFFUSE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Azimuth"
            /// Property Type: FLOAT
            /// </summary>
            AZIMUTH = 0,

            /// <summary>
            /// Property Name: "Elevation"
            /// Property Type: FLOAT
            /// </summary>
            ELEVATION = 1,

            /// <summary>
            /// Property Name: "DiffuseConstant"
            /// Property Type: FLOAT
            /// </summary>
            DIFFUSE_CONSTANT = 2,

            /// <summary>
            /// Property Name: "SurfaceScale"
            /// Property Type: FLOAT
            /// </summary>
            SURFACE_SCALE = 3,

            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            COLOR = 4,

            /// <summary>
            /// Property Name: "KernelUnitLength"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_UNIT_LENGTH = 5,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_DISTANTDIFFUSE_SCALE_MODE
            /// </summary>
            SCALE_MODE = 6,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the effect uses to scale the image to the corresponding kernel unit
        /// length. There are six scale modes that range in quality and speed.
        /// </summary>
        public enum class D2D1_DISTANTDIFFUSE_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode outputs a higher quality
            /// image than nearest neighbor.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is
            /// good for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape of
            /// the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Flood effect's top level properties.
        /// Effect description: Renders an infinite sized floodfill of the given color.
        /// </summary>
        public enum class D2D1_FLOOD_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            COLOR = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Linear Transfer effect's top level properties.
        /// Effect description: Remaps the color intensities of the input bitmap based on a
        /// user specified linear transfer function for each RGBA channel.
        /// </summary>
        public enum class D2D1_LINEARTRANSFER_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "RedYIntercept"
            /// Property Type: FLOAT
            /// </summary>
            RED_Y_INTERCEPT = 0,

            /// <summary>
            /// Property Name: "RedSlope"
            /// Property Type: FLOAT
            /// </summary>
            RED_SLOPE = 1,

            /// <summary>
            /// Property Name: "RedDisable"
            /// Property Type: BOOL
            /// </summary>
            RED_DISABLE = 2,

            /// <summary>
            /// Property Name: "GreenYIntercept"
            /// Property Type: FLOAT
            /// </summary>
            GREEN_Y_INTERCEPT = 3,

            /// <summary>
            /// Property Name: "GreenSlope"
            /// Property Type: FLOAT
            /// </summary>
            GREEN_SLOPE = 4,

            /// <summary>
            /// Property Name: "GreenDisable"
            /// Property Type: BOOL
            /// </summary>
            GREEN_DISABLE = 5,

            /// <summary>
            /// Property Name: "BlueYIntercept"
            /// Property Type: FLOAT
            /// </summary>
            BLUE_Y_INTERCEPT = 6,

            /// <summary>
            /// Property Name: "BlueSlope"
            /// Property Type: FLOAT
            /// </summary>
            BLUE_SLOPE = 7,

            /// <summary>
            /// Property Name: "BlueDisable"
            /// Property Type: BOOL
            /// </summary>
            BLUE_DISABLE = 8,

            /// <summary>
            /// Property Name: "AlphaYIntercept"
            /// Property Type: FLOAT
            /// </summary>
            ALPHA_Y_INTERCEPT = 9,

            /// <summary>
            /// Property Name: "AlphaSlope"
            /// Property Type: FLOAT
            /// </summary>
            ALPHA_SLOPE = 10,

            /// <summary>
            /// Property Name: "AlphaDisable"
            /// Property Type: BOOL
            /// </summary>
            ALPHA_DISABLE = 11,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 12,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Gamma Transfer effect's top level properties.
        /// Effect description: Remaps the color intensities of the input bitmap based on a
        /// user specified gamma transfer function for each RGBA channel.
        /// </summary>
        public enum class D2D1_GAMMATRANSFER_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "RedAmplitude"
            /// Property Type: FLOAT
            /// </summary>
            RED_AMPLITUDE = 0,

            /// <summary>
            /// Property Name: "RedExponent"
            /// Property Type: FLOAT
            /// </summary>
            RED_EXPONENT = 1,

            /// <summary>
            /// Property Name: "RedOffset"
            /// Property Type: FLOAT
            /// </summary>
            RED_OFFSET = 2,

            /// <summary>
            /// Property Name: "RedDisable"
            /// Property Type: BOOL
            /// </summary>
            RED_DISABLE = 3,

            /// <summary>
            /// Property Name: "GreenAmplitude"
            /// Property Type: FLOAT
            /// </summary>
            GREEN_AMPLITUDE = 4,

            /// <summary>
            /// Property Name: "GreenExponent"
            /// Property Type: FLOAT
            /// </summary>
            GREEN_EXPONENT = 5,

            /// <summary>
            /// Property Name: "GreenOffset"
            /// Property Type: FLOAT
            /// </summary>
            GREEN_OFFSET = 6,

            /// <summary>
            /// Property Name: "GreenDisable"
            /// Property Type: BOOL
            /// </summary>
            GREEN_DISABLE = 7,

            /// <summary>
            /// Property Name: "BlueAmplitude"
            /// Property Type: FLOAT
            /// </summary>
            BLUE_AMPLITUDE = 8,

            /// <summary>
            /// Property Name: "BlueExponent"
            /// Property Type: FLOAT
            /// </summary>
            BLUE_EXPONENT = 9,

            /// <summary>
            /// Property Name: "BlueOffset"
            /// Property Type: FLOAT
            /// </summary>
            BLUE_OFFSET = 10,

            /// <summary>
            /// Property Name: "BlueDisable"
            /// Property Type: BOOL
            /// </summary>
            BLUE_DISABLE = 11,

            /// <summary>
            /// Property Name: "AlphaAmplitude"
            /// Property Type: FLOAT
            /// </summary>
            ALPHA_AMPLITUDE = 12,

            /// <summary>
            /// Property Name: "AlphaExponent"
            /// Property Type: FLOAT
            /// </summary>
            ALPHA_EXPONENT = 13,

            /// <summary>
            /// Property Name: "AlphaOffset"
            /// Property Type: FLOAT
            /// </summary>
            ALPHA_OFFSET = 14,

            /// <summary>
            /// Property Name: "AlphaDisable"
            /// Property Type: BOOL
            /// </summary>
            ALPHA_DISABLE = 15,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 16,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Table Transfer effect's top level properties.
        /// Effect description: Remaps the color intensities of the input bitmap based on a
        /// transfer function generated by a user specified list of values for each RGBA
        /// channel.
        /// </summary>
        public enum class D2D1_TABLETRANSFER_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "RedTable"
            /// Property Type: (blob)
            /// </summary>
            RED_TABLE = 0,

            /// <summary>
            /// Property Name: "RedDisable"
            /// Property Type: BOOL
            /// </summary>
            RED_DISABLE = 1,

            /// <summary>
            /// Property Name: "GreenTable"
            /// Property Type: (blob)
            /// </summary>
            GREEN_TABLE = 2,

            /// <summary>
            /// Property Name: "GreenDisable"
            /// Property Type: BOOL
            /// </summary>
            GREEN_DISABLE = 3,

            /// <summary>
            /// Property Name: "BlueTable"
            /// Property Type: (blob)
            /// </summary>
            BLUE_TABLE = 4,

            /// <summary>
            /// Property Name: "BlueDisable"
            /// Property Type: BOOL
            /// </summary>
            BLUE_DISABLE = 5,

            /// <summary>
            /// Property Name: "AlphaTable"
            /// Property Type: (blob)
            /// </summary>
            ALPHA_TABLE = 6,

            /// <summary>
            /// Property Name: "AlphaDisable"
            /// Property Type: BOOL
            /// </summary>
            ALPHA_DISABLE = 7,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 8,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Discrete Transfer effect's top level properties.
        /// Effect description: Remaps the color intensities of the input bitmap based on a
        /// discrete function generated by a user specified list of values for each RGBA
        /// channel.
        /// </summary>
        public enum class D2D1_DISCRETETRANSFER_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "RedTable"
            /// Property Type: (blob)
            /// </summary>
            RED_TABLE = 0,

            /// <summary>
            /// Property Name: "RedDisable"
            /// Property Type: BOOL
            /// </summary>
            RED_DISABLE = 1,

            /// <summary>
            /// Property Name: "GreenTable"
            /// Property Type: (blob)
            /// </summary>
            GREEN_TABLE = 2,

            /// <summary>
            /// Property Name: "GreenDisable"
            /// Property Type: BOOL
            /// </summary>
            GREEN_DISABLE = 3,

            /// <summary>
            /// Property Name: "BlueTable"
            /// Property Type: (blob)
            /// </summary>
            BLUE_TABLE = 4,

            /// <summary>
            /// Property Name: "BlueDisable"
            /// Property Type: BOOL
            /// </summary>
            BLUE_DISABLE = 5,

            /// <summary>
            /// Property Name: "AlphaTable"
            /// Property Type: (blob)
            /// </summary>
            ALPHA_TABLE = 6,

            /// <summary>
            /// Property Name: "AlphaDisable"
            /// Property Type: BOOL
            /// </summary>
            ALPHA_DISABLE = 7,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 8,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Convolve Matrix effect's top level properties.
        /// Effect description: Applies a user specified convolution kernel to a bitmap.
        /// </summary>
        public enum class D2D1_CONVOLVEMATRIX_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "KernelUnitLength"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_UNIT_LENGTH = 0,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_CONVOLVEMATRIX_SCALE_MODE
            /// </summary>
            SCALE_MODE = 1,

            /// <summary>
            /// Property Name: "KernelSizeX"
            /// Property Type: UINT32
            /// </summary>
            KERNEL_SIZE_X = 2,

            /// <summary>
            /// Property Name: "KernelSizeY"
            /// Property Type: UINT32
            /// </summary>
            KERNEL_SIZE_Y = 3,

            /// <summary>
            /// Property Name: "KernelMatrix"
            /// Property Type: (blob)
            /// </summary>
            KERNEL_MATRIX = 4,

            /// <summary>
            /// Property Name: "Divisor"
            /// Property Type: FLOAT
            /// </summary>
            DIVISOR = 5,

            /// <summary>
            /// Property Name: "Bias"
            /// Property Type: FLOAT
            /// </summary>
            BIAS = 6,

            /// <summary>
            /// Property Name: "KernelOffset"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            KERNEL_OFFSET = 7,

            /// <summary>
            /// Property Name: "PreserveAlpha"
            /// Property Type: BOOL
            /// </summary>
            PRESERVE_ALPHA = 8,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 9,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 10,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The interpolation mode the Convolve matrix effect uses to scale the image to the
        /// corresponding kernel unit length. There are six scale modes that range in quality and speed.
        /// </summary>
        public enum class D2D1_CONVOLVEMATRIX_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode outputs a higher quality
            /// image than nearest neighbor mode.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is good
            /// for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape of
            /// the bitmap.
            /// </summary>
            ANISOTROPIC = 4,

            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image
            /// if downscaling is involved in the transform matrix. Then uses the cubic interpolation
            /// mode for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Brightness effect's top level properties.
        /// Effect description: Adjusts the brightness of the image based on the specified
        /// white and black point.
        /// </summary>
        public enum class D2D1_BRIGHTNESS_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "WhitePoint"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            WHITE_POINT = 0,

            /// <summary>
            /// Property Name: "BlackPoint"
            /// Property Type: D2D1_VECTOR_2F
            /// </summary>
            BLACK_POINT = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Arithmetic Composite effect's top level properties.
        /// Effect description: Composites two bitmaps based on the following algorithm:
        /// Output = Coefficients_1 * Source * Destination + Coefficients_2 * Source+
        /// Coefficients_3 * Destination + Coefficients_4.
        /// </summary>
        public enum class D2D1_ARITHMETICCOMPOSITE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Coefficients"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            COEFFICIENTS = 0,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Crop effect's top level properties.
        /// Effect description: Crops the input bitmap according to the specified
        /// parameters.
        /// </summary>
        public enum class D2D1_CROP_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Rect"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            RECT = 0,

            /// <summary>
            /// Property Name: "BorderMode"
            /// Property Type: D2D1_BORDER_MODE
            /// </summary>
            BORDER_MODE = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Border effect's top level properties.
        /// Effect description: Extends the region of the bitmap based on the selected
        /// border mode.
        /// </summary>
        public enum class D2D1_BORDER_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "EdgeModeX"
            /// Property Type: D2D1_BORDER_EDGE_MODE
            /// </summary>
            EDGE_MODE_X = 0,

            /// <summary>
            /// Property Name: "EdgeModeY"
            /// Property Type: D2D1_BORDER_EDGE_MODE
            /// </summary>
            EDGE_MODE_Y = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The edge mode for the Border effect.
        /// </summary>
        public enum class D2D1_BORDER_EDGE_MODE : unsigned int
        {
            /// <summary>
            /// Repeats the pixels from the edges of the image.
            /// </summary>
            CLAMP = 0,

            /// <summary>
            /// Uses pixels from the opposite end edge of the image.
            /// </summary>
            WRAP = 1,

            /// <summary>
            /// Reflects pixels about the edge of the image.
            /// </summary>
            MIRROR = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Morphology effect's top level properties.
        /// Effect description: Erodes or dilates a bitmap by the given radius.
        /// </summary>
        public enum class D2D1_MORPHOLOGY_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Mode"
            /// Property Type: D2D1_MORPHOLOGY_MODE
            /// </summary>
            MODE = 0,

            /// <summary>
            /// Property Name: "Width"
            /// Property Type: UINT32
            /// </summary>
            WIDTH = 1,

            /// <summary>
            /// Property Name: "Height"
            /// Property Type: UINT32
            /// </summary>
            HEIGHT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The mode for the Morphology effect.
        /// </summary>
        public enum class D2D1_MORPHOLOGY_MODE : unsigned int
        {
            /// <summary>
            /// The maximum value from each RGB channel in the kernel is used.
            /// </summary>
            ERODE = 0,

            /// <summary>
            /// The minimum value from each RGB channel in the kernel is used.
            /// </summary>
            DILATE = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Tile effect's top level properties.
        /// Effect description: Tiles the specified region of the input bitmap.
        /// </summary>
        public enum class D2D1_TILE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Rect"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            RECT = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Atlas effect's top level properties.
        /// Effect description: Changes the available area of the input to the specified
        /// rectangle. Provides an optimization for scenarios where a bitmap is used as an
        /// atlas.
        /// </summary>
        public enum class D2D1_ATLAS_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "InputRect"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            INPUT_RECT = 0,

            /// <summary>
            /// Property Name: "InputPaddingRect"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            INPUT_PADDING_RECT = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Opacity Metadata effect's top level properties.
        /// Effect description: Changes the rectangle which is assumed to be opaque.
        /// Provides optimizations in certain scenarios.
        /// </summary>
        public enum class D2D1_OPACITYMETADATA_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "InputOpaqueRect"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            INPUT_OPAQUE_RECT = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the YCbCr effect's top level properties.
        /// Effect description: An effect that takes a Y plane as input 0 and a CbCr plane
        /// as input 1 and outputs RGBA.  The CbCr plane can be chroma subsampled.  Useful
        /// for JPEG color conversion.
        /// </summary>
        public enum class D2D1_YCBCR_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "ChromaSubsampling"
            /// Property Type: D2D1_YCBCR_CHROMA_SUBSAMPLING
            /// </summary>
            CHROMA_SUBSAMPLING = 0,

            /// <summary>
            /// Property Name: "TransformMatrix"
            /// Property Type: D2D1_MATRIX_3X2_F
            /// </summary>
            TRANSFORM_MATRIX = 1,

            /// <summary>
            /// Property Name: "InterpolationMode"
            /// Property Type: D2D1_YCBCR_INTERPOLATION_MODE
            /// </summary>
            INTERPOLATION_MODE = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies the chroma subsampling of the input chroma image used by the YCbCr effect.
        /// </summary>
        public enum class D2D1_YCBCR_CHROMA_SUBSAMPLING : unsigned int
        {
            /// <summary>
            /// This mode attempts to infer the chroma subsampling from the bounds of the input images.
            /// When this option is selected, the smaller plane is upsampled to the size of the larger
            /// plane andthis effect¡¯s output rectangle is the intersection of the two planes.
            /// When using this mode, care should be taken when applying effects to the input planes
            /// that change the image bounds, such as the border transform, so that the desired size
            /// ratio between the planes is maintained.
            /// </summary>
            SUBSAMPLING_AUTO = 0,

            /// <summary>
            /// The chroma plane is horizontally subsampled by 1/2 and vertically subsampled by 1/2.
            /// When this option is selected, the chroma plane is horizontally andvertically upsampled by
            /// 2x and this effect's output rectangle is the intersection of the two planes.
            /// </summary>
            SUBSAMPLING_420 = 1,

            /// <summary>
            /// The chroma plane is horizontally subsampled by 1/2. When this option is selected,
            /// the chroma plane is horizontally upsampled by 2x and this effect's output rectangle is
            /// the intersection of the two planes.
            /// </summary>
            SUBSAMPLING_422 = 2,

            /// <summary>
            /// The chroma plane is not subsampled. When this option is selected this effect¡¯s output
            /// rectangle is the intersection of the two planes.
            /// </summary>
            SUBSAMPLING_444 = 3,

            /// <summary>
            /// The chroma plane is vertically subsampled by 1/2. When this option is selected,
            /// the chroma plane is vertically upsampled by 2x and this effect's output rectangle
            /// is the intersection of the two planes.
            /// </summary>
            SUBSAMPLING_440 = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Specifies the interpolation mode for the YCbCr effect.
        /// </summary>
        public enum class D2D1_YCBCR_INTERPOLATION_MODE : unsigned int
        {
            /// <summary>
            /// Samples the nearest single point and uses that. This mode uses less processing time,
            /// but outputs the lowest quality image.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Uses a four point sample and linear interpolation. This mode uses more processing time than
            /// the nearest neighbor mode, but outputs a higher quality image.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time,
            /// but outputs a higher quality image.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is good
            /// for scaling down by small amounts on images with few pixels.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Uses anisotropic filtering to sample a pattern according to the transformed shape of
            /// the bitmap.
            /// </summary>
            ANISOTROPIC = 4,
            
            /// <summary>
            /// Uses a variable size high quality cubic kernel to perform a pre-downscale the image if
            /// downscaling is involved in the transform matrix. Then uses the cubic interpolation mode
            /// for the final output.
            /// </summary>
            HIGH_QUALITY_CUBIC = 5,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Contrast effect's top level properties.
        /// Effect description: Adjusts the contrast of an image.
        /// </summary>
        public enum class D2D1_CONTRAST_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Contrast"
            /// Property Type: FLOAT
            /// </summary>
            CONTRAST = 0,

            /// <summary>
            /// Property Name: "ClampInput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_INPUT = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the RgbToHue effect's top level properties.
        /// Effect description: Converts an RGB bitmap to HSV or HSL.
        /// </summary>
        public enum class D2D1_RGBTOHUE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "OutputColorSpace"
            /// Property Type: D2D1_RGBTOHUE_OUTPUT_COLOR_SPACE
            /// </summary>
            OUTPUT_COLOR_SPACE = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Values for the <see cref="Direct2DNet::Effects::D2D1_RGBTOHUE_PROP::OUTPUT_COLOR_SPACE"/>
        /// property of the RGB to Hue effect.
        /// </summary>
        public enum class D2D1_RGBTOHUE_OUTPUT_COLOR_SPACE : unsigned int
        {
            /// <summary>
            /// The effect converts from RGB to Hue Saturation Value (HSV).
            /// </summary>
            HUE_SATURATION_VALUE = 0,

            /// <summary>
            /// The effect converts from RGB to Hue Saturation Lightness (HSL).
            /// </summary>
            HUE_SATURATION_LIGHTNESS = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the HueToRgb effect's top level properties.
        /// Effect description: Converts an HSV or HSL bitmap into an RGB bitmap.
        /// </summary>
        public enum class D2D1_HUETORGB_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "InputColorSpace"
            /// Property Type: D2D1_HUETORGB_INPUT_COLOR_SPACE
            /// </summary>
            INPUT_COLOR_SPACE = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Values for the <see cref="Direct2DNet::Effects::D2D1_HUETORGB_PROP::INPUT_COLOR_SPACE"/>
        /// property of the Hue to RGB effect.
        /// </summary>
        public enum class D2D1_HUETORGB_INPUT_COLOR_SPACE : unsigned int
        {
            /// <summary>
            /// The effect converts from Hue Saturation Value (HSV) to RGB.
            /// </summary>
            HUE_SATURATION_VALUE = 0,

            /// <summary>
            /// The effect converts from Hue Saturation Lightness (HSL) to RGB.
            /// </summary>
            HUE_SATURATION_LIGHTNESS = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Chroma Key effect's top level properties.
        /// Effect description: Converts a specified color to transparent.
        /// </summary>
        public enum class D2D1_CHROMAKEY_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_3F
            /// </summary>
            COLOR = 0,

            /// <summary>
            /// Property Name: "Tolerance"
            /// Property Type: FLOAT
            /// </summary>
            TOLERANCE = 1,

            /// <summary>
            /// Property Name: "InvertAlpha"
            /// Property Type: BOOL
            /// </summary>
            INVERT_ALPHA = 2,

            /// <summary>
            /// Property Name: "Feather"
            /// Property Type: BOOL
            /// </summary>
            FEATHER = 3,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Emboss effect's top level properties.
        /// Effect description: Applies an embossing effect to an image.
        /// </summary>
        public enum class D2D1_EMBOSS_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Height"
            /// Property Type: FLOAT
            /// </summary>
            HEIGHT = 0,

            /// <summary>
            /// Property Name: "Direction"
            /// Property Type: FLOAT
            /// </summary>
            DIRECTION = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Exposure effect's top level properties.
        /// Effect description: Simulates camera exposure adjustment.
        /// </summary>
        public enum class D2D1_EXPOSURE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "ExposureValue"
            /// Property Type: FLOAT
            /// </summary>
            EXPOSURE_VALUE = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Posterize effect's top level properties.
        /// Effect description: Reduces the number of colors in an image.
        /// </summary>
        public enum class D2D1_POSTERIZE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "RedValueCount"
            /// Property Type: UINT32
            /// </summary>
            RED_VALUE_COUNT = 0,

            /// <summary>
            /// Property Name: "GreenValueCount"
            /// Property Type: UINT32
            /// </summary>
            GREEN_VALUE_COUNT = 1,

            /// <summary>
            /// Property Name: "BlueValueCount"
            /// Property Type: UINT32
            /// </summary>
            BLUE_VALUE_COUNT = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Sepia effect's top level properties.
        /// Effect description: Applies a Sepia tone to an image.
        /// </summary>
        public enum class D2D1_SEPIA_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Intensity"
            /// Property Type: FLOAT
            /// </summary>
            INTENSITY = 0,

            /// <summary>
            /// Property Name: "AlphaMode"
            /// Property Type: D2D1_ALPHA_MODE
            /// </summary>
            ALPHA_MODE = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Sharpen effect's top level properties.
        /// Effect description: Performs sharpening adjustment
        /// </summary>
        public enum class D2D1_SHARPEN_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Sharpness"
            /// Property Type: FLOAT
            /// </summary>
            SHARPNESS = 0,

            /// <summary>
            /// Property Name: "Threshold"
            /// Property Type: FLOAT
            /// </summary>
            THRESHOLD = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Straighten effect's top level properties.
        /// Effect description: Straightens an image.
        /// </summary>
        public enum class D2D1_STRAIGHTEN_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Angle"
            /// Property Type: FLOAT
            /// </summary>
            ANGLE = 0,

            /// <summary>
            /// Property Name: "MaintainSize"
            /// Property Type: BOOL
            /// </summary>
            MAINTAIN_SIZE = 1,

            /// <summary>
            /// Property Name: "ScaleMode"
            /// Property Type: D2D1_STRAIGHTEN_SCALE_MODE
            /// </summary>
            SCALE_MODE = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Values for the <see cref="Direct2DNet::Effects::D2D1_STRAIGHTEN_PROP::SCALE_MODE"/> property
        /// of the Straighten effect.
        /// </summary>
        public enum class D2D1_STRAIGHTEN_SCALE_MODE : unsigned int
        {
            /// <summary>
            /// Indicates nearest neighbor interpolation should be used.
            /// </summary>
            NEAREST_NEIGHBOR = 0,

            /// <summary>
            /// Indicates linear interpolation should be used.
            /// </summary>
            LINEAR = 1,

            /// <summary>
            /// Indicates cubic interpolation should be used.
            /// </summary>
            CUBIC = 2,

            /// <summary>
            /// Indicates multi-sample linear interpolation should be used.
            /// </summary>
            MULTI_SAMPLE_LINEAR = 3,

            /// <summary>
            /// Indicates anisotropic filtering should be used.
            /// </summary>
            ANISOTROPIC = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Temperature And Tint effect's top level properties.
        /// Effect description: Adjusts the temperature and tint of an image.
        /// </summary>
        public enum class D2D1_TEMPERATUREANDTINT_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Temperature"
            /// Property Type: FLOAT
            /// </summary>
            TEMPERATURE = 0,

            /// <summary>
            /// Property Name: "Tint"
            /// Property Type: FLOAT
            /// </summary>
            TINT = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Vignette effect's top level properties.
        /// Effect description: Fades the edges of an image to the specified color.
        /// </summary>
        public enum class D2D1_VIGNETTE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            COLOR = 0,

            /// <summary>
            /// Property Name: "TransitionSize"
            /// Property Type: FLOAT
            /// </summary>
            TRANSITION_SIZE = 1,

            /// <summary>
            /// Property Name: "Strength"
            /// Property Type: FLOAT
            /// </summary>
            STRENGTH = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Edge Detection effect's top level properties.
        /// Effect description: Detects edges of an image.
        /// </summary>
        public enum class D2D1_EDGEDETECTION_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Strength"
            /// Property Type: FLOAT
            /// </summary>
            STRENGTH = 0,

            /// <summary>
            /// Property Name: "BlurRadius"
            /// Property Type: FLOAT
            /// </summary>
            BLUR_RADIUS = 1,

            /// <summary>
            /// Property Name: "Mode"
            /// Property Type: D2D1_EDGEDETECTION_MODE
            /// </summary>
            MODE = 2,

            /// <summary>
            /// Property Name: "OverlayEdges"
            /// Property Type: BOOL
            /// </summary>
            OVERLAY_EDGES = 3,

            /// <summary>
            /// Property Name: "AlphaMode"
            /// Property Type: D2D1_ALPHA_MODE
            /// </summary>
            ALPHA_MODE = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Values for the <see cref="Direct2DNet::Effects::D2D1_EDGEDETECTION_PROP::MODE"/> property of
        /// the Edge Detection effect.
        /// </summary>
        public enum class D2D1_EDGEDETECTION_MODE : unsigned int
        {
            /// <summary>
            /// Indicates the Sobel operator should be used for edge detection.
            /// </summary>
            SOBEL = 0,

            /// <summary>
            /// Indicates the Prewitt operator should be used for edge detection.
            /// </summary>
            PREWITT = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Highlights and Shadows effect's top level properties.
        /// Effect description: Adjusts the highlight and shadow strength of an image.
        /// </summary>
        public enum class D2D1_HIGHLIGHTSANDSHADOWS_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Highlights"
            /// Property Type: FLOAT
            /// </summary>
            HIGHLIGHTS = 0,

            /// <summary>
            /// Property Name: "Shadows"
            /// Property Type: FLOAT
            /// </summary>
            SHADOWS = 1,

            /// <summary>
            /// Property Name: "Clarity"
            /// Property Type: FLOAT
            /// </summary>
            CLARITY = 2,

            /// <summary>
            /// Property Name: "InputGamma"
            /// Property Type: D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA
            /// </summary>
            INPUT_GAMMA = 3,

            /// <summary>
            /// Property Name: "MaskBlurRadius"
            /// Property Type: FLOAT
            /// </summary>
            MASK_BLUR_RADIUS = 4,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Values for the <see cref="Direct2DNet::Effects::D2D1_HIGHLIGHTSANDSHADOWS_PROP::INPUT_GAMMA"/>
        /// property of the Highlights and Shadows effect.
        /// </summary>
        public enum class D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA : unsigned int
        {
            /// <summary>
            /// Indicates the input image is in linear gamma space.
            /// </summary>
            LINEAR = 0,

            /// <summary>
            /// Indicates the input image is sRGB gamma space.
            /// </summary>
            SRGB = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Lookup Table 3D effect's top level properties.
        /// Effect description: Remaps colors in an image via a 3D lookup table.
        /// </summary>
        public enum class D2D1_LOOKUPTABLE3D_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Lut"
            /// Property Type: IUnknown *
            /// </summary>
            LUT = 0,

            /// <summary>
            /// Property Name: "AlphaMode"
            /// Property Type: D2D1_ALPHA_MODE
            /// </summary>
            ALPHA_MODE = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Opacity effect's top level properties.
        /// Effect description: Adjusts the opacity of an image by multiplying the alpha
        /// channel by the specified opacity.
        /// </summary>
        public enum class D2D1_OPACITY_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Opacity"
            /// Property Type: FLOAT
            /// </summary>
            OPACITY = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Cross Fade effect's top level properties.
        /// Effect description: This effect combines two images by adding weighted pixels
        /// from input images. The formula can be expressed as output = weight * Destination
        /// + (1 - weight) * Source
        /// </summary>
        public enum class D2D1_CROSSFADE_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Weight"
            /// Property Type: FLOAT
            /// </summary>
            WEIGHT = 0,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the Tint effect's top level properties.
        /// Effect description: This effect tints the source image by multiplying the
        /// specified color by the source image.
        /// </summary>
        public enum class D2D1_TINT_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "Color"
            /// Property Type: D2D1_VECTOR_4F
            /// </summary>
            COLOR = 0,

            /// <summary>
            /// Property Name: "ClampOutput"
            /// Property Type: BOOL
            /// </summary>
            CLAMP_OUTPUT = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the White Level Adjustment effect's top level properties.
        /// Effect description: This effect adjusts the white level of the source image by
        /// multiplying the source image color by the ratio of the input and output white
        /// levels. Input and output white levels are specified in nits.
        /// </summary>
        public enum class D2D1_WHITELEVELADJUSTMENT_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "InputWhiteLevel"
            /// Property Type: FLOAT
            /// </summary>
            INPUT_WHITE_LEVEL = 0,

            /// <summary>
            /// Property Name: "OutputWhiteLevel"
            /// Property Type: FLOAT
            /// </summary>
            OUTPUT_WHITE_LEVEL = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// The enumeration of the HDR Tone Map effect's top level properties.
        /// Effect description: Adjusts the maximum luminance of the source image to fit
        /// within the maximum output luminance supported. Input and output luminance values
        /// are specified in nits. Note that the color space of the image is assumed to be
        /// scRGB.
        /// </summary>
        public enum class D2D1_HDRTONEMAP_PROP : unsigned int
        {
            /// <summary>
            /// Property Name: "InputMaxLuminance"
            /// Property Type: FLOAT
            /// </summary>
            INPUT_MAX_LUMINANCE = 0,

            /// <summary>
            /// Property Name: "OutputMaxLuminance"
            /// Property Type: FLOAT
            /// </summary>
            OUTPUT_MAX_LUMINANCE = 1,

            /// <summary>
            /// Property Name: "DisplayMode"
            /// Property Type: D2D1_HDRTONEMAP_DISPLAY_MODE
            /// </summary>
            DISPLAY_MODE = 2,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Defines constants that specify a value for the
        /// <see cref="Direct2DNet::Effects::D2D1_HDRTONEMAP_PROP::DISPLAY_MODE"/> property of the HDR
        /// tone map effect.
        /// </summary>
        public enum class D2D1_HDRTONEMAP_DISPLAY_MODE : unsigned int
        {
            /// <summary>
            /// Specifies that the tone mapper algorithm be optimized for best appearance on a standard
            /// dynamic range (SDR) display.
            /// </summary>
            SDR = 0,

            /// <summary>
            /// Specifies that the tone mapper algorithm be optimized for best appearance on a high
            /// dynamic range (HDR) display.
            /// </summary>
            HDR = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
            FORCE_DWORD = 0xffffffff
        };
    }
}

}