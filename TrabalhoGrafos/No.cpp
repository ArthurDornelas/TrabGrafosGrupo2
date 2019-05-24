#include "Aresta.h"
#include "No.h"
using namespace std;

No::No()
{
    grauSaida=0;
    grauEntrada = 0;
    cor = -1;
}

No::No(int ident, int grauSaidaNo)
{
    id = ident;
    grauSaida = grauSaidaNo;
    visitado=false;

}

No::~No()
{

}

void No::setGrauSaida(int grauSaidaNo)
{
    grauSaida += grauSaidaNo;
}

void No::setGrauEntrada(int grauEntradaNo)
{
    grauEntrada += grauEntradaNo;
}

void No::setId(int ident)
{
    id = ident;
}

int No::getId()
{
    return id;
}

float No::getAresta(int i){
    return listaAresta[i].getIdNo();
}

void No::adicionaAresta(int ident, float pesoAresta,int idLista,int indiceNo)
{
    Aresta aresta = Aresta(ident,pesoAresta,idLista,indiceNo);
    if(ident == id)
        grauSaida += 2;
    else
        grauSaida += 1;
    listaAresta.push_back(aresta);

}

void No::adicionaArestaSemPeso(int ident,int idLista,int indiceNo)
{
    Aresta aresta = Aresta(ident,idLista,indiceNo);
    if(ident == id)
       grauSaida += 2;
    else
       grauSaida += 1;
    listaAresta.push_back(aresta);

}

void No::removeAresta(int ident)
{

    for(vector<Aresta>::iterator a = listaAresta.begin(); a != listaAresta.end();   ++a){
              if(a->getIdNo() == ident) {
                  listaAresta.erase(a);
                  break;
             }

   }

    if(ident == id)
        grauSaida -= 2;
    else
        grauSaida -= 1;
}

bool No::eVizinho(int id)
{
    for(std::vector <Aresta>::iterator it = listaAresta.begin(); it != listaAresta.end(); it++ ){
        if(id == it->getIdNo() ){
            return true;
        }
    }
    return false;
}

void No::setVisitado(bool novo)
{
    visitado=novo;
}

bool No::getVisitado()
{
    return visitado;
}

void No::setVisitadoConex(int a)
{
    visitadoConex= a;
}

int No::getVisitadoConex()
{
    return visitadoConex;
}

void No::addCorAdj(int k)
{
    bool flag = false;
    for(int i=0; i<corAdj.size() ; i++)
    {
        if(corAdj[i] == k)
        {
            flag = true;
            break;
        }
    }
    if(flag == false)
        corAdj.push_back(k);
}
