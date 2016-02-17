#include "Mapa.h"

void Mapa::dibujarMapa(ALLEGRO_BITMAP *pimage, ALLEGRO_DISPLAY *display){

  al_set_target_bitmap(al_get_backbuffer(display));
  al_clear_to_color(al_map_rgb(10,10,50));

  for(int i=0; i< xfilas; ++i){
        for(int j=0; j<xcols; ++j){
            if (this->mapa[i][j] == 'x'){
                al_draw_bitmap(pimage,j*50,i*50,0);
            }
        }
    }

  //al_flip_display();
  //al_rest(10.0);
  //al_destroy_display(display);

}
void Mapa::dibujarPuntos(ALLEGRO_BITMAP *pimage,ALLEGRO_DISPLAY *display){
    al_set_target_bitmap(al_get_backbuffer(display));
    for(int i=0; i< xfilas; ++i){
        for(int j=0; j<xcols; ++j){
            if (this->mapa[i][j] == ' '){
                al_draw_bitmap(pimage,j*50+25,i*50+25,0);
            }
            if (this->mapa[i][j] == '.'){

            }
        }
    }

}

void Mapa::test(){
    for(int i=0; i< xfilas; ++i){
        for(int j=0; j<xcols; ++j){
            //cout << this->mapa[i][j] << " ";
        }
        //cout << "\n" << endl;
    }
}
Mapa::Mapa(){
    //this->imagec  = al_load_bitmap("bloque3.bmp");
    for (int i=0; i<xfilas; ++i ){
        mapa[i] = new char[xcols];
        strcpy(mapa[i],mapat[i]);
    }
}
Mapa::~Mapa()
{
    //dtor
}
