//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P2_SKYNERD_FUNCIONESARBOL_H
#define P2_SKYNERD_FUNCIONESARBOL_H

NodoArbol *crearNodoArbol(ElementoArbol &elemento);
void insertarEnArbol(NodoArbol *&raiz,char flag,int idServer) ;
void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento) ;
void enOrden(NodoArbol *raiz);
NodoArbol *buscarSkyNerd(NodoArbol *raiz) ;
void eliminarHijosSkyNerd(NodoArbol *skynerd) ;

#endif //P2_SKYNERD_FUNCIONESARBOL_H
