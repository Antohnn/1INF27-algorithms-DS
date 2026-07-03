//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P1ARBOLPALABRA_FUNCIONESARBOL_H
#define P1ARBOLPALABRA_FUNCIONESARBOL_H

NodoArbol *crearNodoArbol(ElementoArbol &elemento) ;
void plantarArbol(NodoArbol *&raiz , NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha);
void crearElemento(ElementoArbol &elemento,char letra);
void preOrden(NodoArbol *raiz);
void imprimirPalabras(NodoArbol *raiz,char palabra[],int pos) ;

#endif //P1ARBOLPALABRA_FUNCIONESARBOL_H
