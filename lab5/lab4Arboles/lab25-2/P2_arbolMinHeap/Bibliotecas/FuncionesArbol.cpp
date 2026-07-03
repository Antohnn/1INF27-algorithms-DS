//
// Created by ANTONIO on 2/07/2026.
//

#include <iostream>

#include "estructuras.h"
using namespace std;
#include "FuncionesArbol.h"
#include "FuncionesCola.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();

    nuevo->elemento=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;
    nuevo->padre=nullptr;

    return nuevo;
}

void intercambiarDatos(NodoArbol *a,NodoArbol *b) {
    int aux=a->elemento.dato;
    a->elemento.dato=b->elemento.dato;
    b->elemento.dato=aux;
}
void heapifyUp(NodoArbol *nodo) {

    while (nodo->padre!=nullptr && nodo->elemento.dato<nodo->padre->elemento.dato) {
        intercambiarDatos(nodo,nodo->padre);
        nodo=nodo->padre;
    }
}

void insertarMinHeap(NodoArbol *&raiz,Cola &cola, ElementoArbol &elemento) {
    NodoArbol *nuevo=crearNodoArbol(elemento);

    if (raiz==nullptr) {
        raiz=nuevo;
        encolarNodoArbol(cola,nuevo);
        return;
    }
    ElementoCola frente=verFrente(cola);
    NodoArbol *padre=frente.nodo;

    if (padre->izquierda==nullptr) {
        padre->izquierda=nuevo;
        nuevo->padre=padre;
    }else {
        padre->derecha=nuevo;
        nuevo->padre=padre;

        desencolar(cola);
    }

    encolarNodoArbol(cola,nuevo);
    heapifyUp(nuevo);
}
void imprimirPorNiveles(NodoArbol *raiz) {
    /*
     Forma de solucion:
     Se recorre el arbol por niveles usando una cola auxiliar. Cada elemento
     de la cola contiene un puntero al nodo del arbol que falta procesar.
    */

    if (raiz == nullptr) return;

    Cola cola;
    construirCola(cola);

    encolarNodoArbol(cola, raiz);

    while (!esColaVacia(cola)) {
        ElementoCola elemento = desencolar(cola);
        NodoArbol *actual = elemento.nodo;

        cout << actual->elemento.dato << " ";

        if (actual->izquierda != nullptr) {
            encolarNodoArbol(cola, actual->izquierda);
        }

        if (actual->derecha != nullptr) {
            encolarNodoArbol(cola, actual->derecha);
        }
    }

    cout << endl;
}
