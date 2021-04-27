#pragma once

#include "IWICObject.h"
#include "WICNetHeaders.h"
#include "WICSettings.h"
#include "../Direct2DNet/Exception/DXException.h"
#include <msclr/marshal.h>

using namespace msclr::interop;

namespace D2DNet
{
    namespace WICNet
    {
        ref class IWICImagingFactory;

        // Done.

        /// <summary>
        /// Exposes methods that provide component information.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("23BC3F0A-698B-4357-886B-F24D50671334")]
        public ref class IWICComponentInfo : WICNet::IWICObject
        {
        internal:
            ::IWICComponentInfo *m_pInfo;

            IWICComponentInfo() : m_pInfo(nullptr) {}

            IWICComponentInfo(::IWICComponentInfo *pInfo) : m_pInfo(pInfo) {}

            // CreateComponentInfo
            IWICComponentInfo(
                WICNet::IWICImagingFactory ^factory,
                System::Guid %clsid
            );

        public:
            ~IWICComponentInfo();
            !IWICComponentInfo();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pInfo;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Retrieves the component's <see cref="WICNet::WICComponentType"/>.
            /// </summary>
            /// <param name="type">
            /// A parameter that receives the <see cref="WICNet::WICComponentType"/>(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetComponentType(
                [OutAttribute] WICNet::WICComponentType %type
            );

            /// <summary>
            /// Retrieves the component's <see cref="WICNet::WICComponentType"/>.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="WICNet::WICComponentType"/>) tuple. If this method succeeds,
            /// HRESULT is S_OK. Otherwise, it is an HRESULT error code.
            /// <see cref="WICNet::WICComponentType"/> is the component type.
            /// </returns>
            System::ValueTuple<HRESULT, WICNet::WICComponentType> GetComponentType();

            /// <summary>
            /// Retrieves the component's class identifier (CLSID).
            /// </summary>
            /// <param name="clsid">
            /// A parameter that receives the component's CLSID(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetCLSID(
                [OutAttribute] System::Guid %clsid
            );

            /// <summary>
            /// Retrieves the signing status of the component.
            /// </summary>
            /// <param name="status">
            /// A parameter that receives the <see cref="WICNet::WICComponentSigning"/> status of the
            /// component(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetSigningStatus(
                [OutAttribute] WICNet::WICComponentSigning %status
            );

            /// <summary>
            /// Retrieves the signing status of the component.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="WICNet::WICComponentSigning"/>) tuple. If this method succeeds,
            /// HRESULT is S_OK. Otherwise, it is an HRESULT error code.
            /// <see cref="WICNet::WICComponentType"/> is the signing status.
            /// </returns>
            System::ValueTuple<HRESULT, WICNet::WICComponentSigning> GetSigningStatus();

            /// <summary>
            /// Retrieves the name of component's author.
            /// </summary>
            /// <param name="author">
            /// A parameter that receives the name of the component's author(out parameter). The locale of
            /// the string depends on the value that the codec wrote to the registry at install time.
            /// For built-in components, these strings are always in English.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetAuthor(
                [OutAttribute] System::String ^%author
            );

            /// <summary>
            /// Retrieves the vendor GUID.
            /// </summary>
            /// <param name="guidVendor">
            /// A parameter that receives the component's vendor GUID(out parameter). The list of built-in 
            /// vendor GUIDs is in the <see cref="WICNet::VendorGUID"/> class.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetVendorGUID(
                [OutAttribute] System::Guid %guidVendor
            );

            /// <summary>
            /// Retrieves the component's version.
            /// </summary>
            /// <param name="version">
            /// A parameter that receives a culture invariant string of the component's version(out parameter).
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetVersion(
                [OutAttribute] System::String ^%version
            );

            /// <summary>
            /// Retrieves the component's specification version.
            /// </summary>
            /// <param name="specVersion">
            /// When this method returns, contain a culture invarient string of the component's specification
            /// version(out parameter). The version form is NN.NN.NN.NN.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetSpecVersion(
                [OutAttribute] System::String ^%specVersion
            );

            /// <summary>
            /// Retrieves the component's friendly name, which is a human-readable display name for
            /// the component.
            /// </summary>
            /// <param name="friendlyName">
            /// A parameter that receives the friendly name of the component(out parameter). The locale of
            /// the string depends on the value that the codec wrote to the registry at install time.
            /// For built-in components, these strings are always in English.
            /// </param>
            /// <returns>
            /// If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
            /// </returns>
            HRESULT GetFriendlyName(
                [OutAttribute] System::String ^%friendlyName
            );
        };
    }
}