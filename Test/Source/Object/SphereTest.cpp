/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "SphereTest.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(SphereTest, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Sphere S1(RayTracer::Material(RayTracer::Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0));

    /* Assignment Operator */
    RayTracer::Sphere s2;
    s2 = S1;
    EXPECT_EQ(S1, s2);
}

TEST_F(SphereTest, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Sphere S1(RayTracer::Material(RayTracer::Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0));

    /* Copy Constructor */
    const RayTracer::Sphere S2 = S1;
    EXPECT_EQ(S1, S2);
}

TEST_F(SphereTest, IntersectionDefaultTransform)
{
    /*** Intersection (Default Transform) ***/
    /* Sphere */
    const RayTracer::Sphere Sphere( RayTracer::Material(RayTracer::Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0));

    /* Intersection (Two Points) */
    RayTracer::Ray3 ray(RayTracer::Point3(0.0, 0.0, -5.0), RayTracer::Vector3(0.0, 0.0, 1.0));
    std::array<double, 2> expectedTs {4.0, 6.0};
    EXPECT_EQ(expectedTs, Sphere.intersection(ray));

    /* Intersection (One Point) */
    ray = RayTracer::Ray3(RayTracer::Point3(0.0, 1.0, -5.0), RayTracer::Vector3(0.0, 0.0, 1.0));
    expectedTs = std::array<double, 2>({5.0, 5.0});
    EXPECT_EQ(expectedTs, Sphere.intersection(ray));

    /* Intersection (No Points) */
    ray = RayTracer::Ray3(RayTracer::Point3(0.0, 2.0, -5.0), RayTracer::Vector3(0.0, 0.0, 1.0));
    expectedTs = std::array<double, 2>({-std::numeric_limits<double>::max(), std::numeric_limits<double>::max()});
    EXPECT_EQ(expectedTs, Sphere.intersection(ray));

    /* Intersection (Two Points) */
    ray = RayTracer::Ray3(RayTracer::Point3(0.0, 0.0, 0.0), RayTracer::Vector3(0.0, 0.0, 1.0));
    expectedTs = std::array<double, 2>({-1.0, 1.0});
    EXPECT_EQ(expectedTs, Sphere.intersection(ray));

    /* Intersection (Two Points) */
    ray = RayTracer::Ray3(RayTracer::Point3(0.0, 0.0, 5.0), RayTracer::Vector3(0.0, 0.0, 1.0));
    expectedTs = std::array<double, 2>({-6.0, -4.0});
    EXPECT_EQ(expectedTs, Sphere.intersection(ray));
}

TEST_F(SphereTest, IntersectionNondefaultTransform)
{
    /*** Intersection (Nondefault Transform) ***/
    /* Sphere */
    RayTracer::Sphere sphere(RayTracer::Material(RayTracer::Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0));
    RayTracer::Transform4 transform;
    transform.scale(2.0, 2.0, 2.0);
    sphere.setTransform(transform);

    /* Intersection (Two Points) */
    const RayTracer::Ray3 Ray(RayTracer::Point3(0.0, 0.0, -5.0), RayTracer::Vector3(0.0, 0.0, 1.0));
    const std::array<double, 2> ExpectedTs{3.0, 7.0};
    EXPECT_EQ(ExpectedTs, sphere.intersection(Ray));
}

TEST_F(SphereTest, NormalAtDefaultTransform)
{
    /*** Normal At (Default Transform) ***/
    /* Sphere */
    const RayTracer::Sphere Sphere(RayTracer::Material(RayTracer::Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0));

    /* Normal At */
    RayTracer::Vector3 normal = Sphere.normalAt(RayTracer::Point3(1.0, 0.0, 0.0));
    EXPECT_EQ(RayTracer::Vector3(1.0, 0.0, 0.0), normal);

    /* Normal At */
    normal = Sphere.normalAt(RayTracer::Point3(0.0, 1.0, 0.0));
    EXPECT_EQ(RayTracer::Vector3(0.0, 1.0, 0.0), normal);

    /* Normal At */
    normal = Sphere.normalAt(RayTracer::Point3(0.0, 0.0, 1.0));
    EXPECT_EQ(RayTracer::Vector3(0.0, 0.0, 1.0), normal);

    /* Normal At */
    normal = Sphere.normalAt(RayTracer::Point3(1.0, 1.0, 1.0));
    EXPECT_EQ(RayTracer::Vector3(0.577350, 0.577350, 0.577350), normal);
}

TEST_F(SphereTest, NormalAtNondefaultTransform)
{
    /*** Normal At (Nondefault Transform) ***/
    /* Sphere */
    RayTracer::Sphere sphere(RayTracer::Material(RayTracer::Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0));

    /* Normal At (Sphere Translated) */
    RayTracer::Transform4 translate;
    translate.translation(0.0, 1.0, 0.0);
    sphere.setTransform(translate);
    RayTracer::Vector3 normal = sphere.normalAt(RayTracer::Point3(0.0, 1.707107, -0.707107));
    EXPECT_EQ(RayTracer::Vector3(0.0, 0.707107, -0.707107), normal);

    /* Normal At (Sphere Scaled And Rotated) */
    RayTracer::Transform4 scale;
    scale.scale(1.0, 0.5, 1.0);
    RayTracer::Transform4 rotate;
    rotate.rotateZ(36.0);
    sphere.setTransform(scale * rotate);
    normal = sphere.normalAt(RayTracer::Point3(0.0, 0.707107, -0.707106));
    EXPECT_EQ(RayTracer::Vector3(0.0, 0.970143, -0.242535), normal);
}

TEST_F(SphereTest, Print)
{
    /*** Print ***/
    /* Sphere */
    const RayTracer::Sphere Sphere(RayTracer::Material(RayTracer::Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11.0));

    /* Print */
    std::stringstream ss;
    ss << Sphere;
    EXPECT_EQ("Sphere(Material(Color3(-4.4, 5.5, -6.6), 7.7, -8.8, 9.9, -11), Transform4((1, 0, 0, 0), (0, 1, 0, 0), (0, 0, 1, 0), (0, 0, 0, 1)))", ss.str());
}
