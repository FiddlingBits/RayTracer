/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Matrix4Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Matrix4Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Matrix4 Original({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Assignment Operator */
    RayTracer::Matrix4 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Matrix4Test, Cofactor)
{
    /*** Cofactor ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Cofactor */
    const std::array<std::array<double, 4>, 4> ExpectedCofactor {{{7838.259, -51.909, -259.545, 7128.836}, {-79.86, -186.34, -85.184, -181.016}, {-1011.56, 85.184, 143.748, -1070.124}, {-5261.443, -49.247, 318.109, -4711.74}}};
    for(int row = 0; row < 4; row++)
    {
        for(int column = 0; column < 4; column++)
            EXPECT_NEAR(ExpectedCofactor[row][column], Matrix.cofactor(row, column), 0.000001);
    }
}

TEST_F(Matrix4Test, CopyConstructor)
{
    /*** Copy Constructor ***/
    /* Original */
    const RayTracer::Matrix4 Original({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Copy Constructor */
    const RayTracer::Matrix4 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Matrix4Test, Determinant)
{
    /*** Determinant ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Determinant */
    EXPECT_NEAR(-4035.0596, Matrix.determinant(), 0.000001);
}

TEST_F(Matrix4Test, Identity)
{
    /*** Identity ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}});

    /* Identity */
    EXPECT_EQ(Matrix, RayTracer::Matrix4::identityMatrix());
}

TEST_F(Matrix4Test, Inverse)
{
    /*** Inverse ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Inverse */
    const RayTracer::Matrix4 ExpectedInverse({{{-1.942539, 0.019792, 0.250693, 1.303932}, {0.012864, 0.04618, -0.02111, 0.012205}, {0.064322, 0.021111, -0.035625, -0.078836}, {-1.766723, 0.044861, 0.265206, 1.1677}}});
    EXPECT_EQ(ExpectedInverse, Matrix.inverse());
}

TEST_F(Matrix4Test, MatrixMultiplication)
{
    /*** Matrix Multiplication ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Matrix Multiplication */
    const RayTracer::Matrix4 ActualMatrix = Matrix * Matrix;
    const RayTracer::Matrix4 ExpectedMatrix({{{124.63, 150.04, 194.81, -129.47}, {-131.89, 242, -47.19, 150.04}, {281.93, 66.55, 19.36, -300.08}, {134.31, 212.96, 277.09, -139.15}}});
    EXPECT_EQ(ExpectedMatrix, ActualMatrix);
}

TEST_F(Matrix4Test, MatrixMultiplicationAssignment)
{
    /*** Matrix Multiplication Assignment ***/
    /* Matrix */
    RayTracer::Matrix4 actualMatrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Matrix Multiplication Assignment */
    actualMatrix *= actualMatrix;
    const RayTracer::Matrix4 ExpectedMultiplication({{{124.63, 150.04, 194.81, -129.47}, {-131.89, 242, -47.19, 150.04}, {281.93, 66.55, 19.36, -300.08}, {134.31, 212.96, 277.09, -139.15}}});
    EXPECT_EQ(ExpectedMultiplication, actualMatrix);
}

TEST_F(Matrix4Test, Minor)
{
    /*** Minor ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Minor */
    const std::array<std::array<double, 4>, 4> ExpectedMinor {{{7838.259, 51.909, -259.545, -7128.836}, {79.86, -186.34, 85.184, -181.016}, {-1011.56, -85.184, 143.748, 1070.124}, {5261.443, -49.247, -318.109, -4711.74}}};
    for(int row = 0; row < 4; row++)
    {
        for(int column = 0; column < 4; column++)
            EXPECT_NEAR(ExpectedMinor[row][column], Matrix.minor(row, column), 0.000001);
    }
}

TEST_F(Matrix4Test, Print)
{
    /*** Print ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Print */
    std::stringstream ss;
    ss << Matrix;
    EXPECT_EQ("Matrix4((1.1, 7.7, -13.2, -2.2), (-8.8, 14.3, 3.3, 9.9), (-15.4, -4.4, -11, 16.5), (5.5, 12.1, -17.6, -6.6))", ss.str());
}

TEST_F(Matrix4Test, Submatrix)
{
    /*** Submatrix ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Submatrix */
    const std::array<std::array<RayTracer::Matrix3, 4>, 4> ExpectedSubmatrix =
    {
        {
            {
                RayTracer::Matrix3({{{14.3, 3.3, 9.9}, {-4.4, -11.0, 16.5}, {12.1, -17.6, -6.6}}}),
                RayTracer::Matrix3({{{-8.8, 3.3, 9.9}, {-15.4, -11.0, 16.5}, {5.5, -17.6, -6.6}}}),
                RayTracer::Matrix3({{{-8.8, 14.3, 9.9}, {-15.4, -4.4, 16.5}, {5.5, 12.1, -6.6}}}),
                RayTracer::Matrix3({{{-8.8, 14.3, 3.3}, {-15.4, -4.4, -11.0}, {5.5, 12.1, -17.6}}})
            },
            {
                RayTracer::Matrix3({{{7.7, -13.2, -2.2}, {-4.4, -11.0, 16.5}, {12.1, -17.6, -6.6}}}),
                RayTracer::Matrix3({{{1.1, -13.2, -2.2}, {-15.4, -11.0, 16.5}, {5.5, -17.6, -6.6}}}),
                RayTracer::Matrix3({{{1.1, 7.7, -2.2}, {-15.4, -4.4, 16.5}, {5.5, 12.1, -6.6}}}),
                RayTracer::Matrix3({{{1.1, 7.7, -13.2}, {-15.4, -4.4, -11.0}, {5.5, 12.1, -17.6}}})
            },
            {
                RayTracer::Matrix3({{{7.7, -13.2, -2.2}, {14.3, 3.3, 9.9}, {12.1, -17.6, -6.6}}}),
                RayTracer::Matrix3({{{1.1, -13.2, -2.2}, {-8.8, 3.3, 9.9}, {5.5, -17.6, -6.6}}}),
                RayTracer::Matrix3({{{1.1, 7.7, -2.2}, {-8.8, 14.3, 9.9}, {5.5, 12.1, -6.6}}}),
                RayTracer::Matrix3({{{1.1, 7.7, -13.2}, {-8.8, 14.3, 3.3}, {5.5, 12.1, -17.6}}})
            },
            {
                RayTracer::Matrix3({{{7.7, -13.2, -2.2}, {14.3, 3.3, 9.9}, {-4.4, -11.0, 16.5}}}),
                RayTracer::Matrix3({{{1.1, -13.2, -2.2}, {-8.8, 3.3, 9.9}, {-15.4, -11.0, 16.5}}}),
                RayTracer::Matrix3({{{1.1, 7.7, -2.2}, {-8.8, 14.3, 9.9}, {-15.4, -4.4, 16.5}}}),
                RayTracer::Matrix3({{{1.1, 7.7, -13.2}, {-8.8, 14.3, 3.3}, {-15.4, -4.4, -11.0}}})
            }
        }
    };
    for(int row = 0; row < 4; row++)
    {
        for(int column = 0; column < 4; column++)
            EXPECT_EQ(ExpectedSubmatrix[row][column], Matrix.submatrix(row, column));
    }
}

TEST_F(Matrix4Test, Vector4Multiplication)
{
    /*** Matrix Multiplication ***/
    /* Matrix */
    const RayTracer::Matrix4 Matrix({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}});

    /* Vector4 Multiplication (Vector On Left) */
    const RayTracer::Vector4 Vector(18.7, -19.8, 20.9, -22.0);
    RayTracer::Vector4 actualMatrix = Vector * Matrix;
    const RayTracer::Vector4 ExpectedVector(-359.37, -596.53, -793.76, -359.37);
    EXPECT_EQ(ExpectedVector, actualMatrix);

    /* Vector4 Multiplication (Vector On Right) */
    actualMatrix = Matrix * Vector;
    EXPECT_EQ(ExpectedVector, actualMatrix);
}
