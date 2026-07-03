//
// Created by ANTONIO on 1/07/2026.
//

#include <iostream>

#include "Pila.h"
using namespace std;
#include "FuncionesPila.h"

void construirPila(Pila &pila) {
    pila.cima=nullptr;
}
bool esPilaVacia(Pila &pila) {
    return pila.cima==nullptr;
}
void apilar(Pila &pila,NodoArbol *nodo,bool valido) {
    NodoPila *nuevo=new NodoPila();

    nuevo->elemento.nodo=nodo;
    nuevo->siguiente=nullptr;
    nuevo->elemento.valido=valido;
    nuevo->siguiente=pila.cima;

    pila.cima=nuevo;
}
NodoArbol *desapilar(Pila &pila) {
    NodoPila *aux=nullptr;

    if (pila.cima==nullptr) {
        return nullptr;
    }

    NodoArbol *elemento=pila.cima->elemento.nodo;
    aux=pila.cima;
    pila.cima=pila.cima->siguiente;

    delete aux;

    return elemento;
}
ElementoPila desapilarElemento(Pila &pila) {
    NodoPila *aux=pila.cima;
    ElementoPila elemento{};

    if (pila.cima==nullptr) {
        elemento.nodo=nullptr;
        elemento.valido=false;
        return elemento;
    }

    elemento=pila.cima->elemento;
    pila.cima=pila.cima->siguiente;


    delete aux;

    return elemento;
}