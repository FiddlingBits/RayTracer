/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Color3.h"

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
        : r {}, g {}, b {}
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
        return os << Color.toString();
    }

    /*** Method ***/
    std::string Color3::toString() const
    {
        return std::format("Color3({}, {}, {})", r, g, b);
    }

    /*** Operator ***/
    Color3 Color3::operator*(const Color3& Other) const
    {
        return Color3(r * Other.r, g * Other.g, b * Other.b);
    }

    Color3& Color3::operator*=(const Color3& Other)
    {
        *this = *this * Other;
        return *this;
    }

    Color3 Color3::operator*(const double Scalar) const
    {
        return Color3(r * Scalar, g * Scalar, b * Scalar);
    }

    Color3& Color3::operator*=(const double Scalar)
    {
        *this = *this * Scalar;
        return *this;
    }

    Color3 Color3::operator+(const Color3& Other) const
    {
        return Color3(r + Other.r, g + Other.g, b + Other.b);
    }

    Color3& Color3::operator+=(const Color3& Other)
    {
        *this = *this + Other;
        return *this;
    }

    Color3 Color3::operator-(const Color3& Other) const
    {
        return Color3(r - Other.r, g - Other.g, b - Other.b);
    }

    Color3& Color3::operator-=(const Color3& Other)
    {
        *this = *this - Other;
        return *this;
    }

    bool Color3::operator==(const Color3& Other) const
    {
        const double Delta {0.000001};
        return (std::abs(r - Other.r) <= Delta) &&
               (std::abs(g - Other.g) <= Delta) &&
               (std::abs(b - Other.b) <= Delta);
    }

    Color3& Color3::operator=(const Color3& Other)
    {
        r = Other.r;
        g = Other.g;
        b = Other.b;
        return *this;
    }
}
