/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <cmath>
#include <format>
#include "matrix4.h"
#include <numbers>
#include <ostream>
#include <sstream>
#include <string>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Transform : public Matrix4
    {
        public:
            /*** Constructor ***/
            Transform();
            Transform(const Matrix4& Matrix);

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Transform& T);

            /*** Method ***/
            void rotateX(const double Degrees);
            void rotateY(const double Degrees);
            void rotateZ(const double Degrees);
            void scale(const double X, const double Y, const double Z);
            void shear(const double XY, const double XZ, const double YX, const double YZ, const double ZX, const double ZY);
            void translation(const double X, const double Y, const double Z);
    };
}
