/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Vector4Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Vector4Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Vector4 Original(1.1, -2.2, 3.3, -4.4);

    /* Assignment Operator */
    RayTracer::Vector4 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Vector4Test, CopyConstructor)
{
    /*** Copy Constructor ***/
    /* Original */
    const RayTracer::Vector4 Original(1.1, -2.2, 3.3, -4.4);

    /* Copy Constructor */
    const RayTracer::Vector4 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Vector4Test, Dot)
{
    /*** Copy Constructor ***/
    /* Vector */
    const RayTracer::Vector4 Vector(1.1, -2.2, 3.3, -4.4);

    /* Dot */
    EXPECT_NEAR(36.3, Vector.dot(Vector), 0.000001);
}

TEST_F(Vector4Test, Print)
{
    /*** Print ***/
    /* Vector */
    const RayTracer::Vector4 Vector(1.1, -2.2, 3.3, -4.4);

    /* Print */
    std::stringstream ss;
    ss << Vector;
    EXPECT_EQ("Vector4(1.1, -2.2, 3.3, -4.4)", ss.str());
}
