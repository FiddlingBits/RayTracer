/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "IntersectionTest.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(IntersectionTest, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Intersection I1(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {-8.8, 9.9});

    /* Assignment Operator */
    RayTracer::Intersection i2;
    i2 = I1;
    EXPECT_EQ(I1, i2);
}

TEST_F(IntersectionTest, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Intersection I1(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {-8.8, 9.9});

    /* Copy Constructor */
    const RayTracer::Intersection I2 = I1;
    EXPECT_EQ(I1, I2);
}

TEST_F(IntersectionTest, Print)
{
    /*** Print ***/
    /* Intersection */
    RayTracer::Intersection I(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {-8.8, 9.9});

    /* Print */
    std::stringstream ss;
    ss << I;
    EXPECT_EQ("Intersection(Object(Material(Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), Ts(-8.8, 9.9))", ss.str());
}

TEST_F(IntersectionTest, ToString)
{
    /*** Subtraction ***/
    /* Intersection */
    RayTracer::Intersection I(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {-8.8, 9.9});

    /* To String */
    EXPECT_EQ("Intersection(Object(Material(Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), Ts(-8.8, 9.9))", I.toString());
}
