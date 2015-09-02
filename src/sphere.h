#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "vetor3d.h"

class Sphere{
public:
    Vector3D center;
    std::vector<Vetor3D> points;
    float radius;

    Sphere(){
        this->center = Vector3D(0.0f, 0.0f, 0.0f);
        this->radius = 50.0f;
    }

    Sphere(Vector3D v,float radius){
        this->center = Vector3D(v.x, v.y, v.z);
        this->radius = radius;
    }
};
