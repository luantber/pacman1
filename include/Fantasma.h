#ifndef FANTASMA_H
#define FANTASMA_H
#include "Allegro.h"
#include <Personaje.h>
#include <vector>

class Fantasma : public Personaje
{
    public:
        Fantasma(float x, float y, char*m[13]) : Personaje(x,y,m){};
       /* Fantasma(float x, float y){
            this->pos_x = x;
            this->pos_y = y;
        }; */

        void comer(int ,int){
            //cout << "none" << endl;
        };
        virtual ~Fantasma();
        //ALLEGRO_BITMAP  *bitmap = al_load_bitmap("fantasma.png");

        void s_i(){
            al_destroy_bitmap(this->bitmap);
            this->bitmap = al_load_bitmap("fantasma.png");};
        void s_d(){
            al_destroy_bitmap(this->bitmap);
            this->bitmap = al_load_bitmap("fantasma.png");};
        void s_a(){
            al_destroy_bitmap(this->bitmap);
            this->bitmap = al_load_bitmap("fantasma.png");};
        void s_o(){
            al_destroy_bitmap(this->bitmap);
            this->bitmap = al_load_bitmap("fantasma.png");};



        Cuadro star(int,int,int,int);
    protected:
    private:
};

#endif // FANTASMA_H
