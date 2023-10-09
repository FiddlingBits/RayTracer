/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "matrix4_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Matrix4Test, Copy)
{
    /*** Copy ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 m1(data);

    /* Assignment Operator */
    RayTracer::Matrix4 m2;
    m2 = m1;
    EXPECT_EQ(m1, m2);

    /* Copy Constructor */
    RayTracer::Matrix4 m3 = m1;
    EXPECT_EQ(m1, m3);
}

TEST_F(Matrix4Test, Cofactor)
{
    /*** Cofactor ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, 9.9, -11.0, 5.5}, {-17.6, -2.2, -6.6, 12.1}, {16.5, 7.7, 3.3, -13.2}, {-8.8, -15.4, 14.3, -4.4}});
    RayTracer::Matrix4 matrix(data);

    /* Cofactor */
    EXPECT_NEAR(-1.331, matrix.cofactor(0, 0), 0.000001);
    EXPECT_NEAR(-427.251, matrix.cofactor(1, 1), 0.000001);
    EXPECT_NEAR(-220.946, matrix.cofactor(2, 2), 0.000001);
    EXPECT_NEAR(636.218, matrix.cofactor(3, 3), 0.000001);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix4(data), matrix);
}

TEST_F(Matrix4Test, Determinant)
{
    /*** Determinant ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 matrix(data);

    /* Determinant */
    EXPECT_NEAR(0.0, matrix.determinant(), 0.000001);
    EXPECT_FALSE(matrix.isInvertable()); // Matrix Cannot Be Inverted If Determinant == 0.0

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix4(data), matrix);

    /* Original */
    data = std::array<std::array<double, 4>, 4>({{1.1, 9.9, -11.0, 5.5}, {-17.6, -2.2, -6.6, 12.1}, {16.5, 7.7, 3.3, -13.2}, {-8.8, -15.4, 14.3, -4.4}});
    matrix = RayTracer::Matrix4(data);

    /* Determinant */
    EXPECT_NEAR(11.712799, matrix.determinant(), 0.000001);
    EXPECT_TRUE(matrix.isInvertable()); // Matrix Can Be Inverted If Determinant != 0.0

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix4(data), matrix);
}

TEST_F(Matrix4Test, IdentityMatrix)
{
    /*** Identity Matrix ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 m1(data);

    /* Identity Matrix */
    RayTracer::Matrix4 m2 = m1 * RayTracer::Matrix4::identityMatrix();
    EXPECT_EQ(m1, m2);
}

TEST_F(Matrix4Test, Inverse)
{
    /*** Inverse ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 m1(data);
    data = std::array<std::array<double, 4>, 4>({{1.1, 9.9, -11.0, 5.5}, {-17.6, -2.2, -6.6, 12.1}, {16.5, 7.7, 3.3, -13.2}, {-8.8, -15.4, 14.3, -4.4}});
    RayTracer::Matrix4 m2(data);

    /* Inverse */
    RayTracer::Matrix4 m3 = m2.inverse();
    data = std::array<std::array<double, 4>, 4>({{-0.113636, -0.113636, -0.113636, -0.113636}, {94.431818, -36.477273, -13.75, 58.977273}, {128.409091, -49.772727, -18.863636, 80.227273}, {87.045455, -33.863636, -12.954545, 54.318182}});
    EXPECT_EQ(RayTracer::Matrix4(data), m3);
    m3 = m1 * m2;
    data = std::array<std::array<double, 4>, 4>({{133.1, 108.9, -49.61, -44.77}, {326.7, 263.78, -117.37, -112.53}, {520.3, 418.66, -185.13, -180.29}, {713.9, 573.54, -252.89, -248.05}});
    EXPECT_EQ(RayTracer::Matrix4(data), m3);
    m3 *= m2.inverse();
    EXPECT_EQ(m1, m3);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    EXPECT_EQ(RayTracer::Matrix4(data), m1);
    data = std::array<std::array<double, 4>, 4>({{1.1, 9.9, -11.0, 5.5}, {-17.6, -2.2, -6.6, 12.1}, {16.5, 7.7, 3.3, -13.2}, {-8.8, -15.4, 14.3, -4.4}});
    EXPECT_EQ(RayTracer::Matrix4(data), m2);
}

TEST_F(Matrix4Test, Matrix4Multiplication)
{
    /*** Matrix4 Multiplication ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 m1(data);
    data = std::array<std::array<double, 4>, 4>({{18.7, -19.8, 20.9, -22.0}, {23.1, -24.2, 25.3, -26.4}, {27.5, -28.6, 29.7, -30.8}, {31.9, -33.0, 34.1, -35.2}});
    RayTracer::Matrix4 m2(data);

    /* Matrix4 Multiplication */
    RayTracer::Matrix4 m3 = m1 * m2;
    data = std::array<std::array<double, 4>, 4>({{-79.86, 82.28, -84.7, 87.12}, {-118.58, 121.0, -123.42, 125.84}, {-157.3, 159.72, -162.14, 164.56}, {-196.02, 198.44, -200.86, 203.28}});
    EXPECT_EQ(RayTracer::Matrix4(data), m3);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    EXPECT_EQ(RayTracer::Matrix4(data), m1);
    data = std::array<std::array<double, 4>, 4>({{18.7, -19.8, 20.9, -22.0}, {23.1, -24.2, 25.3, -26.4}, {27.5, -28.6, 29.7, -30.8}, {31.9, -33.0, 34.1, -35.2}});
    EXPECT_EQ(RayTracer::Matrix4(data), m2);

    /* Matrix4 Multiplication Assignment */
    m1 *= m2;
    data = std::array<std::array<double, 4>, 4>({{-79.86, 82.28, -84.7, 87.12}, {-118.58, 121.0, -123.42, 125.84}, {-157.3, 159.72, -162.14, 164.56}, {-196.02, 198.44, -200.86, 203.28}});
    EXPECT_EQ(RayTracer::Matrix4(data), m1);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{18.7, -19.8, 20.9, -22.0}, {23.1, -24.2, 25.3, -26.4}, {27.5, -28.6, 29.7, -30.8}, {31.9, -33.0, 34.1, -35.2}});
    EXPECT_EQ(RayTracer::Matrix4(data), m2);
}

TEST_F(Matrix4Test, SetGet)
{
    /*** Set/Get ***/
    /* Original */
    RayTracer::Matrix4 matrix;

    /* Set/Get */
    const int Row = 1;
    const int Column = 1;
    const double D = 3.14;
    matrix[Row][Column] = D;
    for(int row = 0; row < 4; row++)
    {
        for(int column = 0; column < 4; column++)
        {
            if((row == Row) && (column == Column))
                EXPECT_EQ(D, matrix[row][column]); // Changed
            else
                EXPECT_EQ(0.0, matrix[row][column]); // Not Changed (Default)
        }
    }
}

TEST_F(Matrix4Test, Submatrix)
{
    /*** Submatrix ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data4({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 matrix4(data4);

    /* Submatrix */
    RayTracer::Matrix3 matrix3 = matrix4.submatrix(2, 1);
    std::array<std::array<double, 3>, 3> data3({{1.1, 3.3, -4.4}, {5.5, 7.7, -8.8}, {14.3, 16.5, -17.6}});
    EXPECT_EQ(RayTracer::Matrix3(data3), matrix3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Matrix4(data4), matrix4);
}

TEST_F(Matrix4Test, Transpose)
{
    /*** Transpose ***/
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 m1(data);

    /* Transpose */
    RayTracer::Matrix4 m2 = m1.transpose();
    data = std::array<std::array<double, 4>, 4>({{1.1, 5.5, 9.9, 14.3}, {-2.2, -6.6, -11.0, -15.4}, {3.3, 7.7, 12.1, 16.5}, {-4.4, -8.8, -13.2, -17.6}});
    EXPECT_EQ(RayTracer::Matrix4(data), m2);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    EXPECT_EQ(RayTracer::Matrix4(data), m1);

    /* Transpose */
    m2 = m2.transpose();
    EXPECT_EQ(m1, m2);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    EXPECT_EQ(RayTracer::Matrix4(data), m1);
}

TEST_F(Matrix4Test, Vector4Multiplication)
{
    /*** Vector4 Multiplication /
    /* Original */
    std::array<std::array<double, 4>, 4> data({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    RayTracer::Matrix4 matrix(data);
    RayTracer::Vector4 v1(18.7, -19.8, 20.9, -22.0);

    /* Vector4 Multiplication */
    RayTracer::Vector4 v2 = matrix * v1;
    EXPECT_EQ(RayTracer::Vector4(229.9, 588.06, 946.22, 1304.38), v2);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{1.1, -2.2, 3.3, -4.4}, {5.5, -6.6, 7.7, -8.8}, {9.9, -11.0, 12.1, -13.2}, {14.3, -15.4, 16.5, -17.6}});
    EXPECT_EQ(RayTracer::Matrix4(data), matrix);
}
