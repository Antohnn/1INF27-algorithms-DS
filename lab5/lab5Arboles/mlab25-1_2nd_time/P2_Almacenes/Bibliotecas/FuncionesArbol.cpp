//
// Created by ANTONIO on 4/07/2026.
//

#include <iostream>
#include "estructurasArbol.h"
#include "estructurasPilas.h"
#include "FuncionesPila.h"

using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodo(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();

    nuevo->dato=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}

void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento) {
    if (raiz==nullptr) {
        raiz=crearNodo(elemento);
        return;
    }
    if (elemento.codigo<raiz->dato.codigo) {
        insertarABB(raiz->izquierda,elemento);
    }else {
        insertarABB(raiz->derecha,elemento);
    }
}
void insertar(NodoArbol *&raiz,int codigo) {
    ElementoArbol elemento{};
    elemento.codigo=codigo;

    insertarABB(raiz,elemento);
}

void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    enOrden(raiz->izquierda);
    cout<<raiz->dato.codigo<<" ";
    enOrden(raiz->derecha);
}
void eliminarHojasHijos(NodoArbol *raiz) {
    Pila pila;
    construirPila(pila);

    apilar(pila,raiz,false);

    while (!esPilaVacia(pila)) {
        ElementoPila ele=desapilar(pila);
        NodoArbol *actual=ele.nodo;

        if (ele.valido==false) {

            apilar(pila,actual,true);

            if (actual->derecha!=nullptr) {
                apilar(pila,actual->derecha,false);
            }

            if (actual->izquierda!=nullptr) {
                apilar(pila,actual->izquierda,false);
            }
        }else {
            eliminarHijoUnico(actual);
        }
    }
}
void eliminarHijoUnico(NodoArbol *nodo) {

    bool soloIzquierda= nodo->izquierda!=nullptr and nodo->derecha==nullptr;
    bool soloDerecha= nodo->derecha!=nullptr and nodo->izquierda==nullptr;

    if (soloIzquierda and esHijo(nodo->izquierda)) {
        delete nodo->izquierda;
        nodo->izquierda=nullptr;
    }else if (soloDerecha and esHijo(nodo->derecha)) {
        delete nodo->derecha;
        nodo->derecha=nullptr;
    }
}
bool esHijo(NodoArbol *nodo) {
    return nodo!=nullptr and nodo->izquierda==nullptr and nodo->derecha==nullptr;
}

