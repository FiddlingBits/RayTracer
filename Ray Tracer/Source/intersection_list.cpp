/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "intersection_list.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Method (Private) ***/
    void IntersectionList::sort(const int Index)
    {
        std::function<bool(const Intersection& Left, const Intersection& Right)> lambda;
        switch(Index)
        {
        case 0:
            lambda = [](const Intersection& Left, const Intersection& Right)
            {
                return Left.ts[0] < Right.ts[0];
            };
            break;
        case 1:
            lambda = [](const Intersection& Left, const Intersection& Right)
            {
                return Left.ts[1] < Right.ts[1];
            };
            break;
        }
        std::sort(list.begin(), list.end(), lambda);
    }

    /*** Method (Public) ***/
    void IntersectionList::add(const Intersection& I)
    {
        list.push_back(I);
    }

    bool IntersectionList::hit(const double MinimumT, Intersection& intersection)
    {
        intersection = Intersection(); // Default
        sort(0); // Sort list In Ascending Order By ts[0]; ts[0] <= ts[1]
        for(const Intersection& I : list)
        {
            if(I.ts[0] >= MinimumT)
            {
                intersection = I;
                return true;
            }
        }
        sort(1); // Sort list In Ascending Order By ts[1]; ts[1] >= ts[0]
        for(const Intersection& I : list)
        {
            if(I.ts[1] >= MinimumT)
            {
                intersection = I;
                return true;
            }
        }
        return false;
    }

    /*** Operator ***/
    Intersection& IntersectionList::operator[](const int Index)
    {
        return list[Index];
    }
}
