#pragma once

#include "D2DNetHeaders.h"
#include "../DXCommonSettings.h"
#include "D2DSettings.h"
#include "D2DError.h"
#include "Exception/DXException.h"
#include "ID2D1Factory.h"
#include "ID2D1Factory1.h"
#include "ID2D1Factory2.h"
#include "ID2D1Factory3.h"
#include "../DXGINet/IDXGIDevice.h"
#include "../DXGINet/IDXGISurface.h"
#include "ID2D1Device.h"
#include "ID2D1DeviceContext.h"
#include "ID2D1Effect.h"
#include "ID2D1Bitmap.h"
#include "D2DBuiltinEffects.h"
#include "../GUIDs.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {
        public ref class Direct2D abstract sealed
        {
        public:
            literal int APPEND_ALIGNED_ELEMENT = D2D1_APPEND_ALIGNED_ELEMENT;
            literal float DEFAULT_FLATTENING_TOLERANCE = D2D1_DEFAULT_FLATTENING_TOLERANCE;
            literal unsigned int INVALID_PROPERTY_INDEX = D2D1_INVALID_PROPERTY_INDEX;
            literal unsigned long long INVALID_TAG = D2D1_INVALID_TAG;
            literal float SCENE_REFERRED_SDR_WHITE_LEVEL = D2D1_SCENE_REFERRED_SDR_WHITE_LEVEL;

            /// <summary>
            /// Creates a factory object that can be used to create Direct2D resources.
            /// </summary>
            /// <typeparam name="T">A type that inherits from ID2D1Factory.</typeparam>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            generic<typename T> where T : Direct2DNet::ID2D1Factory
                static T CreateFactory(
                    Direct2DNet::D2D1_FACTORY_TYPE type,
                    [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_FACTORY_OPTIONS> options
                )
            {
                GuidAttribute ^guid = (GuidAttribute ^)System::Attribute::GetCustomAttribute(
                    T::typeid,
                    GuidAttribute::typeid
                );

                System::Guid factoryGuid(guid->Value);
                
                if(factoryGuid == D2DNet::D2DNetGUID::UID_ID2D1Factory)
                {
                    if(options.HasValue)
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory(type, options.Value);
                    }
                    else
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory(type);
                    }
                }
                else if(factoryGuid == D2DNet::D2DNetGUID::UID_ID2D1Factory1)
                {
                    if(options.HasValue)
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory1(type, options.Value);
                    }
                    else
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory1(type);
                    }
                }
                else if(factoryGuid == D2DNet::D2DNetGUID::UID_ID2D1Factory2)
                {
                    if(options.HasValue)
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory2(type, options.Value);
                    }
                    else
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory2(type);
                    }
                }
                else if(factoryGuid == D2DNet::D2DNetGUID::UID_ID2D1Factory3)
                {
                    if(options.HasValue)
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory3(type, options.Value);
                    }
                    else
                    {
                        return (T)gcnew Direct2DNet::ID2D1Factory3(type);
                    }
                }
                else
                {
                    throw gcnew Direct2DNet::Exception::DxException(
                        "Failed to create the factory.", E_INVALIDARG
                    );
                }
            }

            /// <summary>
            /// Creates a factory object that can be used to create Direct2D resources.
            /// </summary>
            /// <param name="guid">
            /// The guid of the factory.
            /// </param>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the factory.
            /// </exception>
            static Direct2DNet::ID2D1Factory ^CreateFactory(
                Direct2DNet::D2D1_FACTORY_TYPE type,
                [InAttribute][IsReadOnlyAttribute] System::Guid %guid,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_FACTORY_OPTIONS> options
            );

            /// <summary>
            /// Converts the given color from one colorspace to another.
            /// </summary>
            /// <param name="sourceColorSpace">
            /// The source color space.
            /// </param>
            /// <param name="destinationColorSpace">
            /// The destination color space.
            /// </param>
            /// <param name="color">
            /// The source color.
            /// </param>
            /// <returns>
            /// The converted color.
            /// </returns>
            static Direct2DNet::D2D1_COLOR_F ConvertColorSpace(
                Direct2DNet::D2D1_COLOR_SPACE sourceColorSpace,
                Direct2DNet::D2D1_COLOR_SPACE destinationColorSpace,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_COLOR_F %color
            );

            /// <summary>
            /// Creates a new Direct2D device associated with the provided DXGI device. This function will
            /// also create a new ID2D1Factory1 that can be retrieved through ID2D1Resource::Factory.
            /// If the creation properties are not specified, then the device will inherit its threading
            /// mode from dxgiDevice and debug tracing will not be enabled.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the device.
            /// </exception>
            static Direct2DNet::ID2D1Device ^CreateDevice(
                DXGINet::IDXGIDevice ^dxgiDevice,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_CREATION_PROPERTIES> creationProperties
            );

            /// <summary>
            /// Creates a new Direct2D device context associated with a DXGI surface. This function will
            /// also create a new ID2D1Factory1 that can be retrieved through ID2D1Resource::Factory.
            /// This function will also create a new ID2D1Device that can be retrieved through
            /// ID2D1DeviceContext::Device. The DXGI device will be specified implicitly through
            /// dxgiSurface. If creationProperties are not specified, the Direct2D device will inherit
            /// its threading mode from the DXGI device implied by dxgiSurface anddebug tracing will not
            /// be enabled.
            /// </summary>
            /// <exception cref="Direct2DNet::Exception::DxException">
            /// Thrown when it failed to create the device context.
            /// </exception>
            static Direct2DNet::ID2D1DeviceContext ^CreateDeviceContext(
                DXGINet::IDXGISurface ^dxgiSurface,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_CREATION_PROPERTIES> creationProperties
            );

            /// <summary>
            /// Sets a bitmap as an effect input, while inserting a DPI compensation effect to preserve
            /// visual appearance as the device context's DPI changes.
            /// </summary>
            /// <param name="deviceContext">
            /// The device context that is the creator of the effect.
            /// </param>
            /// <param name="effect">
            /// The function sets the input of this effect.
            /// </param>
            /// <param name="inputIndex">
            /// The index of the input to be set.
            /// </param>
            /// <param name="inputBitmap">
            /// The input bitmap.
            /// </param>
            /// <param name="interpolationMode">
            /// The interpolation mode for the DPI compensation effect.
            /// </param>
            /// <param name="borderMode">
            /// The border mode for the DPI compensation effect.
            /// </param>
            /// <returns>
            /// If this function succeeds, it returns S_OK. Otherwise, it returns an error code.
            /// </returns>
            static HRESULT SetDpiCompensatedEffectInput(
                Direct2DNet::ID2D1DeviceContext ^deviceContext,
                Direct2DNet::ID2D1Effect ^effect,
                unsigned int inputIndex,
                Direct2DNet::ID2D1Bitmap ^inputBitmap,
                [OptionalAttribute] System::Nullable<Direct2DNet::D2D1_INTERPOLATION_MODE> interpolationMode,
                [OptionalAttribute] System::Nullable<Direct2DNet::Effects::D2D1_BORDER_MODE> borderMode
            );

            /// <summary>
            /// Computes the maximum factor by which a given transform can stretch any vector.
            /// Formally, if M is the input matrix, this method will return the maximum value of
            /// |V * M| / |V| for all vectors V, where |.| denotes length.
            /// </summary>
            /// <param name="matrix">
            /// The input transform matrix.
            /// </param>
            /// <returns>
            /// The scale factor.
            /// </returns>
            static float ComputeMaximumScaleFactor(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %matrix
            );

            /// <summary>
            /// Sets a bitmap as an effect input, while inserting a DPI compensation effect to preserve
            /// visual appearance as the device context's DPI changes.
            /// </summary>
            /// <param name="matrix">
            /// The matrix that will be applied subsequently to the geometry being flattened.
            /// </param>
            /// <param name="dpiX">
            /// The horizontal DPI of the render target that the geometry will be rendered onto
            /// (a choice of 96 implies no DPI correction). The default value is 96.
            /// </param>
            /// <param name="dpiY">
            /// The vertical DPI of the render target that the geometry will be rendered onto 
            /// (a choice of 96 implies no DPI correction). The default value is 96.
            /// </param>
            /// <param name="maxZoomFactor">
            /// The maximum amount of additional scaling (on top of any scaling implied by the matrix
            /// or the DPI) that will be applied to the geometry. The default value is 1.
            /// </param>
            /// <returns>
            /// The flattening tolerance.
            /// </returns>
            static float ComputeFlatteningTolerance(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %matrix,
                [OptionalAttribute] System::Nullable<float> dpiX,
                [OptionalAttribute] System::Nullable<float> dpiY,
                [OptionalAttribute] System::Nullable<float> maxZoomFactor
            );
        };
    }
}