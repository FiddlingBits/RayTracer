/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "color_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(ColorTest, Addition)
{
    /*** Addition ***/
    /* Original */
    RayTracer::Color c1(1.1, -2.2, 3.3);
    RayTracer::Color c2(-2.2, 4.4, -6.6);

    /* Addition */
    RayTracer::Color c3 = c1 + c2;
    EXPECT_EQ(RayTracer::Color(-1.1, 2.2, -3.3), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color(-2.2, 4.4, -6.6), c2);

    /* Addition Assignment */
    c3 += c1;
    EXPECT_EQ(RayTracer::Color(0.0, 0.0, 0.0), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color(-2.2, 4.4, -6.6), c2);
}

TEST_F(ColorTest, ColorMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Original */
    RayTracer::Color c1(1.1, -2.2, 3.3);
    RayTracer::Color c2(-2.2, 4.4, -6.6);

    /* Multiplication */
    RayTracer::Color c3 = c1 * c2;
    EXPECT_EQ(RayTracer::Color(-2.42, -9.68, -21.78), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color(-2.2, 4.4, -6.6), c2);
}

TEST_F(ColorTest, Copy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Color c1(1.1, -2.2, 3.3);

    /* Assignment Operator */
    RayTracer::Color c2;
    c2 = c1;
    EXPECT_EQ(c1, c2);

    /* Copy Constructor */
    RayTracer::Color c3 = c1;
    EXPECT_EQ(c1, c3);
}

TEST_F(ColorTest, ScalarMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Original */
    RayTracer::Color c1(1.1, -2.2, 3.3);

    /* Multiplication; Scalar On Left */
    RayTracer::Color c2 = 2.0 * c1;
    EXPECT_EQ(RayTracer::Color(2.2, -4.4, 6.6), c2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color(1.1, -2.2, 3.3), c1);

    /* Multiplication; Scalar On Right */
    c2 = c1 * -2.0;
    EXPECT_EQ(RayTracer::Color(-2.2, 4.4, -6.6), c2);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color(1.1, -2.2, 3.3), c1);

    /* Multiplication Assignment */
    c1 *= 0.5;
    EXPECT_EQ(RayTracer::Color(0.55, -1.1, 1.65), c1);
}

TEST_F(ColorTest, Subtraction)
{
    /*** Subtraction ***/
    /* Original */
    RayTracer::Color c1(1.1, -2.2, 3.3);
    RayTracer::Color c2(-2.2, 4.4, -6.6);

    /* Subtraction */
    RayTracer::Color c3 = c1 - c2;
    EXPECT_EQ(RayTracer::Color(3.3, -6.6, 9.9), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color(-2.2, 4.4, -6.6), c2);

    /* Subtraction Assignment */
    c3 -= c1;
    EXPECT_EQ(RayTracer::Color(2.2, -4.4, 6.6), c3);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Color(1.1, -2.2, 3.3), c1);
    EXPECT_EQ(RayTracer::Color(-2.2, 4.4, -6.6), c2);
}
