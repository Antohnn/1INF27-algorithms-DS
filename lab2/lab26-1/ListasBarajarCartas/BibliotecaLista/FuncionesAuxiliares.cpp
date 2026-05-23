//
// Created by ANTONIO on 22/05/2026.
//
#include <iostream>

#include "funcionesLista.h"
#include "Lista.h"
using namespace std;
#include "FuncionesAuxiliares.h"

void crear_baraja(Baraja &baraja) {
    ElementoBaraja elemento{};
    for (int i=0;i<53;i++) {
        if (i>0 and i<=13) {
            elemento={i,'C'};
            insertarAlFinal(baraja,elemento);
        }else if (i>13 and i<=26) {
            elemento={i-13,'D'};
            insertarAlFinal(baraja,elemento);
        }else if (i>26 and i<=39) {
            elemento={i-26,'T'};
            insertarAlFinal(baraja,elemento);
        }else if (i>39) {
            elemento={i-39,'E'};
            insertarAlFinal(baraja,elemento);
        }
    }
}
NodoBaraja *extrar_en_posicion(Baraja &baraja, int posicion) {
    NodoBaraja *recorrido=baraja.inicio;
    NodoBaraja *anterior=nullptr;
    NodoBaraja *encontrado=nullptr;
    int auxContador=0;

    while (recorrido!=nullptr) {
        NodoBaraja *siguiente=recorrido->siguiente;
        if (posicion==auxContador) {
            //extraemos el nodo
            if (anterior==nullptr) {
                baraja.inicio=siguiente;
            }else {
                anterior->siguiente=siguiente;
            }
            if (recorrido==baraja.fin) {
                baraja.fin=anterior;
            }
            //desconenctamos el nodo actual
            recorrido->siguiente=nullptr;
            baraja.longitud--;
            encontrado=recorrido;
            return encontrado;
        }
        anterior=recorrido;
        auxContador++;
        recorrido=siguiente;
    }
    return encontrado;
}
void barajar(Baraja &baraja) {
    srand(time(nullptr));
    int auxContador=0;
    while ((52-auxContador)>0) {
        int posicion=rand()%(52-auxContador);

        NodoBaraja *extraido=extrar_en_posicion(baraja,posicion);
        insertarNodoAlFinal(baraja,extraido);

        auxContador++;
    }
}
void insertarNodoAlFinal(Baraja &listaTAD,NodoBaraja *&extraido) {
    if (esListaVacia(listaTAD)) {
        listaTAD.inicio = extraido;
        listaTAD.fin = extraido;
    }
    else {
        listaTAD.fin->siguiente = extraido;
        listaTAD.fin = extraido;
    }
    listaTAD.longitud++;
}
void destruir(Baraja &baraja) {
    /*recorrido apunta al inicio del tad*/
    struct NodoBaraja * recorrido = baraja.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoBaraja * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    baraja.inicio = nullptr;
    baraja.fin = nullptr;
    baraja.longitud = 0;
}
//aux
void imprimirCar(char car,int n) {
    for (int i=0;i<n;i++) {
        cout<<car;
    }
    cout<<endl;
}
