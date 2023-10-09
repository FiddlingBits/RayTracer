/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "matrix2_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Matrix2Test, Copy)
{
    /*** Copy ***/
    /* Original */
    std::array<std::array<double, 2>, 2> data({{1.1, -2.2}, {3.3, -4.4}});
    RayTracer::Matrix2 m1(data);

    /* Assignment Operator */
    RayTracer::Matrix2 m2;
    m2 = m1;
    EXPECT_EQ(m1, m2);

    /* Copy Constructor */
    RayTracer::Matrix2 m3 = m1;
    EXPECT_EQ(m1, m3);
}

TEST_F(Matrix2Test, Determinant)
{
    /*** Determinant ***/
    /* Original */
    std::array<std::array<double, 2>, 2> data({{1.1, -2.2}, {3.3, -4.4}});
    RayTracer::Matrix2 matrix(data);

    /* Determinant */
    EXPECT_NEAR(2.42, matrix.determinant(), 0.000001);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix2(data), matrix);
}

TEST_F(Matrix2Test, SetGet)
{
    /*** Set/Get ***/
    /* Original */
    RayTracer::Matrix2 matrix;

    /* Set/Get */
    const int Row = 1;
    const int Column = 1;
    const double D = 3.14;
    matrix[Row][Column] = D;
    for(int row = 0; row < 2; row++)
    {
        for(int column = 0; column < 2; column++)
        {
            if((row == Row) && (column == Column))
                EXPECT_EQ(D, matrix[row][column]); // Changed
            else
                EXPECT_EQ(0.0, matrix[row][column]); // Not Changed (Default)
        }
    }
}
