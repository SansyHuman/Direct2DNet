#pragma once

#include "IUnknown.h"
#include <ObjIdlbase.h>
#include <msclr/marshal.h>

using namespace msclr::interop;
using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    // Done.

    /// <summary>
    /// Enumerate strings. LPWSTR is the type that indicates a pointer to a zero-terminated string of wide,
    /// or Unicode, characters.
    /// </summary>
    [System::Runtime::InteropServices::GuidAttribute("00000101-0000-0000-C000-000000000046")]
    public ref class IEnumString : D2DNet::IUnknown
    {
    internal:
        ::IEnumString *m_pStr;

        IEnumString(::IEnumString *pStr) : m_pStr(pStr) {}

    public:
        ~IEnumString();
        !IEnumString();

        property void *NativePointer
        {
            virtual void *get()
            {
                return m_pStr;
            }
        }

        virtual void HandleCOMInterface(void *obj);

        /// <summary>
        /// Retrieves the specified number of items in the enumeration sequence.
        /// </summary>
        /// <param name="rgelt">
        /// A string array that receives enumerated items. The number of items to receive is the length of the
        /// array.
        /// </param>
        /// <param name="celtFetched">
        /// The number of items that were retrieved(out parameter). This parameter is always less than or
        /// equal to the number of items requested.
        /// </param>
        /// <returns>
        /// If the method retrieves the number of items requested, the return value is S_OK. Otherwise,
        /// it is S_FALSE.
        /// </returns>
        HRESULT Next(
            array<System::String ^> ^rgelt,
            [InteropServices::OutAttribute] ULONG %celtFetched
        );

        /// <summary>
        /// Skips over the specified number of items in the enumeration sequence.
        /// </summary>
        /// <param name="celt">
        /// The number of items to be skipped.
        /// </param>
        /// <returns>
        /// If the method skips the number of items requested, the return value is S_OK. Otherwise, it is
        /// S_FALSE.
        /// </returns>
        HRESULT Skip(ULONG celt);

        /// <summary>
        /// Resets the enumeration sequence to the beginning.
        /// </summary>
        /// <returns>
        /// The return value is S_OK.
        /// </returns>
        HRESULT Reset();

        /// <summary>
        /// Creates a new enumerator that contains the same enumeration state as the current one.
        /// </summary>
        /// <param name="enumStr">
        /// A parameter to receive the cloned enumerator object.
        /// </param>
        /// <returns>
        /// This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED,
        /// and S_OK.
        /// </returns>
        HRESULT Clone(
            [InteropServices::OutAttribute] D2DNet::IEnumString ^%enumStr
        );
    };
}