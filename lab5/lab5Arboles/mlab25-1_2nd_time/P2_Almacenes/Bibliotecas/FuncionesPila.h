//
// Created by ANTONIO on 4/07/2026.
//

#ifndef P2_ALMACENES_FUNCIONESPILA_H
#define P2_ALMACENES_FUNCIONESPILA_H

void construirPila(Pila &pila) ;
bool esPilaVacia(Pila pila);
void apilar(Pila &pila,NodoArbol *nodo,bool valido) ;
ElementoPila desapilar(Pila &pila);

#endif //P2_ALMACENES_FUNCIONESPILA_H
