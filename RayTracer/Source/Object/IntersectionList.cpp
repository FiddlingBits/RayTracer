/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "IntersectionList.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    IntersectionList::IntersectionList()
        : list {}
    {
    }

    IntersectionList::IntersectionList(const IntersectionList& Other)
        : list {Other.list}
    {
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const IntersectionList& IL)
    {
        std::string string{"IntersectionList("};
        for(const Intersection& I : IL.list)
            string += I.toString() + ", ";
        string.replace(string.size() - 2, 2, ")"); // Replace Final ", " With ")"
        return os << string;
    }

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
        Intersection intersection = I;
        std::sort(intersection.ts.begin(), intersection.ts.end());
        list.push_back(intersection);
    }

    Intersection RayTracer::IntersectionList::closestIntersection(const double MinimumT)
    {
        sort(0); // Sort list In Ascending Order By ts[0]; ts[0] <= ts[1]
        for(const Intersection& I : list)
        {
            if(I.ts[0] >= MinimumT)
                return I;
        }
        sort(1); // Sort list In Ascending Order By ts[1]; ts[1] >= ts[0]
        for(const Intersection& I : list)
        {
            if(I.ts[1] >= MinimumT)
                return I;
        }
        return Intersection(Object(), {{-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}});
    }

    /*** Operator ***/
    Intersection& IntersectionList::operator[](const int Index)
    {
        return list[Index];
    }

    bool RayTracer::IntersectionList::operator==(const IntersectionList& Other) const
    {
        return (list == Other.list);
    }

    IntersectionList& RayTracer::IntersectionList::operator=(const IntersectionList& Other)
    {
        list = Other.list;
        return *this;
    }
}
