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
#include <ostream>
#include <string>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Matrix2
    {
        private:
            /*** Variable ***/
            std::array<std::array<double, 2>, 2> data;

        public:
            /*** Constructor ***/
            Matrix2();
            Matrix2(const std::array<std::array<double, 2>, 2> Data);
            Matrix2(const Matrix2& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Matrix2& Matrix);

            /*** Method ***/
            double determinant() const;

            /*** Operator ***/
            std::array<double, 2>& operator[](const int Row);
            bool operator==(const Matrix2& Other) const;
            Matrix2& operator=(const Matrix2& Other); // Assignment Operator
    };
}
