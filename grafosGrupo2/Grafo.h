#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <vector>
#include "No.h"
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

class Grafo
{
private:
    std::vector <No> listaAdj;
    int ehDigrafo;
    int ehPonderada;

public:

    std::vector <No> arvore;
    std::vector <Aresta> arvoreKruskal;
    std::vector <No> auxArvoreKruskal;
    std::vector <Aresta> arestasArvore;
    std::vector <Aresta> auxArestasArvore;
    std::vector <Aresta> pesoArestas;
    std::vector <int> ordenado;
    std::vector <No> auxOrdena;
    string arquivoSaida;
    Grafo(int ehDigrafoAux, int ehPonderadaAux);
    ~Grafo();
    void adicionarArestaNos(int id, int id2,int peso);
    void adicionarArestaNosSemPeso(int id, int id2);
    void adicionarNo(int id);
    void removerNo(int id);
    void removeAresta(int id1, int id2);
    bool estaNoGrafo(int index);
    int ordemGrafo();
    bool grafoVazio(){return listaAdj.empty();};
    void apagaListaNos(){listaAdj.clear();};
    void alocaTamanhoLista(int numNos){listaAdj.reserve(numNos);};
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
    int ehponderada(){return ehPonderada;};
    bool ehBipartido();
    char bucar_label_do_no(int id);
    void preencher_grafo_bipartido();
    void imprimir_biparticao();
    void auxBuscaEmProfundidade(int key);
    void buscaEmProfundidade(No *v);//faz uma busca a partir de um vertice
    void buscaEmLargura(int id);
    int algoritmoGuloso();
    int algoritmoGulosoRandomizado(float alfa, int intMax, int chamado);
    void auxGulosoRandomizado();
    void ordenaGrafo();
    void auxAlgoritmoGulosoReativo();
    void algoritmoGulosoReativo(float alfa[], int intMax, int block_iterations, int seed,int delta);
    void quickSort(int left, int right);
    int quickPartition(int left, int right);
    void troca(int x1, int x2);
    void algoritmoKruskal();
    void uniao_kruskal(No *v1, No *v2);
    No* busca_kruskal(No *v);
    void quickSortKruskal(int left,int right);
    int quickPartitionKruskal(int left, int right);
    void trocaKruskal(int x1, int x2);
    void dijkstra(int id);
    void algoritmoFloyd();
    void buscaConexaUtil(int u, bool visitado[]);
    void compConexa();
    void fortConexa();
    void fortConexaUtil(int u, int dem[], int low[], stack<int> *membro, bool *verificaMembro);
    void ordenacaoTopologica();
    void ordTopologicaUtil(int v, bool visitado[], stack<int> &pilha);
    bool temCiclo();
    bool buscaUtil(int x, int cor[]);
    void geraRandom(int r[], int m);
    bool verificaVetorVazioDijkstra(int vet[],int n);
};
#endif // GRAFO_H_INCLUDED
