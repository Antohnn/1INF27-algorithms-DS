#include <cstring>
#include <iostream>

using namespace std;

#include "Bibliotecas/Lista.h"
#include "Bibliotecas/funcionesLista.h"
#include "Bibliotecas/ElementoLista.h"

void ordenarListas(Lista &listaPosiciones, Lista &listaJugadores) {
    //definimos un posActual para recorrer la lista de formaciones
    //se define un puntero auxiliar(no lista) que nos permita "guardar" temporalmente la lista ordenada
    NodoLista *ordenada=nullptr;
    NodoLista *posActual=listaPosiciones.inicio;
    //se recorre la lista de posiciones para ordenar segun estas
    while (posActual) {
        //se define recorrido para recorrer la lista de jugadores
        // se define anterior para poder tener un mejor control de la lista
        NodoLista *anterior=nullptr;
        NodoLista *recorrido=listaJugadores.inicio;
        //recorremos la lista de jugadores
        while (recorrido) {
            //se define, dentro del while, un puntero tipo Nodo siguiente para poder tener un mejor control sobre mi lista
            NodoLista *siguiente=recorrido->siguiente;
            //se hace la comparacion con la lista de posiciones y la lista de jugadores
            if (strcmp(posActual->elemento.posicion,recorrido->elemento.posicion)==0) {
                //si se encuentra se verifica si esta en la primera posicion
                if (anterior==nullptr) {
                    //si el dato se encuentra primero se hace que la lista apunte al siguiente elemento
                    //inicio->1P->5D->6M
                    //inicio->5D->6M
                    listaJugadores.inicio=siguiente;
                }else {
                    //si el dato se encuentra al medio o al final
                    //se hace que el dato anterior apunte al siguiente del recorrido
                    //1D->5P->6M
                    //inicio 5D->6M
                    anterior->siguiente=siguiente;
                }
                //se hace que el dato encontrado apunte a un nullptr para poder insetarlo al final del puntero ordenada
                //1P->nullptr
                recorrido->siguiente=nullptr;
                if (ordenada==nullptr) {
                    ordenada=recorrido;
                }else {
                    //definimos un aux para recorrer el puntero ordenado hata el final
                    NodoLista *aux=ordenada;
                    //si aux->siguiente es nullptr cortas el while
                    while (aux->siguiente!=nullptr) {
                        aux=aux->siguiente;
                    }
                    //hago que ese siguiente apunte al recorrido por guardar
                    aux->siguiente=recorrido;
                }

            }else {
                //si no hay coincidencia hago que mi anterior sea mi recorrido
                //1D->9D->6M->4P
                //ant->rec->siguiente
                anterior=recorrido;
            }
            //avanzo con siguiente porque si hay concidencia recorrido->siguiente apuntaria  a nullptr
            recorrido=siguiente;
        }
        //avanzo
        posActual=posActual->siguiente;
    }
    //por ultimo hago que la listaJugadores apunte a mi puntero ordenada
    listaJugadores.inicio=ordenada;
}
int main() {
    struct ElementoLista elemento{};
    struct Lista listaJugadores;
    struct Lista listaPosiciones;

    construir(listaJugadores);
    construir(listaPosiciones);

    // cout<<"Ingrese los datos del jugador(Camiseta,Nombre,Posicion): "<<endl;
    // while (true) {
    //     cin>>elemento.camiseta;
    //     if (elemento.camiseta == 0) break;
    //     cin.get();
    //     cin.getline(elemento.nombre,50,',');
    //     cin.getline(elemento.posicion,50);
    //     insertarAlFinal(listaJugadores, elemento);
    // }
    // cout<<"Ingrese la formacion de los jugadores: "<<endl;
    // for (int i=0;i<4;i++) {
    //     elemento.camiseta=0;
    //     strcpy(elemento.nombre,"");
    //     cout<<"Posicion "<<i+1<<": ";
    //     cin.getline(elemento.posicion,50);
    //     insertarAlFinal(listaPosiciones, elemento);
    // }
    // imprimir(listaPosiciones);

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

    ordenarListas(listaPosiciones,listaJugadores);

    imprimir(listaJugadores);


    return 0;
}
