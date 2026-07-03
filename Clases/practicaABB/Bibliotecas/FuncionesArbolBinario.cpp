//
// Created by ANTONIO on 28/06/2026.
//

#include "FuncionesArbolBinario.h"
#include "ElementoNodo.h"
#include "NodoArbolBinario.h"

bool buscarAbb(NodoArbolBinario *raiz,ElementoNodo &elemento) {
    if (raiz==nullptr) return false;
    if (raiz->elemento.dato==elemento.dato) return true;
    if (elemento.dato<raiz->elemento.dato) {
        return buscarAbb(raiz->izquierda,elemento);
    }else {
        return buscarAbb(raiz->derecha,elemento);
    }
}
void insertarAbb(NodoArbolBinario *&raiz,ElementoNodo &elemento) {
    if (raiz==nullptr) {
        raiz=crearNodo(elemento);
        return;
    }
    if (elemento.dato<raiz->elemento.dato) {
        insertarAbb(raiz->izquierda,elemento);
    }else if (elemento.dato>raiz->elemento.dato) {
        insertarAbb(raiz->derecha,elemento);
    }else {
        return;
    }
}
NodoArbolBinario* crearNodo(ElementoNodo &elemento) {
    NodoArbolBinario *nuevo=new NodoArbolBinario();
    nuevo->elemento=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;
    return nuevo;
}

void preOrden(NodoArbolBinario *raiz) {
    if (raiz==nullptr) return;

    cout<<raiz->elemento.dato<<" ";
    preOrden(raiz->izquierda);
    preOrden(raiz->derecha);
}
void enOrden(NodoArbolBinario *raiz) {
    if (raiz==nullptr) return;

    enOrden(raiz->izquierda);
    cout<<raiz->elemento.dato<<" ";
    enOrden(raiz->derecha);
}
void postOrden(NodoArbolBinario *raiz) {
    if (raiz==nullptr) return;

    postOrden(raiz->izquierda);
    postOrden(raiz->derecha);
    cout<<raiz->elemento.dato<<" ";
}