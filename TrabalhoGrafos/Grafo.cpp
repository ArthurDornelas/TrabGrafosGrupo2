#include "Grafo.h"
#include "No.h"
#include "No.cpp"
#include <vector>
#include <set>
#include <iterator>
#include <list>
#include <algorithm>
#include <cstring>
#define INF 9999999
#include <stack> // busca em profundidade
#include<queue>
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
                listaAdj[k].adicionaArestaSemPeso(id2,id,l);
                listaAdj[l].adicionaArestaSemPeso(id,id2,k);
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
                listaAdj[k].adicionaArestaSemPeso(id2,id,l);
                break;
            }

            i++;
        }

    }


    imprimiGrafo();

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
                listaAdj[k].adicionaAresta(id2,peso,id,l);
                listaAdj[l].adicionaAresta(id,peso,id2,k);
                break;
            }

            i++;
        }

    }

    else if((id1_noGrafo==true && id2_noGrafo==true) && ehDigrafo==1)
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
                listaAdj[k].adicionaAresta(id2,peso,id,l);
                break;
            }

            i++;
        }

    }

    imprimiGrafo();

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

/* Nao terminado
bool Grafo::bipartido()
{
    int numNo = listaNos.size();
    int selecionaVert[numNo+1];
    for (int i = 1; i <= numNo; ++i)
        selecionaVert[i] = -1;

    //O loop faz uma busca em largura, e tenta selecionar 2 grupos, provando a bipartilidade.
    for (int i = 1; i <= V; i++)
      if (selecionaVert[i] == -1)
        if (tenta2ColorirGrafo(i, selecionaVert) == false)
           return false;

     return true;

}
*/

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

void Grafo::lerDigrafo(string caminho)
{
    ifstream arquivo;
    int id_no_1, id_no_2;
    float peso_aresta;
    arquivo.open(caminho.c_str());
    if (arquivo.is_open())
    {
        while(arquivo >> id_no_1 >> id_no_2 >> peso_aresta)
        {

            if( !this->estaNoGrafo(id_no_1) )
            {
                this->adicionarNo(id_no_1);
            }
            if( !this->estaNoGrafo(id_no_2) )
            {
                this->adicionarNo(id_no_2);
            }
            this->adicionarArestaNos(id_no_1, id_no_2, peso_aresta);

        }
    }
    arquivo.close();
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

/** Funcao auxilia utilizada pela compConexa();

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


    else {
    // Marca todos os vertices como nao visitados
    bool *visitado = new bool[listaAdj.size()];
    for(int i=0; i < listaAdj.size(); i++)
    {
        visitado[i] = false;
    }

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

*/
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

        // Se i nao foi visitado entao ira recorrer
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
    int aux = 0; // Variavel utilizada para guardar os nos que foram tirados da pilha
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
        cout << "Nao eh possivel encontrar componente fortemente conexa num grafo direcionado" << endl;

    else {
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

        stack<int> pilha; //pilha para armazenar os Indices do Nós

        //Marca todos os vertices como nao visitados
        bool *visitado = new bool[listaAdj.size()];
        for (int i = 0; i != listaAdj.size(); i++)
        {
            visitado[i]= false;
        }

        // Chama a funcao auxiliar recursiva
        // para guardar a ordem topologica
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

int Grafo::algoritmoGuloso()
{
    //Coloca as cores de todos os nos como -1
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        it->setCorNo(-1);
    }

    //Ordena o vetor em ordem descrecente em relacao ao grau
    quickSort(0,listaAdj.size()-1);

    int k = 0; //o maximo de cor no momento

    //Pega o primeiro vertice com maior No e adiciona a primeira cor a ele.
    listaAdj[0].setCorNo(k);
    //Adiciona k no vetor de cores adjacentes de todos os nós adjacentes ao primeiro no.
    for(std::vector<Aresta>::iterator arest = listaAdj[0].listaAresta.begin(); arest != listaAdj[0].listaAresta.end(); ++arest)
    {
        listaAdj[arest->getIndiceNo()].addCorAdj(k);
    }
    k++;

    for(std::vector<No>::iterator it = listaAdj.begin()+1; it != listaAdj.end(); ++it)
    {

        for(int i=0; i<=k ; i++)
        {

            bool flag = false;
            for(int corAdjacente = 0; corAdjacente < it->corAdj.size(); corAdjacente++)
            {
                if(it->corAdj[corAdjacente] == i)
                {
                    flag = true;
                    break;
                }
            }

            if(flag == false && i < k)
            {
                it->setCorNo(i);
                for(std::vector<Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); ++arest)
                {
                    listaAdj[arest->getIndiceNo()].addCorAdj(i);
                }
                break;
            }
            else if(flag == false && i==k)
            {
                it->setCorNo(i);
                for(std::vector<Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); ++arest)
                {
                    listaAdj[arest->getIndiceNo()].addCorAdj(i);
                }
                k++; // atualiza k com nova cor
                break;
            }
        }
    }

    return k;
}

//////////////////////////////////////////////////////////////////////////
int Grafo::quickPartition(int left, int right)
{
    int pivo = listaAdj[right].getGrauSaida();
    int i = (left - 1);

    for(int j=left ; j <= right-1 ; j++)
    {
        if( listaAdj[j].getGrauSaida() >= pivo)
        {
            i++;
            troca(i, j);
        }
    }
    troca(i+1, right);
    //  for(std::vector<Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); ++arest)//
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
        *aux = listaAdj[x1];
        listaAdj[x1] = listaAdj[x2];
        listaAdj[x2] = *aux;
    }
}
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
                cout<<"\t"<<listaAdj[i].getId()<<listaAdj[j].getId()<<"="<<vet1[i][j];
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
    //vetor distancia que armazena os valores das distancias dos nos para o no de origem
    int distancia[listaAdj.size()];
    bool negativo=1;
    int indiceNo = -1;

    //verifica se existe alguma aresta com peso negativo
    for(int j=0; j<listaAdj.size(); j++)
        for(std::vector<Aresta>::iterator arest = listaAdj[j].listaAresta.begin(); arest != listaAdj[j].listaAresta.end(); ++arest)
            if(arest->getPesoAresta()<0)
            {
                cout<<"DIJKSTRA PRECISA DE ARESTAS COM PESO POSITIVO"<<endl;
                    negativo=0;
                    exit(0);
            }
    //verifica se existem arestas com peso negativo
    if(negativo)
    {
        int i=0;
        //procura o indice do ID do no de origem
        for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            distancia[i]=999999;
            //condicao para achar o indice do no de origem
            if(it->getId()==id)
            {
                indiceNo = i;
            }
            i++;
        }

        //distancia da origem para ela mesma eh 0
        distancia[indiceNo]=0;
        int copia=indiceNo;


        //percorre a lista de aresta do no de origem e atribui a distancia de cada no como seu peso de sua aresta
        for(std::vector<Aresta>::iterator arest = listaAdj[indiceNo].listaAresta.begin(); arest != listaAdj[indiceNo].listaAresta.end(); ++arest)
        {


            //verifica se a distancia do no de origem eh menor que a do no que a aresta esta ligando
            if(distancia[indiceNo]<(distancia[arest->getIndiceNo()]))
            {

                distancia[arest->getIndiceNo()]=distancia[indiceNo]+arest->getPesoAresta();
            }



        }

        //percorre a lista adjacente de nos exceto o no de origem
        for(int j=0; j<listaAdj.size(); j++)
        {
            if(j!=copia)
            {

                //for percorre a lista de aresta de cada no da lista adjacente e compara as distancias
                for(std::vector<Aresta>::iterator arest = listaAdj[j].listaAresta.begin(); arest != listaAdj[j].listaAresta.end(); ++arest)
                {


                    //compara se a distancia do no na lista adjacente eh menor que o no que a aresta esta ligando
                    //todas distancias precisam ser diferentes. Caso n forem elas permanecem a mesma.
                    if(distancia[j]<(distancia[arest->getIndiceNo()])&&distancia[j]!=distancia[arest->getIndiceNo()])
                    {
                        //verifica se a distancia do no apontado seja diferente de infinito e menor que a distancia do no de origem
                        if(distancia[j]<distancia[arest->getIndiceNo()]&&distancia[arest->getIndiceNo()]!=999999&&distancia[j]!=distancia[arest->getIndiceNo()])
                        {
                            //caso nao seja infinito, a distancia do no apontado apenas adiciona com a distancia do no de origem
                            if(distancia[j]+arest->getPesoAresta()!=distancia[arest->getIndiceNo()])
                            {

                                distancia[arest->getIndiceNo()]+=distancia[j];
                            }

                        }
                        //condicao se a disntancia do no quea aresta esta indo seja menor que a distancia do no de origem
                        else
                        {

                            distancia[arest->getIndiceNo()]=distancia[j]+arest->getPesoAresta();
                        }



                    }
                    //condicao para a distancia do no que a aresta esta ligando seja menor que a distancia do no da lista adjacente
                    else if(distancia[j]!=distancia[arest->getIndiceNo()])
                    {
                        if(distancia[j]>(distancia[arest->getIndiceNo()]+arest->getPesoAresta()))
                        {
                            distancia[j]=distancia[arest->getIndiceNo()]+arest->getPesoAresta();
                        }

                    }





                }






            }

        }

        //Imprime a distancia dos nos da lista adjacente em funcao do seu indice na lista.
        cout<<"vetor   Distancia da origem \n";
        for (int i = 0; i < listaAdj.size(); ++i)
            cout<<i<<"---------"<<distancia[i]<<endl;
    }
}





















/////////////////////////////////////////////////////////////
