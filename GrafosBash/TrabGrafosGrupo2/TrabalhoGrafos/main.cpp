#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"
#include "Menu.h"
using namespace std;


//****************************************************************
// Leitura dos Arquivos e armazenamento, quando é um grafo       *
// ponderado.                                                    *
// Recebe um objeto de Grafo e uma string com o arquivo de       *
// entrada.                                                      *
//****************************************************************
void leArquivoComPeso(Grafo *grafo, string arquivoEntrada)
{
    cout<< "Lendo e Armazenando Arquivo..."<<endl<<endl;
    int numN = 0; //armazena o número de N's do arquivo

    string filename = arquivoEntrada;
    ifstream infile(filename.c_str());

    int i=0;
    while(infile)
    {
        if(i==0)
        {
            string s;
            getline(infile,s);
            numN = atoi(s.c_str()); //pega o número de N's que estão no arquivo.
            break;
        }
    }

    i=0;
    while(!infile.eof())
    {
        string s;
        getline(infile,s);
        //cout<<s<<endl;
        char str[s.length()+1];
        strcpy(str, s.c_str());
        char *pch = strtok(str," ");
        int vetN[3]= {0,0,0};
        int contador = 0;
        while (pch != NULL)
        {
            if(contador == 0)
            {
                vetN[contador] = atoi(pch);
                i++;
            }
            else if(contador == 1)
            {
                vetN[contador] = atoi(pch);
                i++;
            }
            else if(contador == 2)
            {
                vetN[contador] = atoi(pch);
                i++;
            }

            pch = strtok (NULL, " ");
            contador++;
        }

        int j=0;
        grafo->adicionarArestaNos(vetN[j],vetN[j+1],vetN[j+2]);

    }

}

//****************************************************************
// Leitura dos Arquivos e armazenamento, quando é um grafo       *
// nao ponderado                                                 *
//****************************************************************
void leArquivoSemPeso(Grafo *grafo, string arquivoEntrada)
{
/*
        int i=0;
        while(!infile.eof())
        {
            string s;
            getline(infile,s);
            //cout<<s<<endl;
            char str[s.length()+1];
            strcpy(str, s.c_str());
            char *pch = strtok(str," ");
            int vetN[3]={0,0,0};
            int contador = 0;
            while (pch != NULL)
            {
                if(contador == 0)
                {
                    vetN[contador] = atoi(pch);
                    i++;
                }

                else if(contador == 1)
                {
                    vetN[contador] = atoi(pch);
                    i++;
                }
                else
                {
                    break;
                }
                pch = strtok (NULL, " ");
                contador++;
            }

            int j=0;
            grafo->adicionarArestaNosSemPeso(vetN[j],vetN[j+1]);

        }
*/
}

int main(int argc, char* argv[])
{
    string arquivoEntrada = argv[1];
    string arquivoSaida = argv[2];
    int digrafo = atoi(argv[3]);
    int ponderado = atoi(argv[4]);
    digrafo = 0, ponderado = 1;
    Grafo* grafo = new Grafo(digrafo,ponderado);

    if(ponderado == 1)
        leArquivoComPeso(grafo,arquivoEntrada);
   // else
       // leArquivoSemPeso(grafo,arquivoEntrada);


    //////////// Teste Gulosos /////////
    /*
    cout<<"Testa Guloso Randomizado"<< endl<<endl;
    grafo->auxGulosoRandomizado();
    cout<<endl;
    grafo->imprimiGrafo();
    cout<< endl<<endl;
    cout<<"Testa Guloso"<< endl<<endl;
    int k = grafo->algoritmoGuloso();
    cout<< "Qtd de Cores: " <<k<< endl<<endl;
    grafo->imprimiGrafo();
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

    Menu* menu = new Menu(grafo);
    menu->inicia();


    return 0;

}
