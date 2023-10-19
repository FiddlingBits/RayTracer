/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <algorithm>
#include <functional>
#include <limits>
#include <iostream>
#include "RayTracer/Source/Object/Intersection.h"
#include <string>
#include <vector>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class IntersectionList
    {
        private:
            /*** Method ***/
            void sort(const int Index);

            /*** Variable ***/
            std::vector<Intersection> list;

        public:
            /*** Constructor ***/
            IntersectionList();
            IntersectionList(const IntersectionList& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const IntersectionList& IL);

            /*** Method ***/
            void add(const Intersection& I);
            Intersection closestIntersection(const double MinimumT);

            /*** Operator ***/
            Intersection& operator[](const int Index);
            bool operator==(const IntersectionList& Other) const;
            IntersectionList& operator=(const IntersectionList& Other); // Assignment Operator
        };
}
