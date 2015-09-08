#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "gl_canvas2d.h"
#include "vector3d.h"

using namespace std;

class Sphere{
public:
    Vector3D position; // centroide da esfera
    vector< vector<Vector3D> > points; //pontos da esfera
    vector< vector<Vector3D> > aux; // clone de pontos para transformação
    float r; // raio da esfera
    float d; // distância da para calculo da perspectiva
    int step; // step armazena o nível de detalhamento
    int row; // conta o numero de linhas pra criar os vetores
    float angle; // angulo de rotaç±ao da esfera

    // Construtor da esfera, seta valores para as variaveis
    Sphere(float r, int s){
        this->position = Vector3D(0.0f, 0.0f, 0.0f);
        this->r = r;
        this->d = 50.0f;
        this->step = s;
        this->row = 0;
        this->angle = 0.0f;
        // um for de 360 e outro de 180 para desenhar a esfera
        for(float lon = -M_PI; lon < M_PI; lon+= M_PI/step*2){
            points.push_back(vector<Vector3D>()); // cria uma linha no array
            aux.push_back(vector<Vector3D>());
            for(float lat = -M_PI/2; lat < M_PI/2; lat+= M_PI/step){
                // formula parametrica das coordenadas de uma esfera
                float x = r*cos(lon)*cos(lat);
                float y = r*sin(lat);
                float z = r*sin(lon)*cos(lat);
                //armazena a coordenada no array
                points[row].push_back(Vector3D(x, y, z));
                aux[row].push_back(Vector3D(x, y, z));
            }
            row++;
        }
    }

    void draw(){
        // Loop que percorre as linhas e colunas do array
        // para desenhar as linhas que formam as esfera
        color(0,0,0);
        for(int i = 0; i < aux.size()-1; i++){
            for(int j = 0; j < aux[0].size()-1; j++){
                // desenha linha horizontal
                line(
                    aux[i][j].x,
                    aux[i][j].y,
                    aux[i][j+1].x,
                    aux[i][j+1].y
                );
                // desenha linha vertical
                line(
                    aux[i][j].x,
                    aux[i][j].y,
                    aux[i+1][j].x,
                    aux[i+1][j].y
                );
                // desenha linha diagonal
                line(
                    aux[i][j].x,
                    aux[i][j].y,
                    aux[i+1][j+1].x,
                    aux[i+1][j+1].y
                );
            }
        }
    }

    void transform(Vector3D trans = Vector3D(300.0f, 300.0f, 300.0f), bool axis = true){
        this->position = trans;
        // Loop que percorre as linhas e colunas do array
        // para aplicar transformações nas coordenadas
        for(int i = 0; i < aux.size(); i++){
            for(int j = 0; j < aux[0].size(); j++){
                // copia o elemento para aux
                aux[i][j] = points[i][j];

                // rotaciona no eixo indicado
                if(axis == true)
                    aux[i][j] = aux[i][j].spinOnX(angle);
                else
                    aux[i][j] = aux[i][j].spinOnY(angle);

                // translada o Z para calculo da perspectiva
                // aux[i][j] = aux[i][j].translateZ(200.0f);

                // faz o cálculo da perspectiva
                // aux[i][j].x = aux[i][j].x*d/aux[i][j].z;
                // aux[i][j].y = aux[i][j].y*d/aux[i][j].z;

                //translada para o meio da tela
                aux[i][j] = aux[i][j].translate(trans);
            }
        }
        angle+=0.05;
    }

};
