//
// Created by ANTONIO on 28/06/2026.
//

#ifndef PRACTICAARBOLES_FUNCIONESARBOL_H
#define PRACTICAARBOLES_FUNCIONESARBOL_H

#include <iomanip>
#include <iostream>
#include "NodoArbol.h"
#include "ElementoNodo.h"
using namespace std;

void preOrden(NodoArbol *);
void enOrden(NodoArbol *);
void postOrden(NodoArbol *);
NodoArbol *crearNodo(ElementoNodoArbol &);
int contarNodos(NodoArbol *);
int contarHojas(NodoArbol *);
int altura(NodoArbol *);
bool buscarElemento(NodoArbol *, ElementoNodoArbol &);


#endif //PRACTICAARBOLES_FUNCIONESARBOL_H
