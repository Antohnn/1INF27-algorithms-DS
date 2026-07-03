//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_ARBOLMINHEAP_FUNCIONESARBOL_H
#define P2_ARBOLMINHEAP_FUNCIONESARBOL_H

NodoArbol *crearNodoArbol(ElementoArbol &elemento) ;
void intercambiarDatos(NodoArbol *a,NodoArbol *b) ;
void heapifyUp(NodoArbol *nodo) ;
void insertarMinHeap(NodoArbol *&raiz,Cola &cola, ElementoArbol &elemento);
void imprimirPorNiveles(NodoArbol *raiz);

#endif //P2_ARBOLMINHEAP_FUNCIONESARBOL_H
