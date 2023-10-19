/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Vector4.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Vector4::Vector4()
        : x {}, y {}, z {}, w {}
    {
    }

    Vector4::Vector4(const double X, const double Y, const double Z, const double W)
        : x {X}, y {Y}, z {Z}, w {W}
    {
    }

    Vector4::Vector4(const Vector4& Other)
        : x {Other.x}, y {Other.y}, z {Other.z}, w {Other.w}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Vector4& Vector)
    {
        return os << std::format("Vector4({}, {}, {}, {})", Vector.x, Vector.y, Vector.z, Vector.w);
    }

    /*** Method ***/
    double Vector4::dot(const Vector4& Other) const
    {
        return (x * Other.x) + (y * Other.y) + (z * Other.z) + (w * Other.w);
    }

    /*** Operator ***/
    double& Vector4::operator[](const int Index)
    {
        static double garbage;
        switch(Index)
        {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
            default:
                return garbage;
        }
    }

    bool Vector4::operator==(const Vector4& Other) const
    {
        const double Delta {0.000001};
        return (std::abs(x - Other.x) <= Delta) &&
               (std::abs(y - Other.y) <= Delta) &&
               (std::abs(z - Other.z) <= Delta) &&
               (std::abs(w - Other.w) <= Delta);
    }

    Vector4& Vector4::operator=(const Vector4& Other)
    {
        x = Other.x;
        y = Other.y;
        z = Other.z;
        w = Other.w;
        return *this;
    }
}
