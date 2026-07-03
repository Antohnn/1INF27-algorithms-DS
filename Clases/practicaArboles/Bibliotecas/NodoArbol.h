//
// Created by ANTONIO on 28/06/2026.
//

#ifndef PRACTICAARBOLES_NODOARBOL_H
#define PRACTICAARBOLES_NODOARBOL_H
#include "ElementoNodo.h"
#include <iostream>
using namespace std;

struct NodoArbol {
    ElementoNodoArbol dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif //PRACTICAARBOLES_NODOARBOL_H
