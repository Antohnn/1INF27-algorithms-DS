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
NodoHeap *eliminarMinimo(NodoHeap *&raiz) {
    if (raiz == nullptr) {
        return nullptr;
    }

    NodoHeap *eliminado = crearNodoHeap(raiz->dato);

    if (raiz->izquierda == nullptr && raiz->derecha == nullptr) {
        delete raiz;
        raiz = nullptr;
        return eliminado;
    }

    NodoHeap *ultimaHoja = buscarElementoDerecha(raiz);

    raiz->dato = ultimaHoja->dato;

    NodoHeap *padre = ultimaHoja->padre;

    if (padre->izquierda == ultimaHoja) {
        padre->izquierda = nullptr;
    } else if (padre->derecha == ultimaHoja) {
        padre->derecha = nullptr;
    }

    delete ultimaHoja;

    heapifyDown(raiz);

    return eliminado;
}
void imprimirPorNiveles(NodoHeap *raiz) {
    if (raiz == nullptr) {
        return;
    }

    Cola cola;
    construirCola(cola);

    encolar(cola, raiz);

    while (!esColaVacia(cola)) {
        NodoHeap *actual = desencolar(cola);

        cout << actual->dato << " ";

        if (actual->izquierda != nullptr) {
            encolar(cola, actual->izquierda);
        }

        if (actual->derecha != nullptr) {
            encolar(cola, actual->derecha);
        }
    }

    cout << endl;
}
void heapifyDown(NodoHeap *nodo) {
    while (nodo != nullptr) {
        NodoHeap *menor = nodo;

        if (nodo->izquierda != nullptr &&
            nodo->izquierda->dato < menor->dato) {
            menor = nodo->izquierda;
            }

        if (nodo->derecha != nullptr &&
            nodo->derecha->dato < menor->dato) {
            menor = nodo->derecha;
            }

        if (menor == nodo) {
            break;
        }

        intercambiarDatos(nodo, menor);

        nodo = menor;
    }
}
