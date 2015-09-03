#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "gl_canvas2d.h"
#include "vector3d.h"

class Sphere{
public:
    Vector3D center;
    std::vector<Vector3D> points;
    std::vector<Vector3D> aux;
    float r;
    float d;

    Sphere(){
        this->center = Vector3D(0.0f, 0.0f, 0.0f);
        this->r = 100.0f;
        this->d = 50.0f;
        for(float lon = 0; lon < 2*M_PI; lon+=0.2){
            for(float lat = 0; lat < M_PI; lat+=0.3){
                float z = r*cos(lat);
                float x = sqrt(r*r - z*z) * cos(lon);
                float y = sqrt(r*r - z*z) * sin(lon);
                points.push_back(Vector3D(x, y, z));
                aux.push_back(Vector3D(x, y, z));
            }
        }
    }

    void draw(){
        for(int i = 0; i< aux.size(); i++){
            point(aux[i].x, aux[i].y);

            // if(i == aux.size())
            //     line(aux[i].x, aux[i].y, aux[1].x, aux[1].y);
            // else
            //     line(aux[i].x, aux[i].y, aux[i+1].x, aux[i+1].y);
        }
    }

    void transformSphere(){

        // ajusta a perspectiva da camera
        for(int i = 0; i< aux.size(); i++){
            aux[i].x = aux[i].x*d/aux[i].z;
            aux[i].y = aux[i].y*d/aux[i].z;
        }

        //translada para o meio da tela
        for(int i = 0; i< aux.size(); i++){
            aux[i] = points[i].spinOnX(0.01f);
        }

        //translada para o meio da tela
        for(int i = 0; i< aux.size(); i++){
            aux[i] = points[i].translate(Vector3D(300.0f, 300.0f, 300.f));
        }
    }

};
