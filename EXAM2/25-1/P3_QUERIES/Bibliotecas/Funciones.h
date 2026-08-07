//
// Created by ANTONIO on 9/07/2026.
//

#ifndef P3_QUERIES_FUNCIONES_H
#define P3_QUERIES_FUNCIONES_H
#include "BibliotecaArbolBinario/ArbolBinario.h"
void crearArbolSQL(ArbolBinario &arbol);
void enOrden(NodoArbolBinario *raiz);
void imprimirTitulo(NodoArbolBinario *raiz) ;
bool noEsComando(string &palabra);
void extraerDatosSQL(string &oracion,string &columna,string &tabla,string &condicion) ;

void validarSQL(ArbolBinario &arbol) ;

#endif //P3_QUERIES_FUNCIONES_H
