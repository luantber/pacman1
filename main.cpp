#include <iostream>
#include "Fantasma.h"
#include "Juego.h"
using namespace std;
char mapa[14][14] = {
        "xxxxxxxxxxxxx",
        "x    x      x",
        "x    x      x",
        "x    x  x   x",
        "x           x",
        "x   xxxxx    ",
        "   xx        ",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "xxxxxxxxxxxxx"};
int main()
{

    Mapa * m= new Mapa;
    Fantasma f(15,15,m->mapa);
    Cuadro  camino;
    camino = f.star(8,3,2,2);

    while(camino.padre != 0){
        cout << camino.x << camino.y << endl;
        camino = *(camino.padre);
    }


    cout << "Iniciando componentes: ";
    Juego * j = new Juego(40,13,13);
    cout << "Listo" << endl;
    j -> start();
    cout << "Fin" << endl;


    return 0;
}
