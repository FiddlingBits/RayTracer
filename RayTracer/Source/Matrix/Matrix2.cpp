/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Matrix2.h"

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
        std::string string {"Matrix2("};
        for(const std::array<double, 2>& Row : Matrix.data)
        {
            string += "(";
            for(const double Value : Row)
                string += std::format("{}, ", Value);
            string.replace(string.size() - 2, 2, "), "); // Replace Final ", " With "), "
        }
        string.replace(string.size() - 2, 2, ")"); // Replace Final ", " With ")"
        return os << string;
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
        const double Delta {0.000001};
        for(int row = 0; row < data.size(); row++)
        {
            for(int column = 0; column < data[row].size(); column++)
            {
                if(std::abs(data[row][column] - Other.data[row][column]) > Delta)
                    return false;
            }
        }
        return true;
    }

    Matrix2& Matrix2::operator=(const Matrix2& Other)
    {
        data = Other.data;
        return *this;
    }
}
