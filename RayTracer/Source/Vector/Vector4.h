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

    class Vector4
    {
        public:
            /*** Constructor ***/
            Vector4();
            Vector4(const double X, const double Y, const double Z, const double W);
            Vector4(const Vector4& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Vector4& Vector);

            /*** Method ***/
            double dot(const Vector4& Other) const;

            /*** Operator ***/
            double& operator[](const int Index);
            bool operator==(const Vector4& Other) const;
            Vector4& operator=(const Vector4& Other); // Assignment Operator

            /*** Variable ***/
            double x, y, z, w;
    };
}
