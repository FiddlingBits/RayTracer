/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "CanvasTest.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(CanvasTest, AssignmentOperator)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Canvas C1(5, 3);

    /* Assignment Operator */
    RayTracer::Canvas c2;
    c2 = C1;
    EXPECT_EQ(C1, c2);
}

TEST_F(CanvasTest, CopyConstructor)
{
    /*** Copy ***/
    /* Original */
    const RayTracer::Canvas C1(5, 3);

    /* Copy Constructor */
    const RayTracer::Canvas C2 = C1;
    EXPECT_EQ(C1, C2);
}

TEST_F(CanvasTest, GetDisplayPortPoin)
{
    /*** To Display Port ***/
    /* Canvas */
    RayTracer::Canvas canvas(5, 3);

    /* To Display Port */
    const std::vector<std::vector<RayTracer::Point2>> ExpectedDisplayPortPoint =
    {
        {RayTracer::Point2(-1.0, 0.6), RayTracer::Point2(-0.5, 0.6), RayTracer::Point2(0.0, 0.6), RayTracer::Point2(0.5, 0.6), RayTracer::Point2(1.0, 0.6)},
        {RayTracer::Point2(-1.0, 0.0), RayTracer::Point2(-0.5, 0.0), RayTracer::Point2(0.0, 0.0), RayTracer::Point2(0.5, 0.0), RayTracer::Point2(1.0, 0.0)},
        {RayTracer::Point2(-1.0, -0.6), RayTracer::Point2(-0.5, -0.6), RayTracer::Point2(0.0, -0.6), RayTracer::Point2(0.5, -0.6), RayTracer::Point2(1.0, -0.6)}
    };
    for(int row = 0; row < canvas.height; row++)
    {
        for(int column = 0; column < canvas.width; column++)
            EXPECT_EQ(ExpectedDisplayPortPoint[row][column], canvas.getDisplayPortPoint(column, row));
    }
}

TEST_F(CanvasTest, PpmString)
{
    /*** PPM String ***/
    /* Canvas */
    RayTracer::Canvas canvas(3, 3);

    /* Set */
    canvas[0][0] = RayTracer::Color3(-0.001, 0.0, 0.001); // Converted To (0, 0, 0)
    canvas[1][1] = RayTracer::Color3(0.5, 0.5, 0.5); // Converted To (128, 128, 128)
    canvas[2][2] = RayTracer::Color3(0.999, 1.0, 1.001); // Converted To (255, 255, 255)

    /* PPM String */
    const std::string ExpectedPpmString = "P3\n3 3\n255\n0 0 0\n0 0 0\n0 0 0\n0 0 0\n128 128 128\n0 0 0\n0 0 0\n0 0 0\n255 255 255\n";
    const std::string ActualPpmString = canvas.ppmString();
    EXPECT_EQ(ExpectedPpmString, ActualPpmString);
}

TEST_F(CanvasTest, Print)
{
    /*** Print ***/
    /* Canvas */
    const RayTracer::Canvas C(4, 3);

    /* Print */
    std::stringstream ss;
    ss << C;
    EXPECT_EQ("Canvas(4, 3, 2, 1.5, {{Color3(0, 0, 0), Color3(0, 0, 0), Color3(0, 0, 0), Color3(0, 0, 0)}, {Color3(0, 0, 0), Color3(0, 0, 0), Color3(0, 0, 0), Color3(0, 0, 0)}, {Color3(0, 0, 0), Color3(0, 0, 0), Color3(0, 0, 0), Color3(0, 0, 0)}})", ss.str());
}

TEST_F(CanvasTest, SetGet)
{
    /*** Set/Get ***/
    /* Canvas */
    RayTracer::Canvas canvas(5, 3);

    /* Set/Get */
    const int Row = 1;
    const int Column = 3;
    RayTracer::Color3 color(1.1, -2.2, 3.3);
    canvas[Row][Column] = color;
    for(int row = 0; row < canvas.height; row++)
    {
        for(int column = 0; column < canvas.width; column++)
        {
            if((row == Row) && (column == Column))
                EXPECT_EQ(color, canvas[row][column]); // Changed
            else
                EXPECT_EQ(RayTracer::Color3(), canvas[row][column]); // Not Changed (Default)
        }
    }
}
