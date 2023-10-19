/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "MaterialTest.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(MaterialTest, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Material M1(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7);

    /* Assignment Operator */
    RayTracer::Material m2;
    m2 = M1;
    EXPECT_EQ(M1, m2);
}

TEST_F(MaterialTest, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Material M1(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7);

    /* Copy Constructor */
    const RayTracer::Material M2 = M1;
    EXPECT_EQ(M1, M2);
}

TEST_F(MaterialTest, Print)
{
    /*** Print ***/
    /* Material */
    const RayTracer::Material Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7);

    /* Print */
    std::stringstream ss;
    ss << Material;
    EXPECT_EQ("Material(Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)", ss.str());
}
