/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "transform_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(TransformTest, Copy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Transform t1;
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}); // Identity Matrix
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), t1);

    /* Assignment Operator */
    RayTracer::Transform t2;
    t2 = t1;
    EXPECT_EQ(t1, t2);

    /* Copy Constructor */
    RayTracer::Transform t3 = t1;
    EXPECT_EQ(t1, t3);
}

TEST_F(TransformTest, RotateX)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Transform transform;
    transform.rotateX(45.0);
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {0.0, 0.707107, -0.707107, 0.0}, {0.0, 0.707107, 0.707107, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Scale On Point; Point On Left */
    RayTracer::Vector4 point(0.0, 1.0, 0.0, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 rotate = point * transform;
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.707107, 0.707107, 1.0), rotate); // w == 1.0 For Point3

    /* Scale On Point; Point On Right */
    rotate = transform.inverse() * point; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.707107, -0.707107, 1.0), rotate); // w == 1.0 For Point3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Original */
    transform.rotateX(90.0);
    data = std::array<std::array<double, 4>, 4>({{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Scale On Vector; Vector On Left */
    RayTracer::Vector4 vector(0.0, 1.0, 0.0, 0.0); // w == 0.0 For Vector3
    rotate = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.0, 1.0, 0.0), rotate); // w == 0.0 For Vector3

    /* Scale On Vector; Vector On Right */
    rotate = transform.inverse() * vector; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector4(0.0, 0.0, -1.0, 0.0), rotate); // w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, RotateY)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Transform transform;
    transform.rotateY(45.0);
    std::array<std::array<double, 4>, 4> data({{0.707107, 0.0, 0.707107, 0.0}, {0.0, 1.0, 0.0, 0.0}, {-0.707107, 0.0, 0.707107, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Scale On Point; Point On Left */
    RayTracer::Vector4 point(0.0, 0.0, 1.0, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 rotate = point * transform;
    EXPECT_EQ(RayTracer::Vector4(0.707107, 0.0, 0.707107, 1.0), rotate); // w == 1.0 For Point3

    /* Scale On Point; Point On Right */
    rotate = transform.inverse() * point; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector4(-0.707107, 0.0, 0.707107, 1.0), rotate); // w == 1.0 For Point3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Original */
    transform.rotateY(90.0);
    data = std::array<std::array<double, 4>, 4>({{0.0, 0.0, 1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Scale On Vector; Vector On Left */
    RayTracer::Vector4 vector(0.0, 0.0, 1.0, 0.0); // w == 0.0 For Vector3
    rotate = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(1.0, 0.0, 0.0, 0.0), rotate); // w == 0.0 For Vector3

    /* Scale On Vector; Vector On Right */
    rotate = transform.inverse() * vector; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector4(-1.0, 0.0, 0.0, 0.0), rotate); // w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, RotateZ)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Transform transform;
    transform.rotateZ(45.0);
    std::array<std::array<double, 4>, 4> data({{0.707107, -0.707107, 0.0, 0.0}, {0.707107, 0.707107, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Scale On Point; Point On Left */
    RayTracer::Vector4 point(1.0, 0.0, 0.0, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 rotate = point * transform;
    EXPECT_EQ(RayTracer::Vector4(0.707107, 0.707107, 0.0, 1.0), rotate); // w == 1.0 For Point3

    /* Scale On Point; Point On Right */
    rotate = transform.inverse() * point; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector4(0.707107, -0.707107, 0.0, 1.0), rotate); // w == 1.0 For Point3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Original */
    transform.rotateZ(90.0);
    data = std::array<std::array<double, 4>, 4>({{0.0, -1.0, 0.0, 0.0}, {1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Scale On Vector; Vector On Left */
    RayTracer::Vector4 vector(1.0, 0.0, 0.0, 0.0); // w == 0.0 For Vector3
    rotate = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(0.0, 1.0, 0.0, 0.0), rotate); // w == 0.0 For Vector3

    /* Scale On Vector; Vector On Right */
    rotate = transform.inverse() * vector; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector4(0.0, -1.0, 0.0, 0.0), rotate); // w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, Scale)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Transform transform;
    transform.scale(1.1, -2.2, 3.3);
    std::array<std::array<double, 4>, 4> data({{1.1, 0.0, 0.0, 0.0}, {0.0, -2.2, 0.0, 0.0}, {0.0, 0.0, 3.3, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Scale On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 scale = point * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.84, -12.1, -21.78, 1.0), scale); // w == 1.0 For Point3

    /* Scale On Point; Point On Right */
    scale = transform.inverse() * point; // Inverse Of Multiplication Is Division
    EXPECT_EQ(RayTracer::Vector4(-4.0, -2.5, -2.0, 1.0), scale); // w == 1.0 For Point3

    /* Scale On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // w == 0.0 For Vector3
    scale = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.84, -12.1, -21.78, 0.0), scale); // w == 0.0 For Vector3

    /* Scale On Vector; Vector On Right */
    scale = transform.inverse() * vector; // Inverse Of Multiplication Is Division
    EXPECT_EQ(RayTracer::Vector4(-4.0, -2.5, -2.0, 0.0), scale); // w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, SeveralTransformationsInSequence)
{
    /*** Several Transformations ***/
    /* Original */
    RayTracer::Transform transformRotation;
    transformRotation.rotateX(90);
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformRotation);
    RayTracer::Transform transformScale;
    transformScale.scale(5.0, 5.0, 5.0);
    data = std::array<std::array<double, 4>, 4>({{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformScale);
    RayTracer::Transform transformTranslation;
    transformTranslation.translation(10.0, 5.0, 7.0);
    data = std::array<std::array<double, 4>, 4>({{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformTranslation);

    /* Rotation */
    RayTracer::Vector4 point(1.0, 0.0, 1.0, 1.0); // w == 1.0 For Point3
    point = transformRotation * point;
    EXPECT_EQ(RayTracer::Vector4(1.0, -1.0, 0.0, 1.0), point);

    /* Scale */
    point = transformScale * point;
    EXPECT_EQ(RayTracer::Vector4(5.0, -5.0, 0.0, 1.0), point);

    /* Translation */
    point = transformTranslation * point;
    EXPECT_EQ(RayTracer::Vector4(15.0, 0.0, 7.0, 1.0), point);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformRotation);
    data = std::array<std::array<double, 4>, 4>({{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformScale);
    data = std::array<std::array<double, 4>, 4>({{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformTranslation);
}

TEST_F(TransformTest, SeveralTransformationsChained)
{
    /*** Several Transformations ***/
    /* Original */
    RayTracer::Transform transformRotation;
    transformRotation.rotateX(90);
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformRotation);
    RayTracer::Transform transformScale;
    transformScale.scale(5.0, 5.0, 5.0);
    data = std::array<std::array<double, 4>, 4>({{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformScale);
    RayTracer::Transform transformTranslation;
    transformTranslation.translation(10.0, 5.0, 7.0);
    data = std::array<std::array<double, 4>, 4>({{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformTranslation);
    RayTracer::Transform transformChained = transformTranslation * transformScale * transformRotation; // Applied In Reverse Order Of Desired Order
    data = std::array<std::array<double, 4>, 4>({{5.0, 0.0, 0.0, 10.0}, {0.0, 0.0, -5.0, 5.0}, {0.0, 5.0, 0.0, 7.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformChained);
    
    /* Rotation, Scale, And Translation Chained */
    RayTracer::Vector4 point(1.0, 0.0, 1.0, 1.0); // w == 1.0 For Point3
    point = transformChained * point;
    EXPECT_EQ(RayTracer::Vector4(15.0, 0.0, 7.0, 1.0), point);

    /* Not Changed */
    data = std::array<std::array<double, 4>, 4>({{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformRotation);
    data = std::array<std::array<double, 4>, 4>({{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformScale);
    data = std::array<std::array<double, 4>, 4>({{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformTranslation);
    data = std::array<std::array<double, 4>, 4>({{5.0, 0.0, 0.0, 10.0}, {0.0, 0.0, -5.0, 5.0}, {0.0, 5.0, 0.0, 7.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transformChained);
}

TEST_F(TransformTest, ShearXY)
{
    /*** Shear ***/
    /* Original */
    RayTracer::Transform transform;
    transform.shear(1.1, 0.0, 0.0, 0.0, 0.0, 0.0); // Move X In Proportion To Y
    std::array<std::array<double, 4>, 4> data({{1.0, 1.1, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Shear On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 shear = point * transform;
    EXPECT_EQ(RayTracer::Vector4(1.65, 5.5, -6.6, 1.0), shear); // x = -4.4 - (1.1 * 5.5) = 1.65; w == 1.0 For Point3

    /* Shear On Point; Point On Right */
    shear = transform.inverse() * point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-10.45, 5.5, -6.6, 1.0), shear); // x = -4.4 - (1.1 * 5.5) = -10.45; w == 1.0 For Point3

    /* Shear On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // x = -4.4 - (1.1 * 5.5) = 1.65; w == 0.0 For Vector3
    shear = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(1.65, 5.5, -6.6, 0.0), shear); // w == 0.0 For Vector3

    /* Shear On Vector; Vector On Right */
    shear = transform.inverse() * vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-10.45, 5.5, -6.6, 0.0), shear); // x = -4.4 - (1.1 * 5.5) = -10.45; w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, ShearXZ)
{
    /*** Shear ***/
    /* Original */
    RayTracer::Transform transform;
    transform.shear(0.0, -2.2, 0.0, 0.0, 0.0, 0.0); // Move X In Proportion To Z
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, -2.2, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Shear On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 shear = point * transform;
    EXPECT_EQ(RayTracer::Vector4(10.12, 5.5, -6.6, 1.0), shear); // x = -4.4 + (-2.2 * -6.6) = 10.12; w == 1.0 For Point3

    /* Shear On Point; Point On Right */
    shear = transform.inverse() * point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-18.92, 5.5, -6.6, 1.0), shear); // x = -4.4 - (-2.2 * -6.6) = -18.92; w == 1.0 For Point3

    /* Shear On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // w == 0.0 For Vector3
    shear = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(10.12, 5.5, -6.6, 0.0), shear); // x = -4.4 + (-2.2 * -6.6) = 10.12; w == 0.0 For Vector3

    /* Shear On Vector; Vector On Right */
    shear = transform.inverse() * vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-18.92, 5.5, -6.6, 0.0), shear); // x = -4.4 - (-2.2 * -6.6) = -18.92; w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, ShearYX)
{
    /*** Shear ***/
    /* Original */
    RayTracer::Transform transform;
    transform.shear(0.0, 0.0, 3.3, 0.0, 0.0, 0.0); // Move Y In Proportion To X
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {3.3, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Shear On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 shear = point * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, -9.02, -6.6, 1.0), shear); // y = 5.5 + (3.3 * -4.4) = -9.02; w == 1.0 For Point3

    /* Shear On Point; Point On Right */
    shear = transform.inverse() * point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, 20.02, -6.6, 1.0), shear); // y = 5.5 - (3.3 * -4.4) = 20.02; w == 1.0 For Point3

    /* Shear On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // w == 0.0 For Vector3
    shear = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, -9.02, -6.6, 0.0), shear); // y = 5.5 + (3.3 * -4.4) = -9.02; w == 0.0 For Vector3

    /* Shear On Vector; Vector On Right */
    shear = transform.inverse() * vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, 20.02, -6.6, 0.0), shear); // y = 5.5 - (3.3 * -4.4) = 20.02; w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, ShearYZ)
{
    /*** Shear ***/
    /* Original */
    RayTracer::Transform transform;
    transform.shear(0.0, 0.0, 0.0, -4.4, 0.0, 0.0); // Move Y In Proportion To Z
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, -4.4, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Shear On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 shear = point * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, 34.54, -6.6, 1.0), shear); // y = 5.5 + (-4.4 * -6.6) = 34.54; w == 1.0 For Point3

    /* Shear On Point; Point On Right */
    shear = transform.inverse() * point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, -23.54, -6.6, 1.0), shear); // y = 5.5 - (-4.4 * -6.6) = -23.54; w == 1.0 For Point3

    /* Shear On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // w == 0.0 For Vector3
    shear = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, 34.54, -6.6, 0.0), shear); // y = 5.5 + (-4.4 * -6.6) = 34.54; w == 0.0 For Vector3

    /* Shear On Vector; Vector On Right */
    shear = transform.inverse() * vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, -23.54, -6.6, 0.0), shear); // y = 5.5 - (-4.4 * -6.6) = -23.54; w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, ShearZX)
{
    /*** Shear ***/
    /* Original */
    RayTracer::Transform transform;
    transform.shear(0.0, 0.0, 0.0, 0.0, 5.5, 0.0); // Move Z In Proportion To X
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {5.5, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Shear On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 shear = point * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, -30.8, 1.0), shear); // z = -6.6 + (5.5 * -4.4) = -30.8; w == 1.0 For Point3

    /* Shear On Point; Point On Right */
    shear = transform.inverse() * point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, 17.6, 1.0), shear); // z = -6.6 - (5.5 * -4.4) = 17.6; w == 1.0 For Point3

    /* Shear On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // w == 0.0 For Vector3
    shear = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, -30.8, 0.0), shear); // z = -6.6 + (5.5 * -4.4) = -30.8; w == 0.0 For Vector3

    /* Shear On Vector; Vector On Right */
    shear = transform.inverse() * vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, 17.6, 0.0), shear); // z = -6.6 - (5.5 * -4.4) = 17.6; w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, ShearZY)
{
    /*** Shear ***/
    /* Original */
    RayTracer::Transform transform;
    transform.shear(0.0, 0.0, 0.0, 0.0, 0.0, -6.6); // Move Z In Proportion To Y
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, -6.6, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Shear On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 shear = point * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, -42.9, 1.0), shear); // z = -6.6 + (-6.6 * 5.5) = -42.9; w == 1.0 For Point3

    /* Shear On Point; Point On Right */
    shear = transform.inverse() * point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, 29.7, 1.0), shear); // z = -6.6 - (-6.6 * 5.5) = 29.7; w == 1.0 For Point3

    /* Shear On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // w == 0.0 For Vector3
    shear = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, -42.9, 0.0), shear); // z = -6.6 + (-6.6 * 5.5) = -42.9; w == 0.0 For Vector3

    /* Shear On Vector; Vector On Right */
    shear = transform.inverse() * vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, 29.7, 0.0), shear); // z = -6.6 - (-6.6 * 5.5) = 29.7; w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}

TEST_F(TransformTest, Translation)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Transform transform;
    transform.translation(1.1, -2.2, 3.3);
    std::array<std::array<double, 4>, 4> data({{1.0, 0.0, 0.0, 1.1}, {0.0, 1.0, 0.0, -2.2}, {0.0, 0.0, 1.0, 3.3}, {0.0, 0.0, 0.0, 1.0}});
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);

    /* Translation On Point; Point On Left */
    RayTracer::Vector4 point(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 translation = point * transform;
    EXPECT_EQ(RayTracer::Vector4(-3.3, 3.3, -3.3, 1.0), translation); // w == 1.0 For Point3

    /* Translation On Point; Point On Right */
    translation = transform.inverse() * point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-5.5, 7.7, -9.9, 1.0), translation); // w == 1.0 For Point3

    /* Translation On Vector; Vector On Left */
    RayTracer::Vector4 vector(-4.4, 5.5, -6.6, 0.0); // w == 0.0 For Vector3
    translation = vector * transform;
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, -6.6, 0.0), translation); // Translation Does Not Change Vector; w == 0.0 For Vector3

    /* Translation On Vector; Vector On Right */
    translation = transform.inverse() * vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector4(-4.4, 5.5, -6.6, 0.0), translation); // Translation Does Not Change Vector; w == 0.0 For Vector3

    /* Not Changed */
    EXPECT_EQ(RayTracer::Transform(RayTracer::Matrix4(data)), transform);
}
