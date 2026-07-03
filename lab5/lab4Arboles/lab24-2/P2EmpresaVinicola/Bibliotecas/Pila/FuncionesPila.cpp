//
// Created by ANTONIO on 1/07/2026.
//

#include <iostream>

#include "Pila.h"
#include "../ElementoArbol.h"
using namespace std;
#include "FuncionesPila.h"

void crearPila(Pila &pila) {
    pila.cima=nullptr;
}
bool esPilaVacia(Pila &pila) {
    return pila.cima==nullptr;
}
void apilar(Pila &pila,ElementoArbol &elemento) {
    NodoPila *nuevo=new NodoPila();

    nuevo->elemento.elemento=elemento;
    nuevo->siguiente=pila.cima;

    pila.cima=nuevo;
}
ElementoArbol desapilar(Pila &pila) {
    ElementoArbol elemento{};

    if (pila.cima==nullptr) {
        return elemento;
    }
    NodoPila *aux=pila.cima;
    elemento=aux->elemento.elemento;

    pila.cima=pila.cima->siguiente;

    delete aux;

    return elemento;
}
