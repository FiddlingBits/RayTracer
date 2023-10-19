/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Vector3.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Vector3::Vector3()
        : x {}, y {}, z {}
    {
    }

    Vector3::Vector3(const double X, const double Y, const double Z)
        : x {X}, y {Y}, z {Z}
    {
    }

    Vector3::Vector3(const Vector3& Other)
        : x {Other.x}, y {Other.y}, z {Other.z}
    {
    }

    /*** Friend ***/
    Vector3 operator*(const double Scalar, const Vector3& Vector)
    {
        return Vector3(Scalar * Vector.x, Scalar * Vector.y, Scalar * Vector.z);
    }

    std::ostream& operator<<(std::ostream& os, const Vector3& Vector)
    {
        return os << std::format("Vector3({}, {}, {})", Vector.x, Vector.y, Vector.z);
    }

    /*** Method ***/
    Vector3 Vector3::cross(const Vector3& Other) const
    {
        return Vector3(((y * Other.z) - (z * Other.y)), ((z * Other.x) - (x * Other.z)), ((x * Other.y) - (y * Other.x)));
    }

    double Vector3::dot(const Vector3& Other) const
    {
        return ((x * Other.x) + (y * Other.y) + (z * Other.z));
    }

    double Vector3::magnitude() const
    {
        return std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0));
    }

    Vector3 Vector3::normalize() const
    {
        return *this / magnitude();
    }

    Vector3 Vector3::reflect(const Vector3& Other) const
    {
        return *this - (Other * 2.0 * dot(Other));
    }

    /*** Operator ***/
    Vector3 Vector3::operator-() const
    {
        return Vector3(-x, -y, -z);
    }

    Vector3 Vector3::operator*(const double Scalar) const
    {
        return Vector3(x * Scalar, y * Scalar, z * Scalar);
    }

    Vector3& Vector3::operator*=(const double Scalar)
    {
        *this = *this * Scalar;
        return *this;
    }

    Vector3 Vector3::operator/(const double Scalar) const
    {
        return Vector3(x / Scalar, y / Scalar, z / Scalar);
    }

    Vector3& Vector3::operator/=(const double Scalar)
    {
        *this = *this / Scalar;
        return *this;
    }

    Vector3 Vector3::operator+(const Vector3& Other) const
    {
        return Vector3(x + Other.x, y + Other.y, z + Other.z);
    }

    Vector3& Vector3::operator+=(const Vector3& Other)
    {
        *this = *this + Other;
        return *this;
    }

    Vector3 Vector3::operator-(const Vector3& Other) const
    {
        return Vector3(x - Other.x, y - Other.y, z - Other.z);
    }

    Vector3& Vector3::operator-=(const Vector3& Other)
    {
        *this = *this - Other;
        return *this;
    }

    bool Vector3::operator==(const Vector3& Other) const
    {
        const double Delta {0.000001};
        return (std::abs(x - Other.x) <= Delta) &&
               (std::abs(y - Other.y) <= Delta) &&
               (std::abs(z - Other.z) <= Delta);
    }

    Vector3& Vector3::operator=(const Vector3& Other)
    {
        x = Other.x;
        y = Other.y;
        z = Other.z;
        return *this;
    }
}