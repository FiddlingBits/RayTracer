/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "ObjectTest.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(ObjectTest, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Object O1(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7));

    /* Assignment Operator */
    RayTracer::Object o2;
    o2 = O1;
    EXPECT_EQ(O1, o2);
}

TEST_F(ObjectTest, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Object O1(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7));

    /* Copy Constructor */
    const RayTracer::Object O2 = O1;
    EXPECT_EQ(O1, O2);
}

TEST_F(ObjectTest, Print)
{
    /*** Print ***/
    /* Object */
    const RayTracer::Object O(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7));

    /* Print */
    std::stringstream ss;
    ss << O;
    EXPECT_EQ("Object(Material(Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7))", ss.str());
}
