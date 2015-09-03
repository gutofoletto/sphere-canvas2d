#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "sphere.h"

const int w = 800;
const int h = 600;

Sphere *bola = NULL;

int main(void) {
    initCanvas(w, h);

    bola = new Sphere();

    runCanvas();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
    bola->transformSphere();
    bola->draw();
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
    switch(key) {
        case 27:
            //esc
            exit(0);
            break;
        case 32:
            //spacebar
            break;
        case 200:
            //left
            break;
        case 201:
            //up
            break;
        case 202:
            //right
            break;
        case 203:
            //down
            break;
    }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key) {
    switch(key) {
        case 32:
            //spacebar
            break;
        case 200:
            //left
            break;
        case 201:
            //up
            break;
        case 202:
            //right
            break;
        case 203:
            //down
            break;
    }
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y) {
    //printf("\nmouse %d %d %d %d", button, state, x, y);
}
