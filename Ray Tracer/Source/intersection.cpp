/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "intersection.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Intersection::Intersection()
        : object {}, ts {}
    {
    }

    Intersection::Intersection(const Object& O, const std::array<double, 2>& Ts)
        : object {O}
    {
        ts[0] = std::min(Ts[0], Ts[1]);
        ts[1] = std::max(Ts[0], Ts[1]);
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Intersection& I)
    {
        std::stringstream ss;
        ss << "Intersection(" << I.object << ", Ts(" << I.ts[0] << ", " << I.ts[1] << "))";
        return os << ss.str();
    }

    /*** Operator ***/
    bool Intersection::operator==(const Intersection& Other) const
    {
        return (object == Other.object) && (ts == Other.ts);
    }
}
