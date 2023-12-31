/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <cmath>
#include <format>
#include <ostream>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Point2
    {
        public:
            /*** Constructor ***/
            Point2();
            Point2(const double X, const double Y);
            Point2(const Point2& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Point2& Point);

            /*** Operator ***/
            bool operator==(const Point2& Other) const;
            Point2& operator=(const Point2& Other); // Assignment Operator

            /*** Variable ***/
            double x, y;
    };
}
