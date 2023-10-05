/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "color_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(ColorTest, Color3Addition)
{
    /*** Addition ***/
    /* Original */
    RayTracer::Color3 c1(1.1, -2.2, 3.3);
    RayTracer::Color3 c2(-2.2, 4.4, -6.6);

    /* Addition */
    RayTracer::Color3 c3 = c1 + c2;
    EXPECT_EQ(RayTracer::Color3(-1.1, 2.2, -3.3), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color3(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color3(-2.2, 4.4, -6.6), c2);

    /* Addition Assignment */
    c3 += c1;
    EXPECT_EQ(RayTracer::Color3(0.0, 0.0, 0.0), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color3(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color3(-2.2, 4.4, -6.6), c2);
}

TEST_F(ColorTest, ColorCopy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Color3 c1(1.1, -2.2, 3.3);

    /* Assignment Operator */
    RayTracer::Color3 c2;
    c2 = c1;
    EXPECT_EQ(c1, c2);

    /* Copy Constructor */
    RayTracer::Color3 c3 = c1;
    EXPECT_EQ(c1, c3);
}

TEST_F(ColorTest, Color3ColorMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Original */
    RayTracer::Color3 c1(1.1, -2.2, 3.3);
    RayTracer::Color3 c2(-2.2, 4.4, -6.6);

    /* Multiplication */
    RayTracer::Color3 c3 = c1 * c2;
    EXPECT_EQ(RayTracer::Color3(-2.42, -9.68, -21.78), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color3(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color3(-2.2, 4.4, -6.6), c2);
}

TEST_F(ColorTest, Color3ScalarMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Original */
    RayTracer::Color3 c1(1.1, -2.2, 3.3);

    /* Multiplication; Scalar On Left */
    RayTracer::Color3 c2 = 2.0 * c1;
    EXPECT_EQ(RayTracer::Color3(2.2, -4.4, 6.6), c2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color3(1.1, -2.2, 3.3), c1);

    /* Multiplication; Scalar On Right */
    c2 = c1 * -2.0;
    EXPECT_EQ(RayTracer::Color3(-2.2, 4.4, -6.6), c2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color3(1.1, -2.2, 3.3), c1);

    /* Multiplication Assignment */
    c1 *= 0.5;
    EXPECT_EQ(RayTracer::Color3(0.55, -1.1, 1.65), c1);
}

TEST_F(ColorTest, Color3Subtraction)
{
    /*** Subtraction ***/
    /* Original */
    RayTracer::Color3 c1(1.1, -2.2, 3.3);
    RayTracer::Color3 c2(-2.2, 4.4, -6.6);

    /* Subtraction */
    RayTracer::Color3 c3 = c1 - c2;
    EXPECT_EQ(RayTracer::Color3(3.3, -6.6, 9.9), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color3(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color3(-2.2, 4.4, -6.6), c2);

    /* Subtraction Assignment */
    c3 -= c1;
    EXPECT_EQ(RayTracer::Color3(2.2, -4.4, 6.6), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color3(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color3(-2.2, 4.4, -6.6), c2);
}
