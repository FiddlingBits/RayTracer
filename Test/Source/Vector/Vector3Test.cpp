/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Vector3Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Vector3Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Vector3 Original(1.1, -2.2, 3.3);

    /* Assignment Operator */
    RayTracer::Vector3 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Vector3Test, CopyConstructor)
{
    /*** Copy Constructor ***/
    /* Original */
    const RayTracer::Vector3 Original(1.1, -2.2, 3.3);

    /* Copy Constructor */
    const RayTracer::Vector3 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Vector3Test, Cross)
{
    /*** Cross ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, 2.2, 3.3);
    const RayTracer::Vector3 V2(2.2, 3.3, 4.4);

    /* Cross */
    EXPECT_EQ(RayTracer::Vector3(-1.21, 2.42, -1.21), V1.cross(V2));
}

TEST_F(Vector3Test, Dot)
{
    /*** Dot ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, -2.2, 3.3);
    const RayTracer::Vector3 V2(-4.4, 5.5, -6.6);

    /* Dot */
    EXPECT_EQ(-38.72, V1.dot(V2));
}

TEST_F(Vector3Test, Magnitude)
{
    /*** Magnitude ***/
    /* Vector */
    const RayTracer::Vector3 Vector(1.1, -2.2, 3.3);

    /* Magnitude */
    EXPECT_NEAR(4.115823, Vector.magnitude(), 0.000001);
}

TEST_F(Vector3Test, Negation)
{
    /*** Negation ***/
    /* Vector */
    const RayTracer::Vector3 Vector(1.1, -2.2, 3.3);

    /* Negation */
    EXPECT_EQ(RayTracer::Vector3(-1.1, 2.2, -3.3), -Vector);
}

TEST_F(Vector3Test, Normalize)
{
    /*** Normalize ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, -2.2, 3.3);

    /* Normalize */
    const RayTracer::Vector3 V2 = V1.normalize();
    EXPECT_EQ(RayTracer::Vector3(0.267261, -0.534523, 0.801784), V2);
    EXPECT_EQ(1.0, V2.magnitude());
}

TEST_F(Vector3Test, Print)
{
    /*** Print ***/
    /* Vector */
    const RayTracer::Vector3 Vector(1.1, -2.2, 3.3);

    /* Print */
    std::stringstream ss;
    ss << Vector;
    EXPECT_EQ("Vector3(1.1, -2.2, 3.3)", ss.str());
}

TEST_F(Vector3Test, Reflect)
{
    /*** Reflect ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.0, -1.0, 0.0);
    const RayTracer::Vector3 V2(0.0, 1.0, 0.0);

    /* Reflect */
    EXPECT_EQ(RayTracer::Vector3(1.0, 1.0, 0.0), V1.reflect(V2));
}

TEST_F(Vector3Test, ScalarDivision)
{
    /*** Scalar Division ***/
    /* Vector */
    const RayTracer::Vector3 Vector(1.1, -2.2, 3.3);

    /* Division */
    EXPECT_EQ(RayTracer::Vector3(0.55, -1.1, 1.65), Vector / 2.0);
}

TEST_F(Vector3Test, ScalarDivisionAssignment)
{
    /*** Scalar Division ***/
    /* Vector */
    RayTracer::Vector3 vector(1.1, -2.2, 3.3);

    /* Division Assignment */
    vector /= 0.5;
    EXPECT_EQ(RayTracer::Vector3(2.2, -4.4, 6.6), vector);
}

TEST_F(Vector3Test, ScalarMultiplication)
{
    /*** Scalar Multiplication ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, -2.2, 3.3);

    /* Multiplication (Scalar On Left) */
    RayTracer::Vector3 v2 = 2.0 * V1;
    EXPECT_EQ(RayTracer::Vector3(2.2, -4.4, 6.6), v2);

    /* Multiplication (Scalar On Right) */
    v2 = V1 * -2.0;
    EXPECT_EQ(RayTracer::Vector3(-2.2, 4.4, -6.6), v2);
}

TEST_F(Vector3Test, ScalarMultiplicationAssignment)
{
    /*** Scalar Multiplication ***/
    /* Vector */
    RayTracer::Vector3 vector(1.1, -2.2, 3.3);

    /* Multiplication Assignment */
    vector *= 0.5;
    EXPECT_EQ(RayTracer::Vector3(0.55, -1.1, 1.65), vector);
}

TEST_F(Vector3Test, Subtraction)
{
    /*** Subtraction ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, -2.2, 3.3);
    const RayTracer::Vector3 V2(-2.2, 4.4, -6.6);

    /* Subtraction */
    EXPECT_EQ(RayTracer::Vector3(3.3, -6.6, 9.9), V1 - V2);
}

TEST_F(Vector3Test, SubtractionAssignment)
{
    /*** Subtraction ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, -2.2, 3.3);
    RayTracer::Vector3 v2(-2.2, 4.4, -6.6);

    /* Subtraction Assignment */
    v2 -= V1;
    EXPECT_EQ(RayTracer::Vector3(-3.3, 6.6, -9.9), v2);
}

TEST_F(Vector3Test, VectorAddition)
{
    /*** Addition ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, -2.2, 3.3);
    const RayTracer::Vector3 V2(-4.4, 5.5, -6.6);

    /* Addition */
    EXPECT_EQ(RayTracer::Vector3(-3.3, 3.3, -3.3), V1 + V2);
}

TEST_F(Vector3Test, VectorAdditionAssignment)
{
    /*** Addition Assignment ***/
    /* Vector */
    const RayTracer::Vector3 V1(1.1, -2.2, 3.3);
    RayTracer::Vector3 v2(-4.4, 5.5, -6.6);

    /* Addition Assignment */
    v2 += V1;
    EXPECT_EQ(RayTracer::Vector3(-3.3, 3.3, -3.3), v2);
}
