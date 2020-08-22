#pragma once

#include <d3dcommon.h>

#include <comdef.h>
#include <msclr/marshal.h>
#include <wchar.h>

using namespace System::Runtime;
using namespace msclr::interop;

#ifdef NULL
#undef NULL
#endif

namespace D2DNet
{
    /// <summary>
    /// Driver type options.
    /// </summary>
    public enum class D3D_DRIVER_TYPE
    {
        /// <summary>
        /// The driver type is unknown.
        /// </summary>
        UNKNOWN = ::D3D_DRIVER_TYPE_UNKNOWN,

        /// <summary>
        /// A hardware driver, which implements Direct3D features in hardware. This is the primary driver
        /// that you should use in your Direct3D applications because it provides the best performance.
        /// A hardware driver uses hardware acceleration (on supported hardware) but can also use software
        /// for parts of the pipeline that are not supported in hardware. This driver type is often referred
        /// to as a hardware abstraction layer or HAL.
        /// </summary>
        HARDWARE = ::D3D_DRIVER_TYPE_HARDWARE,

        /// <summary>
        /// A reference driver, which is a software implementation that supports every Direct3D feature.
        /// A reference driver is designed for accuracy rather than speed and as a result is slow but
        /// accurate. The rasterizer portion of the driver does make use of special CPU instructions
        /// whenever it can, but it is not intended for retail applications; use it only for feature testing,
        /// demonstration of functionality, debugging, or verifying bugs in other drivers. The reference
        /// device for this driver is installed by the Windows SDK 8.0 or later and is intended only as a
        /// debug aid for development purposes. This driver may be referred to as a REF driver, a reference
        /// driver, or a reference rasterizer.
        /// </summary>
        REFERENCE = ::D3D_DRIVER_TYPE_REFERENCE,

        /// <summary>
        /// A NULL driver, which is a reference driver without render capability. This driver is commonly
        /// used for debugging non-rendering API calls, it is not appropriate for retail applications.
        /// This driver is installed by the DirectX SDK.
        /// </summary>
        NULL = (::D3D_DRIVER_TYPE_REFERENCE + 1),

        /// <summary>
        /// A software driver, which is a driver implemented completely in software. The software
        /// implementation is not intended for a high-performance application due to its very slow performance.
        /// </summary>
        SOFTWARE = (::D3D_DRIVER_TYPE_NULL + 1),

        /// <summary>
        /// A WARP driver, which is a high-performance software rasterizer. The rasterizer supports feature
        /// levels 9_1 through level 10_1 with a high performance software implementation.
        /// </summary>
        WARP = (::D3D_DRIVER_TYPE_SOFTWARE + 1)
    };

    /// <summary>
    /// Describes the set of features targeted by a Direct3D device.
    /// </summary>
    public enum class D3D_FEATURE_LEVEL
    {
        /// <summary>
        /// Allows Microsoft Compute Driver Model (MCDM) devices to be used, or more feature-rich devices
        /// (such as traditional GPUs) that support a superset of the functionality. MCDM is the overall
        /// driver model for compute-only; it's a scaled-down peer of the larger scoped Windows Device
        /// Driver Model (WDDM).
        /// </summary>
        LEVEL_1_0_CORE = 0x1000,

        /// <summary>
        /// Targets features supported by feature level 9.1, including shader model 2.
        /// </summary>
        LEVEL_9_1 = 0x9100,

        /// <summary>
        /// Targets features supported by feature level 9.2, including shader model 2.
        /// </summary>
        LEVEL_9_2 = 0x9200,

        /// <summary>
        /// Targets features supported by feature level 9.3, including shader model 2.0b.
        /// </summary>
        LEVEL_9_3 = 0x9300,

        /// <summary>
        /// Targets features supported by Direct3D 10.0, including shader model 4.
        /// </summary>
        LEVEL_10_0 = 0xa000,

        /// <summary>
        /// Targets features supported by Direct3D 10.1, including shader model 4.
        /// </summary>
        LEVEL_10_1 = 0xa100,

        /// <summary>
        /// Targets features supported by Direct3D 11.0, including shader model 5.
        /// </summary>
        LEVEL_11_0 = 0xb000,

        /// <summary>
        /// Targets features supported by Direct3D 11.1, including shader model 5 and logical blend operations.
        /// This feature level requires a display driver that is at least implemented to WDDM for Windows
        /// 8 (WDDM 1.2).
        /// </summary>
        LEVEL_11_1 = 0xb100,

        /// <summary>
        /// Targets features supported by Direct3D 12.0, including shader model 5.
        /// </summary>
        LEVEL_12_0 = 0xc000,

        /// <summary>
        /// Targets features supported by Direct3D 12.1, including shader model 5.
        /// </summary>
        LEVEL_12_1 = 0xc100
    };

    /// <summary>
    /// Describes a local identifier for an adapter.
    /// </summary>
    public value struct LUID
    {
        /// <summary>
        /// Specifies a DWORD that contains the unsigned lower numbers of the id.
        /// </summary>
        DWORD lowPart;

        /// <summary>
        /// Specifies a LONG that contains the signed high numbers of the id.
        /// </summary>
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

    /// <summary>
    /// Represents a 64-bit signed integer value.
    /// </summary>
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

    /// <summary>
    /// Represents a 64-bit unsigned integer value.
    /// </summary>
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

    /// <summary>
    /// The POINT structure defines the x- and y-coordinates of a point.
    /// </summary>
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

    /// <summary>
    /// The SIZE structure defines the width and height of a rectangle.
    /// </summary>
    public value struct SIZE
    {
        /// <summary>
        /// Specifies the rectangle's width. The units depend on which function uses this structure.
        /// </summary>
        LONG        cx;

        /// <summary>
        /// Specifies the rectangle's height. The units depend on which function uses this structure.
        /// </summary>
        LONG        cy;

        SIZE(LONG cx, LONG cy) : cx(cx), cy(cy) {}

        static operator ::SIZE(D2DNet::SIZE %rhs)
        {
            ::SIZE value;
            value.cx = rhs.cx;
            value.cy = rhs.cy;

            return value;
        }

        static operator D2DNet::SIZE(::SIZE %rhs)
        {
            D2DNet::SIZE value;
            value.cx = rhs.cx;
            value.cy = rhs.cy;

            return value;
        }
    };

    /// <summary>
    /// The enum of character sets used in <see cref="D2DNet::LOGFONTW"/>.
    /// </summary>
    public enum class CHARSET : BYTE
    {
        ANSI = ANSI_CHARSET,
        DEFAULT = DEFAULT_CHARSET,
        SYMBOL = SYMBOL_CHARSET,
        SHIFTJIS = SHIFTJIS_CHARSET,
        HANGUL = HANGUL_CHARSET,
        GB2312 = GB2312_CHARSET,
        CHINESEBIG5 = CHINESEBIG5_CHARSET,
        OEM = OEM_CHARSET,
        JOHAB = JOHAB_CHARSET,
        HEBREW = HEBREW_CHARSET,
        ARABIC = ARABIC_CHARSET,
        GREEK = GREEK_CHARSET,
        TURKISH = TURKISH_CHARSET,
        VIETNAMESE = VIETNAMESE_CHARSET,
        THAI = THAI_CHARSET,
        EASTEUROPE = EASTEUROPE_CHARSET,
        RUSSIAN = RUSSIAN_CHARSET,
        MAC = MAC_CHARSET,
        BALTIC = BALTIC_CHARSET
    };

    /// <summary>
    /// The enum of output precisions used in <see cref="D2DNet::LOGFONTW"/>.
    /// </summary>
    public enum class OUT_PRECISION : BYTE
    {
        /// <summary>
        /// Specifies the default font mapper behavior.
        /// </summary>
        DEFAULT = OUT_DEFAULT_PRECIS,

        /// <summary>
        /// This value is not used by the font mapper, but it is returned when raster fonts are enumerated.
        /// </summary>
        STRING = OUT_STRING_PRECIS,

        /// <summary>
        /// Not used.
        /// </summary>
        CHARACTER = OUT_CHARACTER_PRECIS,

        /// <summary>
        /// This value is not used by the font mapper, but it is returned when TrueType, other outline-based
        /// fonts, and vector fonts are enumerated.
        /// </summary>
        STROKE = OUT_STROKE_PRECIS,

        /// <summary>
        /// Instructs the font mapper to choose a TrueType font when the system contains multiple fonts
        /// with the same name.
        /// </summary>
        TT = OUT_TT_PRECIS,

        /// <summary>
        /// Instructs the font mapper to choose a Device font when the system contains multiple fonts with
        /// the same name.
        /// </summary>
        DEVICE = OUT_DEVICE_PRECIS,

        /// <summary>
        /// Instructs the font mapper to choose a raster font when the system contains multiple fonts with
        /// the same name.
        /// </summary>
        RASTER = OUT_RASTER_PRECIS,

        /// <summary>
        /// Instructs the font mapper to choose from only TrueType fonts. If there are no TrueType fonts
        /// installed in the system, the font mapper returns to default behavior.
        /// </summary>
        TT_ONLY = OUT_TT_ONLY_PRECIS,

        /// <summary>
        /// This value instructs the font mapper to choose from TrueType and other outline-based fonts.
        /// </summary>
        OUTLINE = OUT_OUTLINE_PRECIS,

        SCREEN_OUTLINE = OUT_SCREEN_OUTLINE_PRECIS,

        /// <summary>
        /// Instructs the font mapper to choose from only PostScript fonts. If there are no PostScript
        /// fonts installed in the system, the font mapper returns to default behavior.
        /// </summary>
        PS_ONLY = OUT_PS_ONLY_PRECIS
    };

    /// <summary>
    /// The enum of clipping precisions used in <see cref="D2DNet::LOGFONTW"/>.
    /// </summary>
    [System::FlagsAttribute]
    public enum class CLIP_PRECISION : BYTE
    {
        /// <summary>
        /// Specifies default clipping behavior.
        /// </summary>
        DEFAULT = CLIP_DEFAULT_PRECIS,

        /// <summary>
        /// Not used.
        /// </summary>
        CHARACTER = CLIP_CHARACTER_PRECIS,

        /// <summary>
        /// Not used by the font mapper, but is returned when raster, vector, or TrueType fonts are
        /// enumerated. For compatibility, this value is always returned when enumerating fonts. 
        /// </summary>
        STROKE = CLIP_STROKE_PRECIS,

        /// <summary>
        /// When this value is used, the rotation for all fonts depends on whether the orientation of the
        /// coordinate system is left-handed or right-handed.If not used, device fonts always rotate
        /// counterclockwise, but the rotation of other fonts is dependent on the orientation of the
        /// coordinate system. 
        /// </summary>
        LH_ANGLES = CLIP_LH_ANGLES,

        /// <summary>
        /// Not used.
        /// </summary>
        TT_ALWAYS = CLIP_TT_ALWAYS,

        /// <summary>
        /// Turns off font association for the font. Note that this flag is not guaranteed to have any
        /// effect on any platform after Windows Server 2003.
        /// </summary>
        DFA_DISABLE = CLIP_DFA_DISABLE,

        /// <summary>
        /// You must specify this flag to use an embedded read-only font.
        /// </summary>
        EMBEDDED = CLIP_EMBEDDED
    };

    /// <summary>
    /// The enum of output qualities used in <see cref="D2DNet::LOGFONTW"/>.
    /// </summary>
    public enum class OUT_QUALITY : BYTE
    {
        /// <summary>
        /// Appearance of the font does not matter.
        /// </summary>
        DEFAULT = DEFAULT_QUALITY,

        /// <summary>
        /// Appearance of the font is less important than when PROOF is used. For GDI raster fonts, scaling
        /// is enabled, which means that more font sizes are available, but the quality may be lower. Bold, 
        /// italic, underline, and strikeout fonts are synthesized if necessary.
        /// </summary>
        DRAFT = DRAFT_QUALITY,

        /// <summary>
        /// Character quality of the font is more important than exact matching of the logical-font attributes.
        /// For GDI raster fonts, scaling is disabled and the font closest in size is chosen. Although the
        /// chosen font size may not be mapped exactly when PROOF is used, the quality of the font is high
        /// and there is no distortion of appearance. Bold, italic, underline, and strikeout fonts are
        /// synthesized if necessary.
        /// </summary>
        PROOF = PROOF_QUALITY,

        /// <summary>
        /// Font is never antialiased.
        /// </summary>
        NONANTIALIASED = NONANTIALIASED_QUALITY,

        /// <summary>
        /// Font is always antialiased if the font supports it and the size of the font is not too small
        /// or too large.
        /// </summary>
        ANTIALIASED = ANTIALIASED_QUALITY,

        /// <summary>
        /// If set, text is rendered (when possible) using ClearType antialiasing method.
        /// </summary>
        CLEARTYPE = CLEARTYPE_QUALITY,

        CLEARTYPE_NATURAL = CLEARTYPE_NATURAL_QUALITY
    };

    /// <summary>
    /// The enum of font pitches used in <see cref="D2DNet::LOGFONTW"/>.
    /// </summary>
    public enum class FONT_PITCH : BYTE
    {
        DEFAULT = DEFAULT_PITCH,
        FIXED = FIXED_PITCH,
        VARIABLE = VARIABLE_PITCH
    };

    /// <summary>
    /// The enum of font families used in <see cref="D2DNet::LOGFONTW"/>.
    /// </summary>
    public enum class FONT_FAMILY : BYTE
    {
        /// <summary>
        /// Don't care or don't know.
        /// </summary>
        DONTCARE = FF_DONTCARE,

        /// <summary>
        /// Variable stroke width, serifed.
        /// </summary>
        ROMAN = FF_ROMAN,

        /// <summary>
        /// Variable stroke width, sans-serifed.
        /// </summary>
        SWISS = FF_SWISS,

        /// <summary>
        /// Constant stroke width, serifed or sans-serifed.
        /// </summary>
        MODERN = FF_MODERN,

        /// <summary>
        /// Cursive, etc.
        /// </summary>
        SCRIPT = FF_SCRIPT,

        /// <summary>
        /// Old English, etc.
        /// </summary>
        DECORATIVE = FF_DECORATIVE
    };

    /// <summary>
    /// The LOGFONT structure defines the attributes of a font.
    /// </summary>
    public value struct LOGFONTW
    {
        /// <summary>
        /// <para>
        /// The height, in logical units, of the font's character cell or character. The character height
        /// value (also known as the em height) is the character cell height value minus the internal-leading
        /// value. The font mapper interprets the value specified in lfHeight in the following manner.
        /// </para>
        /// <para>
        ///     positive: The font mapper transforms this value into device units and matches it against the
        /// cell height of the available fonts.
        /// </para>
        /// <para>
        ///     0: The font mapper uses a default height value when it searches for a match.
        /// </para>
        /// <para>
        ///     negative: The font mapper transforms this value into device units and matches its absolute
        /// value against the character height of the available fonts.
        /// </para>
        /// </summary>
        LONG            lfHeight;

        /// <summary>
        /// The average width, in logical units, of characters in the font. If lfWidth is zero, the aspect
        /// ratio of the device is matched against the digitization aspect ratio of the available fonts to
        /// find the closest match, determined by the absolute value of the difference.
        /// </summary>
        LONG            lfWidth;

        /// <summary>
        /// The angle, in tenths of degrees, between the escapement vector and the x-axis of the device.
        /// The escapement vector is parallel to the base line of a row of text.
        /// </summary>
        LONG            lfEscapement;

        /// <summary>
        /// The angle, in tenths of degrees, between each character's base line and the x-axis of the device.
        /// </summary>
        LONG            lfOrientation;

        /// <summary>
        /// The weight of the font in the range 0 through 1000. For example, 400 is normal and 700 is bold.
        /// If this value is zero, a default weight is used.
        /// </summary>
        LONG            lfWeight;

        /// <summary>
        /// An italic font if set to true.
        /// </summary>
        bool            lfItalic;

        /// <summary>
        /// An underlined font if set to true.
        /// </summary>
        bool            lfUnderline;

        /// <summary>
        /// A strikeout font if set to true.
        /// </summary>
        bool            lfStrikeOut;

        /// <summary>
        /// The character set.
        /// </summary>
        D2DNet::CHARSET lfCharSet;

        /// <summary>
        /// The output precision. The output precision defines how closely the output must match the
        /// requested font's height, width, character orientation, escapement, pitch, and font type.
        /// </summary>
        D2DNet::OUT_PRECISION lfOutPrecision;

        /// <summary>
        /// The clipping precision. The clipping precision defines how to clip characters that are
        /// partially outside the clipping region.
        /// </summary>
        D2DNet::CLIP_PRECISION lfClipPrecision;

        /// <summary>
        /// The output quality. The output quality defines how carefully the graphics device interface
        /// (GDI) must attempt to match the logical-font attributes to those of an actual physical font.
        /// </summary>
        D2DNet::OUT_QUALITY lfQuality;

        /// <summary>
        /// The pitch of the font.
        /// </summary>
        D2DNet::FONT_PITCH lfPitch;

        /// <summary>
        /// The family of the font.
        /// </summary>
        D2DNet::FONT_FAMILY lfFamily;

        /// <summary>
        /// A null-terminated string that specifies the typeface name of the font. The length of this
        /// string must not exceed 32 TCHAR values, including the terminating null.
        /// </summary>
        System::String ^lfFaceName;

        static operator ::LOGFONTW(D2DNet::LOGFONTW %rhs)
        {
            marshal_context context;

            ::LOGFONTW value;
            value.lfHeight = rhs.lfHeight;
            value.lfWidth = rhs.lfWidth;
            value.lfEscapement = rhs.lfEscapement;
            value.lfOrientation = rhs.lfOrientation;
            value.lfWeight = rhs.lfWeight;
            value.lfItalic = rhs.lfItalic;
            value.lfUnderline = rhs.lfUnderline;
            value.lfStrikeOut = rhs.lfStrikeOut;
            value.lfCharSet = (BYTE)rhs.lfCharSet;
            value.lfOutPrecision = (BYTE)rhs.lfOutPrecision;
            value.lfClipPrecision = (BYTE)rhs.lfClipPrecision;
            value.lfQuality = (BYTE)rhs.lfQuality;
            value.lfPitchAndFamily = (BYTE)rhs.lfPitch | (BYTE)rhs.lfFamily;
            ::wcscpy_s(value.lfFaceName, LF_FACESIZE, context.marshal_as<const WCHAR *>(rhs.lfFaceName));

            return value;
        }

        static operator D2DNet::LOGFONTW(::LOGFONTW %rhs)
        {
            D2DNet::LOGFONTW value;
            value.lfHeight = rhs.lfHeight;
            value.lfWidth = rhs.lfWidth;
            value.lfEscapement = rhs.lfEscapement;
            value.lfOrientation = rhs.lfOrientation;
            value.lfWeight = rhs.lfWeight;
            value.lfItalic = rhs.lfItalic;
            value.lfUnderline = rhs.lfUnderline;
            value.lfStrikeOut = rhs.lfStrikeOut;
            value.lfCharSet = (D2DNet::CHARSET)rhs.lfCharSet;
            value.lfOutPrecision = (D2DNet::OUT_PRECISION)rhs.lfOutPrecision;
            value.lfClipPrecision = (D2DNet::CLIP_PRECISION)rhs.lfClipPrecision;
            value.lfQuality = (D2DNet::OUT_QUALITY)rhs.lfQuality;
            value.lfPitch = (D2DNet::FONT_PITCH)(rhs.lfPitchAndFamily & 0b00000011);
            value.lfFamily = (D2DNet::FONT_FAMILY)(rhs.lfPitchAndFamily & 0b01111000);
            value.lfFaceName = marshal_as<System::String ^>(rhs.lfFaceName);

            return value;
        }
    };

    /// <summary>
    /// Values that are used in activation calls to indicate the execution contexts in which an object is
    /// to be run.
    /// </summary>
    [System::FlagsAttribute]
    public enum class CLSCTX : DWORD
    {
        /// <summary>
        /// The code that creates and manages objects of this class is a DLL that runs in the same process
        /// as the caller of the function specifying the class context.
        /// </summary>
        INPROC_SERVER = 0x1,

        /// <summary>
        /// The code that manages objects of this class is an in-process handler. This is a DLL that runs
        /// in the client process and implements client-side structures of this class when instances of
        /// the class are accessed remotely.
        /// </summary>
        INPROC_HANDLER = 0x2,

        /// <summary>
        /// The EXE code that creates and manages objects of this class runs on same machine but is loaded
        /// in a separate process space.
        /// </summary>
        LOCAL_SERVER = 0x4,

        /// <summary>
        /// Obsolete.
        /// </summary>
        [System::ObsoleteAttribute("Obsolete")]
        INPROC_SERVER16 = 0x8,

        /// <summary>
        /// A remote context. The LocalServer32 or LocalService code that creates and manages objects of
        /// this class is run on a different computer.
        /// </summary>
        REMOTE_SERVER = 0x10,

        /// <summary>
        /// Obsolete.
        /// </summary>
        [System::ObsoleteAttribute("Obsolete")]
        INPROC_HANDLER16 = 0x20,

        /// <summary>
        /// Reserved.
        /// </summary>
        [System::ObsoleteAttribute("Reserved")]
        RESERVED1 = 0x40,

        /// <summary>
        /// Reserved.
        /// </summary>
        [System::ObsoleteAttribute("Reserved")]
        RESERVED2 = 0x80,

        /// <summary>
        /// Reserved.
        /// </summary>
        [System::ObsoleteAttribute("Reserved")]
        RESERVED3 = 0x100,

        /// <summary>
        /// Reserved.
        /// </summary>
        [System::ObsoleteAttribute("Reserved")]
        RESERVED4 = 0x200,

        /// <summary>
        /// Disaables the downloading of code from the directory service or the Internet. This flag cannot
        /// be set at the same time as <see cref="D2DNet::CLSCTX::ENABLE_CODE_DOWNLOAD"/>.
        /// </summary>
        NO_CODE_DOWNLOAD = 0x400,

        /// <summary>
        /// Reserved.
        /// </summary>
        [System::ObsoleteAttribute("Reserved")]
        RESERVED5 = 0x800,

        /// <summary>
        /// Specify if you want the activation to fail if it uses custom marshalling.
        /// </summary>
        NO_CUSTOM_MARSHAL = 0x1000,

        /// <summary>
        /// Enables the downloading of code from the directory service or the Internet. This flag cannot be
        /// set at the same time as <see cref="D2DNet::CLSCTX::NO_CODE_DOWNLOAD"/>.
        /// </summary>
        ENABLE_CODE_DOWNLOAD = 0x2000,

        /// <summary>
        /// The NO_FAILURE_LOG can be used to override the logging of failures in CoCreateInstanceEx.
        /// </summary>
        NO_FAILURE_LOG = 0x4000,

        /// <summary>
        /// Disables activate-as-activator (AAA) activations for this activation only.
        /// </summary>
        DISABLE_AAA = 0x8000,

        /// <summary>
        /// Enables activate-as-activator (AAA) activations for this activation only.
        /// </summary>
        ENABLE_AAA = 0x10000,

        /// <summary>
        /// Begin this activation from the default context of the current apartment.
        /// </summary>
        FROM_DEFAULT_CONTEXT = 0x20000,

        /// <summary>
        /// Activate or connect to a 32-bit version of the server; fail if one is not registered.
        /// </summary>
        ACTIVATE_32_BIT_SERVER = 0x40000,

        /// <summary>
        /// Activate or connect to a 64 bit version of the server; fail if one is not registered.
        /// </summary>
        ACTIVATE_64_BIT_SERVER = 0x80000,

        /// <summary>
        /// When this flag is specified, COM uses the impersonation token of the thread, if one is present,
        /// for the activation request made by the thread. When this flag is not specified or if the thread
        /// does not have an impersonation token, COM uses the process token of the thread's process for
        /// the activation request made by the thread.
        /// </summary>
        ENABLE_CLOAKING = 0x100000,

        /// <summary>
        /// Indicates activation is for an app container.
        /// </summary>
        [System::ObsoleteAttribute("This flag is reserved for internal use and is not intended to be used directly from your code.")]
        APPCONTAINER = 0x400000,

        /// <summary>
        /// Specify this flag for Interactive User activation behavior for As-Activator servers. A strongly
        /// named Medium IL Windows Store app can use this flag to launch an "As Activator" COM server
        /// without a strong name. Also, you can use this flag to bind to a running instance of the COM
        /// server that's launched by a desktop application.
        /// </summary>
        ACTIVATE_AAA_AS_IU = 0x800000,

        /// <summary>
        /// Reserved.
        /// </summary>
        [System::ObsoleteAttribute("Reserved")]
        RESERVED6 = 0x1000000,

        ACTIVATE_ARM32_SERVER = 0x2000000,

        /// <summary>
        /// Used for loading Proxy/Stub DLLs.
        /// </summary>
        PS_DLL = 0x80000000
    };
    
    [InteropServices::StructLayoutAttribute(InteropServices::LayoutKind::Explicit)]
    public value struct DECIMAL
    {
        [InteropServices::FieldOffsetAttribute(0)]
        USHORT reserved;

        [InteropServices::FieldOffsetAttribute(2)]
        BYTE scale;
        
        [InteropServices::FieldOffsetAttribute(3)]
        BYTE sign;

        [InteropServices::FieldOffsetAttribute(2)]
        USHORT signscale;

        [InteropServices::FieldOffsetAttribute(4)]
        ULONG hi32;

        [InteropServices::FieldOffsetAttribute(8)]
        ULONG lo32;

        [InteropServices::FieldOffsetAttribute(12)]
        ULONG mid32;

        [InteropServices::FieldOffsetAttribute(8)]
        ULONGLONG lo64;
    };

    [InteropServices::StructLayoutAttribute(InteropServices::LayoutKind::Explicit)]
    public value struct CY
    {
        [InteropServices::FieldOffsetAttribute(0)]
        ULONG lo;

        [InteropServices::FieldOffsetAttribute(4)]
        LONG hi;

        [InteropServices::FieldOffsetAttribute(0)]
        LONGLONG int64;
    };

    public value struct CLIPDATA
    {
        ULONG cbSize;
        LONG ulClipFmt;
        BYTE *pClipData;
    };

    public value struct BSTRBLOB
    {
        ULONG cbSize;
        BYTE *pData;
    };

    public value struct BLOB
    {
        ULONG cbSize;
        BYTE *pBlobData;
    };

    public value struct VERSIONEDSTREAM
    {
        System::Guid guidVersion;
        System::IntPtr pStream;
    };

    public value struct SAFEARRAYBOUND
    {
        ULONG cElements;
        LONG lLbound;
    };

    public value struct SAFEARRAY
    {
        USHORT cDims;
        USHORT fFeatures;
        ULONG cbElements;
        ULONG cLocks;
        PVOID pvData;
        SAFEARRAYBOUND rgsabound;
    };

    public value struct CAC
    {
        ULONG cElems;
        CHAR *pElems;
    };

    public value struct CAUB
    {
        ULONG cElems;
        UCHAR *pElems;
    };

    public value struct CAI
    {
        ULONG cElems;
        SHORT *pElems;
    };

    public value struct CAUI
    {
        ULONG cElems;
        USHORT *pElems;
    };

    public value struct CAL
    {
        ULONG cElems;
        LONG *pElems;
    };

    public value struct CAUL
    {
        ULONG cElems;
        ULONG *pElems;
    };

    public value struct CAH
    {
        ULONG cElems;
        D2DNet::LARGE_INTEGER *pElems;
    };

    public value struct CAUH
    {
        ULONG cElems;
        D2DNet::ULARGE_INTEGER *pElems;
    };

    public value struct CAFLT
    {
        ULONG cElems;
        FLOAT *pElems;
    };

    public value struct CADBL
    {
        ULONG cElems;
        DOUBLE *pElems;
    };

    public value struct CABOOL
    {
        ULONG cElems;
        VARIANT_BOOL *pElems;
    };

    public value struct CASCODE
    {
        ULONG cElems;
        SCODE *pElems;
    };

    public value struct CACY
    {
        ULONG cElems;
        D2DNet::CY *pElems;
    };

    public value struct CADATE
    {
        ULONG cElems;
        DATE *pElems;
    };

    public value struct CAFILETIME
    {
        ULONG cElems;
        InteropServices::ComTypes::FILETIME *pElems;
    };

    public value struct CACLSID
    {
        ULONG cElems;
        System::Guid *pElems;
    };

    public value struct CACLIPDATA
    {
        ULONG cElems;
        D2DNet::CLIPDATA *pElems;
    };

    public value struct CABSTR
    {
        ULONG cElems;
        BSTR *pElems;
    };

    public value struct CABSTRBLOB
    {
        ULONG cElems;
        D2DNet::BSTRBLOB *pElems;
    };

    public value struct CALPSTR
    {
        ULONG cElems;
        LPSTR *pElems;
    };

    public value struct CALPWSTR
    {
        ULONG cElems;
        LPWSTR *pElems;
    };

    value struct PROPVARIANT;

    public value struct CAPROPVARIANT
    {
        ULONG cElems;
        D2DNet::PROPVARIANT *pElems;
    };

    [InteropServices::StructLayoutAttribute(InteropServices::LayoutKind::Explicit)]
    public value struct InnerPROPVARIANT
    {
        [InteropServices::FieldOffsetAttribute(0)]
        ::VARTYPE vt;

        [InteropServices::FieldOffsetAttribute(2)]
        PROPVAR_PAD1 reserved1;

        [InteropServices::FieldOffsetAttribute(4)]
        PROPVAR_PAD2 reserved2;

        [InteropServices::FieldOffsetAttribute(6)]
        PROPVAR_PAD3 reserved3;

        [InteropServices::FieldOffsetAttribute(8)] CHAR cVal;
        [InteropServices::FieldOffsetAttribute(8)] UCHAR bVal;
        [InteropServices::FieldOffsetAttribute(8)] SHORT iVal;
        [InteropServices::FieldOffsetAttribute(8)] USHORT uiVal;
        [InteropServices::FieldOffsetAttribute(8)] LONG lVal;
        [InteropServices::FieldOffsetAttribute(8)] ULONG ulVal;
        [InteropServices::FieldOffsetAttribute(8)] INT intVal;
        [InteropServices::FieldOffsetAttribute(8)] UINT uintVal;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::LARGE_INTEGER hVal;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::ULARGE_INTEGER uhVal;
        [InteropServices::FieldOffsetAttribute(8)] FLOAT fltVal;
        [InteropServices::FieldOffsetAttribute(8)] DOUBLE dblVal;
        [InteropServices::FieldOffsetAttribute(8)] VARIANT_BOOL boolVal;
        [InteropServices::FieldOffsetAttribute(8)] VARIANT_BOOL __OBSOLETE__VARIANT_BOOL;
        [InteropServices::FieldOffsetAttribute(8)] SCODE scode;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CY cyVal;
        [InteropServices::FieldOffsetAttribute(8)] DATE date;
        [InteropServices::FieldOffsetAttribute(8)] InteropServices::ComTypes::FILETIME filetime;
        [InteropServices::FieldOffsetAttribute(8)] System::Guid *puuid;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CLIPDATA *pclipdata;
        [InteropServices::FieldOffsetAttribute(8)] BSTR bstrVal;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::BSTRBLOB bstrblobVal;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::BLOB blob;
        [InteropServices::FieldOffsetAttribute(8)] LPSTR pszVal;
        [InteropServices::FieldOffsetAttribute(8)] LPWSTR pwszVal;
        [InteropServices::FieldOffsetAttribute(8)] System::IntPtr punkVal;
        [InteropServices::FieldOffsetAttribute(8)] System::IntPtr pdispVal;
        [InteropServices::FieldOffsetAttribute(8)] System::IntPtr pStream;
        [InteropServices::FieldOffsetAttribute(8)] System::IntPtr pStorage;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::VERSIONEDSTREAM *pVersionedStream;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::SAFEARRAY *parray;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAC cac;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAUB caub;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAI cai;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAUI caui;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAL cal;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAUL caul;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAH cah;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAUH cauh;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAFLT caflt;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CADBL cadbl;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CABOOL cabool;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CASCODE cascode;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CACY cacy;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CADATE cadate;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAFILETIME cafiletime;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CACLSID cauuid;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CACLIPDATA caclipdata;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CABSTR cabstr;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CABSTRBLOB cabstrblob;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CALPSTR calpstr;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CALPWSTR calpwstr;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CAPROPVARIANT capropvar;
        [InteropServices::FieldOffsetAttribute(8)] CHAR *pcVal;
        [InteropServices::FieldOffsetAttribute(8)] UCHAR *pbVal;
        [InteropServices::FieldOffsetAttribute(8)] SHORT *piVal;
        [InteropServices::FieldOffsetAttribute(8)] USHORT *puiVal;
        [InteropServices::FieldOffsetAttribute(8)] LONG *plVal;
        [InteropServices::FieldOffsetAttribute(8)] ULONG *pulVal;
        [InteropServices::FieldOffsetAttribute(8)] INT *pintVal;
        [InteropServices::FieldOffsetAttribute(8)] UINT *puintVal;
        [InteropServices::FieldOffsetAttribute(8)] FLOAT *pfltVal;
        [InteropServices::FieldOffsetAttribute(8)] DOUBLE *pdblVal;
        [InteropServices::FieldOffsetAttribute(8)] VARIANT_BOOL *pboolVal;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::DECIMAL *pdecVal;
        [InteropServices::FieldOffsetAttribute(8)] SCODE *pscode;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::CY *pcyVal;
        [InteropServices::FieldOffsetAttribute(8)] DATE *pdate;
        [InteropServices::FieldOffsetAttribute(8)] BSTR *pbstrVal;
        [InteropServices::FieldOffsetAttribute(8)] System::IntPtr ppunkVal;
        [InteropServices::FieldOffsetAttribute(8)] System::IntPtr ppdispVal;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::SAFEARRAY **pparray;
        [InteropServices::FieldOffsetAttribute(8)] D2DNet::PROPVARIANT *pvarVal;
    };

    [InteropServices::StructLayoutAttribute(InteropServices::LayoutKind::Explicit)]
    public value struct PROPVARIANT
    {
        [InteropServices::FieldOffsetAttribute(0)]
        D2DNet::InnerPROPVARIANT innerPROPVARIANT;

        [InteropServices::FieldOffsetAttribute(0)]
        D2DNet::DECIMAL decVal;
    };

    /// <summary>
    /// Delegate that receives the debug message string and handles it.
    /// </summary>
    public delegate void DebugMessageHandler(System::String ^);

    interface class IUnknown;

    /// <summary>
    /// Class that contains DirectX helper functions.
    /// </summary>
    public ref class DirectX abstract sealed
    {
    public:
        /// <summary>
        /// Event called when <see cref="D2DNet::DirectX::PrintDebugMessage"/> is called.
        /// </summary>
        static event DebugMessageHandler ^OnDebugMessage;

        static DirectX()
        {
            OnDebugMessage += gcnew D2DNet::DebugMessageHandler(
                System::Console::Error,
                &System::IO::TextWriter::WriteLine
            );
        }

        /// <summary>
        /// Converts the native guid to managed guid.
        /// </summary>
        static System::Guid ToManagedGUID(const _GUID &guid);

        /// <summary>
        /// Converts the managed guid to native guid.
        /// </summary>
        static _GUID ToNativeGUID(System::Guid %guid);

        /// <summary>
        /// Throws <see cref="Direct2DNet::Exception::DxException"/> if hr smaller than 0(failed).
        /// </summary>
        /// <exception cref="Direct2DNet::Exception::DxException">
        /// Thrown when hr is smaller than 0.
        /// </exception>
        static void ThrowIfFailed(HRESULT hr);

        /// <summary>
        /// Gets error message from the HRESULT code.
        /// </summary>
        static System::String ^GetErrorMessage(HRESULT hr);

        /// <summary>
        /// Gets the debug message and handles it by calling <see cref="D2DNet::DirectX::OnDebugMessage"/>
        /// event. The default action is to print the message on stderr.
        /// </summary>
        static void PrintDebugMessage(System::String ^message);
    };
}

#ifndef NULL
#define NULL 0
#endif