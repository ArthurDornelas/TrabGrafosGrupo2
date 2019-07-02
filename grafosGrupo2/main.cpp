#include <iostream>
#include "Grafo.h"
#include "Menu.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{

    string arquivoEntrada = argv[1];
    string arquivoSaida = argv[2];
    int digrafo = atoi(argv[3]);
    int ponderado = atoi(argv[4]);

    Grafo* grafo = new Grafo(digrafo,ponderado);
    grafo->arquivoSaida = arquivoSaida;

    Menu* menu = new Menu(grafo,arquivoEntrada,arquivoSaida,digrafo,ponderado);
    menu->inicia();



    //////////// Teste Gulosos /////////
    /*
    cout<<"Testa Guloso Randomizado"<< endl<<endl;
    grafo->auxGulosoRandomizado();
    cout<<endl;

    cout<< endl<<endl;
    cout<<"Testa Guloso"<< endl<<endl;
    int k = grafo->algoritmoGuloso();
    cout<< "Qtd de Cores: " <<k<< endl<<endl;
    */


    ////////TESTE KRUSKAL/////////
    /*grafo->adicionarArestaNos(0, 1, 4);
    grafo->adicionarArestaNos(0, 2, 4);
    grafo->adicionarArestaNos(1, 2, 2);
    grafo->adicionarArestaNos(1, 0, 4);
    grafo->adicionarArestaNos(2, 0, 4);
    grafo->adicionarArestaNos(2, 1, 2);
    grafo->adicionarArestaNos(2, 3, 3);
    grafo->adicionarArestaNos(2, 5, 2);
    grafo->adicionarArestaNos(2, 4, 4);
    grafo->adicionarArestaNos(3, 2, 3);
    grafo->adicionarArestaNos(3, 4, 3);
    grafo->adicionarArestaNos(4, 2, 4);
    grafo->adicionarArestaNos(4, 3, 3);
    grafo->adicionarArestaNos(5, 2, 2);
    grafo->adicionarArestaNos(5, 4, 3);*/

    //grafo->adicionarArestaNos(1,2,3);
    //grafo->adicionarArestaNos(1,3,5);
    //grafo->adicionarArestaNos(2,3,7);
    /* grafo->adicionarArestaNos(0,1,10);
     grafo->adicionarArestaNos(0,2,6);
     grafo->adicionarArestaNos(0,3,5);
     grafo->adicionarArestaNos(1,3,15);
     grafo->adicionarArestaNos(2,3,4);
    */




    return 0;

}
