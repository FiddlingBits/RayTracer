/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "matrix2.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Matrix2::Matrix2()
        : data {}
    {
    }

    Matrix2::Matrix2(const std::array<std::array<double, 2>, 2> Data)
        : data {Data}
    {
    }

    Matrix2::Matrix2(const Matrix2& Other)
        : data {Other.data}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Matrix2& Matrix)
    {
        std::string string = "{";
        for(const std::array<double, 2>&Row : Matrix.data)
        {
            string += "{";
            for(const double D : Row)
                string += std::to_string(D) + ", ";
            string += "\b\b}, ";
        }
        string += "\b\b}";
        return os << std::format("Matrix2({})", string);
    }

    /*** Method ***/
    double Matrix2::determinant() const
    {
        return (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);
    }

    /*** Operator ***/
    std::array<double, 2>& Matrix2::operator[](const int Row)
    {
        return data[Row];
    }

    bool Matrix2::operator==(const Matrix2& Other) const
    {
        return (data == Other.data);
    }

    Matrix2& Matrix2::operator=(const Matrix2& Other)
    {
        data = Other.data;
        return *this;
    }
}
