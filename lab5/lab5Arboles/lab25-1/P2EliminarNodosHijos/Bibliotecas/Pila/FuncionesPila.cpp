//
// Created by ANTONIO on 30/06/2026.
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
void apilar(Pila &pila,NodoArbol *nodo,bool visitado) {
    NodoPila *nuevo=new NodoPila();

    nuevo->elemento.nodo=nodo;
    nuevo->elemento.visitado=visitado;
    nuevo->siguiente=pila.cima;

    pila.cima=nuevo;
}
ElementoPila desapilar(Pila &pila) {
    ElementoPila elemento{};
    elemento.nodo=nullptr;
    elemento.visitado=false;

    if (pila.cima==nullptr) {
        return elemento;
    }

    NodoPila *aux=pila.cima;
    elemento=aux->elemento;

    pila.cima=pila.cima->siguiente;

    delete aux;

    return elemento;
}
