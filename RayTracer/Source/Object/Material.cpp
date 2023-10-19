/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Material.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Material::Material()
        : intensity {}, ambient {}, diffuse {}, specular {}, shininess {}
    {
    }

    Material::Material(const Color3& Intensity, const double Ambient, const double Diffuse, const double Specular, const double Shininess)
        : intensity {Intensity}, ambient {Ambient}, diffuse {Diffuse}, specular {Specular}, shininess {Shininess}
    {
    }

    Material::Material(const Material& Other)
        : intensity {Other.intensity}, ambient {Other.ambient}, diffuse {Other.diffuse}, specular {Other.specular}, shininess {Other.shininess}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Material& M)
    {
        return os << "Material(" << M.intensity << std::format(", {}, {}, {}, {})", M.ambient, M.diffuse, M.specular, M.shininess);
    }

    /*** Operator ***/
    bool Material::operator==(const Material& Other) const
    {
        const double Delta {0.000001};
        return (intensity == Other.intensity) &&
               (std::abs(ambient - Other.ambient) <= Delta) &&
               (std::abs(diffuse - Other.diffuse) <= Delta) &&
               (std::abs(specular - Other.specular) <= Delta) &&
               (std::abs(shininess - Other.shininess) <= Delta);
    }

    Material& Material::operator=(const Material& Other)
    {
        intensity = Other.intensity;
        ambient = Other.ambient;
        diffuse = Other.diffuse;
        specular = Other.specular;
        shininess = Other.shininess;
        return *this;
    }
}
