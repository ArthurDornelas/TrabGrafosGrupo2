#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <vector>
#include "No.h"
#include <iostream>
#include <fstream>
using namespace std;

class Grafo
{
private:
    std::vector <No> listaAdj;
    bool ehDigrafo;
    bool ehPonderada;


public:

    std::vector <No> arvore;
    std::vector <Aresta> arestasArvore;
    std::vector <Aresta> auxArestasArvore;
    Grafo(bool ehDigrafo1, bool ehPonderada1);
    ~Grafo();
    void adicionarArestaNos(int id, int id2,int peso);
    void adicionarNo(int id);
    void removerNo(int id);
    void removeAresta(int id1, int id2);
    void adicionaAresta(int id1,int id2, float peso);
    bool estaNoGrafo(int index);
    int ordemGrafo();
    int retornaGrauNo(int id);
    bool vizinho(int id1, int id2);
    bool grafoCompleto();
    bool grafoKRegularidade(int k);
    void vizinhancaAberta(int id);
    void vizinhancaFechada(int id);
    void sequenciaGraus();
    void imprimiGrafo();
    void algoritmoPrim();
    void lerGrafo(string caminho);
    void lerDigrafo(string caminho);
    bool ehBipartido();
    char bucar_label_do_no(int id);
    void preencher_grafo_bipartido();
    void imprimir_biparticao();


};
#endif // GRAFO_H_INCLUDED
