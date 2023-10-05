/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "color.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Color3::Color3()
        : r {0.0}, g {0.0}, b {0.0}
    {
    }

    Color3::Color3(const double R, const double G, const double B)
        : r {R}, g {G}, b {B}
    {
    }

    Color3::Color3(const Color3& Other)
        : r {Other.r}, g {Other.g}, b {Other.b}
    {
    }

    /*** Friend ***/
    Color3 operator*(const double Scalar, const Color3& Color)
    {
        return Color3(Scalar * Color.r, Scalar * Color.g, Scalar * Color.b);
    }

    std::ostream& operator<<(std::ostream& os, const Color3& Color)
    {
        return os << std::format("Color3({}, {}, {})", Color.r, Color.g, Color.b);
    }

    /*** Operator ***/
    Color3 Color3::operator*(const Color3& Other) const
    {
        return Color3(r * Other.r, g * Other.g, b * Other.b);
    }

    Color3& Color3::operator*=(const Color3& Other)
    {
        r *= Other.r;
        g *= Other.g;
        b *= Other.b;
        return *this;
    }

    Color3 Color3::operator*(const double Scalar) const
    {
        return Color3(r * Scalar, g * Scalar, b * Scalar);
    }

    Color3& Color3::operator*=(const double Scalar)
    {
        r *= Scalar;
        g *= Scalar;
        b *= Scalar;
        return *this;
    }

    Color3 Color3::operator+(const Color3& Other) const
    {
        return Color3(r + Other.r, g + Other.g, b + Other.b);
    }

    Color3& Color3::operator+=(const Color3& Other)
    {
        r += Other.r;
        g += Other.g;
        b += Other.b;
        return *this;
    }

    Color3 Color3::operator-(const Color3& Other) const
    {
        return Color3(r - Other.r, g - Other.g, b - Other.b);
    }

    Color3& Color3::operator-=(const Color3& Other)
    {
        r -= Other.r;
        g -= Other.g;
        b -= Other.b;
        return *this;
    }

    bool Color3::operator==(const Color3& Other) const
    {
        const double MaximumDelta{0.000001};
        return (std::abs(r - Other.r) <= MaximumDelta) &&
               (std::abs(g - Other.g) <= MaximumDelta) &&
               (std::abs(b - Other.b) <= MaximumDelta);
    }

    Color3& Color3::operator=(const Color3& Other)
    {
        r = Other.r;
        g = Other.g;
        b = Other.b;
        return *this;
    }
}
