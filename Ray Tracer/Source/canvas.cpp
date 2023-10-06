/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "canvas.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    Canvas::Canvas()
        : width {0}, height {0}
    {
    }

    Canvas::Canvas(const int Width, const int Height)
        : width {Width}, height {Height}, canvas(Height, std::vector<Color>(Width, Color()))
    {
    }

    Canvas::Canvas(const Canvas& Other)
        : width {Other.width}, height {Other.height}, canvas {Other.canvas}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Canvas& C)
    {
        std::string string;
        if(C.canvas.empty())
        {
            string = "{}";
        }
        else
        {
            string = "{";
            for(const std::vector<Color>& row : C.canvas)
            {
                string += "{";
                for(const Color& C : row)
                    string += C.toString() + ", ";
                string += "\b\b}, ";
            }
            string += "\b\b}";
        }
        return os << std::format("Canvas({}, {}, {})", C.width, C.height, string);
    }

    /*** Method (Private) ***/
    int Canvas::convert(const double Value) const
    {
        return std::clamp(static_cast<int>(std::round(255 * Value)), 0, 255);
    }

    /*** Method (Public) ***/
    std::string Canvas::getPpmString() const
    {
        std::string ppm;
        ppm += "P3\n";
        ppm += std::format("{} {}\n", width, height);
        ppm += "255\n";
        for(int row = 0; row < height; row++)
        {
            for(int column = 0; column < width; column++)
            {
                const Color& C = canvas[row][column];
                ppm += std::format("{} {} {}\n", convert(C.r), convert(C.g), convert(C.b));
            }
        }
        return ppm;
    }

    /*** Operator ***/
    std::vector<Color>& Canvas::operator[](const int Row)
    {
        return canvas[Row];
    }

    bool Canvas::operator==(const Canvas& Other) const
    {
        return (width == Other.width) &&
               (height == Other.height) &&
               (canvas == Other.canvas);
    }

    Canvas& Canvas::operator=(const Canvas& Other)
    {
        width = Other.width;
        height = Other.height;
        canvas = Other.canvas;
        return *this;
    }
}
