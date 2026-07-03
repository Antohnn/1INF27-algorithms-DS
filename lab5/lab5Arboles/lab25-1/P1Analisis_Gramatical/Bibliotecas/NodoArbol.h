//
// Created by ANTONIO on 30/06/2026.
//

#ifndef P1ANALISIS_GRAMATICAL_NODOARBOL_H
#define P1ANALISIS_GRAMATICAL_NODOARBOL_H
#include "ElementoArbol.h"

struct NodoArbol {
    ElementoArbol elemento;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif //P1ANALISIS_GRAMATICAL_NODOARBOL_H
