//
// Created by ANTONIO on 30/06/2026.
//

#ifndef P2ELIMINARNODOSHIJOS_FUNCIONESARBOL_H
#define P2ELIMINARNODOSHIJOS_FUNCIONESARBOL_H

#include "Arbol.h"
#include "NodoArbol.h"

NodoArbol *crearNodo(ElementoArbol &elemento) ;
void plantarArbol(NodoArbol *&raiz,NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha) ;
void eliminarNodosHijos(NodoArbol *raiz);
void eliminarHijoUnico(NodoArbol *padre);
bool esHijo(NodoArbol *nodo);
void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento);
void insertarCodigo(NodoArbol *&raiz, int codigo);
void enOrden(NodoArbol *raiz);

#endif //P2ELIMINARNODOSHIJOS_FUNCIONESARBOL_H
