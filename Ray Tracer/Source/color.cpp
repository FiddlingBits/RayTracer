/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "color.h"
#include <string>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Color::Color()
        : r {0.0}, g {0.0}, b {0.0}
    {
    }

    Color::Color(const double R, const double G, const double B)
        : r {R}, g {G}, b {B}
    {
    }

    Color::Color(const Color& Other)
        : r {Other.r}, g {Other.g}, b {Other.b}
    {
    }

    /*** Friend ***/
    Color operator*(const double Scalar, const Color& C)
    {
        return Color(Scalar * C.r, Scalar * C.g, Scalar * C.b);
    }

    std::ostream& operator<<(std::ostream& os, const Color& C)
    {
        return os << C.toString();
    }

    /*** Method ***/
    std::string Color::toString() const
    {
        return std::format("Color({}, {}, {})", r, g, b);
    }

    /*** Operator ***/
    Color Color::operator*(const Color& Other) const
    {
        return Color(r * Other.r, g * Other.g, b * Other.b);
    }

    Color& Color::operator*=(const Color& Other)
    {
        *this = *this * Other;
        return *this;
    }

    Color Color::operator*(const double Scalar) const
    {
        return Color(r * Scalar, g * Scalar, b * Scalar);
    }

    Color& Color::operator*=(const double Scalar)
    {
        *this = *this * Scalar;
        return *this;
    }

    Color Color::operator+(const Color& Other) const
    {
        return Color(r + Other.r, g + Other.g, b + Other.b);
    }

    Color& Color::operator+=(const Color& Other)
    {
        *this = *this + Other;
        return *this;
    }

    Color Color::operator-(const Color& Other) const
    {
        return Color(r - Other.r, g - Other.g, b - Other.b);
    }

    Color& Color::operator-=(const Color& Other)
    {
        *this = *this - Other;
        return *this;
    }

    bool Color::operator==(const Color& Other) const
    {
        const double MaximumDelta {0.000001};
        return (std::abs(r - Other.r) <= MaximumDelta) &&
               (std::abs(g - Other.g) <= MaximumDelta) &&
               (std::abs(b - Other.b) <= MaximumDelta);
    }

    Color& Color::operator=(const Color& Other)
    {
        r = Other.r;
        g = Other.g;
        b = Other.b;
        return *this;
    }
}
