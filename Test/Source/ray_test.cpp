/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "ray_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(RayTest, Copy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Vector4 origin(-1.1, 2.2, 3.3, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 direction(4.4, -5.5, 6.6, 0.0); // w == 0.0 For Vector3
    RayTracer::Ray r1(origin, direction);

    /* Assignment Operator */
    RayTracer::Ray r2;
    r2 = r1;
    EXPECT_EQ(r1, r2);

    /* Copy Constructor */
    RayTracer::Ray r3 = r1;
    EXPECT_EQ(r1, r3);
}

TEST_F(RayTest, Position)
{
    /*** Position ***/
    /* Original */
    RayTracer::Vector4 origin(-1.1, 2.2, -3.3, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 direction(4.4, -5.5, 6.6, 0.0); // w == 0.0 For Vector3
    RayTracer::Ray ray(origin, direction);

    /* Position */
    RayTracer::Vector4 point = ray.position(1.0);
    EXPECT_EQ(RayTracer::Vector4(3.3, -3.3, 3.3, 1.0), point);
    point = ray.position(1.5);
    EXPECT_EQ(RayTracer::Vector4(5.5, -6.05, 6.6, 1.0), point);
    point = ray.position(2.0);
    EXPECT_EQ(RayTracer::Vector4(7.7, -8.8, 9.9, 1.0), point);
    
    /* Not Changed */
    EXPECT_EQ(RayTracer::Ray(origin, direction), ray);
}
