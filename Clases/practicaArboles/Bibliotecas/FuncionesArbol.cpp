//
// Created by ANTONIO on 28/06/2026.
//

#include "FuncionesArbol.h"

void preOrden(NodoArbol *raiz) {
    if (raiz==nullptr)return;

    cout<<raiz->dato.dato<<" ";
    preOrden(raiz->izquierda);
    preOrden(raiz->derecha);
}
void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr)return;

    enOrden(raiz->izquierda);
    cout<<raiz->dato.dato<<" ";
    enOrden(raiz->derecha);
}
void postOrden(NodoArbol *raiz) {
    if (raiz==nullptr)return;

    postOrden(raiz->izquierda);
    postOrden(raiz->derecha);
    cout<<raiz->dato.dato<<" ";
}
//realizamos la implementacion del arbol en si

NodoArbol *crearNodo(ElementoNodoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();
    nuevo->dato=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;
    return nuevo;
}
//contar nodos
int contarNodos(NodoArbol *raiz) {
    if (raiz==nullptr)return 0;

    return 1+contarNodos(raiz->izquierda)
            +contarNodos(raiz->derecha);
}
//contar hojas
int contarHojas(NodoArbol *raiz) {
    if (raiz==nullptr)return 0;
    if (raiz->izquierda==nullptr and raiz->derecha==nullptr) {
        return 1;
    }
    return contarHojas(raiz->izquierda)
        +contarHojas(raiz->derecha);
}
//hallar la altura
int altura(NodoArbol *raiz) {
    if (raiz==nullptr)return -1;

    int alturaIzq=altura(raiz->izquierda);
    int alturaDer=altura(raiz->derecha);

    return 1+max(alturaIzq,alturaDer);
}
//buscar elemento del arbol
bool buscarElemento(NodoArbol *raiz, ElementoNodoArbol &elemento) {
    if (raiz==nullptr)return false;
    if (raiz->dato.dato==elemento.dato) return true;
    return buscarElemento(raiz->izquierda, elemento) || buscarElemento(raiz->derecha, elemento);
}
//plantar arbol binario de abajo hacia arriba
void plantarArbol(NodoArbol *&raiz,NodoArbol *subArbolIzq,ElementoNodoArbol &elemento,NodoArbol *subArbolDer) {
    raiz=crearNodo(elemento);
    raiz->izquierda=subArbolIzq;
    raiz->derecha=subArbolDer;
}
