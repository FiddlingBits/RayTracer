/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "Transform4Test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(Transform4Test, AssignmentOperator)
{
    /*** Assignment Operator ***/
    /* Original */
    const RayTracer::Transform4 Original(RayTracer::Matrix4({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}}));

    /* Assignment Operator */
    RayTracer::Transform4 copy;
    copy = Original;
    EXPECT_EQ(Original, copy);
}

TEST_F(Transform4Test, CopyConstructor)
{
    /*** Copy Constructor ***/
    /* Original */
    const RayTracer::Transform4 Original(RayTracer::Matrix4({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}}));

    /* Copy Constructor */
    const RayTracer::Transform4 Copy = Original;
    EXPECT_EQ(Original, Copy);
}

TEST_F(Transform4Test, Point3RotateX)
{
    /*** Rotate X ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.rotateX(45.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 0.707107, -0.707107, 0.0}, {0.0, 0.707107, 0.707107, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Rotate X (Point On Left) */
    const RayTracer::Point3 Point(0.0, 1.0, 0.0);
    RayTracer::Point3 rotate = Point * transform;
    EXPECT_EQ(RayTracer::Point3(0.0, 0.707107, 0.707107), rotate);

    /* Rotate X (Point On Right) */
    rotate = transform.inverse() * Point; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Point3(0.0, 0.707107, -0.707107), rotate);
}

TEST_F(Transform4Test, Point3RotateY)
{
    /*** Rotate Y ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.rotateY(45.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{0.707107, 0.0, 0.707107, 0.0}, {0.0, 1.0, 0.0, 0.0}, {-0.707107, 0.0, 0.707107, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Rotate Y (Point On Left) */
    const RayTracer::Point3 Point(0.0, 0.0, 1.0);
    RayTracer::Point3 rotate = Point * transform;
    EXPECT_EQ(RayTracer::Point3(0.707107, 0.0, 0.707107), rotate);

    /* Rotate Y (Point On Right) */
    rotate = transform.inverse() * Point; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Point3(-0.707107, 0.0, 0.707107), rotate);
}

TEST_F(Transform4Test, Point3RotateZ)
{
    /*** Rotate Z ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.rotateZ(45.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{0.707107, -0.707107, 0.0, 0.0}, {0.707107, 0.707107, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Rotate Z (Point On Left) */
    const RayTracer::Point3 Point(1.0, 0.0, 0.0);
    RayTracer::Point3 rotate = Point * transform;
    EXPECT_EQ(RayTracer::Point3(0.707107, 0.707107, 0.0), rotate);

    /* Rotate Z (Point On Right) */
    rotate = transform.inverse() * Point; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Point3(0.707107, -0.707107, 0.0), rotate);
}

TEST_F(Transform4Test, Point3Scale)
{
    /*** Scale ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.scale(1.1, -2.2, 3.3);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.1, 0.0, 0.0, 0.0}, {0.0, -2.2, 0.0, 0.0}, {0.0, 0.0, 3.3, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Scale (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 scale = Point * transform;
    EXPECT_EQ(RayTracer::Point3(-4.84, -12.1, -21.78), scale);

    /* Scale (Point On Right) */
    scale = transform.inverse() * Point; // Inverse Of Multiplication Is Division
    EXPECT_EQ(RayTracer::Point3(-4.0, -2.5, -2.0), scale);
}

TEST_F(Transform4Test, Point3SeveralTransformationsInSequence)
{
    /*** Several Transformations (In Sequence) ***/
    /* Transform (Rotation) */
    RayTracer::Transform4 transformRotation;
    transformRotation.rotateX(90);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformRotation);

    /* Transform (Scale) */
    RayTracer::Transform4 transformScale;
    transformScale.scale(5.0, 5.0, 5.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformScale);

    /* Transform (Translation) */
    RayTracer::Transform4 transformTranslation;
    transformTranslation.translation(10.0, 5.0, 7.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}}})), transformTranslation);

    /* Point Rotation */
    RayTracer::Point3 point(1.0, 0.0, 1.0);
    point = transformRotation * point;
    EXPECT_EQ(RayTracer::Point3(1.0, -1.0, 0.0), point);

    /* Point Scale */
    point = transformScale * point;
    EXPECT_EQ(RayTracer::Point3(5.0, -5.0, 0.0), point);

    /* Point Translation */
    point = transformTranslation * point;
    EXPECT_EQ(RayTracer::Point3(15.0, 0.0, 7.0), point);
}

TEST_F(Transform4Test, Point3SeveralTransformationsChained)
{
    /*** Several Transformations (Chained) ***/
    /* Transform (Rotation) */
    RayTracer::Transform4 transformRotation;
    transformRotation.rotateX(90);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformRotation);

    /* Transform (Scale) */
    RayTracer::Transform4 transformScale;
    transformScale.scale(5.0, 5.0, 5.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformScale);

    /* Transform (Translation) */
    RayTracer::Transform4 transformTranslation;
    transformTranslation.translation(10.0, 5.0, 7.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}}})), transformTranslation);

    /* Transform (Chained) */
    const RayTracer::Transform4 TransformChained = transformTranslation * transformScale * transformRotation; // Applied In Reverse Order Of Desired Order
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{5.0, 0.0, 0.0, 10.0}, {0.0, 0.0, -5.0, 5.0}, {0.0, 5.0, 0.0, 7.0}, {0.0, 0.0, 0.0, 1.0}}})), TransformChained);

    /* Point Rotation, Scale, And Translation Chained */
    RayTracer::Point3 point(1.0, 0.0, 1.0);
    point = TransformChained * point;
    EXPECT_EQ(RayTracer::Point3(15.0, 0.0, 7.0), point);
}

TEST_F(Transform4Test, Point3ShearXY)
{
    /*** Shear (XY) ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(1.1, 0.0, 0.0, 0.0, 0.0, 0.0); // Move X In Proportion To Y
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 1.1, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 shear = Point * transform;
    EXPECT_EQ(RayTracer::Point3(1.65, 5.5, -6.6), shear); // x = -4.4 + (1.1 * 5.5) = 1.65

    /* Shear (Point On Right) */
    shear = transform.inverse() * Point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Point3(-10.45, 5.5, -6.6), shear); // x = -4.4 - (1.1 * 5.5) = -10.45
}

TEST_F(Transform4Test, Point3ShearXZ)
{
    /*** Shear (XZ) ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, -2.2, 0.0, 0.0, 0.0, 0.0); // Move X In Proportion To Z
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, -2.2, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 shear = Point * transform;
    EXPECT_EQ(RayTracer::Point3(10.12, 5.5, -6.6), shear); // x = -4.4 + (-2.2 * -6.6) = 10.12

    /* Shear (Point On Right) */
    shear = transform.inverse() * Point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Point3(-18.92, 5.5, -6.6), shear); // x = -4.4 - (-2.2 * -6.6) = -18.92
}

TEST_F(Transform4Test, Point3ShearYX)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 3.3, 0.0, 0.0, 0.0); // Move Y In Proportion To X
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {3.3, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 shear = Point * transform;
    EXPECT_EQ(RayTracer::Point3(-4.4, -9.02, -6.6), shear); // y = 5.5 + (3.3 * -4.4) = -9.02

    /* Shear (Point On Right) */
    shear = transform.inverse() * Point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Point3(-4.4, 20.02, -6.6), shear); // y = 5.5 - (3.3 * -4.4) = 20.02
}

TEST_F(Transform4Test, Point3ShearYZ)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 0.0, -4.4, 0.0, 0.0); // Move Y In Proportion To Z
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, -4.4, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 shear = Point * transform;
    EXPECT_EQ(RayTracer::Point3(-4.4, 34.54, -6.6), shear); // y = 5.5 + (-4.4 * -6.6) = 34.54

    /* Shear (Point On Right) */
    shear = transform.inverse() * Point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Point3(-4.4, -23.54, -6.6), shear); // y = 5.5 - (-4.4 * -6.6) = -23.54
}

TEST_F(Transform4Test, Point3ShearZX)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 0.0, 0.0, 5.5, 0.0); // Move Z In Proportion To X
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {5.5, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 shear = Point * transform;
    EXPECT_EQ(RayTracer::Point3(-4.4, 5.5, -30.8), shear); // z = -6.6 + (5.5 * -4.4) = -30.8

    /* Shear (Point On Right) */
    shear = transform.inverse() * Point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Point3(-4.4, 5.5, 17.6), shear); // z = -6.6 - (5.5 * -4.4) = 17.6
}

TEST_F(Transform4Test, Point3ShearZY)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 0.0, 0.0, 0.0, -6.6); // Move Z In Proportion To Y
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, -6.6, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 shear = Point * transform;
    EXPECT_EQ(RayTracer::Point3(-4.4, 5.5, -42.9), shear); // z = -6.6 + (-6.6 * 5.5) = -42.9

    /* Shear (Point On Right) */
    shear = transform.inverse() * Point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Point3(-4.4, 5.5, 29.7), shear); // z = -6.6 - (-6.6 * 5.5) = 29.7
}

TEST_F(Transform4Test, Point3Translation)
{
    /*** Translation ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.translation(1.1, -2.2, 3.3);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 1.1}, {0.0, 1.0, 0.0, -2.2}, {0.0, 0.0, 1.0, 3.3}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Translation (Point On Left) */
    const RayTracer::Point3 Point(-4.4, 5.5, -6.6);
    RayTracer::Point3 translation = Point * transform;
    EXPECT_EQ(RayTracer::Point3(-3.3, 3.3, -3.3), translation);

    /* Translation (Point On Right) */
    translation = transform.inverse() * Point; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Point3(-5.5, 7.7, -9.9), translation);
}

TEST_F(Transform4Test, Print)
{
    /*** Print ***/
    /* Transform */
    const RayTracer::Transform4 Transform(RayTracer::Matrix4({{{1.1, 7.7, -13.2, -2.2}, {-8.8, 14.3, 3.3, 9.9}, {-15.4, -4.4, -11.0, 16.5}, {5.5, 12.1, -17.6, -6.6}}}));

    /* Print */
    std::stringstream ss;
    ss << Transform;
    EXPECT_EQ("Transform4((1.1, 7.7, -13.2, -2.2), (-8.8, 14.3, 3.3, 9.9), (-15.4, -4.4, -11, 16.5), (5.5, 12.1, -17.6, -6.6))", ss.str());
}

TEST_F(Transform4Test, Ray3Scale)
{
    /*** Scale ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.scale(1.1, -2.2, 3.3);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.1, 0.0, 0.0, 0.0}, {0.0, -2.2, 0.0, 0.0}, {0.0, 0.0, 3.3, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Scale (Ray On Left) */
    const RayTracer::Ray3 Ray(RayTracer::Point3(-4.4, 5.5, -6.6), RayTracer::Vector3(7.7, -8.8, 9.9));
    RayTracer::Ray3 scale = Ray * transform;
    EXPECT_EQ(RayTracer::Ray3(RayTracer::Point3(-4.84, -12.1, -21.78), RayTracer::Vector3(8.47, 19.36, 32.67)), scale); // Origin Changed, Direction Changed

    /* Scale (Ray On Right) */
    scale = transform.inverse() * Ray; // Inverse Of Multiplication Is Division
    EXPECT_EQ(RayTracer::Ray3(RayTracer::Point3(-4.0, -2.5, -2.0), RayTracer::Vector3(7.0, 4.0, 3.0)), scale); // Origin Changed, Direction Changed
}

TEST_F(Transform4Test, Ray3Translation)
{
    /*** Translation ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.translation(1.1, -2.2, 3.3);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 1.1}, {0.0, 1.0, 0.0, -2.2}, {0.0, 0.0, 1.0, 3.3}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Translation (Ray On Left) */
    const RayTracer::Ray3 Ray(RayTracer::Point3(-4.4, 5.5, -6.6), RayTracer::Vector3(7.7, -8.8, 9.9));
    RayTracer::Ray3 translation = Ray * transform;
    EXPECT_EQ(RayTracer::Ray3(RayTracer::Point3(-3.3, 3.3, -3.3), RayTracer::Vector3(7.7, -8.8, 9.9)), translation); // Origin Changed, Direction Unchanged

    /* Translation (Point On Right) */
    translation = transform.inverse() * Ray; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Ray3(RayTracer::Point3(-5.5, 7.7, -9.9), RayTracer::Vector3(7.7, -8.8, 9.9)), translation); // Origin Changed, Direction Unchanged
}

TEST_F(Transform4Test, Vector3RotateX)
{
    /*** Rotate X ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.rotateX(45.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 0.707107, -0.707107, 0.0}, {0.0, 0.707107, 0.707107, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Rotate X (Vector On Left) */
    const RayTracer::Vector3 Vector(0.0, 1.0, 0.0);
    RayTracer::Vector3 rotate = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(0.0, 0.707107, 0.707107), rotate);

    /* Rotate X (Vector On Right) */
    rotate = transform.inverse() * Vector; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector3(0.0, 0.707107, -0.707107), rotate);
}

TEST_F(Transform4Test, Vector3RotateY)
{
    /*** Rotate Y ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.rotateY(45.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{0.707107, 0.0, 0.707107, 0.0}, {0.0, 1.0, 0.0, 0.0}, {-0.707107, 0.0, 0.707107, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Rotate Y (Vector On Left) */
    const RayTracer::Vector3 Vector(0.0, 0.0, 1.0);
    RayTracer::Vector3 rotate = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(0.707107, 0.0, 0.707107), rotate);

    /* Rotate Y (Vector On Right) */
    rotate = transform.inverse() * Vector; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector3(-0.707107, 0.0, 0.707107), rotate);
}

TEST_F(Transform4Test, Vector3RotateZ)
{
    /*** Rotate Z ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.rotateZ(45.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{0.707107, -0.707107, 0.0, 0.0}, {0.707107, 0.707107, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Rotate Z (Vector On Left) */
    RayTracer::Vector3 Vector(1.0, 0.0, 0.0);
    RayTracer::Vector3 rotate = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(0.707107, 0.707107, 0.0), rotate);

    /* Rotate Z (Vector On Right) */
    rotate = transform.inverse() * Vector; // Inverse Rotates In Opposite Direction
    EXPECT_EQ(RayTracer::Vector3(0.707107, -0.707107, 0.0), rotate);
}

TEST_F(Transform4Test, Vector3Scale)
{
    /*** Scale ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.scale(1.1, -2.2, 3.3);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.1, 0.0, 0.0, 0.0}, {0.0, -2.2, 0.0, 0.0}, {0.0, 0.0, 3.3, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Scale (Vector On Left) */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 scale = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(-4.84, -12.1, -21.78), scale);

    /* Scale (Vector On Right) */
    scale = transform.inverse() * Vector; // Inverse Of Multiplication Is Division
    EXPECT_EQ(RayTracer::Vector3(-4.0, -2.5, -2.0), scale);
}

TEST_F(Transform4Test, Vector3SeveralTransformationsInSequence)
{
    /*** Several Transformations (In Sequence) ***/
    /* Transform (Rotation) */
    RayTracer::Transform4 transformRotation;
    transformRotation.rotateX(90);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformRotation);

    /* Transform (Scale) */
    RayTracer::Transform4 transformScale;
    transformScale.scale(5.0, 5.0, 5.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformScale);

    /* Transform (Translation) */
    RayTracer::Transform4 transformTranslation;
    transformTranslation.translation(10.0, 5.0, 7.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}}})), transformTranslation);

    /* Vector Rotation */
    RayTracer::Vector3 vector(1.0, 0.0, 1.0);
    vector = transformRotation * vector;
    EXPECT_EQ(RayTracer::Vector3(1.0, -1.0, 0.0), vector);

    /* Vector Scale */
    vector = transformScale * vector;
    EXPECT_EQ(RayTracer::Vector3(5.0, -5.0, 0.0), vector);

    /* Vector Translation */
    vector = transformTranslation * vector;
    EXPECT_EQ(RayTracer::Vector3(5.0, -5.0, 0.0), vector); // Translation On Vector Does Nothing
}

TEST_F(Transform4Test, Vector3SeveralTransformationsChained)
{
    /*** Several Transformations (Chained) ***/
    /* Transform (Rotation) */
    RayTracer::Transform4 transformRotation;
    transformRotation.rotateX(90);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -1.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformRotation);

    /* Transform (Scale) */
    RayTracer::Transform4 transformScale;
    transformScale.scale(5.0, 5.0, 5.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{5.0, 0.0, 0.0, 0.0}, {0.0, 5.0, 0.0, 0.0}, {0.0, 0.0, 5.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transformScale);

    /* Transform (Translation) */
    RayTracer::Transform4 transformTranslation;
    transformTranslation.translation(10.0, 5.0, 7.0);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 10.0}, {0.0, 1.0, 0.0, 5.0}, {0.0, 0.0, 1.0, 7.0}, {0.0, 0.0, 0.0, 1.0}}})), transformTranslation);

    /* Transform (Chained) */
    const RayTracer::Transform4 TransformChained = transformTranslation * transformScale * transformRotation; // Applied In Reverse Order Of Desired Order
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{5.0, 0.0, 0.0, 10.0}, {0.0, 0.0, -5.0, 5.0}, {0.0, 5.0, 0.0, 7.0}, {0.0, 0.0, 0.0, 1.0}}})), TransformChained);

    /* Vector Rotation, Scale, And Translation Chained */
    RayTracer::Vector3 vector(1.0, 0.0, 1.0);
    vector = TransformChained * vector;
    EXPECT_EQ(RayTracer::Vector3(5.0, -5.0, 0.0), vector); // Translation On Vector Does Nothing
}

TEST_F(Transform4Test, Vector3ShearXY)
{
    /*** Shear (XY) ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(1.1, 0.0, 0.0, 0.0, 0.0, 0.0); // Move X In Proportion To Y
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 1.1, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Vector On Left) */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 shear = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(1.65, 5.5, -6.6), shear); // x = -4.4 + (1.1 * 5.5) = 1.65

    /* Shear (Vector On Right) */
    shear = transform.inverse() * Vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector3(-10.45, 5.5, -6.6), shear); // x = -4.4 - (1.1 * 5.5) = -10.45
}

TEST_F(Transform4Test, Vector3ShearXZ)
{
    /*** Shear (XZ) ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, -2.2, 0.0, 0.0, 0.0, 0.0); // Move X In Proportion To Z
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, -2.2, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Vector On Left) */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 shear = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(10.12, 5.5, -6.6), shear); // x = -4.4 + (-2.2 * -6.6) = 10.12

    /* Shear (Vector On Right) */
    shear = transform.inverse() * Vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector3(-18.92, 5.5, -6.6), shear); // x = -4.4 - (-2.2 * -6.6) = -18.92
}

TEST_F(Transform4Test, Vector3ShearYX)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 3.3, 0.0, 0.0, 0.0); // Move Y In Proportion To X
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {3.3, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Vector On Left) */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 shear = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(-4.4, -9.02, -6.6), shear); // y = 5.5 + (3.3 * -4.4) = -9.02

    /* Shear (Vector On Right) */
    shear = transform.inverse() * Vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector3(-4.4, 20.02, -6.6), shear); // y = 5.5 - (3.3 * -4.4) = 20.02
}

TEST_F(Transform4Test, Vector3ShearYZ)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 0.0, -4.4, 0.0, 0.0); // Move Y In Proportion To Z
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, -4.4, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Vector On Left) */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 shear = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(-4.4, 34.54, -6.6), shear); // y = 5.5 + (-4.4 * -6.6) = 34.54

    /* Shear (Vector On Right) */
    shear = transform.inverse() * Vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector3(-4.4, -23.54, -6.6), shear); // y = 5.5 - (-4.4 * -6.6) = -23.54
}

TEST_F(Transform4Test, Vector3ShearZX)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 0.0, 0.0, 5.5, 0.0); // Move Z In Proportion To X
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {5.5, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Vector On Left) */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 shear = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(-4.4, 5.5, -30.8), shear); // z = -6.6 + (5.5 * -4.4) = -30.8

    /* Shear (Vector On Right) */
    shear = transform.inverse() * Vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector3(-4.4, 5.5, 17.6), shear); // z = -6.6 - (5.5 * -4.4) = 17.6
}

TEST_F(Transform4Test, Vector3ShearZY)
{
    /*** Shear ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.shear(0.0, 0.0, 0.0, 0.0, 0.0, -6.6); // Move Z In Proportion To Y
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, -6.6, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Shear (Vector On Left) */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 shear = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(-4.4, 5.5, -42.9), shear); // z = -6.6 + (-6.6 * 5.5) = -42.9

    /* Shear (Vector On Right) */
    shear = transform.inverse() * Vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector3(-4.4, 5.5, 29.7), shear); // z = -6.6 - (-6.6 * 5.5) = 29.7
}

TEST_F(Transform4Test, Vector3Translation)
{
    /*** Translation ***/
    /* Transform */
    RayTracer::Transform4 transform;
    transform.translation(1.1, -2.2, 3.3);
    EXPECT_EQ(RayTracer::Transform4(RayTracer::Matrix4({{{1.0, 0.0, 0.0, 1.1}, {0.0, 1.0, 0.0, -2.2}, {0.0, 0.0, 1.0, 3.3}, {0.0, 0.0, 0.0, 1.0}}})), transform);

    /* Translation On Vector; Vector On Left */
    const RayTracer::Vector3 Vector(-4.4, 5.5, -6.6);
    RayTracer::Vector3 translation = Vector * transform;
    EXPECT_EQ(RayTracer::Vector3(-4.4, 5.5, -6.6), translation); // Translation On Vector Does Nothing

    /* Translation On Vector; Vector On Right */
    translation = transform.inverse() * Vector; // Inverse Of Addition Is Subtraction
    EXPECT_EQ(RayTracer::Vector3(-4.4, 5.5, -6.6), translation); // Translation On Vector Does Nothing
}
