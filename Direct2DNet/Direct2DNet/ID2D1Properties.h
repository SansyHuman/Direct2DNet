#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"

#include <vector>
#include <msclr/marshal.h>

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace msclr::interop;

namespace D2DNet
{
    namespace Direct2DNet
    {
        // Done.

        /// <summary>
        /// Represents a set of run-time bindable and discoverable properties that allow a
        /// data-driven application to modify the state of a Direct2D effect.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("483473d7-cd46-4f9d-9d3a-3112aa80159d")]
        public ref class ID2D1Properties : Direct2DNet::IDirect2DObject
        {
        internal:
            ::ID2D1Properties *m_pProperties;

        protected:
            ID2D1Properties() : m_pProperties(nullptr) {}

        internal:
            // Used in GetSubProperties and ID2D1Factory::GetEffectProperties
            ID2D1Properties(::ID2D1Properties *pProperties) : m_pProperties(pProperties) {}

        public:
            ~ID2D1Properties();
            !ID2D1Properties();

            virtual bool Equals(System::Object ^other) override;

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return reinterpret_cast<void *>(m_pProperties);
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Gets the total number of custom properties in this interface.
            /// </summary>
            property unsigned int PropertyCount
            {
                unsigned int get()
                {
                    return m_pProperties->GetPropertyCount();
                }
            }

            /// <summary>
            /// Retrieves the property name from the given property index.
            /// </summary>
            /// <returns>
            /// (HRESULT, string) tuple. If this method succeeds, HRESULT is S_OK. Otherwise, it is
            /// an error code. string is the name of the property.
            /// </returns>
            generic<typename U> System::ValueTuple<HRESULT, System::String ^> GetPropertyName(U index)
            {
                UINT32 intIndex = System::Convert::ToUInt32(index);

                UINT32 nameLength = m_pProperties->GetPropertyNameLength(intIndex);

                if(nameLength == 0)
                {
                    return System::ValueTuple<HRESULT, System::String ^>(D2DERR_INVALID_PROPERTY, "");
                }

                std::vector<wchar_t> name(nameLength + 1);

                HRESULT hr = m_pProperties->GetPropertyName(intIndex, name.data(), nameLength + 1);

                return System::ValueTuple<HRESULT, System::String ^>(
                    hr, marshal_as<System::String ^>(name.data())
                    );
            }

            /// <summary>
            /// Retrieves the property name from the given property index.
            /// </summary>
            /// <param name="name">The name of the property(out parameter).</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            generic<typename U> HRESULT GetPropertyName(
                U index,
                [OutAttribute] System::String ^%name)
            {
                UINT32 intIndex = System::Convert::ToUInt32(index);

                UINT32 nameLength = m_pProperties->GetPropertyNameLength(intIndex);

                if(nameLength == 0)
                {
                    name = "";
                    return D2DERR_INVALID_PROPERTY;
                }

                std::vector<wchar_t> nativeName(nameLength + 1);

                HRESULT hr = m_pProperties->GetPropertyName(intIndex, nativeName.data(), nameLength + 1);

                name = marshal_as<System::String ^>(nativeName.data());
                return hr;
            }

            /// <summary>
            /// Returns the length of the property name from the given index.
            /// </summary>
            generic<typename U> unsigned int GetPropertyNameLength(U index)
            {
                return m_pProperties->GetPropertyNameLength(System::Convert::ToUInt32(index));
            }

            /// <summary>
            /// Retrieves the type of the given property.
            /// </summary>
            generic<typename U> Direct2DNet::D2D1_PROPERTY_TYPE GetType(U index)
            {
                return (Direct2DNet::D2D1_PROPERTY_TYPE)((int)
                    m_pProperties->GetType(System::Convert::ToUInt32(index))
                    );
            }

            /// <summary>
            /// Retrieves the property index for the given property name.
            /// </summary>
            unsigned int GetPropertyIndex(System::String ^name);

            /// <summary>
            /// Sets the value of the given property using its name.
            /// </summary>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT SetValueByName(
                System::String ^name,
                Direct2DNet::D2D1_PROPERTY_TYPE type,
                void *data,
                unsigned int dataSize
            );

            /// <summary>
            /// Sets the value of the given property using its name.
            /// </summary>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            generic<typename T> HRESULT SetValueByName(System::String ^propertyName, T value)
            {
                marshal_context context;

                pin_ptr<T> pValue = &value;
                return m_pProperties->SetValueByName(
                    context.marshal_as<PCWSTR>(propertyName),
                    reinterpret_cast<const BYTE *>(pValue),
                    sizeof(value)
                );
            }

            /// <summary>
            /// Sets the given value using the property index.
            /// </summary>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT SetValue(
                unsigned int index,
                Direct2DNet::D2D1_PROPERTY_TYPE type,
                void *data,
                unsigned int dataSize
            );

            /// <summary>
            /// Sets the given value using the property index.
            /// </summary>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            generic<typename U> HRESULT SetValue(
                U index,
                void *data,
                unsigned int dataSize
            )
            {
                return m_pProperties->SetValue(
                    System::Convert::ToUInt32(index),
                    (BYTE *)data,
                    dataSize
                );
            }

            /// <summary>
            /// Sets the given value using the property index.
            /// </summary>
            generic<typename T, typename U> HRESULT SetValue(U index, T value)
            {
                pin_ptr<T> pValue = &value;
                return m_pProperties->SetValue(
                    System::Convert::ToUInt32(index),
                    reinterpret_cast<const BYTE *>(pValue),
                    sizeof(value)
                );
            }

            /// <summary>
            /// Retrieves the given property or sub-property by name. '.' is the delimiter for
            /// sub-properties.
            /// </summary>
            /// <param name="data">The property(out pointer).</param>
            /// <param name="dataSize">The number of bytes in the data to be retrieved.</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT GetValueByName(
                System::String ^name,
                Direct2DNet::D2D1_PROPERTY_TYPE type,
                void *data,
                unsigned int dataSize
            );

            /// <summary>
            /// Retrieves the given property or sub-property by name. '.' is the delimiter for
            /// sub-properties.
            /// </summary>
            /// <param name="data">The property(out pointer).</param>
            /// <param name="dataSize">The number of bytes in the data to be retrieved.</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT GetValueByName(
                System::String ^name,
                void *data,
                unsigned int dataSize
            );

            /// <summary>
            /// Retrieves the given property or sub-property by name. '.' is the delimiter for
            /// sub-properties.
            /// </summary>
            /// <param name="value">The property(out parameter).</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            generic<typename T> HRESULT GetValueByName(
                System::String ^propertyName,
                [OutAttribute] T %value
            )
            {
                marshal_context context;

                pin_ptr<T> pValue = &value;
                HRESULT hr = m_pProperties->GetValueByName(
                    context.marshal_as<PCWSTR>(propertyName),
                    reinterpret_cast<BYTE *>(pValue),
                    sizeof(value)
                );
                pValue = nullptr;

                return hr;
            }

            /// <summary>
            /// Retrieves the given property or sub-property by name. '.' is the delimiter for
            /// sub-properties.
            /// </summary>
            /// <returns>
            /// The property. Ignores the error.
            /// </returns>
            generic<typename T> T GetValueByName(System::String ^propertyName)
            {
                marshal_context context;

                T value;

                pin_ptr<T> pValue = &value;
                HRESULT hr = m_pProperties->GetValueByName(
                    context.marshal_as<PCWSTR>(propertyName),
                    reinterpret_cast<BYTE *>(pValue),
                    sizeof(value)
                );
                pValue = nullptr;

                UNREFERENCED_PARAMETER(hr);

                return value;
            }

            /// <summary>
            /// Retrieves the given value by index.
            /// </summary>
            /// <param name="data">The property(out pointer).</param>
            /// <param name="dataSize">The number of bytes in the data to be retrieved.</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT GetValue(
                unsigned int index,
                Direct2DNet::D2D1_PROPERTY_TYPE type,
                void *data,
                unsigned int dataSize
            );

            /// <summary>
            /// Retrieves the given value by index.
            /// </summary>
            /// <param name="data">The property(out pointer).</param>
            /// <param name="dataSize">The number of bytes in the data to be retrieved.</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            HRESULT GetValue(
                unsigned int index,
                void *data,
                unsigned int dataSize
            );

            /// <summary>
            /// Retrieves the given value by index.
            /// </summary>
            /// <param name="value">The property(out parameter).</param>
            /// <returns>
            /// If this method succeeds, S_OK. Otherwise, an error code.
            /// </returns>
            generic<typename T, typename U> HRESULT GetValue(U index, [OutAttribute] T %value)
            {
                pin_ptr<T> pValue = &value;

                return m_pProperties->GetValue(
                    System::Convert::ToUInt32(index),
                    reinterpret_cast<BYTE *>(pValue),
                    sizeof(value)
                );
            }

            /// <summary>
            /// Retrieves the given value by index.
            /// </summary>
            /// <returns>
            /// The property. Ignores the error.
            /// </returns>
            generic<typename T, typename U> T GetValue(U index)
            {
                T value;

                pin_ptr<T> pValue = &value;
                HRESULT hr = m_pProperties->GetValue(
                    System::Convert::ToUInt32(index),
                    reinterpret_cast<BYTE *>(pValue),
                    sizeof(value)
                );
                pValue = nullptr;

                UNREFERENCED_PARAMETER(hr);

                return value;
            }

            /// <summary>
            /// Returns the value size for the given property index.
            /// </summary>
            generic<typename U> unsigned int GetValueSize(U index)
            {
                return m_pProperties->GetValueSize(System::Convert::ToUInt32(index));
            }

            /// <summary>
            /// Retrieves the sub-properties of the given property by index.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::ID2D1Properties"/>) tuple. If this method succeeds,
            /// HRESULT is S_OK. Otherwise, it is an error code. <see cref="Direct2DNet::ID2D1Properties"/>
            /// is the sub-properties.
            /// </returns>
            generic<typename U> System::ValueTuple<HRESULT, Direct2DNet::ID2D1Properties ^> GetSubProperties(
                U index
            )
            {
                ::ID2D1Properties *pNativeProperties = __nullptr;

                HRESULT hr = m_pProperties->GetSubProperties(
                    System::Convert::ToUInt32(index), &pNativeProperties
                );

                if(!pNativeProperties)
                {
                    return System::ValueTuple<HRESULT, Direct2DNet::ID2D1Properties ^>(hr, nullptr);
                }

                return System::ValueTuple<HRESULT, Direct2DNet::ID2D1Properties ^>(
                    hr,
                    gcnew Direct2DNet::ID2D1Properties(pNativeProperties)
                    );
            }

            /// <summary>
            /// Retrieves the sub-properties of the given property by index.
            /// </summary>
            /// <returns>
            /// (HRESULT, <see cref="Direct2DNet::ID2D1Properties"/>) tuple. If this method succeeds,
            /// HRESULT is S_OK. Otherwise, it is an error code. <see cref="Direct2DNet::ID2D1Properties"/>
            /// is the sub-properties.
            /// </returns>
            generic<typename U> HRESULT GetSubProperties(
                U index,
                [OutAttribute] Direct2DNet::ID2D1Properties ^%subProperties
            )
            {
                ::ID2D1Properties *pNativeProperties = __nullptr;

                HRESULT hr = m_pProperties->GetSubProperties(
                    System::Convert::ToUInt32(index), &pNativeProperties
                );

                if(!pNativeProperties)
                {
                    subProperties = nullptr;
                    return hr;
                }

                subProperties = gcnew Direct2DNet::ID2D1Properties(pNativeProperties);
                return hr;
            }
        };
    }
}