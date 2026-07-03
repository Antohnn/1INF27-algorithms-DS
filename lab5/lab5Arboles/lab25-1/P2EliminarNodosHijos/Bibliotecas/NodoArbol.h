//
// Created by ANTONIO on 30/06/2026.
//

#ifndef P2ELIMINARNODOSHIJOS_NODOARBOL_H
#define P2ELIMINARNODOSHIJOS_NODOARBOL_H
#include "ElementoArbol.h"

struct NodoArbol {
    ElementoArbol elemento;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif //P2ELIMINARNODOSHIJOS_NODOARBOL_H
