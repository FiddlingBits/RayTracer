/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "color.h"
#include <ostream>
#include <sstream>

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
            Material(const Color& C, const double Ambient, const double Diffuse, const double Specular, const double Shininess);
            Material(const Material& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Material& M);

            /*** Operator ***/
            bool operator==(const Material& Other) const;
            Material& operator=(const Material& Other); // Assignment Operator

            /*** Variable ***/
            Color color;
            double ambient, diffuse, specular, shininess;
    };
}
