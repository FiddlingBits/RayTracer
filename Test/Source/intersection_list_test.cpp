/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "intersection_list_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(IntersectionListTest, Add)
{
    /*** Add ***/
    /* Add */
    RayTracer::IntersectionList intersectionList;
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(1.1, -2.2, 3.3)), std::array<double, 2>({-2.2, 1.1})));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(-4.4, 5.5, -6.6)), std::array<double, 2>({3.3, -4.4})));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(7.7, -8.8, 9.9)), std::array<double, 2>({0.0, 0.0})));

    /* std::array<double, 2> Sorted */
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(1.1, -2.2, 3.3)), std::array<double, 2>({-2.2, 1.1})), intersectionList.list[0]);
    EXPECT_EQ(-2.2, intersectionList.list[0].ts[0]);
    EXPECT_EQ(1.1, intersectionList.list[0].ts[1]);
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(-4.4, 5.5, -6.6)), std::array<double, 2>({-4.4, 3.3})), intersectionList.list[1]);
    EXPECT_EQ(-4.4, intersectionList.list[1].ts[0]);
    EXPECT_EQ(3.3, intersectionList.list[1].ts[1]);
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(7.7, -8.8, 9.9)), std::array<double, 2>({0.0, 0.0})), intersectionList.list[2]);
    EXPECT_EQ(0.0, intersectionList.list[2].ts[0]);
    EXPECT_EQ(0.0, intersectionList.list[2].ts[1]);
}

TEST_F(IntersectionListTest, Hit)
{
    /*** Hit ***/
    /* Add */
    RayTracer::IntersectionList intersectionList;
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(1.1, -2.2, 3.3)), std::array<double, 2>({-2.2, 1.1})));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(-4.4, 5.5, -6.6)), std::array<double, 2>({3.3, -4.4})));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(7.7, -8.8, 9.9)), std::array<double, 2>({0.0, 0.0})));

    /* Hit */
    RayTracer::Intersection intersection;
    EXPECT_TRUE(intersectionList.hit(-5.0, intersection));
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(-4.4, 5.5, -6.6)), std::array<double, 2>({-4.4, 3.3})), intersection);
    EXPECT_TRUE(intersectionList.hit(-4.0, intersection));
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(1.1, -2.2, 3.3)), std::array<double, 2>({-2.2, 1.1})), intersection);
    EXPECT_TRUE(intersectionList.hit(-0.1, intersection));
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(7.7, -8.8, 9.9)), std::array<double, 2>({0.0, 0.0})), intersection);
    EXPECT_TRUE(intersectionList.hit(0.1, intersection));
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(1.1, -2.2, 3.3)), std::array<double, 2>({-2.2, 1.1})), intersection);
    EXPECT_TRUE(intersectionList.hit(3.3, intersection));
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(-4.4, 5.5, -6.6)), std::array<double, 2>({-4.4, 3.3})), intersection);
    EXPECT_FALSE(intersectionList.hit(3.31, intersection));
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Color(0.0, 0.0, 0.0)), std::array<double, 2>()), intersection); // Hit Nothing
}
