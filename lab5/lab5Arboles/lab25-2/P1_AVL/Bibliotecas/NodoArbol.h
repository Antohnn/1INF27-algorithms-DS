//
// Created by ANTONIO on 1/07/2026.
//

#ifndef LAB25_2_NODOARBOL_H
#define LAB25_2_NODOARBOL_H
#include "ElementoArbol.h"

struct NodoArbol {
    ElementoArbol elemento;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif //LAB25_2_NODOARBOL_H
