//
// Created by ANTONIO on 4/07/2026.
//

#ifndef P1_FABRICA_PALETAS_FUNCIONESARBOL_H
#define P1_FABRICA_PALETAS_FUNCIONESARBOL_H

NodoArbol *crearNodoArbol(ElementoArbol &elemento);
void insertar_dia_turno(NodoArbol *&raiz,int arr[4][7],int ini,int fin);
void llenarArreglo(int arr[4][7],ElementoArbol datos[]);
void ordenarArreglo(ElementoArbol datos[]) ;
bool esMenor(ElementoArbol &a,ElementoArbol &b) ;
void intercambiar(ElementoArbol &a,ElementoArbol &b);
void insertar_cantidad(NodoArbol *&raiz,ElementoArbol datos[],int ini,int fin);
void enOrden(NodoArbol *raiz);

#endif //P1_FABRICA_PALETAS_FUNCIONESARBOL_H
