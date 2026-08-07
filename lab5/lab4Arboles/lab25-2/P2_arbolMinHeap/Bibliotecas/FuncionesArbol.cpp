//
// Created by ANTONIO on 2/07/2026.
//

#include <iostream>

#include "estructuras.h"
using namespace std;
#include "FuncionesArbol.h"
#include "FuncionesCola.h"

NodoHeap *crearNodoHeap(int dato) {
    NodoHeap *nuevo = new NodoHeap;

    nuevo->dato = dato;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    nuevo->padre = nullptr;

    return nuevo;
}
void intercambiarDatos(NodoHeap *a, NodoHeap *b) {
    int aux = a->dato;
    a->dato = b->dato;
    b->dato = aux;
}
void heapifyUp(NodoHeap *nodo) {
    while (nodo->padre != nullptr && nodo->dato < nodo->padre->dato) {
        intercambiarDatos(nodo, nodo->padre);
        nodo = nodo->padre;
    }
}
void insertarMinHeap(NodoHeap *&raiz, Cola &colaPadres, int dato) {
    NodoHeap *nuevo = crearNodoHeap(dato);

    if (raiz == nullptr) {
        raiz = nuevo;
        encolar(colaPadres, nuevo);
        return;
    }

    NodoHeap *padre = verFrente(colaPadres);

    if (padre->izquierda == nullptr) {
        padre->izquierda = nuevo;
        nuevo->padre = padre;
    } else {
        padre->derecha = nuevo;
        nuevo->padre = padre;

        desencolar(colaPadres);
    }

    encolar(colaPadres, nuevo);

    heapifyUp(nuevo);
}

NodoHeap *buscarElementoDerecha(NodoHeap *raiz) {
    Cola cola;
    construirCola(cola);

    NodoHeap *actual = nullptr;
    encolar(cola,raiz);
    while (!esColaVacia(cola)) {
        actual=desencolar(cola);

        if (actual->izquierda != nullptr) {
            encolar(cola,actual->izquierda);
        }
        if (actual->derecha != nullptr) {
            encolar(cola,actual->derecha);
        }
    }

    return actual;
}