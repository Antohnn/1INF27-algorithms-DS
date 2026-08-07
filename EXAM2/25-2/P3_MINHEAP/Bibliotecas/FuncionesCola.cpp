//
// Created by ANTONIO on 2/07/2026.
//

#include "estructuras.h"
#include <iostream>
using namespace std;
#include "FuncionesCola.h"

void construirCola(Cola &cola) {
    cola.frente = nullptr;
    cola.fin = nullptr;
}

bool esColaVacia(Cola &cola) {
    return cola.frente == nullptr;
}

void encolar(Cola &cola, NodoHeap *nodo) {
    NodoCola *nuevo = new NodoCola;
    nuevo->nodo = nodo;
    nuevo->siguiente = nullptr;

    if (esColaVacia(cola)) {
        cola.frente = nuevo;
        cola.fin = nuevo;
    } else {
        cola.fin->siguiente = nuevo;
        cola.fin = nuevo;
    }
}

NodoHeap *verFrente(Cola &cola) {
    if (esColaVacia(cola)) return nullptr;
    return cola.frente->nodo;
}

NodoHeap *desencolar(Cola &cola) {
    if (esColaVacia(cola)) return nullptr;

    NodoCola *aux = cola.frente;
    NodoHeap *nodo = aux->nodo;

    cola.frente = cola.frente->siguiente;

    if (cola.frente == nullptr) {
        cola.fin = nullptr;
    }

    delete aux;
    return nodo;
}
