#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "IWICComponentInfo.h"
#include <msclr/marshal.h>

using namespace msclr::interop;

namespace D2DNet
{
    namespace WICNet
    {
        // Done.

        /// <summary>
        /// Exposes methods that provide information about a particular codec.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("E87A44C4-B76E-4c47-8B09-298EB12A2714")]
        public ref class IWICBitmapCodecInfo : WICNet::IWICComponentInfo
        {
        internal:
            IWICBitmapCodecInfo() : WICNet::IWICComponentInfo() {}

            IWICBitmapCodecInfo(::IWICBitmapCodecInfo *pInfo) : WICNet::IWICComponentInfo(pInfo) {}

        public:
            /// <summary>
            /// Retrieves the container GUID associated with the codec.
            /// </summary>
            /// <param name="clsid">
            /// A parameter that receives the container GUID(out parameter). The list of built-in container
            /// GUIDs is in the <see cref="WICNet::ContainerFormatGUID"/> class.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetContainerFormat(
                [OutAttribute] System::Guid %guidContainerFormat
            );

            /// <summary>
            /// Retrieves the pixel formats the codec supports.
            /// </summary>
            /// <param name="guidPixelFormats">
            /// An array buffer that receives the supported pixel formats. Use null on first call to
            /// determine needed array size. The list of built-in pixel format GUIDs is in the
            /// <see cref="WICNet::PixelFormatGUID"/> class.
            /// </param>
            /// <param name="cActual">
            /// The array size needed to retrieve all supported pixel formats.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            /// <remarks>
            /// The usage pattern for this method is a two call process. The first call retrieves the array
            /// size needed to retrieve all the supported pixel formats by calling it with guidPixelFormats
            /// set to null. This call sets cActual to the array size needed. Once the needed array size
            /// is determined, a second GetPixelFormats call with guidPixelFormats set to an array of the
            /// appropriate size will retrieve the pixel formats.
            /// </remarks>
            HRESULT GetPixelFormats(
                array<System::Guid> ^guidPixelFormats,
                UINT %cActual
            );

            /// <summary>
            /// Retrieves the color manangement version number the codec supports.
            /// </summary>
            /// <param name="colorManagementVersion">
            /// A parameter that receives the color management version number(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetColorManagementVersion(
                [OutAttribute] System::String ^%colorManagementVersion
            );

            /// <summary>
            /// Retrieves the name of the device manufacture associated with the codec.
            /// </summary>
            /// <param name="deviceManufacturer">
            /// A parameter that receives the device manufacture's name(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetDeviceManufacturer(
                [OutAttribute] System::String ^%deviceManufacturer
            );

            /// <summary>
            /// Retrieves a comma delimited list of device models associated with the codec.
            /// </summary>
            /// <param name="deviceModels">
            /// A parameter that receives a comma delimited list of device model names associated with
            /// the codec(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetDeviceModels(
                [OutAttribute] System::String ^%deviceModels
            );

            /// <summary>
            /// Retrieves a comma delimited sequence of mime types associated with the codec.
            /// </summary>
            /// <param name="mimeTypes">
            /// A parameter that receives the mime types associated with the codec(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetMimeTypes(
                [OutAttribute] System::String ^%mimeTypes
            );

            /// <summary>
            /// Retrieves a comma delimited list of the file name extensions associated with the codec.
            /// </summary>
            /// <param name="fileExtensions">
            /// A parameter that receives a comma delimited list of file name extensions associated with
            /// the codec(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetFileExtensions(
                [OutAttribute] System::String ^%fileExtensions
            );

            /// <summary>
            /// Retrieves a value indicating whether the codec supports animation.
            /// </summary>
            /// <param name="supportAnimation">
            /// A parameter that receives true if the codec supports images with timing information;
            /// otherwise, false(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT DoesSupportAnimation(
                [OutAttribute] bool %supportAnimation
            );

            /// <summary>
            /// Retrieves a value indicating whether the codec supports animation.
            /// </summary>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is true if the codec supports images with timing information;
            /// otherwise, false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> DoesSupportAnimation();

            /// <summary>
            /// Retrieves a value indicating whether the codec supports chromakeys.
            /// </summary>
            /// <param name="supportChromakey">
            /// A parameter that receives true if if the codec supports chromakeys; otherwise, false
            /// (out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT DoesSupportChromakey(
                [OutAttribute] bool %supportChromakey
            );

            /// <summary>
            /// Retrieves a value indicating whether the codec supports chromakeys.
            /// </summary>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is true if the codec supports chromakeys; otherwise, false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> DoesSupportChromakey();

            /// <summary>
            /// Retrieves a value indicating whether the codec supports lossless formats.
            /// </summary>
            /// <param name="supportLossless">
            /// A parameter that receives true if if the codec supports lossless formats; otherwise, false
            /// (out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT DoesSupportLossless(
                [OutAttribute] bool %supportLossless
            );

            /// <summary>
            /// Retrieves a value indicating whether the codec supports lossless formats.
            /// </summary>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is true if the codec supports lossless formats; otherwise, false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> DoesSupportLossless();

            /// <summary>
            /// Retrieves a value indicating whether the codec supports multi frame images.
            /// </summary>
            /// <param name="supportMultiframe">
            /// A parameter that receives true if if the codec supports multi frame images; otherwise, false
            /// (out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT DoesSupportMultiframe(
                [OutAttribute] bool %supportMultiframe
            );

            /// <summary>
            /// Retrieves a value indicating whether the codec supports lossless formats.
            /// </summary>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is true if the codec supports multi frame images; otherwise, false.
            /// </returns>
            System::ValueTuple<HRESULT, bool> DoesSupportMultiframe();

            /// <summary>
            /// Retrieves a value indicating whether the given mime type matches the mime type of the codec.
            /// </summary>
            /// <param name="mimeType">
            /// The mime type to compare.
            /// </param>
            /// <param name="matches">
            /// A parameter that receives true if if the mime types match; otherwise, false(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            /// <remarks>
            /// The Windows provided codecs do not implement this method and return E_NOTIMPL.
            /// </remarks>
            HRESULT MatchesMimeType(
                System::String ^mimeType,
                [OutAttribute] bool %matches
            );

            /// <summary>
            /// Retrieves a value indicating whether the given mime type matches the mime type of the codec.
            /// </summary>
            /// <param name="mimeType">
            /// The mime type to compare.
            /// </param>
            /// <returns>
            /// (HRESULT, bool) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is an
            /// HRESULT error code. bool is true if if the mime types match; otherwise, false.
            /// </returns>
            /// <remarks>
            /// The Windows provided codecs do not implement this method and return (E_NOTIMPL, false).
            /// </remarks>
            System::ValueTuple<HRESULT, bool> MatchesMimeType(
                System::String ^mimeType
            );
        };
    }
}