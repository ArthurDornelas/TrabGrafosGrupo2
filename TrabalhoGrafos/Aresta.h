#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
using namespace std;

class Aresta{
    private:
        float pesoAresta;
        int identNo;
        int idLista;
        int indiceNo;

    public:
        Aresta(int idNo,float pesoA,int id, int indNo){ identNo = idNo; pesoAresta = pesoA; idLista = id; indiceNo = indNo;};
        Aresta(int idNo,int id, int indNo ){ identNo = idNo; pesoAresta = -1 ; idLista = id; indiceNo = indNo; };
        float getPesoAresta(){ return this->pesoAresta; };
        int getIdNo(){ return this->identNo; };
        void setIdNo(int id) {this->identNo = id; };
        int getIdLista(){ return this->idLista; };
        void setIdLista(int id) {this->idLista = id; };
        void setPesoAresta(float peso){ this->pesoAresta = peso; };
        void setIndiceNo(int indNo){this->indiceNo = indNo;};
        int getIndiceNo(){ return this->indiceNo; };
};

#endif // ARESTA_H_INCLUDED
