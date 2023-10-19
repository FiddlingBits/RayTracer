/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Matrix3.h"

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
        std::string string{"Matrix3("};
        for(const std::array<double, 3>& Row : Matrix.data)
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
    double Matrix3::cofactor(const int Row, const int Column) const
    {
        if(((Row + Column) % 2) != 0)
            return -minor(Row, Column);
        else
            return minor(Row, Column);
    }

    double Matrix3::determinant() const
    {
        double determinant {0.0};
        const int Row = 0; // Using Row 0; Other Rows Should Produce The Same Result
        for(int column = 0; column < data[Row].size(); column++)
            determinant += data[Row][column] * cofactor(Row, column);
        return determinant;
    }

    double Matrix3::minor(const int Row, const int Column) const
    {
        return submatrix(Row, Column).determinant();
    }

    Matrix2 Matrix3::submatrix(const int Row, const int Column) const
    {
        Matrix2 matrix;
        int r = 0, c = 0;
        for(int row = 0; row < data.size(); row++)
        {
            if(row != Row)
            {
                c = 0;
                for(int column = 0; column < data[row].size(); column++)
                {
                    if(column != Column)
                    {
                        matrix[r][c] = data[row][column];
                        c++;
                    }
                }
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

    Matrix3& Matrix3::operator=(const Matrix3& Other)
    {
        data = Other.data;
        return *this;
    }
}
