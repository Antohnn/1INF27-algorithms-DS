//
// Created by ANTONIO on 30/06/2026.
//

#ifndef P2ELIMINARNODOSHIJOS_FUNCIONESPILA_H
#define P2ELIMINARNODOSHIJOS_FUNCIONESPILA_H

#include "Pila.h"

void construirPila(Pila &pila);
bool esPilaVacia(Pila &pila);
void apilar(Pila &pila,NodoArbol *nodo,bool visitado) ;
ElementoPila desapilar(Pila &pila);

#endif //P2ELIMINARNODOSHIJOS_FUNCIONESPILA_H
