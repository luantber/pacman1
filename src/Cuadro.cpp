#include "Cuadro.h"

Cuadro::Cuadro()
{
    //ctor
}

int Cuadro::distancia(int y, int x){
    return abs(this->y - y) + abs(this->x - x);
}

bool Cuadro:: operator <(Cuadro * otro){
    return (this->peso < otro->peso);
}

bool Cuadro::operator ==(Cuadro* otro){
    //cout << this->y << "vs"<< otro->y << " and " << this->x << "vs"<< otro->x <<endl;
    return (this->y == otro->y) and (this->x == otro->x);
};



Cuadro::~Cuadro()
{
    //dtor
}
