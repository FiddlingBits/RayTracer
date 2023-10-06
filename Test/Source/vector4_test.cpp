/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "vector4_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Vector4Test, Addition)
{
    /*** Addition ***/
    /* Original */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);
    RayTracer::Vector4 v2(-2.2, 4.4, -6.6, 8.8);

    /* Addition */
    RayTracer::Vector4 v3 = v1 + v2;
    EXPECT_EQ(RayTracer::Vector4(-1.1, 2.2, -3.3, 4.4), v3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);
    EXPECT_EQ(RayTracer::Vector4(-2.2, 4.4, -6.6, 8.8), v2);

    /* Addition Assignment */
    v3 += v1;
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.0, 0.0, 0.0), v3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);
    EXPECT_EQ(RayTracer::Vector4(-2.2, 4.4, -6.6, 8.8), v2);
}

TEST_F(Vector4Test, Copy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);

    /* Assignment Operator */
    RayTracer::Vector4 v2;
    v2 = v1;
    EXPECT_EQ(v1, v2);

    /* Copy Constructor */
    RayTracer::Vector4 v3 = v1;
    EXPECT_EQ(v1, v3);
}

TEST_F(Vector4Test, CrossProduct)
{
    /*** Cross Product ***/
    /* Original */
    RayTracer::Vector4 v1(1.1, 2.2, 3.3, 0.0); // w == 0.0 For Vector3
    RayTracer::Vector4 v2(2.2, 3.3, 4.4, 0.0); // w == 0.0 For Vector3

    /* Cross Product Success */
    RayTracer::Vector4 v3 = v1.crossProduct(v2);
    EXPECT_EQ(RayTracer::Vector4(-1.21, 2.42, -1.21, 0.0), v3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, 2.2, 3.3, 0.0), v1);
    EXPECT_EQ(RayTracer::Vector4(2.2, 3.3, 4.4, 0.0), v2);

    /* Original */
    v1 = RayTracer::Vector4(1.1, 2.2, 3.3, 0.0); // w == 0.0 For Vector3
    v2 = RayTracer::Vector4(2.2, 3.3, 4.4, 1.0); // w == 1.0 For Point3

    /* Cross Product Failure */
    v3 = v1.crossProduct(v2);
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.0, 0.0, 0.0), v3); // Vector4() Returned If Either v1 Or v2 Not A Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, 2.2, 3.3, 0.0), v1);
    EXPECT_EQ(RayTracer::Vector4(2.2, 3.3, 4.4, 1.0), v2);
}

TEST_F(Vector4Test, DotProduct)
{
    /*** Dot Product ***/
    /* Original */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);
    RayTracer::Vector4 v2(-2.2, 4.4, -6.6, 8.8);

    /* Dot Product */
    EXPECT_EQ(-72.6, v1.dotProduct(v2));

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);
    EXPECT_EQ(RayTracer::Vector4(-2.2, 4.4, -6.6, 8.8), v2);
}

TEST_F(Vector4Test, IsPoint3)
{
    /*** Is Point3 ***/
    /* Set */
    RayTracer::Vector4 v(1.1, -2.2, 3.3, 1.0); // w == 1.0 For Point3

    /* Is Point3 */
    EXPECT_TRUE(v.isPoint3());

    /* Is NOT Vector3 */
    EXPECT_FALSE(v.isVector3());
}

TEST_F(Vector4Test, IsVector3)
{
    /*** Is Vector3 ***/
    /* Set */
    RayTracer::Vector4 v(1.1, -2.2, 3.3, 0.0); // w == 0.0 For Vector3

    /* Is Vector3 */
    EXPECT_TRUE(v.isVector3());

    /* Is NOT Point3 */
    EXPECT_FALSE(v.isPoint3());
}

TEST_F(Vector4Test, Magnitude)
{
    /*** Magnitude ***/
    /* Original */
    RayTracer::Vector4 v(1.1, -2.2, 3.3, -4.4);

    /* Magnitude */
    EXPECT_NEAR(6.024948, v.magnitude(), 0.000001);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v);
}

TEST_F(Vector4Test, Negation)
{
    /*** Subtraction ***/
    /* Orignal */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);

    /* Negation */
    RayTracer::Vector4 v2 = -v1;
    EXPECT_EQ(RayTracer::Vector4(-1.1, 2.2, -3.3, 4.4), v2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);
}

TEST_F(Vector4Test, Normalize)
{
    /* Original */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);

    /* Normalize */
    RayTracer::Vector4 v2 = v1.normalize();
    EXPECT_EQ(RayTracer::Vector4(0.182574, -0.365148, 0.547723, -0.730297), v2);
    EXPECT_EQ(1.0, v2.magnitude());

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);
}

TEST_F(Vector4Test, ScalarDivision)
{
    /*** Scalar Division ***/
    /* Original */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);

    /* Division */
    RayTracer::Vector4 v2 = v1 / 2.0;
    EXPECT_EQ(RayTracer::Vector4(0.55, -1.1, 1.65, -2.2), v2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);

    /* Division Assignment */
    v1 /= 0.5;
    EXPECT_EQ(RayTracer::Vector4(2.2, -4.4, 6.6, -8.8), v1);
}

TEST_F(Vector4Test, ScalarMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Original */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);

    /* Multiplication; Scalar On Left */
    RayTracer::Vector4 v2 = 2.0 * v1;
    EXPECT_EQ(RayTracer::Vector4(2.2, -4.4, 6.6, -8.8), v2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);

    /* Multiplication; Scalar On Right */
    v2 = v1 * -2.0;
    EXPECT_EQ(RayTracer::Vector4(-2.2, 4.4, -6.6, 8.8), v2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);

    /* Multiplication Assignment */
    v1 *= 0.5;
    EXPECT_EQ(RayTracer::Vector4(0.55, -1.1, 1.65, -2.2), v1);
}

TEST_F(Vector4Test, Subtraction)
{
    /*** Subtraction ***/
    /* Original */
    RayTracer::Vector4 v1(1.1, -2.2, 3.3, -4.4);
    RayTracer::Vector4 v2(-2.2, 4.4, -6.6, 8.8);

    /* Subtraction */
    RayTracer::Vector4 v3 = v1 - v2;
    EXPECT_EQ(RayTracer::Vector4(3.3, -6.6, 9.9, -13.2), v3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);
    EXPECT_EQ(RayTracer::Vector4(-2.2, 4.4, -6.6, 8.8), v2);

    /* Subtraction Assignment */
    v3 -= v1;
    EXPECT_EQ(RayTracer::Vector4(2.2, -4.4, 6.6, -8.8), v3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Vector4(1.1, -2.2, 3.3, -4.4), v1);
    EXPECT_EQ(RayTracer::Vector4(-2.2, 4.4, -6.6, 8.8), v2);
}
