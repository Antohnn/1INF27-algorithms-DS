#include <iostream>

using namespace std;
#include "Bibliotecas/funcionesLista.h"
#include "Bibliotecas/ElementoLista.h"
#include "Bibliotecas/Lista.h"
#include "Bibliotecas/NodoLista.h"

void ordenarLista(Lista &listaCuadrigas) {
    //defino los punteros para manejar mis "listas" de pares e impares
    NodoLista *iniPares=nullptr;
    NodoLista *finPares=nullptr;
    NodoLista *iniImpares=nullptr;
    NodoLista *finImpares=nullptr;
    //puntero para recorrer la lista
    NodoLista *recorrido=listaCuadrigas.inicio;
    //recorro la lista
    while (recorrido) {
        NodoLista *siguiente=recorrido->siguiente;
        recorrido->siguiente=nullptr;

        if (recorrido->elemento.id % 2==0) {
            if (iniPares==nullptr) {
                iniPares=recorrido;
                finPares=recorrido;
            }else {
                finPares->siguiente=recorrido;
                finPares=recorrido;
            }
        }else {
            if (iniImpares==nullptr) {
                iniImpares=recorrido;
                finImpares=recorrido;
            }else {
                finImpares->siguiente=recorrido;
                finImpares=recorrido;
            }
        }
        recorrido=siguiente;
    }
    if (iniPares==nullptr) {
        listaCuadrigas.inicio=iniImpares;
    }else {
        listaCuadrigas.inicio=iniPares;
        finPares->siguiente=iniImpares;
    }
}
int main() {

    struct ElementoLista elemento{};
    struct Lista listaCuadrigas;
    int n;
    construir(listaCuadrigas);
    // cout<<"Inserte el numero de cuadrigas en la competencia: "<<endl;
    // cin>>n;
    // cout<<"Inserte las cuadrigas (id,nombre,equipo): "<<endl;
    // for (int i=0;i<n;i++) {
    //     cin>>elemento.id;
    //     cin.ignore();
    //     cin.getline(elemento.nombre,50,',');
    //     cin.getline(elemento.equipo,50);
    //     insertarAlFinal(listaCuadrigas,elemento);
    // }
    // imprimir(listaCuadrigas);

    elemento={0,17,"Messala","Rojo"};
    insertarAlFinal(listaCuadrigas, elemento);
    elemento={0,4,"Ben-Hur","Azul"};
    insertarAlFinal(listaCuadrigas, elemento);
    elemento={0,12,"Artax","Verde"};
    insertarAlFinal(listaCuadrigas, elemento);
    elemento={0,7,"Drusus","Negro"};
    insertarAlFinal(listaCuadrigas, elemento);

    //imprimir(listaCuadrigas);

    ordenarLista(listaCuadrigas);
    imprimir(listaCuadrigas);


    return 0;
}
