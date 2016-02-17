#include "Juego.h"
#include <fstream>

void Juego::start(){
    // Iniciando componentes
    this->init();

    bool key[4] = { false, false, false, false };
    bool doexit = false;
    bool redraw = true;

    ///////////////////////////////////////

    int i=0;

    Mapa * m= new Mapa;
    Personaje *pacman = new Personaje(200,100, m->mapa);
    Fantasma *pacman2 = new Fantasma(100,200,m->mapa);
    Fantasma * fantasma3 = new Fantasma(100,100,m->mapa);
    Fantasma * fantasma4 = new Fantasma(300,300,m->mapa);
    Fantasma * fantasma5 = new Fantasma(500,500,m->mapa);
   // Personaje *pacman3 = new Personaje (100,200,m->mapa);



    int iSecret;
    int ite=0;
    ALLEGRO_EVENT ev;

    Cuadro * camino = new Cuadro;
    int ia = 1;
    int j=0;
    int y_c ;
    int x_c ;

    while(1)
   {
        al_wait_for_event(this->event_queue, &ev);
      // Se crea un evento "ev

      //Evento Timer
      if(ev.type == ALLEGRO_EVENT_TIMER) {
        //cout << i << "  :" << 1%10 << endl;
        i++;

        if(ite == 0){
            iSecret = rand() % 4 + 1;
            ite = 30;

       }
        else{
           switch ( iSecret ) {

            case 1:
                pacman2->mover_a();
                //fantasma3->mover_o();
                fantasma4->mover_d();
                fantasma5->mover_i();
                break;
            case 2:
                pacman2->mover_o();
                //fantasma3->mover_a();
                fantasma4->mover_i();
                fantasma5->mover_d();
                break;
            case 3:
              pacman2->mover_i();
              //fantasma3->mover_d();
              fantasma4->mover_o();
              fantasma5->mover_a();
              break;
            case 4:
              pacman2->mover_d();
              //fantasma3->mover_i();
              fantasma4->mover_a();
              fantasma5->mover_o();
              break;
            default:
              //cout << "Oops" <<endl;
              break;
            }
        ite--;
        }

int a[2] = {fantasma3->getpos()[0],fantasma3->getpos()[1]};
int b[2] = {pacman->getpos()[0],pacman->getpos()[1]};

cout <<"Pacman" <<pacman->getpos()[0] << "," << pacman->getpos()[1] << endl;
cout << "Fantasma" << fantasma3->getpos()[0] << "," << fantasma3->getpos()[1] << endl;

* camino = fantasma3->star(b[0],b[1],a[0],a[1]);
while(camino->padre != 0){
    cout << camino->y << camino->x  << ", ";
    fantasma3->ir(camino->x*50,camino->y*50);
    //al_rest(0.5);
    camino = camino->padre;

}

cout << endl;

        //cout << ia << endl;
        if(ia == 0 ){
            int a[2] = {fantasma3->getpos()[0],fantasma3->getpos()[1]};
            int b[2] = {pacman->getpos()[0],pacman->getpos()[1]};
            //cout << endl;
            //cout <<"Pacman" <<pacman->getpos()[0] << "," << pacman->getpos()[1] << endl;
            //cout << "Fantasma" << fantasma3->getpos()[0] << "," << fantasma3->getpos()[1] << endl;

            * camino = fantasma3->star(b[0],b[1],a[0],a[1]);
            cout << camino->y << camino->x << endl;
            camino = camino->padre;
            cout << camino->y << camino->x << endl;

            ia = 20;
            y_c = camino->y;
            x_c = camino->x;
            //cout << "ia" << endl;
        }

        else{

            if (camino->padre != NULL){
                if (j>=10){
                    camino = camino->padre;
                    y_c = camino->y;
                    x_c = camino->x;
                    j=0;
                    //cout << "here" << endl;
                }
                else{
                        //cout << fantasma3->pos_x  << ", " << fantasma3->pos_y << endl;

                        //cout <<"Actual" << fantasma3->getpos()[0] <<"," <<fantasma3->getpos()[1] << endl;
                        cout <<"DEstino " << camino->y <<" ," <<camino->x << endl;

                        cout <<"Test Arriba: " << fantasma3->ary() << ", " << fantasma3->arx() << endl;
                        cout <<"Test Abajo: " << fantasma3->aby() << ", " << fantasma3->abx() << endl;
                        cout <<"Test Derecga: " << fantasma3->dey() << ", " << fantasma3->dex() << endl;
                        cout <<"Test Izquierda: " << fantasma3->izy() << ", " << fantasma3->izx() << endl;


                        cout << ia << endl;
                    if (fantasma3->y() == camino->y and fantasma3->x() == camino->x and ia%10==0){
                        cout << "iguales"<< endl;
                        camino = camino->padre;
                        ia++;
                    }

                    else if ( fantasma3->ary() >= camino->y and fantasma3->arx() == camino->x){
                        cout << "Arriba" << endl;
                        fantasma3->mover_a();
                        //cout << j << endl;
                    }

                    //cout <<"Camino " << camino->y << camino->x << endl;
                    //cout <<"Test Abajo: " << fantasma3->aby() << ", " << fantasma3->abx() << endl;

                    else if ( fantasma3->aby() <= camino->y and fantasma3->abx() == camino->x){
                        cout << "Abajo" << endl;
                        fantasma3->mover_o();
                        //cout << j << endl;
                    }

                     else if ( fantasma3->izy() == camino->y and fantasma3->izx() >= camino->x){
                        fantasma3->mover_i();
                        cout << "Izquierda" << endl;
                        //cout << j << endl;
                    }
                    else if ( fantasma3->dey() == camino->y and fantasma3->dex() <= camino->x){
                        fantasma3->mover_d();
                        cout << "Derecha" << endl;
                        //cout << j << endl;
                    }


                    j++;

                }


        }
        ia--;
        }

        /* */
        //cout << fantasma3->pos_x  << ", " << fantasma3->pos_y << endl;

         if(key[KEY_UP] ) {
            pacman->mover_a();
            //pacman2->mover_a();
         }

         if(key[KEY_DOWN]) {
            pacman->mover_o();
            //pacman2->mover_o();
         }

         if(key[KEY_LEFT] ) {
            pacman->mover_i();
            //pacman2->mover_i();
         }

         if(key[KEY_RIGHT]) {
            pacman->mover_d();
            //pacman2->mover_d();

         }
        redraw = true;
      }

      // Evento: Cierre de Pantalla
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        break;
      }

      else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = true;
               //cout << "Key_Down: " << "Arriba" <<endl;
               break;

            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = true;
               //cout << "Key_Down: " << "Abajo" <<endl;
               break;

            case ALLEGRO_KEY_LEFT:
               key[KEY_LEFT] = true;
               //cout << "Key_Down: " << "Left" <<endl;
               break;

            case ALLEGRO_KEY_RIGHT:
               key[KEY_RIGHT] = true;
               //cout << "Key_Down: " << "Right" <<endl;
               break;
         }
      }

      else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = false;
               //cout << "Key_Up: " << "Arriba" <<endl;
               break;

            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = false;
               //cout << "Key_Up: " << "Abajo" <<endl;
               break;

            case ALLEGRO_KEY_LEFT:
               key[KEY_LEFT] = false;
               //cout << "Key_Up: " << "Left" <<endl;
               break;

            case ALLEGRO_KEY_RIGHT:
               key[KEY_RIGHT] = false;
               //cout << "Key_Up: " << "Right" <<endl;
               break;

            case ALLEGRO_KEY_ESCAPE:
              //cout << "Key_Up: " << "Escape" <<endl;
              doexit = true;
               break;
         }
      }
      if (doexit == true) break;
      if (redraw && al_is_event_queue_empty(this->event_queue)) {

        m->dibujarMapa(m->imagec,this->display);
        m->dibujarPuntos(m->imagep,this->display);

        pacman->draw();
        //cout << pacman->pos_x << pacman->pos_y << endl;
        //pacman->ir(625,315);
        pacman2->draw();

        fantasma3->draw();
        fantasma4->draw();
        fantasma5->draw();

        //pacman3->draw();

        redraw = false;
        al_flip_display();
      }


     }
}

/////////////

void Juego::init(){
    //Iniciando Componentes (Imagenes y teclado)
    al_init();
    al_init_image_addon();
    al_install_keyboard();


    //Iniciando Pantalla "display"
    display = al_create_display(this->filas*50,this->cols*50);

    //Creando Timer y Eventero
    this->timer = al_create_timer(1.0/ this->FPS);
    this->event_queue = al_create_event_queue();

    //Registradores de eventos
    al_register_event_source(this->event_queue, al_get_display_event_source(this->display));
    al_register_event_source(this->event_queue, al_get_keyboard_event_source());
    al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));

    al_flip_display();
    al_start_timer(this->timer);
}
Juego::Juego(float fps, int f, int c)
{
    this->FPS=fps;
    this->filas=c;
    this->cols=c;
}

Juego::~Juego()
{
    //dtor
}
