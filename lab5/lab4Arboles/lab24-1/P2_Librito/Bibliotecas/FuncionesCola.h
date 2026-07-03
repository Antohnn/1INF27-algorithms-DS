//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_LIBRITO_FUNCIONESCOLA_H
#define P2_LIBRITO_FUNCIONESCOLA_H
void construirCola(Cola &cola);
bool esColaVacia(const Cola &cola);
void encolar(Cola &cola, NodoArbol *nodo, int nivel);
ElementoCola desencolar(Cola &cola);

#endif //P2_LIBRITO_FUNCIONESCOLA_H
