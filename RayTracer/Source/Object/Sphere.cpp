/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Sphere.h"

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
        : Object(), transform {}
    {
    }

    Sphere::Sphere(const Material& M)
        : Object(M), transform {}
    {
    }

    Sphere::Sphere(const Sphere& Other)
        : Object(Other.material), transform {Other.transform}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Sphere& S)
    {
        return os << "Sphere(" << S.material << ", " << S.transform << ")";
    }

    /*** Method ***/
    std::array<double, 2> Sphere::intersection(const Ray3& Ray) const
    {
        Ray3 ray = Ray * transform.inverse(); // Inverse Transform On Ray Results In Same Output As Transform On Unit Sphere At (0, 0, 0)
        Vector3 centerToOrigin = ray.origin - Point3(0.0, 0.0, 0.0);
        double a = ray.direction.dot(ray.direction);
        double b = 2.0 * ray.direction.dot(centerToOrigin);
        double c = centerToOrigin.dot(centerToOrigin) - 1.0; // Radius Is 1.0 (Unit Sphere); 1.0 * 1.0 = 1.0
        double discriminant = std::pow(b, 2.0) - (4.0 * a * c);
        std::array<double, 2> ts({-std::numeric_limits<double>::max(), std::numeric_limits<double>::max()});
        if(discriminant == 0.0)
        {
            ts[0] = ts[1] = - b / (2.0 * a);
        }
        else if(discriminant > 0.0)
        {
            ts[0] = (-b - std::sqrt(discriminant)) / (2.0 * a); // Smaller Value
            ts[1] = (-b + std::sqrt(discriminant)) / (2.0 * a); // Larger Value
        }
        return ts;
    }

    Vector3 Sphere::normalAt(const Point3& WorldPoint) const
    {
        Point3 objectPoint = transform.inverse() * WorldPoint;
        Vector3 objectNormal = objectPoint - Point3(0.0, 0.0, 0.0);
        Vector3 worldNormal = transform.inverse().transpose() * objectNormal;
        return worldNormal.normalize();
    }

    void Sphere::setTransform(const Transform4& Transform)
    {
        transform = Transform;
    }

    /*** Operator ***/
    bool Sphere::operator==(const Sphere& Other) const
    {
        return (material == Other.material) && (transform == Other.transform);
    }

    Sphere& Sphere::operator=(const Sphere& Other)
    {
        material = Other.material;
        transform = Other.transform;
        return *this;
    }
}
