//
// Created by ANTONIO on 30/06/2026.
//

#ifndef P1ANALISIS_GRAMATICAL_FUNCIONESARBOL_H
#define P1ANALISIS_GRAMATICAL_FUNCIONESARBOL_H

NodoArbol *crearNodoArbol(ElementoArbol &elemento);
void plantarArbol(NodoArbol *&raiz,NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha) ;
void crearArbolGramatical(Arbol &arbol,const char **articulos,const char **sustantivos,const char **verbos) ;
Categoria determinarCategoria(char *palabra,const char **articulos,const char **sustantivos,const char **verbos);
bool validarArbolGramatical(NodoArbol *nodo,Categoria esperada) ;

#endif //P1ANALISIS_GRAMATICAL_FUNCIONESARBOL_H
