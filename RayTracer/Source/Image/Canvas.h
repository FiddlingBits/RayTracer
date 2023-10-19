/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <algorithm>
#include <format>
#include <iostream>
#include "RayTracer/Source/Image/Color3.h"
#include "RayTracer/Source/Vector/Point2.h"
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
            double displayPortWidth, displayPortHeight;
            std::vector<std::vector<Color3>> canvas;

        public:
            /*** Constructor ***/
            Canvas();
            Canvas(const int Width, const int Height);
            Canvas(const Canvas& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Canvas& C);

            /*** Method ***/
            Point2 getDisplayPortPoint(const int CanvasX, const int CanvasY);
            std::string ppmString() const; // Portable Pixmap Format

            /*** Operator ***/
            std::vector<Color3>& operator[](const int Row);
            bool operator==(const Canvas& Other) const;
            Canvas& operator=(const Canvas& Other); // Assignment Operator

            /*** Variable ***/
            int width, height;
    };
}
