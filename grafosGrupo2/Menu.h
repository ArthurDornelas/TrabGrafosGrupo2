#ifndef MENU_H
#define MENU_H
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"

using namespace std;

class Menu
{
    private:
        Grafo* grafoUtilizado;
        int digrafo;
        int ponderado;
        string arquivoEntrada;
        string arquivoSaida;

    public:
        Menu(Grafo* grafo);
        Menu(Grafo* grafo, string arquivoEntrada, string arquivoSaida, int ehDigrafo, int ehPonderado);
        void leArquivoComPeso();
        void leArquivoSemPeso();
        void leArquivoColoracao();
        void inicia();
        void parte_1();
        void coloracaoVertices();
        void guloso();
        void gulosoRandomizado();
        void gulosoReativo();
        void opcao1();
        void opcao2();
        void opcao3();
        void opcao4();
        void opcao5();
        void opcao6();
        void opcao7();
        void opcao8();
        void opcao9();
        void opcao10();
        void opcao11();
        void opcao12();
        void opcao13();
        void opcao14();
        void opcao15();
        void opcao16();
        void opcao17();
        void opcao18();
        void opcao19();
        void opcao20();
        void opcao21();


};


#endif
