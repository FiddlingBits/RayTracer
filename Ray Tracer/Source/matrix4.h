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
#include "matrix3.h"
#include <iostream>
#include <string>
#include "vector4.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Matrix4
    {
        public:
            /*** Constructor ***/
            Matrix4();
            Matrix4(const std::array<std::array<double, 4>, 4> Data);
            Matrix4(const Matrix4& Other); // Copy Constructor

            /*** Friend ***/
            friend Vector4 operator*(const Vector4& Vector, const Matrix4& Matrix);
            friend std::ostream& operator<<(std::ostream& os, const Matrix4& Matrix);

            /*** Method ***/
            double cofactor(const int Row, const int Column) const;
            double determinant() const;
            static Matrix4 identityMatrix();
            Matrix4 inverse() const;
            bool isInvertable() const;
            Matrix3 submatrix(const int Row, const int Column) const;
            Matrix4 transpose() const;

            /*** Operator ***/
            std::array<double, 4>& operator[](const int Row);
            Matrix4 operator*(const Matrix4& Other) const;
            Matrix4& operator*=(const Matrix4& Other);
            Vector4 operator*(const Vector4& Vector) const;
            bool operator==(const Matrix4& Other) const;
            Matrix4& operator=(const Matrix4& Other); // Assignment Operator

            /*** Variable ***/
            std::array<std::array<double, 4>, 4> data;
    };
}
