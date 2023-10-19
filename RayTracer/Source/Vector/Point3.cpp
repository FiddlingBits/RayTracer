/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Point3.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Point3::Point3()
        : x {}, y {}, z {}
    {
    }

    Point3::Point3(const double X, const double Y, const double Z)
        : x {X}, y {Y}, z {Z}
    {
    }

    Point3::Point3(const Point3& Other)
        : x {Other.x}, y {Other.y}, z {Other.z}
    {
    }

    /*** Friend ***/
    Point3 operator+(const Vector3& Vector, const Point3& Point)
    {
        return Point3(Point.x + Vector.x, Point.y + Vector.y, Point.z + Vector.z);
    }

    std::ostream& operator<<(std::ostream& os, const Point3& Point)
    {
        return os << std::format("Point3({}, {}, {})", Point.x, Point.y, Point.z);
    }

    /*** Operator ***/
    Point3 Point3::operator+(const Vector3& Vector) const
    {
        return Point3(x + Vector.x, y + Vector.y, z + Vector.z);
    }

    Vector3 Point3::operator-(const Point3& Other) const
    {
        return Vector3(x - Other.x, y - Other.y, z - Other.z);
    }

    bool Point3::operator==(const Point3& Other) const
    {
        const double Delta {0.000001};
        return (std::abs(x - Other.x) <= Delta) &&
               (std::abs(y - Other.y) <= Delta) &&
               (std::abs(z - Other.z) <= Delta);
    }

    Point3& Point3::operator=(const Point3& Other)
    {
        x = Other.x;
        y = Other.y;
        z = Other.z;
        return *this;
    }
}
