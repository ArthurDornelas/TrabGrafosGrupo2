#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"
#include "Menu.h"
using namespace std;

int main()
{

    Grafo* grafo = new Grafo(0,1);
    //grafo->lerDigrafo("teste.txt");

    grafo->adicionarArestaNos(1,2,0);
    grafo->adicionarArestaNos(1,4,0);
    grafo->adicionarArestaNos(2,3,0);

    grafo->buscaEmLargura(1);
    Menu* menu = new Menu(grafo);
    menu->inicia();




}
