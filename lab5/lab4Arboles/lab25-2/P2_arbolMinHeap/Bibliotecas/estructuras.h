//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_ARBOLMINHEAP_ESTRUCTURAS_H
#define P2_ARBOLMINHEAP_ESTRUCTURAS_H
struct ElementoArbol {
    int dato;
};
struct NodoArbol {
    ElementoArbol elemento;
    NodoArbol *izquierda;
    NodoArbol *derecha;
    NodoArbol *padre;
};

struct ElementoCola {
    NodoArbol *nodo;
};

struct NodoCola {
    ElementoCola elemento;
    NodoCola *siguiente;
};

struct Cola {
    NodoCola *frente;
    NodoCola *fin;
};
#endif //P2_ARBOLMINHEAP_ESTRUCTURAS_H
