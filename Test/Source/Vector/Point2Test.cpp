/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Point2Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Point2Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Point2 Original(1.1, -2.2);

    /* Assignment Operator */
    RayTracer::Point2 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Point2Test, CopyConstructor)
{
    /*** Copy Constructor ***/
    /* Original */
    const RayTracer::Point2 Original(1.1, -2.2);

    /* Copy Constructor */
    const RayTracer::Point2 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Point2Test, Print)
{
    /*** Print ***/
    /* Point */
    const RayTracer::Point2 Point(1.1, -2.2);

    /* Print */
    std::stringstream ss;
    ss << Point;
    EXPECT_EQ("Point2(1.1, -2.2)", ss.str());
}
