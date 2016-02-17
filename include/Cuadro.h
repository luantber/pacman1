#ifndef CUADRO_H
#define CUADRO_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Cuadro
{
    public:
        int y;
        int x;
        int peso;
        Cuadro * padre;

        Cuadro();
        Cuadro(int y,int x){
            this->y = y;
            this->x = x;
            this->padre = NULL;
        }

        int distancia(int,int);
        bool operator <(Cuadro*);
        bool operator ==(Cuadro*);

        int ary(){if(y-1<0)return y; else return y-1;};
        int arx() {return x;};

        int aby(){if(y+1>13)return y; else return y+1;};
        int abx() {return x;};

        int izy() {return y;};
        int izx() {if(x-1<0)return x; else return x-1;};

        int dey() {return x;};
        int dex(){if(x+1>13)return x; else return x+1;};

        virtual ~Cuadro();


    protected:
    private:
};

#endif // CUADRO_H
