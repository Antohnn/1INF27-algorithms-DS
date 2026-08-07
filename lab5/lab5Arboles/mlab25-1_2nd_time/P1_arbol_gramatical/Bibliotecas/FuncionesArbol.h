//
// Created by ANTONIO on 3/07/2026.
//

#ifndef P1_ARBOL_GRAMATICAL_FUNCIONESARBOL_H
#define P1_ARBOL_GRAMATICAL_FUNCIONESARBOL_H

NodoArbol *crearNodoArbol(ElementoArbol &elemento);
Categoria determinarCategoria(char *palabra,const char **articulos,const char **sustantivos,const char **verbos);
void plantarArbol(NodoArbol *&nodo,NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha);
void crearArbolGramatical(Arbol &arbol,const char **articulos,const char **sustantivos,const char **verbos);
bool validarArbolGramatical(Arbol &arbol);
bool verificar(NodoArbol *nodo,Categoria cate);
void mensajeDeError(Categoria cate);
void preOrden(NodoArbol *raiz) ;
void imprimirCategoria(Categoria categoria);

#endif //P1_ARBOL_GRAMATICAL_FUNCIONESARBOL_H
