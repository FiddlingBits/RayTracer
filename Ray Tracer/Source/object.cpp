/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "object.h"

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
        : color {}
    {
    }

    Object::Object(const Color& C)
        : color {C}
    {
    }

    /*** Friend ***/

    /*** Method ***/
    Color Object::getColor() const
    {
        return color;
    }

    void Object::setColor(const Color& C)
    {
        color = C;
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Object& O)
    {
        std::stringstream ss;
        ss << "Object(" << O.color << ")";
        return os << ss.str();
    }

    /*** Operator ***/
    bool Object::operator==(const Object& Other) const
    {
        return (color == Other.color);
    }
}
