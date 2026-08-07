//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_ARBOLMINHEAP_FUNCIONESARBOL_H
#define P2_ARBOLMINHEAP_FUNCIONESARBOL_H

#include "estructuras.h"
NodoHeap *crearNodoHeap(int dato) ;
void intercambiarDatos(NodoHeap *a, NodoHeap *b) ;
void heapifyUp(NodoHeap *nodo) ;
void insertarMinHeap(NodoHeap *&raiz, Cola &colaPadres, int dato);
NodoHeap *buscarElementoDerecha(NodoHeap *raiz);
NodoHeap *eliminarMinimo(NodoHeap *&raiz);
void imprimirPorNiveles(NodoHeap *raiz) ;
void heapifyDown(NodoHeap *nodo) ;

#endif //P2_ARBOLMINHEAP_FUNCIONESARBOL_H
