//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P1_AVL_FUNCIONESARBOL_H
#define P1_AVL_FUNCIONESARBOL_H

int altura(NodoArbol *nodo) ;
int factor_balance(NodoArbol *nodo);
NodoArbol *rotacionDerecha(NodoArbol *y);
NodoArbol *rotacionIzquierda(NodoArbol *x);
NodoArbol *insertarAVL(NodoArbol *&nodo, int dni);
void enOrden(NodoArbol *raiz) ;

#endif //P1_AVL_FUNCIONESARBOL_H
