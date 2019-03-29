#include "Grafo.h"
#include "No.h"
#include "No.cpp"
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 9999999;
using namespace std;

Grafo::Grafo(bool ehDigrafo, bool ehPonderada)
{
   this->ehDigrafo == ehDigrafo;
   this->ehPonderada == ehPonderada;

   if(ehDigrafo == true)
    cout << "Digrafo" << endl;
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

    if(ehDigrafo == false)
    {

        if(estaNoGrafo(id1) && estaNoGrafo(id2))
        {
            if(vizinho(id1,id2))
            {
                for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
                {
                    if( it->getId() == id1 )
                        it->removeAresta(id2);
                    if( it->getId() == id2)
                        it->removeAresta(id1);
                }
            }

        }
        else
        {
            cout << "Um ou mais NOS nao existem, impossivel remover a ARESTA." << endl;
        }

    }

    else
    {

        if(estaNoGrafo(id1) && estaNoGrafo(id2))
        {
            if(vizinho(id1,id2))
            {
                for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
                {
                    if( it->getId() == id1 ){

                        it->removeAresta(id2);

                    }
                    else if( it->getId() == id2){

                        it->removeAresta(id1);
                    }
                }
            }

        }
        else
        {
            cout << "Um ou mais NOS nao existem, impossivel remover a ARESTA." << endl;
        }

    }

}

void Grafo::adicionarArestaNos(int id, int id2,int peso)
{
        this->ehDigrafo == true;

        bool id1_noGrafo = false;
        bool id2_noGrafo = false;

        // Verifica se os Nos existem, senao eles sao criados
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
        //////////////////////////////////////////////////////

        // Se nao for Digrafo
        if(id1_noGrafo && id2_noGrafo && (this->ehDigrafo == false) )
        {

            for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
            {

                if(id != id2)
                {
                    if(it->getId() == id)
                    {
                        it->adicionaAresta(id2,peso,id);
                        if(ehDigrafo == false)
                            cout<< "false";
                        else
                            cout<< "true";
                        cout << "Add Aresta Nao Digrafo" << endl;
                    }

                    if(it->getId() == id2)
                    {
                        it->adicionaAresta(id,peso,id2);
                    }
                }

            }

        }
        ////////////////////////////////////////

        //Se for Digrafo
        else if(id1_noGrafo && id2_noGrafo && (this->ehDigrafo == true) )
        {
            for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
            {
                if(id != id2)
                {
                    if(it->getId() == id)
                    {
                        it->adicionaAresta(id2,peso,id);
                        cout << "add Aresta Digrafo" << endl;
                    }
                }
            }
        }
        //////////////////////////////////

        imprimiGrafo();

}


bool Grafo::estaNoGrafo(int i)
{
    if(listaAdj.size() > 0){

        cout<< listaAdj.size() << endl;

        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            if( it->getId() == i )
            {
                return true;
            }
        }
        return false;

    }

    else{
        return false;

    }
}

int Grafo::ordemGrafo()
{
    return listaAdj.size();
}

int Grafo::retornaGrauNo(int id)
{

    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if( it->getId() == id )
        {
            return it->getGrau();
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
        num_Arestas += listaAdj[i].getGrau();
    }
    if(num_Arestas == n*(n-1))
        return true;
    return false;

}

bool Grafo::grafoKRegularidade(int k)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if(it->getGrau()!=k)
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
        std::cout << "No " << it->getId() << " - " << it->getGrau() << "  ";
    }
}


/*
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X                                                                                                                                                               X
X  No algoritmo de Prim comeca do primeiro No inserido e busca o proximo No com menor peso de aresta que esse liga                                              X
X  e adiciona esse No a um vetor chamado arvore.Em seguida o algoritmo de prim  busca o proximo No a ser inserido com menor pseso                               X
X  de aresta entre os nos ja presentes no vetor, por exemplo, se temos dois Nos inseridos no vetor arvore buscaremos a aresta de menor peso                     X
X  em um conjunto que engloba a aresta desses dois nos ,  colocaremos esse No aqual essa aresta liga ao nosso vetor                                             X
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
        std::cout << it->getId();
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
    for(std::vector<No>::iterator it = listaAdj.begin();it != listaAdj.end() ; ++it)
    {
        if(paridade)
        {
            it->setLabel('A');
        }else
        {
            it->setLabel('B');
        }
        paridade = !paridade;
    }

}

void Grafo::imprimir_biparticao()
{
    for(std::vector<No>::iterator it = listaAdj.begin();it != listaAdj.end() ; ++it)
    {
        std::cout<< "-> "<< it->getLabel()<< std::endl;
    }
}
