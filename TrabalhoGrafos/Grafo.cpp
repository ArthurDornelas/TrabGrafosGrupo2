#include "Grafo.h"
#include "No.h"
#include "No.cpp"
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 9999999;
#include <stack> // busca em profundidade
#include<queue>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "Aresta.h"

using namespace std;

Grafo::Grafo(int ehDigrafoAux, int ehPonderadaAux)
{
    ehDigrafo = 0, ehPonderada = 0;
    ehDigrafo = ehDigrafoAux;
    ehPonderada = ehPonderadaAux;
}

Grafo::~Grafo()
{

}

void Grafo::adicionarNo(int id)
{
    No no = No();
    no.setId(id);
    listaAdj.push_back(no);
}

void Grafo::removerNo (int id)
{
    std::vector <No>::iterator it;
    std::vector <Aresta>::iterator a;
    int i=0,j=0;
    for(it = listaAdj.begin() ; it != listaAdj.end(); ++it, i++ )
    {
        if ( it->getId() == id )
        {
            listaAdj.erase( listaAdj.begin() + i  );
        }
    }
    i =0;
    for(it = listaAdj.begin(); it != listaAdj.end(); ++it,i++)
    {
        j = 0;
        for(std::vector<Aresta>::iterator a = listaAdj[i].listaAresta.begin(); a != listaAdj[i].listaAresta.end() && j < listaAdj[i].listaAresta.size() ;   ++a)
        {
            if(a->getIdNo() == id)
            {
                listaAdj[i].listaAresta.erase( listaAdj[i].listaAresta.begin() + j );
            }
            j++;
        }
    }
}

void Grafo::removeAresta(int id1,int id2)
{
    if(estaNoGrafo(id1) && estaNoGrafo(id2))
    {
        if(vizinho(id1,id2))
        {
            if(ehDigrafo == 0)
            {
                for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
                {
                    if( it->getId() == id1 )
                        it->removeAresta(id2);
                    if( it->getId() == id2)
                        it->removeAresta(id1);
                }
            }
            else
                for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
                {
                    if( it->getId() == id1 )
                        it->removeAresta(id2);
                }
        }

    }
    else
    {
        cout << "Um ou mais NOS nao existem, impossivel remover a ARESTA." << endl;
    }

    imprimiGrafo();
}

void Grafo::adicionarArestaNosSemPeso(int id, int id2)
{
    bool id1_noGrafo = false;
    bool id2_noGrafo = false;

    if(estaNoGrafo(id))
    {
        id1_noGrafo = true;
    }
    else
    {
        adicionarNo(id);
        id1_noGrafo = true;
    }

    if(estaNoGrafo(id2))
    {
        id2_noGrafo = true;
    }
    else
    {
        adicionarNo(id2);
        id2_noGrafo = true;
    }


    if(id1_noGrafo==true && id2_noGrafo==true && ehDigrafo==0 )
    {
        int i=0,k=-1,l=-1;
        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {

            if(id != id2)
            {
                if(it->getId() == id)
                {
                    k = i;
                }

                else if(it->getId() == id2)
                {
                    l = i;
                }
            }

            if((k!=-1) && (l!=-1))
            {
                listaAdj[k].adicionaArestaSemPeso(id2,id,l,k);
                listaAdj[l].adicionaArestaSemPeso(id,id2,k,l);
                break;
            }

            i++;
        }

    }

    else if(id1_noGrafo==true && id2_noGrafo==true && ehDigrafo==1)
    {
        int i=0,k=-1,l=-1;
        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {

            if(id != id2)
            {

                if(it->getId() == id)
                {
                    k = i;
                }

                else if(it->getId() == id2)
                {
                    l = i;
                }

            }

            if((k!=-1) && (l!=-1))
            {
                listaAdj[k].adicionaArestaSemPeso(id2,id,l,k);
                listaAdj[l].setGrauEntrada(1);
                break;
            }

            i++;
        }

    }


}

void Grafo::adicionarArestaNos(int id, int id2,int peso)
{
    bool id1_noGrafo = false;
    bool id2_noGrafo = false;

    if(estaNoGrafo(id))
    {
        id1_noGrafo = true;
    }
    else
    {
        adicionarNo(id);
        id1_noGrafo = true;
    }

    if(estaNoGrafo(id2))
    {
        id2_noGrafo = true;
    }
    else
    {
        adicionarNo(id2);
        id2_noGrafo = true;
    }


    if(id1_noGrafo==true && id2_noGrafo==true && ehDigrafo==0 )
    {
        int i=0,k=-1,l=-1;
        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {

            if(id != id2)
            {
                if(it->getId() == id)
                {
                    k = i;
                }

                else if(it->getId() == id2)
                {
                    l = i;
                }
            }

            if((k!=-1) && (l!=-1))
            {
                listaAdj[k].adicionaAresta(id2,peso,id,l,k);
                listaAdj[l].adicionaAresta(id,peso,id2,k,l);
                break;
            }

            i++;
        }

    }

    else if(id1_noGrafo==true && id2_noGrafo==true && ehDigrafo==1)
    {
        int i=0,k=-1,l=-1;
        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {

            if(id != id2)
            {

                if(it->getId() == id)
                {
                    k = i;
                }

                else if(it->getId() == id2)
                {
                    l = i;
                }

            }

            if((k!=-1) && (l!=-1))
            {
                listaAdj[k].adicionaAresta(id2,peso,id,l,k);
                listaAdj[l].setGrauEntrada(1);
                break;
            }

            i++;
        }

    }

}


bool Grafo::estaNoGrafo(int i)
{
    if(listaAdj.size() > 0)
    {

        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            if( it->getId() == i )
            {
                return true;
            }
        }
        return false;

    }

    else
    {
        return false;
        cout<<"lista vazia";
    }
}

int Grafo::ordemGrafo()
{
    return listaAdj.size();
}

int Grafo::retornagrauSaidaNo(int id)
{

    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if( it->getId() == id )
        {
            return it->getGrauSaida();
        }
    }
    cout << "Nao existe esse NO no Grafo."<<endl;

}

bool Grafo::vizinho(int id1, int id2)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if(it->getId() == id1 )
        {
            return it->eVizinho(id2);
        }
        if(it->getId() == id2 )
        {
            return it->eVizinho(id1);
        }
    }
    return false;
}

bool Grafo::grafoCompleto()
{
    int n = ordemGrafo();
    int num_Arestas = 0;
    for(int i = 0; i < n; i++)
    {
        num_Arestas += listaAdj[i].getGrauSaida();
    }
    if(num_Arestas == n*(n-1))
        return true;
    return false;

}

bool Grafo::grafoKRegularidade(int k)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if(it->getGrauSaida()!=k)
        {
            return false;
        }
    }
    return true;

}

void Grafo::vizinhancaAberta(int id)
{
    int i=0;
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++)
    {
        if( it->getId() == id )
        {
            if(it->listaAresta.size() >= 1)
            {
                for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest)
                    std::cout << arest->getIdNo() << std::endl;
                break;
            }
            else
            {
                cout << "Vizinhanca aberta sem nos" << endl;
                break;
            }
        }
    }
}

void Grafo::vizinhancaFechada(int id)
{
    int i=0;
    std::cout << id << std::endl;
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++)
    {
        if( it->getId() == id )
        {
            for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest)
                std::cout << arest->getIdNo() << std::endl;
        }
    }

}

void Grafo::sequenciaGraus()
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        std::cout << "No " << it->getId() << " - " << it->getGrauSaida() << "  ";
    }
}


/*
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X                                                                                                                                                               X
X  No algoritmo de Prim comeca do primeiro No inserido e busca o proximo No com menor peso de aresta que esse liga                                              X
X  e adiciona esse No a um vetor chamado arvore.Em seguida o algoritmo de prim  busca o proximo No a ser inserido com menor pseso                               X
X  de aresta entre os nos ja presentes no vetor, por exemplo, se temos dois Nos inseridos no vetor arvore buscaremos a aresta de menor peso                     X
X  em um conjunto que engloba a aresta desses dois nos ,  colocaremos esse No a qual essa aresta liga ao nosso vetor                                            X
X  e o processo repete.Verificamos antes de inserir o novo No se ele vai formar um ciclo com dois Nos ja presentes no vetor arvore atraves da variavel "ciclo". X
X  O processo que verifica qual a menor aresta consiste em rodar um For e  comparar com uma variavel declarada na variavel chamada Menor,                       X
X  caso o peso da aresta seja menor que a variavel "menor" esse valor E substituido pelo peso da aresta,                                                        X
X  e assim tambem guardamoas a aresta em um vetor chamado "arestasArvore" e o No no vetor arvore  que ela liga. acresentando entao o No ao vetor.               X
X                                                                                                                                                               X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
 */
void Grafo::algoritmoPrim()
{
    int posListaAdj = 0;
    int cont = 0;
    arvore.push_back(listaAdj[0]);

    while(arvore.size() != listaAdj.size())
    {

        int menor = INF;
        int idNo = -1;
        int arestaMenor = -1;
        int posNoArvoreMenor = -1; //posicao que está o nó que contem a menor aresta

        //for que roda os nós que já estão na árvore
        int posArvore = 0; // posicao atual da arvore
        for(std::vector<No>::iterator arv = arvore.begin(); arv != arvore.end(); ++arv)
        {

            //loop para ver qual a menor aresta
            int contAresta = 0; //posicao atual da aresta
            for(std::vector<Aresta>::iterator arest = arvore[posArvore].listaAresta.begin(); arest != arvore[posArvore].listaAresta.end(); ++arest)
            {
                // Verifica se é um ciclo ou não
                bool ciclo = false;
                if(arvore.size() > 0)
                {
                    for(std::vector<No>::iterator noArv = arvore.begin(); noArv != arvore.end(); ++noArv)
                    {

                        if(arest->getIdNo() == noArv->getId())
                        {
                            ciclo = true;
                            break;
                        }
                    }
                }
                // Se nao for ciclo, entra neste IF, se for ele apenas troca para a proxima aresta
                if (ciclo == false)
                {

                    if(arest->getPesoAresta() < menor)
                    {
                        menor = arest->getPesoAresta(); //recebe o peso da aresta
                        arestaMenor = contAresta;
                        posNoArvoreMenor = posArvore;
                    }
                }
                contAresta++;
            }
            posArvore++;
        }

        idNo = arvore[posNoArvoreMenor].listaAresta[arestaMenor].getIdNo();
        int i = 0;

        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            if(idNo == it->getId())
            {
                posListaAdj = i;
                arvore.push_back(listaAdj[i]);
                arestasArvore.push_back(arvore[posNoArvoreMenor].listaAresta[arestaMenor]);
                break;
            }
            i++;
        }
        cont++;
    }

    for (std::vector<No>::iterator no = arvore.begin(); no != arvore.end(); ++no)
    {
        cout << no->getId() << "  ";
    }
    cout << endl;

    for (std::vector<Aresta>::iterator aresta = arestasArvore.begin(); aresta != arestasArvore.end(); ++aresta)
    {
        cout << aresta->getIdLista() << " -> " << aresta->getIdNo() << "  ";
    }
    cout<<endl;
}

void Grafo::imprimiGrafo()
{

    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        int j=0;
        std::cout <<" Cor: " << it->getCorNo()<<"  "<< it->getId();
        for(std::vector <Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); arest++,j++)
        {
            std::cout << " -> " << it->listaAresta[j].getIdNo();
        }
        std::cout << std::endl;
    }

}


char Grafo::bucar_label_do_no(int id)
{
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        int id_it = it->getId();
        if(id_it == id)
        {
            return it->getLabel();
        }
    }
}

bool Grafo::ehBipartido()
{

    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        char label = it->getLabel();
        for(std::vector <Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); arest++)
        {
            int id = arest->getIdNo();
            char label_2 = bucar_label_do_no(id);
            if(label_2 == label)
            {
                return false;
            }
        }
    }

    return true;
}

void Grafo::preencher_grafo_bipartido()
{
    bool paridade = true;
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end() ; ++it)
    {
        if(paridade)
        {
            it->setLabel('A');
        }
        else
        {
            it->setLabel('B');
        }
        paridade = !paridade;
    }

}

void Grafo::imprimir_biparticao()
{
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end() ; ++it)
    {
        std::cout<< "-> "<< it->getLabel()<< std::endl;
    }
}

/*
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X                                                                                                                                                               X
X   O algoritmo de busca em profundidade eh um algoritmo recursivo, que faz uma busca  na direçao "vertical", ou seja, ao ser encotrado um nó que nao tem
X   mais nós adjacentes para "baixo" ele retornar para o nó anterior e confere se existe outro no adjacente a esse e que n tenha sido visitado
X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/
void Grafo::auxBuscaEmProfundidade(int key)
{
    No *aux=new No();
    int i=0;
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        it->setVisitado(false);
        if(it->getId()==key)
        {
            aux=(&(listaAdj[i]));
        }
        i++;
    }
    buscaEmProfundidade(aux);
}

void Grafo::buscaEmProfundidade(No *v)
{
    v->setVisitado(true);
    cout<<"Vertice "<< v->getId() <<" visitado"<<endl;
    for(std::vector<Aresta>::iterator arest = v->listaAresta.begin(); arest != v->listaAresta.end(); ++arest)
    {
        int indice = arest->getIndiceNo();

        if(listaAdj[indice].getVisitado()==false)
        {
            buscaEmProfundidade(&(listaAdj[indice]));
            break;
        }
    }
}


void Grafo::buscaEmLargura(int id)

{
    int indiceNo = -1;
    queue<int> fila;

    int i=0;
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if(it->getId()==id)
        {
            indiceNo = i;
        }
        i++;
    }

    fila.push(indiceNo);
    while(!fila.empty())
    {
        indiceNo = fila.front();
        listaAdj[indiceNo].setVisitado(true);
        cout<<"Vertice "<< listaAdj[indiceNo].getId() <<" visitado"<<endl;
        cout<<endl;

        for(std::vector<Aresta>::iterator arest = listaAdj[indiceNo].listaAresta.begin(); arest != listaAdj[indiceNo].listaAresta.end(); ++arest)
        {

            if(listaAdj[arest->getIndiceNo()].getVisitado()==false)
            {
                fila.push(arest->getIndiceNo());
            }

        }
        fila.pop();
    }

}

/** Funcao auxiliar utilizada pela compConexa();
*/

void Grafo::buscaConexaUtil(int u, bool visitado[])
{
    // Marca e mostra o no atual visitado
    visitado[u] = true;
    cout << u << " ";

    // Percorre todos os nos adjacentes ao no atual
    for(std::vector<Aresta>::iterator arest = listaAdj[u].listaAresta.begin(); arest != listaAdj[u].listaAresta.end(); ++arest)
    {
        int i = arest->getIndiceNo();
        if(!visitado[i])
            buscaConexaUtil(i,visitado);


    }
}

/** Funcao utilizada para encontrar a componente conexa
*/

void Grafo::compConexa()
{
    if(ehdigrafo()==1)
        cout << "Utilize a funcao compFortConexa() para grafos direcionados";

    else
    {
        // Marca todos os vertices como nao visitados
        bool *visitado = new bool[listaAdj.size()];
        for(int i=0; i < listaAdj.size(); i++)
            visitado[i] = false;
        for(int i=0; i < listaAdj.size(); i++)
        {
            if(visitado[i] == false)
            {
                // Mostra todos os vertices alcancaveis
                buscaConexaUtil(i, visitado);
                cout << "\n";
            }
        }
    }
}
/**
       Uma funcao recursiva utilizada para encontra a componente fortemente conexa
       utilizado a busca em profundidade
       u -> O no a ser visitado
       dem[] --> Guarda as vezes que os nos foram visitados
       low[] --> o no menos visitado que pode ser alcancado pela
       subarvore com o no atual
       membro --> Guarda todos nos anteriores que estao conectado
       (pode ser parte da componente fortemente conexa)
       verificaMembro[] --> Um vetor utilizado para checar mais
       rapidamente se o no esta na pilha
**/

void Grafo::fortConexaUtil(int u, int dem[], int low[], stack<int> *membro, bool *verificaMembro)
{
    // Variavel estatica utilizada para facilitar ao inves de utilizar ponteiro
    static int time = 0;
    //Inicializa o tempo de descoberta e o valor low
    dem[u] = low[u] = ++time;
    membro->push(u);
    verificaMembro[u] = true;

    // Percorre todos os nos adjacentes ao no atual
    for(std::vector<Aresta>::iterator arest = listaAdj[u].listaAresta.begin(); arest != listaAdj[u].listaAresta.end(); ++arest)
    {
        int i = arest->getIndiceNo();

        // Se i nao foi visitado entao ira chamar novamente a funcao
        if(dem[i] == -1)
        {
            fortConexaUtil(i, dem, low, membro, verificaMembro);
            /* Checa se a subarvore enraizada a 'i', tem conexao
               com algum dos nos anteriores a 'u'
            */
            low[u] = min(low[u], low[i]);
        }
        /*  Atualiza o valor low de 'u' somente se 'i' ainda esta na pilha
                , ou seja, eh uma aresta de saida ao inves de uma aresta externa.
            */
        else if(verificaMembro[i] == true)
            low[u] = min(low[u], dem[i]);
    }
    // No encontrando, utiliza a funcao pop da pilha e mostra a componente fortemente conexa
    // Variavel utilizada para guardar os nos que foram tirados da pilha
    int aux = 0;
    if(low[u] == dem[u])
    {
        while(membro->top() != u)
        {
            aux = (int) membro->top();
            cout << aux << " ";
            verificaMembro[aux] =  false;
            membro->pop();
        }
        aux = (int)membro->top();
        cout << aux << "\n";
        verificaMembro[aux] = false;
        membro->pop();
    }
}
/** Funcao que faz uma busca em profundidade. Utiliza fortConexaUtil()
*/

void Grafo::fortConexa()
{
    if(ehdigrafo()==0)
        cout << "Nao eh possivel encontrar componente fortemente conexa num grafo nao direcionado" << endl;

    else
    {
        int *dem = new int[listaAdj.size()];
        int *low = new int[listaAdj.size()];
        bool *verificaMembro = new bool[listaAdj.size()];
        stack<int> *membro = new stack<int>();

        // Inicializa variaveis
        for(int i = 0; i < listaAdj.size(); i++)
        {
            dem[i] = -1;
            low[i] = -1;
            verificaMembro[i] = false;
        }
        /* Chama a funcao auxiliar recursiva para encontrar
           as componentes conexas
        */
        for(int i = 0; i < listaAdj.size(); i++)
            if(dem[i]==-1)
                fortConexaUtil(i, dem, low, membro, verificaMembro);

    }
}

/**
    Funcao auxiliar para verificar se tem ciclo
*/
bool Grafo::buscaUtil(int u, int cor[])
{
    // Colore como 1 para mostrar que o vertice
    // esta sendo processado (a busca em profundidade
    // começou mas não acabou.
    cor[u] = 1;
    // Percorre todos os adjacentes
    for(std::vector<Aresta>::iterator arest = listaAdj[u].listaAresta.begin(); arest != listaAdj[u].listaAresta.end(); ++arest)
    {
        int v = arest->getIndiceNo(); // Nó adjacente a u
        //Se v ja foi visitado
        if(cor[v] == 1)
            return true;
        //Se v não foi visitado e tem um aresta de saida
        if(cor[v] == 0 && buscaUtil(v, cor))
            return true;
    }
    // Colore como 2 para mostrar que foi processado
    cor[u] = 2;
    return false;
}
/**
    Funcao que verifica se tem ciclo no grafo.
    Retorna true se ha um ciclo.
*/
bool Grafo::temCiclo()
{
    // Inicializa todos as cores de todos vertices como -1
    int *cor = new int[listaAdj.size()];
    for(int i = 0; i != listaAdj.size(); i++)
    {
        cor[i] = 0;
    }
    //Faz uma busca em profundidade com todos os vertices
    for(int i= 0; i != listaAdj.size(); i++)
    {
        if(cor[i]== 0)
            if(buscaUtil(i, cor) == true)
                return true;
    }
    return false;
}
/**
    Funcao recursiva utilizada pela Ordenaçao Topologica.
*/
void Grafo::ordTopologicaUtil(int v, bool visitado[], stack<int> &pilha)
{
    // Marca o no atual como visitado
    visitado[v] = true;
    // Percorre todos os nos adjacentes a esse no
    for(std::vector<Aresta>::iterator arest = listaAdj[v].listaAresta.begin(); arest != listaAdj[v].listaAresta.end(); ++arest)
    {
        int i = arest->getIndiceNo();
        if(!visitado[i])
            ordTopologicaUtil(i, visitado, pilha);
    }
    // Coloca o no atual na pilha para guardar o resultado
    pilha.push(v);
}




/**
    Funcao para fazer a Ordenacao Topologica.
    Ela utiliza a funcao auxiliar OrdenacaoTopologicaUtil.
*/
void Grafo::ordenacaoTopologica()
{
    if(temCiclo()==true)
    {
        cout << "Nao eh possivel fazer uma ordenacao topologica pois o grafo possui pelo menos um ciclo";
    }
    else
    {
        stack<int> pilha; //pilha para armazenar o indice dos nós
        //Marca todos os vertices como nao visitados
        bool *visitado = new bool[listaAdj.size()];
        for (int i = 0; i != listaAdj.size(); i++)
        {
            visitado[i]= false;
        }
        // Chama a funcao auxiliar recursiva
        // para guardar a ordenacao topologica
        // de todos os vertices, um por um
        for (int i= 0; i!=listaAdj.size(); i++)
        {
            if(visitado[i] == false)
                ordTopologicaUtil(i, visitado, pilha);
        }
        // Imprime o conteudo da pilha
        while (pilha.empty() == false)
        {
            cout << listaAdj[pilha.top()].getId() << " ";
            pilha.pop();
        }
    }
}

/*
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X                                                                                                                                                               X
X  O algoritmo de Kruskal,sendo um grafo conexo, ponderado e nao direcionado, tem como objetivo encontrar um subconjunto das arestas que forma uma árvore que   X
X  inclui todos os vértices, onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado. No algoritmo abaixo inicialmente foi criado uma   X
X  floresta onde cada vertice eh uma arvore independente, representado de forma como o pai de cada vertice eh o proprio vertice e o Rank de todos os vertice    X
X   eh inicializado com 0. O passo seguinte foi colocar todas as arestas em um unico vetor, e entao ordernar-lo em ordem crescente de acordo com o peso da      X
X   aresta,esta ordenacao eh feita por meio do Quick Sort. Apos isso foi colocado um FOR para rodar o vector de aresta, no algoritmo abaixo representado com o  X
X   nome "pesoArestas". Para cada aresta recuperada do vector, pegamos os vertices de origem e de destino da mesma e mandamos por paramentro de uma funcao      X
X   auxiliar que chama "busca_kruskal" que tem como objetivo busca e retornar o subconjunto de determinado vertice informado por parametro.Com o subconjunto    X
X   do vertice de origem e do vertice de destino em maos agora comparamos se sao diferentes , caso sejam, significa que nao estao no mesmo subconjunto e,       X
X   portanto, nao temos ciclos.Dessa forma, agora inserimos esta aresta em questao no vector "arvoreKruskal" que e aonde estarao armazenadas todas a arestas da X
X   arvore geradora minima do grafo.Por ultimo , mas nao menos importante, utilizamos outra funcao auxiliar "uniao_krukal" que tem como objetivo unir o vertice X
X   de origem e de destino em um mesmo subconjunto independente.Ao final voltamos ao FOR , pegamos outra aresta, faz-se o mesmo procedimento ate o final do     X
X   vector de arestas.                                                                                                                                          X
X                                                                                                                                                               X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
 */
No* Grafo::busca_kruskal(No *v)//funcao que busca e retorna o subconjunto de um determinado vertice informado por parametro
{
    if(v->getPai() == v)
        return v;
    return busca_kruskal(v->getPai());
}

void Grafo::uniao_kruskal(No *v1,No *v2)//funcao para unir 2 subconjuntos de vertices em um unico subconjuto
{
    if(v1->getRank() > v2->getRank())
        v2->setPai(v1);
    else if(v2->getRank() > v1->getRank())
        v1->setPai(v2);
    else
    {
        v2->setPai(v1);
        v1->incrementaRank();
    }

}

void Grafo::algoritmoKruskal()
{
    int k=0;
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        it->setPai(&listaAdj[k]);//criar uma sub-arvore independente para cada no do grafo
        it->setRank(0);          //sendo o pai o proprio vertice e o Rank sendo 0
        k++;
    }

    int i=0;
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        int j=0;
        for(std::vector<Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); ++arest)
        {
            pesoArestas.push_back(it->listaAresta[j]);//colocando todas as arestas em um unico vetor
            j++;
        }
        i++;
    }

    quickSortKruskal(0,pesoArestas.size()-1);//ordenando o vetor de arestas na ordem crescente de acordo com seu peso

    int l=0;
    for(std::vector<Aresta>::iterator it = pesoArestas.begin(); it != pesoArestas.end(); ++it)
    {
        No *v1=busca_kruskal(&listaAdj[it->getIndiceLista()]);//busca do subconjunto do vertice de origem de uma aresta
        No *v2=busca_kruskal(&listaAdj[it->getIndiceNo()]);//busca do subconjunto do vertice de destino de uma aresta

        if(v1 != v2)// se os subconjuntos de v1 e v2 forem diferentes significa que nao ha ciclo , entao
        {
            arvoreKruskal.push_back(pesoArestas[l]);//insere no vetor de arestas da arvore geradora minima
            uniao_kruskal(v1,v2);//faz a uniao de v1 e v2 em um mesmo subconjunto
        }
        l++;
    }

    int soma=0;
    cout<<"Arvore Geradora Minima - KRUSKAL"<<endl;
    cout<<"|No Origem|"<<"  |No destino|"<<"  |Peso Aresta|"<<endl;
    for(std::vector<Aresta>::iterator it = arvoreKruskal.begin(); it != arvoreKruskal.end(); ++it)
    {
        soma+=it->getPesoAresta();
        cout<<"     "<<it->getIdLista()<<" ----------- "<<it->getIdNo()<<"     ==>    "<<it->getPesoAresta()<<endl;
    }
    cout<<"                           -----------"<<endl;
    cout<<"      Custo Minimo       ==>    "<<soma<<endl;
}

int Grafo::quickPartitionKruskal(int left, int right)//ordenacao de um vetor de arestas em ordem crescente de acordo com o peso
{

    int pivo = pesoArestas[right].getPesoAresta();
    int i = (left - 1);

    for(int j=left ; j <= right-1 ; j++)
    {
        if( pesoArestas[j].getPesoAresta() <= pivo)
        {
            i++;
            trocaKruskal(i, j);
        }
    }
    trocaKruskal(i+1, right);
    return i+1;
}

void Grafo::quickSortKruskal(int left,int right)//ordenacao de um vetor de arestas em ordem crescente de acordo com o peso
{
    if( left < right)
    {
        int pi = quickPartitionKruskal(left, right);

        quickSortKruskal(left, pi-1);
        quickSortKruskal(pi+1, right);
    }
}

void Grafo::trocaKruskal(int x1, int x2)//ordenacao de um vetor de arestas em ordem crescente de acordo com o peso
{
    if(x1 != x2)
    {
        Aresta *aux = new Aresta();
        *aux = pesoArestas[x1];
        pesoArestas[x1] = pesoArestas[x2];
        pesoArestas[x2] = *aux;
    }
}


/**
        Algoritmo Guloso para Coloração de Vértices.

*/
int Grafo::algoritmoGuloso()
{
    ordenado.clear();
    auxOrdena.clear();
    double tInicio = clock();
    int i = 0;
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        it->setCorNo(-1);           // Coloca as cores de todos os nos como -1
        ordenado.push_back(i);      // Manda a posicao de todos os nós na listaAdj para o vetor ordenado
        i++;
    }


    auxOrdena = listaAdj;

    quickSort(0,listaAdj.size()-1);         // Ordena o vetor em ordem descrecente em relacao ao grau.



    int k = 0;                              // O maximo de cor no momento.

    listaAdj[ordenado[0]].setCorNo(k);      // Pega o primeiro vertice com maior No e adiciona a primeira cor a ele.


    for(std::vector<Aresta>::iterator arest = listaAdj[ordenado[0]].listaAresta.begin(); arest != listaAdj[ordenado[0]].listaAresta.end(); ++arest)
    {
        listaAdj[arest->getIndiceNo()].addCorAdj(k);        // Adiciona k no vetor de cores adjacentes de todos os nós adjacentes ao primeiro no.
    }
    k++;                                                    // Atualiza k.

    for(int j=1; j < ordenado.size() ; j++)                 // Pega os próximos nós de acordo com a ordem decrescente em reaçao ao grau.
    {
        int pos = ordenado[j];                              // Var pos que pega qual o indice da listaAdj fica o nó.

        for(int i=0; i<=k ; i++)                            // For que roda todas as cores que existem até o momento.
        {

            bool flag = false;
            if(i<k)                                         // Se i = k entao nenhum nó adjacente a ele tem cor k, assim a cor dele sera k e nao é preciso checar suas cores adjacentes.
            {
                for(int corAdjacente = 0; corAdjacente < listaAdj[pos].corAdj.size(); corAdjacente++)       // For que roda todas as cores que sao adjacentes ao nó, pelo vetor corAdjacente que pertence ao nó.
                {
                    if(listaAdj[pos].corAdj[corAdjacente] == i)
                    {
                        flag = true;                                          // Var flag recebe true se existe a cor i no vetor de corAdjacente do nó, e assim passa para a próxima cor.
                        break;
                    }
                }
            }
            /* Se a Var flag for falsa, entao temos que aquele indice de cor nao está sendo
               utilizada por nenhum nó adjacente, portanto pode ser dada a esse nó, e para
               isso, é necessario verificar se a cor i é uma cor que ja foi utilizada antes
               ou é uma cor nova (o que implica que o nó é adjacente a todas as cores já
               utilizadas), sendo assim necessário atualizar a variavel k, com uma cor nova.
            */
            if(flag == false && i < k)                                   // Cor i já existe.
            {
                listaAdj[pos].setCorNo(i);
                for(std::vector<Aresta>::iterator arest = listaAdj[pos].listaAresta.begin(); arest != listaAdj[pos].listaAresta.end(); ++arest)
                {
                    listaAdj[arest->getIndiceNo()].addCorAdj(i);         // Adiciona k no vetor de cores adjacentes de todos os nós adjacentes ao no.
                }
                break;
            }
            else if(flag == false && i==k)                               // Cor i não existe.
            {
                listaAdj[pos].setCorNo(i);
                for(std::vector<Aresta>::iterator arest = listaAdj[pos].listaAresta.begin(); arest != listaAdj[pos].listaAresta.end(); ++arest)
                {
                    listaAdj[arest->getIndiceNo()].addCorAdj(i);         // Adiciona k no vetor de cores adjacentes de todos os nós adjacentes ao no.
                }
                k++;                                                     // Atualiza k com nova cor
                break;
            }
        }
    }

        double tFinal = clock();
        double tDecorrido = ((double)(tFinal - tInicio))/CLOCKS_PER_SEC;
        cout << "Tempo decorrido: " << tDecorrido <<" segundos" << endl;

    return k;                                                            // Retorna o numero k-coloravel do grafo.
}



void Grafo::auxGulosoRandomizado()
{
    algoritmoGulosoRandomizado(0.1,30);
    algoritmoGulosoRandomizado(0.2,30);
    algoritmoGulosoRandomizado(0.3,30);
}

void Grafo::algoritmoGulosoRandomizado(float alfa, int intMax)
{
    cout<<"Valor de alpha :"<< alfa <<endl;
    ordenado.clear();
    auxOrdena.clear();
    double tMedio=0;
    int solucoes[intMax];
    int mediaSolucao=0;
    int i = 0;
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        it->setCorNo(-1);           // Coloca as cores de todos os nos como -1
        ordenado.push_back(i);      // Manda a posicao de todos os nós na listaAdj para o vetor ordenado
        i++;
    }
    auxOrdena = listaAdj;
    quickSort(0, listaAdj.size()-1);

    srand(time(NULL));

    std::vector <int> posCandidatos;
    int melhorSolucao = 9999;

    int aux = 0;
    int j = 0;
    i=0;
    double tInicio=clock();

    while(i < intMax)
    {
        posCandidatos = ordenado;
        for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            it->setCorNo(-1);           // Coloca as cores de todos os nos como -1
            it->corAdj.clear();         // Apaga as cores do vetor corAdj de cada no.
        }
        int k = 0;
        while(posCandidatos.size() != 0)
        {

            int aux = ceil(posCandidatos.size() * alfa);


            int j = rand() % aux;

            int pos = posCandidatos[j];


            for(int i=0; i<=k ; i++)                            // For que roda todas as cores que existem até o momento.
            {

                bool flag = false;
                if(i<k)                                         // Se i = k entao nenhum nó adjacente a ele tem cor k, assim a cor dele sera k e nao é preciso checar suas cores adjacentes.
                {
                    for(int corAdjacente = 0; corAdjacente < listaAdj[pos].corAdj.size(); corAdjacente++)       // For que roda todas as cores que sao adjacentes ao nó, pelo vetor corAdjacente que pertence ao nó.
                    {
                        if(listaAdj[pos].corAdj[corAdjacente] == i)
                        {
                            flag = true;                                          // Var flag recebe true se existe a cor i no vetor de corAdjacente do nó, e assim passa para a próxima cor.
                            break;
                        }
                    }
                }

                /* Se a var flag for falsa, entao temos que aquele indice de cor nao está sendo
                   utilizada por nenhum nó adjacente, portanto pode ser dada a esse nó, e para
                   isso, é necessario verificar se a cor i é uma cor que ja foi utilizada antes
                   ou é uma cor nova (o que implica que o nó é adjacente a todas as cores já
                   utilizadas), sendo assim necessário atualizar a variavel k, com uma cor nova.
                */
                if(flag == false && i < k)                                   // Cor i já existe.
                {
                    listaAdj[pos].setCorNo(i);
                    for(std::vector<Aresta>::iterator arest = listaAdj[pos].listaAresta.begin(); arest != listaAdj[pos].listaAresta.end(); ++arest)
                    {
                        if(listaAdj[arest->getIndiceNo()].getCorNo() == -1 )
                            listaAdj[arest->getIndiceNo()].addCorAdj(i);   // Adiciona k no vetor de cores adjacentes de todos os nós adjacentes ao no.
                    }
                    break;
                }
                else if(flag == false && i==k)                               // Cor i não existe.
                {
                    listaAdj[pos].setCorNo(i);
                    for(std::vector<Aresta>::iterator arest = listaAdj[pos].listaAresta.begin(); arest != listaAdj[pos].listaAresta.end(); ++arest)
                    {
                        if(listaAdj[arest->getIndiceNo()].getCorNo() == -1)
                            listaAdj[arest->getIndiceNo()].addCorAdj(i);   // Adiciona k no vetor de cores adjacentes de todos os nós adjacentes ao no.
                    }
                    k++;                                                     // Atualiza k com nova cor
                    break;
                }
            }

            double tFinal = clock();

            double tDecorrido = ((double)(tFinal - tInicio))/CLOCKS_PER_SEC;
            tMedio += tDecorrido;
            posCandidatos.erase(posCandidatos.begin()+j);

        }

        if(k < melhorSolucao)
        {
            melhorSolucao = k;
        }
        solucoes[i]=k;
        mediaSolucao += k;
        posCandidatos.clear();
        cout<<"Solucao "<<i<<" : " <<k<<endl;
        i++;
    }
    mediaSolucao = mediaSolucao / intMax;
    tMedio = tMedio / intMax;
    float desvioPadrao = 0;
    for(int s=0; s < intMax ; s++)
    {
        desvioPadrao += pow((solucoes[s]-mediaSolucao),2);
    }
    desvioPadrao = sqrt(desvioPadrao / intMax);


    cout<< "A melhor solucao de cores: " << melhorSolucao <<endl;
    cout<< "A solucao media de cores: " << mediaSolucao <<endl;
    cout<< "Desvio padrao: " << desvioPadrao <<endl;
    cout << "Tempo decorrido: " << tMedio <<" segundos" << endl<<endl;

}


/**
        Realiza o quickSort para fazer com que os nós do vector auxOrdena
        e os inteiros do vector ordenada fiquem em ordem decrescente em
        relaçao ao grau. Utiliza-se as tres funções quickPartition, Quick
        Sort e troca.
*/
int Grafo::quickPartition(int left, int right)
{
    int pivo = auxOrdena[right].getGrauSaida();
    int i = (left - 1);

    for(int j=left ; j <= right-1 ; j++)
    {
        if( auxOrdena[j].getGrauSaida() >= pivo)
        {
            i++;
            troca(i, j);
        }
    }
    troca(i+1, right);
    return i+1;
}

void Grafo::quickSort(int left,int right)
{
    if( left < right)
    {
        int pi = quickPartition(left, right);

        quickSort(left, pi-1);
        quickSort(pi+1, right);
    }
}

void Grafo::troca(int x1, int x2)
{
    if(x1 != x2)
    {
        No *aux = new No();
        *aux = auxOrdena[x1];
        auxOrdena[x1] = auxOrdena[x2];
        auxOrdena[x2] = *aux;

        int auxiliar = 0;
        auxiliar = ordenado[x1];
        ordenado[x1] = ordenado[x2];
        ordenado[x2] = auxiliar;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  ALGORITMO FLOYD                                                                                                 /
// O algoritmo de floyd serve para calcular a menar distancia entre todos pares de vertices em um grafo ponderado   //
// e direcionado,armazenando eles em uma matriz.No codigo abaixo iniciamos todos os valores com um int INF para     //
//representar o valor infinito.A matriz mostra o caminho mais curto de cada vertice,representado por                //
//cada posicao, VET[1][2] por exemplo é o menor caminho do vertice 1 para o vertice 2.                              //
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//

void Grafo::algoritmoFloyd()
{
    if(ehdigrafo()==1&&ehponderada()==1)
    {

        int i,j;
        int tam =listaAdj.size();

        int vet1[tam][tam];

        for(int i=0; i<tam; i++)
            for(int j=0; j<tam; j++)
                vet1[i][j]=INF;

        for(int i=0; i<tam; i++)
        {
            for(j=0; j<tam; j++)
            {
                if(i==j)
                    vet1[i][j]=0;

            }

            for(int i=0; i<tam; i++)
            {
                for(int j=0; j<tam; j++)
                {

                    // cout<<"IDNO="<< no->getId();

                    for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest)
                    {
                        if(i!=j)
                        {

                            if(arest->getIdNo() == listaAdj[j].getId() && arest->getPesoAresta()<vet1[i][j])
                            {

                                // cout<<"\ni="<<i<<"j="<<j;
                                // cout<<"   vetIeJ="<<vet1[i][j]<<"\n";
                                vet1[i][j]=arest->getPesoAresta();
                                //   cout<<"\n"<<arest->getPesoAresta();
                                break;
                            }

                        }
                    }
                }


            }





        }
        for(int i=0; i<tam; i++)
        {
            for(int j=0; j<tam; j++)
            {
                for(int k=0; k<tam; k++)
                {
                    if(vet1[i][k]+vet1[k][j]<vet1[i][j])
                        vet1[i][j]=vet1[i][k]+vet1[k][j];



                }


            }
        }




        for(int i=0; i<listaAdj.size(); i++)
        {
            cout<<"\n";
            for(int j=0; j<listaAdj.size(); j++)
            {
                cout<<listaAdj[i].getId()<<"i"<<listaAdj[j].getId()<<"j"<<"="<<vet1[i][j]<<"\t";
            }
        }



    }







}

///////////////////////////////////////////////////////////////////////////////////////////////////
//DIJKSTRA                                                                                       //
// O algoritmo de Dijkstra calcula o caminho de menor custo entre os nós de um grafo.     //
//Um vértice de origem é escolhido,dai o algoritmo calcula o custo mínimo do vértoce de origem   //
//para todos outros vértices do grafo.                                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////

void Grafo::dijkstra(int id)
{



    queue<int>fila;

    int distancia[listaAdj.size()];

    int i=0;
    int indiceNoOrigem=-1;
    //loop para achar o indice do ID no vetor de vertices
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)//percorre a lista procurando o indice do no de origem na lista adjascente
    {

        distancia[i]=999999;
        if(it->getId()==id)
        {
            indiceNoOrigem = i;
        }
        i++;


    }
    int menor=999999;
    distancia[indiceNoOrigem]=0;
    int indice;
    fila.push(indiceNoOrigem);
    listaAdj[indiceNoOrigem].setVisitado(true);
    while(!fila.empty())
    {

        fila.pop();
        if(menor!=999999)
            menor=999999;
        //loop que percorre o no de menor distancia e atribui a distancia para todos nos adjacentes a ele
        for(std::vector<Aresta>::iterator arest = listaAdj[indiceNoOrigem].listaAresta.begin(); arest != listaAdj[indiceNoOrigem].listaAresta.end(); ++arest)
        {
            if(arest->getPesoAresta()<0)
            {
                cout<<"DIJKSTRA NAO ACEITA ARESTAS COM VALORES NEGATIVOS"<<endl;
                    exit(0);
            }
            if(distancia[arest->getIndiceNo()]!=distancia[indiceNoOrigem])
            {


                if(!listaAdj[arest->getIndiceNo()].getVisitado())
                {



                    if(distancia[arest->getIndiceNo()]>distancia[indiceNoOrigem]+arest->getPesoAresta())
                    {

                        distancia[arest->getIndiceNo()]=distancia[indiceNoOrigem]+arest->getPesoAresta();

                    }
                    else if(distancia[arest->getIndiceNo()]==arest->getPesoAresta())
                    {
                        distancia[arest->getIndiceNo()]+=distancia[indiceNoOrigem];
                    }

                    //guarda o indice do no de menor aresta
                    if(arest->getPesoAresta()<menor)
                    {
                        menor=arest->getPesoAresta();
                        indice=arest->getIndiceNo();
                    }
                }
            }
            //loop que percorre todos os nos adjacentes dos nos adjacentes ao no de menor distancia
            for(std::vector<Aresta>::iterator arest2 = listaAdj[arest->getIndiceNo()].listaAresta.begin(); arest2 != listaAdj[arest->getIndiceNo()].listaAresta.end(); ++arest2)
            {
                if(arest2->getPesoAresta()<0)
                {
                    cout<<"DIJKSTRA NAO ACEITA ARESTAS COM VALORES NEGATIVOS"<<endl;
                        exit(0);
                }
                if(indiceNoOrigem!=arest2->getIndiceNo())
                {




                    if(!listaAdj[arest2->getIndiceNo()].getVisitado())
                    {
                        if(distancia[arest->getIndiceNo()]!=distancia[arest2->getIndiceNo()])
                        {



                            if(distancia[arest2->getIndiceNo()]>distancia[arest->getIndiceNo()]+arest2->getPesoAresta())
                            {

                                distancia[arest2->getIndiceNo()]=distancia[arest->getIndiceNo()]+arest2->getPesoAresta();
                            }
                            else if(distancia[arest2->getIndiceNo()]==arest2->getPesoAresta())
                            {
                                distancia[arest2->getIndiceNo()]+=distancia[arest->getIndiceNo()];
                            }


                        }

                    }
                }

            }




        }
        //bota na fila o no de menor indice e marca ele como visitado
        if(!listaAdj[indice].getVisitado())
        {

            indiceNoOrigem=indice;
            fila.push(indiceNoOrigem);
            listaAdj[indice].setVisitado(true);

        }
    }
    cout<<"VERTICE"<<" "<<" DISTANCIA DA ORIGEM"<<endl;
    for(int i=0; i<listaAdj.size(); i++)
    {

        cout<<listaAdj[i].getId()<<"\t \t"<<distancia[i]<<endl;
    }



}










