//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P2EMPRESAVINICOLA_FUNCIONESARBOL_H
#define P2EMPRESAVINICOLA_FUNCIONESARBOL_H
NodoArbol *crearNodoArbol(ElementoArbol &elemento) ;
void ingresa_lote(NodoArbol *&raiz, ElementoArbol &elemento);
void crearElemento(ElementoArbol &elemento,int anio,int lote) ;
void enOrden(NodoArbol *raiz) ;
void reporteDeStock(NodoArbol *raiz) ;
NodoArbol *buscarMenor(NodoArbol *raiz);
NodoArbol *buscarSucesor(NodoArbol *raiz,int anioActual);

#endif //P2EMPRESAVINICOLA_FUNCIONESARBOL_H
