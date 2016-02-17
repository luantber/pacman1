#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Allegro.h"

class Personaje
{
    public:
        Personaje(char *m[13]){
            this-> pos_x=100;
            this->pos_y = 300;
            mapa = m;
        };
        Personaje(float x ,float y ,char*m[13]){
           this-> pos_x = x;
           this-> pos_y = y;
           this-> mapa = m;
        };

        virtual ~Personaje();

        virtual void comer(int,int);
        void ir(float x, float y);
        virtual void mover_i();
        virtual void mover_d();
        void mover_a();
        void mover_o();

        int* getpos();

        virtual void s_i();
        virtual void s_d();
        virtual void s_a();
        virtual void s_o();

        int x(){return getpos()[1];};
        int y(){return getpos()[0];};

        int ary(){if(this->getpos()[0]-1<0)return this->getpos()[0]; else return this->getpos()[0]-1;};
        int arx() {return this->getpos()[1];};

        int aby(){if(this->getpos()[0]+1>13)return this->getpos()[0]; else return this->getpos()[0]+1;};
        int abx() {return this->getpos()[1];};

        int izy() {return this->getpos()[0];};
        int izx() {if(this->getpos()[1]-1<0)return this->getpos()[1]; else return this->getpos()[1]-1;};

        int dey() {return this->getpos()[0];};
        int dex(){if(this->getpos()[1]+1>13)return this->getpos()[1]; else return this->getpos()[1]+1;};

    protected:
        char **mapa;
        void draw();
    private:
        float pos_x;
        float pos_y;

        ALLEGRO_BITMAP *bitmap = al_load_bitmap("pacman_a.png");

    friend class Juego;
    friend class Fantasma;
};

#endif // PERSONAJE_H
