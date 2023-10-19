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

    class Vector3
    {
        public:
            /*** Constructor ***/
            Vector3();
            Vector3(const double X, const double Y, const double Z);
            Vector3(const Vector3& Other); // Copy Constructor

            /*** Friend ***/
            friend Vector3 operator*(const double Scalar, const Vector3& Vector);
            friend std::ostream& operator<<(std::ostream& os, const Vector3& Vector);

            /*** Method ***/
            Vector3 cross(const Vector3& Other) const;
            double dot(const Vector3& Other) const;
            double magnitude() const;
            Vector3 normalize() const;
            Vector3 reflect(const Vector3& Other) const;

            /*** Operator ***/
            Vector3 operator-() const;
            Vector3 operator*(const double Scalar) const;
            Vector3& operator*=(const double Scalar);
            Vector3 operator/(const double Scalar) const;
            Vector3& operator/=(const double Scalar);
            Vector3 operator+(const Vector3& Other) const;
            Vector3& operator+=(const Vector3& Other);
            Vector3 operator-(const Vector3& Other) const;
            Vector3& operator-=(const Vector3& Other);
            bool operator==(const Vector3& Other) const;
            Vector3& operator=(const Vector3& Other); // Assignment Operator

            /*** Variable ***/
            double x, y, z;
    };
}
