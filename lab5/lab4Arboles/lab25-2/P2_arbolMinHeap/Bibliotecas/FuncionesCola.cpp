//
// Created by ANTONIO on 2/07/2026.
//

#include "estructuras.h"
#include <iostream>
using namespace std;
#include "FuncionesCola.h"

void construirCola(Cola &cola) {
    cola.frente=nullptr;
    cola.fin=nullptr;
}
bool esColaVacia(Cola &cola) {
    return cola.frente==nullptr;
}

void encolar(Cola &cola,ElementoCola &elemento) {
    NodoCola *nuevo=new NodoCola();

    nuevo->elemento=elemento;
    if (cola.frente==nullptr) {
        cola.frente=nuevo;
        cola.fin=nuevo;
    }else {
        cola.fin->siguiente=nuevo;
        cola.fin=nuevo;
    }
}
ElementoCola desencolar(Cola &cola) {
    ElementoCola elemento{};
    elemento.nodo=nullptr;

    if (cola.frente==nullptr) {
        return elemento;
    }

    NodoCola *aux=cola.frente;
    elemento.nodo=aux->elemento.nodo;

    cola.frente=cola.frente->siguiente;
    if (cola.frente==nullptr) {
        cola.fin=nullptr;
    }

    delete aux;

    return elemento;
}

ElementoCola verFrente(Cola &cola) {
    ElementoCola elemento{};
    elemento.nodo=nullptr;

    if (!esColaVacia(cola)) {
        elemento.nodo=cola.frente->elemento.nodo;
    }
    return elemento;
}
void encolarNodoArbol(Cola &cola,NodoArbol *nodo) {
    ElementoCola elemento{};
    elemento.nodo=nodo;

    encolar(cola,elemento);
}
