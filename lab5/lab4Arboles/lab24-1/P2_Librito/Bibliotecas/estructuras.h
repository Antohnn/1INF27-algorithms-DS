//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_LIBRITO_ESTRUCTURAS_H
#define P2_LIBRITO_ESTRUCTURAS_H
#include <iostream>
#include <cstring>
using namespace std;

struct ElementoArbol {
    char titulo[50];
    int relevancia;
};

struct NodoArbol {
    ElementoArbol elemento;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};

struct Arbol {
    NodoArbol *raiz;
    int tamanio;
};

struct ElementoCola {
    NodoArbol *nodo;
    int nivel;
};

struct NodoCola {
    ElementoCola elemento;
    NodoCola *siguiente;
};

struct Cola {
    NodoCola *frente;
    NodoCola *fin;
};
#endif //P2_LIBRITO_ESTRUCTURAS_H
