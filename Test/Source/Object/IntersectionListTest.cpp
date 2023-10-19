/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "IntersectionListTest.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(IntersectionListTest, Add)
{
    /*** Add ***/
    /* Intersection List */
    RayTracer::IntersectionList intersectionList;
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{3.3, -4.4}}));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22.0, 23.1)), {{0.0, 0.0}}));

    /* Ts Sorted (Element 0) */
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}), intersectionList[0]);

    /* Ts Sorted (Element 1) */
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{-4.4, 3.3}}), intersectionList[1]);

    /* Ts Sorted (Element 2) */
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22.0, 23.1)), {{0.0, 0.0}}), intersectionList[2]);
}

TEST_F(IntersectionListTest, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    RayTracer::IntersectionList il1;
    il1.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}));
    il1.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{3.3, -4.4}}));
    il1.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22.0, 23.1)), {{0.0, 0.0}}));

    /* Assignment Operator */
    RayTracer::IntersectionList il2;
    il2 = il1;
    EXPECT_EQ(il1, il2);
}

TEST_F(IntersectionListTest, ClosestIntersection)
{
    /*** Closest Intersection ***/
    /* Intersection List */
    RayTracer::IntersectionList intersectionList;
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{3.3, -4.4}}));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22.0, 23.1)), {{0.0, 0.0}}));

    /* Closest Intersection */
    RayTracer::Intersection intersection = intersectionList.closestIntersection(-5.0);
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{-4.4, 3.3}}), intersection);

    /* Closest Intersection */
    intersection = intersectionList.closestIntersection(-4.0);
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}), intersection);

    /* Closest Intersection */
    intersection = intersectionList.closestIntersection(-0.1);
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22.0, 23.1)), {{0.0, 0.0}}), intersection);

    /* Closest Intersection */
    intersection = intersectionList.closestIntersection(0.1);
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}), intersection);

    /* Closest Intersection */
    intersection = intersectionList.closestIntersection(3.3);
    EXPECT_EQ(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{-4.4, 3.3}}), intersection);

    /* Closest Intersection (None) */
    intersection = intersectionList.closestIntersection(3.31);
    EXPECT_EQ(RayTracer::Object(), intersection.object);
    EXPECT_EQ(-std::numeric_limits<double>::infinity(), intersection.ts[0]);
    EXPECT_EQ(std::numeric_limits<double>::infinity(), intersection.ts[1]);
}

TEST_F(IntersectionListTest, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    RayTracer::IntersectionList il1;
    il1.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}));
    il1.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{3.3, -4.4}}));
    il1.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22.0, 23.1)), {{0.0, 0.0}}));

    /* Copy Constructor */
    const RayTracer::IntersectionList IL2 = il1;
    EXPECT_EQ(il1, IL2);
}

TEST_F(IntersectionListTest, Print)
{
    /*** Print ***/
    /* Intersection */
    RayTracer::IntersectionList intersectionList;
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), {{-2.2, 1.1}}));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(-8.8, 9.9, -11.0), 12.1, -13.2, 14.3, -15.4)), {{3.3, -4.4}}));
    intersectionList.add(RayTracer::Intersection(RayTracer::Object(RayTracer::Material(RayTracer::Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22.0, 23.1)), {{0.0, 0.0}}));

    /* Print */
    std::stringstream ss;
    ss << intersectionList;
    EXPECT_EQ("IntersectionList(Intersection(Object(Material(Color3(1.1, -2.2, 3.3), -4.4, 5.5, -6.6, 7.7)), Ts(-2.2, 1.1)), Intersection(Object(Material(Color3(-8.8, 9.9, -11), 12.1, -13.2, 14.3, -15.4)), Ts(-4.4, 3.3)), Intersection(Object(Material(Color3(16.5, -17.6, 18.7), -19.8, 20.9, -22, 23.1)), Ts(0, 0)))", ss.str());
}
