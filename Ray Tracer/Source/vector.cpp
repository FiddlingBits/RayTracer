/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "vector.h"

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
        : x {0.0}, y {0.0}, z {0.0}, w {0.0}
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
    Vector4 operator*(const double Scalar, const Vector4& Vector)
    {
        return Vector4(Scalar * Vector.x, Scalar * Vector.y, Scalar * Vector.z, Scalar * Vector.w);
    }

    std::ostream& operator<<(std::ostream& os, const Vector4& Vector)
    {
        return os << std::format("Vector4({}, {}, {}, {})", Vector.x, Vector.y, Vector.z, Vector.w);
    }

    /*** Method ***/
    Vector4 Vector4::crossProduct(const Vector4& Other) const
    {
        if(isVector3() && Other.isVector3()) // Cross Product Used Only On Vectors
            return Vector4(((y * Other.z) - (z * Other.y)), ((z * Other.x) - (x * Other.z)), ((x * Other.y) - (y * Other.x)), Other.w); // 4D Cross Product Not Used (And Significantly More Complicated To Calculate)
        else
            return Vector4();
    }

    double Vector4::dotProduct(const Vector4& Other) const
    {
        return ((x * Other.x) + (y * Other.y) + (z * Other.z) + (w * Other.w));
    }

    bool Vector4::isPoint3() const
    {
        return (w == 1.0);
    }

    bool Vector4::isVector3() const
    {
        return (w == 0.0);
    }

    double Vector4::magnitude() const
    {
        return std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0) + pow(w, 2.0));
    }

    Vector4 Vector4::normalize() const
    {
        return *this / magnitude();
    }

    /*** Operator ***/
    Vector4 Vector4::operator-() const
    {
        return Vector4(-x, -y, -z, -w);
    }

    Vector4 Vector4::operator*(const double Scalar) const
    {
        return Vector4(x * Scalar, y * Scalar, z * Scalar, w * Scalar);
    }

    Vector4& Vector4::operator*=(const double Scalar)
    {
        x *= Scalar;
        y *= Scalar;
        z *= Scalar;
        w *= Scalar;
        return *this;
    }

    Vector4 Vector4::operator/(const double Scalar) const
    {
        return Vector4(x / Scalar, y / Scalar, z / Scalar, w / Scalar);
    }

    Vector4& Vector4::operator/=(const double Scalar)
    {
        x /= Scalar;
        y /= Scalar;
        z /= Scalar;
        w /= Scalar;
        return *this;
    }

    Vector4 Vector4::operator+(const Vector4& Other) const
    {
        return Vector4(x + Other.x, y + Other.y, z + Other.z, w + Other.w);
    }

    Vector4& Vector4::operator+=(const Vector4& Other)
    {
        x += Other.x;
        y += Other.y;
        z += Other.z;
        w += Other.w;
        return *this;
    }

    Vector4 Vector4::operator-(const Vector4& Other) const
    {
        return Vector4(x - Other.x, y - Other.y, z - Other.z, w - Other.w);
    }

    Vector4& Vector4::operator-=(const Vector4& Other)
    {
        x -= Other.x;
        y -= Other.y;
        z -= Other.z;
        w -= Other.w;
        return *this;
    }

    bool Vector4::operator==(const Vector4& Other) const
    {
        const double MaximumDelta {0.000001};
        return (std::abs(x - Other.x) <= MaximumDelta) &&
               (std::abs(y - Other.y) <= MaximumDelta) &&
               (std::abs(z - Other.z) <= MaximumDelta) &&
               (std::abs(w - Other.w) <= MaximumDelta);
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
