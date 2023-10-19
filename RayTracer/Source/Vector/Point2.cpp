/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Point2.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Point2::Point2()
        : x {}, y {}
    {
    }

    Point2::Point2(const double X, const double Y)
        : x {X}, y {Y}
    {
    }

    Point2::Point2(const Point2& Other)
        : x {Other.x}, y {Other.y}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Point2& Point)
    {
        return os << std::format("Point2({}, {})", Point.x, Point.y);
    }

    /*** Operator ***/
    bool Point2::operator==(const Point2& Other) const
    {
        const double Delta {0.000001};
        return (std::abs(x - Other.x) <= Delta) &&
               (std::abs(y - Other.y) <= Delta);
    }

    Point2& Point2::operator=(const Point2& Other)
    {
        x = Other.x;
        y = Other.y;
        return *this;
    }
}
