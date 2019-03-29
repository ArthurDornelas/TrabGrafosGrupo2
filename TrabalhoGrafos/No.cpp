#include "Aresta.h"
#include "No.h"
using namespace std;

No::No()
{
    grau=0;
}

No::No(int ident, int grauNo)
{
    id = ident;
    grau = grauNo;

}

No::~No()
{

}

void No::setGrau(int grauNo)
{
    grau = grauNo;
}

int No::getGrau()
{
    return grau;
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

void No::adicionaAresta(int ident, float pesoAresta,int idLista){
    Aresta aresta = Aresta(ident,pesoAresta,idLista);
    if(ident == id)
       grau += 2;
    else
       grau += 1;
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
        grau -= 2;
    else
        grau -= 1;
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

