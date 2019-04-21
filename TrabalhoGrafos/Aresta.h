#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"
using namespace std;

class Aresta{
    private:
        float pesoAresta;
        int identNo;
        int idLista;

    public:
        Aresta(int idNo,float pesoA,int id ){ identNo = idNo; pesoAresta = pesoA; idLista = id; };
        Aresta(int idNo,int id ){ identNo = idNo; pesoAresta = -1 ; idLista = id; };
        float getPesoAresta(){ return this->pesoAresta; };
        int getIdNo(){ return this->identNo; };
        void setIdNo(int id) {this->identNo = id; };
        int getIdLista(){ return this->idLista; };
        void setIdLista(int id) {this->idLista = id; };
        void setPesoAresta(float peso){ this->pesoAresta = peso; };
};

#endif // ARESTA_H_INCLUDED
