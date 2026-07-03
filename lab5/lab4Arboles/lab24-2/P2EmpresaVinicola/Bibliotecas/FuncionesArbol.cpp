//
// Created by ANTONIO on 1/07/2026.
//
#include <iostream>

#include "NodoArbol.h"
#include "Pila/Pila.h"
#include "Pila/FuncionesPila.h"
using namespace std;

#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo= new NodoArbol();

    nuevo->elemento=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}
void ingresa_lote(NodoArbol *&raiz, ElementoArbol &elemento) {

    if (raiz==nullptr) {
        raiz=crearNodoArbol(elemento);
        return;
    }
    if (elemento.anio==raiz->elemento.anio) {
        raiz->elemento.lote+=elemento.lote;
        return;
    }
    if (elemento.anio<raiz->elemento.anio) {
        ingresa_lote(raiz->izquierda,elemento);
    }else {
        ingresa_lote(raiz->derecha,elemento);
    }
}
void crearElemento(ElementoArbol &elemento,int anio,int lote) {
    elemento.anio=anio;
    elemento.lote=lote;
}
void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    enOrden(raiz->izquierda);
    cout<<raiz->elemento.anio<<" "<<raiz->elemento.lote<<endl;
    enOrden(raiz->derecha);
}

void reporteDeStock(NodoArbol *raiz) {
    Pila pila;
    crearPila(pila);

    NodoArbol *actual=buscarMenor(raiz);

    while (actual!=nullptr) {
        apilar(pila,actual->elemento);
        actual=buscarSucesor(raiz,actual->elemento.anio);
    }

    while (!esPilaVacia(pila)) {
        ElementoArbol elemento=desapilar(pila);
        cout<<elemento.anio<<" "<<elemento.lote<<endl;
    }
    cout<<endl;
}
NodoArbol *buscarSucesor(NodoArbol *raiz,int anioActual) {
    NodoArbol *sucesor=nullptr;

    while (raiz!=nullptr) {
        if (raiz->elemento.anio>anioActual) {
            sucesor=raiz;
            raiz=raiz->izquierda;
        }else {
            raiz=raiz->derecha;
        }
    }
    return sucesor;
}
NodoArbol *buscarMenor(NodoArbol *raiz) {
    if (raiz==nullptr) return nullptr;

    while (raiz->izquierda!=nullptr) {
        raiz=raiz->izquierda;
    }
    return raiz;
}