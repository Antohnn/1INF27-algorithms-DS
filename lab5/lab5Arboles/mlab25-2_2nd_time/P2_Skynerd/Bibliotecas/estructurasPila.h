//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P2_SKYNERD_ESTRUCTURASPILA_H
#define P2_SKYNERD_ESTRUCTURASPILA_H
#include "estructurasArbol.h"

struct ElementoPila {
    NodoArbol *nodo;
    bool visitado;
};
struct NodoPila {
    ElementoPila dato;
    NodoPila *siguiente;
};
struct Pila {
    NodoPila *cima;
};
#endif //P2_SKYNERD_ESTRUCTURASPILA_H
