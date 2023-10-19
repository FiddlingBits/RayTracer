/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Intersection.h"

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
        : object {O}, ts {Ts}
    {
    }

    Intersection::Intersection(const Intersection& Other)
        : object {Other.object}, ts {Other.ts}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Intersection& I)
    {
        return os << I.toString();
    }

    /*** Method ***/
    std::string Intersection::toString() const
    {
        std::stringstream ss;
        ss << "Intersection(" << object << std::format(", Ts({}, {}))", ts[0], ts[1]);
        return ss.str();
    }

    /*** Operator ***/
    bool Intersection::operator==(const Intersection& Other) const
    {
        const double Delta {0.000001};
        return (object == Other.object) &&
               (std::abs(ts[0] - Other.ts[0]) <= Delta) &&
               (std::abs(ts[1] - Other.ts[1]) <= Delta);
    }

    Intersection& Intersection::operator=(const Intersection& Other)
    {
        object = Other.object;
        ts = Other.ts;
        return *this;
    }
}
