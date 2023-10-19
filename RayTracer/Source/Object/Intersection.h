/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <array>
#include <cmath>
#include <format>
#include <ostream>
#include "RayTracer/Source/Object/Object.h"
#include <string>
#include <sstream>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Intersection
    {
        public:
            /*** Constructor ***/
            Intersection();
            Intersection(const Object& O, const std::array<double, 2>& Ts);
            Intersection(const Intersection& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Intersection& I);

            /*** Method ***/
            std::string toString() const;

            /*** Operator ***/
            bool operator==(const Intersection& Other) const;
            Intersection& operator=(const Intersection& Other); // Assignment Operator

            /*** Variable ***/
            Object object;
            std::array<double, 2> ts;
    };
}
