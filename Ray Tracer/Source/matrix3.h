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
#include "matrix2.h"
#include <ostream>
#include <string>
#include <vector>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Matrix3
    {
        private:
            /*** Variable ***/
            std::array<std::array<double, 3>, 3> data;

        public:
            /*** Constructor ***/
            Matrix3();
            Matrix3(const std::array<std::array<double, 3>, 3> Data);
            Matrix3(const Matrix3& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Matrix3& Matrix);

            /*** Method ***/
            double cofactor(const int Row, const int Column) const;
            double determinant() const;
            double minor(const int Row, const int Column) const;
            Matrix2 submatrix(const int Row, const int Column) const;

            /*** Operator ***/
            std::array<double, 3>& operator[](const int Row);
            bool operator==(const Matrix3& Other) const;
            Matrix3& operator=(const Matrix3& Other); // Assignment Operator
    };
}
