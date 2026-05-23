//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Baraja & listaTAD) {
    listaTAD.inicio = nullptr;
    listaTAD.fin = nullptr;
    listaTAD.longitud = 0;
}

bool esListaVacia(const struct Baraja & listaTAD) {
    return listaTAD.inicio == nullptr;
}

/*Inserta los elementos al inicio de la lista*/
void insertarAlInicio(struct Baraja & listaTAD, const struct ElementoBaraja & elemento) {

    struct NodoBaraja * nuevo;
    nuevo = new struct NodoBaraja;
    nuevo->elemento = elemento;
    nuevo->siguiente = listaTAD.inicio;
    listaTAD.inicio = nuevo;
    listaTAD.longitud++;
}

/*Inserta un elemento siempre al final de la lista*/
void insertarAlFinal(struct Baraja & listaTAD, const struct ElementoBaraja & elemento) {
    struct NodoBaraja * nuevo;
    nuevo = new struct NodoBaraja;
    nuevo->elemento = elemento;
    nuevo->siguiente = nullptr;

    if (esListaVacia(listaTAD)) {
        listaTAD.inicio = nuevo;
        listaTAD.fin = nuevo;
    }
    else {
        listaTAD.fin->siguiente = nuevo;
        listaTAD.fin = nuevo;
    }
    listaTAD.longitud++;
}

/*Obtiene el último NodoLista de la lista*/
struct NodoBaraja * obtenerUltimoNodo(const struct Baraja & listaTAD) {
    struct NodoBaraja * ultimo = nullptr;
    struct NodoBaraja* recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarEnOrden(struct Baraja & listaTAD, const struct ElementoBaraja & elemento) {

    struct NodoBaraja *nuevo, *recorrido = listaTAD.inicio, * anterior = nullptr;
    nuevo = new struct NodoBaraja;
    nuevo->elemento = elemento;
    while(recorrido){
        if(recorrido->elemento.numero > elemento.numero) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo->siguiente = recorrido;
    if(anterior == nullptr) listaTAD.inicio = nuevo;
    else anterior->siguiente = nuevo;
    listaTAD.longitud++;
}

void eliminaNodo(struct Baraja & listaTAD, const struct ElementoBaraja & elemento) {
    struct NodoBaraja * ultimo = nullptr;
    struct NodoBaraja * recorrido = listaTAD.inicio;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento.numero != elemento.numero)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            listaTAD.inicio = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
    }
    listaTAD.longitud--;
}

// void destruir(struct Baraja & listaTAD) {
//     /*recorrido apunta al inicio del tad*/
//     struct NodoBaraja * recorrido = listaTAD.inicio;
//
//     while (recorrido != nullptr) {
//         /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
//         struct NodoBaraja * NodoListaAEliminar = recorrido;
//         recorrido = recorrido->siguiente;
//         delete NodoListaAEliminar;
//     }
//     /*la lista queda vacia*/
//     listaTAD.inicio = nullptr;
//     listaTAD.fin = nullptr;
//     listaTAD.longitud = 0;
// }

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Baraja & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoBaraja * recorrido = listaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.numero<<recorrido->elemento.tipo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}