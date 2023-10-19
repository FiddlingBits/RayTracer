/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Matrix3Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Matrix3Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Matrix3 Original({{{1.1, -6.6, -2.2}, {7.7, 3.3, -8.8}, {-4.4, 9.9, 5.5}}});

    /* Assignment Operator */
    RayTracer::Matrix3 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Matrix3Test, Cofactor)
{
    /*** Cofactor ***/
    /* Matrix */
    const RayTracer::Matrix3 Matrix({{{1.1, -6.6, -2.2}, {7.7, 3.3, -8.8}, {-4.4, 9.9, 5.5}}});

    /* Cofactor */
    const std::array<std::array<double, 3>, 3> ExpectedCofactor{{{105.27, -3.63, 90.75}, {14.52, -3.63, 18.15}, {65.34, -7.26, 54.45}}};
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
            EXPECT_NEAR(ExpectedCofactor[row][column], Matrix.cofactor(row, column), 0.000001);
    }
}

TEST_F(Matrix3Test, CopyConstructor)
{
    /*** Copy Constructor ***/
    /* Original */
    const RayTracer::Matrix3 Original({{{1.1, -6.6, -2.2}, {7.7, 3.3, -8.8}, {-4.4, 9.9, 5.5}}});

    /* Copy Constructor */
    const RayTracer::Matrix3 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Matrix3Test, Determinant)
{
    /*** Determinant ***/
    /* Matrix */
    const RayTracer::Matrix3 Matrix({{{1.1, -6.6, -2.2}, {7.7, 3.3, -8.8}, {-4.4, 9.9, 5.5}}});

    /* Determinant */
    EXPECT_NEAR(-59.895, Matrix.determinant(), 0.000001);
}

TEST_F(Matrix3Test, Minor)
{
    /*** Minor ***/
    /* Matrix */
    const RayTracer::Matrix3 Matrix({{{1.1, -6.6, -2.2}, {7.7, 3.3, -8.8}, {-4.4, 9.9, 5.5}}});

    /* Minor */
    const std::array<std::array<double, 3>, 3> ExpectedMinor{{{105.27, 3.63, 90.75}, {-14.52, -3.63, -18.15}, {65.34, 7.26, 54.45}}};
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
            EXPECT_NEAR(ExpectedMinor[row][column], Matrix.minor(row, column), 0.000001);
    }
}

TEST_F(Matrix3Test, Print)
{
    /*** Print ***/
    /* Matrix */
    const RayTracer::Matrix3 Matrix({{{1.1, -6.6, -2.2}, {7.7, 3.3, -8.8}, {-4.4, 9.9, 5.5}}});

    /* Print */
    std::stringstream ss;
    ss << Matrix;
    EXPECT_EQ("Matrix3((1.1, -6.6, -2.2), (7.7, 3.3, -8.8), (-4.4, 9.9, 5.5))", ss.str());
}

TEST_F(Matrix3Test, Submatrix)
{
    /*** Submatrix ***/
    /* Matrix */
    const RayTracer::Matrix3 Matrix({{{1.1, -6.6, -2.2}, {7.7, 3.3, -8.8}, {-4.4, 9.9, 5.5}}});

    /* Submatrix */
    const std::array<std::array<RayTracer::Matrix2, 3>, 3> ExpectedSubmatrix =
    {
        {
            {
                RayTracer::Matrix2({{{3.3, -8.8}, {9.9, 5.5}}}),
                RayTracer::Matrix2({{{7.7, -8.8}, {-4.4, 5.5}}}),
                RayTracer::Matrix2({{{7.7, 3.3}, {-4.4, 9.9}}})
            },
            {
                RayTracer::Matrix2({{{-6.6, -2.2}, {9.9, 5.5}}}),
                RayTracer::Matrix2({{{1.1, -2.2}, {-4.4, 5.5}}}),
                RayTracer::Matrix2({{{1.1, -6.6}, {-4.4, 9.9}}})
            },
            {
                RayTracer::Matrix2({{{-6.6, -2.2}, {3.3, -8.8}}}),
                RayTracer::Matrix2({{{1.1, -2.2}, {7.7, -8.8}}}),
                RayTracer::Matrix2({{{1.1, -6.6}, {7.7, 3.3}}})
            }
        }
    };
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
            EXPECT_EQ(ExpectedSubmatrix[row][column], Matrix.submatrix(row, column));
    }
}
