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
        : transform {}, Object(), material {}
    {
        material.specular = 1.0; // Change Default
    }

    Sphere::Sphere(const double R, const double G, const double B, const Material& M)
        : Object(Color(R, G, B)), material {M}
    {
    }

    Sphere::Sphere(const Color& C, const Material& M)
        : Object(C), material {M}
    {
    }

    Sphere::Sphere(const Sphere& Other)
        : Object(Other.getColor()), material {Other.material}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Sphere& S)
    {
        std::stringstream ss;
        ss << "Sphere(" << S.getColor() << ", " << S.material << ")";
        return os << ss.str();
    }

    /*** Method ***/
    std::array<double, 2> Sphere::intersection(const Ray& R) const
    {
        Ray ray = R * transform.inverse(); // Inverse Transform On Ray Results In Same Output As Transform On Unit Sphere At (0, 0, 0)
        Vector4 centerToOrigin = ray.origin - Vector4(0.0, 0.0, 0.0, 1.0); // w == 1.0 For Point3
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

    Vector4 Sphere::normalAt(const Vector4& WorldPoint) const
    {
        Vector4 objectPoint = transform.inverse() * WorldPoint;
        Vector4 objectNormal = objectPoint - Vector4(0.0, 0.0, 0.0, 1.0); // w == 1.0 For Point3
        Vector4 worldNormal = transform.inverse().transpose() * objectNormal;
        worldNormal.w = 0.0; // w == 0.0 For Vector3 
        return worldNormal.normalize();
    }

    void Sphere::setTransform(const Transform& T)
    {
        transform = T;
    }

    /*** Operator ***/
    bool Sphere::operator==(const Sphere& Other) const
    {
        return (getColor() == Other.getColor()) && (material == Other.material);
    }

    Sphere& Sphere::operator=(const Sphere& Other)
    {
        setColor(Other.getColor());
        material = Other.material;
        return *this;
    }
}
