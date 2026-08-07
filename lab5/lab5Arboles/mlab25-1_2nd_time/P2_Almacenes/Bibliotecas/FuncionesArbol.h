//
// Created by ANTONIO on 4/07/2026.
//

#ifndef P2_ALMACENES_FUNCIONESARBOL_H
#define P2_ALMACENES_FUNCIONESARBOL_H

NodoArbol *crearNodo(ElementoArbol &elemento) ;
void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento) ;
void insertar(NodoArbol *&raiz,int codigo) ;
void enOrden(NodoArbol *raiz) ;
void eliminarHojasHijos(NodoArbol *raiz) ;
void eliminarHijoUnico(NodoArbol *nodo);
bool esHijo(NodoArbol *nodo);

#endif //P2_ALMACENES_FUNCIONESARBOL_H
