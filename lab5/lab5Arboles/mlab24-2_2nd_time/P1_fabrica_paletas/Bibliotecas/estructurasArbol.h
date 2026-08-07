//
// Created by ANTONIO on 4/07/2026.
//

#ifndef P1_FABRICA_PALETAS_ESTRUCTURASARBOL_H
#define P1_FABRICA_PALETAS_ESTRUCTURASARBOL_H
struct ElementoArbol {
    int turno;
    int dia;
    int cantidad;
};
struct NodoArbol {
    ElementoArbol dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
struct Arbol {
    NodoArbol *raiz;
};
#endif //P1_FABRICA_PALETAS_ESTRUCTURASARBOL_H
