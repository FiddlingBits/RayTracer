/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <cmath>
#include <numbers>
#include <ostream>
#include "RayTracer/Source/Matrix/Matrix4.h"
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

    class Transform4 : public Matrix4
    {
        public:
            /*** Constructor ***/
            Transform4();
            Transform4(const Matrix4& Matrix);

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Transform4& Transform);

            /*** Method ***/
            void rotateX(const double Degrees);
            void rotateY(const double Degrees);
            void rotateZ(const double Degrees);
            void scale(const double X, const double Y, const double Z);
            void shear(const double XY, const double XZ, const double YX, const double YZ, const double ZX, const double ZY);
            void translation(const double X, const double Y, const double Z);
    };
}
