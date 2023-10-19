/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <format>
#include <ostream>
#include "RayTracer/Source/Image/Color3.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Material
    {
        public:
            /*** Constructor ***/
            Material();
            Material(const Color3& Intensity, const double Ambient, const double Diffuse, const double Specular, const double Shininess);
            Material(const Material& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Material& M);

            /*** Operator ***/
            bool operator==(const Material& Other) const;
            Material& operator=(const Material& Other); // Assignment Operator

            /*** Variable ***/
            Color3 intensity;
            double ambient, diffuse, specular, shininess;
    };
}
