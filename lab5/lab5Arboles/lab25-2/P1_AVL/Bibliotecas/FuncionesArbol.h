//
// Created by ANTONIO on 1/07/2026.
//

#ifndef LAB25_2_FUNCIONESARBOL_H
#define LAB25_2_FUNCIONESARBOL_H
#include "NodoArbol.h"
#include "ElementoArbol.h"
#include "Arbol.h"
#include <iostream>
using namespace std;
NodoArbol *crearNodo(ElementoArbol &elemento);
int altura(NodoArbol *raiz) ;
int factor_balance(NodoArbol *raiz);
NodoArbol *rotacionDerecha(NodoArbol *y);
NodoArbol *rotacionIzquierda(NodoArbol *x) ;
NodoArbol *casoIzquierdaDerecha(NodoArbol *nodo);
NodoArbol *casoDerechaIzquierda(NodoArbol *nodo) ;
NodoArbol *insertarAVL(NodoArbol *nodo,ElementoArbol &elemento);
void crearElemento(ElementoArbol &elemento, int dni) ;
void enOrden(NodoArbol *raiz);

#endif //LAB25_2_FUNCIONESARBOL_H
