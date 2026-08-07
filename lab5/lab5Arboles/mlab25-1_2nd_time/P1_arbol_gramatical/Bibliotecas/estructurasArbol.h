//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P1_ARBOL_GRAMATICAL_ESTRUCTURASARBOL_H
#define P1_ARBOL_GRAMATICAL_ESTRUCTURASARBOL_H
#include "enum.h"

struct ElementoArbol {
    Categoria categoria;
    char palabra[40];
};

struct NodoArbol {
    ElementoArbol dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};

struct Arbol {
    NodoArbol *raiz;
    char oracion[300];
    int cantidadPalabras;
};
#endif //P1_ARBOL_GRAMATICAL_ESTRUCTURASARBOL_H
