/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "sphere.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Sphere::Sphere()
        : center {}, transform {}, Object()
    {
    }

    Sphere::Sphere(const double CX, const double CY, const double CZ, const double CR, const double CG, const double CB)
        : center {Vector4(CX, CY, CZ, 1.0)}, Object(Color(CR, CG, CB)) // w == 1.0 For Point3
    {
    }

    Sphere::Sphere(const Vector4& Center, const Color& C)
        : center {Center}, Object(C)
    {
    }

    Sphere::Sphere(const Sphere& Other)
        : center {Other.center}, Object(Other.getColor())
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Sphere& S)
    {
        std::stringstream ss;
        ss << "Sphere(" << S.center << ", " << S.getColor() << ")";
        return os << ss.str();
    }

    /*** Method ***/
    std::array<double, 2> Sphere::intersection(const Ray& R) const
    {
        Ray ray = R * transform.inverse();
        Vector4 centerToOrigin = ray.origin - center;
        double a = ray.direction.dotProduct(ray.direction);
        double b = 2.0 * ray.direction.dotProduct(centerToOrigin);
        double c = centerToOrigin.dotProduct(centerToOrigin) - 1.0; // Radius Is 1.0 (Unit Sphere); 1.0 * 1.0 = 1.0
        double discriminant = std::pow(b, 2.0) - (4.0 * a * c);
        double t1, t2;
        if(discriminant < 0.0)
        {
            t1 = -std::numeric_limits<double>::max();
            t2 = -std::numeric_limits<double>::max();
        }
        else
        {
            t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
            t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        }
        return std::array<double, 2>({t1, t2});
    }

    void Sphere::setTransform(const Transform& T)
    {
        transform = T;
    }

    /*** Operator ***/
    bool Sphere::operator==(const Sphere& Other) const
    {
        const double MaximumDelta {0.000001};
        return (center == Other.center) && (getColor() == Other.getColor());
    }

    Sphere& Sphere::operator=(const Sphere& Other)
    {
        center = Other.center;
        setColor(Other.getColor());
        return *this;
    }
}
