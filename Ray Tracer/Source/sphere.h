/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <array>
#include "color.h"
#include <limits>
#include "material.h"
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
            Transform transform;
            Material material;

        public:
            /*** Constructor ***/
            Sphere();
            Sphere(const double R, const double G, const double B, const Material& M);
            Sphere(const Color& C, const Material& M);
            Sphere(const Sphere& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Sphere& S);

            /*** Method ***/
            std::array<double, 2> intersection(const Ray& R) const;
            Vector4 normalAt(const Vector4& WorldPoint) const;
            void setTransform(const Transform& T);

            /*** Operator ***/
            bool operator==(const Sphere& Other) const;
            Sphere& operator=(const Sphere& Other); // Assignment Operator
    };
}
