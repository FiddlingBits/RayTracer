/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Object.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Object::Object()
        : material {}
    {
    }

    Object::Object(const Material& M)
        : material {M}
    {
    }

    Object::Object(const Object& Other)
        : material {Other.material}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Object& O)
    {
        return os << "Object(" << O.material << ")";
    }

    /*** Operator ***/
    bool Object::operator==(const Object& Other) const
    {
        return (material == Other.material);
    }

    Object& Object::operator=(const Object& Other)
    {
        material = Other.material;
        return *this;
    }
}
