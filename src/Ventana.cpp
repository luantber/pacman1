#include "Ventana.h"

Ventana::Ventana()
{
    // Crea *display ,*eventero *image * timer

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    ALLEGRO_BITMAP  *pacman   = NULL;
    ALLEGRO_TIMER *timer = NULL;

    //Iniciando Componentes (Imagenes y teclado)
    al_init();
    al_init_image_addon();
    al_install_keyboard();

    //Iniciando Pantalla "display"
    this->display = al_create_display(xxfilas*50,xxcols*50);

    al_clear_to_color(al_map_rgb(0,0,100));
    al_flip_display();

    //al_rest(10.0);

    //al_destroy_display(display);
}

Ventana::~Ventana()
{
    //dtor
}
