/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Point3Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Point3Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Point3 Original(1.1, -2.2, 3.3);

    /* Assignment Operator */
    RayTracer::Point3 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Point3Test, CopyConstructor)
{
    /*** Copy Constructor ***/
    /* Original */
    const RayTracer::Point3 Original(1.1, -2.2, 3.3);

    /* Copy Constructor */
    const RayTracer::Point3 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Point3Test, PointSubtraction)
{
    /*** Addition ***/
    /* Vector */
    const RayTracer::Point3 P1(1.1, -2.2, 3.3);
    const RayTracer::Point3 P2(-4.4, 5.5, -6.6);

    /* Subtraction */
    EXPECT_EQ(RayTracer::Vector3(5.5, -7.7, 9.9), P1 - P2); // Vector From p2 To p1
}

TEST_F(Point3Test, Print)
{
    /*** Print ***/
    /* Point */
    const RayTracer::Point3 Point(1.1, -2.2, 3.3);

    /* Print */
    std::stringstream ss;
    ss << Point;
    EXPECT_EQ("Point3(1.1, -2.2, 3.3)", ss.str());
}

TEST_F(Point3Test, VectorAddition)
{
    /*** Addition ***/
    /* Vector */
    const RayTracer::Point3 Point(1.1, -2.2, 3.3);
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);

    /* Addition (Vector On Left) */
    EXPECT_EQ(RayTracer::Point3(-3.3, 3.3, -3.3), Vector + Point);

    /* Addition (Vector On Right) */
    EXPECT_EQ(RayTracer::Point3(-3.3, 3.3, -3.3), Point + Vector);
}
