/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <cmath>
#include "color.h"
#include "material.h"
#include <ostream>
#include <sstream>
#include "vector4.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class PointLight
    {
        public:
            /*** Constructor ***/
            PointLight();
            PointLight(const double IR, const double IG, const double IB, const double PX, const double PY, const double PZ);
            PointLight(const Color& Intensity, const Vector4& Position);
            PointLight(const PointLight& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const PointLight& PL);

            /*** Method ***/
            Color getLighting(const Material& M, const Vector4& MaterialPoint, const Vector4& EyeVector, const Vector4& MaterialNormal);

            /*** Operator ***/
            bool operator==(const PointLight& Other) const;
            PointLight& operator=(const PointLight& Other); // Assignment Operator

            /*** Variable ***/
            Color intensity;
            Vector4 position;
    };
}
