//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_ARBOLMINHEAP_ESTRUCTURAS_H
#define P2_ARBOLMINHEAP_ESTRUCTURAS_H
struct ElementoArbol {
    int dato;
};
struct NodoHeap {
    int dato;
    NodoHeap *izquierda;
    NodoHeap *derecha;
    NodoHeap *padre;
};

struct NodoCola {
    NodoHeap *nodo;
    NodoCola *siguiente;
};

struct Cola {
    NodoCola *frente;
    NodoCola *fin;
};
#endif //P2_ARBOLMINHEAP_ESTRUCTURAS_H
