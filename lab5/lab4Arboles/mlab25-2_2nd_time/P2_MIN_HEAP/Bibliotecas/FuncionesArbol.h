//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P2_MIN_HEAP_FUNCIONESARBOL_H
#define P2_MIN_HEAP_FUNCIONESARBOL_H

#include "NodoArbol.h"
#include "Cola/Cola.h"
#include "ElementoArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento);
void insertarMinHeap(NodoArbol *&raiz,Cola &cola,ElementoArbol &elemento);
void heapifyup(NodoArbol *nuevo);
void intercambiarDatos(NodoArbol *nuevo,NodoArbol *padre);
void imprimirPorNiveles(NodoArbol *raiz);

#endif //P2_MIN_HEAP_FUNCIONESARBOL_H
