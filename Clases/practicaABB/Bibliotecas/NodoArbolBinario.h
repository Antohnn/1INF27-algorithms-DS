//
// Created by ANTONIO on 28/06/2026.
//

#ifndef PRACTICAABB_NODOARBOLBINARIO_H
#define PRACTICAABB_NODOARBOLBINARIO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include "ElementoNodo.h"

using namespace std;

struct NodoArbolBinario {
    ElementoNodo elemento;
    NodoArbolBinario *izquierda;
    NodoArbolBinario *derecha;
};
#endif //PRACTICAABB_NODOARBOLBINARIO_H
