/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <array>
#include <cmath>
#include "color.h"
#include <limits>
#include "object.h"
#include <ostream>
#include "ray.h"
#include <sstream>
#include "transform.h"
#include "vector4.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    class Sphere : public Object
    {
        private:
            /*** Variable ***/
            Vector4 center;
            Transform transform;

        public:
            /*** Constructor ***/
            Sphere();
            Sphere(const double CX, const double CY, const double CZ, const double CR, const double CG, const double CB);
            Sphere(const Vector4& Center, const Color& C);
            Sphere(const Sphere& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Sphere& S);

            /*** Method ***/
            std::array<double, 2> intersection(const Ray& R) const;
            void setTransform(const Transform& T);

            /*** Operator ***/
            bool operator==(const Sphere& Other) const;
            Sphere& operator=(const Sphere& Other); // Assignment Operator
    };
}
