/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Matrix4.h"

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
    Point3 operator*(const Point3& Point, const Matrix4& Matrix)
    {
        return Matrix * Point;
    }

    Ray3 operator*(const Ray3& Ray, const Matrix4& Matrix)
    {
        return Matrix * Ray;
    }

    Vector3 operator*(const Vector3& Vector, const Matrix4& Matrix)
    {
        return Matrix * Vector;
    }

    Vector4 operator*(const Vector4& Vector, const Matrix4& Matrix)
    {
        return Matrix * Vector;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix4& Matrix)
    {
        std::string string {"Matrix4("};
        for(const std::array<double, 4>& Row : Matrix.data)
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
    double Matrix4::cofactor(const int Row, const int Column) const
    {
        if(((Row + Column) % 2) != 0)
            return -minor(Row, Column);
        else
            return minor(Row, Column);
    }

    double Matrix4::determinant() const
    {
        double determinant = 0.0;
        const int Row = 0; // Using Row 0; Other Rows Should Produce The Same Result
        for(int column = 0; column < data[Row].size(); column++)
            determinant += data[Row][column] * cofactor(Row, column);
        return determinant;
    }

    Matrix4 Matrix4::identityMatrix()
    {
        Matrix4 matrix;
        for(int i = 0; i < matrix.data.size(); i++)
            matrix[i][i] = 1.0;
        return matrix;
    }

    Matrix4 Matrix4::inverse() const
    {
        const double Determinant = determinant();
        Matrix4 matrix;
        for(int row = 0; row < data.size(); row++)
        {
            for(int column = 0; column < data[row].size(); column++)
                matrix.data[column][row] = cofactor(row, column) / Determinant;
        }
        return matrix;
    }

    double Matrix4::minor(const int Row, const int Column) const
    {
        return submatrix(Row, Column).determinant();
    }

    Matrix3 Matrix4::submatrix(const int Row, const int Column) const
    {
        Matrix3 matrix;
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

    Matrix4 Matrix4::transpose() const
    {
        Matrix4 matrix;
        for(int row = 0; row < data.size(); row++)
        {
            for(int column = 0; column < data[row].size(); column++)
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
                matrix[row][column] = v1.dot(v2);
            }
        }
        return matrix;
    }

    Point3 Matrix4::operator*(const Point3& Point) const
    {
        Vector4 vector = *this * Vector4(Point.x, Point.y, Point.z, 1.0); // w == 1.0 For Point3
        return Point3(vector.x, vector.y, vector.z);
    }

    Ray3 Matrix4::operator*(const Ray3& Ray) const
    {
        return Ray3(*this * Ray.origin, *this * Ray.direction);
    }

    Vector3 Matrix4::operator*(const Vector3& Vector) const
    {
        Vector4 vector = *this * Vector4(Vector.x, Vector.y, Vector.z, 0.0); // w == 0.0 For Vector3
        return Vector3(vector.x, vector.y, vector.z);
    }

    Vector4 Matrix4::operator*(const Vector4& Vector) const
    {
        Vector4 vector;
        for(int row = 0; row < 4; row++)
            vector[row] = Vector4(data[row][0], data[row][1], data[row][2], data[row][3]).dot(Vector);
        return vector;
    }

    Matrix4& Matrix4::operator*=(const Matrix4& Other)
    {
        *this = *this * Other;
        return *this;
    }

    bool Matrix4::operator==(const Matrix4& Other) const
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

    Matrix4& Matrix4::operator=(const Matrix4& Other)
    {
        data = Other.data;
        return *this;
    }
}
