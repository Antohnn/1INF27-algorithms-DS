//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_ARBOLMINHEAP_FUNCIONESCOLA_H
#define P2_ARBOLMINHEAP_FUNCIONESCOLA_H
#include "estructuras.h"
void construirCola(Cola &cola) ;
bool esColaVacia(Cola &cola);
void encolar(Cola &cola, NodoHeap *nodo) ;
NodoHeap *verFrente(Cola &cola);
NodoHeap *desencolar(Cola &cola);


#endif //P2_ARBOLMINHEAP_FUNCIONESCOLA_H
