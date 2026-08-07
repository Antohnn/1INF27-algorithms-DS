//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P2_SKYNERD_ESTRUCTURASARBOL_H
#define P2_SKYNERD_ESTRUCTURASARBOL_H

struct ElementoArbol {
    int idServidor;
    char flag;
};

struct NodoArbol {
    ElementoArbol dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};

struct Arbol {
    NodoArbol *raiz;
};

#endif //P2_SKYNERD_ESTRUCTURASARBOL_H
