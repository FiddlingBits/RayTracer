/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Ray3.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Ray3::Ray3()
        : origin {}, direction {}
    {
    }

    Ray3::Ray3(const Point3& Origin, const Vector3& Direction)
        : origin {Origin}, direction {Direction}
    {
    }

    Ray3::Ray3(const Ray3& Other)
        : origin {Other.origin}, direction {Other.direction}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Ray3& Ray)
    {
        return os << "Ray3(" << Ray.origin << ", " << Ray.direction << ")";
    }

    /*** Method ***/
    Point3 Ray3::position(const double T) const
    {
        return origin + (direction * T);
    }

    /*** Operator ***/
    bool Ray3::operator==(const Ray3& Other) const
    {
        return (origin == Other.origin) && (direction == Other.direction);
    }

    Ray3& Ray3::operator=(const Ray3& Other)
    {
        origin = Other.origin;
        direction = Other.direction;
        return *this;
    }
}
