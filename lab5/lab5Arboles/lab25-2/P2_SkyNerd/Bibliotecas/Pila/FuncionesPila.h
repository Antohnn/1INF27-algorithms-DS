//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P2_SKYNERD_FUNCIONESPILA_H
#define P2_SKYNERD_FUNCIONESPILA_H

#include "Pila.h"
void construirPila(Pila &pila);
bool esPilaVacia(Pila &pila) ;
void apilar(Pila &pila,NodoArbol *nodo,bool valido) ;
NodoArbol *desapilar(Pila &pila);
ElementoPila desapilarElemento(Pila &pila);

#endif //P2_SKYNERD_FUNCIONESPILA_H
