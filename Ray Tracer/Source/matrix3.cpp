/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "matrix3.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Matrix3::Matrix3()
        : data {}
    {
    }

    Matrix3::Matrix3(const std::array<std::array<double, 3>, 3> Data)
        : data {Data}
    {
    }

    Matrix3::Matrix3(const Matrix3& Other)
        : data {Other.data}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Matrix3& Matrix)
    {
        std::string string = "{";
        for(const std::array<double, 3>&Row : Matrix.data)
        {
            string += "{";
            for(const double D : Row)
                string += std::to_string(D) + ", ";
            string += "\b\b}, ";
        }
        string += "\b\b}";
        return os << std::format("Matrix3({})", string);
    }

    /*** Method ***/
    double Matrix3::cofactor(const int Row, const int Column) const
    {
        if(((Row + Column) % 2) != 0)
            return -minor(Row, Column);
        else
            return minor(Row, Column);
    }

    double Matrix3::determinant() const
    {
        double d = 0.0;
        const int Row = 0; // Using Row 0; Other Rows Should Produce The Same Result
        for(int column = 0; column < 3; column++)
            d += data[Row][column] * cofactor(Row, column);
        return d;
    }

    double Matrix3::minor(const int Row, const int Column) const
    {
        return submatrix(Row, Column).determinant();
    }

    Matrix2 Matrix3::submatrix(const int Row, const int Column) const
    {
        Matrix2 matrix;
        int r = 0, c = 0;
        for(int row = 0; row < 3; row++)
        {
            if(row != Row)
            {
                for(int column = 0; column < 3; column++)
                {
                    if(column != Column)
                    {
                        matrix[r][c] = data[row][column];
                        c++;
                    }
                }
                c = 0;
                r++;
            }
        }
        return matrix;
    }

    /*** Operator ***/
    std::array<double, 3>& Matrix3::operator[](const int Row)
    {
        return data[Row];
    }

    bool Matrix3::operator==(const Matrix3& Other) const
    {
        return (data == Other.data);
    }

    Matrix3& Matrix3::operator=(const Matrix3& Other)
    {
        data = Other.data;
        return *this;
    }
}
