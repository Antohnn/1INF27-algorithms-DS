//
// Created by ANTONIO on 28/06/2026.
//

#ifndef PRACTICAABB_FUNCIONESARBOLBINARIO_H
#define PRACTICAABB_FUNCIONESARBOLBINARIO_H
#include "NodoArbolBinario.h"
#include "ElementoNodo.h"

bool buscarAbb(NodoArbolBinario *raiz,ElementoNodo &elemento);
void insertarAbb(NodoArbolBinario *&raiz,ElementoNodo &elemento);
NodoArbolBinario* crearNodo(ElementoNodo &elemento) ;
void preOrden(NodoArbolBinario *raiz);
void enOrden(NodoArbolBinario *raiz);
void postOrden(NodoArbolBinario *raiz) ;

#endif //PRACTICAABB_FUNCIONESARBOLBINARIO_H
