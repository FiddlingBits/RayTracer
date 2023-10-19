/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <array>
#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include "RayTracer/Source/Image/Canvas.h"
#include "RayTracer/Source/Image/Color3.h"
#include "RayTracer/Source/Matrix/Transform4.h"
#include "RayTracer/Source/Object/Material.h"
#include "RayTracer/Source/Object/PointLight.h"
#include "RayTracer/Source/Object/Sphere.h"
#include "RayTracer/Source/Vector/Point2.h"
#include "RayTracer/Source/Vector/Point3.h"
#include <sstream>
#include <stdlib.h>

/******************************************************************************************************
 * Function
 ******************************************************************************************************/

int main()
{
    /*** Set Up ***/
    /* Camera */
    double cameraDistance = 1.0; // Distance From Origin To Display Port
    RayTracer::Point3 cameraOrigin(0.0, 0.0, 0.0);
    int cameraFrames = 1;

    /* Canvas */
    RayTracer::Canvas canvas(1920, 1080);

    /* Light */
    RayTracer::PointLight pointLight(RayTracer::Color3(1.0, 1.0, 1.0), RayTracer::Point3(-10.0, 10.0, -10.0));

    /* Sphere */
    RayTracer::Sphere sphere(RayTracer::Material(RayTracer::Color3(1.0, 0.0, 0.0), 0.1, 0.9, 0.9, 200.0));
    RayTracer::Transform4 transform;
    transform.translation(0.0, 0.0, 2.0);
    sphere.setTransform(transform);

    /*** Render **/
    for(int i = 0; i < cameraFrames; i++)
    {
        std::cout << std::format("Image: {}/{}", i + 1, cameraFrames) << std::endl;
        for(int y = 0; y < canvas.height; y++)
        {
            for(int x = 0; x < canvas.width; x++)
            {
                /* Get Intersection */
                RayTracer::Point2 displayPortPoint = canvas.getDisplayPortPoint(x, y);
                RayTracer::Ray3 ray(cameraOrigin, RayTracer::Vector3(displayPortPoint.x, displayPortPoint.y, cameraDistance).normalize());
                std::array<double, 2> intersection = sphere.intersection(ray);
                double t = -std::numeric_limits<double>::infinity();
                if(intersection[0] > (cameraOrigin.z + cameraDistance))
                    t = intersection[0];
                else if(intersection[1] > (cameraOrigin.z + cameraDistance))
                    t = intersection[1];

                /* Handle Intersection */
                if(t != -std::numeric_limits<double>::infinity())
                {
                    RayTracer::Point3 point = ray.position(t);
                    RayTracer::Vector3 normal = sphere.normalAt(point);
                    RayTracer::Vector3 eye = -ray.direction;
                    canvas[y][x] = pointLight.getLighting(sphere.material, point, eye, normal);
                }
                else
                {
                    canvas[y][x] = RayTracer::Color3(0.0, 0.0, 0.0); // Black
                }
            }
        }

        /* Write Image */
        std::stringstream fileName;
        fileName << "output/image" << std::setw(4) << std::setfill('0') << i << ".ppm";
        std::ofstream file;
        file.open(fileName.str());
        file << canvas.ppmString();
        file.close();

        /* Update */
        pointLight.position.z += 0.1;
    }

    /*** Create MP4 ***/
    std::cout << "Create MP4: ffmpeg -framerate 24 -i output/image%04d.ppm -c:v libx264 -crf 25 -vf \"scale = 640:480, format = yuv420p\" -movflags +faststart image.mp4" << std::endl;
}
