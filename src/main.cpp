/**
*** 3D Sphere on Cavas2D
*** Antônio Augusto Foletto
*** Programação de Jogos 3D
***
*** Funcionalidades Implementadas:
*** - Opção para definir o nível de detalhe (fatias) da esfera
*** - Uso de produto vetorial para cálculo de ângulos. Ex: Um canhão que
*** dispara contra a nave. O canhão pode ficar parado em um local do jogo.
*** - Animação da esfera
**/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "sphere.h"

const int w = 800;
const int h = 600;

Sphere *globe = NULL;
Sphere *globe2 = NULL;
Sphere *globe3 = NULL;

int main(void) {
    initCanvas(w, h);

    // inicializa a esfera
    // Sphere(float, int)
    // float raio: define o tamanho da esfera
    // int steps: define o nivel de detalhamento
    globe = new Sphere(100.0f, 42);
    globe2 = new Sphere(50.0f, 20);
    globe3 = new Sphere(50.0f, 10);

    runCanvas();
}

// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
// globais que podem ser setadas pelo metodo keyboard()
void render()
{
    // aplica as transformações na esfera
    // transform(Vector3D, bool)
    // Vector3D indica a posicão para transladar
    // bool: true indica rotação no eixo X, false no Y
    globe->transform(Vector3D(400.0f, 300.0f, 0.0f), true);
    globe2->transform(Vector3D(200.0f, 150.0f, 0.0f), false);
    globe3->transform(Vector3D(600.0f, 450.0f, 0.0f), false);
    // desenha a esfera
    globe->draw();
    globe2->draw();
    globe3->draw();
}

// funcao chamada toda vez que uma tecla for pressionada
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

// funcao chamada toda vez que uma tecla for liberada
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

// funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y) {
    // printf("\nmouse %d %d %d %d", button, state, x, y);
}
