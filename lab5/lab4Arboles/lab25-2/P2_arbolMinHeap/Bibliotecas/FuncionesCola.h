//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_ARBOLMINHEAP_FUNCIONESCOLA_H
#define P2_ARBOLMINHEAP_FUNCIONESCOLA_H
#include "estructuras.h"
void construirCola(Cola &cola) ;
bool esColaVacia(Cola &cola);
void encolar(Cola &cola,ElementoCola &elemento);
ElementoCola desencolar(Cola &cola);
ElementoCola verFrente(Cola &cola);
void encolarNodoArbol(Cola &cola,NodoArbol *nodo) ;

#endif //P2_ARBOLMINHEAP_FUNCIONESCOLA_H
