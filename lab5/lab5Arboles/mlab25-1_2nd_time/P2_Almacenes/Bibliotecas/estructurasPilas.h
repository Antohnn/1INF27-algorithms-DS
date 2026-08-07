//
// Created by ANTONIO on 4/07/2026.
//

#ifndef P2_ALMACENES_ESTRUCTURASPILAS_H
#define P2_ALMACENES_ESTRUCTURASPILAS_H
#include "estructurasArbol.h"

struct ElementoPila {
    NodoArbol *nodo;
    bool valido;
};
struct NodoPila {
    ElementoPila dato;
    NodoPila *siguiente;
};
struct Pila {
    NodoPila *cima;
};
#endif //P2_ALMACENES_ESTRUCTURASPILAS_H
