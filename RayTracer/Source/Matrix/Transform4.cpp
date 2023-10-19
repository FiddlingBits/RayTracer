/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Transform4.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace RayTracer
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** Constructor ***/
    Transform4::Transform4()
    {
        data = Matrix4::identityMatrix().data;
    }

    Transform4::Transform4(const Matrix4& Matrix)
    {
        data = Matrix.data;
    }

    /*** Friend ***/
    std::ostream& operator<<(std::ostream& os, const Transform4& Transform)
    {
        std::stringstream ss;
        ss << Matrix4(Transform);
        return os << ss.str().replace(0, std::strlen("Matrix4"), "Transform4");
    }

    /*** Method ***/
    void Transform4::rotateX(const double Degrees)
    {
        const double Radians = Degrees * (std::numbers::pi / 180.0);
        data[1][1] = std::cos(Radians);
        data[1][2] = -std::sin(Radians);
        data[2][1] = std::sin(Radians);
        data[2][2] = std::cos(Radians);
    }

    void Transform4::rotateY(const double Degrees)
    {
        const double Radians = Degrees * (std::numbers::pi / 180.0);
        data[0][0] = std::cos(Radians);
        data[0][2] = std::sin(Radians);
        data[2][0] = -std::sin(Radians);
        data[2][2] = std::cos(Radians);
    }

    void Transform4::rotateZ(const double Degrees)
    {
        const double Radians = Degrees * (std::numbers::pi / 180.0);
        data[0][0] = std::cos(Radians);
        data[0][1] = -std::sin(Radians);
        data[1][0] = std::sin(Radians);
        data[1][1] = std::cos(Radians);
    }

    void Transform4::scale(const double X, const double Y, const double Z)
    {
        data[0][0] = X;
        data[1][1] = Y;
        data[2][2] = Z;
    }

    void Transform4::shear(const double XY, const double XZ, const double YX, const double YZ, const double ZX, const double ZY)
    {
        data[0][1] = XY; // Move X In Proportion To Y
        data[0][2] = XZ; // Move X In Proportion To Z
        data[1][0] = YX; // Move Y In Proportion To X
        data[1][2] = YZ; // Move Y In Proportion To Z
        data[2][0] = ZX; // Move Z In Proportion To X
        data[2][1] = ZY; // Move Z In Proportion To Y
    }

    void Transform4::translation(const double X, const double Y, const double Z)
    {
        data[0][3] = X;
        data[1][3] = Y;
        data[2][3] = Z;
    }
}
