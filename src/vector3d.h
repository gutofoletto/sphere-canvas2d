#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

class Vector3D{
public:
    float x, y, z;

    Vector3D(){
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
    }

    Vector3D(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3D translate(Vector3D v){
        return Vector3D(
            this->x + v.x,
            this->y + v.y,
            this->z + v.z
        );
    }

    Vector3D spinOnX(float angle){
        return Vector3D(
            this->x,
            this->y = (cos(angle)*y) - (sin(angle)*z),
            this->z = (sin(angle)*y) + (cos(angle)*z)
        );
    }

    Vector3D spinOnY(float angle){
        return Vector3D(
            this->x = (cos(angle)*x) - (sin(angle)*z),
            this->y,
            this->z = (sin(angle)*y) + (cos(angle)*z)
        );
    }
};
