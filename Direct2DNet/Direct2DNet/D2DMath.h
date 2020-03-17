#pragma once

#include "D2DNetHeaders.h"

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

    internal:
        static operator ::D2D1_POINT_2U (Direct2DNet::D2D1_POINT_2U %rhs)
        {
            ::D2D1_POINT_2U value;
            value.x = rhs.x;
            value.y = rhs.y;

            return value;
        }

        static operator Direct2DNet::D2D1_POINT_2U (::D2D1_POINT_2U %rhs)
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

    internal:
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
    };

    /// <summary>
    /// Represents a rectangle defined by the coordinates of the upper-left corner
    /// (left, top) and the coordinates of the lower-right corner (right, bottom).
    /// </summary>
    public value struct D2D1_RECT_F
    {
        float left;
        float top;
        float right;
        float bottom;

        D2D1_RECT_F(float left, float top, float right, float bottom) : left(left), top(top), right(right), bottom(bottom) {}

    internal:
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
    };

    /// <summary>
    /// Represents a rectangle defined by the coordinates of the upper-left corner
    /// (left, top) and the coordinates of the lower-right corner (right, bottom).
    /// </summary>
    public value struct D2D1_RECT_U
    {
        unsigned int left;
        unsigned int top;
        unsigned int right;
        unsigned int bottom;

        D2D1_RECT_U(unsigned int left, unsigned int top, unsigned int right, unsigned int bottom) : left(left), top(top), right(right), bottom(bottom) {}

    internal:
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
    };

    /// <summary>
    /// Stores an ordered pair of floats, typically the width and height of a rectangle.
    /// </summary>
    public value struct D2D1_SIZE_F
    {
        float width;
        float height;

        D2D1_SIZE_F(float width, float height) : width(width), height(height) {}

    internal:
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
    /// Stores an ordered pair of integers, typically the width and height of a
    /// rectangle.
    /// </summary>
    public value struct D2D1_SIZE_U
    {
        unsigned int width;
        unsigned int height;

        D2D1_SIZE_U(unsigned int width, unsigned int height) : width(width), height(height) {}

    internal:
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

    internal:
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
    /// Represents a 3-by-2 matrix.
    /// </summary>
    public value struct D2D1_MATRIX_3X2_F
    {
        float _11, _12;
        float _21, _22;
        float _31, _32;

        D2D1_MATRIX_3X2_F(float _11, float _12, float _21, float _22, float _31, float _32) : _11(_11), _12(_12), _21(_21), _22(_22), _31(_31), _32(_32) {}

    internal:
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
}
