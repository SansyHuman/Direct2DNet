#pragma once

#include <Unknwn.h>
#using <mscorlib.dll>

namespace D2DNet
{
    /// <summary>
    /// Root interface of all COM objects.
    /// </summary>
    [System::Runtime::InteropServices::GuidAttribute("00000000-0000-0000-C000-000000000046")]
    public interface class IUnknown
    {
        /// <summary>
        /// Gets the pointer to the COM interfaces which wrapper class contains.
        /// This property does not add reference count. So you should call AddRef(C++/CLI) or 
        /// make <see cref="D2DNet::ComObjectHandle"/>(C#) if you keep the reference to the object
        /// semi-permanently.
        /// </summary>
        property void *NativePointer
        {
            void *get();
        }

        /// <summary>
        /// Sets the pointer to the COM interfaces which wrapper class contains.
        /// This method takes the pointer to COM object and replace the current internal COM pointer
        /// to the newly accepted pointer. This method releases the previous object and automatically
        /// adds reference count to the new object.
        /// This method does not check the type or the state of the object, so it is not recommended to
        /// use this method by application.
        /// This method is used primarily for internal, so use this method if it is safe.
        /// </summary>
        [System::ObsoleteAttribute("This method is primarily for internal purpose, and could be unsafe.")]
        void HandleCOMInterface(void *obj);

        /// <summary>
        /// Receives the native pointer to the COM interface and decreases the reference count of the
        /// COM object.
        /// </summary>
        /// <returns>
        /// New reference count of the object.
        /// </returns>
        static ULONG Release(void *obj);

        /// <summary>
        /// Receives the native pointer to the COM interface and increases the reference count of the
        /// COM object.
        /// </summary>
        /// <returns>
        /// New reference count of the object.
        /// </returns>
        static ULONG AddRef(void *obj);
    };

    [System::Runtime::CompilerServices::ExtensionAttribute]
    public ref class IUnknownExtension abstract sealed
    {
    public:
        /// <summary>
        /// Queries a COM object for a wrapper to one of its interface; identifying the interface by a generic
        /// parameter.
        /// </summary>
        /// <typeparam name="T">A type that inherits from the IUnknown interface.</typeparam>
        /// <param name="queryObj">An object to query for(out parameter).</param>
        /// <returns>
        /// HRESULT error code.
        /// </returns>
        generic<typename T> where T : D2DNet::IUnknown
        [System::Runtime::CompilerServices::ExtensionAttribute]
        static HRESULT QueryInterface(
                D2DNet::IUnknown ^obj,
                [System::Runtime::InteropServices::OutAttribute] T %queryObj
        );

        /// <summary>
        /// Queries a COM object for a wrapper to one of its interface; identifying the interface by a GUID.
        /// </summary>
        /// <param name="riid">The guid of a object to query for.</param>
        /// <param name="queryObj">An object to query for(out parameter).</param>
        /// <returns>
        /// HRESULT error code.
        /// </returns>
        [System::Runtime::CompilerServices::ExtensionAttribute]
        static HRESULT QueryInterface(
            D2DNet::IUnknown ^obj,
            [System::Runtime::InteropServices::InAttribute][System::Runtime::CompilerServices::IsReadOnlyAttribute] System::Guid %riid,
            [System::Runtime::InteropServices::OutAttribute] D2DNet::IUnknown ^%queryObj
        );
    };

    /// <summary>
    /// Wrapper of native COM object reference.
    /// </summary>
    public ref class ComObjectHandle : D2DNet::IUnknown
    {
    internal:
        ::IUnknown *m_pObj;

    public:
        /// <summary>
        /// Receives the native COM object pointer and make wrapper object.
        /// The constructor receives the pointer from <see cref="D2DNet::IUnknown::NativePointer"/>
        /// property and automatically adds reference count.
        /// </summary>
        ComObjectHandle(void *pObj) : m_pObj(reinterpret_cast<::IUnknown *>(pObj))
        {
            m_pObj->AddRef();
        }

        ~ComObjectHandle()
        {
            this->!ComObjectHandle();
        }

        !ComObjectHandle()
        {
            if(m_pObj)
            {
                m_pObj->Release();
                m_pObj = nullptr;
            }
        }

        virtual property void *NativePointer
        {
            virtual void *get()
            {
                return m_pObj;
            }
        }

        virtual void HandleCOMInterface(void *obj)
        {
            if(m_pObj)
            {
                m_pObj->Release();
            }

            m_pObj = (::IUnknown *)obj;
            m_pObj->AddRef();
        }
    };
}