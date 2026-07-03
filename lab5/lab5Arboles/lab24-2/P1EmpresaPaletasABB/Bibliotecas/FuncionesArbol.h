//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P1EMPRESAPALETASABB_FUNCIONESARBOL_H
#define P1EMPRESAPALETASABB_FUNCIONESARBOL_H

NodoArbol *CrearNodoArbol(ElementoArbol &elemento);
ElementoArbol crearElemento(int turno,int dia,int cantidad) ;
void insertar_dia_turno(NodoArbol  *&raiz,int arr[4][7],int ini,int fin) ;
void enOrden(NodoArbol *raiz) ;
int altura(NodoArbol *raiz);
bool estaEquilibrado(NodoArbol *raiz) ;
bool esMenorCantidad(ElementoArbol &a,ElementoArbol &b) ;
void llenarArreglo(int arr[4][7],ElementoArbol datos[]);
void ordenarArreglo(ElementoArbol datos[]);
void intercambiar(ElementoArbol &a,ElementoArbol &b);
void insertar_cantidad(NodoArbol *&raiz,ElementoArbol datos[],int ini,int fin);


#endif //P1EMPRESAPALETASABB_FUNCIONESARBOL_H
