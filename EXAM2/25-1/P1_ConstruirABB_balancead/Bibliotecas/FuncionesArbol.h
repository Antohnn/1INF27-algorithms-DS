//
// Created by ANTONIO on 6/07/2026.
//

#ifndef P1_CONSTRUIRABB_BALANCEAD_FUNCIONESARBOL_H
#define P1_CONSTRUIRABB_BALANCEAD_FUNCIONESARBOL_H

#include "estructuras.h"
#include <iostream>
using namespace std;

NodoArbol *crearNodoArbol(int dato) ;
void insertarEquilibrado(int arr[],NodoArbol *&raiz,int ini,int fin);
void preOrden(NodoArbol *raiz);


#endif //P1_CONSTRUIRABB_BALANCEAD_FUNCIONESARBOL_H
