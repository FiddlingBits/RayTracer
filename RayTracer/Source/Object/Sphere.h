/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <array>
#include <limits>
#include <ostream>
#include "RayTracer/Source/Matrix/Transform4.h"
#include "RayTracer/Source/Object/Material.h"
#include "RayTracer/Source/Object/Object.h"
#include "RayTracer/Source/Vector/Point3.h"
#include "RayTracer/Source/Vector/Ray3.h"
#include "RayTracer/Source/Vector/Vector3.h"

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
            Transform4 transform;

        public:
            /*** Constructor ***/
            Sphere();
            Sphere(const Material& M);
            Sphere(const Sphere& Other); // Copy Constructor

            /*** Friend ***/
            friend std::ostream& operator<<(std::ostream& os, const Sphere& S);

            /*** Method ***/
            std::array<double, 2> intersection(const Ray3& R) const;
            Vector3 normalAt(const Point3& WorldPoint) const;
            void setTransform(const Transform4& Transform);

            /*** Operator ***/
            bool operator==(const Sphere& Other) const;
            Sphere& operator=(const Sphere& Other); // Assignment Operator
    };
}
