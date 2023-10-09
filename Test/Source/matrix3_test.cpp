/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "matrix3_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Matrix3Test, Cofactor)
{
    /*** Cofactor ***/
    /* Original */
    std::array<std::array<double, 3>, 3> data({{1.1, -2.2, 3.3}, {-4.4, 5.5, -6.6}, {7.7, -8.8, 9.9}});
    RayTracer::Matrix3 matrix(data);

    /* Cofactor */
    EXPECT_NEAR(-7.26, matrix.cofactor(1, 0), 0.000001);
    EXPECT_NEAR(-14.52, matrix.cofactor(1, 1), 0.000001);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix3(data), matrix);
}

TEST_F(Matrix3Test, Copy)
{
    /*** Copy ***/
    /* Original */
    std::array<std::array<double, 3>, 3> data({{1.1, -2.2, 3.3}, {-4.4, 5.5, -6.6}, {7.7, -8.8, 9.9}});
    RayTracer::Matrix3 m1(data);

    /* Assignment Operator */
    RayTracer::Matrix3 m2;
    m2 = m1;
    EXPECT_EQ(m1, m2);

    /* Copy Constructor */
    RayTracer::Matrix3 m3 = m1;
    EXPECT_EQ(m1, m3);
}

TEST_F(Matrix3Test, Determinant)
{
    /*** Determinant ***/
    /* Original */
    std::array<std::array<double, 3>, 3> data({{1.1, -2.2, 3.3}, {-4.4, 5.5, -6.6}, {7.7, -8.8, 9.9}});
    RayTracer::Matrix3 matrix(data);

    /* Determinant */
    EXPECT_NEAR(0.0, matrix.determinant(), 0.000001);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix3(data), matrix);

    /* Original */
    data = std::array<std::array<double, 3>, 3>({{1.1, -6.6, 5.5}, {7.7, -2.2, -4.4}, {9.9, -8.8, 3.3}});
    matrix = RayTracer::Matrix3(data);

    /* Determinant */
    EXPECT_NEAR(151.734, matrix.determinant(), 0.000001);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix3(data), matrix);
}

TEST_F(Matrix3Test, Minor)
{
    /*** Minor ***/
    /* Original */
    std::array<std::array<double, 3>, 3> data({{1.1, -2.2, 3.3}, {-4.4, 5.5, -6.6}, {7.7, -8.8, 9.9}});
    RayTracer::Matrix3 matrix(data);

    /* Minor */
    EXPECT_NEAR(7.26, matrix.minor(1, 0), 0.000001);
    EXPECT_NEAR(-14.52, matrix.minor(1, 1), 0.000001);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix3(data), matrix);
}

TEST_F(Matrix3Test, SetGet)
{
    /*** Set/Get ***/
    /* Original */
    RayTracer::Matrix3 matrix;

    /* Set/Get */
    const int Row = 1;
    const int Column = 1;
    const double D = 3.14;
    matrix[Row][Column] = D;
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            if((row == Row) && (column == Column))
                EXPECT_EQ(D, matrix[row][column]); // Changed
            else
                EXPECT_EQ(0.0, matrix[row][column]); // Not Changed (Default)
        }
    }
}

TEST_F(Matrix3Test, Submatrix)
{
    /*** Submatrix ***/
    /* Original */
    std::array<std::array<double, 3>, 3> data3({{1.1, -2.2, 3.3}, {-4.4, 5.5, -6.6}, {7.7, -8.8, 9.9}});
    RayTracer::Matrix3 matrix3(data3);

    /* Submatrix */
    RayTracer::Matrix2 matrix2 = matrix3.submatrix(0, 2);
    std::array<std::array<double, 2>, 2> data2({{-4.4, 5.5}, {7.7, -8.8}});
    EXPECT_EQ(RayTracer::Matrix2(data2), matrix2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix3(data3), matrix3);
}
