/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "point_light_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(PointLightTest, Copy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Color color(1.1, -2.2, 3.3);
    RayTracer::Vector4 position(-4.4, 5.5, -6.6, 1.0); // w == 1.0 For Point3
    RayTracer::PointLight pl1(color, position);

    /* Assignment Operator */
    RayTracer::PointLight pl2;
    pl2 = pl1;
    EXPECT_EQ(pl1, pl2);

    /* Copy Constructor */
    RayTracer::PointLight pl3 = pl1;
    EXPECT_EQ(pl1, pl3);
}

TEST_F(PointLightTest, GetLighting)
{
    /*** Get Light ***/
    /* Original */
    RayTracer::Material material(RayTracer::Color(1.0, 1.0, 1.0), 0.1, 0.9, 0.9, 200.0);
    RayTracer::Vector4 materialPosition(0.0, 0.0, 0.0, 1.0); // w == 1.0 For Point3
    RayTracer::Vector4 materialNormal(0.0, 0.0, -1.0, 0.0); // w == 0.0 For Vector3

    /* Get Lighting */
    RayTracer::PointLight pointLight(RayTracer::Color(1.0, 1.0, 1.0), RayTracer::Vector4(0.0, 0.0, -10.0, 1.0));
    RayTracer::Vector4 eyeVector(0.0, 0.0, -1.0, 0.0);
    EXPECT_EQ(RayTracer::Color(1.9, 1.9, 1.9), pointLight.getLighting(material, materialPosition, eyeVector, materialNormal));
    pointLight = RayTracer::PointLight(RayTracer::Color(1.0, 1.0, 1.0), RayTracer::Vector4(0.0, 0.0, -10.0, 1.0));
    eyeVector = RayTracer::Vector4(0.0, 0.707107, 0.707107, 0.0);
    EXPECT_EQ(RayTracer::Color(1.0, 1.0, 1.0), pointLight.getLighting(material, materialPosition, eyeVector, materialNormal));
    pointLight = RayTracer::PointLight(RayTracer::Color(1.0, 1.0, 1.0), RayTracer::Vector4(0.0, 10.0, -10.0, 1.0));
    eyeVector = RayTracer::Vector4(0.0, 0.0, -1.0, 0.0);
    EXPECT_EQ(RayTracer::Color(0.736396, 0.736396, 0.736396), pointLight.getLighting(material, materialPosition, eyeVector, materialNormal));
    pointLight = RayTracer::PointLight(RayTracer::Color(1.0, 1.0, 1.0), RayTracer::Vector4(0.0, 10.0, -10.0, 1.0));
    eyeVector = RayTracer::Vector4(0.0, -0.707107, -0.707107, 0.0);
    EXPECT_EQ(RayTracer::Color(1.636452, 1.636452, 1.636452), pointLight.getLighting(material, materialPosition, eyeVector, materialNormal));
}
