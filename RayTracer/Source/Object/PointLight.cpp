/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "PointLight.h"

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
        : color {}, position {}
    {
    }

    PointLight::PointLight(const Color3& Color, const Point3& Position)
        : color {Color}, position {Position}
    {
    }

    PointLight::PointLight(const PointLight& Other)
        : color {Other.color}, position {Other.position}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const PointLight& PL)
    {
        return os << "PointLight(" << PL.color << ", " << PL.position << ")";
    }

    /*** Method ***/
    Color3 PointLight::getLighting(const Material& M, const Point3& MaterialPoint, const Vector3& EyeVector, const Vector3& MaterialNormal)
    {
        /*** Get Lighting ***/
        /* Set Up */
        Vector3 lightVector = (position - MaterialPoint).normalize();
        double lightDotNormal = lightVector.dot(MaterialNormal);
        Color3 effectiveColor = M.intensity * color;
        Color3 diffuse(0.0, 0.0, 0.0); // Black
        Color3 specular(0.0, 0.0, 0.0);

        /* Calculate Diffuse And Specular */
        if(lightDotNormal >= 0.0)
        {
            diffuse = effectiveColor * M.diffuse * lightDotNormal;
            Vector3 reflectVector = -lightVector.reflect(MaterialNormal);
            double reflectDotEye = reflectVector.dot(EyeVector);
            if(reflectDotEye <= 0.0)
                specular = Color3(0.0, 0.0, 0.0); // Black
            else
                specular = color * M.specular * std::pow(reflectDotEye, M.shininess);
        }

        return (effectiveColor * M.ambient) + diffuse + specular;
    }

    /*** Operator ***/
    bool PointLight::operator==(const PointLight& Other) const
    {
        return (color == Other.color) && (position == Other.position);
    }

    PointLight& PointLight::operator=(const PointLight& Other)
    {
        color = Other.color;
        position = Other.position;
        return *this;
    }
}
