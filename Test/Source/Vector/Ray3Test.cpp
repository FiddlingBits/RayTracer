/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Ray3Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Ray3Test, AssignmentOperator)
{
    /*** Copy ***/
    /* Ray */
    const RayTracer::Ray3 R1(RayTracer::Point3(1.1, -2.2, 3.3), RayTracer::Vector3(-4.4, 5.5, -6.6));

    /* Assignment Operator */
    RayTracer::Ray3 r2;
    r2 = R1;
    EXPECT_EQ(R1, r2);
}

TEST_F(Ray3Test, CopyConstructor)
{
    /*** Copy ***/
    /* Ray */
    const RayTracer::Ray3 R1(RayTracer::Point3(1.1, -2.2, 3.3), RayTracer::Vector3(-4.4, 5.5, -6.6));

    /* Copy Constructor */
    const RayTracer::Ray3 R2 = R1;
    EXPECT_EQ(R1, R2);
}

TEST_F(Ray3Test, Position)
{
    /*** Position ***/
    /* Ray */
    const RayTracer::Ray3 Ray(RayTracer::Point3(1.1, -2.2, 3.3), RayTracer::Vector3(-4.4, 5.5, -6.6));

    /* Position (1.0) */
    RayTracer::Point3 point = Ray.position(1.0);
    EXPECT_EQ(RayTracer::Point3(-3.3, 3.3, -3.3), point);

    /* Position (1.4) */
    point = Ray.position(1.5);
    EXPECT_EQ(RayTracer::Point3(-5.5, 6.05, -6.6), point);

    /* Position (2.0) */
    point = Ray.position(2.0);
    EXPECT_EQ(RayTracer::Point3(-7.7, 8.8, -9.9), point);
}

TEST_F(Ray3Test, Print)
{
    /*** Print ***/
    /* Ray */
    const RayTracer::Ray3 Ray(RayTracer::Point3(1.1, -2.2, 3.3), RayTracer::Vector3(-4.4, 5.5, -6.6));

    /* Print */
    std::stringstream ss;
    ss << Ray;
    EXPECT_EQ("Ray3(Point3(1.1, -2.2, 3.3), Vector3(-4.4, 5.5, -6.6))", ss.str());
}
