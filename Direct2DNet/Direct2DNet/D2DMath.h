#pragma once

#include "D2DNetHeaders.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace Direct2DNet
    {


        /// <summary>
        /// Represents an x-coordinate and y-coordinate pair in two-dimensional space.
        /// </summary>
        public value struct D2D1_POINT_2U
        {
            unsigned int x;
            unsigned int y;

            D2D1_POINT_2U(unsigned int x, unsigned int y) : x(x), y(y) {}

            static operator ::D2D1_POINT_2U(Direct2DNet::D2D1_POINT_2U %rhs)
            {
                ::D2D1_POINT_2U value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }

            static operator Direct2DNet::D2D1_POINT_2U(::D2D1_POINT_2U %rhs)
            {
                Direct2DNet::D2D1_POINT_2U value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }
        };

        /// <summary>
        /// Represents an x-coordinate and y-coordinate pair in two-dimensional space.
        /// </summary>
        public value struct D2D1_POINT_2F
        {
            float x;
            float y;

            D2D1_POINT_2F(float x, float y) : x(x), y(y) {}

            static operator ::D2D1_POINT_2F(Direct2DNet::D2D1_POINT_2F %rhs)
            {
                ::D2D1_POINT_2F value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }

            static operator Direct2DNet::D2D1_POINT_2F(::D2D1_POINT_2F %rhs)
            {
                Direct2DNet::D2D1_POINT_2F value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }

            virtual System::String ^ToString() override
            {
                return "(" + x + ", " + y + ")";
            }
        };

        /// <summary>
        /// Represents the x- and y- coordinates of a point.
        /// </summary>
        public value struct D2D1_POINT_2L
        {
            LONG x;
            LONG y;

            D2D1_POINT_2L(LONG x, LONG y) : x(x), y(y) {}

            static operator ::D2D1_POINT_2L(Direct2DNet::D2D1_POINT_2L %rhs)
            {
                ::D2D1_POINT_2L value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }

            static operator Direct2DNet::D2D1_POINT_2L(::D2D1_POINT_2L %rhs)
            {
                Direct2DNet::D2D1_POINT_2L value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }
        };

        /// <summary>
        /// Contains the center point, x-radius, and y-radius of an ellipse.
        /// </summary>
        public value struct D2D1_ELLIPSE
        {
            Direct2DNet::D2D1_POINT_2F point;
            float radiusX;
            float radiusY;

            D2D1_ELLIPSE(Direct2DNet::D2D1_POINT_2F point, float radiusX, float radiusY)
                : point(point), radiusX(radiusX), radiusY(radiusY) {}

            static operator ::D2D1_ELLIPSE(Direct2DNet::D2D1_ELLIPSE %rhs)
            {
                ::D2D1_ELLIPSE value;
                value.point = static_cast<::D2D1_POINT_2F>(rhs.point);
                value.radiusX = rhs.radiusX;
                value.radiusY = rhs.radiusY;

                return value;
            }

            static operator Direct2DNet::D2D1_ELLIPSE(::D2D1_ELLIPSE %rhs)
            {
                Direct2DNet::D2D1_ELLIPSE value;
                value.point = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point);
                value.radiusX = rhs.radiusX;
                value.radiusY = rhs.radiusY;

                return value;
            }
        };

        /// <summary>
        /// Describes a cubic bezier in a path.
        /// </summary>
        public value struct D2D1_BEZIER_SEGMENT
        {
            Direct2DNet::D2D1_POINT_2F point1;
            Direct2DNet::D2D1_POINT_2F point2;
            Direct2DNet::D2D1_POINT_2F point3;

            D2D1_BEZIER_SEGMENT(
                Direct2DNet::D2D1_POINT_2F point1,
                Direct2DNet::D2D1_POINT_2F point2,
                Direct2DNet::D2D1_POINT_2F point3
            ) : point1(point1), point2(point2), point3(point3) {}

            static operator ::D2D1_BEZIER_SEGMENT(Direct2DNet::D2D1_BEZIER_SEGMENT %rhs)
            {
                ::D2D1_BEZIER_SEGMENT value;
                value.point1 = static_cast<::D2D1_POINT_2F>(rhs.point1);
                value.point2 = static_cast<::D2D1_POINT_2F>(rhs.point2);
                value.point3 = static_cast<::D2D1_POINT_2F>(rhs.point3);

                return value;
            }

            static operator Direct2DNet::D2D1_BEZIER_SEGMENT(::D2D1_BEZIER_SEGMENT %rhs)
            {
                Direct2DNet::D2D1_BEZIER_SEGMENT value;
                value.point1 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point1);
                value.point2 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point2);
                value.point3 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point3);

                return value;
            }
        };

        /// <summary>
        /// Contains the control point and end point for a quadratic Bezier segment.
        /// </summary>
        public value struct D2D1_QUADRATIC_BEZIER_SEGMENT
        {
            Direct2DNet::D2D1_POINT_2F point1;
            Direct2DNet::D2D1_POINT_2F point2;

            D2D1_QUADRATIC_BEZIER_SEGMENT(
                Direct2DNet::D2D1_POINT_2F point1,
                Direct2DNet::D2D1_POINT_2F point2
            ) : point1(point1), point2(point2) {}

            static operator ::D2D1_QUADRATIC_BEZIER_SEGMENT(Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT %rhs)
            {
                ::D2D1_QUADRATIC_BEZIER_SEGMENT value;
                value.point1 = static_cast<::D2D1_POINT_2F>(rhs.point1);
                value.point2 = static_cast<::D2D1_POINT_2F>(rhs.point2);

                return value;
            }

            static operator Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT(::D2D1_QUADRATIC_BEZIER_SEGMENT %rhs)
            {
                Direct2DNet::D2D1_QUADRATIC_BEZIER_SEGMENT value;
                value.point1 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point1);
                value.point2 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point2);

                return value;
            }
        };

        /// <summary>
        /// Represents a rectangle defined by the float-type coordinates of the upper-left corner
        /// (left, top) and the coordinates of the lower-right corner (right, bottom).
        /// </summary>
        public value struct D2D1_RECT_F
        {
            float left;
            float top;
            float right;
            float bottom;

            D2D1_RECT_F(float left, float top, float right, float bottom) : left(left), top(top), right(right), bottom(bottom) {}

            static operator ::D2D1_RECT_F(Direct2DNet::D2D1_RECT_F %rhs)
            {
                ::D2D1_RECT_F value;
                value.left = rhs.left;
                value.top = rhs.top;
                value.right = rhs.right;
                value.bottom = rhs.bottom;

                return value;
            }

            static operator Direct2DNet::D2D1_RECT_F(::D2D1_RECT_F %rhs)
            {
                Direct2DNet::D2D1_RECT_F value;
                value.left = rhs.left;
                value.top = rhs.top;
                value.right = rhs.right;
                value.bottom = rhs.bottom;

                return value;
            }

            static property Direct2DNet::D2D1_RECT_F InfiniteRect
            {
                static Direct2DNet::D2D1_RECT_F get()
                {
                    return Direct2DNet::D2D1_RECT_F(
                        -D2D1::FloatMax(), -D2D1::FloatMax(), D2D1::FloatMax(), D2D1::FloatMax()
                    );
                }
            }
        };

        /// <summary>
        /// Contains the dimensions and corner radii of a rounded rectangle.
        /// </summary>
        public value struct D2D1_ROUNDED_RECT
        {
            /// <summary>
            /// The coordinates of the rectangle.
            /// </summary>
            Direct2DNet::D2D1_RECT_F rect;

            /// <summary>
            /// The x-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.
            /// </summary>
            float radiusX;

            /// <summary>
            /// The y-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.
            /// </summary>
            float radiusY;

            D2D1_ROUNDED_RECT(Direct2DNet::D2D1_RECT_F rect, float radiusX, float radiusY)
                : rect(rect), radiusX(radiusX), radiusY(radiusY) {}

            static operator ::D2D1_ROUNDED_RECT(Direct2DNet::D2D1_ROUNDED_RECT %rhs)
            {
                ::D2D1_ROUNDED_RECT value;
                value.rect = static_cast<::D2D1_RECT_F>(rhs.rect);
                value.radiusX = rhs.radiusX;
                value.radiusY = rhs.radiusY;

                return value;
            }

            static operator Direct2DNet::D2D1_ROUNDED_RECT(::D2D1_ROUNDED_RECT %rhs)
            {
                Direct2DNet::D2D1_ROUNDED_RECT value;
                value.rect = static_cast<Direct2DNet::D2D1_RECT_F>(rhs.rect);
                value.radiusX = rhs.radiusX;
                value.radiusY = rhs.radiusY;

                return value;
            }
        };

        /// <summary>
        /// Represents a rectangle defined by the UInt32-type coordinates of the upper-left corner
        /// (left, top) and the coordinates of the lower-right corner (right, bottom).
        /// </summary>
        public value struct D2D1_RECT_U
        {
            unsigned int left;
            unsigned int top;
            unsigned int right;
            unsigned int bottom;

            D2D1_RECT_U(unsigned int left, unsigned int top, unsigned int right, unsigned int bottom) : left(left), top(top), right(right), bottom(bottom) {}

            static operator ::D2D1_RECT_U(Direct2DNet::D2D1_RECT_U %rhs)
            {
                ::D2D1_RECT_U value;
                value.left = rhs.left;
                value.top = rhs.top;
                value.right = rhs.right;
                value.bottom = rhs.bottom;

                return value;
            }

            static operator Direct2DNet::D2D1_RECT_U(::D2D1_RECT_U %rhs)
            {
                Direct2DNet::D2D1_RECT_U value;
                value.left = rhs.left;
                value.top = rhs.top;
                value.right = rhs.right;
                value.bottom = rhs.bottom;

                return value;
            }

            static bool operator==(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_U %lhs,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_RECT_U %rhs)
            {
                return (lhs.left == rhs.left) && (lhs.top == rhs.top) &&
                    (lhs.right == rhs.right) && (lhs.bottom == rhs.bottom);
            }

            static property Direct2DNet::D2D1_RECT_U InfiniteRectU
            {
                static Direct2DNet::D2D1_RECT_U get()
                {
                    return static_cast<Direct2DNet::D2D1_RECT_U>(D2D1::InfiniteRectU());
                }
            }
        };

        /// <summary>
        /// Represents a rectangle defined by the int-type coordinates of the upper-left corner
        /// (left, top) and the coordinates of the lower-right corner (right, bottom).
        /// </summary>
        public value struct D2D1_RECT_L
        {
            LONG left;
            LONG top;
            LONG right;
            LONG bottom;

            D2D1_RECT_L(LONG left, LONG top, LONG right, LONG bottom) : left(left), top(top), right(right), bottom(bottom) {}

            static operator ::D2D1_RECT_L(Direct2DNet::D2D1_RECT_L %rhs)
            {
                ::D2D1_RECT_L value;
                value.left = rhs.left;
                value.top = rhs.top;
                value.right = rhs.right;
                value.bottom = rhs.bottom;

                return value;
            }

            static operator Direct2DNet::D2D1_RECT_L(::D2D1_RECT_L %rhs)
            {
                Direct2DNet::D2D1_RECT_L value;
                value.left = rhs.left;
                value.top = rhs.top;
                value.right = rhs.right;
                value.bottom = rhs.bottom;

                return value;
            }
        };

        /// <summary>
        /// Describes a triangle.
        /// </summary>
        public value struct D2D1_TRIANGLE
        {
            Direct2DNet::D2D1_POINT_2F point1;
            Direct2DNet::D2D1_POINT_2F point2;
            Direct2DNet::D2D1_POINT_2F point3;

            D2D1_TRIANGLE(
                Direct2DNet::D2D1_POINT_2F point1,
                Direct2DNet::D2D1_POINT_2F point2,
                Direct2DNet::D2D1_POINT_2F point3
            ) : point1(point1), point2(point2), point3(point3) {}

            D2D1_TRIANGLE(float x1, float y1, float x2, float y2, float x3, float y3)
                : point1(x1, y1), point2(x2, y2), point3(x3, y3) {}

            static operator ::D2D1_TRIANGLE(Direct2DNet::D2D1_TRIANGLE %rhs)
            {
                ::D2D1_TRIANGLE value;
                value.point1 = static_cast<::D2D1_POINT_2F>(rhs.point1);
                value.point2 = static_cast<::D2D1_POINT_2F>(rhs.point2);
                value.point3 = static_cast<::D2D1_POINT_2F>(rhs.point3);

                return value;
            }

            static operator Direct2DNet::D2D1_TRIANGLE(::D2D1_TRIANGLE %rhs)
            {
                Direct2DNet::D2D1_TRIANGLE value;
                value.point1 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point1);
                value.point2 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point2);
                value.point3 = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point3);

                return value;
            }
        };

        /// <summary>
        /// Stores an ordered pair of floats, typically the width and height of a rectangle.
        /// </summary>
        public value struct D2D1_SIZE_F
        {
            float width;
            float height;

            D2D1_SIZE_F(float width, float height) : width(width), height(height) {}

            static operator ::D2D1_SIZE_F(Direct2DNet::D2D1_SIZE_F %rhs)
            {
                ::D2D1_SIZE_F value;
                value.width = rhs.width;
                value.height = rhs.height;

                return value;
            }

            static operator Direct2DNet::D2D1_SIZE_F(::D2D1_SIZE_F %rhs)
            {
                Direct2DNet::D2D1_SIZE_F value;
                value.width = rhs.width;
                value.height = rhs.height;

                return value;
            }
        };

        /// <summary>
        /// Defines the direction that an elliptical arc is drawn.
        /// </summary>
        public enum class D2D1_SWEEP_DIRECTION
        {
            COUNTER_CLOCKWISE = 0,
            CLOCKWISE = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
        FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Differentiates which of the two possible arcs could match the given arc
        /// parameters.
        /// </summary>
        public enum class D2D1_ARC_SIZE
        {
            /// <summary>
            /// An arc's sweep should be 180 degrees or less.
            /// </summary>
            SMALL = 0,

            /// <summary>
            /// An arc's sweep should be 180 degrees or greater.
            /// </summary>
            LARGE = 1,

            [System::ObsoleteAttribute("Do not use this value.", true)]
        FORCE_DWORD = 0xffffffff
        };

        /// <summary>
        /// Describes an arc that is defined as part of a path.
        /// </summary>
        public value struct D2D1_ARC_SEGMENT
        {
            Direct2DNet::D2D1_POINT_2F point;

            /// <summary>
            /// The x-radius and y-radius of the arc.
            /// </summary>
            Direct2DNet::D2D1_SIZE_F size;

            /// <summary>
            /// A value that specifies how many degrees in the clockwise direction the ellipse is rotated
            /// relative to the current coordinate system.
            /// </summary>
            float rotationAngle;

            Direct2DNet::D2D1_SWEEP_DIRECTION sweepDirection;
            Direct2DNet::D2D1_ARC_SIZE arcSize;

            D2D1_ARC_SEGMENT(
                Direct2DNet::D2D1_POINT_2F point,
                Direct2DNet::D2D1_SIZE_F size,
                float rotationAngle,
                Direct2DNet::D2D1_SWEEP_DIRECTION sweepDirection,
                Direct2DNet::D2D1_ARC_SIZE arcSize
            ) : point(point), size(size), rotationAngle(rotationAngle), sweepDirection(sweepDirection), arcSize(arcSize) {}

            static operator ::D2D1_ARC_SEGMENT(Direct2DNet::D2D1_ARC_SEGMENT %rhs)
            {
                ::D2D1_ARC_SEGMENT value;
                value.point = static_cast<::D2D1_POINT_2F>(rhs.point);
                value.size = static_cast<::D2D1_SIZE_F>(rhs.size);
                value.rotationAngle = rhs.rotationAngle;
                value.sweepDirection = (::D2D1_SWEEP_DIRECTION)((int)rhs.sweepDirection);
                value.arcSize = (::D2D1_ARC_SIZE)((int)rhs.arcSize);

                return value;
            }

            static operator Direct2DNet::D2D1_ARC_SEGMENT(::D2D1_ARC_SEGMENT %rhs)
            {
                Direct2DNet::D2D1_ARC_SEGMENT value;
                value.point = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point);
                value.size = static_cast<Direct2DNet::D2D1_SIZE_F>(rhs.size);
                value.rotationAngle = rhs.rotationAngle;
                value.sweepDirection = (Direct2DNet::D2D1_SWEEP_DIRECTION)((int)rhs.sweepDirection);
                value.arcSize = (Direct2DNet::D2D1_ARC_SIZE)((int)rhs.arcSize);

                return value;
            }
        };

        /// <summary>
        /// Stores an ordered pair of integers, typically the width and height of a
        /// rectangle.
        /// </summary>
        public value struct D2D1_SIZE_U
        {
            unsigned int width;
            unsigned int height;

            D2D1_SIZE_U(unsigned int width, unsigned int height) : width(width), height(height) {}

            static bool operator==(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_U %lhs,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_U %rhs)
            {
                return (lhs.width == rhs.width) && (lhs.height == rhs.height);
            }

            static operator ::D2D1_SIZE_U(Direct2DNet::D2D1_SIZE_U %rhs)
            {
                ::D2D1_SIZE_U value;
                value.width = rhs.width;
                value.height = rhs.height;

                return value;
            }

            static operator Direct2DNet::D2D1_SIZE_U(::D2D1_SIZE_U %rhs)
            {
                Direct2DNet::D2D1_SIZE_U value;
                value.width = rhs.width;
                value.height = rhs.height;

                return value;
            }
        };

        /// <summary>
        /// Stores an ordered pair of floats, typically rgba of the color.
        /// </summary>
        public value struct D2D1_COLOR_F
        {
            float r;
            float g;
            float b;
            float a;

            D2D1_COLOR_F(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

            /// <summary>
            /// List of pre-defined colors, with rgb values assigned to each elements.
            /// </summary>
            enum class Color
            {
                AliceBlue = 0xF0F8FF,
                AntiqueWhite = 0xFAEBD7,
                Aqua = 0x00FFFF,
                Aquamarine = 0x7FFFD4,
                Azure = 0xF0FFFF,
                Beige = 0xF5F5DC,
                Bisque = 0xFFE4C4,
                Black = 0x000000,
                BlanchedAlmond = 0xFFEBCD,
                Blue = 0x0000FF,
                BlueViolet = 0x8A2BE2,
                Brown = 0xA52A2A,
                BurlyWood = 0xDEB887,
                CadetBlue = 0x5F9EA0,
                Chartreuse = 0x7FFF00,
                Chocolate = 0xD2691E,
                Coral = 0xFF7F50,
                CornflowerBlue = 0x6495ED,
                Cornsilk = 0xFFF8DC,
                Crimson = 0xDC143C,
                Cyan = 0x00FFFF,
                DarkBlue = 0x00008B,
                DarkCyan = 0x008B8B,
                DarkGoldenrod = 0xB8860B,
                DarkGray = 0xA9A9A9,
                DarkGreen = 0x006400,
                DarkKhaki = 0xBDB76B,
                DarkMagenta = 0x8B008B,
                DarkOliveGreen = 0x556B2F,
                DarkOrange = 0xFF8C00,
                DarkOrchid = 0x9932CC,
                DarkRed = 0x8B0000,
                DarkSalmon = 0xE9967A,
                DarkSeaGreen = 0x8FBC8F,
                DarkSlateBlue = 0x483D8B,
                DarkSlateGray = 0x2F4F4F,
                DarkTurquoise = 0x00CED1,
                DarkViolet = 0x9400D3,
                DeepPink = 0xFF1493,
                DeepSkyBlue = 0x00BFFF,
                DimGray = 0x696969,
                DodgerBlue = 0x1E90FF,
                Firebrick = 0xB22222,
                FloralWhite = 0xFFFAF0,
                ForestGreen = 0x228B22,
                Fuchsia = 0xFF00FF,
                Gainsboro = 0xDCDCDC,
                GhostWhite = 0xF8F8FF,
                Gold = 0xFFD700,
                Goldenrod = 0xDAA520,
                Gray = 0x808080,
                Green = 0x008000,
                GreenYellow = 0xADFF2F,
                Honeydew = 0xF0FFF0,
                HotPink = 0xFF69B4,
                IndianRed = 0xCD5C5C,
                Indigo = 0x4B0082,
                Ivory = 0xFFFFF0,
                Khaki = 0xF0E68C,
                Lavender = 0xE6E6FA,
                LavenderBlush = 0xFFF0F5,
                LawnGreen = 0x7CFC00,
                LemonChiffon = 0xFFFACD,
                LightBlue = 0xADD8E6,
                LightCoral = 0xF08080,
                LightCyan = 0xE0FFFF,
                LightGoldenrodYellow = 0xFAFAD2,
                LightGreen = 0x90EE90,
                LightGray = 0xD3D3D3,
                LightPink = 0xFFB6C1,
                LightSalmon = 0xFFA07A,
                LightSeaGreen = 0x20B2AA,
                LightSkyBlue = 0x87CEFA,
                LightSlateGray = 0x778899,
                LightSteelBlue = 0xB0C4DE,
                LightYellow = 0xFFFFE0,
                Lime = 0x00FF00,
                LimeGreen = 0x32CD32,
                Linen = 0xFAF0E6,
                Magenta = 0xFF00FF,
                Maroon = 0x800000,
                MediumAquamarine = 0x66CDAA,
                MediumBlue = 0x0000CD,
                MediumOrchid = 0xBA55D3,
                MediumPurple = 0x9370DB,
                MediumSeaGreen = 0x3CB371,
                MediumSlateBlue = 0x7B68EE,
                MediumSpringGreen = 0x00FA9A,
                MediumTurquoise = 0x48D1CC,
                MediumVioletRed = 0xC71585,
                MidnightBlue = 0x191970,
                MintCream = 0xF5FFFA,
                MistyRose = 0xFFE4E1,
                Moccasin = 0xFFE4B5,
                NavajoWhite = 0xFFDEAD,
                Navy = 0x000080,
                OldLace = 0xFDF5E6,
                Olive = 0x808000,
                OliveDrab = 0x6B8E23,
                Orange = 0xFFA500,
                OrangeRed = 0xFF4500,
                Orchid = 0xDA70D6,
                PaleGoldenrod = 0xEEE8AA,
                PaleGreen = 0x98FB98,
                PaleTurquoise = 0xAFEEEE,
                PaleVioletRed = 0xDB7093,
                PapayaWhip = 0xFFEFD5,
                PeachPuff = 0xFFDAB9,
                Peru = 0xCD853F,
                Pink = 0xFFC0CB,
                Plum = 0xDDA0DD,
                PowderBlue = 0xB0E0E6,
                Purple = 0x800080,
                Red = 0xFF0000,
                RosyBrown = 0xBC8F8F,
                RoyalBlue = 0x4169E1,
                SaddleBrown = 0x8B4513,
                Salmon = 0xFA8072,
                SandyBrown = 0xF4A460,
                SeaGreen = 0x2E8B57,
                SeaShell = 0xFFF5EE,
                Sienna = 0xA0522D,
                Silver = 0xC0C0C0,
                SkyBlue = 0x87CEEB,
                SlateBlue = 0x6A5ACD,
                SlateGray = 0x708090,
                Snow = 0xFFFAFA,
                SpringGreen = 0x00FF7F,
                SteelBlue = 0x4682B4,
                Tan = 0xD2B48C,
                Teal = 0x008080,
                Thistle = 0xD8BFD8,
                Tomato = 0xFF6347,
                Turquoise = 0x40E0D0,
                Violet = 0xEE82EE,
                Wheat = 0xF5DEB3,
                White = 0xFFFFFF,
                WhiteSmoke = 0xF5F5F5,
                Yellow = 0xFFFF00,
                YellowGreen = 0x9ACD32,
            };

            /// <summary>
            /// Sets the rgb value to the pre-defined color, and sets alpha value.
            /// </summary>
            D2D1_COLOR_F(Direct2DNet::D2D1_COLOR_F::Color knownColor, float alpha)
            {
                Init(static_cast<unsigned int>(knownColor), alpha);
            }

            /// <summary>
            /// Sets the rgb value to <paramref name="colorHex"/>, and sets alpha value.
            /// </summary>
            /// <param name="colorHex">An RGB value in hex code(i.e. 0xFFBB51).</param>
            D2D1_COLOR_F(unsigned int colorHex, float alpha)
            {
                Init(colorHex, alpha);
            }

        private:

            literal unsigned int sc_redShift = 16;
            literal unsigned int sc_greenShift = 8;
            literal unsigned int sc_blueShift = 0;

            literal unsigned int sc_redMask = 0xff << sc_redShift;
            literal unsigned int sc_greenMask = 0xff << sc_greenShift;
            literal unsigned int sc_blueMask = 0xff << sc_blueShift;

            void Init(unsigned int rgb, float alpha)
            {
                r = static_cast<float>((rgb & sc_redMask) >> sc_redShift) / 255.f;
                g = static_cast<float>((rgb & sc_greenMask) >> sc_greenShift) / 255.f;
                b = static_cast<float>((rgb & sc_blueMask) >> sc_blueShift) / 255.f;
                a = alpha;
            }

        public:
            static operator ::D2D1_COLOR_F(Direct2DNet::D2D1_COLOR_F %rhs)
            {
                ::D2D1_COLOR_F value;
                value.r = rhs.r;
                value.g = rhs.g;
                value.b = rhs.b;
                value.a = rhs.a;

                return value;
            }

            static operator Direct2DNet::D2D1_COLOR_F(::D2D1_COLOR_F %rhs)
            {
                Direct2DNet::D2D1_COLOR_F value;
                value.r = rhs.r;
                value.g = rhs.g;
                value.b = rhs.b;
                value.a = rhs.a;

                return value;
            }
        };

        /// <summary>
        /// A vector of 2 float values (x, y).
        /// </summary>
        public value struct D2D1_VECTOR_2F
        {
            float x;
            float y;

            D2D1_VECTOR_2F(float x, float y) : x(x), y(y) {}

            property float Length
            {
                float get()
                {
                    return sqrtf((x * x) + (y * y));
                }
            }

            property float SqrLength
            {
                float get()
                {
                    return (x * x) + (y * y);
                }
            }

            static operator ::D2D1_VECTOR_2F(Direct2DNet::D2D1_VECTOR_2F %rhs)
            {
                ::D2D1_VECTOR_2F value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }

            static operator Direct2DNet::D2D1_VECTOR_2F(::D2D1_VECTOR_2F %rhs)
            {
                Direct2DNet::D2D1_VECTOR_2F value;
                value.x = rhs.x;
                value.y = rhs.y;

                return value;
            }
        };

        /// <summary>
        /// A vector of 3 float values (x, y, z).
        /// </summary>
        public value struct D2D1_VECTOR_3F
        {
            float x;
            float y;
            float z;

            D2D1_VECTOR_3F(float x, float y, float z) : x(x), y(y), z(z) {}

            property float Length
            {
                float get()
                {
                    return sqrtf((x * x) + (y * y) + (z * z));
                }
            }

            property float SqrLength
            {
                float get()
                {
                    return (x * x) + (y * y) + (z * z);
                }
            }

            static operator ::D2D1_VECTOR_3F(Direct2DNet::D2D1_VECTOR_3F %rhs)
            {
                ::D2D1_VECTOR_3F value;
                value.x = rhs.x;
                value.y = rhs.y;
                value.z = rhs.z;

                return value;
            }

            static operator Direct2DNet::D2D1_VECTOR_3F(::D2D1_VECTOR_3F %rhs)
            {
                Direct2DNet::D2D1_VECTOR_3F value;
                value.x = rhs.x;
                value.y = rhs.y;
                value.z = rhs.z;

                return value;
            }
        };

        /// <summary>
        /// A vector of 4 float values (x, y, z, w).
        /// </summary>
        public value struct D2D1_VECTOR_4F
        {
            float x;
            float y;
            float z;
            float w;

            D2D1_VECTOR_4F(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

            property float Length
            {
                float get()
                {
                    return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
                }
            }

            property float SqrLength
            {
                float get()
                {
                    return (x * x) + (y * y) + (z * z) + (w * w);
                }
            }

            static operator ::D2D1_VECTOR_4F(Direct2DNet::D2D1_VECTOR_4F %rhs)
            {
                ::D2D1_VECTOR_4F value;
                value.x = rhs.x;
                value.y = rhs.y;
                value.z = rhs.z;
                value.w = rhs.w;

                return value;
            }

            static operator Direct2DNet::D2D1_VECTOR_4F(::D2D1_VECTOR_4F %rhs)
            {
                Direct2DNet::D2D1_VECTOR_4F value;
                value.x = rhs.x;
                value.y = rhs.y;
                value.z = rhs.z;
                value.w = rhs.w;

                return value;
            }
        };

        /// <summary>
        /// Represents a 3-by-2 matrix.
        /// </summary>
        [StructLayoutAttribute(LayoutKind::Explicit)]
        public value struct D2D1_MATRIX_3X2_F
        {
            [FieldOffsetAttribute(0)] float _11;
            [FieldOffsetAttribute(4)] float _12;
            [FieldOffsetAttribute(8)] float _21;
            [FieldOffsetAttribute(12)] float _22;
            [FieldOffsetAttribute(16)] float _31;
            [FieldOffsetAttribute(20)] float _32;

            /// <summary>
            /// Horizontal scaling / cosine of rotation
            /// </summary>
            [FieldOffsetAttribute(0)] float m11;

            /// <summary>
            /// Vertical shear / sine of rotation
            /// </summary>
            [FieldOffsetAttribute(4)] float m12;

            /// <summary>
            /// Horizontal shear / negative sine of rotation
            /// </summary>
            [FieldOffsetAttribute(8)] float m21;

            /// <summary>
            /// Vertical scaling / cosine of rotation
            /// </summary>
            [FieldOffsetAttribute(12)] float m22;

            /// <summary>
            /// Horizontal shift (always orthogonal regardless of rotation)
            /// </summary>
            [FieldOffsetAttribute(16)] float dx;

            /// <summary>
            /// Vertical shift (always orthogonal regardless of rotation)
            /// </summary>
            [FieldOffsetAttribute(20)] float dy;

            D2D1_MATRIX_3X2_F(float _11, float _12, float _21, float _22, float _31, float _32) : _11(_11), _12(_12), _21(_21), _22(_22), _31(_31), _32(_32) {}

            /// <summary>
            /// Gets the identity matrix.
            /// </summary>
            static property Direct2DNet::D2D1_MATRIX_3X2_F Identity
            {
                static Direct2DNet::D2D1_MATRIX_3X2_F get()
                {
                    return Direct2DNet::D2D1_MATRIX_3X2_F(
                        1.0f, 0.0f,
                        0.0f, 1.0f,
                        0.0f, 0.0f
                    );
                }
            }

            /// <summary>
            /// Gets the translation matrix.
            /// </summary>
            /// <param name="trans"><see cref="Direct2DNet::D2D1_SIZE_F::width"/> is a translation in x axis.
            /// <see cref="Direct2DNet::D2D1_SIZE_F::height"/> is a translation in y axis.</param>
            static Direct2DNet::D2D1_MATRIX_3X2_F Translation(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_F %trans)
            {
                Direct2DNet::D2D1_MATRIX_3X2_F translation;

                translation._11 = 1.0; translation._12 = 0.0;
                translation._21 = 0.0; translation._22 = 1.0;
                translation._31 = trans.width; translation._32 = trans.height;

                return translation;
            }

            /// <summary>
            /// Gets the translation matrix.
            /// </summary>
            /// <param name="transX">Translation in x axis.</param>
            /// <param name="transY">Translation in y axis.</param>
            static Direct2DNet::D2D1_MATRIX_3X2_F Translation(float transX, float transY)
            {
                Direct2DNet::D2D1_MATRIX_3X2_F translation;

                translation._11 = 1.0; translation._12 = 0.0;
                translation._21 = 0.0; translation._22 = 1.0;
                translation._31 = transX; translation._32 = transY;

                return translation;
            }

            /// <summary>
            /// Gets the scale matrix.
            /// </summary>
            /// <param name="scaleFactor"><see cref="Direct2DNet::D2D1_SIZE_F::width"/> is a scale factor in x axis.
            /// <see cref="Direct2DNet::D2D1_SIZE_F::height"/> is a scale factor in y axis.</param>
            /// <param name="center">The point about which the scale is performed.</param>
            static Direct2DNet::D2D1_MATRIX_3X2_F Scale(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_SIZE_F %scaleFactor,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %center)
            {
                Direct2DNet::D2D1_MATRIX_3X2_F scale;

                scale._11 = scaleFactor.width; scale._12 = 0.0;
                scale._21 = 0.0; scale._22 = scaleFactor.height;
                scale._31 = center.x - scaleFactor.width * center.x;
                scale._32 = center.y - scaleFactor.height * center.y;

                return scale;
            }

            /// <summary>
            /// Gets the scale matrix.
            /// </summary>
            /// <param name="scaleX">scale factor in x axis.</param>
            /// <param name="scaleY">scale factor in Y axis.</param>
            /// <param name="center">The point about which the scale is performed.</param>
            static Direct2DNet::D2D1_MATRIX_3X2_F Scale(float scaleX, float scaleY,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %center)
            {
                Direct2DNet::D2D1_MATRIX_3X2_F scale;

                scale._11 = scaleX; scale._12 = 0.0;
                scale._21 = 0.0; scale._22 = scaleY;
                scale._31 = center.x - scaleX * center.x;
                scale._32 = center.y - scaleY * center.y;

                return scale;
            }

            /// <summary>
            /// Gets the rotation matrix.
            /// </summary>
            /// <param name="angle">Rotation angle in degrees.</param>
            /// <param name="center">The point about which the rotation is performed.</param>
            static Direct2DNet::D2D1_MATRIX_3X2_F Rotation(float angle,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %center)
            {
                return static_cast<Direct2DNet::D2D1_MATRIX_3X2_F>(
                    D2D1::Matrix3x2F::Rotation(angle, static_cast<::D2D1_POINT_2F>(center)));
            }

            /// <summary>
            /// Gets the skew matrix.
            /// </summary>
            /// <param name="angleX">Skew angle in x axis. It is measured in degrees
            /// counterclockwise from y axis.</param>
            /// <param name="scaleY">Skew angle in y axis. It is measured in degrees
            /// clockwise from x axis.</param>
            /// <param name="center">The point about which the skew is performed.</param>
            static Direct2DNet::D2D1_MATRIX_3X2_F Skew(float angleX, float angleY,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %center)
            {
                return static_cast<Direct2DNet::D2D1_MATRIX_3X2_F>(
                    D2D1::Matrix3x2F::Skew(angleX, angleY, static_cast<::D2D1_POINT_2F>(center)));
            }

            /// <summary>
            /// Gets the determinant of the matrix.
            /// </summary>
            property float Determinant
            {
                float get()
                {
                    return (_11 * _22) - (_12 * _21);
                }
            }

            /// <summary>
            /// Gets whether the matrix is invertible.
            /// </summary>
            property bool Invertible
            {
                bool get()
                {
                    return this->Determinant != 0;
                }
            }

            /// <summary>
            /// Inverts the matrix if it is possible.
            /// </summary>
            /// <returns>
            /// True if the matrix was inverted, false if it was not inverted.
            /// </returns>
            bool Invert()
            {
                ::D2D1_MATRIX_3X2_F temp = D2D1::Matrix3x2F(_11, _12, _21, _22, _31, _32);

                pin_ptr<::D2D1_MATRIX_3X2_F> pTemp = &temp;
                bool result = !!::D2D1InvertMatrix((::D2D1_MATRIX_3X2_F *)pTemp);
                pTemp = nullptr;

                if(result)
                {
                    this->_11 = temp._11;
                    this->_12 = temp._12;
                    this->_21 = temp._21;
                    this->_22 = temp._22;
                    this->_31 = temp._31;
                    this->_32 = temp._32;
                }

                return result;
            }

            /// <summary>
            /// Gets whether the matrix is the identity matrix.
            /// </summary>
            property bool IsIdentity
            {
                bool get()
                {
                    return     _11 == 1.f && _12 == 0.f
                        && _21 == 0.f && _22 == 1.f
                        && _31 == 0.f && _32 == 0.f;
                }
            }

            /// <summary>
            /// Multiplies two matrix and stores the value in this matrix.
            /// </summary>
            void SetProduct(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %a,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %b)
            {
                _11 = a._11 * b._11 + a._12 * b._21;
                _12 = a._11 * b._12 + a._12 * b._22;
                _21 = a._21 * b._11 + a._22 * b._21;
                _22 = a._21 * b._12 + a._22 * b._22;
                _31 = a._31 * b._11 + a._32 * b._21 + b._31;
                _32 = a._31 * b._12 + a._32 * b._22 + b._32;
            }

            static Direct2DNet::D2D1_MATRIX_3X2_F operator*(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %lhs,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %rhs)
            {
                Direct2DNet::D2D1_MATRIX_3X2_F result;
                result.SetProduct(lhs, rhs);

                return result;
            }

            /// <summary>
            /// Uses this matrix to transform the specified point and returns the result.
            /// </summary>
            Direct2DNet::D2D1_POINT_2F TransformPoint(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %point)
            {
                return Direct2DNet::D2D1_POINT_2F(
                    point.x * _11 + point.y * _21 + _31,
                    point.x * _12 + point.y * _22 + _32
                );
            }

            static Direct2DNet::D2D1_POINT_2F operator*(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_POINT_2F %lhs,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_3X2_F %rhs)
            {
                return rhs.TransformPoint(lhs);
            }

            static operator ::D2D1_MATRIX_3X2_F(Direct2DNet::D2D1_MATRIX_3X2_F %rhs)
            {
                ::D2D1_MATRIX_3X2_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._31 = rhs._31;
                value._32 = rhs._32;

                return value;
            }

            static operator Direct2DNet::D2D1_MATRIX_3X2_F(::D2D1_MATRIX_3X2_F %rhs)
            {
                Direct2DNet::D2D1_MATRIX_3X2_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._31 = rhs._31;
                value._32 = rhs._32;

                return value;
            }
        };

        /// <summary>
        /// Represents a 4-by-3 matrix.
        /// </summary>
        public value struct D2D1_MATRIX_4X3_F
        {
            float _11, _12, _13;
            float _21, _22, _23;
            float _31, _32, _33;
            float _41, _42, _43;

            D2D1_MATRIX_4X3_F(
                float m11, float m12, float m13,
                float m21, float m22, float m23,
                float m31, float m32, float m33,
                float m41, float m42, float m43
            ) : _11(m11), _12(m12), _13(m13), _21(m21), _22(m22), _23(m23),
                _31(m31), _32(m32), _33(m33), _41(m41), _42(m42), _43(m43) {}

            static property Direct2DNet::D2D1_MATRIX_4X3_F Identity
            {
                static Direct2DNet::D2D1_MATRIX_4X3_F get()
                {
                    return Direct2DNet::D2D1_MATRIX_4X3_F(
                        1, 0, 0,
                        0, 1, 0,
                        0, 0, 1,
                        0, 0, 0
                    );
                }
            }

            static operator ::D2D1_MATRIX_4X3_F(Direct2DNet::D2D1_MATRIX_4X3_F %rhs)
            {
                ::D2D1_MATRIX_4X3_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._13 = rhs._13;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._23 = rhs._23;
                value._31 = rhs._31;
                value._32 = rhs._32;
                value._33 = rhs._33;
                value._41 = rhs._41;
                value._42 = rhs._42;
                value._43 = rhs._43;

                return value;
            }

            static operator Direct2DNet::D2D1_MATRIX_4X3_F(::D2D1_MATRIX_4X3_F %rhs)
            {
                Direct2DNet::D2D1_MATRIX_4X3_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._13 = rhs._13;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._23 = rhs._23;
                value._31 = rhs._31;
                value._32 = rhs._32;
                value._33 = rhs._33;
                value._41 = rhs._41;
                value._42 = rhs._42;
                value._43 = rhs._43;

                return value;
            }
        };

        /// <summary>
        /// Represents a 4-by-4 matrix.
        /// </summary>
        public value struct D2D1_MATRIX_4X4_F
        {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;

            D2D1_MATRIX_4X4_F(
                float m11, float m12, float m13, float m14,
                float m21, float m22, float m23, float m24,
                float m31, float m32, float m33, float m34,
                float m41, float m42, float m43, float m44
            ) : _11(m11), _12(m12), _13(m13), _14(m14), _21(m21), _22(m22), _23(m23), _24(m24),
                _31(m31), _32(m32), _33(m33), _34(m34), _41(m41), _42(m42), _43(m43), _44(m44) {}

            static property Direct2DNet::D2D1_MATRIX_4X4_F Identity
            {
                static Direct2DNet::D2D1_MATRIX_4X4_F get()
                {
                    return Direct2DNet::D2D1_MATRIX_4X4_F(
                        1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, 1, 0,
                        0, 0, 0, 1
                    );
                }
            }

            static bool operator==(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %lhs,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %rhs)
            {
                return lhs._11 == rhs._11 && lhs._12 == rhs._12 && lhs._13 == rhs._13 && lhs._14 == rhs._14 &&
                    lhs._21 == rhs._21 && lhs._22 == rhs._22 && lhs._23 == rhs._23 && lhs._24 == rhs._24 &&
                    lhs._31 == rhs._31 && lhs._32 == rhs._32 && lhs._33 == rhs._33 && lhs._34 == rhs._34 &&
                    lhs._41 == rhs._41 && lhs._42 == rhs._42 && lhs._43 == rhs._43 && lhs._44 == rhs._44;
            }

            static bool operator!=(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %lhs,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %rhs)
            {
                return !(lhs == rhs);
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F Translation(float x, float y, float z)
            {
                Direct2DNet::D2D1_MATRIX_4X4_F translation;

                translation._11 = 1.0; translation._12 = 0.0; translation._13 = 0.0; translation._14 = 0.0;
                translation._21 = 0.0; translation._22 = 1.0; translation._23 = 0.0; translation._24 = 0.0;
                translation._31 = 0.0; translation._32 = 0.0; translation._33 = 1.0; translation._34 = 0.0;
                translation._41 = x;   translation._42 = y;   translation._43 = z;   translation._44 = 1.0;

                return translation;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F Scale(float x, float y, float z)
            {
                Direct2DNet::D2D1_MATRIX_4X4_F scale;

                scale._11 = x;   scale._12 = 0.0; scale._13 = 0.0; scale._14 = 0.0;
                scale._21 = 0.0; scale._22 = y;   scale._23 = 0.0; scale._24 = 0.0;
                scale._31 = 0.0; scale._32 = 0.0; scale._33 = z;   scale._34 = 0.0;
                scale._41 = 0.0; scale._42 = 0.0; scale._43 = 0.0; scale._44 = 1.0;

                return scale;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F RotationX(float degreeX)
            {
                float angleInRadian = degreeX * (3.141592654f / 180.0f);

                float sinAngle = 0.0;
                float cosAngle = 0.0;
                ::D2D1SinCos(angleInRadian, &sinAngle, &cosAngle);

                Direct2DNet::D2D1_MATRIX_4X4_F rotationX(
                    1, 0, 0, 0,
                    0, cosAngle, sinAngle, 0,
                    0, -sinAngle, cosAngle, 0,
                    0, 0, 0, 1
                );

                return rotationX;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F RotationY(float degreeY)
            {
                float angleInRadian = degreeY * (3.141592654f / 180.0f);

                float sinAngle = 0.0;
                float cosAngle = 0.0;
                ::D2D1SinCos(angleInRadian, &sinAngle, &cosAngle);

                Direct2DNet::D2D1_MATRIX_4X4_F rotationY(
                    cosAngle, 0, -sinAngle, 0,
                    0, 1, 0, 0,
                    sinAngle, 0, cosAngle, 0,
                    0, 0, 0, 1
                );

                return rotationY;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F RotationZ(float degreeZ)
            {
                float angleInRadian = degreeZ * (3.141592654f / 180.0f);

                float sinAngle = 0.0;
                float cosAngle = 0.0;
                ::D2D1SinCos(angleInRadian, &sinAngle, &cosAngle);

                Direct2DNet::D2D1_MATRIX_4X4_F rotationZ(
                    cosAngle, sinAngle, 0, 0,
                    -sinAngle, cosAngle, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1
                );

                return rotationZ;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F RotationArbitraryAxis(float x, float y, float z, float degree)
            {
                float magnitude = ::D2D1Vec3Length(x, y, z);
                x /= magnitude;
                y /= magnitude;
                z /= magnitude;

                float angleInRadian = degree * (3.141592654f / 180.0f);

                float sinAngle = 0.0;
                float cosAngle = 0.0;
                ::D2D1SinCos(angleInRadian, &sinAngle, &cosAngle);

                float oneMinusCosAngle = 1 - cosAngle;

                Direct2DNet::D2D1_MATRIX_4X4_F rotationArb(
                    1 + oneMinusCosAngle * (x * x - 1),
                    z * sinAngle + oneMinusCosAngle * x * y,
                    -y * sinAngle + oneMinusCosAngle * x * z,
                    0,

                    -z * sinAngle + oneMinusCosAngle * y * x,
                    1 + oneMinusCosAngle * (y * y - 1),
                    x * sinAngle + oneMinusCosAngle * y * z,
                    0,

                    y * sinAngle + oneMinusCosAngle * z * x,
                    -x * sinAngle + oneMinusCosAngle * z * y,
                    1 + oneMinusCosAngle * (z * z - 1),
                    0,

                    0, 0, 0, 1
                );

                return rotationArb;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F SkewX(float degreeX)
            {
                float angleInRadian = degreeX * (3.141592654f / 180.0f);

                float tanAngle = D2D1Tan(angleInRadian);

                Direct2DNet::D2D1_MATRIX_4X4_F skewX(
                    1, 0, 0, 0,
                    tanAngle, 1, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1
                );

                return skewX;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F SkewY(float degreeY)
            {
                float angleInRadian = degreeY * (3.141592654f / 180.0f);

                float tanAngle = D2D1Tan(angleInRadian);

                Direct2DNet::D2D1_MATRIX_4X4_F skewY(
                    1, tanAngle, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1
                );

                return skewY;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F PerspectiveProjection(float depth)
            {
                float proj = 0;

                if(depth > 0)
                {
                    proj = -1 / depth;
                }

                Direct2DNet::D2D1_MATRIX_4X4_F projection(
                    1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, proj,
                    0, 0, 0, 1
                );

                return projection;
            }

            property float Determinant
            {
                float get()
                {
                    float minor1 = _41 * (_12 * (_23 * _34 - _33 * _24) - _13 * (_22 * _34 - _24 * _32) + _14 * (_22 * _33 - _23 * _32));
                    float minor2 = _42 * (_11 * (_21 * _34 - _31 * _24) - _13 * (_21 * _34 - _24 * _31) + _14 * (_21 * _33 - _23 * _31));
                    float minor3 = _43 * (_11 * (_22 * _34 - _32 * _24) - _12 * (_21 * _34 - _24 * _31) + _14 * (_21 * _32 - _22 * _31));
                    float minor4 = _44 * (_11 * (_22 * _33 - _32 * _23) - _12 * (_21 * _33 - _23 * _31) + _13 * (_21 * _32 - _22 * _31));

                    return minor1 - minor2 + minor3 - minor4;
                }
            }

            property bool IsIdentity
            {
                bool get()
                {
                    return _11 == 1.f && _12 == 0.f && _13 == 0.f && _14 == 0.f
                        && _21 == 0.f && _22 == 1.f && _23 == 0.f && _24 == 0.f
                        && _31 == 0.f && _32 == 0.f && _33 == 1.f && _34 == 0.f
                        && _41 == 0.f && _42 == 0.f && _43 == 0.f && _44 == 1.f;
                }
            }

            void SetProduct(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %a,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %b
            )
            {
                _11 = a._11 * b._11 + a._12 * b._21 + a._13 * b._31 + a._14 * b._41;
                _12 = a._11 * b._12 + a._12 * b._22 + a._13 * b._32 + a._14 * b._42;
                _13 = a._11 * b._13 + a._12 * b._23 + a._13 * b._33 + a._14 * b._43;
                _14 = a._11 * b._14 + a._12 * b._24 + a._13 * b._34 + a._14 * b._44;

                _21 = a._21 * b._11 + a._22 * b._21 + a._23 * b._31 + a._24 * b._41;
                _22 = a._21 * b._12 + a._22 * b._22 + a._23 * b._32 + a._24 * b._42;
                _23 = a._21 * b._13 + a._22 * b._23 + a._23 * b._33 + a._24 * b._43;
                _24 = a._21 * b._14 + a._22 * b._24 + a._23 * b._34 + a._24 * b._44;

                _31 = a._31 * b._11 + a._32 * b._21 + a._33 * b._31 + a._34 * b._41;
                _32 = a._31 * b._12 + a._32 * b._22 + a._33 * b._32 + a._34 * b._42;
                _33 = a._31 * b._13 + a._32 * b._23 + a._33 * b._33 + a._34 * b._43;
                _34 = a._31 * b._14 + a._32 * b._24 + a._33 * b._34 + a._34 * b._44;

                _41 = a._41 * b._11 + a._42 * b._21 + a._43 * b._31 + a._44 * b._41;
                _42 = a._41 * b._12 + a._42 * b._22 + a._43 * b._32 + a._44 * b._42;
                _43 = a._41 * b._13 + a._42 * b._23 + a._43 * b._33 + a._44 * b._43;
                _44 = a._41 * b._14 + a._42 * b._24 + a._43 * b._34 + a._44 * b._44;
            }

            static Direct2DNet::D2D1_MATRIX_4X4_F operator*(
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %lhs,
                [InAttribute][IsReadOnlyAttribute] Direct2DNet::D2D1_MATRIX_4X4_F %rhs)
            {
                Direct2DNet::D2D1_MATRIX_4X4_F result;

                result.SetProduct(lhs, rhs);

                return result;
            }

            static operator ::D2D1_MATRIX_4X4_F(Direct2DNet::D2D1_MATRIX_4X4_F %rhs)
            {
                ::D2D1_MATRIX_4X4_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._13 = rhs._13;
                value._14 = rhs._14;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._23 = rhs._23;
                value._24 = rhs._24;
                value._31 = rhs._31;
                value._32 = rhs._32;
                value._33 = rhs._33;
                value._34 = rhs._34;
                value._41 = rhs._41;
                value._42 = rhs._42;
                value._43 = rhs._43;
                value._44 = rhs._44;

                return value;
            }

            static operator Direct2DNet::D2D1_MATRIX_4X4_F(::D2D1_MATRIX_4X4_F %rhs)
            {
                Direct2DNet::D2D1_MATRIX_4X4_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._13 = rhs._13;
                value._14 = rhs._14;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._23 = rhs._23;
                value._24 = rhs._24;
                value._31 = rhs._31;
                value._32 = rhs._32;
                value._33 = rhs._33;
                value._34 = rhs._34;
                value._41 = rhs._41;
                value._42 = rhs._42;
                value._43 = rhs._43;
                value._44 = rhs._44;

                return value;
            }
        };

        /// <summary>
        /// Represents a 5-by-4 matrix.
        /// </summary>
        public value struct D2D1_MATRIX_5X4_F
        {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
            float _51, _52, _53, _54;

            D2D1_MATRIX_5X4_F(
                float m11, float m12, float m13, float m14,
                float m21, float m22, float m23, float m24,
                float m31, float m32, float m33, float m34,
                float m41, float m42, float m43, float m44,
                float m51, float m52, float m53, float m54
            ) : _11(m11), _12(m12), _13(m13), _14(m14), _21(m21), _22(m22), _23(m23), _24(m24),
                _31(m31), _32(m32), _33(m33), _34(m34), _41(m41), _42(m42), _43(m43), _44(m44),
                _51(m51), _52(m52), _53(m53), _54(m54) {}

            static property Direct2DNet::D2D1_MATRIX_5X4_F Identity
            {
                static Direct2DNet::D2D1_MATRIX_5X4_F get()
                {
                    return Direct2DNet::D2D1_MATRIX_5X4_F(
                        1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, 1, 0,
                        0, 0, 0, 1,
                        0, 0, 0, 0
                    );
                }
            }

            static operator ::D2D1_MATRIX_5X4_F(Direct2DNet::D2D1_MATRIX_5X4_F %rhs)
            {
                ::D2D1_MATRIX_5X4_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._13 = rhs._13;
                value._14 = rhs._14;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._23 = rhs._23;
                value._24 = rhs._24;
                value._31 = rhs._31;
                value._32 = rhs._32;
                value._33 = rhs._33;
                value._34 = rhs._34;
                value._41 = rhs._41;
                value._42 = rhs._42;
                value._43 = rhs._43;
                value._44 = rhs._44;
                value._51 = rhs._51;
                value._52 = rhs._52;
                value._53 = rhs._53;
                value._54 = rhs._54;

                return value;
            }

            static operator Direct2DNet::D2D1_MATRIX_5X4_F(::D2D1_MATRIX_5X4_F %rhs)
            {
                Direct2DNet::D2D1_MATRIX_5X4_F value;
                value._11 = rhs._11;
                value._12 = rhs._12;
                value._13 = rhs._13;
                value._14 = rhs._14;
                value._21 = rhs._21;
                value._22 = rhs._22;
                value._23 = rhs._23;
                value._24 = rhs._24;
                value._31 = rhs._31;
                value._32 = rhs._32;
                value._33 = rhs._33;
                value._34 = rhs._34;
                value._41 = rhs._41;
                value._42 = rhs._42;
                value._43 = rhs._43;
                value._44 = rhs._44;
                value._51 = rhs._51;
                value._52 = rhs._52;
                value._53 = rhs._53;
                value._54 = rhs._54;

                return value;
            }
        };

        /// <summary>
        /// Describes a point along a path.
        /// </summary>
        public value struct D2D1_POINT_DESCRIPTION
        {
            /// <summary>
            /// The end point after walking the path.
            /// </summary>
            Direct2DNet::D2D1_POINT_2F point;

            /// <summary>
            /// A unit vector indicating the tangent point.
            /// </summary>
            Direct2DNet::D2D1_POINT_2F unitTangentVector;

            /// <summary>
            /// The index of the segment on which point resides.
            /// This index is global to the entire path, not just to a particular figure.
            /// </summary>
            unsigned int endSegment;

            /// <summary>
            /// The index of the figure on which point resides.
            /// </summary>
            unsigned int endFigure;

            /// <summary>
            /// The length of the section of the path stretching from the start of the path
            /// to the start of endSegment.
            /// </summary>
            float lengthToEndSegment;

            static operator Direct2DNet::D2D1_POINT_DESCRIPTION(::D2D1_POINT_DESCRIPTION %rhs)
            {
                Direct2DNet::D2D1_POINT_DESCRIPTION value;
                value.point = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.point);
                value.unitTangentVector = static_cast<Direct2DNet::D2D1_POINT_2F>(rhs.unitTangentVector);
                value.endSegment = rhs.endSegment;
                value.endFigure = rhs.endFigure;
                value.lengthToEndSegment = rhs.lengthToEndSegment;

                return value;
            }
        };

    }
}