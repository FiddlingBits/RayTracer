/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Canvas.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Canvas::Canvas()
        : width {0}, height {0}, displayPortWidth {}, displayPortHeight {}, canvas {}
    {
    }

    Canvas::Canvas(const int Width, const int Height)
        : width {Width}, height {Height}, displayPortWidth {2.0}, displayPortHeight {2.0 * Height / Width}, canvas(Height, std::vector<Color3>(Width, Color3()))
    {
    }

    Canvas::Canvas(const Canvas& Other)
        : width {Other.width}, height {Other.height}, displayPortWidth {Other.displayPortWidth}, displayPortHeight {Other.displayPortHeight}, canvas {Other.canvas}
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
            for(const std::vector<Color3>& Row : C.canvas)
            {
                string += "{";
                for(const Color3& Color : Row)
                    string += Color.toString() + ", ";
                string.replace(string.size() - 2, 2, "}, "); // Replace Final ", " With "), "
            }
            string.replace(string.size() - 2, 2, "}"); // Replace Final ", " With "}"
        }
        return os << std::format("Canvas({}, {}, {}, {}, {})", C.width, C.height, C.displayPortWidth, C.displayPortHeight, string);
    }

    /*** Method (Private) ***/
    int Canvas::convert(const double Value) const
    {
        return std::clamp(static_cast<int>(std::round(255 * Value)), 0, 255);
    }

    /*** Method (Public) ***/
    Point2 Canvas::getDisplayPortPoint(const int CanvasX, const int CanvasY)
    {
        double x = -(displayPortWidth / 2.0) + (displayPortWidth * CanvasX / (width - 1));
        double y = (displayPortHeight / 2.0) - (displayPortHeight * CanvasY / (height - 1));
        return Point2(x, y);
    }

    std::string Canvas::ppmString() const
    {
        std::string ppm;
        ppm += "P3\n";
        ppm += std::format("{} {}\n", width, height);
        ppm += "255\n";
        for(int row = 0; row < height; row++)
        {
            for(int column = 0; column < width; column++)
            {
                const Color3& Color = canvas[row][column];
                ppm += std::format("{} {} {}\n", convert(Color.r), convert(Color.g), convert(Color.b));
            }
        }
        return ppm;
    }

    /*** Operator ***/
    std::vector<Color3>& Canvas::operator[](const int Row)
    {
        return canvas[Row];
    }

    bool Canvas::operator==(const Canvas& Other) const
    {
        const double Delta {0.000001};
        return (width == Other.width) &&
               (height == Other.height) &&
               (std::abs(displayPortWidth - Other.displayPortWidth) <= Delta) &&
               (std::abs(displayPortHeight - Other.displayPortHeight) <= Delta) &&
               (canvas == Other.canvas);
    }

    Canvas& Canvas::operator=(const Canvas& Other)
    {
        width = Other.width;
        height = Other.height;
        displayPortWidth = Other.displayPortWidth;
        displayPortHeight = Other.displayPortHeight;
        canvas = Other.canvas;
        return *this;
    }
}
