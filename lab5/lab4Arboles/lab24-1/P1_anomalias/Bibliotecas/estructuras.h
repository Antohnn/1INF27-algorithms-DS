//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P1_ANOMALIAS_ESTRUCTURAS_H
#define P1_ANOMALIAS_ESTRUCTURAS_H
#include <iostream>
#include <climits>
using namespace std;

struct NodoArbol {
    int dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};

struct Arbol {
    NodoArbol *raiz;
};
#endif //P1_ANOMALIAS_ESTRUCTURAS_H
