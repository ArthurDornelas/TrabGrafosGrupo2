#include "Menu.h"
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"
#include "iostream"
using namespace std;

Menu::Menu(Grafo* grafo)
{
    grafoUtilizado = grafo;

}

void Menu::inicia()
{

    int code = 1;
    cout << "///////////////////////////" << endl;
    cout << "Digite 1 para ler o arquivo" << endl;
    cout << "Digite 2 para adicionar ou excluir no"<< endl;
    cout << "Digite 3 para adicionar ou excluir aresta" << endl;
    cout << "Digite 4 para verificar o grau do no" << endl;
    cout << "Digite 5 para verificar a k-regularidade de um grafo" << endl;
    cout << "Digite 6 para retornar a ordem de um grafo" << endl;
    cout << "Digite 7 para mostrar a vizinhanca aberta de um no" << endl;
    cout << "Digite 8 para mostra a vizinhanca fechado de um no" << endl;
    cout << "Digite 9 para verificar se o grafo e completo" << endl;
    cout << "Digite 10 para verificar se o grafo e bipartido" << endl;
    cout << "Digite 11 para imprimir a sequencia de grau do vertice" << endl;
    cout << "Digite 12 para realizar uma busca em profundidade a partir de um vertice" << endl;
    cout << "Digite 13 para Algoritmo de Kruskal" << endl;
    cout << "Digite 0 para finalizar o programa" << endl;
    while(code != 0)
    {
        cin >> code;
        switch(code)
        {
        case 1:
             opcao1();
            break;
        case 2:
            opcao2();
            break;
        case 3:
            opcao3();
            break;
        case 4:
            opcao4();
            break;
        case 5:
            opcao5();
            break;
        case 6:
            opcao6();
            break;
        case 7:
            opcao7();
            break;
        case 8:
            opcao8();
            break;
        case 9:
            opcao9();
            break;
        case 10:
            opcao10();
            break;
        case 11:
            opcao11();
            break;
        case 12:
            opcao12();
            break;
        case 13:
            opcao13();
            break;
        case 0:
            cout << "Fechando o programa" << endl;
            break;

        }
    }

}


void Menu::opcao1()
{
    /* ainda nao implementamos essa parte */

}
void Menu::opcao2()
{
    int i;
    cout << "Digite 1 para adicionar ou 2 para excluir o no" << endl;
    cin >> i;
    if (i == 1)
    {
        cout << "Digite o id do no que sera adicionado" << endl;
        int id;
        cin >> id;
        grafoUtilizado->adicionarNo(id);
        cout << "No adicionado" << endl;

    }
    else if (i == 2)
    {
        cout << "Digite o id do no que sera excluido" << endl;
        int id;
        cin >> id;
        grafoUtilizado->removerNo(id);
        cout << "No removido" << endl;

    }
    else
        cout << "Voltando ao menu" << endl;
    this->inicia();

}

void Menu::opcao3()
{
    int i;
    cout << "Digite 1 para adicionar ou 2 para excluir a aresta" << endl;
    cin >> i;
    if (i == 1)
    {
        cout << "Digite os ids dos nos que você quer adicionar uma aresta" << endl;
        int id1;
        int id2;
        cin >> id1;
        cin >> id2;
        if(grafoUtilizado->ehponderada() == 1){
            cout << "Digite o peso da aresta" << endl;
            float peso;
            cin >> peso;
            grafoUtilizado->adicionarArestaNos(id1, id2,peso);
            cout << "Aresta adicionada" << endl;
        }
        else{
            grafoUtilizado->adicionarArestaNosSemPeso(id1, id2);
            cout << "Aresta adicionada" << endl;
        }
    }
    else if (i == 2)
    {
        cout << "Digite o id da aresta que sera excluido" << endl;
        int id1;
        int id2;
        cout << "Digite os dois nos que terao a aresta removida" << endl;
        cin >> id1;
        cin >> id2;
        grafoUtilizado->removeAresta(id1, id2);

    }
    else
        cout << "Reposta invalida, voltando ao menu" << endl;
    this->inicia();


}

void Menu::opcao4()
{

    cout << "Digite o no para verificar seu grau" << endl;
    int id;
    cin >> id;
    int grauSaida = grafoUtilizado->retornagrauSaidaNo(id);
    cout << "O Grau do no é: " << grauSaida << endl;
    this->inicia();

}

void Menu::opcao5()
{
    cout << "Qual o valor de K para verificar a regularidade?" << endl;
    int k;
    cin >> k;
    if (grafoUtilizado->grafoKRegularidade(k))
    {
        cout << "O grafo eh: " << k << "-regular" << endl;
    }
    else
        cout << "Nao eh regular" << endl;

    this->inicia();

}

void Menu::opcao6()
{
    int ordem = grafoUtilizado->ordemGrafo();
    cout << "O grafo eh de ordem: " << ordem << endl;
    this->inicia();

}

void Menu::opcao7()
{
    cout << "Digite o no para saber a vizinhança aberta" << endl;
    int id;
    cin >> id;
    grafoUtilizado->vizinhancaAberta(id);
    this->inicia();

}

void Menu::opcao8()
{
    cout << "Digite o no para saber a vizinhança fechada" << endl;
    int id;
    cin >> id;
    grafoUtilizado->vizinhancaFechada(id);
    this->inicia();
}

void Menu::opcao9()
{
    if(grafoUtilizado->grafoCompleto())
    {
        cout << "Eh completo" << endl;
    }
    else
        cout << "Nao eh completo" << endl;
    this->inicia();
}

void Menu::opcao10()
{
    /* opçao do grafo bipartido ainda deve ser implementada */


}

void Menu::opcao11()
{
    grafoUtilizado->sequenciaGraus();
    this->inicia();

}

void Menu::opcao12()
{
    int key=0;
    cout<<"Digite a id do no que deseja iniciar a busca:"<<endl;
    cin>>key;
    grafoUtilizado->auxBuscaEmProfundidade(key);
    this->inicia();
}

void Menu::opcao13()
{
    grafoUtilizado->algoritmoKruskal();
    this->inicia();
}

