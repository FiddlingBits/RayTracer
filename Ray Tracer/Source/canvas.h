/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <algorithm>
#include "color.h"
#include <format>
#include <ostream>
#include <string>
#include <vector>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Canvas
    {
        private:
            /*** Method ***/
            int convert(const double Value) const;

            /*** Variable ***/
            std::vector<std::vector<Color>> canvas;

        public:
            /*** Constructor ***/
            Canvas();
            Canvas(const int Width, const int Height);
            Canvas(const Canvas& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Canvas& C);

            /*** Method ***/
            std::string getPpmString() const; // Portable Pixmap Format

            /*** Operator ***/
            std::vector<Color>& operator[](const int Row);
            bool operator==(const Canvas& Other) const;
            Canvas& operator=(const Canvas& Other); // Assignment Operator

            /*** Variable ***/
            int width, height;
    };
}
