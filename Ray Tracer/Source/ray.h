/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <ostream>
#include <sstream>
#include "vector4.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Ray
    {
        public:
            /*** Constructor ***/
            Ray();
            Ray(const double OX, const double OY, const double OZ, const double DX, const double DY, const double DZ);
            Ray(const Vector4& Origin, const Vector4& Direction);
            Ray(const Ray& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Ray& R);

            /*** Method ***/
            Vector4 position(const double T) const;

            /*** Operator ***/
            bool operator==(const Ray& Other) const;
            Ray& operator=(const Ray& Other); // Assignment Operator

            /*** Variable ***/
            Vector4 origin, direction;
    };
}
