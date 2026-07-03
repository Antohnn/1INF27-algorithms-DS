//
// Created by ANTONIO on 30/06/2026.
//

#include <iostream>

#include "Arbol.h"
#include "NodoArbol.h"
#include "Pila/FuncionesPila.h"
#include "Pila/Pila.h"

using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodo(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();

    nuevo->elemento=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}
void plantarArbol(NodoArbol *&raiz,NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha) {
    raiz=crearNodo(elemento);
    raiz->izquierda=izquierda;
    raiz->derecha=derecha;
}

bool esHijo(NodoArbol *nodo) {
    return nodo!=nullptr and
    nodo->derecha==nullptr and
    nodo->izquierda==nullptr;
}
void eliminarHijoUnico(NodoArbol *padre) {

    bool soloIzq=padre->izquierda!=nullptr and padre->derecha==nullptr;
    bool soloDer=padre->derecha!=nullptr and padre->izquierda==nullptr;

    if (soloIzq and esHijo(padre->izquierda)) {
        delete padre->izquierda;
        padre->izquierda=nullptr;
    }else if (soloDer and esHijo(padre->derecha)) {
        delete padre->derecha;
        padre->derecha=nullptr;
    }
}
void eliminarNodosHijos(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    Pila pila;
    construirPila(pila);

    apilar(pila,raiz,false);

    while (!esPilaVacia(pila)) {
        ElementoPila actual=desapilar(pila);

        if (!actual.visitado) {
            apilar(pila,actual.nodo,true);

            if (actual.nodo->derecha!=nullptr) {
                apilar(pila,actual.nodo->derecha,false);
            }

            if (actual.nodo->izquierda!=nullptr) {
                apilar(pila,actual.nodo->izquierda,false);
            }
        }else {
            eliminarHijoUnico(actual.nodo);
        }
    }
}
void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento) {
    if (raiz==nullptr) {
        raiz=crearNodo(elemento);
        return;
    }
    if (elemento.dato<raiz->elemento.dato) {
        insertarABB(raiz->izquierda,elemento);
    }else {
        insertarABB(raiz->derecha,elemento);
    }
}
void insertarCodigo(NodoArbol *&raiz, int codigo) {
    ElementoArbol elemento{};
    elemento.dato = codigo;
    insertarABB(raiz, elemento);
}
void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    enOrden(raiz->izquierda);
    cout<<raiz->elemento.dato<<" ";
    enOrden(raiz->derecha);
}
