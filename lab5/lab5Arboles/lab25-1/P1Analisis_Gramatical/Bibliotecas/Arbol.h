//
// Created by ANTONIO on 30/06/2026.
//

#ifndef P1ANALISIS_GRAMATICAL_ARBOL_H
#define P1ANALISIS_GRAMATICAL_ARBOL_H
#include "NodoArbol.h"

struct Arbol {
    NodoArbol *raiz;
    char oracion[300];
    int cantidadPalabras;
};
#endif //P1ANALISIS_GRAMATICAL_ARBOL_H
