#include <cstring>
#include <iostream>

using namespace std;

#include "Bibliotecas/Lista.h"
#include "Bibliotecas/ElementoLista.h"
#include "Bibliotecas/funcionesLista.h"
#include "Bibliotecas/NodoLista.h"

void ordenarLista(Lista &listaPosiciones,Lista &listaJugadores) {
    NodoLista *ordenada=nullptr;
    NodoLista *posActual=listaPosiciones.inicio;
    while(posActual!=nullptr) {
        NodoLista *recorrido=listaJugadores.inicio;
        NodoLista *anterior=nullptr;
        while (recorrido!=nullptr) {
            NodoLista *siguiente=recorrido->siguiente;
            if (strcmp(recorrido->elemento.posicion,posActual->elemento.posicion)==0) {
                //sacamos ese nodo
                if (anterior==nullptr) {
                    listaJugadores.inicio=siguiente;
                }else {
                    anterior->siguiente=siguiente;
                }
                recorrido->siguiente=nullptr;
                //insertamos el nodo en mi lista ordenada
                if (ordenada==nullptr) {
                    ordenada=recorrido;
                }else {
                    //usamos un aux para encontrar el ultimo nodo al cual hay que insertar
                    NodoLista *aux=ordenada;
                    while (aux->siguiente!=nullptr) {
                        aux=aux->siguiente;
                    }
                    //insertamos en el ultimo nodo de la lista recorrida
                    aux->siguiente=recorrido;
                }
            }else {
                anterior=recorrido;
            }
            recorrido=siguiente;
        }
        posActual=posActual->siguiente;
    }
    listaJugadores.inicio=ordenada;
}
int main() {
    Lista listaPosiciones,listaJugadores;

    construir(listaPosiciones);
    construir(listaJugadores);

    ElementoLista elemento{};

    elemento={0,0,"","Portero"};
    insertarAlFinal(listaPosiciones, elemento);
    elemento={0,0,"","Defensa"};
    insertarAlFinal(listaPosiciones, elemento);
    elemento={0,0,"","Mediocampo"};
    insertarAlFinal(listaPosiciones, elemento);
    elemento={0,0,"","Delantero"};
    insertarAlFinal(listaPosiciones, elemento);

    // imprimir(listaPosiciones);

    elemento={0,7,"Martinez","Delantero"};
    insertarAlFinal(listaJugadores, elemento);
    elemento={0,1,"Ramirez","Portero"};
    insertarAlFinal(listaJugadores, elemento);
    elemento={0,5,"Perez","Defensa"};
    insertarAlFinal(listaJugadores, elemento);
    elemento={0,8,"Torres","Mediocampo"};
    insertarAlFinal(listaJugadores, elemento);
    elemento={0,9,"Lopez","Delantero"};
    insertarAlFinal(listaJugadores, elemento);
    elemento={0,3,"Gomez","Defensa"};
    insertarAlFinal(listaJugadores, elemento);

    // cout<<endl;
    // imprimir(listaJugadores);
    ordenarLista(listaPosiciones,listaJugadores);
    imprimir(listaJugadores);

    return 0;
}
