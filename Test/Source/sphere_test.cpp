/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "sphere_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(SphereTest, Copy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Vector4 center(-1.1, 2.2, 3.3, 1.0); // w == 1.0 For Point3
    RayTracer::Color color(-4.4, 5.5, -6.6);
    RayTracer::Sphere s1(center, color);

    /* Assignment Operator */
    RayTracer::Sphere s2;
    s2 = s1;
    EXPECT_EQ(s1, s2);

    /* Copy Constructor */
    RayTracer::Sphere s3 = s1;
    EXPECT_EQ(s1, s3);
}

TEST_F(SphereTest, IntersectionCustomTransform)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Vector4 center(0.0, 0.0, 0.0, 1.0); // w == 1.0 For Point3
    RayTracer::Color color(1.0, 1.0, 1.0);
    RayTracer::Sphere sphere(center, color);
    RayTracer::Transform transform;
    transform.scale(2.0, 2.0, 2.0);
    sphere.setTransform(transform);

    /* Intersection */
    RayTracer::Ray ray(RayTracer::Vector4(0.0, 0.0, -5.0, 1.0), RayTracer::Vector4(0.0, 0.0, 1.0, 0.0)); // w == 1.0 For Point3; w == 0.0 For Vector3
    std::array<double, 2> actual = sphere.intersection(ray);
    std::array<double, 2> expected({3.0, 7.0}); // Two Points
    EXPECT_EQ(expected, actual);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Sphere(center, color), sphere);
}

TEST_F(SphereTest, IntersectionDefaultTransform)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Vector4 center(0.0, 0.0, 0.0, 1.0); // w == 1.0 For Point3
    RayTracer::Color color(1.0, 1.0, 1.0);
    RayTracer::Sphere sphere(center, color);

    /* Intersection */
    RayTracer::Ray ray(RayTracer::Vector4(0.0, 0.0, -5.0, 1.0), RayTracer::Vector4(0.0, 0.0, 1.0, 0.0)); // w == 1.0 For Point3; w == 0.0 For Vector3
    std::array<double, 2> actual = sphere.intersection(ray);
    std::array<double, 2> expected({4.0, 6.0}); // Two Points
    EXPECT_EQ(expected, actual);
    ray = RayTracer::Ray(RayTracer::Vector4(0.0, 1.0, -5.0, 1.0), RayTracer::Vector4(0.0, 0.0, 1.0, 0.0)); // w == 1.0 For Point3; w == 0.0 For Vector3
    actual = sphere.intersection(ray);
    expected = std::array<double, 2>({5.0, 5.0}); // One Point
    EXPECT_EQ(expected, actual);
    ray = RayTracer::Ray(RayTracer::Vector4(0.0, 2.0, -5.0, 1.0), RayTracer::Vector4(0.0, 0.0, 1.0, 0.0)); // w == 1.0 For Point3; w == 0.0 For Vector3
    actual = sphere.intersection(ray);
    expected = std::array<double, 2>({-std::numeric_limits<double>::max(), -std::numeric_limits<double>::max()}); // Zero Points
    EXPECT_EQ(expected, actual);
    ray = RayTracer::Ray(RayTracer::Vector4(0.0, 0.0, 0.0, 1.0), RayTracer::Vector4(0.0, 0.0, 1.0, 0.0)); // Ray Inside Sphere; w == 1.0 For Point3; w == 0.0 For Vector3
    actual = sphere.intersection(ray);
    expected = std::array<double, 2>({-1.0, 1.0}); // Two Points
    EXPECT_EQ(expected, actual);
    ray = RayTracer::Ray(RayTracer::Vector4(0.0, 0.0, 5.0, 1.0), RayTracer::Vector4(0.0, 0.0, 1.0, 0.0)); // Sphere Behind Ray; w == 1.0 For Point3; w == 0.0 For Vector3
    actual = sphere.intersection(ray);
    expected = std::array<double, 2>({-6.0, -4.0}); // Two Points
    EXPECT_EQ(expected, actual);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Sphere(center, color), sphere);
}
