//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P2_SKYNERD_FUNCIONESPILA_H
#define P2_SKYNERD_FUNCIONESPILA_H

#include "estructurasPila.h"
#include "estructurasArbol.h"

void crearPila(Pila &pila) ;
bool esPilaVacia(Pila &pila);
void apilar(Pila &pila,NodoArbol *elemento,bool visitado) ;
ElementoPila desapilar(Pila &pila) ;

#endif //P2_SKYNERD_FUNCIONESPILA_H
