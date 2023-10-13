/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "point_light.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    PointLight::PointLight()
        : intensity {}, position {}
    {
    }

    PointLight::PointLight(const double IR, const double IG, const double IB, const double PX, const double PY, const double PZ)
        : intensity {Color(IR, IG, IB)}, position {Vector4(PX, PY, PZ, 1.0)} // w == 1.0 For Point3
    {
    }

    PointLight::PointLight(const Color& Intensity, const Vector4& Position)
        : intensity {Intensity}, position {Position}
    {
    }

    PointLight::PointLight(const PointLight& Other)
        : intensity {Other.intensity}, position {Other.position}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const PointLight& PL)
    {
        std::stringstream ss;
        ss << "PointLight(" << PL.intensity << ", " << PL.position << ")";
        return os << ss.str();
    }

    /*** Method ***/
    Color PointLight::getLighting(const Material& M, const Vector4& MaterialPoint, const Vector4& EyeVector, const Vector4& MaterialNormal)
    {
        Color effectiveColor = M.color * intensity;
        Vector4 lightVector = (position - MaterialPoint).normalize();
        Color ambient = effectiveColor * M.ambient;
        double lightDotNormal = lightVector.dotProduct(MaterialNormal);
        Color diffuse;
        Color specular;
        if(lightDotNormal < 0.0)
        {
            diffuse = Color(0.0, 0.0, 0.0); // Black
            specular = Color(0.0, 0.0, 0.0);
        }
        else
        {
            diffuse = effectiveColor * M.diffuse * lightDotNormal;
            Vector4 reflectVector = -lightVector.reflect(MaterialNormal);
            double reflectDotEye = reflectVector.dotProduct(EyeVector);
            if(reflectDotEye <= 0.0)
            {
                specular = Color(0.0, 0.0, 0.0);
            }
            else
            {
                double factor = std::pow(reflectDotEye, M.shininess);
                specular = intensity * M.specular * factor;
            }
        }
        return ambient + diffuse + specular;
    }

    /*** Operator ***/
    bool PointLight::operator==(const PointLight& Other) const
    {
        return (intensity == Other.intensity) && (position == Other.position);
    }

    PointLight& PointLight::operator=(const PointLight& Other)
    {
        intensity = Other.intensity;
        position = Other.position;
        return *this;
    }
}
