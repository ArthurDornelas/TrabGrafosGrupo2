#ifndef MENU_H
#define MENU_H
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"

using namespace std;

class Menu
{
    public:
        Menu(Grafo* grafo);
        void inicia();
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


    private:
        Grafo* grafoUtilizado;
};


#endif
