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
    RayTracer::Color color(1.1, -2.2, 3.3);
    RayTracer::Material material(RayTracer::Color(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0);
    RayTracer::Sphere s1(color, material);

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
    /*** Intersection (Custom Transform) ***/
    /* Original */
    RayTracer::Color color(1.0, 1.0, 1.0);
    RayTracer::Material material(RayTracer::Color(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0);
    RayTracer::Sphere sphere(color, material);
    RayTracer::Transform transform;
    transform.scale(2.0, 2.0, 2.0);
    sphere.setTransform(transform);

    /* Intersection */
    RayTracer::Ray ray(RayTracer::Vector4(0.0, 0.0, -5.0, 1.0), RayTracer::Vector4(0.0, 0.0, 1.0, 0.0)); // w == 1.0 For Point3; w == 0.0 For Vector3
    std::array<double, 2> actual = sphere.intersection(ray);
    std::array<double, 2> expected({3.0, 7.0}); // Two Points
    EXPECT_EQ(expected, actual);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Sphere(color, material), sphere);
}

TEST_F(SphereTest, IntersectionDefaultTransform)
{
    /*** Intersection (Default Transform) ***/
    /* Original */
    RayTracer::Color color(1.0, 1.0, 1.0);
    RayTracer::Material material(RayTracer::Color(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0);
    RayTracer::Sphere sphere(color, material);

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
    EXPECT_EQ(RayTracer::Sphere(color, material), sphere);
}

TEST_F(SphereTest, NormalAtWithTransform)
{
    /*** Normal At (With Transform) ***/
    /* Original */
    RayTracer::Color color(1.0, 1.0, 1.0);
    RayTracer::Material material(RayTracer::Color(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0);
    RayTracer::Sphere sphere(color, material);

    /* Normal At */
    RayTracer::Transform transform;
    transform.translation(0.0, 1.0, 0.0);
    sphere.setTransform(transform);
    RayTracer::Vector4 normal = sphere.normalAt(RayTracer::Vector4(0.0, 1.707107, -0.707107, 1.0)); // w == 1.0 For Point3
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.707107, -0.707107, 0.0), normal); // w == 0.0 For Vector3
    RayTracer::Transform scale;
    scale.scale(1.0, 0.5, 1.0);
    RayTracer::Transform rotate;
    rotate.rotateZ(36.0);
    transform = scale * rotate;
    sphere.setTransform(transform);
    normal = sphere.normalAt(RayTracer::Vector4(0.0, 0.707107, -0.707106, 1.0));
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.970143, -0.242535, 0.0), normal); // w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Sphere(color, material), sphere);
}

TEST_F(SphereTest, NormalAtWithoutTransform)
{
    /*** Normal At (Without Transform) ***/
    /* Original */
    RayTracer::Color color(1.0, 1.0, 1.0);
    RayTracer::Material material(RayTracer::Color(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0);
    RayTracer::Sphere sphere(color, material);

    /* Normal At */
    RayTracer::Vector4 normal = sphere.normalAt(RayTracer::Vector4(1.0, 0.0, 0.0, 1.0)); // w == 1.0 For Point3
    EXPECT_EQ(RayTracer::Vector4(1.0, 0.0, 0.0, 0.0), normal); // w == 0.0 For Vector3
    normal = sphere.normalAt(RayTracer::Vector4(2.0, 0.0, 0.0, 1.0)); // Point3 Not Normalized
    EXPECT_EQ(RayTracer::Vector4(1.0, 0.0, 0.0, 0.0), normal); // Vector3 Normalized
    normal = sphere.normalAt(RayTracer::Vector4(0.0, 1.0, 0.0, 1.0));
    EXPECT_EQ(RayTracer::Vector4(0.0, 1.0, 0.0, 0.0), normal);
    normal = sphere.normalAt(RayTracer::Vector4(0.0, 0.0, 1.0, 1.0));
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.0, 1.0, 0.0), normal);
    normal = sphere.normalAt(RayTracer::Vector4(0.577350, 0.577350, 0.577350, 1.0));
    EXPECT_EQ(RayTracer::Vector4(0.577350, 0.577350, 0.577350, 0.0), normal);

    /* Not Changed */
    EXPECT_EQ(RayTracer::Sphere(color, material), sphere);
}
