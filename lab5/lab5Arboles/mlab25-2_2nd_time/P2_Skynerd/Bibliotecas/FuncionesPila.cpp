//
// Created by ANTONIO on 3/07/2026.
//

#include "estructurasPila.h"

#include <iostream>
using namespace std;
#include "FuncionesPila.h"

void crearPila(Pila &pila) {
    pila.cima=nullptr;
}
bool esPilaVacia(Pila &pila) {
    return pila.cima==nullptr;
}
void apilar(Pila &pila,NodoArbol *elemento,bool visitado) {
    NodoPila *nuevo=new NodoPila();

    nuevo->dato.nodo=elemento;
    nuevo->dato.visitado=visitado;

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
