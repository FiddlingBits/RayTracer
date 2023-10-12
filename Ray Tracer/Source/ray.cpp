/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "ray.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Ray::Ray()
        : origin {}, direction {}
    {
    }

    RayTracer::Ray::Ray(const double OX, const double OY, const double OZ, const double DX, const double DY, const double DZ)
        : origin {Vector4(OX, OY, OZ, 1.0)}, direction {Vector4(DX, DY, DZ, 0.0)} // w == 1.0 For Point3; w == 0.0 For Vector3
    {
    }

    Ray::Ray(const Vector4& Origin, const Vector4& Direction)
        : origin {Origin}, direction {Direction}
    {
    }

    Ray::Ray(const Ray& Other)
        : origin {Other.origin}, direction {Other.direction}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Ray& R)
    {
        std::stringstream ss;
        ss << "Ray(" << R.origin << ", " << R.direction << ")";
        return os << ss.str();
    }

    /*** Method ***/
    Vector4 Ray::position(const double T) const
    {
        return origin + (direction * T);
    }

    /*** Operator ***/
    bool Ray::operator==(const Ray& Other) const
    {
        return (origin == Other.origin) && (direction == Other.direction);
    }

    Ray& Ray::operator=(const Ray& Other)
    {
        origin = Other.origin;
        direction = Other.direction;
        return *this;
    }
}
