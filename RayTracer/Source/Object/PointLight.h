/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <cmath>
#include <ostream>
#include "RayTracer/Source/Image/Color3.h"
#include "RayTracer/Source/Object/Material.h"
#include "RayTracer/Source/Vector/Point3.h"
#include "RayTracer/Source/Vector/Vector3.h"

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
            PointLight(const Color3& Color, const Point3& Position);
            PointLight(const PointLight& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const PointLight& PL);

            /*** Method ***/
            Color3 getLighting(const Material& M, const Point3& MaterialPoint, const Vector3& EyeVector, const Vector3& MaterialNormal);

            /*** Operator ***/
            bool operator==(const PointLight& Other) const;
            PointLight& operator=(const PointLight& Other); // Assignment Operator

            /*** Variable ***/
            Color3 color;
            Point3 position;
    };
}
