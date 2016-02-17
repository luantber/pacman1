#include <vector>
#include <iostream>
using namespace std;

Cuadro menor(vector<Cuadro> xs){
    Cuadro m = xs.at(0);
    for(int i = 0; i<xs.size() ; ++i){
        if (xs.at(i) < &m)
            m = xs.at(i);
    }
    return m;
}

int index(vector<Cuadro> xs,Cuadro* bus){
    for(int i=0; i<xs.size();++i){
        if(xs.at(i) == bus)
            return i;
    }

}

bool esta(vector<Cuadro> xs, Cuadro* bus){
    //cout << "funciono" << endl;
    for(int i=0; i<xs.size();++i){
        if(xs.at(i) == bus){
            return true;
        }
    }
    return false;
}

void print(vector <Cuadro> xs){
    cout << endl;
    for(int i = 0; i<xs.size();++i){
        cout << xs.at(i).y << ", " << xs.at(i).x;
        //cout << "(" << xs.at(i)->padre->pos[0] << ", " << xs.at(i)->padre->pos[1] << ")  ;";
    }
    cout << endl;
}

//vector <vector <int > > caminar ()

