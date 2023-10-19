/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "PointLightTest.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(PointLightTest, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::PointLight PL1(RayTracer::Color3(1.1, -2.2, 3.3), RayTracer::Point3(-4.4, 5.5, -6.6));

    /* Assignment Operator */
    RayTracer::PointLight pl2;
    pl2 = PL1;
    EXPECT_EQ(PL1, pl2);
}

TEST_F(PointLightTest, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::PointLight PL1(RayTracer::Color3(1.1, -2.2, 3.3), RayTracer::Point3(-4.4, 5.5, -6.6));

    /* Copy Constructor */
    const RayTracer::PointLight PL2 = PL1;
    EXPECT_EQ(PL1, PL2);
}

TEST_F(PointLightTest, GetLighting)
{
    /*** Get Light ***/
    /* Original */
    const RayTracer::Material M(RayTracer::Color3(1.0, 1.0, 1.0), 0.1, 0.9, 0.9, 200.0);
    const RayTracer::Point3 MaterialPosition(0.0, 0.0, 0.0);
    const RayTracer::Vector3 MaterialNormal(0.0, 0.0, -1.0);

    /* Get Lighting */
    RayTracer::PointLight pointLight(RayTracer::Color3(1.0, 1.0, 1.0), RayTracer::Point3(0.0, 0.0, -10.0));
    RayTracer::Vector3 eyeVector(0.0, 0.0, -1.0);
    EXPECT_EQ(RayTracer::Color3(1.9, 1.9, 1.9), pointLight.getLighting(M, MaterialPosition, eyeVector, MaterialNormal));

    /* Get Lighting */
    pointLight = RayTracer::PointLight(RayTracer::Color3(1.0, 1.0, 1.0), RayTracer::Point3(0.0, 0.0, -10.0));
    eyeVector = RayTracer::Vector3(0.0, 0.707107, 0.707107);
    EXPECT_EQ(RayTracer::Color3(1.0, 1.0, 1.0), pointLight.getLighting(M, MaterialPosition, eyeVector, MaterialNormal));

    /* Get Lighting */
    pointLight = RayTracer::PointLight(RayTracer::Color3(1.0, 1.0, 1.0), RayTracer::Point3(0.0, 10.0, -10.0));
    eyeVector = RayTracer::Vector3(0.0, 0.0, -1.0);
    EXPECT_EQ(RayTracer::Color3(0.736396, 0.736396, 0.736396), pointLight.getLighting(M, MaterialPosition, eyeVector, MaterialNormal));

    /* Get Lighting */
    pointLight = RayTracer::PointLight(RayTracer::Color3(1.0, 1.0, 1.0), RayTracer::Point3(0.0, 10.0, -10.0));
    eyeVector = RayTracer::Vector3(0.0, -0.707107, -0.707107);
    EXPECT_EQ(RayTracer::Color3(1.636452, 1.636452, 1.636452), pointLight.getLighting(M, MaterialPosition, eyeVector, MaterialNormal));
}

TEST_F(PointLightTest, Print)
{
    /*** Print ***/
    /* Point Light */
    const RayTracer::PointLight PL(RayTracer::Color3(1.1, -2.2, 3.3), RayTracer::Point3(-4.4, 5.5, -6.6));

    /* Print */
    std::stringstream ss;
    ss << PL;
    EXPECT_EQ("PointLight(Color3(1.1, -2.2, 3.3), Point3(-4.4, 5.5, -6.6))", ss.str());
}
