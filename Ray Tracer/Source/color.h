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

    class Color3
    {
        public:
            /*** Constructor ***/
            Color3();
            Color3(const double R, const double G, const double B);
            Color3(const Color3& Other); // Copy Constructor

            /*** Friend ***/
            friend Color3 operator*(const double Scalar, const Color3& Color);
            friend std::ostream& operator<<(std::ostream& os, const Color3& Color);

            /*** Operator ***/
            Color3 operator*(const Color3& Other) const;
            Color3& operator*=(const Color3& Other);
            Color3 operator*(const double Scalar) const;
            Color3& operator*=(const double Scalar);
            Color3 operator+(const Color3& Other) const;
            Color3& operator+=(const Color3& Other);
            Color3 operator-(const Color3& Other) const;
            Color3& operator-=(const Color3& Other);
            bool operator==(const Color3& Other) const;
            Color3& operator=(const Color3& Other); // Assignment Operator

            /*** Variable ***/
            double r, g, b;
    };
}
