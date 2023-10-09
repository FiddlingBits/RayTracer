/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "canvas_test.h"

/****************************************************************************************************
 * Test
 ****************************************************************************************************/

TEST_F(CanvasTest, Copy)
{
    /*** Copy ***/
    /* Original */
    RayTracer::Canvas c1(5, 3);

    /* Assignment Operator */
    RayTracer::Canvas c2;
    c2 = c1;
    EXPECT_EQ(c1, c2);

    /* Copy Constructor */
    RayTracer::Canvas c3 = c1;
    EXPECT_EQ(c1, c3);
}

TEST_F(CanvasTest, PpmString)
{
    /*** PPM String ***/
    /* Original */
    RayTracer::Canvas c(3, 3);

    /* Set */
    c[0][0] = RayTracer::Color(-0.001, 0.0, 0.001); // Converted To (0, 0, 0)
    c[1][1] = RayTracer::Color(0.5, 0.5, 0.5); // Converted To (128, 128, 128)
    c[2][2] = RayTracer::Color(0.999, 1.0, 1.001); // Converted To (255, 255, 255)

    /* PPM String */
    const std::string ExpectedPpmString = "P3\n3 3\n255\n0 0 0\n0 0 0\n0 0 0\n0 0 0\n128 128 128\n0 0 0\n0 0 0\n0 0 0\n255 255 255\n";
    const std::string ActualPpmString = c.ppmString();
    EXPECT_EQ(ExpectedPpmString, ActualPpmString);
}

TEST_F(CanvasTest, SetGet)
{
    /*** Set/Get ***/
    /* Original */
    RayTracer::Canvas canvas(5, 3);

    /* Set/Get */
    const int Row = 1;
    const int Column = 3;
    RayTracer::Color color(1.1, -2.2, 3.3);
    canvas[Row][Column] = color;
    for(int row = 0; row < canvas.height; row++)
    {
        for(int column = 0; column < canvas.width; column++)
        {
            if((row == Row) && (column == Column))
                EXPECT_EQ(color, canvas[row][column]); // Changed
            else
                EXPECT_EQ(RayTracer::Color(), canvas[row][column]); // Not Changed (Default)
        }
    }
}
