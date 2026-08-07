//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_ARBOLMINHEAP_FUNCIONESARBOL_H
#define P2_ARBOLMINHEAP_FUNCIONESARBOL_H

NodoHeap *crearNodoHeap(int dato) ;
void intercambiarDatos(NodoHeap *a, NodoHeap *b) ;
void heapifyUp(NodoHeap *nodo) ;
void insertarMinHeap(NodoHeap *&raiz, Cola &colaPadres, int dato);
void imprimirPorNiveles(NodoHeap *raiz);
NodoHeap *buscarElementoDerecha(NodoHeap *raiz);

#endif //P2_ARBOLMINHEAP_FUNCIONESARBOL_H
