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
#include "RayTracer/Source/Vector/Point3.h"
#include "RayTracer/Source/Vector/Vector3.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Ray3
    {
        public:
            /*** Constructor ***/
            Ray3();
            Ray3(const Point3& Origin, const Vector3& Direction);
            Ray3(const Ray3& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Ray3& Ray);

            /*** Method ***/
            Point3 position(const double T) const;

            /*** Operator ***/
            bool operator==(const Ray3& Other) const;
            Ray3& operator=(const Ray3& Other); // Assignment Operator

            /*** Variable ***/
            Point3 origin;
            Vector3 direction;
    };
}
