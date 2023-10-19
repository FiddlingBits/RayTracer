/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Matrix2Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Matrix2Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Matrix2 Original({{{1.1, -2.2}, {3.3, -4.4}}});

    /* Assignment Operator */
    RayTracer::Matrix2 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Matrix2Test, CopyConstructor)
{
    /*** Copyructor ***/
    /* Original */
    const RayTracer::Matrix2 Original({{{1.1, -2.2}, {3.3, -4.4}}});

    /* Copyructor */
    const RayTracer::Matrix2 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Matrix2Test, Determinant)
{
    /*** Determinant ***/
    /* Matrix */
    const RayTracer::Matrix2 Matrix({{{1.1, -2.2}, {3.3, -4.4}}});

    /* Determinant */
    EXPECT_NEAR(2.42, Matrix.determinant(), 0.000001); // (1.1 * -4.4) - (-2.2 * 3.3) = 2.42
}

TEST_F(Matrix2Test, Print)
{
    /*** Print ***/
    /* Matrix */
    const RayTracer::Matrix2 Matrix({{{1.1, -2.2}, {3.3, -4.4}}});

    /* Print */
    std::stringstream ss;
    ss << Matrix;
    EXPECT_EQ("Matrix2((1.1, -2.2), (3.3, -4.4))", ss.str());
}
