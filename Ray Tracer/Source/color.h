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

    class Color
    {
        public:
            /*** Constructor ***/
            Color();
            Color(const double R, const double G, const double B);
            Color(const Color& Other); // Copy Constructor

            /*** Friend ***/
            friend Color operator*(const double Scalar, const Color& C);
            friend std::ostream& operator<<(std::ostream& os, const Color& C);

            /*** Method ***/
            std::string toString() const;

            /*** Operator ***/
            Color operator*(const Color& Other) const;
            Color& operator*=(const Color& Other);
            Color operator*(const double Scalar) const;
            Color& operator*=(const double Scalar);
            Color operator+(const Color& Other) const;
            Color& operator+=(const Color& Other);
            Color operator-(const Color& Other) const;
            Color& operator-=(const Color& Other);
            bool operator==(const Color& Other) const;
            Color& operator=(const Color& Other); // Assignment Operator

            /*** Variable ***/
            double r, g, b;
    };
}
