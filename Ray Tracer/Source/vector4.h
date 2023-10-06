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
            friend Vector4 operator*(const double Scalar, const Vector4& V);
            friend std::ostream& operator<<(std::ostream& os, const Vector4& V);

            /*** Method ***/
            Vector4 crossProduct(const Vector4& Other) const;
            double dotProduct(const Vector4& Other) const;
            bool isPoint3() const;
            bool isVector3() const;
            double magnitude() const;
            Vector4 normalize() const;

            /*** Operator ***/
            Vector4 operator-() const;
            Vector4 operator*(const double Scalar) const;
            Vector4& operator*=(const double Scalar);
            Vector4 operator/(const double Scalar) const;
            Vector4& operator/=(const double Scalar);
            Vector4 operator+(const Vector4& Other) const;
            Vector4& operator+=(const Vector4& Other);
            Vector4 operator-(const Vector4& Other) const;
            Vector4& operator-=(const Vector4& Other);
            bool operator==(const Vector4& Other) const;
            Vector4& operator=(const Vector4& Other); // Assignment Operator

            /*** Variable ***/
            double x, y, z, w;
    };
}
