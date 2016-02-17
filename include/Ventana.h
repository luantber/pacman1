#ifndef VENTANA_H
#define VENTANA_H

#include "Allegro.h"

#define xxfilas 13
#define xxcols 13

class Ventana
{
    public:
        ALLEGRO_DISPLAY *display;
        Ventana();
        virtual ~Ventana();

    protected:
    private:
};

#endif // VENTANA_H
