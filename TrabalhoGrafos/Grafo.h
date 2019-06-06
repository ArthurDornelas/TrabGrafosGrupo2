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
    int ehDigrafo;
    int ehPonderada;


public:

    std::vector <No> arvore;
    std::vector <Aresta> arestasArvore;
    std::vector <Aresta> auxArestasArvore;
    Grafo(int ehDigrafoAux, int ehPonderadaAux);
    ~Grafo();
    void adicionarArestaNos(int id, int id2,int peso);
    void adicionarArestaNosSemPeso(int id, int id2);
    void adicionarNo(int id);
    void removerNo(int id);
    void removeAresta(int id1, int id2);
    //void adicionaAresta(int id1,int id2, float peso);
    bool estaNoGrafo(int index);
    int ordemGrafo();
    int retornagrauSaidaNo(int id);
    bool vizinho(int id1, int id2);
    bool grafoCompleto();
    bool grafoKRegularidade(int k);
    void vizinhancaAberta(int id);
    void vizinhancaFechada(int id);
    void sequenciaGraus();
    void imprimiGrafo();
    void algoritmoPrim();
    int ehdigrafo(){return ehDigrafo;};
    int ehponderada() {return ehPonderada;};
    void lerGrafo(string caminho);
    void lerDigrafo(string caminho);
    bool ehBipartido();
    char bucar_label_do_no(int id);
    void preencher_grafo_bipartido();
    void imprimir_biparticao();
    void auxBuscaEmProfundidade(int key);
    void buscaEmProfundidade(No *v);//faz uma busca a partir de um vertice
    void buscaEmLargura(int id);
    void compConexa();
    void buscaConexa(No* v, int componente);
    int algoritmoGuloso();
    void quickSort(int left, int right);
    int quickPartition(int left, int right);
    void troca(int x1, int x2);
    void algoritmoFloyd();


};
#endif // GRAFO_H_INCLUDED
