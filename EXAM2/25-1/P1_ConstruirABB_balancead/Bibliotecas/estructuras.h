//
// Created by ANTONIO on 6/07/2026.
//

#ifndef P1_CONSTRUIRABB_BALANCEAD_ESTRUCTURAS_H
#define P1_CONSTRUIRABB_BALANCEAD_ESTRUCTURAS_H


struct NodoArbol {
    int dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
struct Arbol {
    NodoArbol *raiz;
};
#endif //P1_CONSTRUIRABB_BALANCEAD_ESTRUCTURAS_H
