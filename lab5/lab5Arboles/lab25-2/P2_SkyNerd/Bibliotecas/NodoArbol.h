//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P2_SKYNERD_NODOARBOL_H
#define P2_SKYNERD_NODOARBOL_H
#include "ElementoArbol.h"

struct NodoArbol {
    ElementoArbol dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif //P2_SKYNERD_NODOARBOL_H
