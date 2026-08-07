//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P2_MIN_HEAP_NODOARBOL_H
#define P2_MIN_HEAP_NODOARBOL_H
#include "ElementoArbol.h"

struct NodoArbol {
    ElementoArbol elemento;
    NodoArbol *padre;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif //P2_MIN_HEAP_NODOARBOL_H
