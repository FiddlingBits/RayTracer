/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Color3Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Color3Test, Addition)
{
    /*** Addition ***/
    /* Color */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);
    const RayTracer::Color3 C2(-2.2, 4.4, -6.6);

    /* Addition */
    EXPECT_EQ(RayTracer::Color3(-1.1, 2.2, -3.3), C1 + C2);
}

TEST_F(Color3Test, AdditionAssignment)
{
    /*** Addition ***/
    /* Color */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);
    RayTracer::Color3 c2(-2.2, 4.4, -6.6);

    /* Addition Assignment */
    c2 += C1;
    EXPECT_EQ(RayTracer::Color3(-1.1, 2.2, -3.3), c2);
}

TEST_F(Color3Test, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);

    /* Assignment Operator */
    RayTracer::Color3 c2;
    c2 = C1;
    EXPECT_EQ(C1, c2);
}

TEST_F(Color3Test, ColorMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Color */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);
    const RayTracer::Color3 C2(-2.2, 4.4, -6.6);

    /* Multiplication */
    EXPECT_EQ(RayTracer::Color3(-2.42, -9.68, -21.78), C1 * C2);
}

TEST_F(Color3Test, ColorMultiplicationAssignment)
{
    /*** Scalar Multiplication ***/
    /* Color */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);
    RayTracer::Color3 c2(-2.2, 4.4, -6.6);

    /* Multiplication Assignment */
    c2 *= C1;
    EXPECT_EQ(RayTracer::Color3(-2.42, -9.68, -21.78), c2);
}

TEST_F(Color3Test, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);

    /* Copy Constructor */
    const RayTracer::Color3 C2 = C1;
    EXPECT_EQ(C1, C2);
}

TEST_F(Color3Test, Print)
{
    /*** Print ***/
    /* Color */
    const RayTracer::Color3 Color(1.1, -2.2, 3.3);

    /* Print */
    std::stringstream ss;
    ss << Color;
    EXPECT_EQ("Color3(1.1, -2.2, 3.3)", ss.str());
}

TEST_F(Color3Test, ScalarMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Color */
    const RayTracer::Color3 Color(1.1, -2.2, 3.3);

    /* Multiplication (Scalar On Left) */
    EXPECT_EQ(RayTracer::Color3(2.2, -4.4, 6.6), 2.0 * Color);

    /* Multiplication (Scalar On Right) */
    EXPECT_EQ(RayTracer::Color3(-2.2, 4.4, -6.6), Color * -2.0);
}

TEST_F(Color3Test, ScalarMultiplicationAssignment)
{
    /*** Scalar Multiplication ***/
    /* Color */
    RayTracer::Color3 color(1.1, -2.2, 3.3);

    /* Multiplication Assignment */
    color *= 0.5;
    EXPECT_EQ(RayTracer::Color3(0.55, -1.1, 1.65), color);
}

TEST_F(Color3Test, Subtraction)
{
    /*** Subtraction ***/
    /* Color */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);
    const RayTracer::Color3 C2(-2.2, 4.4, -6.6);

    /* Subtraction */
    EXPECT_EQ(RayTracer::Color3(3.3, -6.6, 9.9), C1 - C2);
}

TEST_F(Color3Test, SubtractionAssignment)
{
    /*** Subtraction ***/
    /* Color */
    const RayTracer::Color3 C1(1.1, -2.2, 3.3);
    RayTracer::Color3 c2(-2.2, 4.4, -6.6);

    /* Subtraction Assignment */
    c2 -= C1;
    EXPECT_EQ(RayTracer::Color3(-3.3, 6.6, -9.9), c2);
}

TEST_F(Color3Test, ToString)
{
    /*** Subtraction ***/
    /* Color */
    const RayTracer::Color3 Color(1.1, -2.2, 3.3);

    /* To String */
    EXPECT_EQ("Color3(1.1, -2.2, 3.3)", Color.toString());
}
