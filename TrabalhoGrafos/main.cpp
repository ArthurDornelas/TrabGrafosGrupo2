#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"
#include "Menu.h"
using namespace std;

void leArquivo(Grafo *grafo, int ponderado)
{
    int numN = 0; //armazena o n�mero de N's do arquivo
    ifstream infile ("teste.txt");
    int i=0;

    while(infile)
    {
        if(i==0)
        {
            string s;
            getline(infile,s);
            numN = atoi(s.c_str()); //pega o n�mero de N's que est�o no arquivo.
            break;
        }
    }



    //****************************************************************
    // Leitura dos Arquivos e armazenamento, quando � um grafo       *
    // ponderado                                                     *
    //****************************************************************
    i=0;
    if(ponderado == 1)
    {
        while(infile)
        {
            string s;
            getline(infile,s);
            //cout<<s<<endl;
            char str[s.length()+1];
            strcpy(str, s.c_str());
            char *pch = strtok(str," ");
            int vetN[3];
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
                    vetN[contador] = atoi(pch);
                    i++;
                }
                pch = strtok (NULL, " ");
                contador++;
            }

            int j=0;
            grafo->adicionarArestaNos(vetN[j],vetN[j+1],vetN[j+2]);
            cout<<endl<<endl;

            if(i>=12)
                break;
        }
    }


    //****************************************************************
    // Leitura dos Arquivos e armazenamento, quando � um grafo       *
    // nao ponderado                                                 *
    //****************************************************************

    else
    {
        i=0;
        while(infile)
        {
            string s;
            getline(infile,s);
            //cout<<s<<endl;
            char str[s.length()+1];
            strcpy(str, s.c_str());
            char *pch = strtok(str," ");
            int vetN[3];
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
                pch = strtok (NULL, " ");
                contador++;
            }

            int j=0;
            grafo->adicionarArestaNosSemPeso(vetN[j],vetN[j+1]);
            cout<<endl<<endl;

            if(i>=9)
                break;
        }
    }

}


int main(int argc, char* argv[])
{

    Grafo* grafo = new Grafo(1,1);
    Grafo* grafo2 = new Grafo(0,0);
    grafo2->adicionarNo(0);
    grafo2->adicionarNo(1);
    grafo2->adicionarNo(2);
    grafo2->adicionarNo(3);
    grafo2->adicionarNo(4);
    grafo2->adicionarArestaNosSemPeso(0,1);
    grafo2->adicionarArestaNosSemPeso(1,2);
    grafo2->adicionarArestaNosSemPeso(3,4);
    grafo2->compConexa();

    //leArquivo(grafo,1);
    grafo->adicionarArestaNosSemPeso(1,2);
    grafo->adicionarArestaNosSemPeso(2,3);
    grafo->adicionarArestaNosSemPeso(3,1);
    grafo->adicionarArestaNosSemPeso(2,4);
    grafo->adicionarArestaNosSemPeso(4,5);
    grafo->fortConexa();
    //grafo->compConexa();
    //cout << grafo->temCiclo() << endl;
    //grafo->ordenacaoTopologica();

   // grafo->adicionarArestaNosSemPeso(0,2);
   // grafo->adicionarArestaNosSemPeso(3,0);





    // leArquivo(grafo,1);
    //cout<<"Testa Guloso"<< endl<<endl<<endl<<endl;
    //int k = grafo->algoritmoGuloso();

   // cout<< k<< endl<<endl;
   /* cout<<"Imprime"<<endl;
    grafo->imprimiGrafo();
    grafo->adicionarNo(1);
     grafo->adicionarArestaNos(4,2,-1);
    grafo->adicionarNo(2);
    grafo->adicionarNo(3);
    grafo->adicionarNo(4);
    grafo->adicionarArestaNos(2,3,3);

    grafo->adicionarArestaNos(3,4,2);
    grafo->adicionarArestaNos(1,3,-2);
    grafo->adicionarArestaNos(2,1,4);


    grafo->algoritmoFloyd();
    // Menu* menu = new Menu(grafo);//
    // menu->inicia();//

*/
    return 0;

}
