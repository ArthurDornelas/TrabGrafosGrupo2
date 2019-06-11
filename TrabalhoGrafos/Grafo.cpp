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

void Grafo::compConexa()
{

    No *aux=new No();
    int i=0;
    aux = (&(listaAdj[i]));

    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        it->setVisitadoConex(0);
    }

    int componente = 0;

    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if(it->getVisitadoConex() == 0)
        {
            componente = componente + 1;
            buscaConexa(aux, componente);
        }
    }

}

void Grafo::buscaConexa(No *v, int componente)
{
    v->setVisitadoConex(componente);

    for(std::vector<Aresta>::iterator arest = v->listaAresta.begin(); arest != v->listaAresta.end(); ++arest)
    {
        int i= 0;
        for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            if(it->getVisitadoConex()==0)
            {
                if(it->getId()==arest->getIdNo())
                {
                    buscaConexa(&(listaAdj[i]), componente);
                    break;
                }
                i++;
            }

        }
    }
}

/*
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X                                                                                                                                                               X
X  O algoritmo de Kruskal,sendo um grafo conexo, ponderado e nao direcionado, tem como objetivo encontrar um subconjunto das arestas que forma uma árvore que   X 
X  inclui todos os vértices, onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado. No algoritmo abaixo inicialmente foi inicializado X 
X  todos os vertices do grafo como sendo um subconjunto unitario contendo apenas o proprio vertice, representado de forma como o pai de cada vertice eh o       X
X  proprio vertice e o Rank de todos os vertice eh inicializado com 0. O passo seguinte foi colocar todas as arestas em um unico vetor, e entao ordernar-lo     X
X  em ordem crescente de acordo com o peso da aresta,esta ordenacao eh feita por meio do Quick Sort. Apos isso eh utilizada uma funcao auxiliar          X
X                                                                                                                                                               X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
 */
No* Grafo::busca_kruskal(No *v)
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
        it->setPai(&listaAdj[k]);//criar uma sub-arvore para cada no do grafo
        it->setRank(0);          //sendo o pai o proprio vertice
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
        No *v1=busca_kruskal(&listaAdj[it->getIndiceLista()]);//vertice de origem de uma aresta
        No *v2=busca_kruskal(&listaAdj[it->getIndiceNo()]);//vertice de destino de uma aresta

        if(v1 != v2)//se forem diferentes é porque nao forma ciclo
        {
            arvoreKruskal.push_back(pesoArestas[l]);//insere no vetor de arestas da arvore geradora minima
            uniao_kruskal(v1,v2);//faz a uniao
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

int Grafo::quickPartitionKruskal(int left, int right)//ordenacao de um vetor de arestas em ordem crescente 
{                                                   //de acordo com o peso
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

void Grafo::quickSortKruskal(int left,int right)
{
    if( left < right)
    {
        int pi = quickPartitionKruskal(left, right);

        quickSortKruskal(left, pi-1);
        quickSortKruskal(pi+1, right);
    }
}

void Grafo::trocaKruskal(int x1, int x2)
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

    return k;                                                            // Retorna o numero k-coloravel do grafo.
}



void Grafo::auxGulosoRandomizado()
{
    algoritmoGulosoRandomizado(0.1,1);
}

void Grafo::algoritmoGulosoRandomizado(float alfa, int intMax)
{
    ordenado.clear();
    auxOrdena.clear();
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

    while(i < intMax)
    {
        posCandidatos = ordenado;
        for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            it->setCorNo(-1);           // Coloca as cores de todos os nos como -1
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

                posCandidatos.erase(posCandidatos.begin()+j);

        }

        if(k < melhorSolucao)
        {
            melhorSolucao = k;
        }
        posCandidatos.clear();
        cout<<"Solucao "<<i<<" : " <<k<<endl;
        i++;
    }
    cout<< "A melhor solucao: " << melhorSolucao;

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
/////////////////////////////////////////////////////////////
