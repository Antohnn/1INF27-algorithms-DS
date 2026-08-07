//
// Created by ANTONIO on 4/07/2026.
//

#ifndef P1_ARBOLES_PARALELOS_ESTRUCTURASARBOL_H
#define P1_ARBOLES_PARALELOS_ESTRUCTURASARBOL_H
struct ElementoArbol {
    int valor;
};
struct NodoArbol {
    ElementoArbol dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
struct Arbol {
    NodoArbol *raiz;
};
#endif //P1_ARBOLES_PARALELOS_ESTRUCTURASARBOL_H
