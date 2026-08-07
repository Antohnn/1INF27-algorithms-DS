//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P1_AVL_ESTRUCTURASARBOL_H
#define P1_AVL_ESTRUCTURASARBOL_H

struct NodoArbol {
    int dni;
    int altura;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
struct Arbol {
    NodoArbol *raiz;
};
#endif //P1_AVL_ESTRUCTURASARBOL_H
