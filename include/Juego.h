#ifndef JUEGO_H
#define JUEGO_H

#include "Mapa.h"
#include "Allegro.h"
#include "Personaje.h"
#include "Fantasma.h"
class Juego
{
    public:
        Juego(){
            this->FPS=50;
            this->filas=12;
            this->cols=12;
        };

        Juego(float,int,int);
        virtual ~Juego();
        void start();
        void test(){cout << this-> display;};

    protected:
        ALLEGRO_DISPLAY *display;
        int filas;
        int cols;

    private:
        float FPS;
        ALLEGRO_TIMER *timer;
        ALLEGRO_EVENT_QUEUE *event_queue;
        enum MYKEYS {
            KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
        };
        void init();
       // Personaje *pacman = new Personaje;

    friend class Mapa;
};

#endif // JUEGO_H
