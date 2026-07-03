//
// Created by ANTONIO on 2/07/2026.
//

#include "estructuras.h"
#include "FuncionesCola.h"

void construirCola(Cola &cola) {
    cola.frente = nullptr;
    cola.fin = nullptr;
}

bool esColaVacia(const Cola &cola) {
    return cola.frente == nullptr;
}

void encolar(Cola &cola, NodoArbol *nodo, int nivel) {
    NodoCola *nuevo = new NodoCola;

    nuevo->elemento.nodo = nodo;
    nuevo->elemento.nivel = nivel;
    nuevo->siguiente = nullptr;

    if (esColaVacia(cola)) {
        cola.frente = nuevo;
        cola.fin = nuevo;
    } else {
        cola.fin->siguiente = nuevo;
        cola.fin = nuevo;
    }
}

ElementoCola desencolar(Cola &cola) {
    ElementoCola elemento{};
    elemento.nodo = nullptr;
    elemento.nivel = -1;

    if (esColaVacia(cola)) {
        return elemento;
    }

    NodoCola *sale = cola.frente;
    elemento = sale->elemento;

    cola.frente = cola.frente->siguiente;

    if (cola.frente == nullptr) {
        cola.fin = nullptr;
    }

    delete sale;
    return elemento;
}
