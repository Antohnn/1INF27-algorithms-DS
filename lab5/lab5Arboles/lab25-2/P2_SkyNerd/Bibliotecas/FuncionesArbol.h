//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P2_SKYNERD_FUNCIONESARBOL_H
#define P2_SKYNERD_FUNCIONESARBOL_H

NodoArbol *crearNodoArbol(ElementoArbol &elemento) ;
void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento);
void insertarEnArbol(NodoArbol *&raiz,int idServer,char flag,ElementoArbol &dato);
ElementoArbol crearElemento(ElementoArbol &dato,int idServer,char flag);
void enOrden(NodoArbol *raiz) ;
NodoArbol *buscarNodoSkyNerd(NodoArbol *raiz) ;
void eliminarHijosSkynerd(NodoArbol *nodoSkyNerd) ;


#endif //P2_SKYNERD_FUNCIONESARBOL_H
