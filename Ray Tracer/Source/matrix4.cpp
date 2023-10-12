/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "matrix4.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Matrix4::Matrix4()
        : data {}
    {
    }

    Matrix4::Matrix4(const std::array<std::array<double, 4>, 4> Data)
        : data {Data}
    {
    }

    Matrix4::Matrix4(const Matrix4& Other)
        : data {Other.data}
    {
    }

    /*** Friend ***/
    Ray operator*(const Ray& R, const Matrix4& Matrix)
    {
        return Ray(Matrix * R.origin, Matrix * R.direction);
    }

    Vector4 RayTracer::operator*(const Vector4& Vector, const Matrix4& Matrix)
    {
        return Matrix * Vector;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix4& Matrix)
    {
        std::string string = "{";
        for(const std::array<double, 4>& Row : Matrix.data)
        {
            string += "{";
            for(const double D : Row)
                string += std::to_string(D) + ", ";
            string += "\b\b}, ";
        }
        string += "\b\b}";
        return os << std::format("Matrix4({})", string);
    }

    /*** Method ***/
    double Matrix4::cofactor(const int Row, const int Column) const
    {
        Matrix3 matrix = submatrix(Row, Column);
        if(((Row + Column) % 2) != 0)
            return -matrix.determinant();
        else
            return matrix.determinant();
    }

    double Matrix4::determinant() const
    {
        double d = 0.0;
        const int Row = 0; // Using Row 0; Other Rows Should Produce The Same Result
        for(int column = 0; column < 4; column++)
            d += data[Row][column] * cofactor(Row, column);
        return d;
    }
    
    Matrix4 Matrix4::identityMatrix()
    {
        Matrix4 matrix;
        for(int i = 0; i < 4; i++)
            matrix[i][i] = 1.0;
        return matrix;
    }

    Matrix4 Matrix4::inverse() const
    {
        double d = determinant();
        Matrix4 matrix;
        for(int row = 0; row < 4; row++)
        {
            for(int column = 0; column < 4; column++)
                matrix.data[column][row] = cofactor(row, column) / d;
        }
        return matrix;
    }

    bool Matrix4::isInvertable() const
    {
        const double MaximumDelta {0.000001};
        return (abs(determinant()) > MaximumDelta);
    }

    Matrix3 Matrix4::submatrix(const int Row, const int Column) const
    {
        Matrix3 matrix;
        int r = 0, c = 0;
        for(int row = 0; row < 4; row++)
        {
            if(row != Row)
            {
                for(int column = 0; column < 4; column++)
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

    Matrix4 Matrix4::transpose() const
    {
        Matrix4 matrix;
        for(int row = 0; row < 4; row++)
        {
            for(int column = 0; column < 4; column++)
                matrix[column][row] = data[row][column];
        }
        return matrix;
    }

    /*** Operator ***/
    std::array<double, 4>& Matrix4::operator[](const int Row)
    {
        return data[Row];
    }

    Matrix4 Matrix4::operator*(const Matrix4& Other) const
    {
        Matrix4 matrix;
        for(int row = 0; row < 4; row++)
        {
            for(int column = 0; column < 4; column++)
            {
                Vector4 v1(data[row][0], data[row][1], data[row][2], data[row][3]);
                Vector4 v2(Other.data[0][column], Other.data[1][column], Other.data[2][column], Other.data[3][column]);
                matrix[row][column] = v1.dotProduct(v2);
            }
        }
        return matrix;
    }

    Matrix4& Matrix4::operator*=(const Matrix4& Other)
    {
        *this = *this * Other;
        return *this;
    }

    Ray Matrix4::operator*(const Ray& R) const
    {
        return Ray(*this * R.origin, *this * R.direction);
    }

    Vector4 Matrix4::operator*(const Vector4& Vector) const
    {
        Vector4 v2;
        for(int row = 0; row < 4; row++)
        {
            Vector4 v1(data[row][0], data[row][1], data[row][2], data[row][3]);
            v2[row] = v1.dotProduct(Vector); // Reusing Row Variable For Vector Though Column Is Being Accessed
        }
        return v2;
    }

    bool Matrix4::operator==(const Matrix4& Other) const
    {
        const double MaximumDelta {0.000001};
        for(int row = 0; row < 4; row++)
        {
            for(int column = 0; column < 4; column++)
            {
                if(std::abs(data[row][column] - Other.data[row][column]) > MaximumDelta)
                    return false;
            }
        }
        return true;
    }

    Matrix4& Matrix4::operator=(const Matrix4& Other)
    {
        data = Other.data;
        return *this;
    }
}
