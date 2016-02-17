#ifndef MAPA_H
#define MAPA_H

#include "Allegro.h"

#define xfilas 13
#define xcols 13

class Mapa
{
    public:
        Mapa();
        virtual ~Mapa();
        void test();
        void star();
        char **mapa = new char*[xfilas];
    protected:

        void dibujarMapa(ALLEGRO_BITMAP*,ALLEGRO_DISPLAY*);
        void dibujarPuntos(ALLEGRO_BITMAP*,ALLEGRO_DISPLAY*);
    private:
        ALLEGRO_BITMAP  *imagec = al_load_bitmap("bloque3.bmp");
        ALLEGRO_BITMAP  *imagep = al_load_bitmap("point.png");
        char mapat[xfilas][xcols+1] = {
        "xxxxxxxxxxxxx",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "             ",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "xxxxxxxxxxxxx"};


    friend class Juego;
};

#endif // MAPA_H
