/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "material.h"

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
        : color {Color(1.0, 1.0, 1.0)}, ambient {0.1}, diffuse {0.9}, specular {0.9}, shininess {200.0}
    {
    }

    Material::Material(const Color& C, const double Ambient, const double Diffuse, const double Specular, const double Shininess)
        : color {C}, ambient {Ambient}, diffuse {Diffuse}, specular {Specular}, shininess {Shininess}
    {
    }

    Material::Material(const Material& Other)
        : color {Other.color}, ambient {Other.ambient}, diffuse {Other.diffuse}, specular {Other.specular}, shininess {Other.shininess}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Material& M)
    {
        std::stringstream ss;
        ss << "Material(" << M.color << ", " << M.ambient << ", " << M.diffuse << ", " << M.specular << ", " << M.shininess << ")";
        return os << ss.str();
    }

    /*** Operator ***/
    bool Material::operator==(const Material& Other) const
    {
        const double MaximumDelta{0.000001};
        return (color == Other.color) && 
               (std::abs(ambient - Other.ambient) <= MaximumDelta) &&
               (std::abs(diffuse - Other.diffuse) <= MaximumDelta) &&
               (std::abs(specular - Other.specular) <= MaximumDelta) &&
               (std::abs(shininess - Other.shininess) <= MaximumDelta);
    }

    Material& Material::operator=(const Material& Other)
    {
        color = Other.color;
        ambient = Other.ambient;
        diffuse = Other.diffuse;
        specular = Other.specular;
        shininess = Other.shininess;
        return *this;
    }
}
