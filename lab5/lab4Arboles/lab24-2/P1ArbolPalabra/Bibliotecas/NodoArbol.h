//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P1ARBOLPALABRA_NODOARBOL_H
#define P1ARBOLPALABRA_NODOARBOL_H
#include "ElementoArbol.h"

struct NodoArbol {
    ElementoArbol elemento;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif //P1ARBOLPALABRA_NODOARBOL_H
