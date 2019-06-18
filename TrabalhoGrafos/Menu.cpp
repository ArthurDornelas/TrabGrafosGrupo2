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

Menu::Menu(Grafo* grafo, string arquivoEntrada1, string arquivoSaida1, int ehDigrafo, int ehPonderado)
{
    grafoUtilizado = grafo;
    arquivoEntrada = arquivoEntrada1;
    arquivoSaida = arquivoSaida1;
    digrafo = ehDigrafo;
    ponderado = ehPonderado;
}

//****************************************************************
// Leitura dos Arquivos e armazenamento, quando é um grafo       *
// ponderado.                                                    *
//****************************************************************
void Menu::leArquivoComPeso()
{
    if(!grafoUtilizado->grafoVazio())
        grafoUtilizado->apagaListaNos();
    cout<< "Lendo e Armazenando Arquivo..."<<endl<<endl;

    string filename = arquivoEntrada;
    ifstream infile(filename.c_str());

    int numNos, id, id2, peso;
    int contador = 0;

    if(infile.is_open()){
        infile >> numNos;
        grafoUtilizado->alocaTamanhoLista(numNos);
        while(infile >> id >> id2 >> peso){
            cout<<"id: "<<id<<endl;
            cout<<"id2: "<<id2<<endl;
            cout<<"peso: "<<peso<<endl<<endl;
            grafoUtilizado->adicionarArestaNos(id,id2,peso);
        }
    }
    grafoUtilizado->imprimiGrafo();
}

//****************************************************************
// Leitura dos Arquivos e armazenamento, quando é um grafo       *
// nao ponderado                                                 *
//****************************************************************
void Menu::leArquivoSemPeso()
{
    if(!grafoUtilizado->grafoVazio())
        grafoUtilizado->apagaListaNos();
    cout<< "Lendo e Armazenando Arquivo..."<<endl<<endl;

    string filename = arquivoEntrada;
    ifstream infile(filename.c_str());

    int numNos, id, id2;
    int contador = 0;

    if(infile.is_open()){
        while(infile >> id >> id2){
            cout<<"id: "<<id<<endl;
            cout<<"id2: "<<id2<<endl<<endl;
            grafoUtilizado->adicionarArestaNosSemPeso(id,id2);
        }

    }
    grafoUtilizado->imprimiGrafo();

}

//****************************************************************
// Leitura dos Arquivos e armazenamento, para Coloraçao de       *
// Vertices.                                                     *
//****************************************************************
void Menu::leArquivoColoracao()
{
    if(!grafoUtilizado->grafoVazio())
        grafoUtilizado->apagaListaNos();
    cout<< "Lendo e Armazenando Arquivo..."<<endl<<endl;

    string filename = arquivoEntrada;
    ifstream infile(filename.c_str());

    int numNos, numArestas, id, id2;
    string p, edge, e; // strings que armazenam os caracteres do arquivo

    if(infile.is_open()){
        infile >> p >> edge >> numNos >> numArestas;
        grafoUtilizado->alocaTamanhoLista(numNos);
        while(infile >> e >> id >> id2){
           // cout<<"id: "<<id<<endl;
            //cout<<"id2: "<<id2<<endl<<endl;
            grafoUtilizado->adicionarArestaNosSemPeso(id,id2);
        }
    }
   // grafoUtilizado->imprimiGrafo();

}

void Menu::inicia()
{
    int code = 1;
    cout<<endl<<endl;
    cout << "//////////////        MENU        /////////////" << endl;
    cout << "Digite 1 para Parte 1" << endl;
    cout << "Digite 2 para Coloracao de Vertices"<< endl;
    cout << "Digite 0 para Sair" << endl;
    cout << endl << endl;

    while(code != 0)
    {
        cin >> code;
        switch(code)
        {
        case 1:
            if(ponderado == 1)
                this->leArquivoComPeso();
            else
                this->leArquivoSemPeso();
            parte_1();
            break;
        case 2:
            this->leArquivoColoracao();
            coloracaoVertices();
            break;
        case 0:
            cout << "Fechando o programa" << endl;
            break;
        }
    }

}

void Menu::coloracaoVertices()
{
    int code = 1;
    cout<<endl<<endl;
    cout << "//////////////        Coloracao de Vertices        /////////////" << endl;
    cout << "Digite 1 para Algoritmo Guloso" << endl;
    cout << "Digite 2 para Algoritmo Guloso Randomizado"<< endl;
    cout << "Digite 3 para Algoritmo Guloso Randomizado Reativo"<< endl;
    cout << "Digite 0 para Voltar" << endl;
    cout << endl << endl;

    while(code != 0)
    {
        cin >> code;
        switch(code)
        {
        case 1:
            guloso();
            break;
        case 2:
            gulosoRandomizado();
            break;
        case 3:
            gulosoReativo();
            break;
        case 0:
            this->inicia();
            break;
        }
    }
}

void Menu::guloso()
{
    cout<<"Algoritmo Guloso"<< endl<<endl;
    int k = grafoUtilizado->algoritmoGuloso();
    cout<< "Qtd de Cores: " <<k<< endl<<endl;
    this->coloracaoVertices();
}

void Menu::gulosoRandomizado()
{
    cout<<"Algoritmo Guloso Randomizado"<< endl<<endl;
    grafoUtilizado->auxGulosoRandomizado();
    cout<<endl;
    this->coloracaoVertices();
}

void Menu::gulosoReativo()
{
    this->coloracaoVertices();
}

void Menu::parte_1()
{
    int code = 1;
    cout<<endl<<endl;
    cout << "//////////////        PARTE 1        /////////////" << endl;
    cout << "Digite 1 para adicionar ou excluir no"<< endl;
    cout << "Digite 2 para adicionar ou excluir aresta" << endl;
    cout << "Digite 3 para realizar um Caminhamento em Largura a partir de um vertice" << endl;
    cout << "Digite 4 para realizar um Caminhamento em Profundidade a partir de um vertice" << endl;
    cout << "Digite 5 para obter as Componentes Fortemente Conexas de um Digrafo" << endl;
    cout << "Digite 6 para obter as Componentes Conexas de um Grafo Simples" << endl;
    cout << "Digite 7 para obter a Ordenacao Topologica" << endl;
    cout << "Digite 8 para Algoritmo de Dijkstra (Caminho Minimo)" << endl;
    cout << "Digite 9 para Algoritmo de Floyd (Caminho Minimo)" << endl;
    cout << "Digite 10 para Algoritmo de Kruskal (Arvore Geradora Minima)" << endl;
    cout << "Digite 11 para Algoritmo de Prim (Arvore Geradora Minima)" << endl;
    cout << endl;
    cout << "Extras:" <<endl;
    cout << "Digite 12 para verificar o grau de um No" << endl;
    cout << "Digite 13 para verificar a k-regularidade de um grafo" << endl;
    cout << "Digite 14 para retornar a Ordem do Grafo" << endl;
    cout << "Digite 15 para mostrar a vizinhanca aberta de um no" << endl;
    cout << "Digite 16 para mostra a vizinhanca fechado de um no" << endl;
    cout << "Digite 17 para verificar se o grafo eh Completo" << endl;
    cout << "Digite 18 para verificar se o grafo eh Bipartido" << endl;
    cout << "Digite 19 para imprimir a Sequencia de Grau do Vertice" << endl;
    cout << "Digite 20 para verificar se ha um Ciclo no Grafo" << endl;
    cout << "Digite 21 para Imprimir o Grafo" << endl;
    cout << "Digite 0 para Voltar" << endl;
    cout << endl << endl;

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
        case 14:
            opcao14();
            break;
        case 15:
            opcao15();
            break;
        case 16:
            opcao16();
            break;
        case 17:
            opcao17();
            break;
        case 18:
            opcao18();
            break;
        case 19:
            opcao19();
            break;
        case 20:
            opcao20();
            break;
        case 21:
            opcao21();
            break;
        case 0:
            this->inicia();
            break;

        }
    }
}

void Menu::opcao1()
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
    this->parte_1();


}
void Menu::opcao2()
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
    this->parte_1();
}

void Menu::opcao3()
{
    /* Busca Em Largura */
    this->parte_1();
}

void Menu::opcao4()
{
    int key=0;
    cout<<"Digite o ID do No que deseja iniciar a Busca:"<<endl;
    cin>>key;
    grafoUtilizado->auxBuscaEmProfundidade(key);
    this->parte_1();
}

void Menu::opcao5()
{
    //Componente Fortemente Conexa
    this->parte_1();
}

void Menu::opcao6()
{
    //Componente Conexa
    this->parte_1();
}

void Menu::opcao7()
{
    //Ordenacao Topologica
    this->parte_1();
}

void Menu::opcao8()
{
    int origem=0;
    cout<<"Digite o ID do No de Origem"<<endl;
    cin>>origem;
    grafoUtilizado->dijkstra(origem);
    this->parte_1();
}

void Menu::opcao9()
{
    grafoUtilizado->algoritmoFloyd();
    this->parte_1();
}

void Menu::opcao10()
{
    grafoUtilizado->algoritmoKruskal();
    this->parte_1();
}

void Menu::opcao11()
{
    grafoUtilizado->algoritmoPrim();
    this->parte_1();
}

void Menu::opcao12()
{
    cout << "Digite o no para verificar seu grau" << endl;
    int id;
    cin >> id;
    int grauSaida = grafoUtilizado->retornagrauSaidaNo(id);
    cout << "O Grau do no é: " << grauSaida << endl;
    this->parte_1();
}

void Menu::opcao13()
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

    this->parte_1();

}

void Menu::opcao14()
{
    int ordem = grafoUtilizado->ordemGrafo();
    cout << "O grafo eh de ordem: " << ordem << endl;
    this->parte_1();

}

void Menu::opcao15()
{
    cout << "Digite o no para saber a vizinhança aberta" << endl;
    int id;
    cin >> id;
    grafoUtilizado->vizinhancaAberta(id);
    this->parte_1();

}

void Menu::opcao16()
{
    cout << "Digite o no para saber a vizinhança fechada" << endl;
    int id;
    cin >> id;
    grafoUtilizado->vizinhancaFechada(id);
    this->parte_1();
}

void Menu::opcao17()
{
    if(grafoUtilizado->grafoCompleto())
    {
        cout << "Eh completo" << endl;
    }
    else
        cout << "Nao eh completo" << endl;
    this->parte_1();
}

void Menu::opcao18()
{
    if(grafoUtilizado->ehBipartido())
    {
        cout << "Eh bipartido" << endl;
    }
    else
        cout << "Nao eh bipartido" << endl;
    this->parte_1();
}

void Menu::opcao19()
{
    grafoUtilizado->sequenciaGraus();
    this->parte_1();
}

void Menu::opcao20()
{
    if(grafoUtilizado->temCiclo())
    {
        cout << "Tem Ciclo" << endl;
    }
    else
        cout << "Nao Tem Ciclo" << endl;
    this->parte_1();
}

void Menu::opcao21()
{
    grafoUtilizado->imprimiGrafo();
    this->parte_1();
}






