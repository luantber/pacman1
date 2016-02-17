#include "Fantasma.h"
#include "modulo.cpp"
#include "Cuadro.h"
Cuadro Fantasma :: star(int ya,int xa,int yb,int xb){
char mapa2[14][14] = {
        "xxxxxxxxxxxxx",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "             ",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "x           x",
        "xxxxxxxxxxxxx"};

    /*
    int ya = 1;
    int xa = 1;

    int yb = 11;
    int xb = 2; */


    vector<vector < Cuadro > > cuadros;
    for (int i = 0; i<14;++i){
        vector <Cuadro> row;
        for(int j=0;j<14;++j){
            row.push_back(Cuadro(i,j));
            row.at(j).peso = row.at(j).distancia(yb,xb);
        }
        cuadros.push_back(row);
    }


    Cuadro a =cuadros.at(ya).at(xa);
    Cuadro b =cuadros.at(yb).at(xb);

    Cuadro pos = a;

    vector <Cuadro> l_abierta;
    vector <Cuadro> l_cerrada;
    l_abierta.push_back(a);

    bool parar = false;
    int contador = 0;

    while(!parar){
        Cuadro * pos = new Cuadro;
        vector <Cuadro> adyacentes;

        *pos = menor(l_abierta);
        //cout <<"Menor: " << pos -> y << ", "<<pos -> x << "  ";
        //cout <<"PAdre: " << pos -> padre -> y << ", "<<pos -> padre -> x<<endl;

        int temp = index(l_abierta,pos);
        l_cerrada.push_back(l_abierta.at(temp));
        l_abierta.erase(l_abierta.begin()+temp);


        int ary = pos->ary();
        int arx = pos->arx();
        int aby = pos->aby();
        int abx = pos->abx();
        int izy = pos->izy();
        int izx = pos->izx();
        int dey = pos->dey();
        int dex = pos->dex();

        if (!esta(l_cerrada,&(cuadros.at(ary).at(arx))) and mapa2[ary][arx] == ' '){
            adyacentes.push_back(cuadros.at(ary).at(arx));
         //cout << "arriba" << ary << ","<< arx << endl;
        }

        if (!esta(l_cerrada,&cuadros.at(aby).at(abx)) and mapa2[aby][abx] == ' ')
            adyacentes.push_back(cuadros.at(aby).at(abx));

        if (!esta(l_cerrada,&cuadros.at(izy).at(izx)) and mapa2[izy][izx] == ' ')
            adyacentes.push_back(cuadros.at(izy).at(izx));

        if (!esta(l_cerrada,&cuadros.at(dey).at(dex)) and mapa2[dey][dex] == ' ')
            adyacentes.push_back(cuadros.at(dey).at(dex));


        for(int i=0; i<adyacentes.size();++i){
            if (!esta(l_abierta,&adyacentes.at(i))){
                //cout << adyacentes.at(i) << endl;
                adyacentes.at(i).padre=pos;

                //cout << adyacentes.at(i).padre -> y <<", " << adyacentes.at(i).padre -> x<< endl;
                l_abierta.push_back(adyacentes.at(i));

               if (adyacentes.at(i) == &b){
                    parar = true;
                    //adyacentes.push_back(*b)
                    return adyacentes.at(i);
                }

            }
        }

    }

    //cout << cuadros.at(yb).at(xb).padre -> x << " " << cuadros.at(yb).at(xb).padre->y << endl;
}
Fantasma::~Fantasma()
{
    //dtor
}
