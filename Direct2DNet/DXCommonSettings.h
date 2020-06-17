#pragma once

#include <d3dcommon.h>

#include <comdef.h>
#include <msclr/marshal.h>

using namespace System::Runtime;
using namespace msclr::interop;

#ifdef NULL
#undef NULL
#endif

namespace D2DNet
{
    public enum class D3D_DRIVER_TYPE
    {
        UNKNOWN = ::D3D_DRIVER_TYPE_UNKNOWN,
        HARDWARE = ::D3D_DRIVER_TYPE_HARDWARE,
        REFERENCE = ::D3D_DRIVER_TYPE_REFERENCE,
        NULL = (D3D_DRIVER_TYPE_REFERENCE + 1),
        SOFTWARE = (D3D_DRIVER_TYPE_NULL + 1),
        WARP = (D3D_DRIVER_TYPE_SOFTWARE + 1)
    };

    public enum class D3D_FEATURE_LEVEL
    {
        D3D_FEATURE_LEVEL_1_0_CORE = 0x1000,
        D3D_FEATURE_LEVEL_9_1 = 0x9100,
        D3D_FEATURE_LEVEL_9_2 = 0x9200,
        D3D_FEATURE_LEVEL_9_3 = 0x9300,
        D3D_FEATURE_LEVEL_10_0 = 0xa000,
        D3D_FEATURE_LEVEL_10_1 = 0xa100,
        D3D_FEATURE_LEVEL_11_0 = 0xb000,
        D3D_FEATURE_LEVEL_11_1 = 0xb100,
        D3D_FEATURE_LEVEL_12_0 = 0xc000,
        D3D_FEATURE_LEVEL_12_1 = 0xc100
    };

    public value struct LUID
    {
        DWORD lowPart;
        LONG highPart;

        static operator ::LUID(D2DNet::LUID %rhs)
        {
            ::LUID value;
            value.LowPart = rhs.lowPart;
            value.HighPart = rhs.highPart;

            return value;
        }

        static operator D2DNet::LUID(::LUID %rhs)
        {
            D2DNet::LUID value;
            value.lowPart = rhs.LowPart;
            value.highPart = rhs.HighPart;

            return value;
        }
    };

    [InteropServices::StructLayoutAttribute(InteropServices::LayoutKind::Explicit)]
    public value struct LARGE_INTEGER
    {
        [InteropServices::FieldOffsetAttribute(0)]
        DWORD lowPart;
        [InteropServices::FieldOffsetAttribute(4)]
        LONG highPart;
        [InteropServices::FieldOffsetAttribute(0)]
        LONGLONG quadPart;

        LARGE_INTEGER(LONGLONG value) : quadPart(value) {}
        LARGE_INTEGER(DWORD lowPart, LONG highPart) : lowPart(lowPart), highPart(highPart) {};

        static operator D2DNet::LARGE_INTEGER(LONGLONG rhs)
        {
            D2DNet::LARGE_INTEGER value;
            value.quadPart = rhs;

            return value;
        }

        static operator LONGLONG(D2DNet::LARGE_INTEGER rhs)
        {
            return rhs.quadPart;
        }

        static operator ::LARGE_INTEGER(D2DNet::LARGE_INTEGER %rhs)
        {
            ::LARGE_INTEGER value;
            value.QuadPart = rhs.quadPart;

            return value;
        }

        static operator D2DNet::LARGE_INTEGER(::LARGE_INTEGER %rhs)
        {
            D2DNet::LARGE_INTEGER value;
            value.quadPart = rhs.QuadPart;

            return value;
        }
    };

    [InteropServices::StructLayoutAttribute(InteropServices::LayoutKind::Explicit)]
    public value struct ULARGE_INTEGER
    {
        [InteropServices::FieldOffsetAttribute(0)]
        DWORD lowPart;
        [InteropServices::FieldOffsetAttribute(4)]
        DWORD highPart;
        [InteropServices::FieldOffsetAttribute(0)]
        ULONGLONG quadPart;

        ULARGE_INTEGER(ULONGLONG value) : quadPart(value) {}
        ULARGE_INTEGER(DWORD lowPart, DWORD highPart) : lowPart(lowPart), highPart(highPart) {};

        static operator D2DNet::ULARGE_INTEGER(ULONGLONG rhs)
        {
            D2DNet::ULARGE_INTEGER value;
            value.quadPart = rhs;

            return value;
        }

        static operator ULONGLONG(D2DNet::ULARGE_INTEGER rhs)
        {
            return rhs.quadPart;
        }

        static operator ::ULARGE_INTEGER(D2DNet::ULARGE_INTEGER %rhs)
        {
            ::ULARGE_INTEGER value;
            value.QuadPart = rhs.quadPart;

            return value;
        }

        static operator D2DNet::ULARGE_INTEGER(::ULARGE_INTEGER %rhs)
        {
            D2DNet::ULARGE_INTEGER value;
            value.quadPart = rhs.QuadPart;

            return value;
        }
    };

    /// <summary>
    /// Represents a rectangle defined by the int-type coordinates of the upper-left corner
    /// (left, top) and the coordinates of the lower-right corner (right, bottom).
    /// </summary>
    public value struct RECT
    {
        LONG left;
        LONG top;
        LONG right;
        LONG bottom;

        RECT(LONG left, LONG top, LONG right, LONG bottom) : left(left), top(top), right(right), bottom(bottom) {}

        static operator ::RECT(D2DNet::RECT %rhs)
        {
            ::RECT value;
            value.left = rhs.left;
            value.top = rhs.top;
            value.right = rhs.right;
            value.bottom = rhs.bottom;

            return value;
        }

        static operator D2DNet::RECT(::RECT %rhs)
        {
            D2DNet::RECT value;
            value.left = rhs.left;
            value.top = rhs.top;
            value.right = rhs.right;
            value.bottom = rhs.bottom;

            return value;
        }
    };

    public value struct POINT
    {
        LONG x;
        LONG y;

        POINT(LONG x, LONG y) : x(x), y(y) {}

        static operator ::POINT(D2DNet::POINT %rhs)
        {
            ::POINT value;
            value.x = rhs.x;
            value.y = rhs.y;

            return value;
        }

        static operator D2DNet::POINT(::POINT %rhs)
        {
            D2DNet::POINT value;
            value.x = rhs.x;
            value.y = rhs.y;

            return value;
        }
    };

    public value struct DirectX abstract sealed
    {
    public:
        static System::Guid ToManagedGUID(const _GUID &guid);
        static _GUID ToNativeGUID(System::Guid %guid);
        static void ThrowIfFailed(HRESULT hr);
        static System::String ^GetErrorMessage(HRESULT hr);
    };
}

#ifndef NULL
#define NULL 0
#endif