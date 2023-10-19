/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <array>
#include <format>
#include <ostream>
#include "RayTracer/Source/Matrix/Matrix3.h"
#include "RayTracer/Source/Vector/Point3.h"
#include "RayTracer/Source/Vector/Ray3.h"
#include "RayTracer/Source/Vector/Vector3.h"
#include "RayTracer/Source/Vector/Vector4.h"
#include <string>

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
            friend Point3 operator*(const Point3& Point, const Matrix4& Matrix);
            friend Ray3 operator*(const Ray3& Ray, const Matrix4& Matrix);
            friend Vector3 operator*(const Vector3& Vector, const Matrix4& Matrix);
            friend Vector4 operator*(const Vector4& Vector, const Matrix4& Matrix);
            friend std::ostream& operator<<(std::ostream& os, const Matrix4& Matrix);

            /*** Method ***/
            double cofactor(const int Row, const int Column) const;
            double determinant() const;
            static Matrix4 identityMatrix();
            Matrix4 inverse() const;
            double minor(const int Row, const int Column) const;
            Matrix3 submatrix(const int Row, const int Column) const;
            Matrix4 transpose() const;

            /*** Operator ***/
            std::array<double, 4>& operator[](const int Row);
            Matrix4 operator*(const Matrix4& Other) const;
            Point3 operator*(const Point3& Point) const;
            Ray3 operator*(const Ray3& Ray) const;
            Vector3 operator*(const Vector3& Vector) const;
            Vector4 operator*(const Vector4& Vector) const;
            Matrix4& operator*=(const Matrix4& Other);
            bool operator==(const Matrix4& Other) const;
            Matrix4& operator=(const Matrix4& Other); // Assignment Operator

            /*** Variable ***/
            std::array<std::array<double, 4>, 4> data;
    };
}
