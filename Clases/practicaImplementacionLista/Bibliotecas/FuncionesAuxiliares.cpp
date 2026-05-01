//
// Created by ANTONIO on 30/04/2026.
//
#include <iostream>

#include "Lista.h"

using namespace std;

#include "FuncionesAuxiliares.h"
#include "Elemento.h"
#include "Nodo.h"

void construirLista(struct Lista &listaInicio) {
    listaInicio.inicio=nullptr;
    listaInicio.longitud=0;
}
bool esListaVacia(struct Lista &listaTAD) {
    return listaTAD.inicio==nullptr;
}
void insertarAlInicio(struct Lista &listaInicio,struct Elemento &elemento) {
    struct Nodo *nuevo;
    nuevo=new struct Nodo;
    nuevo->elemento=elemento;
    nuevo->siguiente=listaInicio.inicio;
    listaInicio.inicio=nuevo;
    listaInicio.longitud++;
}
void imprimir(struct Lista &listaInicio) {
    struct Nodo *recorrido;
    recorrido=listaInicio.inicio;
    while (recorrido) {
        cout<<recorrido->elemento.dni<<endl;
        recorrido=recorrido->siguiente;
    }
}
void isertarAlFinal(struct Lista &listaFin,struct Elemento &elemento) {
    struct Nodo *nuevo,*ultimoNodo;
    ultimoNodo=obtenerUltimoNodo(listaFin);
    nuevo =new struct Nodo;
    nuevo->elemento=elemento;
    nuevo->siguiente=nullptr;
    if (ultimoNodo==nullptr) {
        listaFin.inicio=nuevo;
    }else {
        ultimoNodo->siguiente=nuevo;
    }
    listaFin.longitud++;
}
struct Nodo *obtenerUltimoNodo(struct Lista &listaFin) {
    struct Nodo *recorrido,*ultimo;
    ultimo=nullptr;
    recorrido=listaFin.inicio;
    while (recorrido) {
        ultimo=recorrido;
        recorrido=recorrido->siguiente;
    }
    return ultimo;
}
void insertarEnOrden(struct Lista &listaOrdenada,struct Elemento &elemento) {
    struct Nodo *nuevo,*recorrido=listaOrdenada.inicio,*anterior=nullptr;
    nuevo=new struct Nodo;
    nuevo->elemento=elemento;
    while (recorrido) {
        if (recorrido->elemento.dni>elemento.dni) break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo->siguiente=recorrido;
    if (anterior==nullptr) listaOrdenada.inicio=nuevo;
    else anterior->siguiente=nuevo;
    listaOrdenada.longitud++;
}
void eliminaNodo(struct Lista &listaInicio,struct Elemento &elemento) {
    struct Nodo *recorrido,*ultimo;
    ultimo=nullptr;
    recorrido=listaInicio.inicio;

    while ((recorrido != nullptr) and (recorrido->elemento.dni != elemento.dni)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            listaInicio.inicio = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
    }
    listaInicio.longitud--;

}
