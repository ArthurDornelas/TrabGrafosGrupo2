#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"
#include "Menu.h"
using namespace std;

void leArquivo(Grafo *grafo, int ponderado)
{
    int numN = 0; //armazena o número de N's do arquivo
    ifstream infile ("teste.txt");
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



    //****************************************************************
    // Leitura dos Arquivos e armazenamento, quando é um grafo       *
    // ponderado                                                     *
    //****************************************************************
    i=0;
    if(ponderado == 1)
    {
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
            cout<<endl<<endl;


        }
    }


    //****************************************************************
    // Leitura dos Arquivos e armazenamento, quando é um grafo       *
    // nao ponderado                                                 *
    //****************************************************************

    else
    {
        i=0;
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
            cout<< "ADD: " << vetN[j] << " e " << vetN[j+1]<<endl;
            grafo->adicionarArestaNosSemPeso(vetN[j],vetN[j+1]);
            cout<<endl<<endl;

        }
    }

}


int main(int argc, char* argv[])
{
    int digrafo = atoi(argv[0]);
    int ponderado = atoi(argv[1]);

    Grafo* grafo = new Grafo(0,0);
    leArquivo(grafo,0);


    cout<<"Testa Guloso"<< endl<<endl;
    int k = grafo->algoritmoGuloso();
    cout<< "Qtd de Cores: " <<k<< endl<<endl;
    cout<<"Imprime"<<endl;
    grafo->imprimiGrafo();


    Menu* menu = new Menu(grafo);
    menu->inicia();


    return 0;

}
