//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P2_MIN_HEAP_FUNCIONESCOLA_H
#define P2_MIN_HEAP_FUNCIONESCOLA_H

void construirCola(Cola &cola) ;
bool esColaVacia(Cola &cola) ;
void encolar(Cola &cola,ElementoCola &elemento);
ElementoCola desencolar(Cola &cola) ;
void encolarNodoArbol(Cola &cola,NodoArbol *elemento) ;

#endif //P2_MIN_HEAP_FUNCIONESCOLA_H
