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
#include "RayTracer/Source/Vector/Vector3.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Point3
    {
        public:
            /*** Constructor ***/
            Point3();
            Point3(const double X, const double Y, const double Z);
            Point3(const Point3& Other); // Copy Constructor

            /*** Friend ***/
            friend Point3 operator+(const Vector3& Vector, const Point3& Point);
            friend std::ostream& operator<<(std::ostream& os, const Point3& Point);

            /*** Operator ***/
            Point3 operator+(const Vector3& Vector) const;
            Vector3 operator-(const Point3& Other) const;
            bool operator==(const Point3& Other) const;
            Point3& operator=(const Point3& Other); // Assignment Operator

            /*** Variable ***/
            double x, y, z;
    };
}
