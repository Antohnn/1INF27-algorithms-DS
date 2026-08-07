//
// Created by ANTONIO on 4/07/2026.
//

#include <iostream>
using namespace std;
#include "estructurasPilas.h"
#include "FuncionesPila.h"

void construirPila(Pila &pila) {
    pila.cima=nullptr;
}
bool esPilaVacia(Pila pila) {
    return pila.cima==nullptr;
}

void apilar(Pila &pila,NodoArbol *nodo,bool valido) {
    NodoPila *nuevo=new NodoPila();

    nuevo->dato.nodo=nodo;
    nuevo->dato.valido=valido;

    nuevo->siguiente=pila.cima;
    pila.cima=nuevo;
}

ElementoPila desapilar(Pila &pila) {
    ElementoPila ele{};

    if (pila.cima==nullptr) {
        return ele;
    }

    NodoPila *aux=pila.cima;
    ele=aux->dato;
    pila.cima=pila.cima->siguiente;

    delete aux;

    return ele;
}
