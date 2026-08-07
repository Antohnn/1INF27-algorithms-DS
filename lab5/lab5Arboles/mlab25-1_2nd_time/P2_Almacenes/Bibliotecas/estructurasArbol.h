//
// Created by ANTONIO on 4/07/2026.
//

#ifndef P2_ALMACENES_ESTRUCTURASARBOL_H
#define P2_ALMACENES_ESTRUCTURASARBOL_H

struct ElementoArbol {
    int codigo;
};
struct NodoArbol {
    ElementoArbol dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
struct Arbol {
    NodoArbol *raiz;
};
#endif //P2_ALMACENES_ESTRUCTURASARBOL_H
