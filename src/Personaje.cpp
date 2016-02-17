#include "Personaje.h"


void Personaje::draw(){
    al_draw_bitmap(this->bitmap, this->pos_x, this->pos_y, 0);
}

void Personaje::ir(float x, float y){
    this->pos_x = x;
    this->pos_y = y;
    this->draw();
    s_a();
}

void Personaje::comer(int x, int y){
    //cout << "come" << x << "_" <<y << endl;
    this->mapa[x][y] = '.';
}

void Personaje::s_a(){
    al_destroy_bitmap(this->bitmap);
    this->bitmap = al_load_bitmap("pacman_a.png");
}
void Personaje::s_o(){
    al_destroy_bitmap(this->bitmap);
this->bitmap = al_load_bitmap("pacman_o.png");
}

void Personaje::s_i(){
    al_destroy_bitmap(this->bitmap);
this->bitmap = al_load_bitmap("pacman_i.png");
}

void Personaje::s_d(){
    al_destroy_bitmap(this->bitmap);
    this->bitmap = al_load_bitmap("pacman_d.png");
}

void Personaje::mover_a(){
    this->s_a();

    int * nyf = new int;
    int * nxc = new int;
    int * n2xc = new int;

    *nyf = (this->pos_y - 5)/50;
    *nxc = (this->pos_x + 8)/50;
    *n2xc = (this->pos_x + 40)/50;

    if ((this->mapa[*nyf][*nxc] == ' ' or this->mapa[*nyf][*nxc] == '.')  and (this->mapa[*nyf][*n2xc] == ' ' or this->mapa[*nyf][*n2xc] == '.')){
        this->pos_y -= 5.0;

        if((int(pos_x)%50+20) >= 15 and (int(pos_x)%50+20) <= 30){
            this->comer(int(pos_y/50),int(pos_x/50));
        }

    }

    delete nyf;
    delete nxc;
    delete n2xc;

}

void Personaje::mover_d(){
    this->s_d();

    int * nxc = new int;
    int * nyf = new int;
    int * n2yf = new int;

    *nxc = (this->pos_x + 45)/50;
    *nyf = (this->pos_y)/50;
    *n2yf = (this->pos_y+42)/50;

    //cout << "Derecha" <<nyf << "**" << nxc << endl;
    //cout << "-"<<this->mapa[nyf][nxc] << "-" <<this->mapa[n2yf][nxc] << "-"<<endl;
    //cout << "derecha" <<int(this->mapa[nyf][nxc]) << endl;
    //cout << (this->mapa[nyf][nxc] == '.')<< endl;
    if ((this->mapa[(*nyf)][(*nxc)] == ' ' or this->mapa[(*nyf)][(*nxc)] == '.' or int(this->mapa[(*nyf)][(*nxc)] == 0))  and (this->mapa[(*n2yf)][(*nxc)] == ' ' or this->mapa[(*n2yf)][(*nxc)] == '.' or int(this->mapa[(*n2yf)][(*nxc)]) == 0)){
        if (pos_x>=625) {
            this->ir(-10,pos_y); }
        else
            this->pos_x += 5.0;
        //cout << "" ;
        //cout << "derech" << pos_x<< endl;
    if (((int(pos_y)%50+20) >= 15 and (int(pos_y)%50+20) <= 30) or ((int(pos_y-40)%50+20) >= 15 and (int(pos_y-40)%50+20) <= 30)){
            this->comer(int(pos_y/50),int(pos_x/50));
    }
    }

    delete nxc ;
    delete nyf ;
    delete n2yf;

}

void Personaje::mover_i(){

    this->s_i();

    int * nxc = new int;
    int * nyf = new int;
    int * n2yf = new int;

    *nxc = (this->pos_x - 5)/50;
    *nyf = (this->pos_y)/50;
    *n2yf = (this->pos_y+42)/50;


    //cout << "Izquierda  " <<this->pos_x << "** " <<nyf << "**" << nxc << endl;
    //cout <<"i<quierda" <<mapa[nyf][nxc] << endl;
    if ((this->mapa[*nyf][*nxc] == ' ' or this->mapa[*nyf][*nxc] == '.')  and (this->mapa[*n2yf][*nxc] == ' ' or this->mapa[*n2yf][*nxc] == '.')){
        if (pos_x<-10) {
            this->ir(620,pos_y); }
        else
            this->pos_x -= 5.0;

        if((int(pos_x))%10 != 0){
            this->comer(int(pos_y/50),int(pos_x/50));
        }
    }

    delete nxc;
    delete nyf;
    delete n2yf;
}

void Personaje::mover_o(){
    this->s_o();
    int * nyf = new int;
    int * nxc = new int;
    int * n2xc = new int;

    *nyf = (this->pos_y + 46)/50;
    *nxc = (this->pos_x)/50;
    *n2xc = (this->pos_x + 40)/50;


    if ((this->mapa[*nyf][*nxc] == ' ' or this->mapa[*nyf][*nxc] == '.')  and (this->mapa[*nyf][*n2xc] == ' ' or this->mapa[*nyf][*n2xc] == '.')){
        this->pos_y += 5.0;
        //cout << "se movio abo"  << endl;
        //cout << int(pos_x)<< "_"<<int(pos_x)%50-20 << endl;
        if((int(pos_x)%50+20) >= 15 and (int(pos_x)%50+20) <= 30){
            this->comer(int((pos_y+20)/50),int((pos_x+20)/50));
        }

    }

    delete nyf;
    delete nxc;
    delete n2xc;
}

int * Personaje::getpos(){
    int * get = new int[2];
    get[1] = (this->pos_x+25)/50;
    get[0] = (this->pos_y+25)/50;
    return get;
}

Personaje::~Personaje()
{
    //dtor
}
