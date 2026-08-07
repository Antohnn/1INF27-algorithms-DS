//
// Created by ANTONIO on 3/07/2026.
//

#include <iostream>

#include "Cola.h"
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
    nuevo->siguiente=nullptr;

    if (esColaVacia(cola)) {
        cola.frente=nuevo;
        cola.fin=nuevo;
    }else {
        cola.fin->siguiente=nuevo;
        cola.fin=nuevo;
    }
}
void encolarNodoArbol(Cola &cola,NodoArbol *elemento) {
    NodoCola *nuevo=new NodoCola();

    nuevo->elemento.nodo=elemento;
    nuevo->siguiente=nullptr;

    if (esColaVacia(cola)) {
        cola.frente=nuevo;
        cola.fin=nuevo;
    }else {
        cola.fin->siguiente=nuevo;
        cola.fin=nuevo;
    }
}

ElementoCola desencolar(Cola &cola) {
    ElementoCola elemento{};
    if (esColaVacia(cola)) {
        return elemento;
    }

    NodoCola *aux=cola.frente;
    elemento=aux->elemento;
    cola.frente=cola.frente->siguiente;

    delete aux;

    return elemento;
}
